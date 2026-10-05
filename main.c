#ifndef CORE_FUNCTIONS_H

#define CORE_FUNCTIONS_H
#include "coreFunctions.h"

#endif

int main(void){
    //testing the expansion of 128 bit key, test key taken from FIPS197 section A.1
    Key128 key = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    uint8_t keySchedule[11 * 4 * 4];

    keyExpansion(key, keySchedule);
 
    //print every word from keySchedule
    for(int i = 0; i < 176; i += 4){
        printWord(&keySchedule[i]);
    }
}