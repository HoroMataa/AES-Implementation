#include "coreFunctions.h"


//sbox in a row major layout
const uint8_t substituionBox[256] = {
 	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

//round constants
const uint8_t rCon[] = {
    0x00,
    0x01,
    0x02,
    0x04,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80,
    0x1B,
    0x36
};

//version of the function working with the array sBox, later to be changed to the mathematical function
uint8_t sBox(uint8_t byte){
    return (substituionBox[byte]);
}

//caling sBox for each byte in the state
void subBytes(State state){

    for(int column = 0; column < 4; column++){
        for(int row = 0; row < 4; row++){
            state[row][column] = sBox(state[row][column]);
        }
    }
  
}


void shiftRows(State state){
    //each row except row0 gets shifted(rotated) i spots to the left where i is the row index
    for(int i = 1; i < 4; i++){
        stateShiftLeft(&state[i][0], i);
    }
}

//shifts(rotates) a row in a state [shiftCount] times, accepts a pointer to the first byte of row we want to shift
void stateShiftLeft(uint8_t* stateByte, int shiftCount){
    for(int i = 0; i < shiftCount; i++){

        uint8_t tmp = stateByte[0];
        for(int j = 0; j < 3; j++){
            stateByte[j] = stateByte[j + 1];
        }
        stateByte[3] = tmp;
    }
}

void mixColumns(uint8_t* state){
    for(int i = 0; i < 4; i++){
        printf("Column %i before mixColumns():\n", i);
        printState(state);


        mixOneColumn(state + i);

        printf("Column %i mixed:\n", i);
        printState(state);
    }
}

//function that changes every column, be careful not to overwrite the bytes before all the caclulations are completed!
void mixOneColumn(uint8_t* stateByte){

    uint8_t tmp0, tmp1, tmp2, tmp3;

    tmp0 = (xTimes(&stateByte[0])) ^ (xTimes(&stateByte[4]) ^ stateByte[4]) ^ (stateByte[8]) ^ (stateByte[12]);
    tmp1 = (stateByte[0]) ^ (xTimes(&stateByte[4])) ^ (xTimes(&stateByte[8]) ^ stateByte[8]) ^ (stateByte[12]);
    tmp2 = (stateByte[0]) ^ (stateByte[4]) ^ (xTimes(&stateByte[8])) ^ (xTimes(&stateByte[12]) ^ stateByte[12]);
    tmp3 = (xTimes(&stateByte[0]) ^ stateByte[0]) ^ (stateByte[4]) ^ (stateByte[8]) ^ (xTimes(&stateByte[12]));

    stateByte[0] = tmp0;
    stateByte[4] = tmp1;
    stateByte[8] = tmp2;
    stateByte[12] = tmp3;

}

//Function that returns a polynomial(in a binary representation) that is a result of multiplication of the input by x in GF(2^8)
uint8_t xTimes(uint8_t* byte){
    //if bit7 is 0, we just shift the byte to the left
    //if not, there appears x^8 term but from the AES polynomial(x^8 + x^4 + x^3 + x + 1) we know that x^8 = x^4 + x^3 + x + 1 = 0x1b so we can just add(XOR in GF2^8) 0x1b
    if(*byte & 0b10000000){
        return((*byte << 1) ^ 0x1b);
   }
    else{
        return(*byte << 1);
    }
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




//accepts the first key and empty keySchedule array that will be filled with generated keys
void keyExpansion(Key128 firstKey, uint8_t* keySchedule){

    //copy first key into keySchedule
    int i = 0;
    for(; i < 4 * 4; i += 4){
        cpyWord(&firstKey[i], &keySchedule[i]);
    }
    
    //generate new word (remaining 40 words = 10 keys)
    //for each key(roundcount + 1) and each word(4) and each first byte in that word(+4)
    for(; i < (ROUND_COUNT + 1) * 4 * 4; i += 4){
        if(i % 16 == 0){
            xorWord(&keySchedule[i - 4 * 4], 
                addRoundConstant(
                    subWord(
                        rotWord(
                            cpyWord(&keySchedule[i - 1 * 4],&keySchedule[i])
                        )
                    )
                , i / 16)
            );
        }
        else{
            xorWord(&keySchedule[i - 4 * 4],
                cpyWord(&keySchedule[i - 1 * 4], &keySchedule[i])
            );
        }
    }
}

//copies original word into new word and returns pointer to first byte of new word
uint8_t* cpyWord(uint8_t* original, uint8_t* copy){
    for(int i = 0; i < 4; i++){
        copy[i] = original[i];
    }
    return(copy);
}

//xors word1 with word2 and writes result in word2, returns pointer to it
uint8_t* xorWord(uint8_t* wToStay, uint8_t* wToChange){
    for(int i = 0; i < 4; i++){
        wToChange[i] = wToChange[i] ^ wToStay[i];
    }
    return(wToChange);
}


//rotates 4 bytes in a word one place to the left
uint8_t* rotWord(uint8_t* word){
    uint8_t tmp = word[0];
    for(int i = 0; i < 3; i++){
        word[i] = word[i + 1];
    }
    word[3] = tmp;

    return(word);
}

//substitutes each byte in a word via sbox
uint8_t* subWord(uint8_t* word){
    for(int i = 0; i < 4; i++){
        word[i] = sBox(word[i]);
    }
    return(word);
}

//adds the round constant to the first byte of a word
uint8_t* addRoundConstant(uint8_t* word, uint8_t round){
    word[0] = word[0] ^ rCon[round];
    return(word);
}

void printWord(uint8_t* word){
    for(int i = 0; i < 4; i++){
        printf("%02x", word[i]);
    }
    printf("\n");
}

void printState(State state){
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%x  ", state[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
}