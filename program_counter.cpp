#include "program_counter.h"

Program_counter::Program_counter(addr_t init_val){
    program_counter = init_val;
}

addr_t Program_counter::get_pc(){
    return program_counter;
}

error_t Program_counter::set_pc(addr_t addr){
   program_counter = addr;
   return 0;
}

error_t Program_counter::increment(){
    program_counter++;
    return 0;
}

error_t Program_counter::add(addr_t off){
    program_counter += off;
    return 0;
}