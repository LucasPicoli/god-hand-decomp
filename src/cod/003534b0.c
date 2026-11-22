/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern unsigned char D_003FC7B8[];

__attribute__((section(".text.func_003534B0")))
int func_003534B0(char *a0) {
    int *p = (int*)(a0 + 0x36B4);
    int *q = (int*)(a0 + 0xDF0);
    int *r = (int*)(a0 + 0xE48);
    int v = p[1];
    if (v < 0) return 0;
    if (*r != 0) return 0;
    return func_00366918(v, p[2], q[9], q[10]) == 0;
}

__attribute__((section(".text.func_003B9E60")))
void func_003B9E60(void) {
    if (D_003FC7A8 == 1) {
        func_003A52F0(D_003FC7B8, 0, 0x3C);
    }
    D_003FC7A8 = D_003FC7A8 - 1;
}
