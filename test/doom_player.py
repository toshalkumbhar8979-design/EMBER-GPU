"""doom_player.py — Doom on the EMBER GPU, in a window you can drive.

Plays the frames test/tb_doom_demo.py rendered out of ember_rtr_top, at the
frame rate the GPU actually delivers (15.97 fps for the E1M1 walk), in a 2x
window scaled the way ember_display does it, with a live FPS overlay.

    GPU      — that frame's measured cost on the RTL (sim clock at 50 MHz)
    DISPLAY  — the rate this window is really putting frames on screen

Keys:  SPACE pause   <- / -> step (pauses)   UP / DOWN speed
       R restart     F fullscreen            ESC / Q quit

Usage:
    python test/doom_player.py [--session test/demo_frames] [--scale 2]
"""
import argparse
import json
import os
import sys
import tempfile
import time

import tkinter as tk
from PIL import Image

HERE = os.path.dirname(os.path.abspath(__file__))


class Player:
    def __init__(self, root, session, scale):
        self.root = root
        self.scale = scale
        meta_path = os.path.join(session, "metrics.json")
        with open(meta_path) as fh:
            meta = json.load(fh)
        self.frames = meta["frames"]
        self.summ = meta["summary"]
        self.fps = max(self.summ["mean_fps"], 1.0)
        self.W, self.H = meta["gpu"]["resolution"]
        self.w, self.h = self.W * scale, self.H * scale

        # Tk 8.6 reads PNG directly, so no ImageTk dependency: build the 2x
        # nearest-neighbour frames once, then swap PhotoImages every tick.
        self.tmp = tempfile.mkdtemp(prefix="ember_player_")
        self.photos = []
        for rec in self.frames:
            im = Image.open(os.path.join(session, rec["ppm"])).convert("RGB")
            im = im.resize((self.w, self.h), Image.NEAREST)
            p = os.path.join(self.tmp, f"{rec['frame']:04d}.png")
            im.save(p)
            self.photos.append(tk.PhotoImage(file=p))

        self.idx = 0
        self.paused = False
        self.speed = 1.0
        self.display_fps = self.fps
        self.last_t = time.perf_counter()
        self.deadline = self.last_t
        self.running = True

        root.title("DOOM on EMBER GPU — SPACE pause · ←/→ walk · "
                   "↑/↓ speed · F full · ESC quit")
        root.configure(bg="black")
        root.resizable(False, False)
        self.canvas = tk.Canvas(root, width=self.w, height=self.h,
                                highlightthickness=0, bg="black")
        self.canvas.pack()
        self.img_id = self.canvas.create_image(0, 0, anchor="nw",
                                               image=self.photos[0])

        # ---- overlay (the strip is redrawn every frame) ------------------
        self.band = self.canvas.create_rectangle(
            0, 0, self.w, 56, fill="black", outline="#ffd166")
        self.t_title = self.canvas.create_text(
            10, 10, anchor="nw", text="EMBER GPU  ·  DOOM E1M1",
            fill="#ffd166", font=("Consolas", 15, "bold"))
        self.t_count = self.canvas.create_text(
            self.w - 10, 12, anchor="ne", text="", fill="#d2d2d2",
            font=("Consolas", 12))
        self.t_gpu = self.canvas.create_text(
            10, 34, anchor="nw", text="", fill="#78e68c",
            font=("Consolas", 12, "bold"))
        self.t_disp = self.canvas.create_text(
            self.w - 10, 34, anchor="ne", text="", fill="#aec0ff",
            font=("Consolas", 12))

        self.walk = 0
        root.bind("<space>", self.toggle_pause)
        root.bind("<KeyPress-Right>", lambda e: self.start_walk(1))
        root.bind("<KeyRelease-Right>", lambda e: self.stop_walk(1))
        root.bind("<KeyPress-Left>", lambda e: self.start_walk(-1))
        root.bind("<KeyRelease-Left>", lambda e: self.stop_walk(-1))
        root.bind("<Up>", lambda e: self.set_speed(1))
        root.bind("<Down>", lambda e: self.set_speed(-1))
        root.bind("<r>", self.restart)
        root.bind("<f>", self.toggle_full)
        root.bind("<Escape>", lambda e: self.quit())
        root.bind("<q>", lambda e: self.quit())
        root.protocol("WM_DELETE_WINDOW", self.quit)

        self.tick()

    # ---- controls --------------------------------------------------------
    def toggle_pause(self, _evt=None):
        self.paused = not self.paused
        self.deadline = time.perf_counter()

    def start_walk(self, d):
        """Holding an arrow walks through the session at GPU speed."""
        self.walk = d
        self.paused = False
        self.deadline = time.perf_counter()

    def stop_walk(self, d):
        if self.walk == d:
            self.walk = 0

    def step(self, n):
        self.paused = True
        self.idx = (self.idx + n) % len(self.frames)
        self.draw(force=True)

    def set_speed(self, n):
        steps = [0.25, 0.5, 1.0, 2.0, 4.0]
        i = steps.index(min(steps, key=lambda s: abs(s - self.speed)))
        self.speed = steps[max(0, min(len(steps) - 1, i + n))]

    def restart(self, _evt=None):
        self.idx = 0
        self.walk = 0
        self.paused = False
        self.deadline = time.perf_counter()

    def toggle_full(self, _evt=None):
        self.root.attributes("-fullscreen",
                             not self.root.attributes("-fullscreen"))

    def quit(self):
        self.running = False
        self.root.destroy()

    # ---- frame pump ------------------------------------------------------
    def draw(self, force=False):
        rec = self.frames[self.idx]
        if force or rec["frame"] != getattr(self, "_shown", None):
            self.canvas.itemconfig(self.img_id, image=self.photos[self.idx])
            self._shown = rec["frame"]
        self.canvas.itemconfig(self.t_count,
                               text=f"frame {self.idx + 1}/{len(self.frames)}")
        self.canvas.itemconfig(
            self.t_gpu,
            text=f"GPU {rec['fps']:.2f} fps · {rec['gpu_ms']:.1f} ms · "
                 f"{rec['tris']:,} tris · {rec['cycles']:,} cyc")
        self.canvas.itemconfig(
            self.t_disp,
            text=f"display {self.display_fps:.1f} fps"
                 + (f" · {self.speed:g}x" if self.speed != 1.0 else "")
                 + (" · WALKING" if self.walk else "")
                 + (" · PAUSED" if self.paused and not self.walk else ""))

    def tick(self):
        if not self.running:
            return
        now = time.perf_counter()
        dt = now - self.last_t
        self.last_t = now
        if dt > 0:
            self.display_fps += (1.0 / dt - self.display_fps) * 0.15

        if not self.paused or self.walk:
            period = 1.0 / (self.fps * self.speed)
            step = self.walk if self.walk else 1
            if now >= self.deadline:
                self.idx = (self.idx + step) % len(self.frames)
                self.deadline += period
                if self.deadline < now - period:
                    self.deadline = now + period
            self.draw()
        else:
            self.draw(force=True)

        delay = 0 if self.paused else max(
            1, int((self.deadline - time.perf_counter()) * 1000))
        self.root.after(delay, self.tick)


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--session", default=os.path.join(HERE, "demo_frames"))
    ap.add_argument("--scale", type=int, default=2)
    args = ap.parse_args(argv)

    if not os.path.exists(os.path.join(args.session, "metrics.json")):
        sys.exit(f"no session at {args.session}: run test/doom_session.sh first")

    root = tk.Tk()
    root.lift()
    root.attributes("-topmost", True)
    root.after(1200, lambda: root.attributes("-topmost", False))
    Player(root, args.session, args.scale)
    print("DOOM on EMBER GPU: window up — SPACE pause, arrows walk, ESC quit",
          flush=True)
    root.mainloop()
    return 0


if __name__ == "__main__":
    sys.exit(main())
