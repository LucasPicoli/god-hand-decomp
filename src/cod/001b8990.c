/* sn-2.95.3-136 matched TU. */
#include "godhand/cObj.h"

extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern void func_001B76D8(void *a0);
extern struct Table_0017ADE0 D_003BDD98;

struct Entry_0017ADE0 { short f0; short f2; short f4; short f6; };
struct Table_0017ADE0 { struct Entry_0017ADE0 e[1]; };


__attribute__((section(".text.func_001B8990")))
void func_001B8990(void *a0)
{
    cObj *s0 = a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = s0->mode * 8;
    e = (char *)&D_003BDD98 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDD98 + i8 + 4);
    }
    f0 = D_003BDD98.e[s0->mode].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)s0 + arg));
    func_001B76D8(s0);
}
