/**
 * @file ic7400.h
 * @author Microprocessor & Assembly Course Group 07
 * @brief IC7400 API
 * @version 0.1
 * @date 2022-12-12
 *
 * 
 * IC7400 direct guarded api for interfacing with
 * a 7400 model hardware IC chip. 
*/
#ifndef __IC_7400__
#define __IC_7400__

/** Internal Includes */
#include "ATSTAMP.h"
#include "utils.h"

/** Standard Includes */
#include <stdbool.h>

/** Identifier */
#define CHIP_7400 7400

/** Pin Addresses */
#define NAND_VCC  P0,0
#define NAND_GND  P2,0

#define NAND_B4   P0,1
#define NAND_A4   P0,2
#define NAND_Y4   P0,3

#define NAND_B3   P0,4
#define NAND_A3   P0,5
#define NAND_Y3   P0,6

#define NAND_Y2   P2,1
#define NAND_B2   P2,2
#define NAND_A2   P2,3

#define NAND_Y1   P2,4
#define NAND_B1   P2,5
#define NAND_A1   P2,6

/**
 * @brief Different combinations of `setting` / `clearing` pins.
 * 
 * Different pins state transformations over `Ax` and `Bx`,
 * to correctly identify `IC7400` chip.
 */
void _ic7400_clear_A_clear_B() {
    clr(NAND_A1); clr(NAND_B1);
	clr(NAND_A2); clr(NAND_B2);
	clr(NAND_A3); clr(NAND_B3);
	clr(NAND_A4); clr(NAND_B4);
}

void _ic7400_clear_A_set_B() {
    clr(NAND_A1); setb(NAND_B1);
	clr(NAND_A2); setb(NAND_B2);
	clr(NAND_A3); setb(NAND_B3);
	clr(NAND_A4); setb(NAND_B4);
}

void _ic7400_set_A_clear_B() {
    setb(NAND_A1); clr(NAND_B1);
	setb(NAND_A2); clr(NAND_B2);
	setb(NAND_A3); clr(NAND_B3);
	setb(NAND_A4); clr(NAND_B4);
}

void _ic7400_set_A_set_B() {
    setb(NAND_A1); setb(NAND_B1);
	setb(NAND_A2); setb(NAND_B2);
	setb(NAND_A3); setb(NAND_B3);
	setb(NAND_A4); setb(NAND_B4);
}

/**
 * @brief IC7400 Tester Function.
 * 
 * @return true 
 * @return false 
 */
bool ic7400_check() {
	/**
	 * Give power to the IC.
	 * 
     * Setting `VCC`.
     * Clearing `GND`.
	*/
	setb(NAND_VCC); clr(NAND_GND);

	/**
	 * Start checking the truth table.
     * 
     * - First for: A=L, B=L, Y=H.
     * - clear `NAND_Ax` and `NAND_Bx`.
	*/
	_ic7400_clear_A_clear_B();
	_EXPECT_TRUE(GetBit(NAND_Y1) && GetBit(NAND_Y2) && GetBit(NAND_Y3) && GetBit(NAND_Y4));

    /**
     * Second for: A=L, B=H, Y=H.
     * 
     * - clear `NAND_Ax`.
     * - set   `NAND_Bx`.
    */
	_ic7400_clear_A_set_B();
	_EXPECT_TRUE(GetBit(NAND_Y1) && GetBit(NAND_Y2) && GetBit(NAND_Y3) && GetBit(NAND_Y4));

    /**
     * Third for: A=H, B=L, Y=H.
     * 
     * - set     `NAND_Ax`.
     * - clear   `NAND_Bx`.
    */
    _ic7400_set_A_clear_B();
	_EXPECT_TRUE(GetBit(NAND_Y1) && GetBit(NAND_Y2) && GetBit(NAND_Y3) && GetBit(NAND_Y4));

    /**
     * Fourth for: A=H, B=H, Y=L.
     * 
     * - set `NAND_Ax`.
     * - set `NAND_Bx`.
    */
	_ic7400_set_A_set_B();
	_EXPECT_FALSE(GetBit(NAND_Y1) || GetBit(NAND_Y2) || GetBit(NAND_Y3) || GetBit(NAND_Y4));

	/**
	 * Return `true` on passing all checks for IC7400.
     * 
     * @alias true 1
	*/
	return true;
}

#endif // __IC_7400__
