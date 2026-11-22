#include "godhand/globals.h"
extern int GetD003EE804_360720(void);
extern void SFXLIB_Error(void *a0, void *a1, char *msg);

__attribute__((section(".text.func_00360520")))
void func_00360520(void *hn, unsigned int *src, short *dst)
{
    int i;

    if (GetD003EE804_360720() == 1) {
        for (i = 0; i < 0x100; i++)
            dst[i] = src[i] >> 15;
    } else {
        SFXLIB_Error(0, 0, D_0045A0A0);
    }
}
