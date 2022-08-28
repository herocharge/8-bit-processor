#include "stack.h"


Stack::Stack(Memory& mem) : memory(mem){
    memory = mem;
    sp = 0xFFFF;
}
Stack::~Stack(){}

error_t Stack::push(word_t w){
    memory.set_word(sp, w);
    sp -= 1;
    return 0;
}

word_t Stack::pop(){
    word_t word = memory.get_word(sp);
    sp += 1;
    return word;
}

error_t Stack::assign(addr_t w){
    sp = w;
    return 0;
}

addr_t Stack::get_sp(){
    return sp;
}