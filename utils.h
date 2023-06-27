#ifndef __UTILS_H__
#define __UTILS_H__

#include <conio.h>
#include <windows.h>
#include <string.h>

/**
 * Expects `condition` to be `truthy` otherwise,
 * it terminates the function with a `falsy` result.
 *
 * @note Used internally only, external usages are discouraged.
*/
#define _EXPECT_TRUE(condition) \
    if (!(condition)) return 0


/**
 * Expects `condition` to be `falsy` otherwise,
 * it terminates the function with a `falsy` result.
 *
 * @note Used internally only, external usages are discouraged.
*/
#define _EXPECT_FALSE(condition) \
    if ((condition)) return 0


#define __await(callable, duration) \
    callable(); Sleep(duration)

#endif
