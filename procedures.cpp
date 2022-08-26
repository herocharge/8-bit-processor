#include "global_decl.h"
#include "memory.h"

void NOP_0x00(Registers& registers, Memory& memory, Stack& stack){}
void MOVAA_0x7F(Registers& registers, Memory& memory, Stack& stack){
    registers.A = registers.A;
}
void MOVAB_0x78(Registers& registers, Memory& memory, Stack& stack){
    registers.A = registers.B;
}
void MOVAC_0x79(Registers& registers, Memory& memory, Stack& stack){
    registers.A = registers.C;
}
void MOVAD_0x7A(Registers& registers, Memory& memory, Stack& stack){
    registers.A = registers.D;
}
void MOVAE_0x7B(Registers& registers, Memory& memory, Stack& stack){
    registers.A = registers.E;
}
void MOVAH_0x7C(Registers& registers, Memory& memory, Stack& stack){
    registers.A = registers.H;
}
void MOVAL_0x7D(Registers& registers, Memory& memory, Stack& stack){
    registers.A = registers.L;
}
void MOVAM_0x7E(Registers& registers, Memory& memory, Stack& stack){
    registers.A = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}
void LDAXB_0x0A(Registers& registers, Memory& memory, Stack& stack){
    registers.A = memory.get_word((((addr_t)registers.B) << (8 * sizeof(word_t))) + registers.C); 
}
void LDAXD_0x1A(Registers& registers, Memory& memory, Stack& stack){
    registers.A = memory.get_word((((addr_t)registers.D) << (8 * sizeof(word_t)) )+ registers.E); 
}
void LDA_0x3Aword(Registers& registers, Memory& memory, Stack& stack, word_t word){
    registers.A = memory.get_word(word); 
}
// TODO: implement z80 style instructions as well maybe

void MOVBA_0x47(Registers& registers, Memory& memory, Stack& stack){
    registers.B = registers.A;
}
void MOVBB_0x40(Registers& registers, Memory& memory, Stack& stack){
    registers.B = registers.B;
}
void MOVBC_0x41(Registers& registers, Memory& memory, Stack& stack){
    registers.B = registers.C;
}
void MOVBD_0x42(Registers& registers, Memory& memory, Stack& stack){
    registers.B = registers.D;
}
void MOVBE_0x43(Registers& registers, Memory& memory, Stack& stack){
    registers.B = registers.E;
}
void MOVBH_0x44(Registers& registers, Memory& memory, Stack& stack){
    registers.B = registers.H;
}
void MOVBL_0x45(Registers& registers, Memory& memory, Stack& stack){
    registers.B = registers.L;
}
void MOVBM_0x46(Registers& registers, Memory& memory, Stack& stack){
    registers.B = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVCA_0x4F(Registers& registers, Memory& memory, Stack& stack){
    registers.C = registers.A;
}
void MOVCB_0x48(Registers& registers, Memory& memory, Stack& stack){
    registers.C = registers.B;
}
void MOVCC_0x49(Registers& registers, Memory& memory, Stack& stack){
    registers.C = registers.C;
}
void MOVCD_0x4A(Registers& registers, Memory& memory, Stack& stack){
    registers.C = registers.D;
}
void MOVCE_0x4B(Registers& registers, Memory& memory, Stack& stack){
    registers.C = registers.E;
}
void MOVCH_0x4C(Registers& registers, Memory& memory, Stack& stack){
    registers.C = registers.H;
}
void MOVCL_0x4D(Registers& registers, Memory& memory, Stack& stack){
    registers.C = registers.L;
}
void MOVCM_0x4E(Registers& registers, Memory& memory, Stack& stack){
    registers.C = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVDA_0x57(Registers& registers, Memory& memory, Stack& stack){
    registers.D = registers.A;
}
void MOVDB_0x50(Registers& registers, Memory& memory, Stack& stack){
    registers.D = registers.B;
}
void MOVDC_0x51(Registers& registers, Memory& memory, Stack& stack){
    registers.D = registers.C;
}
void MOVDD_0x52(Registers& registers, Memory& memory, Stack& stack){
    registers.D = registers.D;
}
void MOVDE_0x53(Registers& registers, Memory& memory, Stack& stack){
    registers.D = registers.E;
}
void MOVDH_0x54(Registers& registers, Memory& memory, Stack& stack){
    registers.D = registers.H;
}
void MOVDL_0x55(Registers& registers, Memory& memory, Stack& stack){
    registers.D = registers.L;
}
void MOVDM_0x56(Registers& registers, Memory& memory, Stack& stack){
    registers.D = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVEA_0x5F(Registers& registers, Memory& memory, Stack& stack){
    registers.E = registers.A;
}
void MOVEB_0x58(Registers& registers, Memory& memory, Stack& stack){
    registers.E = registers.B;
}
void MOVEC_0x59(Registers& registers, Memory& memory, Stack& stack){
    registers.E = registers.C;
}
void MOVED_0x5A(Registers& registers, Memory& memory, Stack& stack){
    registers.E = registers.D;
}
void MOVEE_0x5B(Registers& registers, Memory& memory, Stack& stack){
    registers.E = registers.E;
}
void MOVEH_0x5C(Registers& registers, Memory& memory, Stack& stack){
    registers.E = registers.H;
}
void MOVEL_0x5D(Registers& registers, Memory& memory, Stack& stack){
    registers.E = registers.L;
}
void MOVEM_0x5E(Registers& registers, Memory& memory, Stack& stack){
    registers.E = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVHA_0x67(Registers& registers, Memory& memory, Stack& stack){
    registers.H = registers.A;
}
void MOVHB_0x60(Registers& registers, Memory& memory, Stack& stack){
    registers.H = registers.B;
}
void MOVHC_0x61(Registers& registers, Memory& memory, Stack& stack){
    registers.H = registers.C;
}
void MOVHD_0x62(Registers& registers, Memory& memory, Stack& stack){
    registers.H = registers.D;
}
void MOVHE_0x63(Registers& registers, Memory& memory, Stack& stack){
    registers.H = registers.E;
}
void MOVHH_0x64(Registers& registers, Memory& memory, Stack& stack){
    registers.H = registers.H;
}
void MOVHL_0x65(Registers& registers, Memory& memory, Stack& stack){
    registers.H = registers.L;
}
void MOVHM_0x66(Registers& registers, Memory& memory, Stack& stack){
    registers.H = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVLA_0x6F(Registers& registers, Memory& memory, Stack& stack){
    registers.L = registers.A;
}
void MOVLB_0x68(Registers& registers, Memory& memory, Stack& stack){
    registers.L = registers.B;
}
void MOVLC_0x69(Registers& registers, Memory& memory, Stack& stack){
    registers.L = registers.C;
}
void MOVLD_0x6A(Registers& registers, Memory& memory, Stack& stack){
    registers.L = registers.D;
}
void MOVLE_0x6B(Registers& registers, Memory& memory, Stack& stack){
    registers.L = registers.E;
}
void MOVLH_0x6C(Registers& registers, Memory& memory, Stack& stack){
    registers.L = registers.H;
}
void MOVLL_0x6D(Registers& registers, Memory& memory, Stack& stack){
    registers.L = registers.L;
}
void MOVLM_0x6E(Registers& registers, Memory& memory, Stack& stack){
    registers.L = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVMA_0x77(Registers& registers, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.A);
}
void MOVMB_0x70(Registers& registers, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.B);
}
void MOVMC_0x71(Registers& registers, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.C);
}
void MOVMD_0x72(Registers& registers, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.D);
}
void MOVME_0x73(Registers& registers, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.E);
}
void MOVMH_0x74(Registers& registers, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.H);
}
void MOVML_0x75(Registers& registers, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.L);
}

void MVIA_0x3Eword(Registers& registers, Memory& memory, Stack& stack, word_t word){
    registers.A = word;
}
void MVIB_0x06word(Registers& registers, Memory& memory, Stack& stack, word_t word){
    registers.B = word;
}
void MVIC_0x0Eword(Registers& registers, Memory& memory, Stack& stack, word_t word){
    registers.C = word;
}
void MVID_0x16word(Registers& registers, Memory& memory, Stack& stack, word_t word){
    registers.D = word;
}
void MVIE_0x1Eword(Registers& registers, Memory& memory, Stack& stack, word_t word){
    registers.E = word;
}
void MVIH_0x26word(Registers& registers, Memory& memory, Stack& stack, word_t word){
    registers.H = word;
}
void MVIL_0x2Eword(Registers& registers, Memory& memory, Stack& stack, word_t word){
    registers.L = word;
}
void MVIM_0x36word(Registers& registers, Memory& memory, Stack& stack, word_t word){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, word);
}

void STAXB_0x02(Registers& registers, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.B) << (8 * sizeof(word_t))) + registers.C;
    memory.set_word(addr, registers.A);
}
void STAXD_0x12(Registers& registers, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.D) << (8 * sizeof(word_t))) + registers.E;
    memory.set_word(addr, registers.A);
}

void STA_0x32word(Registers& registers, Memory& memory, Stack& stack, word_t word){
    memory.set_word(word, registers.A);
}

// TODO: implement LXI and 16 bit transfer instructions 
