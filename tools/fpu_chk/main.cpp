// Minimal direct Verilator probe for ember_fpu4 (bypasses cocotb).
#include <verilated.h>
#include "Vember_fpu4.h"
#include <cstdio>
#include <cstdint>

static Vember_fpu4* dut;

static void tick() {
  dut->clk = 0; dut->eval();
  dut->clk = 1; dut->eval();
}

static void reset() {
  dut->rst_n = 0; dut->go = 0; dut->lane_en = 0; dut->op = 0;
  for (int i = 0; i < 3; i++) tick();
  dut->rst_n = 1; tick();
}

static uint32_t run(uint32_t op, uint32_t a, uint32_t b) {
  dut->lane_en = 0x1;
  dut->op = op;
  dut->a0 = a; dut->b0 = b;
  dut->a1 = a; dut->b1 = b;
  dut->a2 = a; dut->b2 = b;
  dut->a3 = a; dut->b3 = b;
  tick();
  dut->go = 1; tick();
  dut->go = 0;
  while (dut->busy) tick();
  tick();
  return dut->y0;
}

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  dut = new Vember_fpu4;
  reset();

  struct V { uint32_t op, a, b, want; const char* name; };
  V vecs[] = {
    {0, 0x3F800000u, 0x40000000u, 0x40400000u, "1.0+2.0"},
    {0, 0x00000000u, 0x40000000u, 0x40000000u, "0.0+2.0"},
    {0, 0x3F800000u, 0x00000000u, 0x3F800000u, "1.0+0.0"},
    {0, 0x3F800000u, 0x3F800000u, 0x40000000u, "1.0+1.0"},
    {1, 0x3F800000u, 0x40000000u, 0xBF800000u, "1.0-2.0"},
    {1, 0x3F800000u, 0x3F800000u, 0x00000000u, "1.0-1.0"},
    {2, 0x3F800000u, 0x40000000u, 0x40000000u, "1.0*2.0"},
    {3, 0x3F800000u, 0x40000000u, 0x3F000000u, "1.0/2.0"},
  };
  for (auto& v : vecs) {
    uint32_t got = run(v.op, v.a, v.b);
    printf("%-8s a=%08x b=%08x got=%08x want=%08x %s\n",
           v.name, v.a, v.b, got, v.want, (got == v.want) ? "OK" : "BAD");
  }
  delete dut;
  return 0;
}
