#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "addressing_modes.h"
#define UNIMPL false
const uint8_t sizes[256] = {1, 2, 0, 0, 0, 2, 2, 0, 1, 2, 1, 0, 0, 3, 3, 0, 2, 2, 0, 0, 0, 2, 2, 0, 1, 3, 0, 0, 0, 3, 3, 0, 3, 2, 0, 0, 2, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0, 2, 2, 0, 0, 0, 2, 2, 0, 1, 3, 0, 0, 0, 3, 3, 0, 1, 2, 0, 0, 0, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0, 2, 2, 0, 0, 0, 2, 2, 0, 1, 3, 0, 0, 0, 3, 3, 0, 1, 2, 0, 0, 0, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0, 2, 2, 0, 0, 0, 2, 2, 0, 1, 3, 0, 0, 0, 3, 3, 0, 0, 2, 0, 0, 2, 2, 2, 0, 1, 0, 1, 0, 3, 3, 3, 0, 2, 2, 0, 0, 2, 2, 2, 0, 1, 3, 1, 0, 0, 3, 0, 0, 2, 2, 2, 0, 2, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0, 2, 2, 0, 0, 2, 2, 2, 0, 1, 3, 1, 0, 3, 3, 3, 0, 2, 2, 0, 0, 2, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0, 2, 2, 0, 0, 0, 2, 2, 0, 1, 3, 0, 0, 0, 3, 3, 0, 2, 2, 0, 0, 2, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0, 2, 2, 0, 0, 0, 2, 2, 0, 1, 3, 0, 0, 0, 3, 3, 0};
const bool inst_adr_touch[256] = {true, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, false, false, false, UNIMPL, UNIMPL, false, false, UNIMPL, true, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, false, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, true, false, UNIMPL, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, true, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, false, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, true, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, false, false, false, UNIMPL, true, false, false, UNIMPL, true, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, false, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, true, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, false, false, false, UNIMPL, true, false, false, UNIMPL, true, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, false, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, UNIMPL, false, UNIMPL, UNIMPL, false, false, false, UNIMPL, false, UNIMPL, false, UNIMPL, false, false, false, UNIMPL, true, false, UNIMPL, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, UNIMPL, false, UNIMPL, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, true, false, UNIMPL, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, false, false, UNIMPL, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, true, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, false, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, false, false, UNIMPL, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, false, false, false, UNIMPL, true, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL, false, false, UNIMPL, UNIMPL, UNIMPL, false, false, UNIMPL};
const uint16_t instr_addressing[256] = {AM_impl,AM_X_ind,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_zpg,AM_zpg,AM_NONEXIST,AM_impl,AM_imm,AM_A,AM_NONEXIST,AM_NONEXIST,AM_abs,AM_abs,AM_NONEXIST,AM_rel,AM_ind_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_zpg_X,AM_zpg_X,AM_NONEXIST,AM_impl,AM_abs_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_abs_X,AM_abs_X,AM_NONEXIST,AM_abs,AM_X_ind,AM_NONEXIST,AM_NONEXIST,AM_zpg,AM_zpg,AM_zpg,AM_NONEXIST,AM_impl,AM_imm,AM_A,AM_NONEXIST,AM_abs,AM_abs,AM_abs,AM_NONEXIST,AM_rel,AM_ind_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_zpg_X,AM_zpg_X,AM_NONEXIST,AM_impl,AM_abs_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_abs_X,AM_abs_X,AM_NONEXIST,AM_impl,AM_X_ind,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_zpg,AM_zpg,AM_NONEXIST,AM_impl,AM_imm,AM_A,AM_NONEXIST,AM_abs,AM_abs,AM_abs,AM_NONEXIST,AM_rel,AM_ind_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_zpg_X,AM_zpg_X,AM_NONEXIST,AM_impl,AM_abs_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_abs_X,AM_abs_X,AM_NONEXIST,AM_impl,AM_X_ind,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_zpg,AM_zpg,AM_NONEXIST,AM_impl,AM_imm,AM_A,AM_NONEXIST,AM_ind,AM_abs,AM_abs,AM_NONEXIST,AM_rel,AM_ind_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_zpg_X,AM_zpg_X,AM_NONEXIST,AM_impl,AM_abs_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_abs_X,AM_abs_X,AM_NONEXIST,AM_NONEXIST,AM_X_ind,AM_NONEXIST,AM_NONEXIST,AM_zpg,AM_zpg,AM_zpg,AM_NONEXIST,AM_impl,AM_NONEXIST,AM_impl,AM_NONEXIST,AM_abs,AM_abs,AM_abs,AM_NONEXIST,AM_rel,AM_ind_Y,AM_NONEXIST,AM_NONEXIST,AM_zpg_X,AM_zpg_X,AM_zpg_Y,AM_NONEXIST,AM_impl,AM_abs_Y,AM_impl,AM_NONEXIST,AM_NONEXIST,AM_abs_X,AM_NONEXIST,AM_NONEXIST,AM_imm,AM_X_ind,AM_imm,AM_NONEXIST,AM_zpg,AM_zpg,AM_zpg,AM_NONEXIST,AM_impl,AM_imm,AM_impl,AM_NONEXIST,AM_abs,AM_abs,AM_abs,AM_NONEXIST,AM_rel,AM_ind_Y,AM_NONEXIST,AM_NONEXIST,AM_zpg_X,AM_zpg_X,AM_zpg_Y,AM_NONEXIST,AM_impl,AM_abs_Y,AM_impl,AM_NONEXIST,AM_abs_X,AM_abs_X,AM_abs_Y,AM_NONEXIST,AM_imm,AM_X_ind,AM_NONEXIST,AM_NONEXIST,AM_zpg,AM_zpg,AM_zpg,AM_NONEXIST,AM_impl,AM_imm,AM_impl,AM_NONEXIST,AM_abs,AM_abs,AM_abs,AM_NONEXIST,AM_rel,AM_ind_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_zpg_X,AM_zpg_X,AM_NONEXIST,AM_impl,AM_abs_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_abs_X,AM_abs_X,AM_NONEXIST,AM_imm,AM_X_ind,AM_NONEXIST,AM_NONEXIST,AM_zpg,AM_zpg,AM_zpg,AM_NONEXIST,AM_impl,AM_imm,AM_impl,AM_NONEXIST,AM_abs,AM_abs,AM_abs,AM_NONEXIST,AM_rel,AM_ind_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_zpg_X,AM_zpg_X,AM_NONEXIST,AM_impl,AM_abs_Y,AM_NONEXIST,AM_NONEXIST,AM_NONEXIST,AM_abs_X,AM_abs_X,AM_NONEXIST};

uint8_t read_mem(uint16_t address, uint8_t *membuf) {
    //TODO: memory mapped I/O stuff goes here
    return membuf[address];
}
void write_mem(uint16_t address, uint8_t *membuf, uint8_t value) {
    membuf[address] = value;
}
uint16_t read_param(uint16_t address, uint8_t *membuf, cpu_state_t *state) {

}
int main(int argc, char *kwargs[]) {
    if (argc != 2) {
        printf("Usage: %s binary_file.bin\n", kwargs[0]);
        return -1;
    } 
    FILE *f = fopen(kwargs[1], "rb");
    uint8_t *address_space = malloc(65536);
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    fread(address_space + 65536 / 2, fsize, 1, f);
    fclose(f);
    cpu_state_t state;
    state.ip = ((uint16_t)address_space[0xfffd] << 8) | (uint16_t)address_space[0xfffc];
    uint16_t value = 0x0;
    while (1) { 
    
    int arguments[sizes[address_space[state.ip]]];

    for(int i = 0; i < sizes[address_space[state.ip]]; i++){

        arguments[i] = address_space[state.ip] + i + 1;
    }

    switch (address_space[state.ip]) {

        // BRK (implied) -  Force Break
        case 0x00:

        break;
        
        // ORA ((indirect,X)) -  OR Memory with Accumulator
        case 0x01:

        break;
        
        // ORA (zeropage) -  OR Memory with Accumulator
        case 0x05:

        break;
        
        // ASL (zeropage) -  Shift Left One Bit (Memory or Accumulator)
        case 0x06:

        break;
        
        // PHP (implied) -  Push Processor Status on Stack
        case 0x08:

        break;
        
        // ORA (immidiate) -  OR Memory with Accumulator
        case 0x09:

        break;
        
        // ASL (accumulator) -  Shift Left One Bit (Memory or Accumulator)
        case 0x0A:

        break;
        
        // ORA (absolute) -  OR Memory with Accumulator
        case 0x0D:

        break;
        
        // ASL (absolute) -  Shift Left One Bit (Memory or Accumulator)
        case 0x0E:

        break;
        
        // BPL (relative) -  Branch on Result Plus
        case 0x10:

        break;
        
        // ORA ((indirect),Y) -  OR Memory with Accumulator
        case 0x11:

        break;
        
        // ORA (zeropage,X) -  OR Memory with Accumulator
        case 0x15:

        break;
        
        // ASL (zeropage,X) -  Shift Left One Bit (Memory or Accumulator)
        case 0x16:

        break;
        
        // CLC (implied) -  Clear Carry Flag
        case 0x18:

        break;
        
        // ORA (absolute,Y) -  OR Memory with Accumulator
        case 0x19:

        break;
        
        // ORA (absolute,X) -  OR Memory with Accumulator
        case 0x1D:

        break;
        
        // ASL (absolute,X) -  Shift Left One Bit (Memory or Accumulator)
        case 0x1E:

        break;
        
        // JSR (absolute) -  Jump to New Location Saving Return Address
        case 0x20:

        break;
        
        // AND ((indirect,X)) -  AND Memory with Accumulator
        case 0x21:

        break;
        
        // BIT (zeropage) -  Test Bits in Memory with Accumulator
        case 0x24:

        break;
        
        // AND (zeropage) -  AND Memory with Accumulator
        case 0x25:

        break;
        
        // ROL (zeropage) -  Rotate One Bit Left (Memory or Accumulator)
        case 0x26:

        break;
        
        // PLP (implied) -  Pull Processor Status from Stack
        case 0x28:

        break;
        
        // AND (immidiate) -  AND Memory with Accumulator
        case 0x29:

        break;
        
        // ROL (accumulator) -  Rotate One Bit Left (Memory or Accumulator)
        case 0x2A:

        break;
        
        // BIT (absolute) -  Test Bits in Memory with Accumulator
        case 0x2C:

        break;
        
        // AND (absolute) -  AND Memory with Accumulator
        case 0x2D:

        break;
        
        // ROL (absolute) -  Rotate One Bit Left (Memory or Accumulator)
        case 0x2E:

        break;
        
        // BMI (relative) -  Branch on Result Minus
        case 0x30:

        break;
        
        // AND ((indirect),Y) -  AND Memory with Accumulator
        case 0x31:

        break;
        
        // AND (zeropage,X) -  AND Memory with Accumulator
        case 0x35:

        break;
        
        // ROL (zeropage,X) -  Rotate One Bit Left (Memory or Accumulator)
        case 0x36:

        break;
        
        // SEC (implied) -  Set Carry Flag
        case 0x38:

        break;
        
        // AND (absolute,Y) -  AND Memory with Accumulator
        case 0x39:

        break;
        
        // AND (absolute,X) -  AND Memory with Accumulator
        case 0x3D:

        break;
        
        // ROL (absolute,X) -  Rotate One Bit Left (Memory or Accumulator)
        case 0x3E:

        break;
        
        // RTI (implied) -  Return from Interrupt
        case 0x40:

        break;
        
        // EOR ((indirect,X)) -  Exclusive-OR Memory with Accumulator
        case 0x41:

        break;
        
        // EOR (zeropage) -  Exclusive-OR Memory with Accumulator
        case 0x45:

        break;
        
        // LSR (zeropage) -  Shift One Bit Right (Memory or Accumulator)
        case 0x46:

        break;
        
        // PHA (implied) -  Push Accumulator on Stack
        case 0x48:

        break;
        
        // EOR (immidiate) -  Exclusive-OR Memory with Accumulator
        case 0x49:

        break;
        
        // LSR (accumulator) -  Shift One Bit Right (Memory or Accumulator)
        case 0x4A:

        break;
        
        // JMP (absolute) -  Jump to New Location
        case 0x4C:

        break;
        
        // EOR (absolute) -  Exclusive-OR Memory with Accumulator
        case 0x4D:

        break;
        
        // LSR (absolute) -  Shift One Bit Right (Memory or Accumulator)
        case 0x4E:

        break;
        
        // BVC (relative) -  Branch on Overflow Clear
        case 0x50:

        break;
        
        // EOR ((indirect),Y) -  Exclusive-OR Memory with Accumulator
        case 0x51:

        break;
        
        // EOR (zeropage,X) -  Exclusive-OR Memory with Accumulator
        case 0x55:

        break;
        
        // LSR (zeropage,X) -  Shift One Bit Right (Memory or Accumulator)
        case 0x56:

        break;
        
        // CLI (implied) -  Clear Interrupt Disable Bit
        case 0x58:

        break;
        
        // EOR (absolute,Y) -  Exclusive-OR Memory with Accumulator
        case 0x59:

        break;
        
        // EOR (absolute,X) -  Exclusive-OR Memory with Accumulator
        case 0x5D:

        break;
        
        // LSR (absolute,X) -  Shift One Bit Right (Memory or Accumulator)
        case 0x5E:

        break;
        
        // RTS (implied) -  Return from Subroutine
        case 0x60:

        break;
        
        // ADC ((indirect,X)) -  Add Memory to Accumulator with Carry
        case 0x61:

        break;
        
        // ADC (zeropage) -  Add Memory to Accumulator with Carry
        case 0x65:

        break;
        
        // ROR (zeropage) -  Rotate One Bit Right (Memory or Accumulator)
        case 0x66:

        break;
        
        // PLA (implied) -  Pull Accumulator from Stack
        case 0x68:

        break;
        
        // ADC (immidiate) -  Add Memory to Accumulator with Carry
        case 0x69:

        break;
        
        // ROR (accumulator) -  Rotate One Bit Right (Memory or Accumulator)
        case 0x6A:

        break;
        
        // JMP (indirect) -  Jump to New Location
        case 0x6C:

        break;
        
        // ADC (absolute) -  Add Memory to Accumulator with Carry
        case 0x6D:

        break;
        
        // ROR (absolute) -  Rotate One Bit Right (Memory or Accumulator)
        case 0x6E:

        break;
        
        // BVC (relative) -  Branch on Overflow Clear
        case 0x70:

        break;
        
        // ADC ((indirect),Y) -  Add Memory to Accumulator with Carry
        case 0x71:

        break;
        
        // ADC (zeropage,X) -  Add Memory to Accumulator with Carry
        case 0x75:

        break;
        
        // ROR (zeropage,X) -  Rotate One Bit Right (Memory or Accumulator)
        case 0x76:

        break;
        
        // SEI (implied) -  Set Interrupt Disable Status
        case 0x78:

        break;
        
        // ADC (absolute,Y) -  Add Memory to Accumulator with Carry
        case 0x79:

        break;
        
        // ADC (absolute,X) -  Add Memory to Accumulator with Carry
        case 0x7D:

        break;
        
        // ROR (absolute,X) -  Rotate One Bit Right (Memory or Accumulator)
        case 0x7E:

        break;
        
        // STA ((indirect,X)) -  Store Accumulator in Memory
        case 0x81:

        break;
        
        // STY (zeropage) -  Sore Index Y in Memory
        case 0x84:

        break;
        
        // STA (zeropage) -  Store Accumulator in Memory
        case 0x85:

        break;
        
        // STX (zeropage) -  Store Index X in Memory
        case 0x86:

        break;
        
        // DEC (implied) -  Decrement Memory by One
        case 0x88:

        break;
        
        // TXA (implied) -  Transfer Index X to Accumulator
        case 0x8A:

        break;
        
        // STY (absolute) -  Sore Index Y in Memory
        case 0x8C:

        break;
        
        // STA (absolute) -  Store Accumulator in Memory
        case 0x8D:

        break;
        
        // STX (absolute) -  Store Index X in Memory
        case 0x8E:

        break;
        
        // BCC (relative) -  Branch on Carry Clear
        case 0x90:

        break;
        
        // STA ((indirect),Y) -  Store Accumulator in Memory
        case 0x91:

        break;
        
        // STY (zeropage,X) -  Sore Index Y in Memory
        case 0x94:

        break;
        
        // STA (zeropage,X) -  Store Accumulator in Memory
        case 0x95:

        break;
        
        // STX (zeropage,Y) -  Store Index X in Memory
        case 0x96:

        break;
        
        // TYA (implied) -  Transfer Index Y to Accumulator
        case 0x98:

        break;
        
        // STA (absolute,Y) -  Store Accumulator in Memory
        case 0x99:

        break;
        
        // TXS (implied) -  Transfer Index X to Stack Register
        case 0x9A:

        break;
        
        // STA (absolute,X) -  Store Accumulator in Memory
        case 0x9D:

        break;
        
        // LDY (immidiate) -  Load Index Y with Memory
        case 0xA0:

        break;
        
        // LDA ((indirect,X)) -  Load Accumulator with Memory
        case 0xA1:

        break;
        
        // LDX (immidiate) -  Load Index X with Memory
        case 0xA2:

        break;
        
        // LDY (zeropage) -  Load Index Y with Memory
        case 0xA4:

        break;
        
        // LDA (zeropage) -  Load Accumulator with Memory
        case 0xA5:

        break;
        
        // LDX (zeropage) -  Load Index X with Memory
        case 0xA6:

        break;
        
        // TAY (implied) -  Transfer Accumulator to Index Y
        case 0xA8:

        break;
        
        // LDA (immidiate) -  Load Accumulator with Memory
        case 0xA9:
            state.accum = arguments[0];
        break;
        
        // TAX (implied) -  Transfer Accumulator to Index X
        case 0xAA:

        break;
        
        // LDY (absolute) -  Load Index Y with Memory
        case 0xAC:

        break;
        
        // LDA (absolute) -  Load Accumulator with Memory
        case 0xAD:

        break;
        
        // LDX (absolute) -  Load Index X with Memory
        case 0xAE:

        break;
        
        // BCS (relative) -  Branch on Carry Set
        case 0xB0:

        break;
        
        // LDA ((indirect),Y) -  Load Accumulator with Memory
        case 0xB1:

        break;
        
        // LDY (zeropage,X) -  Load Index Y with Memory
        case 0xB4:

        break;
        
        // LDA (zeropage,X) -  Load Accumulator with Memory
        case 0xB5:

        break;
        
        // LDX (zeropage,Y) -  Load Index X with Memory
        case 0xB6:

        break;
        
        // CLV (implied) -  Clear Overflow Flag
        case 0xB8:

        break;
        
        // LDA (absolute,Y) -  Load Accumulator with Memory
        case 0xB9:

        break;
        
        // TSX (implied) -  Transfer Stack Pointer to Index X
        case 0xBA:

        break;
        
        // LDY (absolute,X) -  Load Index Y with Memory
        case 0xBC:

        break;
        
        // LDA (absolute,X) -  Load Accumulator with Memory
        case 0xBD:

        break;
        
        // LDX (absolute,Y) -  Load Index X with Memory
        case 0xBE:

        break;
        
        // CPY (immidiate) -  Compare Memory and Index Y
        case 0xC0:

        break;
        
        // CMP ((indirect,X)) -  Compare Memory with Accumulator
        case 0xC1:

        break;
        
        // CPY (zeropage) -  Compare Memory and Index Y
        case 0xC4:

        break;
        
        // CMP (zeropage) -  Compare Memory with Accumulator
        case 0xC5:

        break;
        
        // DEC (zeropage) -  Decrement Memory by One
        case 0xC6:

        break;
        
        // INY (implied) -  Increment Index Y by One
        case 0xC8:

        break;
        
        // CMP (immidiate) -  Compare Memory with Accumulator
        case 0xC9:

        break;
        
        // DEC (implied) -  Decrement Memory by One
        case 0xCA:

        break;
        
        // CPY (absolute) -  Compare Memory and Index Y
        case 0xCC:

        break;
        
        // CMP (absolute) -  Compare Memory with Accumulator
        case 0xCD:

        break;
        
        // DEC (absolute) -  Decrement Memory by One
        case 0xCE:

        break;
        
        // BNE (relative) -  Branch on Result not Zero
        case 0xD0:

        break;
        
        // CMP ((indirect),Y) -  Compare Memory with Accumulator
        case 0xD1:

        break;
        
        // CMP (zeropage,X) -  Compare Memory with Accumulator
        case 0xD5:

        break;
        
        // DEC (zeropage,X) -  Decrement Memory by One
        case 0xD6:

        break;
        
        // CLD (implied) -  Clear Decimal Mode
        case 0xD8:

        break;
        
        // CMP (absolute,Y) -  Compare Memory with Accumulator
        case 0xD9:

        break;
        
        // CMP (absolute,X) -  Compare Memory with Accumulator
        case 0xDD:

        break;
        
        // DEC (absolute,X) -  Decrement Memory by One
        case 0xDE:

        break;
        
        // CPX (immidiate) -  Compare Memory and Index X
        case 0xE0:

        break;
        
        // SBC ((indirect,X)) -  Subtract Memory from Accumulator with Borrow
        case 0xE1:

        break;
        
        // CPX (zeropage) -  Compare Memory and Index X
        case 0xE4:

        break;
        
        // SBC (zeropage) -  Subtract Memory from Accumulator with Borrow
        case 0xE5:

        break;
        
        // INC (zeropage) -  Increment Memory by One
        case 0xE6:

        break;
        
        // INX (implied) -  Increment Index X by One
        case 0xE8:

        break;
        
        // SBC (immidiate) -  Subtract Memory from Accumulator with Borrow
        case 0xE9:

        break;
        
        // NOP (implied) -  No Operation
        case 0xEA:
        //this is a joke, right?
        break;
        
        // CPX (absolute) -  Compare Memory and Index X
        case 0xEC:

        break;
        
        // SBC (absolute) -  Subtract Memory from Accumulator with Borrow
        case 0xED:

        break;
        
        // INC (absolute) -  Increment Memory by One
        case 0xEE:

        break;
        
        // BEQ (relative) -  Branch on Result Zero
        case 0xF0:

        break;
        
        // SBC ((indirect),Y) -  Subtract Memory from Accumulator with Borrow
        case 0xF1:

        break;
        
        // SBC (zeropage,X) -  Subtract Memory from Accumulator with Borrow
        case 0xF5:

        break;
        
        // INC (zeropage,X) -  Increment Memory by One
        case 0xF6:

        break;
        
        // SED (implied) -  Set Decimal Flag
        case 0xF8:

        break;
        
        // SBC (absolute,Y) -  Subtract Memory from Accumulator with Borrow
        case 0xF9:

        break;
        
        // SBC (absolute,X) -  Subtract Memory from Accumulator with Borrow
        case 0xFD:

        break;
        
        // INC (absolute,X) -  Increment Memory by One
        case 0xFE:

        break;
        }
        if (!inst_adr_touch[address_space[state.ip]]) {
            state.ip += sizes[address_space[state.ip]];
        }
    }

}