#include "coreFunctions.h"

extern const uint8_t inverseSubstituionBox[256];


invShiftRows(State state);

invMixColumns(State state);

invSubBytes(State state);

uint8_t invSBox(uint8_t byte);