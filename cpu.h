#ifndef CPU_H
#define CPU_H

#include "global_decl.h"
#include "program_counter.h"
#include "memory.h"

class CPU{
    private:
        Registers registers;
        // For 8080 Registers are -
        // 111=A   (Accumulator)
        // 000=B
        // 001=C
        // 010=D
        // 011=E
        // 100=H
        // 101=L
        // 110=M 
        std::vector<bool> flags;
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
        Memory memory;
        Program_counter pc;
    public:
        CPU(addr_t memory_size);
        error_t load(std::vector<word_t>& instructions);
        word_t fetch();
        error_t execute(addr_t start);
};
#endif