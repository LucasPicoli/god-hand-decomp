#include "godhand/globals.h"
typedef struct AdxPs2Work {
    char pad0[0xE8];
    int dma;
    int unkEC;
    int unkF0;
} AdxPs2Work;

typedef struct AdxPs2Obj {
    char pad0[4];
    AdxPs2Work *work;
} AdxPs2Obj;

typedef struct AdxtPs2Hn {
    char pad0[3];
    signed char maxnch;
    AdxPs2Obj *obj;
} AdxtPs2Hn;

extern void func_0033F130(char *msg);
extern void ADXT_Stop(AdxtPs2Hn *adxt);
extern void func_00336CE0(AdxtPs2Hn *adxt);
extern void PL2ENC_Init(int);
extern void PL2ENC_SetCbErr(void (*fn)(int, int), int arg);
extern void Forward33B658_325C60(void);
extern void Forward33B670_325C78(void);
extern int func_00340538(int a, int b);
extern void PL2ENC_SetPos(int dma, int a, int b);
extern void Forward33F130_336E70(int a0, int a1);
extern void PL2LINK_DetachDolbyProLogicII(void *a0);
extern int Forward340740_336E38(int a0, int a1, int a2, int a3);
extern int Forward3406D0_336E20(int a0);
extern int Forward340A20_336E58(int a0, int a1);

__attribute__((section(".text.func_00336BA8")))
void func_00336BA8(AdxtPs2Hn *adxt, int a1, int a2)
{
    AdxPs2Work *w;
    int dma;

    if (adxt->maxnch < 2) {
        func_0033F130(D_00455290);
        return;
    }
    ADXT_Stop(adxt);
    func_00336CE0(adxt);
    PL2ENC_SetCbErr(Forward33F130_336E70, 0);
    PL2ENC_Init(0);
    w = adxt->obj->work;
    Forward33B658_325C60();
    dma = func_00340538(a1, a2);
    if (dma == 0) {
        func_0033F130(D_004552D0);
        return;
    }
    PL2ENC_SetPos(dma, w->unkEC, w->unkF0);
    w->dma = dma;
    D_003D1424 = PL2LINK_DetachDolbyProLogicII;
    D_003E9D4C = Forward340740_336E38;
    D_003E9D50 = Forward3406D0_336E20;
    D_003CF9EC = Forward340A20_336E58;
    Forward33B670_325C78();
}
