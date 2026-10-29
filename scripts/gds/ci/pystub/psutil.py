"""Minimal psutil replacement for the OpenLane container.

harden_block.sh caps synthesis RSS with psutil, but the container's nix Python
has no psutil and no pip. Without this shim every 15 s loop prints a
ModuleNotFoundError traceback into the job log and the guard never fires. This
implements exactly the calls harden_block.sh makes, using /proc only:

    Process(pid).memory_info().rss
    Process(pid).children(recursive=True)
    Process(pid).is_running(), .status()
    psutil.Error

The CI workflow puts this directory on PYTHONPATH for the synthesis job.
"""

import os

STATUS_ZOMBIE = "zombie"
STATUS_RUNNING = "running"


class Error(Exception):
    pass


class _MemoryInfo(object):
    __slots__ = ("rss",)


class Process(object):
    def __init__(self, pid):
        self.pid = int(pid)

    def _stat_fields(self):
        # /proc/<pid>/stat: the comm field may contain spaces and parens, so
        # split after the last ')'. Field 3 (state) is index 0.
        try:
            with open("/proc/%d/stat" % self.pid) as fh:
                return fh.read().rsplit(")", 1)[1].split()
        except (OSError, IndexError):
            raise Error("no process %d" % self.pid)

    def is_running(self):
        return os.path.exists("/proc/%d" % self.pid)

    def status(self):
        try:
            return STATUS_ZOMBIE if self._stat_fields()[0] == "Z" else STATUS_RUNNING
        except Error:
            return STATUS_ZOMBIE

    def memory_info(self):
        try:
            with open("/proc/%d/statm" % self.pid) as fh:
                resident_pages = int(fh.read().split()[1])
        except (OSError, IndexError, ValueError):
            raise Error("no memory info for %d" % self.pid)
        info = _MemoryInfo()
        info.rss = resident_pages * os.sysconf("SC_PAGE_SIZE")
        return info

    def children(self, recursive=False):
        found = []
        frontier = [self.pid]
        while frontier:
            parent = frontier.pop()
            for entry in os.listdir("/proc"):
                if not entry.isdigit():
                    continue
                child = Process(int(entry))
                try:
                    if int(child._stat_fields()[1]) != parent:
                        continue
                except Error:
                    continue
                found.append(child)
                if recursive:
                    frontier.append(child.pid)
        return found
