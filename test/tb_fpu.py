# tb_fpu.py — Phase-4 FPU testbench: bit-exact vs tools/golden/fpu.py.
#
# Standalone sim (TOPLEVEL=ember_fpu4): drive go/lane_en/op/operands, wait
# done, compare y* against the pure-Python IEEE-754 reference.
#
# cocotb 2.1 gotchas honored: print() not logging; Clock started before any
# await; multiple drivers separated per test.
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly
from cocotb.utils import get_sim_time

import os
import sys
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools", "golden"))
import fpu  # noqa: E402


class FpuDriver:
    def __init__(self, dut):
        self.dut = dut
        self.clk = Clock(dut.clk, 20, units="ns")
        cocotb.start_soon(self.clk.start())
        dut.rst_n.value = 0
        dut.go.value = 0
        dut.lane_en.value = 0
        dut.op.value = 0
        dut.a0.value = 0
        dut.b0.value = 0
        dut.a1.value = 0
        dut.b1.value = 0
        dut.a2.value = 0
        dut.b2.value = 0
        dut.a3.value = 0
        dut.b3.value = 0

    async def ready(self):
        for _ in range(3):
            await RisingEdge(self.dut.clk)
        self.dut.rst_n.value = 1
        await RisingEdge(self.dut.clk)

    async def run_op(self, op, a, b):
        """Drive one op on all 4 lanes; fixed-latency protocol (no polling).

        Latency contract: go sampled at edge N -> y valid after edge N+5
        (cnt 0..4, execute at cnt==4).  We wait 6 edges total for settle."""
        d = self.dut
        await RisingEdge(d.clk)
        d.lane_en.value = 0xF
        d.op.value = op
        d.a0.value = a
        d.b0.value = b
        d.a1.value = a
        d.b1.value = b
        d.a2.value = a
        d.b2.value = b
        d.a3.value = a
        d.b3.value = b
        d.go.value = 1
        await RisingEdge(d.clk)   # edge N: go+operands sampled, lane starts
        d.go.value = 0
        for _ in range(6):        # edges N+1..N+6; y final at N+5
            await RisingEdge(d.clk)
        r = [int(d.y0.value), int(d.y1.value), int(d.y2.value), int(d.y3.value)]
        return r


async def golden_vecs():
    """Random normal vectors (deterministic seed) + specials."""
    import random
    random.seed(20260926)
    vecs = [
        (fpu.f2b(1.0), fpu.f2b(2.0)),
        (fpu.f2b(1.5), fpu.f2b(-2.25)),
        (fpu.f2b(0.1), fpu.f2b(0.2)),
        (fpu.f2b(-0.1), fpu.f2b(-0.2)),
        (fpu.f2b(1.0), fpu.f2b(1.0)),            # exact tie add/sub
        (fpu.f2b(1.0), fpu.f2b(-1.0)),           # exact cancellation
        (fpu.f2b(3.0e38), fpu.f2b(3.0e38)),      # mul/add overflow -> Inf
        (fpu.f2b(1e-38), fpu.f2b(1e-38)),        # mul underflow -> FTZ
        (fpu.f2b(1e-38), fpu.f2b(1e30)),         # div underflow -> FTZ
        (fpu.f2b(1e30), fpu.f2b(1e-30)),         # div overflow -> Inf
        (fpu.f2b(1.0), fpu.f2b(0.0)),            # div by zero
        (fpu.f2b(-0.0), fpu.f2b(0.0)),           # -0 + 0
        (0x7F800000, fpu.f2b(1.0)),              # Inf
        (0xFF800000, fpu.f2b(1.0)),              # -Inf
        (0x7FC00000, fpu.f2b(1.0)),              # NaN
        (fpu.f2b(1.0), 0x7F800000),              # /Inf
        (fpu.f2b(7.0), fpu.f2b(3.0)),            # repeating binary
        (fpu.f2b(123456.789), fpu.f2b(0.000123)),
        (0x00800001, fpu.f2b(2.0)),              # min normal input
        (0x7F7FFFFF, fpu.f2b(2.0)),              # max finite input
    ]
    for _ in range(400):
        vecs.append((rnd_normal_b(), rnd_normal_b()))
    return vecs


def rnd_normal_b():
    import random
    e = random.randint(1, 254)
    m = random.getrandbits(23)
    s = random.getrandbits(1)
    return (s << 31) | (e << 23) | m


@cocotb.test()
async def test_fpu_bitexact(dut):
    """All 4 ops across 420 operand pairs — bit-exact vs golden on 4 lanes."""
    drv = FpuDriver(dut)
    await drv.ready()
    vecs = await golden_vecs()
    nerr = 0
    t0 = get_sim_time(units="ns")
    for i, (a, b) in enumerate(vecs):
        for op in range(4):
            r = await drv.run_op(op, a, b)
            want = fpu.fp_exec(op, a, b)
            for lane, got in enumerate(r):
                if got != want:
                    nerr += 1
                    if nerr <= 6:
                        da = int(dut.a0.value) if lane == 0 else -1
                        db = int(dut.b0.value) if lane == 0 else -1
                        print(f"[{i}] op{op} lane{lane} a={a:08x} b={b:08x} "
                              f"got={got:08x} want={want:08x} dut.a0={da:08x} dut.b0={db:08x}")
    t1 = get_sim_time(units="ns")
    print(f"test_fpu_bitexact: 4 ops x {len(vecs)} pairs x 4 lanes, "
          f"errors={nerr}, sim={t1 - t0:.0f}ns")
    assert nerr == 0, f"{nerr} bit-exact mismatches vs golden"


@cocotb.test()
async def test_fpu_independent_lanes(dut):
    """4 lanes carry DIFFERENT ops/operands concurrently; each matches golden."""
    drv = FpuDriver(dut)
    await drv.ready()
    d = dut
    a = [fpu.f2b(2.5), fpu.f2b(-7.75), fpu.f2b(0.375), fpu.f2b(1234.5)]
    b = [fpu.f2b(0.5), fpu.f2b(2.0), fpu.f2b(-0.125), fpu.f2b(-0.0025)]
    ops = [0, 1, 2, 3]

    d.a0.value, d.b0.value = a[0], b[0]
    d.a1.value, d.b1.value = a[1], b[1]
    d.a2.value, d.b2.value = a[2], b[2]
    d.a3.value, d.b3.value = a[3], b[3]

    nerr = 0
    # op is shared, so enable lanes per op round: lane i fires when its op
    # is on the shared op bus; every lane executes exactly once.
    for op in range(4):
        d.op.value = op
        mask = 0
        for lane in range(4):
            if ops[lane] == op:
                mask |= (1 << lane)
        d.lane_en.value = mask
        await RisingEdge(d.clk)
        d.go.value = 1
        await RisingEdge(d.clk)
        d.go.value = 0
        for _ in range(6):
            await RisingEdge(d.clk)
        for lane in range(4):
            if (mask >> lane) & 1:
                y = int(getattr(d, f"y{lane}").value)
                w = fpu.fp_exec(ops[lane], a[lane], b[lane])
                if y != w:
                    nerr += 1
                    print(f"lane{lane} op{op} got={y:08x} want={w:08x}")
        await RisingEdge(d.clk)
    assert nerr == 0, f"{nerr} lane-op mismatches"
