#include "godhand/cSnd.h"

extern int PartHolder_classify(void *self);
extern void func_001DE858(void *self, unsigned char n);
extern void cSnd_SetBgmState(void *snd, int state);
extern void cSnd_BgmEventStart(void *snd, int ev, int a, int b);

__attribute__((section(".text.func_001D9CA0")))
void func_001D9CA0(void *self)
{
    int n;
    n = PartHolder_classify(self);
    *(int *)((char *)self + 0x3048) = n;
    if (n < 8) {
        func_001DE858(self, (unsigned char)*(int *)((char *)self + 0x3048));
        if (*(int *)((char *)self + 0x3048) < 8) {
            cSnd_SetBgmState(&D_005FEE00, 2);
            ((unsigned char *)self)[0x3024] = 9;
            ((unsigned char *)self)[0x3025] = 0;
            return;
        }
    }
    cSnd_BgmEventStart(&D_005FEE00, 0x28, 0, 0);
    ((unsigned char *)self)[0x3024] = 10;
    ((unsigned char *)self)[0x3025] = 0;
}

