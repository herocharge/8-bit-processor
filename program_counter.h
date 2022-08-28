#ifndef PROGRAM_COUNTER_H
#define PROGRAM_COUNTER_H

#include "global_decl.h"

class Program_counter
{
    private:
        addr_t program_counter;
    public:
        Program_counter() = default;
        Program_counter(addr_t init_val);
        addr_t get_pc();
        error_t set_pc(addr_t addr);
        error_t increment();
        error_t add(addr_t off);
        ~Program_counter();
};

#endif