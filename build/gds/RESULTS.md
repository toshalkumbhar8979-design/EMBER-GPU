# Ember ASIC hardening results (sky130A, OpenLane 2 image, OpenROAD)

| Block | Cells | Area (um^2) | Wire (um) | WNS (ns) | Magic DRC | GDS (KB) | Flow |
|---|---|---|---|---|---|---|---|
| `rtr_scan` | 1416166 | - | - | - | - | - | synthesized |
| `rtr_setup` | 20782 | 150387 | 853284 | 0.00 | 0 | 57106 | GDS; routing/Magic DRC zero (LVS pending) |
| `rtr_top` | - | - | - | - | - | - | not run |
| `fpu4` | 101131 | 712822 | 3665444 | -48.87 | - | 38284 | GDS present (unvalidated) |
| `gsx` | 113334 | - | - | - | - | - | synthesized |
| `blit` | 2169 | 22326 | 81022 | 0.00 | 0 | 8652 | GDS; routing/Magic DRC zero (LVS pending) |
| `display` | 454 | 6061 | 16149 | 0.00 | 0 | 2100 | GDS; routing/Magic DRC zero (LVS pending) |
| `cp` | 7593 | 119186 | 568455 | 0.00 | 0 | 40451 | GDS; routing/Magic DRC zero (LVS pending) |
| `xbar` | 267 | 3187 | 68220 | 0.00 | 0 | 2571 | GDS; routing/Magic DRC zero (LVS pending) |
| `ram_slave` | 158 | 5573 | 22661 | 0.00 | 0 | 1850 | GDS; routing/Magic DRC zero (LVS pending) |
| `core` | 347494 | - | - | - | - | - | synthesized |
| `tu` | 257363 | - | - | - | - | - | synthesized |
