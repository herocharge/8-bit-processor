#include "program_counter.h"

Program_counter::Program_counter(addr_t init_val){
    program_counter = init_val;
}

word_t Program_counter::get_pc(){
    return program_counter;
}

error_t Program_counter::increment(){
    program_counter++;
}

error_t Program_counter::add(addr_t off){
    program_counter += off;
}