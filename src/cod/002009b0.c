/* cygnus-2.96 matched TU. */
#include "godhand/sndTiming.h"

extern char D_00747A78[];
extern SndSystemVol D_0076A7B8;         /* D_0076A790.vol */

typedef struct {
    char b[24];
} T24;

__attribute__((section(".text.SetField_1C_2009B0")))
void SetField_1C_2009B0(char *dst, char *src) {
    *(T24 *)(dst + 0x1C) = *(T24 *)src;
}

/* cygnus-2.96 | as sn */
typedef struct {
    char b[8];
} T8;



__attribute__((section(".text.func_002BF800")))
void func_002BF800(char *p)
{
    *(T8 *)D_00747A78 = *(T8 *)(p + 0x74);
}

__attribute__((section(".text.SdeSystemVolGet")))
void SdeSystemVolGet(SndSystemVol *dst) {
    *dst = D_0076A7B8;
}
