/**
 * @file ic7432.h
 * @author Microprocessor & Assembly Course Group 07
 * @brief IC7432 API
 * @version 0.1
 * @date 2022-12-12
 *
 * 
 * IC7432 direct guarded api for interfacing with
 * a 7432 model hardware IC chip. 
*/
#ifndef __IC_7432__
#define __IC_7432__

/** Internal Includes */
#include "ATSTAMP.h"
#include "utils.h"

/** Standard Includes */
#include <stdbool.h>

/** Identifier */
#define CHIP_7432 7432

/** Pin Addresses */
#define OR_VCC  P0,0
#define OR_GND  P2,0

#define OR_B4   P0,1
#define OR_A4   P0,2
#define OR_Y4   P0,3

#define OR_B3   P0,4
#define OR_A3   P0,5
#define OR_Y3   P0,6

#define OR_Y2   P2,1
#define OR_B2   P2,2
#define OR_A2   P2,3

#define OR_Y1   P2,4
#define OR_B1   P2,5
#define OR_A1   P2,6

/**
 * @brief Different combinations of `setting` / `clearing` pins.
 * 
 * Different pins state transformations over `Ax` and `Bx`,
 * to correctly identify `IC7432` chip.
 */
void _ic7432_clear_A_clear_B() {
    clr(OR_A1); clr(OR_B1);
	clr(OR_A2); clr(OR_B2);
	clr(OR_A3); clr(OR_B3);
	clr(OR_A4); clr(OR_B4);
}

void _ic7432_clear_A_set_B() {
    clr(OR_A1); setb(OR_B1);
	clr(OR_A2); setb(OR_B2);
	clr(OR_A3); setb(OR_B3);
	clr(OR_A4); setb(OR_B4);
}

void _ic7432_set_A_clear_B() {
    setb(OR_A1); clr(OR_B1);
	setb(OR_A2); clr(OR_B2);
	setb(OR_A3); clr(OR_B3);
	setb(OR_A4); clr(OR_B4);
}

void _ic7432_set_A_set_B() {
    setb(OR_A1); setb(OR_B1);
	setb(OR_A2); setb(OR_B2);
	setb(OR_A3); setb(OR_B3);
	setb(OR_A4); setb(OR_B4);
}

/**
 * @brief IC7432 Tester Function.
 * 
 * @return true 
 * @return false 
 */
bool ic7432_check() {
	/**
	 * Give power to the IC.
	 * 
     * Setting `VCC`.
     * Clearing `GND`.
	*/
	setb(OR_VCC); clr(OR_GND);

	/**
	 * Start checking the truth table.
     * 
     * - First for: A=L, B=L, Y=L.
     * - clear `OR_Ax` and `OR_Bx`.
	*/
	_ic7432_clear_A_clear_B();
	_EXPECT_FALSE(GetBit(OR_Y1) || GetBit(OR_Y2) || GetBit(OR_Y3) || GetBit(OR_Y4));

    /**
     * Second for: A=L, B=H, Y=H.
     * 
     * - clear `OR_Ax`.
     * - set   `OR_Bx`.
    */
	_ic7432_clear_A_set_B();
	_EXPECT_TRUE(GetBit(OR_Y1) && GetBit(OR_Y2) && GetBit(OR_Y3) && GetBit(OR_Y4));

    /**
     * Third for: A=H, B=L, Y=H.
     * 
     * - set     `OR_Ax`.
     * - clear   `OR_Bx`.
    */
    _ic7432_set_A_clear_B();
	_EXPECT_TRUE(GetBit(OR_Y1) && GetBit(OR_Y2) && GetBit(OR_Y3) && GetBit(OR_Y4));

    /**
     * Fourth for: A=H, B=H, Y=H.
     * 
     * - set `OR_Ax`.
     * - set `OR_Bx`.
    */
	_ic7432_set_A_set_B();
	_EXPECT_TRUE(GetBit(OR_Y1) && GetBit(OR_Y2) && GetBit(OR_Y3) && GetBit(OR_Y4));

	/**
	 * Return `true` on passing all checks for IC7432.
     * 
     * @alias true 1
	*/
	return true;
}

#endif // __IC_7432__
