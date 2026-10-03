#include <stdint.h>

typedef uint8_t State[4][4];
typedef uint8_t Key128[16];

extern const uint8_t substituionBox[256];


//FUNCTION PROTOTYPES
uint8_t sBox(uint8_t byte);
void shiftRows(State s);
void mixColumns(State s);
void addRoundKey(State state, uint8_t* roundKey);
void keyExpansion(Key128 firstKey, uint8_t* allKeys);
void printState(State state);