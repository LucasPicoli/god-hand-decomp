/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void DTX_Finish(void);
extern void DTX_Init(void);

typedef struct SJ SJ;
struct SJVT { char pad[0x24]; int (*f24)(SJ *, int); };
struct SJ { struct SJVT *vt; };




__attribute__((section(".text.ADXT_GetNumSmplObuf")))
int ADXT_GetNumSmplObuf(int adxt, int ch)
{
    SJ *sj;
    if (adxt == 0 || ch < 0) {
        func_0033F130(D_00452408);
        return -1;
    }
    sj = *(SJ **)(ch * 4 + adxt + 0x18);
    if (sj != 0) return sj->vt->f24(sj, 1) / 2;
    return 0;
}

__attribute__((section(".text.ADXT_IsHeader")))
int ADXT_IsHeader(unsigned short *buf, int len, int *out)
{
    short a;
    char b, c, d, e;
    int f, g, h;
    unsigned short v;
    if (len < 2) return 0;
    v = buf[0];
    if ((unsigned short)((v >> 8) | (v << 8)) != 0x8000) return 0;
    if (func_0033E8A0(buf, len, &a, &b, &c, &d, &e, &f, &g, &h) < 0) return 0;
    *out = a;
    return 1;
}

__attribute__((section(".text.func_0033B010")))
void func_0033B010(void)
{
    if (--D_003E8DCC == 0) DTX_Finish();
}

__attribute__((section(".text.SJRMT_Init")))
void SJRMT_Init(void)
{
    int unused = D_003E8DC8;
    if (D_003E8DCC == 0) DTX_Init();
    D_003E8DCC = D_003E8DCC + 1;
}
