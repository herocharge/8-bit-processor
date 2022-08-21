#include "opcode_handler.h"

Opcode_handler::Opcode_handler(){
    
}

bool Opcode_handler::is_valid(word_t opcode){
    return opcode <= 0x7f;
}

uint8_t Opcode_handler::get_opcode_pcount(word_t opcode){
    if(!is_valid(opcode))return 0; // Exit 
    return parameter_count[opcode];
}