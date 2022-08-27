#include "stack.h"

Stack::Stack(Memory& memory, addr_t sp) : memory(memory), sp(sp){
    sp = 0xFFFF;
}

error_t Stack::push(word_t w){
    memory.set_word(sp, w);
    sp -= 1;
}

word_t Stack::pop(){
    memory.get_word(sp);
    sp += 1;
}

error_t Stack::assign(addr_t w){
    sp = w;
}

addr_t Stack::get_sp(){
    return sp;
}