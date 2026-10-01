#include "coreFunctions.h"

//*TODO DEFINE SBOX*





void subBytes(State* s){

}


void shiftRows(State* s){

}


void mixColumns(State* s){

}


void addRoundKey(State state, uint8_t* roundKey){
    //function that xors the state with the corresponging round key, notice that we loop column major because the state and the xoring is both column major

    int xorCount = 0;

    for(int column = 0; column < 4; column++){
        for(int row = 0; row < 4; row++){
            state[row][column] = state[row][column] ^ roundKey[xorCount++];
        }
    }
}

void keyExpansion(Key128 firstKey, uint8_t[16 * 11]){

}