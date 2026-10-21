#!/usr/bin/env bash
# push_retry.sh -- resilient first-push to GitHub over a flaky link.
# git lfs push is idempotent: objects already on the server are skipped, so
# every attempt makes real progress even if the connection drops mid-batch.
cd /c/Users/tosha/Downloads/GPU || exit 1
for i in $(seq 1 10); do
  echo "=== attempt $i $(date '+%F %T') ==="
  if git lfs push origin main 2>&1; then
    echo "--- LFS objects up; pushing refs ---"
    if git push origin main 2>&1; then
      echo "PUSH_OK $(date '+%F %T')"
      exit 0
    fi
  fi
  echo "--- attempt $i failed; waiting 30s ---"
  sleep 30
done
echo "PUSH_FAILED after 10 attempts $(date '+%F %T')"
exit 1
