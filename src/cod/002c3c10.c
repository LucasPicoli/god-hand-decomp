/* sn-2.95.3-136 matched TU. */

extern int D_00747A78;
extern int D_00747A80;
extern int D_00747A84;
extern char D_005864F0[];
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void pl00_reset(void *a0);
extern void ClearCameraOverlayState_2C3FC0(void *a0);
extern void func_002948E8(void *a0, int a1);
extern void cScenario_setOmSuspend(void *a0, int a1);
extern void func_002FA470(int a0);

__attribute__((section(".text.cScenario__endSoftEvent")))
void cScenario__endSoftEvent(int a0)
{
    char *s2 = (char *)a0;
    int t;
    int c;
    int v;

    c = *(unsigned short *)(s2 + 0xE8);
    if (*(short *)(s2 + 0xE8) <= 0) return;
    t = c - 1;
    *(unsigned short *)(s2 + 0xE8) = t;
    if ((short)t > 0) return;

    {
        char *g = (char *)&D_00747A84;

        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x02000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x00400000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x00100000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x00040000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & 0x7FFFFFFF;
        D_00747A84 = D_00747A84 & ~0x40000000;
        D_00747A84 = D_00747A84 & ~0x40;
        D_00747A84 = D_00747A84 & ~0x00010000;
        D_00747A84 = D_00747A84 & ~0x04000000;
        D_00747A84 = D_00747A84 & ~0x01000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x40000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x20000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x10000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x08000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x04000000;
        *(int *)(g - 0x4) = *(int *)(g - 0x4) & ~0x00100000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x00800000;

        switch (*(int *)(s2 + 0xE0)) {
        case 0:
        case 1:
        case 3:
            D_00747A80 = D_00747A80 & ~0x02000000;
            func_002FA470(0);
            ClearCameraOverlayState_2C3FC0(s2);
            break;
        case 2:
            D_00747A80 = D_00747A80 & ~0x02000000;
            func_002FA470(0);
            break;
        case 4:
            D_00747A84 = D_00747A84 & ~0x00080000;
            pl00_reset(Obj0000_Get_D_00747A94_2DB6B0());
            ClearCameraOverlayState_2C3FC0(s2);
            break;
        case 5:
            ClearCameraOverlayState_2C3FC0(s2);
            break;
        }
    }
    func_002948E8(D_005864F0, 0);
    cScenario_setOmSuspend(s2, 0);
    {
        char *p = (char *)Obj0000_Get_D_00747A94_2DB6B0();
        char *vt = *(char **)(p + 0x214);
        (*(void (**)(char *, int))(vt + 0x64))(p + *(short *)(vt + 0x60), 0);
    }
    v = *(int *)(s2 + 0x24);
    if (v >= 0) {
        char *e = (char *)(v * 0x58 + *(int *)(s2 + 0x1C));
        *(unsigned char *)(e + 0x50) = *(unsigned char *)(e + 0x50) & 0xFE;
    }
    *(int *)(s2 + 0x48) = *(int *)(s2 + 0x48) & ~1;
}
