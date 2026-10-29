#ifndef CORE_FUNCTIONS_H

#define CORE_FUNCTIONS_H
#include "coreFunctions.h"

#endif

int main(void){

    State state = {{0x32, 0x88, 0x31, 0xe0}, {0x43, 0x5a, 0x31, 0x37}, {0xf6, 0x30, 0x98, 0x07}, {0xa8, 0x8d, 0xa2, 0x34}};
    Key128 key = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    uint8_t keySchedule[11 * 16];
    keyExpansion(key, keySchedule);

    printf("INPUT:\n");
    printState(state);


    //CIPHER
    addRoundKey(state, keySchedule);

    for(int round = 1; round < 10; round++){
        subBytes(state);
        shiftRows(state);
        mixColumns(state);
        addRoundKey(state, &keySchedule[round * 16]);
    }

    subBytes(state);
    shiftRows(state);
    addRoundKey(state, &keySchedule[10 * 16]);
    //END CIPHER

    printf("OUTPUT:\n");
    printState(state);





}
