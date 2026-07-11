/* sn-2.95.3-136 matched TU. */

extern char D_00463050[];
extern int D_003C2F84;
extern int D_00747A78;
extern void cCamManager_setPlCamera(char *a0, int a1);
extern void cScenario__endSoftEvent(int a0);
extern char D_005FEE00[];
extern void cSnd_SeCall_2CB8A0(char *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern void func_003201F0();
extern void func_0031F4A0();

__attribute__((section(".text.func_00171A70")))
int func_00171A70(char *a0, char *a1)
{
    char *a2 = a0 + 0x100;
    if (a2 != a1) {
        *(float *)(a0 + 0x100) = *(float *)(a1 + 0);
        *(float *)(a2 + 4) = *(float *)(a1 + 4);
        *(float *)(a2 + 8) = *(float *)(a1 + 8);
    }
    return func_001717C0(a0, *(int *)(a0 + 0xF0), a2);
}

__attribute__((section(".text.func_0017C408")))
int func_0017C408(char *a0, char *a1)
{
    char *a2 = a0 + 0x100;
    if (a2 != a1) {
        *(float *)(a0 + 0x100) = *(float *)(a1 + 0);
        *(float *)(a2 + 4) = *(float *)(a1 + 4);
        *(float *)(a2 + 8) = *(float *)(a1 + 8);
    }
    return func_0017C028(a0, *(int *)(a0 + 0xF0), a2);
}

__attribute__((section(".text.func_001832A8")))
int func_001832A8(char *a0, char *a1)
{
    char *a2 = a0 + 0x100;
    if (a2 != a1) {
        *(float *)(a0 + 0x100) = *(float *)(a1 + 0);
        *(float *)(a2 + 4) = *(float *)(a1 + 4);
        *(float *)(a2 + 8) = *(float *)(a1 + 8);
    }
    return cOl30_SetInitialPosition(a0, *(int *)(a0 + 0xF0), a2);
}

__attribute__((section(".text.func_001A4CF8")))
void func_001A4CF8(char *a0) {
    if (*(unsigned char *)(a0 + 0x763)) {
        cCamManager_setPlCamera(D_00463050, 0);
        cScenario__endSoftEvent(D_003C2F84);
        D_00747A78 &= 0xFFFEFFFF;
    }
}

__attribute__((section(".text.func_001A95F0")))
int func_001A95F0(char *a0, char *a1)
{
    char *a2 = a0 + 0x100;
    if (a2 != a1) {
        *(float *)(a0 + 0x100) = *(float *)(a1 + 0);
        *(float *)(a2 + 4) = *(float *)(a1 + 4);
        *(float *)(a2 + 8) = *(float *)(a1 + 8);
    }
    return func_001A9210(a0, *(int *)(a0 + 0xF0), a2);
}

__attribute__((section(".text.func_00294A88")))
void func_00294A88(char *a0) {
    if (*(short *)(a0 + 0x542) != 0) return;
    *(short *)(a0 + 0x542) = 0x96;
    cSnd_SeCall_2CB8A0(D_005FEE00, 2, 0xA4, -1, -1, 0, 0);
}

__attribute__((section(".text.cCollisionShape_setOffsetPos")))
int cCollisionShape_setOffsetPos(char *a0, char *a1)
{
    char *v0 = a0 + 0x50;
    if (v0 != a1) {
        *(float *)(a0 + 0x50) = *(float *)(a1 + 0);
        *(float *)(v0 + 4) = *(float *)(a1 + 4);
        *(float *)(v0 + 8) = *(float *)(a1 + 8);
    }
    return func_002BB2D8(a0);
}

__attribute__((section(".text.func_002BB298")))
int func_002BB298(char *a0, char *a1)
{
    char *v0 = a0 + 0x60;
    if (v0 != a1) {
        *(float *)(a0 + 0x60) = *(float *)(a1 + 0);
        *(float *)(v0 + 4) = *(float *)(a1 + 4);
        *(float *)(v0 + 8) = *(float *)(a1 + 8);
    }
    return func_002BB2D8(a0);
}

__attribute__((section(".text.func_00304BF8")))
int func_00304BF8(char *a0) {
    char *a1 = *(char **)(a0 + 0x108);
    if (a1 != 0) {
        *(int *)(a0 + 0x240) = *(unsigned char *)(a1 + 0x2F4);
        *(int *)(a0 + 0x244) = *(unsigned char *)(a1 + 0x2F5);
        *(int *)(a0 + 0x248) = *(unsigned char *)(a1 + 0x2F6);
        *(int *)(a0 + 0x24C) = *(unsigned char *)(a1 + 0x2F7);
        return func_00303A20(a0);
    }
    return 0;
}

__attribute__((section(".text.func_0031F9D0")))
int func_0031F9D0(char *a0) {
    int v0 = 0;
    if (a0 != 0) {
        char *p = *(char **)(a0 + 4);
        v0 = __dynamic_cast(*(int *)(p + 4), func_003201F0, 1,
                           a0 + *(short *)p, func_0031F4A0, a0);
    }
    return v0 != 0;
}
