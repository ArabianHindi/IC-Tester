#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define LED_INDICATOR_PIN P1,0

#include "state.h"
#include "utils.h"
#include "core.h"

#include "ic7400.h"
#include "ic7404.h"
#include "ic7408.h"
#include "ic7432.h"

int main() {
	/**
	 * Check availability of `portComNumber`.
	 * 
	 * @note terminates whole program on failure.
	*/
	if (!OpenCom(5, 115200))
		exit(0);

	/** Captures the initial state of the pins. */
	state_capture();

	/**
	 * Main loop of the program.
	 * 
	 * this expresses the periodic function of the project,
	 * repetitive checks over what `IC` is currently connected.
	*/
	while (1) {
		clr(LED_INDICATOR_PIN);
		int chip = detect_ic();

		switch (chip) {
			case CHIP_7400:
				printf("IC 7400 (Quad 2-Input NAND Gates) Detected!\n");
				break;
			
			case CHIP_7404:
				printf("IC 7404 (Hex Inverting Gates) Detected!\n");
				break;

			case CHIP_7408:
				printf("IC 7408 (Quad 2-Input AND Gates) Detected!\n");
				break;

			case CHIP_7432:
				printf("IC 7432 (Quad 2-Input OR Gates) Detected!\n");
				break;

			default:
				printf("No IC Detected. Please insert a sutible IC.\n");
		}

        setb(LED_INDICATOR_PIN);
		Sleep(1000);
	}

	return 0;
}
