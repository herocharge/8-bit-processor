#include <iostream>
#include "memory.h"

Memory::Memory(int size){
    memory.assign(size, 0);
    max_addr = size;
}
word_t Memory::get_word(addr_t addr){
    if(addr > max_addr){
        std::cout<<"Error: Address exceeded max memory"<<std::endl;
        return 0;  // Violently exit
    }
    return memory[addr];
}
error_t Memory::set_word(addr_t addr, word_t word){
    if(addr > max_addr){
        std::cout<<"Error: Address exceeded max memory"<<std::endl;
        return 1;  // Violently exit
    }
    memory[addr] = word;
    return 0;
}
bool Memory::is_valid(addr_t addr){
    if(addr > max_addr)return false;
    return true;
}
