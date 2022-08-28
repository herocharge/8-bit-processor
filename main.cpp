#include <iostream>
#include "emu.h"

int main(){
    std::cout<<"Hello"<<std::endl;
    CPU cpu = CPU();
    std::vector<word_t> instructions = {0x76};
    cpu.load(instructions);
    cpu.execute(0);
    return 0;
}