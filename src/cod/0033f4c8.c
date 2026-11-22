#include "godhand/globals.h"
extern void ADXF_CloseAll(void);
extern void *func_003A52F0(void *d, int c, unsigned int n);
extern signed char D_003EAEC8[];
extern char D_003EB308[];
extern char D_003EB710[];
extern char D_003EB810[];

__attribute__((section(".text.func_0033F4C8")))
void func_0033F4C8(void)
{
    if (--D_003EAEC0 == 0) {
        ADXF_CloseAll();
        D_003EB840 = 1;
        D_003EB83C = -1;
        D_003EB838 = 0;
        D_003EB834 = 0;
        D_003EB708 = 0;
        D_003EB830 = 0;
        func_003A52F0(D_003EB810, 0, 0x20);
        func_003A52F0(D_003EB710, 0xFF, 0x100);
        func_003A52F0(D_003EB308, 0, 0x400);
        func_003A52F0(D_003EAEC8, 0, 0x440);
    }
}
