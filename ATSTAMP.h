#ifndef __ATSTAMP_H__
#define __ATSTAMP_H__

/** Standard Includes */
#include <stdbool.h>

/** Ports Definitions */
#define P0 0
#define P1 1
#define P2 2
#define P3 3

#ifdef __cplusplus
extern "C" {
#endif

void         CloseCom();
unsigned int SerialInput(unsigned int portnum);
void         clr(unsigned int portnum, unsigned char bit);
void         setb(unsigned int portnum, unsigned char bit);
bool         GetBit(unsigned int portnum, unsigned char bit);
void         SerialOutput(unsigned int portnum, unsigned char data);

#ifdef __cplusplus
bool         OpenCom(unsigned int ComPortNumber, int BAUDRATE = 115200);
#endif

#ifndef __cplusplus
bool         OpenCom(unsigned int ComPortNumber, int BAUDRATE);
#endif

#ifdef __cplusplus
}
#endif

#endif // __ATSTAMP_H__
