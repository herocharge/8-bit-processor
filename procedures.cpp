#include "global_decl.h"
#include "memory.h"
#include "stack.h"

void NOP_0x00(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){}
void MOVAA_0x7F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A = registers.A;
}
void MOVAB_0x78(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A = registers.B;
}
void MOVAC_0x79(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A = registers.C;
}
void MOVAD_0x7A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A = registers.D;
}
void MOVAE_0x7B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A = registers.E;
}
void MOVAH_0x7C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A = registers.H;
}
void MOVAL_0x7D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A = registers.L;
}
void MOVAM_0x7E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}
void LDAXB_0x0A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A = memory.get_word((((addr_t)registers.B) << (8 * sizeof(word_t))) + registers.C); 
}
void LDAXD_0x1A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A = memory.get_word((((addr_t)registers.D) << (8 * sizeof(word_t)) )+ registers.E); 
}
void LDA_0x3Aword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.A = memory.get_word(word); 
}
// TODO: implement z80 style instructions as well maybe

void MOVBA_0x47(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.B = registers.A;
}
void MOVBB_0x40(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.B = registers.B;
}
void MOVBC_0x41(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.B = registers.C;
}
void MOVBD_0x42(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.B = registers.D;
}
void MOVBE_0x43(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.B = registers.E;
}
void MOVBH_0x44(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.B = registers.H;
}
void MOVBL_0x45(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.B = registers.L;
}
void MOVBM_0x46(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.B = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVCA_0x4F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.C = registers.A;
}
void MOVCB_0x48(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.C = registers.B;
}
void MOVCC_0x49(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.C = registers.C;
}
void MOVCD_0x4A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.C = registers.D;
}
void MOVCE_0x4B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.C = registers.E;
}
void MOVCH_0x4C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.C = registers.H;
}
void MOVCL_0x4D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.C = registers.L;
}
void MOVCM_0x4E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.C = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVDA_0x57(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.D = registers.A;
}
void MOVDB_0x50(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.D = registers.B;
}
void MOVDC_0x51(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.D = registers.C;
}
void MOVDD_0x52(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.D = registers.D;
}
void MOVDE_0x53(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.D = registers.E;
}
void MOVDH_0x54(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.D = registers.H;
}
void MOVDL_0x55(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.D = registers.L;
}
void MOVDM_0x56(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.D = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVEA_0x5F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.E = registers.A;
}
void MOVEB_0x58(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.E = registers.B;
}
void MOVEC_0x59(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.E = registers.C;
}
void MOVED_0x5A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.E = registers.D;
}
void MOVEE_0x5B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.E = registers.E;
}
void MOVEH_0x5C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.E = registers.H;
}
void MOVEL_0x5D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.E = registers.L;
}
void MOVEM_0x5E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.E = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVHA_0x67(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.H = registers.A;
}
void MOVHB_0x60(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.H = registers.B;
}
void MOVHC_0x61(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.H = registers.C;
}
void MOVHD_0x62(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.H = registers.D;
}
void MOVHE_0x63(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.H = registers.E;
}
void MOVHH_0x64(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.H = registers.H;
}
void MOVHL_0x65(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.H = registers.L;
}
void MOVHM_0x66(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.H = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVLA_0x6F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.L = registers.A;
}
void MOVLB_0x68(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.L = registers.B;
}
void MOVLC_0x69(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.L = registers.C;
}
void MOVLD_0x6A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.L = registers.D;
}
void MOVLE_0x6B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.L = registers.E;
}
void MOVLH_0x6C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.L = registers.H;
}
void MOVLL_0x6D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.L = registers.L;
}
void MOVLM_0x6E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.L = memory.get_word((((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L); 
}

void MOVMA_0x77(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.A);
}
void MOVMB_0x70(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.B);
}
void MOVMC_0x71(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.C);
}
void MOVMD_0x72(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.D);
}
void MOVME_0x73(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.E);
}
void MOVMH_0x74(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.H);
}
void MOVML_0x75(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, registers.L);
}

void MVIA_0x3Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.A = word;
}
void MVIB_0x06word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.B = word;
}
void MVIC_0x0Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.C = word;
}
void MVID_0x16word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.D = word;
}
void MVIE_0x1Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.E = word;
}
void MVIH_0x26word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.H = word;
}
void MVIL_0x2Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.L = word;
}
void MVIM_0x36word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    addr_t addr = (((addr_t)registers.H) << (8 * sizeof(word_t))) + registers.L;
    memory.set_word(addr, word);
}

void STAXB_0x02(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.B) << (8 * sizeof(word_t))) + registers.C;
    memory.set_word(addr, registers.A);
}
void STAXD_0x12(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = (((addr_t)registers.D) << (8 * sizeof(word_t))) + registers.E;
    memory.set_word(addr, registers.A);
}

void STA_0x32word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    memory.set_word(word, registers.A);
}

// TODO: implement LXI and 16 bit transfer instructions // done

void LXIBC_0x01doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word1, word_t word2){
    registers.B = word1;
    registers.C = word2;
}
void LXIDE_0x11doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word1, word_t word2){
    registers.D = word1;
    registers.E = word2;
}
void LXIHL_0x21doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word1, word_t word2){
    registers.H = word1;
    registers.L = word2;
}
void LXISP_0x31doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word1, word_t word2){
    stack.assign(((addr_t)word1 << (sizeof(word_t) * 8)) + word2);
}

// Leaving out LHLD, SHLD, SPHL for now

void XCHNG_0xEB(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    word_t tmp = registers.H;
    registers.H = registers.D;
    registers.D = tmp;

    tmp = registers.L;
    registers.L = registers.E;
    registers.E = tmp;
}

void XCHNG_0xEB(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    word_t tmp = registers.H;
    registers.H = memory.get_word(stack.get_sp() + 1);
    memory.set_word(stack.get_sp() + 1, tmp);

    tmp = registers.L;
    registers.L = memory.get_word(stack.get_sp());
    memory.set_word(stack.get_sp(), tmp);
}

// TODO: Flag setting

void ADDA_0x87(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.A;
}
void ADDB_0x80(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.B;
}
void ADDC_0x81(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.C;
}
void ADDD_0x82(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.D;
}
void ADDE_0x83(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.E;
}
void ADDH_0x84(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.H;
}
void ADDL_0x85(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.L;
}
void ADDM_0x86(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = ((addr_t) registers.H) << (sizeof(word_t) * 8) + registers.L;
    registers.A += memory.get_word(addr); 
}
void ADI_0xC6(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.A += word;
}

void ADCA_0x8F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.A + flags[0];
}
void ADCB_0x88(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.B + flags[0];
}
void ADCC_0x89(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.C + flags[0];
}
void ADCD_0x8A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.D + flags[0];
}
void ADCE_0x8B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.E + flags[0];
}
void ADCH_0x8C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.H + flags[0];
}
void ADCL_0x8D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A += registers.L + flags[0];
}
void ADCM_0x8E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = ((addr_t) registers.H) << (sizeof(word_t) * 8) + registers.L;
    registers.A += memory.get_word(addr) + flags[0]; 
}
void ACI_0xCE(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.A += word + flags[0];
}


void SUBA_0x97(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.A;
}
void SUBB_0x90(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.B;
}
void SUBC_0x91(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.C;
}
void SUBD_0x92(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.D;
}
void SUBE_0x93(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.E;
}
void SUBH_0x94(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.H;
}
void SUBL_0x95(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.L;
}
void SUBM_0x96(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = ((addr_t) registers.H) << (sizeof(word_t) * 8) + registers.L;
    registers.A -= memory.get_word(addr); 
}
void SUI_0xD6(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.A -= word;
}

void SBBA_0x9F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.A + flags[0];
}
void SBBB_0x98(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.B + flags[0];
}
void SBBC_0x99(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.C + flags[0];
}
void SBBD_0x9A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.D + flags[0];
}
void SBBE_0x9B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.E + flags[0];
}
void SBBH_0x9C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.H + flags[0];
}
void SBBL_0x9D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    registers.A -= registers.L + flags[0];
}
void SBBM_0x9E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack){
    addr_t addr = ((addr_t) registers.H) << (sizeof(word_t) * 8) + registers.L;
    registers.A -= memory.get_word(addr) + flags[0]; 
}
void SBI_0xDE(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, word_t word){
    registers.A -= word + flags[0];
}