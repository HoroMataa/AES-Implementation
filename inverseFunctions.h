#ifndef CORE_FUNCTIONS_H
#define CORE_FUNCTIONS_H
#include "coreFunctions.h"
#endif

extern const uint8_t inverseSubstituionBox[256];


void invShiftRows(State state);

void invMixColumns(State state);

void invSubBytes(State state);

uint8_t invSBox(uint8_t byte);