#!/usr/bin/env bash
# push_smart.sh -- flaky-link-friendly first push to GitHub.
# Strategy: LFS objects one at a time, SMALLEST FIRST, with per-object retries.
# git-lfs remembers objects already accepted by the server, so every completed
# object is permanent progress -- a dropped connection costs at most the one
# in-flight object. Only after ALL objects are up do we push the pack + refs.
cd /c/Users/tosha/Downloads/GPU || exit 1
git config lfs.concurrenttransfers 1
git config lfs.dialtimeout 30
git config lfs.activitytimeout 120

echo "SMART_PUSH start $(date '+%F %T')"
FAILED=""
while read -r size path; do
  oid=$(basename "$path")
  echo "[$(date '+%F %T')] object $oid ($((size / 1048576)) MB)"
  ok=0
  for try in 1 2 3 4 5; do
    if git lfs push origin --object-id "$oid"; then ok=1; break; fi
    echo "  attempt $try failed for $oid; retrying in 15s"
    sleep 15
  done
  if [ "$ok" = 0 ]; then
    echo "OBJECT_FAILED $oid"
    FAILED="$FAILED $oid"
  fi
done < <(find .git/lfs/objects -type f -printf '%s %p\n' 2>/dev/null | sort -n)

echo "[$(date '+%F %T')] object phase done; failed:${FAILED:- none}"
echo "[$(date '+%F %T')] final git lfs push + git push"
if [ -z "$FAILED" ] && git lfs push origin main && git push origin main; then
  echo "SMART_PUSH_OK $(date '+%F %T')"
  exit 0
fi
echo "SMART_PUSH_FAILED $(date '+%F %T')"
exit 1
