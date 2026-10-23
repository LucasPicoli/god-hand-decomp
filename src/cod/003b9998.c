/* cygnus-2.96: func_003B9998, set up the ADX decoder for the handle (same shape as
 * func_00336BA8): reset and configure, create the decoder under the lock, then install the five callbacks. */
#include "godhand/CriServer.h"

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

extern char D_00460818[];
extern char D_00460840[];
extern void *D_003D141C;
extern void *D_003E9D20;
extern void *D_003D1420;
extern void *D_003E9D18;
extern void *D_003E9D1C;

extern void func_00329EA8(AdxtView *adxt);
extern void func_003B9AF8(AdxtView *adxt);
extern void Obj3260_TrampVia0C_00337B30_D220(AdxtView *adxt, int v);
extern void Obj3260_TrampVia0C_00337B80_D238(AdxtView *adxt, int v);
extern void func_003B9E10(void);
extern void Obj0000_Set_D_003FC7AC_D_003FC7B0_3B9D98(void (*fn)(), int arg);
extern void func_003B9D48(void *a0, void *a1);
extern void Forward33B658_325C60(void);
extern void Forward33B670_325C78(void);
extern int func_003B9EB0(int a, int b);
extern void func_0033F1A8(char *a, char *b);
extern void CriServer_setFreq(CriServer *self, int freq);
extern void func_003B9B20(char *obj);
extern void func_003B9BF0(void *s);
extern void func_003B9BB8(int a0);
extern void func_003B9CE8(int a0, int a1);
extern void func_003B9D30(void);

__attribute__((section(".text.func_003B9998")))
void func_003B9998(AdxtView *adxt, int a1, int a2)
{
    int *sfreq = &adxt->sfreq;
    AdxtDecWork *w;
    int nch;
    int dec;

    func_00329EA8(adxt);
    func_003B9AF8(adxt);
    Obj3260_TrampVia0C_00337B30_D220(adxt, 1);
    Obj3260_TrampVia0C_00337B80_D238(adxt, 0);
    func_003B9E10();
    Obj0000_Set_D_003FC7AC_D_003FC7B0_3B9D98(func_003B9D48, 0);
    w = adxt->obj->work;
    nch = adxt->nch;
    Forward33B658_325C60();
    dec = func_003B9EB0(a1, a2);
    if (dec == 0) {
        func_0033F1A8(D_00460818, D_00460840);
        return;
    }
    CriServer_setCallback((CriServer *)dec, (void *)nch, (void *)*sfreq);
    CriServer_setFreq((CriServer *)dec, 0x14);
    w->dec = dec;
    D_003D141C = func_003B9B20;
    D_003E9D20 = func_003B9BF0;
    D_003D1420 = func_003B9BB8;
    D_003E9D18 = func_003B9CE8;
    D_003E9D1C = func_003B9D30;
    Forward33B670_325C78();
}
