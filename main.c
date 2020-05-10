#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argc, char *kwargs[]) {
    FILE *f = fopen("textfile.txt", "rb");
    uint8_t *address_space = malloc(65536);
    
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    fread(address_space + 65536 / 2, fsize, 1, f);
    fclose(f);
    uint16_t ip;
    uint8_t accum;
    uint8_t X;
    uint8_t Y;
    uint8_t status;
    ip = ((uint16_t)address_space[0xfffd] << 8) | (uint16_t)address_space[0xfffc];
    int isInstruction = 0;
    bool increment = false;
    uint16_t value = 0x0;
    while (1) {
        if(isInstruction == 0){
        switch (address_space[ip]) {
            case 0x00:

            case 0x01:

            
            case 0x02:
            break;
        }
        }else if(isInstruction == 1){

        value = address_space[ip]
        if(increment){

        isInstruction = 2;
        }else{
            isInstruction = 0;
        }
        } else if(isInstruction == 2){
            value = ((uint16_t)value << 8) | address_space[ip];
            isInstruction = 0;
        }
    }
}