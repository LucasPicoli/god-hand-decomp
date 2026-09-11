/* cygnus-2.96 matched TU. */

/* cygnus-2.96 candidate: sftim_GetVtimeTmr */

extern int GetArrayElemA0C_35A1C8(int, int);
extern int D_003EE270;

__attribute__((section(".text.func_0035A810")))
void func_0035A810(int a0, int a1, int *a2, int *a3)
{
    int *dp = &D_003EE270;
    int t;
    if (GetArrayElemA0C_35A1C8(a0, 0x47) == 1) {
        t = *(volatile int *)(a1 + 0x2D0);
        *a2 = *(volatile int *)(a1 + 0x2A8) - t;
        *a3 = dp[2];
    } else {
        *a2 = *(volatile int *)(a1 + 0x2DC) - *(volatile int *)(a1 + 0x2D0);
        *a3 = *(volatile int *)(a1 + 0x2E0);
    }
}
