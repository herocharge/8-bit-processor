#include "stack.h"

Stack::Stack(Memory& memory, word_t sp) : memory(memory), sp(sp){
    sp = 0xFFFF;
}

error_t Stack::push(word_t w){
    memory.set_word(sp, w);
    sp -= sizeof(word_t) * 8;
}

word_t Stack::pop(){
    memory.get_word(sp);
    sp += sizeof(word_t) * 8;
}

