/* cygnus-2.96: func_003B9998, set up the ADX decoder for the handle (same shape as
 * func_00336BA8): reset and configure, create the decoder under the lock, then install the five callbacks. */
#include "godhand/CriServer.h"
#include "godhand/globals.h"

typedef struct AdxtDecWork {
    char pad0[0xC0];
    int dec;                /* 0xC0 */
} AdxtDecWork;

typedef struct AdxtInner {
    char pad0[4];
    AdxtDecWork *work;       /* 0x04 */
} AdxtInner;

typedef struct AdxtView {
    char pad0[4];
    AdxtInner *obj;       /* 0x04 */
    char pad8[8];
    int nch;                /* 0x10 */
    char pad14[4];
    int sfreq;              /* 0x18 */
} AdxtView;

extern void *D_003D1420;

extern void ADXT_Stop(AdxtView *adxt);
extern void func_003B9AF8(AdxtView *adxt);
extern void Obj3260_TrampVia0C_00337B30_D220(AdxtView *adxt, int v);
extern void Obj3260_TrampVia0C_00337B80_D238(AdxtView *adxt, int v);
extern void AC3CNV_Init(void);
extern void Obj0000_Set_D_003FC7AC_D_003FC7B0_3B9D98(void (*fn)(), int arg);
extern void func_003B9D48(void *a0, void *a1);
extern void Forward33B658_325C60(void);
extern void Forward33B670_325C78(void);
extern int AC3CNV_Create(int a, int b);
extern void func_0033F1A8(char *a, char *b);
extern void CriServer_setFreq(CriServer *self, int freq);
extern void AC3LINK_DetachAc3(char *obj);
extern void AC3LINK_ExecOneAc3(void *s);
extern void AC3LINK_StopAc3(int a0);
extern void AC3LINK_SetInSj(int a0, int a1);
extern void func_003B9D30(void);

__attribute__((section(".text.func_003B9998")))
void func_003B9998(AdxtView *adxt, int a1, int a2)
{
    int *sfreq = &adxt->sfreq;
    AdxtDecWork *w;
    int nch;
    int dec;

    ADXT_Stop(adxt);
    func_003B9AF8(adxt);
    Obj3260_TrampVia0C_00337B30_D220(adxt, 1);
    Obj3260_TrampVia0C_00337B80_D238(adxt, 0);
    AC3CNV_Init();
    Obj0000_Set_D_003FC7AC_D_003FC7B0_3B9D98(func_003B9D48, 0);
    w = adxt->obj->work;
    nch = adxt->nch;
    Forward33B658_325C60();
    dec = AC3CNV_Create(a1, a2);
    if (dec == 0) {
        func_0033F1A8(D_00460818, D_00460840);
        return;
    }
    CriServer_setCallback((CriServer *)dec, (void *)nch, (void *)*sfreq);
    CriServer_setFreq((CriServer *)dec, 0x14);
    w->dec = dec;
    D_003D141C = AC3LINK_DetachAc3;
    D_003E9D20 = AC3LINK_ExecOneAc3;
    D_003D1420 = AC3LINK_StopAc3;
    D_003E9D18 = AC3LINK_SetInSj;
    D_003E9D1C = func_003B9D30;
    Forward33B670_325C78();
}
