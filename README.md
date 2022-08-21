## 8 bit processor
I am trying to recreate the intel 8080 processor virtually, the goal is to just be able to process the opcodes and simulate the memory in an array or smtg.
### Goal:
- simulate a processor?
- Make a processor + memory + minimal i/o support

### Notes
- opcodes
- memory
- cpu
- registers


// 7	6	5	4	3	2	1	0
    // S    Z	0	A	0	P	1	C

    // S - Sign Flag
    // Z - Zero Flag
    // 0 - Not used, always zero
    // A - also called AC, Auxiliary Carry Flag
    // 0 - Not used, always zero
    // P - Parity Flag
    // 1 - Not used, always one
    // C - Carry Flag