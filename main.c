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



    
    

    State state = {{0x32, 0x88, 0x31, 0xe0}, {0x43, 0x5a, 0x31, 0x37}, {0xf6, 0x30, 0x98, 0x07}, {0xa8, 0x8d, 0xa2, 0x34}};
    Key128 key = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    uint8_t keySchedule[11 * 16];
    keyExpansion(key, keySchedule);

    printf("INPUT:\n");
    printState(state);



    cipher(state, Nr, keySchedule);

    printf("AFTER CIPHER:\n");
    printState(state);



    invCipher(state, Nr, keySchedule);

    printf("AFTER INVERSE CIPHER:\n");
    printState(state);


}
