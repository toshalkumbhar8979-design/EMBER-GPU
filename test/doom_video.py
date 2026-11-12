"""doom_video.py — turn an Ember Doom session into a video for the repo.

Reads what test/tb_doom_demo.py produced (PPM frames out of ember_rtr_top +
metrics.json with the measured per-frame RTL timings), burns that frame's
measured frame rate into the corner (nothing else), and encodes an H.264 MP4 at
the frame rate the GPU actually achieved. Also writes a looping GIF for README
embeds.

The overlay is drawn at 2x with nearest-neighbour, matching ember_display's
320x240 -> 640x480 2x2 upscale, so the video is the display controller's
output rather than a resampled screenshot.

Usage:
    python test/doom_video.py [--session test/demo_frames]
                              [--mp4 docs/media/doom_ember.mp4]
                              [--gif docs/media/doom_ember.gif]
                              [--loops 3]
"""
import argparse
import json
import os
import shutil
import subprocess
import sys
import tempfile

from PIL import Image, ImageDraw, ImageFont

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
SCALE = 2
W, H = 320, 240


def load(path):
    with open(path) as fh:
        return json.load(fh)


def font(size):
    try:
        return ImageFont.load_default(size=size)
    except TypeError:                       # Pillow < 10.1
        return ImageFont.load_default()


def overlay(img, rec, total, summ, title, small, tiny):
    """Burn only the frame's measured frame rate, with no backing plate.

    No bar, no panel, no frame counter: just the number that frame achieved,
    outlined so it stays readable over bright and dark scenes alike.
    """
    d = ImageDraw.Draw(img, "RGBA")
    d.text((12, 10), f"{rec['fps']:.1f} fps", font=title,
           fill=(150, 240, 160), stroke_width=3, stroke_fill=(0, 0, 0))
    return img


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--session", default=os.path.join(HERE, "demo_frames"))
    ap.add_argument("--mp4", default=os.path.join(ROOT, "docs", "media",
                                                  "doom_ember.mp4"))
    ap.add_argument("--gif", default=os.path.join(ROOT, "docs", "media",
                                                  "doom_ember.gif"))
    ap.add_argument("--loops", type=int, default=3)
    args = ap.parse_args(argv)

    meta = load(os.path.join(args.session, "metrics.json"))
    frames, summ = meta["frames"], meta["summary"]
    fps = max(summ["mean_fps"], 1.0)
    print(f"session: {len(frames)} frames, {summ['mean_frame_ms']:.2f} ms/frame, "
          f"{summ['mean_fps']:.2f} fps -> encoding at {fps:.2f} fps")

    title, small, tiny = font(16), font(13), font(12)
    tmp = tempfile.mkdtemp(prefix="ember_doom_")
    n = 0
    try:
        for _ in range(max(1, args.loops)):
            for rec in frames:
                src = os.path.join(args.session, rec["ppm"])
                im = Image.open(src).convert("RGB")
                if im.size != (W, H):
                    raise SystemExit(f"{src}: unexpected size {im.size}")
                im = im.resize((W * SCALE, H * SCALE), Image.NEAREST)
                overlay(im, rec, len(frames), summ, title, small, tiny)
                n += 1
                im.save(os.path.join(tmp, f"{n:05d}.png"), optimize=False)

        ffmpeg = shutil.which("ffmpeg")
        if not ffmpeg:
            raise SystemExit("ffmpeg not found on PATH")
        os.makedirs(os.path.dirname(args.mp4), exist_ok=True)
        cmd = [ffmpeg, "-y", "-loglevel", "error",
               "-framerate", f"{fps:.4f}", "-i", os.path.join(tmp, "%05d.png"),
               "-c:v", "libx264", "-preset", "slow", "-crf", "20",
               "-pix_fmt", "yuv420p", "-movflags", "+faststart",
               args.mp4]
        subprocess.run(cmd, check=True)
        print(f"wrote {os.path.relpath(args.mp4, ROOT)} "
              f"({os.path.getsize(args.mp4) / 1024:.0f} KB, "
              f"{n / fps:.2f} s @ {fps:.2f} fps)")

        if args.gif:
            os.makedirs(os.path.dirname(args.gif), exist_ok=True)
            gif_tmp = os.path.join(tmp, "gif")
            os.makedirs(gif_tmp, exist_ok=True)
            for i, rec in enumerate(frames):
                im = Image.open(os.path.join(args.session, rec["ppm"]))
                im = im.convert("RGB").resize((W, H), Image.NEAREST)
                overlay(im, rec, len(frames), summ, font(13), font(9), font(8))
                im = im.convert("P", palette=Image.ADAPTIVE, colors=200)
                im.save(os.path.join(gif_tmp, f"{i:04d}.png"))
            subprocess.run([ffmpeg, "-y", "-loglevel", "error",
                            "-framerate", f"{fps:.4f}",
                            "-i", os.path.join(gif_tmp, "%04d.png"),
                            "-vf", "split[a][b];[a]palettegen=max_colors=200[p];"
                                   "[b][p]paletteuse=dither=bayer",
                            "-loop", "0", args.gif], check=True)
            print(f"wrote {os.path.relpath(args.gif, ROOT)} "
                  f"({os.path.getsize(args.gif) / 1024:.0f} KB)")
        return 0
    finally:
        shutil.rmtree(tmp, ignore_errors=True)


if __name__ == "__main__":
    sys.exit(main())
