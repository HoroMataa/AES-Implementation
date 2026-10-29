#ifndef CORE_FUNCTIONS_H

#define CORE_FUNCTIONS_H
#include "coreFunctions.h"

#endif

int main(void){
    /* //testing the expansion of 128 bit key, test key taken from FIPS197 section A.1
    Key128 key = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    uint8_t keySchedule[11 * 4 * 4];

    keyExpansion(key, keySchedule);
 
    //print every word from keySchedule
    for(int i = 0; i < 176; i += 4){
        printWord(&keySchedule[i]);
    } */


    
    //mixColumns test taken from fips 197 appendix B
    State state = {
    {0xd4, 0xe0, 0xb8, 0x1e},
    {0xbf, 0xb4, 0x41, 0x27},
    {0x5d, 0x52, 0x11, 0x98},
    {0x30, 0xae, 0xf1, 0xe5}};


    mixColumns(state);


}
