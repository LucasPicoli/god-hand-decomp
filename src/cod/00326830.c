/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void adxsjd_clear(int a0);
extern void (*D_003EADB8)(void *, void *);
extern char D_003EADC0[];

/* clone */


__attribute__((section(".text.ADXSJD_Start")))
void ADXSJD_Start(void *a0) {
    adxsjd_clear(a0);
    *(char *)((char *)a0 + 0x1) = 1;
}

/* clone */





__attribute__((section(".text.func_0033F0F0")))
void func_0033F0F0(void) {
    func_003A52F0(D_003EADC0, 0, 0x100);
    D_003EADB8 = 0;
    D_003EADBC = 0;
}
