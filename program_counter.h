#ifndef PROGRAM_COUNTER_H
#define PROGRAM_COUNTER_H

#include "global_decl.h"

class Program_counter
{
    private:
        word_t program_counter;
    public:
        Program_counter() = default;
        Program_counter(addr_t init_val);
        word_t get_pc();
        error_t increment();
        error_t add(addr_t off);
        ~Program_counter();
};

#endif