/**
 * @file state.h
 * @author Microprocessor & Assembly Course Group 07
 * @brief program state management
 * @version 0.1
 * @date 2022-12-13
 * 
 * State management api for predictable
 * program execution behavior.
 */
#ifndef __STATE_H__
#define __STATE_H__

/** External Includes */
#include <stdint.h>

/** Internal Includes */
#include "ic7400.h"
#include "ic7404.h"
#include "ic7408.h"
#include "ic7432.h"

#define _APPLY(state_index, pp_pair) (_state[state_index] ? setb(pp_pair) : clr(pp_pair))

typedef uint8_t byte_t;

// Allocate 56 bytes for storing program state.
// one byte for each (port, pin) pair.
// state is centralized and shared. (be careful of side effects.)
byte_t _state[56] = {0};

// Captures the current state.
void state_capture() {
    /** `IC7400` (port, pin) pairs. */
    _state[0]  = GetBit(NAND_VCC);  _state[1]  = GetBit(NAND_GND);
    _state[2]  = GetBit(NAND_A1);   _state[3]  = GetBit(NAND_B1);
    _state[4]  = GetBit(NAND_Y1);   _state[5]  = GetBit(NAND_A2);
    _state[6]  = GetBit(NAND_B2);   _state[7]  = GetBit(NAND_Y2);
    _state[8]  = GetBit(NAND_A3);   _state[9]  = GetBit(NAND_B3);
    _state[10] = GetBit(NAND_Y3);   _state[11] = GetBit(NAND_A4);
    _state[12] = GetBit(NAND_B4);   _state[13] = GetBit(NAND_Y4);

    /** `IC7404` (port, pin) pairs. */
    _state[14] = GetBit(NOT_VCC); _state[15] = GetBit(NOT_GND);
    _state[16] = GetBit(NOT_A1);  _state[17] = GetBit(NOT_Y1);
    _state[18] = GetBit(NOT_A2);  _state[19] = GetBit(NOT_Y2);
    _state[20] = GetBit(NOT_A3);  _state[21] = GetBit(NOT_Y3);
    _state[22] = GetBit(NOT_A4);  _state[23] = GetBit(NOT_Y4);
    _state[24] = GetBit(NOT_A5);  _state[25] = GetBit(NOT_Y5);
    _state[26] = GetBit(NOT_A6);  _state[27] = GetBit(NOT_Y6);

    /** `IC7408` (port, pin) pairs. */
    _state[28] = GetBit(AND_VCC);  _state[29] = GetBit(AND_GND);
    _state[30] = GetBit(AND_A1);   _state[31] = GetBit(AND_B1);
    _state[32] = GetBit(AND_Y1);   _state[33] = GetBit(AND_A2);
    _state[34] = GetBit(AND_B2);   _state[35] = GetBit(AND_Y2);
    _state[36] = GetBit(AND_A3);   _state[37] = GetBit(AND_B3);
    _state[38] = GetBit(AND_Y3);   _state[39] = GetBit(AND_A4);
    _state[40] = GetBit(AND_B4);   _state[41] = GetBit(AND_Y4);

    /** `IC7432` (port, pin) pairs. */
    _state[42] = GetBit(OR_VCC);  _state[43] = GetBit(OR_GND);
    _state[44] = GetBit(OR_A1);   _state[45] = GetBit(OR_B1);
    _state[46] = GetBit(OR_Y1);   _state[47] = GetBit(OR_A2);
    _state[48] = GetBit(OR_B2);   _state[49] = GetBit(OR_Y2);
    _state[50] = GetBit(OR_A3);   _state[51] = GetBit(OR_B3);
    _state[52] = GetBit(OR_Y3);   _state[53] = GetBit(OR_A4);
    _state[54] = GetBit(OR_B4);   _state[55] = GetBit(OR_Y4);
}

// Applies the latest captured state.
void state_apply() {
    _APPLY(0, NAND_VCC);  _APPLY(1, NAND_GND);
    _APPLY(2, NAND_A1);   _APPLY(3, NAND_B1);
    _APPLY(4, NAND_Y1);   _APPLY(5, NAND_A2);
    _APPLY(6, NAND_B2);   _APPLY(7, NAND_Y2);
    _APPLY(8, NAND_A3);   _APPLY(9, NAND_B3);
    _APPLY(10, NAND_Y3);  _APPLY(11, NAND_A4);
    _APPLY(12, NAND_B4);  _APPLY(13, NAND_Y4);

    _APPLY(14, NOT_VCC);  _APPLY(15, NOT_GND);
    _APPLY(16, NOT_A1);   _APPLY(17, NOT_Y1);
    _APPLY(18, NOT_A2);   _APPLY(19, NOT_Y2);
    _APPLY(20, NOT_A3);   _APPLY(21, NOT_Y3);
    _APPLY(22, NOT_A4);   _APPLY(23, NOT_Y4);
    _APPLY(24, NOT_A5);   _APPLY(25, NOT_Y5);
    _APPLY(26, NOT_A6);   _APPLY(27, NOT_Y6);

    _APPLY(28, AND_VCC);  _APPLY(29, AND_GND);
    _APPLY(30, AND_A1);   _APPLY(31, AND_B1);
    _APPLY(32, AND_Y1);   _APPLY(33, AND_A2);
    _APPLY(34, AND_B2);   _APPLY(35, AND_Y2);
    _APPLY(36, AND_A3);   _APPLY(37, AND_B3);
    _APPLY(38, AND_Y3);   _APPLY(39, AND_A4);
    _APPLY(40, AND_B4);   _APPLY(41, AND_Y4);

    _APPLY(42, OR_VCC);  _APPLY(43, OR_GND);
    _APPLY(44, OR_A1);   _APPLY(45, OR_B1);
    _APPLY(46, OR_Y1);   _APPLY(47, OR_A2);
    _APPLY(48, OR_B2);   _APPLY(49, OR_Y2);
    _APPLY(50, OR_A3);   _APPLY(51, OR_B3);
    _APPLY(52, OR_Y3);   _APPLY(53, OR_A4);
    _APPLY(54, OR_B4);   _APPLY(55, OR_Y4);
}

#endif
