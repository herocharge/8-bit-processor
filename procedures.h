#include "global_decl.h"
#include "memory.h"
#include "stack.h"
#include "program_counter.h"

addr_t wtod(word_t a, word_t b);

word_t higher_byte(addr_t a);
word_t lower_byte(addr_t a);

int get_bit(word_t w, int pos);

bool is_neg(word_t w);

void set_cmp_flags(std::vector<bool>& flags, word_t a, word_t b, word_t res);

void NOP_0x00(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVAA_0x7F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVAB_0x78(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVAC_0x79(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVAD_0x7A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVAE_0x7B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVAH_0x7C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVAL_0x7D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVAM_0x7E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void LDAXB_0x0A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void LDAXD_0x1A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void LDA_0x3Aword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
// TODO: implement z80 style instructions as well maybe

void MOVBA_0x47(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVBB_0x40(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVBC_0x41(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVBD_0x42(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVBE_0x43(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVBH_0x44(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVBL_0x45(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVBM_0x46(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void MOVCA_0x4F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVCB_0x48(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVCC_0x49(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVCD_0x4A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVCE_0x4B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVCH_0x4C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVCL_0x4D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVCM_0x4E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void MOVDA_0x57(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVDB_0x50(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVDC_0x51(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVDD_0x52(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVDE_0x53(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVDH_0x54(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVDL_0x55(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVDM_0x56(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void MOVEA_0x5F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVEB_0x58(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVEC_0x59(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVED_0x5A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVEE_0x5B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVEH_0x5C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVEL_0x5D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVEM_0x5E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void MOVHA_0x67(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVHB_0x60(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVHC_0x61(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVHD_0x62(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVHE_0x63(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVHH_0x64(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVHL_0x65(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVHM_0x66(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void MOVLA_0x6F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVLB_0x68(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVLC_0x69(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVLD_0x6A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVLE_0x6B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVLH_0x6C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVLL_0x6D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVLM_0x6E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void MOVMA_0x77(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVMB_0x70(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVMC_0x71(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVMD_0x72(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVME_0x73(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVMH_0x74(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MOVML_0x75(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void MVIA_0x3Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MVIB_0x06word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MVIC_0x0Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MVID_0x16word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MVIE_0x1Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MVIH_0x26word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MVIL_0x2Eword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void MVIM_0x36word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void STAXB_0x02(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void STAXD_0x12(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void  STA_0x32doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

// TODO: implement LXI and 16 bit transfer instructions // done

void LXIBC_0x01doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void LXIDE_0x11doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void LXIHL_0x21doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void LXISP_0x31doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

// Leaving out LHLD, SHLD, SPHL for now

void XCHNG_0xEB(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void XTHL_0xE3(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

// TODO: Flag setting

void ADDA_0x87(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADDB_0x80(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADDC_0x81(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADDD_0x82(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADDE_0x83(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADDH_0x84(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADDL_0x85(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADDM_0x86(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADI_0xC6word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void ADCA_0x8F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADCB_0x88(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADCC_0x89(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADCD_0x8A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADCE_0x8B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADCH_0x8C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADCL_0x8D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ADCM_0x8E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ACI_0xCEword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);


void SUBA_0x97(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SUBB_0x90(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SUBC_0x91(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SUBD_0x92(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SUBE_0x93(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SUBH_0x94(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SUBL_0x95(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SUBM_0x96(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SUI_0xD6word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void SBBA_0x9F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SBBB_0x98(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SBBC_0x99(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SBBD_0x9A(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SBBE_0x9B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SBBH_0x9C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SBBL_0x9D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SBBM_0x9E(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void SBI_0xDEword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void DADBC_0x09(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void DADDE_0x19(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void DADHL_0x29(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void DADSP_0x39(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

// TODO: DI, EI, -> what are these?, HLT

void INRA_0x3C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void INRB_0x04(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void INRC_0x0C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void INRD_0x14(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void INRE_0x1C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void INRH_0x24(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void INRL_0x2C(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void INRM_0x34(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void DCRA_0x3D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void DCRB_0x05(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void DCRC_0x0D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void DCRD_0x15(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void DCRE_0x1D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void DCRH_0x25(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void DCRL_0x2D(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void DCRM_0x35(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void INXBC_0x03(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void INXDE_0x13(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void INXHL_0x23(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void INXSP_0x33(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void DCXBC_0x0B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void DCXDE_0x1B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void DCXHL_0x2B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void DCXSP_0x3B(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

// TODO: Special Accumulator and Flag Instructions

void RLC_0x07(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void RRC_0x0F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void RAL_0x17(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void RAR_0x1F(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);


void ANAA_0xA7(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ANAB_0xA0(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ANAC_0xA1(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ANAD_0xA2(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ANAE_0xA3(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ANAH_0xA4(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ANAL_0xA5(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ANAM_0xA6(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ANI_0xE6word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void XRAA_0xAF(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void XRAB_0xA8(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void XRAC_0xA9(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void XRAD_0xAA(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void XRAE_0xAB(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void XRAH_0xAC(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void XRAL_0xAD(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void XRAM_0xAE(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void XRI_0xEEword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);


void ORAA_0xB7(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ORAB_0xB0(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ORAC_0xB1(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ORAD_0xB2(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ORAE_0xB3(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ORAH_0xB4(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ORAL_0xB5(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ORAM_0xB6(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void ORI_0xF6word(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void CMPA_0xBF(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void CMPB_0xB8(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void CMPC_0xB9(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void CMPD_0xBA(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void CMPE_0xBB(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void CMPH_0xBC(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void CMPL_0xBD(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void CMPM_0xBE(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void CPI_0xFEword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void JMP_0xC3doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void JNZ_0xC2doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void JZ_0xCAdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void JNC_0xD2doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void JC_0xDAdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void JPO_0xE2doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void JPE_0xEAdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void JP_0xF2doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void JM_0xFAdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void PCHL_0xE9(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void CALL_0XCDdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void CNZ_0xC4doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void CZ_0xCCdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void CNC_0xD4doubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);
void CC_0xDCdoubleword(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

void RET_0xC9(Registers& registers, std::vector<bool>& flags, Memory& memory, Stack& stack, Program_counter& pc, word_t word1, word_t word2);

// Skipping conditional return coz im too tired