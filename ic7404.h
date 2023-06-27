/**
 * @file ic7404.h
 * @author Microprocessor & Assembly Course Group 07
 * @brief IC7404 API
 * @version 0.1
 * @date 2022-12-12
 *
 * 
 * IC7404 direct guarded api for interfacing with
 * a 7404 model hardware IC chip. 
*/
#ifndef __IC_7404__
#define __IC_7404__

/** Internal Includes */
#include "ATSTAMP.h"
#include "utils.h"

/** Standard Includes */
#include <stdbool.h>

/** Identifier */
#define CHIP_7404 7404

/** Pin Addresses */
#define NOT_VCC  P0,0
#define NOT_GND  P2,0

#define NOT_A6   P0,1
#define NOT_Y6   P0,2

#define NOT_A5   P0,3
#define NOT_Y5   P0,4

#define NOT_A4   P0,5
#define NOT_Y4   P0,6

#define NOT_Y3   P2,1
#define NOT_A3   P2,2

#define NOT_Y2   P2,3
#define NOT_A2   P2,4

#define NOT_Y1   P2,5
#define NOT_A1   P2,6

/**
 * @brief Different combinations of `setting` / `clearing` pins.
 * 
 * Different pins state transformations over `Ax`,
 * to correctly identify `IC7404` chip.
*/
void _ic7404_clear_A() {
    clr(NOT_A1); clr(NOT_A2);
	clr(NOT_A3); clr(NOT_A4);
	clr(NOT_A5); clr(NOT_A6);
}

void _ic7400_set_A() {
    setb(NOT_A1); setb(NOT_A2);
	setb(NOT_A3); setb(NOT_A4);
	setb(NOT_A5); setb(NOT_A6);
}

/**
 * @brief IC7404 Tester Function.
 * 
 * @return true 
 * @return false 
*/
bool ic7404_check() {
	/**
	 * Give power to the IC.
	 * 
     * Setting `VCC`.
     * Clearing `GND`.
	*/
	setb(NOT_VCC); clr(NOT_GND);

	/**
	 * Start checking the truth table.
     * 
     * - First for: A=L, Y=H.
     * - clear `NOT_Ax`.
	*/
	_ic7404_clear_A();
	_EXPECT_TRUE(GetBit(NOT_Y1) && GetBit(NOT_Y2) && GetBit(NOT_Y3) && GetBit(NOT_Y4) && GetBit(NOT_Y5) && GetBit(NOT_Y6));

    /**
     * Second for: A=H, Y=L.
     * 
     * - set `NOT_Ax`.
    */
	_ic7400_set_A();
	_EXPECT_FALSE(GetBit(NOT_Y1) || GetBit(NOT_Y2) || GetBit(NOT_Y3) || GetBit(NOT_Y4) || GetBit(NOT_Y5) || GetBit(NOT_Y6));

	/**
	 * Return `true` on passing all checks for IC7404.
     * 
     * @alias true 1
	*/
	return true;
}

#endif // __IC_7404__
