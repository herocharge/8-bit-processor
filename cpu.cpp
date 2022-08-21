#include "cpu.h"
#include "memory.h"

CPU::CPU(addr_t memory_size){
    memory = Memory(memory_size);
    pc = Program_counter(0);
    flags.assign(8, 0); 
    flags[1] = 1; flags[3] = 0; flags[5] = 0; 
}

word_t CPU::fetch(){
    if(!memory.is_valid(pc.get_pc()));//exit violently
    return memory.get_word(pc.get_pc());
}

error_t CPU::execute(addr_t start){
    pc = Program_counter(start);
    while(true){
        word_t instruction = fetch();

        pc.increment();
    }
}
