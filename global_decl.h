#ifndef GLOBAL_DECL
#define GLOBAL_DECL

#include <vector>
#include <cstdint>

typedef uint8_t word_t;
typedef uint16_t addr_t;
typedef uint8_t error_t;
typedef struct Registers Registers;
struct Registers
{
    word_t A;
    word_t B;
    word_t C;
    word_t D;
    word_t E;
    word_t H;
    word_t L;
};
typedef void (*voidFunctionType)(void);

enum flags {
    SIGN = 7,// S - Sign Flag
    ZERO = 6,// Z - Zero Flag
    // 0 - Not used, always zero
    AUXCARRY = 4, // A - also called AC, Auxiliary Carry Flag
    ZEROLIT = 3, // 0 - Not used, always zero
    PARITY = 2,// P - Parity Flag
    ONELIT = 1,// 1 - Not used, always one
    CARRY = 0// C - Carry Flag
};

#endif