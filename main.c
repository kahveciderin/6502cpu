#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <addressing_modes.h>
const uint8_t sizes[256] = {};
const bool inst_adr_touch[256] = {};
const uint16_t instr_addressing[256] = {};
extern void execute_cycle(uint8_t *address_space, uint16_t *ip, uint8_t *accum, uint8_t *X, uint8_t *Y, uint8_t *status);
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
    while (1) {
        switch (address_space[ip]) {
            //AND
            case 0x29:

            break;
            //LDA
            case 0xA9:
            
            break;
            //JMP
            case 0x4C:

            break;
            //ADC
            case 0x69:
            break;
            //STA
            case 0x8D:
            break;
        }
        if (!inst_adr_touch[address_space[ip]]) {
            ip += sizes[address_space[ip]];
        }
    }
}