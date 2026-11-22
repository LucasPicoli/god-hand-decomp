#include "godhand/globals.h"
extern void func_002E0DE8(int a0, int a1, int a2, const char *fmt, ...);
extern int SdeIssStatusGetBySndId(void *p);

__attribute__((section(".text.func_0037B338")))
void func_0037B338(char *self)
{
    void *item;
    int st;

    func_002E0DE8(3, 4, 8, D_0045BD90);
    item = *(void **)(self + 0xC);
    if (item == 0) {
        func_002E0DE8(0xC, 4, 0xF, D_0045BDA0);
        return;
    }
    st = SdeIssStatusGetBySndId(item);
    if (st == 0) {
        func_002E0DE8(0xC, 4, 0xF, D_0045BDA0);
        return;
    }
    if (st & 1)
        func_002E0DE8(0xC, 4, 0xD, D_0045BDA8);
    if (st & 2)
        func_002E0DE8(0xC, 4, 0xC, D_0045BDB8);
}
