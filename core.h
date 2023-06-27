#ifndef __CORE_H__
#define __CORE_H__

#include "ic7400.h"
#include "ic7404.h"
#include "ic7408.h"
#include "ic7432.h"
#include "utils.h"
#include "state.h"

int detect_ic() {
	__await(state_apply, 100);
	if (ic7400_check()) return CHIP_7400;

	__await(state_apply, 100);
	if (ic7404_check()) return CHIP_7404;

	__await(state_apply, 100);
	if (ic7408_check()) return CHIP_7408;

	__await(state_apply, 100);
	if (ic7432_check()) return CHIP_7432;

    return -1;
}

#endif
