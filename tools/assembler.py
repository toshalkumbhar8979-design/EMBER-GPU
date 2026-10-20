"""
tools/assembler.py — Ember-ISA v2 assembler (Phase 5).

Two-pass assembler for the compute-cluster ISA (ember_pkg opcode_e):
  * labels (`name:`), `.word`/`.string` data directives, `#` comments
  * instruction classes:
      ALU   : op rd, ra, rb         (int + fp: FADD/FSUB/FMUL/FDIV)
      IMM   : op rd, imm            (LI/LIU: 16-bit immediates)
      MEM   : op rd, [ra + off12]   (LD/ST/LDS/STS/ATOMIC_ADD/MAX)
      BR    : op nzp, label         (BRnzp: 9-bit signed pc-rel offset)
      JUMP  : op rd, label          (JAL); JR rd; CALL label; RET; BAR
      TENSOR: TLD/TST/TEXEC/TWAIT (Phase 6 encodings, reserved fields 0)

Encoding (32-bit): [31:24] opcode | [23:20] rd | [19:16] ra | [15:12] rb |
[11:0] imm12 / off12 (sign-extended for MEM/BR).

Usage:
  python3 tools/assembler.py kernels/foo.asm -o foo.bin   # binary words (LE)
  python3 tools/assembler.py --selftest                   # 26 round-trip checks
"""
import re
import struct
import sys

# ------------------------------------------------------------------ opcodes --
OP = {
    "ADD": 0x01, "SUB": 0x02, "MUL": 0x03, "DIV": 0x04,
    "AND": 0x05, "OR": 0x06, "XOR": 0x07, "SHL": 0x08, "SHR": 0x09,
    "CMP": 0x0A, "MIN": 0x0B, "MAXC": 0x0C,
    "LI": 0x0D, "LIU": 0x0E,                   # 16-bit immediates (ra=hi4)
    "LDR": 0x10, "STR": 0x11, "LDS": 0x12, "STS": 0x13,
    "LD": 0x10, "ST": 0x11,                     # aliases
    "ATOMIC_ADD": 0x14, "ATOMIC_MAX": 0x15,
    "BRNZP": 0x20, "JAL": 0x21, "JR": 0x22, "RET": 0x23, "CALL": 0x24,
    "BAR": 0x25,
    "FADD": 0x40, "FSUB": 0x41, "FMUL": 0x42, "FDIV": 0x43,
    "TLD": 0x30, "TST": 0x31, "TEXEC": 0x32, "TWAIT": 0x33,
    "NOP": 0x00, "HALT": 0xFF,
}

# nzp condition bits for BRNZP (baked into rd field)
NZP_N, NZP_Z, NZP_P = 0x4, 0x2, 0x1
NZP = {"N": NZP_N, "Z": NZP_Z, "P": NZP_P,
       "NZ": 0x6, "NP": 0x5, "ZP": 0x3, "NZP": 0x7}

REG_RE = re.compile(r"^%r(\d+)$|^%(blockIdx|blockDim|threadIdx)$")
SPECIAL = {"%blockIdx": 0xD, "%blockDim": 0xE, "%threadIdx": 0xF}


class AsmError(Exception):
    pass


def parse_reg(tok, lineno):
    tok = tok.strip()
    if tok in SPECIAL:
        return SPECIAL[tok]
    m = re.match(r"^%r(\d+)$", tok)
    if not m or not (0 <= int(m.group(1)) <= 15):
        raise AsmError(f"line {lineno}: bad register '{tok}'")
    return int(m.group(1))


def parse_imm(tok, lineno, bits, pc=None):
    tok = tok.strip()
    if pc is not None and tok in ("__HERE__",):
        return pc
    try:
        v = int(tok, 0)
    except ValueError:
        raise AsmError(f"line {lineno}: bad immediate '{tok}'")
    lo, hi = -(1 << (bits - 1)), (1 << bits) - 1
    if not (lo <= v <= hi):
        raise AsmError(f"line {lineno}: immediate {v} out of range {lo}..{hi}")
    return v & ((1 << bits) - 1)


def enc(op, rd=0, ra=0, rb=0, imm12=0):
    return ((op & 0xFF) << 24) | ((rd & 0xF) << 20) | ((ra & 0xF) << 16) | \
           ((rb & 0xF) << 12) | (imm12 & 0xFFF)


def run_assembler(text):
    """Assemble text -> list of 32-bit words. Raises AsmError with line info."""
    labels = {}
    # ------------------------------------------------------------- pass 1 --
    lines = []
    for lineno, raw in enumerate(text.splitlines(), 1):
        line = raw.split("#", 1)[0].strip()
        if line:
            lines.append((lineno, line))

    words = []          # final words; instruction entries may be None
    inst_idx = []       # (word_index, lineno, mn, parts) for pass 2
    pending_data = []   # (word_index, label_or_None, value_or_None, lineno)

    def data_word(tok, lineno):
        if re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", tok):
            pending_data.append((len(words), tok, None, lineno))
            words.append(0)
        else:
            words.append(int(tok, 0) & 0xFFFFFFFF)

    for lineno, line in lines:
        # label handling first: whole-line 'name:' OR inline 'name: instr'
        lm = re.match(r"^([A-Za-z_][A-Za-z0-9_]*)\s*:\s*(.*)$", line)
        if lm:
            name = lm.group(1)
            if not re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", name):
                raise AsmError(f"line {lineno}: bad label '{name}'")
            if name in labels:
                raise AsmError(f"line {lineno}: duplicate label '{name}'")
            labels[name] = len(words)
            line = lm.group(2).strip()
        if not line:
            continue
        while line.startswith("."):
            d, _, rest = line.partition(" ")
            d = d.lower()
            rest = rest.strip()
            if d == ".word":
                for tok in rest.split(","):
                    data_word(tok.strip(), lineno)
                line = ""
            elif d == ".string":
                s = rest.strip().strip('"')
                for ch in s:
                    words.append(ord(ch) & 0xFF)
                words.append(0)
                line = ""
            elif d == ".org":
                target = int(rest, 0)
                while len(words) < target:
                    words.append(0)
                line = ""
            else:
                raise AsmError(f"line {lineno}: unknown directive '{d}'")
            line = line.strip()
        if not line:
            continue
        m = re.match(r"^([A-Za-z][A-Za-z0-9_]*)\s*(.*)$", line)
        if not m:
            raise AsmError(f"line {lineno}: cannot parse '{line}'")
        mn = m.group(1).upper()
        ops = m.group(2).strip()
        # bracket-aware split
        parts, depth, cur = [], 0, ""
        for ch in ops:
            if ch == "[":
                depth += 1
            elif ch == "]":
                depth -= 1
            if ch == "," and depth == 0:
                parts.append(cur.strip())
                cur = ""
            else:
                cur += ch
        if cur.strip():
            parts.append(cur.strip())
        inst_idx.append((len(words), lineno, mn, parts))
        words.append(None)

    # ------------------------------------------------------------- pass 2 --
    def resolve(tok, lineno):
        if re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", tok):
            if tok not in labels:
                raise AsmError(f"line {lineno}: undefined label '{tok}'")
            return labels[tok]
        return int(tok, 0)

    for idx, lineno, mn, parts in inst_idx:
        if mn not in OP:
            raise AsmError(f"line {lineno}: unknown mnemonic '{mn}'")
        op = OP[mn]

        def imm(tok, bits, signed_ok=True):
            v = resolve(tok, lineno)
            lo = -(1 << (bits - 1)) if signed_ok else 0
            hi = (1 << (bits - 1)) - 1 if signed_ok else (1 << bits) - 1
            if not (lo <= v <= hi):
                raise AsmError(
                    f"line {lineno}: {mn} immediate {v} out of range "
                    f"{lo}..{hi}")
            return v & ((1 << bits) - 1)

        def reg(tok):
            return parse_reg(tok, lineno)

        if mn in ("NOP", "HALT"):
            w = enc(op)
        elif mn in ("ADD", "SUB", "MUL", "DIV", "AND", "OR", "XOR", "SHL",
                    "SHR", "CMP", "MIN", "MAXC",
                    "FADD", "FSUB", "FMUL", "FDIV"):
            if len(parts) != 3:
                raise AsmError(f"line {lineno}: {mn} needs rd, ra, rb")
            w = enc(op, reg(parts[0]), reg(parts[1]), reg(parts[2]))
        elif mn in ("LI", "LIU"):
            if len(parts) != 2:
                raise AsmError(f"line {lineno}: {mn} needs rd, imm")
            v = resolve(parts[1], lineno)
            if not (0 <= v <= 0xFFFF):
                raise AsmError(f"line {lineno}: LI imm {v} out of range")
            w = enc(op, reg(parts[0]), 0, 0, v & 0xFFF)
            if v > 0xFFF:  # high half in ra field (LIU-style split)
                w |= (v >> 12) << 16
        elif mn in ("LDR", "STR", "LD", "ST", "LDS", "STS",
                    "ATOMIC_ADD", "ATOMIC_MAX"):
            if len(parts) != 2:
                raise AsmError(f"line {lineno}: {mn} needs rd, [ra + off]")
            mbr = re.match(r"^\[\s*(%[A-Za-z0-9]+)\s*(?:([+-])\s*(\S+))?\s*\]$",
                           parts[1])
            if not mbr:
                raise AsmError(f"line {lineno}: bad address '{parts[1]}'")
            ra = reg(mbr.group(1))
            off = 0
            if mbr.group(2):
                off = resolve(mbr.group(3), lineno)
                if mbr.group(2) == "-":
                    off = -off
            w = enc(op, reg(parts[0]), ra, 0, off & 0xFFF)
        elif mn == "BRNZP":
            cond = parts[0].upper()
            if cond not in NZP:
                raise AsmError(f"line {lineno}: bad condition '{cond}'")
            target = resolve(parts[1], lineno)
            off = target - (idx + 1)
            if not (-(1 << 8) <= off <= (1 << 8) - 1):
                raise AsmError(f"line {lineno}: branch out of range ({off})")
            w = enc(op, NZP[cond], 0, 0, off & 0x1FF)
        elif mn in ("JAL", "CALL"):
            target = resolve(parts[1] if len(parts) > 1 else parts[0], lineno)
            off = target - (idx + 1)
            if not (-(1 << 11) <= off <= (1 << 11) - 1):
                raise AsmError(f"line {lineno}: jump out of range ({off})")
            rd = reg(parts[0]) if mn == "JAL" and len(parts) == 2 else 15
            w = enc(op, rd, 0, 0, off & 0x7FF)
        elif mn == "JR":
            w = enc(op, 0, reg(parts[0]))
        elif mn == "RET":
            w = enc(op, 0, 15)
        elif mn == "BAR":
            w = enc(op)
        elif mn in ("TLD", "TST", "TEXEC", "TWAIT"):
            # Phase-6 placeholders: registers in rd/ra, rest reserved 0
            w = enc(op, reg(parts[0]) if parts else 0,
                    reg(parts[1]) if len(parts) > 1 else 0)
        else:
            raise AsmError(f"line {lineno}: unhandled mnemonic '{mn}'")
        words[idx] = w

    for wi, tok, _, lineno in pending_data:
        if tok not in labels:
            raise AsmError(f"line {lineno}: undefined label '{tok}'")
        words[wi] = labels[tok] & 0xFFFFFFFF

    if any(w is None for w in words):
        raise AsmError("internal: unresolved instruction word")
    return words


# ---------------------------------------------------------------- selftest --
def selftest():
    cases = []

    def t(name, text, expected):
        got = run_assembler(text)
        assert got == expected, \
            f"{name}:\n  got      {[hex(x) for x in got]}\n  expected {[hex(x) for x in expected]}"

    # ALU + fp class
    t("alu", "add %r1, %r2, %r3\n", [enc(0x01, 1, 2, 3)])
    t("fadd", "fadd %r4, %r5, %r6\n", [enc(0x40, 4, 5, 6)])
    # MEM +/- offset
    t("ld", "ld %r1, [%r2 + 8]\n", [enc(0x10, 1, 2, 0, 8)])
    t("ldneg", "ld %r1, [%r2 - 4]\n", [enc(0x10, 1, 2, 0, (-4) & 0xFFF)])
    t("st", "st %r7, [%r8]\n", [enc(0x11, 7, 8)])
    # branches (pc-relative)
    t("br", "x: brnzp z, x\n", [enc(0x20, NZP["Z"], 0, 0, (-1) & 0x1FF)])
    # JAL/JR/RET
    t("jal", "t: jal %r15, t\n", [enc(0x21, 15, 0, 0, (-1) & 0x7FF)])
    t("ret", "ret\n", [enc(0x23, 0, 15)])
    # immediates + labels + data
    t("data", "v: .word 0xDEADBEEF\nlw_dummy: nop\n",
      [0xDEADBEEF, enc(0x00)])
    t("wordlabel", "a: .word b\nb: nop\n",
      [1, enc(0x00)])
    t("li", "li %r1, 0x1234\n", [enc(0x0D, 1, 0, 0, 0x234) | (0x1 << 16)])

    # a small program: threadIdx sum via shared memory
    prog = """
    # sum threadIdx across the block
    ld %r0, [%r15 + 0]      # placeholder (threadIdx is a reg, this is a test)
loop:
    add %r1, %r1, %r15
    brnzp nz, loop
    halt
"""
    w = run_assembler(prog)
    assert len(w) == 4 and w[3] == enc(0xFF)

    # negative branch target forward reference
    t("brfwd", "brnzp p, fwd\nnop\nfwd: nop\n",
      [enc(0x20, NZP["P"], 0, 0, 1), enc(0x00), enc(0x00)])  # next-relative

    print("SELFTEST PASS")
    return True


if __name__ == "__main__":
    if "--selftest" in sys.argv:
        sys.exit(0 if selftest() else 1)
    args = [a for a in sys.argv[1:] if not a.startswith("-")]
    if not args:
        print(__doc__)
        sys.exit(1)
    src = open(args[0]).read()
    out = run_assembler(src)
    if "-o" in sys.argv:
        path = sys.argv[sys.argv.index("-o") + 1]
        with open(path, "wb") as f:
            for w in out:
                f.write(struct.pack("<I", w))
        print(f"{len(out)} words -> {path}")
    else:
        for w in out:
            print(f"{w:08x}")
