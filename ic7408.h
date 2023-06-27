/**
 * @file ic7408.h
 * @author Microprocessor & Assembly Course Group 07
 * @brief IC7408 API
 * @version 0.1
 * @date 2022-12-12
 *
 * 
 * IC7408 direct guarded api for interfacing with
 * a 7408 model hardware IC chip. 
*/
#ifndef __IC_7408__
#define __IC_7408__

/** Internal Includes */
#include "ATSTAMP.h"
#include "utils.h"

/** Standard Includes */
#include <stdbool.h>

/** Identifier */
#define CHIP_7408 7408

/** Pin Addresses */
#define AND_VCC  P0,0
#define AND_GND  P2,0

#define AND_B4   P0,1
#define AND_A4   P0,2
#define AND_Y4   P0,3

#define AND_B3   P0,4
#define AND_A3   P0,5
#define AND_Y3   P0,6

#define AND_Y2   P2,1
#define AND_B2   P2,2
#define AND_A2   P2,3

#define AND_Y1   P2,4
#define AND_B1   P2,5
#define AND_A1   P2,6

/**
 * @brief Different combinations of `setting` / `clearing` pins.
 * 
 * Different pins state transformations over `Ax` and `Bx`,
 * to correctly identify `IC7408` chip.
*/
void _ic7408_clear_A_clear_B() {
    clr(AND_A1); clr(AND_B1);
	clr(AND_A2); clr(AND_B2);
	clr(AND_A3); clr(AND_B3);
	clr(AND_A4); clr(AND_B4);
}

void _ic7408_clear_A_set_B() {
    clr(AND_A1); setb(AND_B1);
	clr(AND_A2); setb(AND_B2);
	clr(AND_A3); setb(AND_B3);
	clr(AND_A4); setb(AND_B4);
}

void _ic7408_set_A_clear_B() {
    setb(AND_A1); clr(AND_B1);
	setb(AND_A2); clr(AND_B2);
	setb(AND_A3); clr(AND_B3);
	setb(AND_A4); clr(AND_B4);
}

void _ic7408_set_A_set_B() {
    setb(AND_A1); setb(AND_B1);
	setb(AND_A2); setb(AND_B2);
	setb(AND_A3); setb(AND_B3);
	setb(AND_A4); setb(AND_B4);
}

/**
 * @brief IC7408 Tester Function.
 * 
 * @return true 
 * @return false 
*/
bool ic7408_check() {
	/**
	 * Give power to the IC.
	 * 
     * Setting `VCC`.
     * Clearing `GND`.
	*/
	setb(AND_VCC); clr(AND_GND);

	/**
	 * Start checking the truth table.
     * 
     * - First for: A=L, B=L, Y=L.
     * - clear `AND_Ax` and `AND_Bx`.
	*/
	_ic7408_clear_A_clear_B();
	_EXPECT_FALSE(GetBit(AND_Y1) || GetBit(AND_Y2) || GetBit(AND_Y3) || GetBit(AND_Y4));

    /**
     * Second for: A=L, B=H, Y=L.
     * 
     * - clear `AND_Ax`.
     * - set   `AND_Bx`.
    */
	_ic7408_clear_A_set_B();
	_EXPECT_FALSE(GetBit(AND_Y1) || GetBit(AND_Y2) || GetBit(AND_Y3) || GetBit(AND_Y4));

    /**
     * Third for: A=H, B=L, Y=L.
     * 
     * - set     `AND_Ax`.
     * - clear   `AND_Bx`.
    */
    _ic7408_set_A_clear_B();
	_EXPECT_FALSE(GetBit(AND_Y1) || GetBit(AND_Y2) || GetBit(AND_Y3) || GetBit(AND_Y4));

    /**
     * Fourth for: A=H, B=H, Y=H.
     * 
     * - set `AND_Ax`.
     * - set `AND_Bx`.
    */
	_ic7408_set_A_set_B();
	_EXPECT_TRUE(GetBit(AND_Y1) && GetBit(AND_Y2) && GetBit(AND_Y3) && GetBit(AND_Y4));

	/**
	 * Return `true` on passing all checks for IC7408.
     * 
     * @alias true 1
	*/
	return true;
}

#endif // __IC_7408__
