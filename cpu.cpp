#include "cpu.h"
#include "memory.h"
#include <iostream>
CPU::CPU() : stack(memory){
    memory = Memory(0xFFFF);
    pc = Program_counter(0);
    flags.assign(8, 0);
    flags[1] = 1; flags[3] = 0; flags[5] = 0;
    opcode_handler = Opcode_handler();
}

CPU::~CPU(){}

word_t CPU::fetch(){
    if(!memory.is_valid(pc.get_pc()));//exit violently
    return memory.get_word(pc.get_pc());
}

error_t CPU::execute(addr_t start){
    pc = Program_counter(start);
    while(true){
        word_t instruction = fetch();
        std::cout<<(int)instruction<<" ";
        if(instruction == 0x76)break;
        int param_count = opcode_handler.get_opcode_pcount(instruction);
        std::cout<<(int)param_count<<std::endl;
        voidFunctionType procedure = opcode_handler.get_opcode_procedure(instruction);
        if(param_count == 0){
            procedure(registers, flags, memory, stack, pc, 0, 0);
        }
        else if(param_count == 1){
            pc.increment();
            word_t word1 = fetch();
            procedure(registers, flags, memory, stack, pc, word1, 0);
        }
        else if(param_count == 2){
            pc.increment();
            word_t word1 = fetch();
            pc.increment();
            word_t word2 = fetch();
            procedure(registers, flags, memory, stack, pc, word1, word2);
        }
        pc.increment();
        if(interrrupt_addr != 0){
            addr_t a = pc.get_pc();
            stack.push(a >> (sizeof(word_t) * 8));             // higher byte
            stack.push(a &( (1 << (sizeof(word_t) * 8)) - 1)); // lower byte
            pc.set_pc((addr_t) interrrupt_addr);
        }
    }
    return 0;
}

error_t CPU::load(std::vector<word_t>& instructions){
    addr_t addr = 0;
    for(auto instruction : instructions){
        memory.set_word(addr, instruction);
        addr++;
    }
    return 0;
}

std::vector<word_t> CPU::mem_dump(){
    std::vector<word_t> dump;
    for(addr_t i = 0; i < 0xFFFF; i++){
        dump.push_back(memory.get_word(i));
    }
    return dump;
}
