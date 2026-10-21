#include "godhand/criStm.h"

extern void func_0033C768(int a0, int a1, int a2, int a3);
extern void func_0033C7A0(int *a0, int a1, int a2);
extern void *func_003A52F0(void *dst, int val, int len);
extern void *func_0033F8B8(void);
extern void func_0033C918(AsyncCall *e);
extern void AsyncCall_clearAinf(AsyncCall *e);

__attribute__((section(".text.func_0033C7F8")))
AsyncCall *func_0033C7F8(int a0, int a1, int a2, int a3)
{
    AsyncCall *p = D_003E9D60;
    AsyncCall *e;
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
    e->pd = func_0033F8B8();
    if (e->pd == 0) {
        func_0033C918(e);
        return 0;
    }
    e->cb = (char *)func_0033C768 + 8;
    e->a0 = a0;
    e->a1 = a1;
    e->a2 = a2;
    e->a3 = a3;
    e->fn = func_0033C7A0;
    e->cbarg = e;
    e->fnarg = e;
    AsyncCall_clearAinf(e);
    return e;
}
