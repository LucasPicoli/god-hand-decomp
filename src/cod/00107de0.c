/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int D_0041DCC8[];
extern void __builtin_delete(void);
extern int D_004615F0[];
extern void pl00_reset(void);

__attribute__((section(".text.InitPtrField80AndForward_144AD0")))
void InitPtrField80AndForward_144AD0(void *a0, int a1) {
    *(int **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.ResetGlobalStateFields_107DE0")))
void ResetGlobalStateFields_107DE0(int a0, int a1) {
    if (a1 == 0xFFFF) {
        if (a0 != 0) {
            *(int*)((char*)D_004615F0+0) = 0;
            *(float*)((char*)D_004615F0+0xC) = 1.0f;
            *(int*)((char*)D_004615F0+0x8) = 0;
            *(int*)((char*)D_004615F0+0x4) = 0;
        }
    }
}

__attribute__((section(".text.StoreVec3Field_12CDF0")))
void StoreVec3Field_12CDF0(char *a0, float *a1) {
    float *p = (float*)(a0 + 0x650);
    if (p == a1) return;
    *(float*)(a0 + 0x650) = a1[0];
    p[1] = a1[1];
    p[2] = a1[2];
}
