#ifndef CORE_FUNCTIONS_H

#define CORE_FUNCTIONS_H
#include "coreFunctions.h"

#endif

int main(void){
    
    State s = {0x2d,0x01,0x55,0xfa};
    Key128 key = {255,255,255,255, 0,255,255,255, 255,255,255,255, 0,255,255,255};
    printState(s);

    //addRoundKey(s, key);
    subBytes(s);


    printState(s);
}