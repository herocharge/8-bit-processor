#include <iostream>
#include "emu.h"

int main(){
    std::cout<<"Hello"<<std::endl;
    CPU cpu = CPU();
    std::vector<word_t> instructions = {
/*0*/   0x26, // H <- 0x00
        0x00,  
        0x2E, // L <- 0x1A
        0x1A, 
        0x36, // (HL) <- x010
        0x10, 
        0x2E, // L <- 0x1B
        0x1B, 
        0x36, // (HL) <- 0x10
        0x10, 
        0x3E, // A <- 0
        0x00,
        0x3C, // A <- A + 1
        0xFE, // cmp A - 0x0A
        0x07,   
        0xDA, // JC to 0x000C
        0x00,
        0x0C,
        0x32, // (0x001A) <- A
        0x00,
        0x1A,
        0x76  // HALT
    };
    cpu.load(instructions);
    cpu.execute(0);
    std::vector<word_t> dump = cpu.mem_dump();
    for(int i = 0; i < 100; i++)
        std::cout<<(int)dump[i]<<" ";
    std::cout<<std::endl;
    return 0;
}