/* sn-2.95.3-136 matched TU. */
#include "godhand/globals.h"

extern char D_00455920[];
extern char D_00455950[];
extern char D_00455BD8[];
extern char D_00455C08[];
extern int func_002AFC48(void *a0, float f12, float f13, int a1, int a2, int a3, int t0, int t1);
extern unsigned char D_003C23B0[];

__attribute__((section(".text.sjmem_GetUuid")))
int sjmem_GetUuid(int *a0) {
    if (a0 == 0) {
        func_00338A48(D_00455970, D_00455920);
        return 0;
    }
    if (a0[1] != 0) {
        return a0[2];
    }
    func_00338A48(D_00455980, D_00455950);
    return 0;
}

__attribute__((section(".text.sjuni_GetUuid")))
int sjuni_GetUuid(char *a0) {
    if (a0 == 0) {
        func_0033A048(D_00455C28, D_00455BD8);
        return 0;
    }
    if (*(char *)(a0 + 4) != 0) {
        return *(int *)(a0 + 8);
    }
    func_0033A048(D_00455C38, D_00455C08);
    return 0;
}

__attribute__((section(".text.func_002AFC08")))
int func_002AFC08(void *a0, int a1)
{
    return func_002AFC48(
        a0,
        *(float*)((char*)a0+0x88),
        *(float*)((char*)a0+0x8C),
        *(int*)((char*)a0+0x4),
        *(int*)((char*)a0+0x64),
        *(int*)((char*)a0+0x68),
        a1,
        *(int*)((char*)a0+0x1C) - *(int*)((char*)a0+0x6C));
}

__attribute__((section(".text.func_002B0480")))
void func_002B0480(void *a0, void *a1)
{
    int v1;
    int v0;
    int r;
    *(float*)((char*)a1+0x0) = 1.0f;
    v1 = *(int*)((char*)a0+0x4C) * 20;
    v0 = (*(int*)((char*)a0+0x50) << 2) + v1;
    r = *(int*)(D_003C23B0 + v0);
    *(int*)((char*)a1+0x8) = 0;
    *(int*)((char*)a1+0x4) = r;
}
