#ifndef STACK_H
#define STACK_H

#include "global_decl.h"
#include "memory.h"

class Stack{
    private:
        Memory& memory;
        addr_t sp; // Stack pointer, thank me later
    public:
        Stack() = default;
        Stack(Memory& mem, addr_t sp);
        error_t assign(addr_t w);
        error_t push(word_t w);
        word_t pop();
        addr_t get_sp();
        ~Stack();
};

#endif