#include "godhand/mwPly.h"
#include "godhand/globals.h"

extern void Obj33F8_Tramp_0033F130_FCB0(char *);
extern int func_0032F4C8(void *);
extern int AIXSJD_GetSfreq(void *, int);
extern int AIXSJD_GetNumChan(void *, int);

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
            total += AIXSJD_GetSfreq(d, i) * AIXSJD_GetNumChan(d, i) * 18 / 32;
        }
        return total;
    }
    return 0;
}
