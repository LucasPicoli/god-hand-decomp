#include "godhand/criStm.h"

extern void func_0033C768(int a0, int a1, int a2, int a3);
extern void func_0033C7A0(int *a0, int a1, int a2);
extern void *func_003A52F0(void *dst, int val, int len);
extern void *func_0033F8B8(void);
extern void func_0033C918(ADX_BASIC *e);

/* Take a free decoder from the pool of 16 and give it an ADPCM decoder and the PCM output buffer. */
__attribute__((section(".text.ADXB_Create")))
ADX_BASIC *ADXB_Create(int a0, int a1, int a2, int a3)
{
    ADX_BASIC *p = D_003E9D60;
    ADX_BASIC *e;
    int i = 0;

    if (p->used != 0) {
        do {
            i++;
            p++;
            if (i >= 0x10)
                break;
        } while (p->used != 0);
    }
    if (i == 0x10)
        return 0;
    e = &D_003E9D60[i];
    func_003A52F0(e, 0, 0x104);
    e->used = 1;
    e->xpd = func_0033F8B8();
    if (e->xpd == 0) {
        func_0033C918(e);
        return 0;
    }
    e->getwrfunc = (char *)func_0033C768 + 8;
    e->maxnch = a0;
    e->pcmbuf = a1;
    e->pcmbsize = a2;
    e->pcmbdist = a3;
    e->addwrfunc = func_0033C7A0;
    e->getwrobj = e;
    e->addwrobj = e;
    adxb_ResetAinf(e);
    return e;
}
