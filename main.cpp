#include <iostream>
#include "emu.h"

int main(){
    std::cout<<"Hello"<<std::endl;
    CPU cpu = CPU();
    std::vector<word_t> instructions = {0x26, 0x00, 0x2E, 0x1A, 0x36, 0x10, 0x2E, 0x1B, 0x36, 0x10, 0x76};
    cpu.load(instructions);
    cpu.execute(0);
    std::vector<word_t> dump = cpu.mem_dump();
    for(int i = 0; i < 100; i++)
        std::cout<<(int)dump[i]<<" ";
    std::cout<<std::endl;
    return 0;
}