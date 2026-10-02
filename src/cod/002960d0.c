/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int FindResolveActor_295978(void *a0, float f);
extern void func_0026E7A0(int a0, float f);
extern int D_0044A870;
extern void func_002736F8(int a0);
extern void func_00289028(int a0);
extern int D_0044A878;
extern void cEma2_SetEscPos(int a0, int a1);
extern void cEm00_setAlphaMode(int a0, int a1);

__attribute__((section(".text.cEmWrap_StartEscape")))
void cEmWrap_StartEscape(void *a0, float f) {
    if (FindResolveActor_295978(a0, f)) {
        int *p = *(int **)((char *)a0 + 4);
        if (func_003A5678(&D_0044A878, p[0x4AC / 4]) == 0) {
            func_00289028(*(int *)((char *)a0 + 4));
        }
    }
}

__attribute__((section(".text.cEmWrap_setAlphaMode")))
void cEmWrap_setAlphaMode(void *a0, int a1, float f) {
    if (FindResolveActor_295978(a0, f)) {
        int *p = *(int **)((char *)a0 + 4);
        if (func_003A5678(&D_0044A870, p[0x4AC / 4]) == 0) {
            cEm00_setAlphaMode(*(int *)((char *)a0 + 4), a1);
            if (a1 == 0) {
                *(short *)(*(char **)((char *)a0 + 4) + 0x2AE) = 0x1770;
            } else {
                *(short *)(*(char **)((char *)a0 + 4) + 0x2AE) = 0x258;
            }
        }
    }
}
