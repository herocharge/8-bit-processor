#include "procedures.h"
#include <iostream>
addr_t wtod(word_t a, word_t b){
    return (((addr_t)a) << (8 * sizeof(word_t))) + b;
}

word_t higher_byte(addr_t a){
    return a >> (sizeof(word_t) * 8);
}
word_t lower_byte(addr_t a){
    return a &( (1 << (sizeof(word_t) * 8)) - 1);
}

int get_bit(word_t w, int pos){
    return (w << (pos)) > 0;
}

bool is_neg(word_t w){
    return (get_bit(w, 7));
}

void set_cmp_flags(std::vector<bool>& flags, word_t res, word_t a, word_t b){
    flags[SIGN] = is_neg(res);
    std::cout<<(int)(a < b)<<std::endl;
    flags[CARRY] = (a < b);
    flags[ZERO] = (res == 0);
    flags[PARITY] = (res&1);
}

void NOP_0x00(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){}
void MOVAA_0x7F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = registers.A;
}
void MOVAB_0x78(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = registers.B;
}
void MOVAC_0x79(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = registers.C;
}
void MOVAD_0x7A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = registers.D;
}
void MOVAE_0x7B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = registers.E;
}
void MOVAH_0x7C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = registers.H;
}
void MOVAL_0x7D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = registers.L;
}
void MOVAM_0x7E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}
void LDAXB_0x0A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = memory.get_word((((addr_t)registers.B) << (8 * sizeof(word_t))) + registers.C); 
}
void LDAXD_0x1A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = memory.get_word((((addr_t)registers.D) << (8 * sizeof(word_t)) )+ registers.E); 
}
void LDA_0x3Aword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = memory.get_word(word1); 
}
// TODO: implement z80 style instructions as well maybe

void MOVBA_0x47(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B = registers.A;
}
void MOVBB_0x40(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B = registers.B;
}
void MOVBC_0x41(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B = registers.C;
}
void MOVBD_0x42(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B = registers.D;
}
void MOVBE_0x43(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B = registers.E;
}
void MOVBH_0x44(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B = registers.H;
}
void MOVBL_0x45(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B = registers.L;
}
void MOVBM_0x46(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVCA_0x4F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.C = registers.A;
}
void MOVCB_0x48(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.C = registers.B;
}
void MOVCC_0x49(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.C = registers.C;
}
void MOVCD_0x4A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.C = registers.D;
}
void MOVCE_0x4B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.C = registers.E;
}
void MOVCH_0x4C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.C = registers.H;
}
void MOVCL_0x4D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.C = registers.L;
}
void MOVCM_0x4E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.C = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVDA_0x57(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D = registers.A;
}
void MOVDB_0x50(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D = registers.B;
}
void MOVDC_0x51(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D = registers.C;
}
void MOVDD_0x52(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D = registers.D;
}
void MOVDE_0x53(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D = registers.E;
}
void MOVDH_0x54(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D = registers.H;
}
void MOVDL_0x55(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D = registers.L;
}
void MOVDM_0x56(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVEA_0x5F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.E = registers.A;
}
void MOVEB_0x58(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.E = registers.B;
}
void MOVEC_0x59(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.E = registers.C;
}
void MOVED_0x5A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.E = registers.D;
}
void MOVEE_0x5B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.E = registers.E;
}
void MOVEH_0x5C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.E = registers.H;
}
void MOVEL_0x5D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.E = registers.L;
}
void MOVEM_0x5E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.E = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVHA_0x67(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H = registers.A;
}
void MOVHB_0x60(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H = registers.B;
}
void MOVHC_0x61(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H = registers.C;
}
void MOVHD_0x62(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H = registers.D;
}
void MOVHE_0x63(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H = registers.E;
}
void MOVHH_0x64(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H = registers.H;
}
void MOVHL_0x65(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H = registers.L;
}
void MOVHM_0x66(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVLA_0x6F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.L = registers.A;
}
void MOVLB_0x68(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.L = registers.B;
}
void MOVLC_0x69(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.L = registers.C;
}
void MOVLD_0x6A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.L = registers.D;
}
void MOVLE_0x6B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.L = registers.E;
}
void MOVLH_0x6C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.L = registers.H;
}
void MOVLL_0x6D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.L = registers.L;
}
void MOVLM_0x6E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.L = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVMA_0x77(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.A);
}
void MOVMB_0x70(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.B);
}
void MOVMC_0x71(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.C);
}
void MOVMD_0x72(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.D);
}
void MOVME_0x73(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.E);
}
void MOVMH_0x74(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.H);
}
void MOVML_0x75(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.L);
}

void MVIA_0x3Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A = word1;
}
void MVIB_0x06word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B = word1;
}
void MVIC_0x0Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.C = word1;
}
void MVID_0x16word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D = word1;
}
void MVIE_0x1Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.E = word1;
}
void MVIH_0x26word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H = word1;
}
void MVIL_0x2Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.L = word1;
}
void MVIM_0x36word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, word1);
}

void STAXB_0x02(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = (((addr_t)registers.B) << (8 * sizeof(word_t))) + registers.C;
    memory.set_word(addr, registers.A);
}
void STAXD_0x12(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = (((addr_t)registers.D) << (8 * sizeof(word_t))) + registers.E;
    memory.set_word(addr, registers.A);
}

void STA_0x32doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    memory.set_word(wtod(word1, word2), registers.A);
}

// TODO: implement LXI and 16 bit transfer instructions // done

void LXIBC_0x01doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B = word1;
    registers.C = word2;
}
void LXIDE_0x11doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D = word1;
    registers.E = word2;
}
void LXIHL_0x21doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H = word1;
    registers.L = word2;
}
void LXISP_0x31doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    stack.assign(((addr_t)word1 << (sizeof(word_t) * 8)) + word2);
}

// Leaving out LHLD, SHLD, SPHL for now

void XCHNG_0xEB(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    word_t tmp = registers.H;
    registers.H = registers.D;
    registers.D = tmp;

    tmp = registers.L;
    registers.L = registers.E;
    registers.E = tmp;
}

void XTHL_0xE3(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    word_t tmp = registers.H;
    registers.H = memory.get_word(stack.get_sp() + 1);
    memory.set_word(stack.get_sp() + 1, tmp);

    tmp = registers.L;
    registers.L = memory.get_word(stack.get_sp());
    memory.set_word(stack.get_sp(), tmp);
}

// TODO: Flag setting

void ADDA_0x87(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.A;
}
void ADDB_0x80(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.B;
}
void ADDC_0x81(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.C;
}
void ADDD_0x82(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.D;
}
void ADDE_0x83(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.E;
}
void ADDH_0x84(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.H;
}
void ADDL_0x85(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.L;
}
void ADDM_0x86(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = wtod(registers.H, registers.L);
    registers.A += memory.get_word(addr); 
}
void ADI_0xC6word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += word1;
}

void ADCA_0x8F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.A + flags[0];
}
void ADCB_0x88(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.B + flags[0];
}
void ADCC_0x89(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.C + flags[0];
}
void ADCD_0x8A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.D + flags[0];
}
void ADCE_0x8B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.E + flags[0];
}
void ADCH_0x8C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.H + flags[0];
}
void ADCL_0x8D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += registers.L + flags[0];
}
void ADCM_0x8E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = wtod(registers.H, registers.L);
    registers.A += memory.get_word(addr) + flags[0]; 
}
void ACI_0xCEword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A += word1 + flags[0];
}


void SUBA_0x97(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.A;
}
void SUBB_0x90(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.B;
}
void SUBC_0x91(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.C;
}
void SUBD_0x92(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.D;
}
void SUBE_0x93(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.E;
}
void SUBH_0x94(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.H;
}
void SUBL_0x95(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.L;
}
void SUBM_0x96(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = wtod(registers.H, registers.L);
    registers.A -= memory.get_word(addr); 
}
void SUI_0xD6word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= word1;
}

void SBBA_0x9F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.A + flags[0];
}
void SBBB_0x98(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.B + flags[0];
}
void SBBC_0x99(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.C + flags[0];
}
void SBBD_0x9A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.D + flags[0];
}
void SBBE_0x9B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.E + flags[0];
}
void SBBH_0x9C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.H + flags[0];
}
void SBBL_0x9D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= registers.L + flags[0];
}
void SBBM_0x9E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = wtod(registers.H, registers.L);
    registers.A -= memory.get_word(addr) + flags[0]; 
}
void SBI_0xDEword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A -= word1 + flags[0];
}

void DADBC_0x09(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t one = wtod(registers.B, registers.C);
    addr_t two = wtod(registers.H, registers.L);
    two += one;
    registers.H = higher_byte(two);
    registers.L = lower_byte(two);
}

void DADDE_0x19(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t one = wtod(registers.D, registers.E);
    addr_t two = wtod(registers.H, registers.L);
    two += one;
    registers.H = higher_byte(two);
    registers.L = lower_byte(two);
}

void DADHL_0x29(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t one = wtod(registers.H, registers.L);
    addr_t two = wtod(registers.H, registers.L);
    two += one;
    registers.H = higher_byte(two);
    registers.L = lower_byte(two);
}

void DADSP_0x39(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t one = stack.get_sp();
    addr_t two = wtod(registers.H, registers.L);
    two += one;
    registers.H = higher_byte(two);
    registers.L = lower_byte(two);
}

// TODO: DI, EI, -> what are these?, HLT

void INRA_0x3C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A++;
}
void INRB_0x04(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B++;
}
void INRC_0x0C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.C++;
}
void INRD_0x14(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D++;
}
void INRE_0x1C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.E++;
}
void INRH_0x24(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H++;
}
void INRL_0x2C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.L++;
}
void INRM_0x34(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = wtod(registers.H, registers.L);
    word_t word = memory.get_word(addr);
    memory.set_word(addr, word + 1);
}

void DCRA_0x3D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A--;
}
void DCRB_0x05(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.B--;
}
void DCRC_0x0D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.C--;
}
void DCRD_0x15(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.D--;
}
void DCRE_0x1D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.E--;
}
void DCRH_0x25(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.H--;
}
void DCRL_0x2D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.L--;
}
void DCRM_0x35(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = wtod(registers.H, registers.L);
    word_t word = memory.get_word(addr);
    memory.set_word(addr, word - 1);
}

void INXBC_0x03(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t dword = wtod(registers.B, registers.C);
    dword++;
    registers.B = higher_byte(dword);
    registers.C = higher_byte(dword);
}
void INXDE_0x13(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t dword = wtod(registers.D, registers.E);
    dword++;
    registers.D = higher_byte(dword);
    registers.E = higher_byte(dword);
}
void INXHL_0x23(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t dword = wtod(registers.H, registers.L);
    dword++;
    registers.H = higher_byte(dword);
    registers.L = higher_byte(dword);
}
void INXSP_0x33(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t dword = stack.get_sp();
    dword++;
    stack.assign(dword);
}

void DCXBC_0x0B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t dword = wtod(registers.B, registers.C);
    dword--;
    registers.B = higher_byte(dword);
    registers.C = higher_byte(dword);
}
void DCXDE_0x1B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t dword = wtod(registers.D, registers.E);
    dword--;
    registers.D = higher_byte(dword);
    registers.E = higher_byte(dword);
}
void DCXHL_0x2B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t dword = wtod(registers.H, registers.L);
    dword--;
    registers.H = higher_byte(dword);
    registers.L = higher_byte(dword);
}
void DCXSP_0x3B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t dword = stack.get_sp();
    dword--;
    stack.assign(dword);
}

// TODO: Special Accumulator and Flag Instructions

void RLC_0x07(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    flags[CARRY] = get_bit(registers.A, 7);
    registers.A <<= 1;
    registers.A |= flags[CARRY];
}
void RRC_0x0F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    flags[CARRY] = get_bit(registers.A, 0);
    registers.A >>= 1;
    registers.A |= ((word_t)flags[CARRY] << 7);
}
void RAL_0x17(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    flags[CARRY] = get_bit(registers.A, 7);
    registers.A <<= 1;
}
void RAR_0x1F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    flags[CARRY] = get_bit(registers.A, 0);
    registers.A >>= 1;
}


void ANAA_0xA7(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A &= registers.A;
}
void ANAB_0xA0(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A &= registers.B;
}
void ANAC_0xA1(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A &= registers.C;
}
void ANAD_0xA2(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A &= registers.D;
}
void ANAE_0xA3(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A &= registers.E;
}
void ANAH_0xA4(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A &= registers.H;
}
void ANAL_0xA5(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A &= registers.L;
}
void ANAM_0xA6(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = wtod(registers.H, registers.L);
    registers.A &= memory.get_word(addr); 
}
void ANI_0xE6word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A &= word1;
}

void XRAA_0xAF(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A ^= registers.A;
}
void XRAB_0xA8(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A ^= registers.B;
}
void XRAC_0xA9(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A ^= registers.C;
}
void XRAD_0xAA(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A ^= registers.D;
}
void XRAE_0xAB(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A ^= registers.E;
}
void XRAH_0xAC(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A ^= registers.H;
}
void XRAL_0xAD(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A ^= registers.L;
}
void XRAM_0xAE(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = wtod(registers.H, registers.L);
    registers.A ^= memory.get_word(addr); 
}
void XRI_0xEEword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A &= word1;
}


void ORAA_0xB7(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A |= registers.A;
}
void ORAB_0xB0(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A |= registers.B;
}
void ORAC_0xB1(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A |= registers.C;
}
void ORAD_0xB2(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A |= registers.D;
}
void ORAE_0xB3(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A |= registers.E;
}
void ORAH_0xB4(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A |= registers.H;
}
void ORAL_0xB5(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A |= registers.L;
}
void ORAM_0xB6(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    addr_t addr = wtod(registers.H, registers.L);
    registers.A |= memory.get_word(addr); 
}
void ORI_0xF6word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    registers.A |= word1;
}

void CMPA_0xBF(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    set_cmp_flags(flags, registers.A - registers.A, registers.A, registers.A);
}
void CMPB_0xB8(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    set_cmp_flags(flags, registers.A - registers.B, registers.A, registers.B);
}
void CMPC_0xB9(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    set_cmp_flags(flags, registers.A - registers.C, registers.A, registers.C);
}
void CMPD_0xBA(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    set_cmp_flags(flags, registers.A - registers.D, registers.A, registers.D);
}
void CMPE_0xBB(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    set_cmp_flags(flags, registers.A - registers.E, registers.A, registers.E);
}
void CMPH_0xBC(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    set_cmp_flags(flags, registers.A - registers.H, registers.A, registers.H);
}
void CMPL_0xBD(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    set_cmp_flags(flags, registers.A - registers.L, registers.A, registers.L);
}
void CMPM_0xBE(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    word_t word = memory.get_word(wtod(registers.H, registers.L));
    set_cmp_flags(flags, registers.A - word, registers.A, word);
}
void CPI_0xFEword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    set_cmp_flags(flags, registers.A - word1, registers.A, word1);
    std::cout<<(int)registers.A<<std::endl;
    std::cout<<(int)word1<<std::endl;
    std::cout<<(int)(registers.A < word1)<<std::endl;
}

void JMP_0xC3doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    pc.set_pc(wtod(word1, word2) - 1); // -1 so that it goes to right place after increment
}
void JNZ_0xC2doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(!flags[ZERO])
        pc.set_pc(wtod(word1, word2) - 1); 
}
void JZ_0xCAdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(flags[ZERO])
        pc.set_pc(wtod(word1, word2) - 1); 
}
void JNC_0xD2doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(!flags[CARRY])
        pc.set_pc(wtod(word1, word2) - 1); 
}
void JC_0xDAdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(flags[CARRY])
        pc.set_pc(wtod(word1, word2) - 1); 
}
void JPO_0xE2doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(flags[PARITY])
        pc.set_pc(wtod(word1, word2) - 1); 
}
void JPE_0xEAdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(!flags[PARITY])
        pc.set_pc(wtod(word1, word2) - 1); 
}
void JP_0xF2doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(!flags[SIGN])
        pc.set_pc(wtod(word1, word2) - 1); 
}
void JM_0xFAdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(flags[SIGN])
        pc.set_pc(wtod(word1, word2) - 1); 
}
void PCHL_0xE9(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    pc.set_pc(memory.get_word(wtod(registers.H, registers.L)) - 1);
}

void CALL_0XCDdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    stack.push(higher_byte(pc.get_pc()));
    stack.push(lower_byte(pc.get_pc()));
    pc.set_pc(wtod(word1, word2) - 1); // -1 to account for increment later
}

void CNZ_0xC4doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(!flags[ZERO])
        CALL_0XCDdoubleword(registers, flags, memory, stack, pc, word1, word2);
}
void CZ_0xCCdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(flags[ZERO])
        CALL_0XCDdoubleword(registers, flags, memory, stack, pc, word1, word2);
}
void CNC_0xD4doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(!flags[CARRY])
        CALL_0XCDdoubleword(registers, flags, memory, stack, pc, word1, word2);
}
void CC_0xDCdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    if(flags[CARRY])
        CALL_0XCDdoubleword(registers, flags, memory, stack, pc, word1, word2);
}

void RET_0xC9(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2){
    pc.set_pc(wtod(memory.get_word(stack.get_sp()), memory.get_word(stack.get_sp() + 1)));
    stack.pop();
    stack.pop();
    // Dont pop inside the wtod function since parameter evaluation order is not defined
}

// Skipping conditional return coz im too tired