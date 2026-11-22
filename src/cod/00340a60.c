#include "godhand/globals.h"
extern void func_00340450(int msg);

__attribute__((section(".text.func_00340A60")))
void func_00340A60(char *obj, int rate)
{
    int q, n;

    if (obj == 0) {
        func_00340450((int)D_00456FE8);
        return;
    }
    if (rate <= 0) {
        func_00340450((int)D_00457010);
        return;
    }
    q = rate / 750;
    *(int *)(obj + 0x10) = rate;
    if (q > 96)
        q = 96;
    else if (q <= 0)
        q = 1;
    *(int *)(obj + 0x18) = q;
}
