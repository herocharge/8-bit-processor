#ifndef GLOBAL_DECL
#define GLOBAL_DECL

#include <vector>
#include <cstdint>

typedef uint8_t word_t;
typedef uint16_t addr_t;
typedef uint8_t error_t;
typedef struct Registers Registers;
typedef struct stack Stack;
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


#endif