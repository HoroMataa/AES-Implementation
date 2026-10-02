#ifndef CORE_FUNCTIONS_H

#define CORE_FUNCTIONS_H
#include "coreFunctions.h"

#endif

int main(void){
    
    State s = {0b11001100,0b1001100,0b00000001,0b11101110};
    Key128 key = {0b11111111};
    printState(s);

    addRoundKey(s, key);

    printState(s);
}