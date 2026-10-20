#!/bin/bash
# Launch the Phase-7f MNIST trainer detached, with a verifiable PID file.
cd /mnt/c/Users/tosha/Downloads/GPU || exit 1
mkdir -p data/run
PYTHONDONTWRITEBYTECODE=1 nohup python3 tools/train_mnist.py \
    --epochs 6 --train 8192 --val 300 \
    > data/run/train6k.log 2>&1 &
echo $! > data/run/train.pid
echo "launched pid $(cat data/run/train.pid)"
