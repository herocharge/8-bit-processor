#ifndef OPCODE_HANDLER
#define OPCODE_HANDLER

#include "global_decl.h"
#include <unordered_map>
#include "procedures.h"
typedef void (*voidFunctionType)(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

class Opcode_handler
{
    private:
        std::unordered_map<word_t, voidFunctionType> procedures;
        std::unordered_map<word_t, uint8_t> parameter_count;
    public:
        Opcode_handler();
        uint8_t get_opcode_pcount(word_t opcode);
        voidFunctionType get_opcode_procedure(word_t opcode);
        bool is_valid(word_t opcode);
};



#endif