#include <stdint.h>
#define ROUND_COUNT 10

typedef uint8_t State[4][4];
typedef uint8_t Key128[16];

extern const uint8_t substituionBox[256];
extern const uint8_t rCon[10];


//FUNCTION PROTOTYPES
uint8_t sBox(uint8_t byte);
void subBytes(State state);
void shiftRows(State s);
void mixColumns(State s);
void addRoundKey(State state, uint8_t* roundKey);

void keyExpansion(Key128 firstKey, uint8_t* allKeys);
uint8_t* cpyWord(uint8_t* original, uint8_t* copy);
uint8_t* xorWord(uint8_t* wToStay, uint8_t* wToChange);
uint8_t* rotWord(uint8_t* word);
uint8_t* subWord(uint8_t* word);
uint8_t* addRoundConstant(uint8_t* word, uint8_t round);

void printState(State state);