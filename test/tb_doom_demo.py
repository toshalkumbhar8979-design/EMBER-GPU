"""
tb_doom_demo.py — a continuous Doom E1M1 session on the Ember RTL.

This is the playable demo, not a one-shot pixel test: a scripted walk through
E1M1 (starting at the player start, heading out into the courtyard) renders
frame after frame, and every single frame takes the full hardware path —

    clear FB/Z via CP DMA -> pack the frame's texture atlas -> DMA it into
    TEX_BASE -> DMA the frame's 19-word GSX triangles -> kick ember_rtr_top
    -> read the RGB565 framebuffer back over the debug port.

Each frame is written out as a PPM P6 image and timed from the sim clock, so
the session reports what EMBER actually achieves: ms/frame, fps, cycles per
frame, triangles/s and pixels/s at the 50 MHz design clock.

Output (DOOM_OUT, default test/demo_frames):
    frames/doom_0000.ppm      RGB565 framebuffer, 320x240
    metrics.json              per-frame timings + session summary

Env knobs:
    DOOM_FRAMES=N   frames in the session        (default 32)
    DOOM_STEP=U     map units walked per frame   (default 24)
    DOOM_OUT=dir    output directory             (default test/demo_frames)
    DOOM_BATCHES=N  cap atlas batches per frame  (debug)
"""
import json
import math
import os
import sys
import time

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
from cocotb.utils import get_sim_time

CLK_NS = 10                      # 100 MHz sim clock; design timing given at 50 MHz
DESIGN_MHZ = 50.0
FRAMES_DEFAULT = 32
STEP_DEFAULT = 24.0
PLAYER_RADIUS = 16.0
MAX_STEP_UP = 24.0

_HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.abspath(os.path.join(_HERE, "..", "tools", "golden")))
import doom_real as R        # noqa: E402
import raster                # noqa: E402

CP_STATUS = 0x04
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_RTR_KICK = 0x20

FB0_BASE = raster.FB0_BASE
ZBUF_BASE = raster.ZBUF_BASE
TEX_BASE = raster.TEX_BASE
CMDBUF = raster.CMDBUF_BASE
PAL_BASE = raster.PAL_BASE

SCR_W, SCR_H = raster.SCR_W, raster.SCR_H
FB_BYTES = SCR_W * SCR_H * 2
Z_BYTES = FB_BYTES
M32 = 0xFFFFFFFF


# ---------------------------------------------------------------- host side --
class TB:
    def __init__(self, dut):
        self.dut = dut

    async def wr(self, addr, data, strb=0xF):
        d = self.dut
        d.h_awaddr.value = addr
        d.h_awvalid.value = 1
        d.h_wdata.value = data
        d.h_wstrb.value = strb
        d.h_wvalid.value = 1
        aw_done = w_done = False
        while not (aw_done and w_done):
            await RisingEdge(d.clk)
            if d.h_awready.value == 1 and d.h_awvalid.value == 1:
                aw_done = True
                d.h_awvalid.value = 0
            if d.h_wready.value == 1 and d.h_wvalid.value == 1:
                w_done = True
                d.h_wvalid.value = 0
        d.h_bready.value = 1
        while True:
            await RisingEdge(d.clk)
            if d.h_bvalid.value == 1:
                resp = int(d.h_bresp.value)
                break
        d.h_bready.value = 0
        assert resp == 0, f"AXI write resp {resp} at {addr:#x}"

    async def rd(self, addr):
        d = self.dut
        d.h_araddr.value = addr
        d.h_arvalid.value = 1
        while True:
            await RisingEdge(d.clk)
            if d.h_arready.value == 1 and d.h_arvalid.value == 1:
                d.h_arvalid.value = 0
                break
        d.h_rready.value = 1
        while True:
            await RisingEdge(d.clk)
            if d.h_rvalid.value == 1:
                data = int(d.h_rdata.value)
                resp = int(d.h_rresp.value)
                break
        d.h_rready.value = 0
        assert resp == 0, f"AXI read resp {resp} at {addr:#x}"
        return data

    async def reset(self):
        d = self.dut
        d.rst_n.value = 0
        d.dbg_en.value = 0
        d.dbg_addr.value = 0
        d.dbg_wdata.value = 0
        d.dbg_be.value = 0
        d.h_awvalid.value = 0
        d.h_wvalid.value = 0
        d.h_arvalid.value = 0
        d.h_bready.value = 0
        d.h_rready.value = 0
        await RisingEdge(d.clk)
        await RisingEdge(d.clk)
        d.rst_n.value = 1
        await RisingEdge(d.clk)

    async def dma(self, byte_off, words, chunk=60):
        off = byte_off
        for i in range(0, len(words), chunk):
            part = words[i:i + chunk]
            for w in part:
                await self.wr(CP_FIFOD, w & M32)
            await self.wr(CP_DMA_DST, off)
            await self.wr(CP_DMA_LEN, len(part) * 4)
            await self.wr(CP_CMDX, 0)
            for _ in range(4000):
                await RisingEdge(self.dut.clk)
                if (await self.rd(CP_STATUS) & 1) == 0:
                    break
            else:
                raise AssertionError("DMA never went idle")
            off += len(part) * 4

    async def kick_and_wait(self, step=500, timeout=4_000_000):
        await self.wr(CP_RTR_KICK, 1)
        waited = 0
        while waited < timeout:
            for _ in range(step):
                await RisingEdge(self.dut.clk)
            waited += step
            if (await self.rd(CP_STATUS) >> 1) & 1 == 0:
                return
        raise AssertionError("rtr_busy stuck high")

    async def dbg_word(self, word_addr):
        d = self.dut
        d.dbg_en.value = 1
        d.dbg_addr.value = word_addr
        d.dbg_be.value = 0
        await RisingEdge(d.clk)
        await RisingEdge(d.clk)
        val = int(d.dbg_rdata.value)
        d.dbg_en.value = 0
        return val

    async def read_region(self, byte_off, nbytes):
        out = bytearray()
        base = byte_off >> 2
        for w in range(nbytes // 4):
            out += (await self.dbg_word(base + w)).to_bytes(4, "little")
        return bytes(out)


def _words(byte_seq):
    return [byte_seq[4 * i] | (byte_seq[4 * i + 1] << 8)
            | (byte_seq[4 * i + 2] << 16) | (byte_seq[4 * i + 3] << 24)
            for i in range(len(byte_seq) // 4)]


def now_ns():
    """Sim time in ns (cocotb 2 returns the simulator's raw unit, Verilator's
    ps, when no unit is asked for)."""
    try:
        return int(get_sim_time(unit="ns"))
    except TypeError:                                   # older cocotb
        return int(get_sim_time()) // 1000


def write_ppm_p6(path, raw565):
    """RGB565 framebuffer bytes -> binary PPM (P6), exactly Ember's output."""
    out = bytearray(b"P6\n%d %d\n255\n" % (SCR_W, SCR_H))
    for i in range(SCR_W * SCR_H):
        p = raw565[2 * i] | (raw565[2 * i + 1] << 8)
        out += bytes((((p >> 11) & 0x1F) << 3,
                      ((p >> 5) & 0x3F) << 2,
                      (p & 0x1F) << 3))
    with open(path, "wb") as fh:
        fh.write(bytes(out))


# ------------------------------------------------------------- the walk ------
class Walker:
    """Collision-aware scripts camera: walks E1M1 like a player would.

    Forward until something solid is inside the player radius, then steer
    around it, exactly so a stray wall cannot swallow a frame's worth of RTL
    time.
    """

    def __init__(self, rend):
        self.r = rend
        m = rend.map
        self.solid = []
        for ld in m.linedefs:
            if ld[6] == 0xFFFF:
                self.solid.append((m.verts[ld[0]], m.verts[ld[1]]))
                continue
            s1 = m.sidedefs[ld[5]][5]
            s2 = m.sidedefs[ld[6]][5]
            if abs(m.sectors[s1][0] - m.sectors[s2][0]) > MAX_STEP_UP:
                self.solid.append((m.verts[ld[0]], m.verts[ld[1]]))

    def _dist(self, px, py, a, b):
        dx, dy = b[0] - a[0], b[1] - a[1]
        L = dx * dx + dy * dy
        t = 0.0 if L == 0 else max(0.0, min(1.0, ((px - a[0]) * dx
                                                  + (py - a[1]) * dy) / L))
        return math.hypot(px - (a[0] + t * dx), py - (a[1] + t * dy))

    def blocked(self, x, y):
        return any(self._dist(x, y, a, b) < PLAYER_RADIUS
                   for a, b in self.solid)

    def poses(self, n, step):
        """n (x, y, yaw_bam) poses walking forward from the player start."""
        r = self.r
        x, y, yaw = r.px, r.py, r.yaw
        out = [(x, y, yaw * 65536.0 / (2.0 * math.pi))]
        for _ in range(max(0, n - 1)):
            for dyaw in (0, -4, 4, -8, 8, -14, 14, -22, 22, -35, 35,
                         -50, 50, -70, 70, 90, -90):
                a = yaw + math.radians(dyaw)
                nx, ny = x + step * math.cos(a), y + step * math.sin(a)
                if not self.blocked(nx, ny):
                    x, y, yaw = nx, ny, a
                    break
            else:
                break                                  # boxed in: stop here
            out.append((x, y, yaw * 65536.0 / (2.0 * math.pi)))
        return out


@cocotb.test()
async def test_doom_session(dut):
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = TB(dut)

    here = _HERE
    outdir = os.environ.get("DOOM_OUT", os.path.join(here, "demo_frames"))
    fdir = os.path.join(outdir, "frames")
    os.makedirs(fdir, exist_ok=True)

    wad = os.path.abspath(os.path.join(here, "..", "data", "doom1.wad"))
    if not os.path.exists(wad):
        cocotb.skip("data/doom1.wad not present")
    rend = R.DoomRenderer(wad, "E1M1")

    nframes = int(os.environ.get("DOOM_FRAMES", str(FRAMES_DEFAULT)))
    step = float(os.environ.get("DOOM_STEP", str(STEP_DEFAULT)))
    start = int(os.environ.get("DOOM_START", "0"))
    count = int(os.environ.get("DOOM_COUNT", "0"))
    max_batches = int(os.environ.get("DOOM_BATCHES", "0")) or None

    walker = Walker(rend)
    poses = walker.poses(nframes, step)
    nframes = len(poses)
    # Frames are independent (each one clears FB and Z first), so a session
    # can be split across parallel simulator processes: DOOM_START/DOOM_COUNT
    # select this process's slice, and metrics_part_<start>.json is merged
    # afterwards by test/doom_session.sh.
    if count:
        poses = poses[start:start + count]
    elif start:
        poses = poses[start:]
    print(f"EMBERSESSION: {len(poses)} frames ({start}.."
          f"{start + len(poses) - 1} of {nframes}), {step:g} units/frame, "
          f"out={outdir}", flush=True)

    await tb.reset()

    pal = [(b << 16) | (g << 8) | r for (r, g, b) in rend.pal]
    await tb.dma(PAL_BASE, pal)

    frames = []
    t_wall0 = time.time()
    t_sim0 = now_ns()

    for fi, (x, y, yaw_bam) in enumerate(poses, start=start):
        rend.set_player(x, y, yaw_bam)
        batches, stats = rend.render()
        if max_batches:
            batches = batches[:max_batches]

        # ---- one frame, start to finish on the RTL ----------------------
        t0 = now_ns()
        await tb.dma(FB0_BASE, [0] * (FB_BYTES // 4))
        await tb.dma(ZBUF_BASE, [0xFFFFFFFF] * (Z_BYTES // 4))
        tris = 0
        for atlas, cmds in batches:
            await tb.dma(TEX_BASE, _words(atlas))
            for gi in range(0, len(cmds), 1000):
                part = cmds[gi:gi + 1000]
                words = []
                for c in part:
                    words += [w & M32 for w in c]
                words.append(0)                # tri_valid=0: end of queue
                await tb.dma(CMDBUF, words)
                await tb.kick_and_wait()
                tris += len(part)
        t1 = now_ns()

        # ---- capture (debug port readback: not part of a game frame) ----
        raw = await tb.read_region(FB0_BASE, FB_BYTES)
        t2 = now_ns()

        path = os.path.join(fdir, f"doom_{fi:04d}.ppm")
        write_ppm_p6(path, raw)

        gpu_ns = t1 - t0
        wall = time.time()
        rec = {
            "frame": fi,
            "x": round(x, 2), "y": round(y, 2),
            "yaw_deg": round(yaw_bam * 360.0 / 65536.0, 2),
            "tris": tris,
            "batches": len(batches),
            "segs": stats["segs"],
            "gpu_ns": gpu_ns,
            "gpu_ms": round(gpu_ns / 1e6, 3),
            "cycles": gpu_ns // CLK_NS,
            "fps": round(1e9 / gpu_ns, 2) if gpu_ns else 0.0,
            "readback_ms": round((t2 - t1) / 1e6, 3),
            "ppm": os.path.relpath(path, outdir),
            "wall_s": round(wall - t_wall0, 1),
        }
        frames.append(rec)
        print(f"EMBERSESSION frame {fi:3d}/{nframes - 1}: "
              f"pos=({x:7.1f},{y:7.1f}) yaw={rec['yaw_deg']:6.1f} "
              f"{tris:5d} tris  {rec['gpu_ms']:8.3f} ms  "
              f"{rec['fps']:6.2f} fps  ({rec['cycles']} cyc, "
              f"readback {rec['readback_ms']:.1f} ms)", flush=True)

    t_sim_end = now_ns()
    wall_total = time.time() - t_wall0
    wall_frames = sum(fr["gpu_ns"] for fr in frames) / 1e6

    ms = [fr["gpu_ms"] for fr in frames]
    fps = [fr["fps"] for fr in frames]
    tris_total = sum(fr["tris"] for fr in frames)
    summary = {
        "frames": len(frames),
        "mean_frame_ms": round(sum(ms) / len(ms), 3),
        "min_frame_ms": round(min(ms), 3),
        "max_frame_ms": round(max(ms), 3),
        "mean_fps": round(len(frames) / (sum(ms) / 1000.0), 2),
        "best_fps": round(max(fps), 2),
        "worst_fps": round(min(fps), 2),
        "mean_tris_per_frame": round(tris_total / len(frames), 1),
        "total_tris": tris_total,
        "tris_per_s": round(tris_total / (sum(ms) / 1000.0), 0),
        "mean_cycles_per_frame": int(sum(fr["cycles"] for fr in frames)
                                     / len(frames)),
        "fill_px_per_s": int(round(SCR_W * SCR_H
                                   * len(frames) / (sum(ms) / 1000.0))),
        "session_sim_ms": round((t_sim_end - t_sim0) / 1e6, 1),
        "session_wall_s": round(wall_total, 1),
        "sim_realtime_factor": round((t_sim_end - t_sim0) / 1e9 / wall_total, 5),
        "rtl_frame_wall_s": round(wall_frames / 1000.0 / len(frames), 2),
    }
    part = os.path.join(outdir, f"metrics_part_{start:04d}.json")
    with open(part, "w") as fh:
        json.dump({"frames": frames, "summary": summary}, fh, indent=1)

    print("EMBERSESSION summary: "
          f"{summary['mean_frame_ms']:.2f} ms/frame = "
          f"{summary['mean_fps']:.2f} fps mean "
          f"(best {summary['best_fps']:.2f}, worst {summary['worst_fps']:.2f}); "
          f"{summary['mean_tris_per_frame']:.0f} tris/frame; "
          f"sim ran {summary['sim_realtime_factor']:.5f}x real time",
          flush=True)
    assert len(frames) == nframes
    assert all(fr["tris"] > 0 for fr in frames), "an empty frame slipped through"
