#include <stdio.h>
#include "coreFunctions.h"


//*TODO DEFINE SBOX*





void subBytes(State* s){

}


void shiftRows(State* s){

}


void mixColumns(State* s){

}

//function that xors the state with the corresponging round key, notice that we loop column major because the state and the xoring is both column major
//takes state as an intput and then pointer to the first byte of our round key
void addRoundKey(State state, uint8_t* roundKey){
    
    int xorCount = 0;

    for(int column = 0; column < 4; column++){
        for(int row = 0; row < 4; row++){
            state[row][column] = state[row][column] ^ roundKey[xorCount++];
        }
    }
}

void keyExpansion(Key128 firstKey, uint8_t* allKeys){

}

void printState(State state){
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d  ", state[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
}