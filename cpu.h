#ifndef CPU_H
#define CPU_H

#include "global_decl.h"
#include "program_counter.h"
#include "memory.h"
#include "opcode_handler.h"
#include "stack.h"

typedef void (*voidFunctionType)(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);


class CPU{
    private:
        Registers registers;
        
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
        std::vector<bool> flags;
        
        Memory memory;
        Program_counter pc;
        Opcode_handler opcode_handler;
        word_t interrrupt_addr; // Only 8 bits for ISRs start from 0x1
        Stack stack;
    public:
        CPU();
        error_t load(std::vector<word_t>& instructions);
        word_t fetch();
        error_t execute(addr_t start);
        std::vector<word_t> mem_dump(void);
        ~CPU();
};
#endif