#include "godhand/mwPly.h"
#include "godhand/globals.h"

extern void Obj33F8_Tramp_0033F130_FCB0(char *);
extern int func_0032F4C8(void *);
extern int func_0032F4D0(void *, int);
extern int func_0032F4E0(void *, int);

__attribute__((section(".text.func_0032E3A0")))
int func_0032E3A0(MwPly *s)
{
    void *d;
    int i;
    int n;
    int total;

    if (s == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452E58);
        return -1;
    }
    if ((unsigned int)(s->stat - 1) < 3) {
        d = s->adx;
        total = 0;
        n = func_0032F4C8(d);
        for (i = 0; i < n; i++) {
            total += func_0032F4D0(d, i) * func_0032F4E0(d, i) * 18 / 32;
        }
        return total;
    }
    return 0;
}
