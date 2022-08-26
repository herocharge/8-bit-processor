#ifndef STACK_H
#define STACK_H

#include "global_decl.h"
#include "memory.h"

class Stack{
    private:
        Memory& memory;
        word_t sp; // Stack pointer, thank me later
    public:
        Stack() = default;
        Stack(Memory& mem, word_t sp);
        error_t push(word_t w);
        word_t pop();
        ~Stack();
};

#endif