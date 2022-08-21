#ifndef MEMORY_H
#define MEMORY_H

#include "global_decl.h"

class Memory{
    private:
        std::vector<word_t> memory;
        addr_t max_addr;
    public:
        Memory() = default;
        Memory(addr_t size);
        word_t get_word(addr_t addr);
        error_t set_word(addr_t addr, word_t word);
        bool is_valid(addr_t addr);
};

#endif