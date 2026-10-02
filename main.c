#ifndef CORE_FUNCTIONS_H

#define CORE_FUNCTIONS_H
#include "coreFunctions.h"

#endif

int main(void){
    
    State s = {1,255,255,1};
    Key128 key = {255,255,255,255, 0,255,255,255, 255,255,255,255, 0,255,255,255};
    printState(s);

    addRoundKey(s, key);

    printState(s);
}