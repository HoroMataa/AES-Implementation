#ifndef CORE_FUNCTIONS_H
#define CORE_FUNCTIONS_H
#include "coreFunctions.h"
#endif

#ifndef INVERSE_FUNCTIONS_H
#define INVERSE_FUNCTIONS_H
#include "inverseFunctions.h"
#endif

#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]){

    //number of words in a key
    uint8_t Nk = 4;
    //number of rounds
    uint8_t Nr = 10;

    for(int i = 1; i < argc;i++){

        if(strcmp(argv[i], "-k") == 0 && argc > i){

            switch (atoi(argv[++i])){
            case 128:
                printf("AES128\n");
                break;
            case 192:
                printf("AES192\n");
                Nk = 6;
                Nr = 12;
                break;
            case 256:
                printf("AES256\n");
                Nk = 8;
                Nr = 14;
                break;
            default:
                printf("Key length not chosen, AES128\n");
                break;
            }

        }
        else if(strcmp(argv[i], "-k") == 0){
            printf("Key length not chosen, AES128\n");
        }


    }

    //FIPS 197 TEST KEYS
    Key128 key128 = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    Key192 key192 = {0x8e ,0x73 ,0xb0 ,0xf7 ,0xda ,0x0e ,0x64 ,0x52 ,0xc8 ,0x10 ,0xf3 ,0x2b ,0x80 ,0x90 ,0x79 ,0xe5 ,0x62 ,0xf8 ,0xea ,0xd2 ,0x52 ,0x2c ,0x6b ,0x7b};
    Key256 key256 = {0x60 ,0x3d ,0xeb ,0x10 ,0x15 ,0xca ,0x71 ,0xbe ,0x2b ,0x73 ,0xae ,0xf0 ,0x85 ,0x7d ,0x77 ,0x81 ,0x1f ,0x35 ,0x2c ,0x07 ,0x3b ,0x61 ,0x08 ,0xd7 ,0x2d ,0x98 ,0x10 ,0xa3 ,0x09 ,0x14 ,0xdf ,0xf4};

    uint8_t keySchedule[(Nr + 1) * 4 * 4];
    keyExpansion(key256, keySchedule, Nk, Nr);
    
    for(int i = 0; i < (Nr + 1) * 4 * 4; i += 4){
        printWord(&keySchedule[i]);
    }
    

    /* State state = {{0x32, 0x88, 0x31, 0xe0}, {0x43, 0x5a, 0x31, 0x37}, {0xf6, 0x30, 0x98, 0x07}, {0xa8, 0x8d, 0xa2, 0x34}};
    
    uint8_t keySchedule[(Nr + 1) * 4 * 4];
    keyExpansion(key, keySchedule, Nk, Nr);

    printf("INPUT:\n");
    printState(state);



    cipher(state, Nr, keySchedule);

    printf("AFTER CIPHER:\n");
    printState(state);



    invCipher(state, Nr, keySchedule);

    printf("AFTER INVERSE CIPHER:\n");
    printState(state); */


}
