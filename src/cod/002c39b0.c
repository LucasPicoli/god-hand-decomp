/* sn-2.95.3-136 matched TU. */

extern int D_00747A78;
extern int D_00747A84;
extern char D_00747B20[];
extern char D_005864F0[];
extern void HideModelMgr_ResetHiddenModels(void *a0);
extern void HideModelMgr_ClearHiddenModelList(void *a0);
extern void KeyStop(void);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_00126770(void *a0);
extern void func_002948E8(void *a0, int a1);
extern void cScenario_setOmSuspend(void *a0, int a1);
extern void func_002FA470(int a0);

__attribute__((section(".text.cScenario_startSoftEvent")))
void cScenario_startSoftEvent(void *a0, int a1)
{
    char *s2 = (char *)a0;
    int t;
    int v;

    t = *(unsigned short *)(s2 + 0xE8) + 1;
    *(unsigned short *)(s2 + 0xE8) = t;
    if ((short)t >= 2) return;

    *(int *)(s2 + 0xE0) = a1;
    if (a1 == 5) {
        HideModelMgr_ResetHiddenModels(D_00747B20);
        HideModelMgr_ClearHiddenModelList(D_00747B20);
    } else {
        char *g = (char *)&D_00747A84;
        D_00747A84 = D_00747A84 | 0x40000040;
        KeyStop();
        *(int *)(g - 0xC) = *(int *)(g - 0xC) | 0x00400000;
        *(int *)(g - 0x4) = *(int *)(g - 0x4) | 0x00100000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) | 0x00100000;
        *(int *)(g - 0x4) = *(int *)(g - 0x4) | 0x02000000;
        func_00126770(Obj0000_Get_D_00747A94_2DB6B0());

        switch (*(int *)(s2 + 0xE0)) {
        case 0:
        case 1:
        case 3:
            {
                char *g2 = (char *)&D_00747A78;
                char *p;
                char *vt;
                D_00747A78 = D_00747A78 | 0x00040000;
                *(int *)(g2 + 0xC) = *(int *)(g2 + 0xC) | 0x00010000;
                *(int *)(g2 + 0xC) = *(int *)(g2 + 0xC) | 0x04000000;
                HideModelMgr_ResetHiddenModels(D_00747B20);
                HideModelMgr_ClearHiddenModelList(D_00747B20);
                func_002948E8(D_005864F0, 1);
                cScenario_setOmSuspend(s2, 1);
                func_002FA470(1);
                p = (char *)Obj0000_Get_D_00747A94_2DB6B0();
                vt = *(char **)(p + 0x214);
                (*(void (**)(char *, int))(vt + 0x64))(p + *(short *)(vt + 0x60), 1);
                *(int *)(g2 + 0xC) = *(int *)(g2 + 0xC) | 0x01000000;
            }
            break;
        case 2:
            D_00747A78 = D_00747A78 | 0x00040000;
            D_00747A78 = D_00747A78 | 0x80000000;
            D_00747A78 = D_00747A78 | 0x40000000;
            D_00747A78 = D_00747A78 | 0x20000000;
            D_00747A78 = D_00747A78 | 0x10000000;
            D_00747A78 = D_00747A78 | 0x08000000;
            D_00747A78 = D_00747A78 | 0x04000000;
            D_00747A78 = D_00747A78 | 0x00800000;
            break;
        case 4:
            {
                char *g3 = (char *)&D_00747A84;
                D_00747A84 = D_00747A84 | 0x00080000;
                *(int *)(g3 - 0xC) = *(int *)(g3 - 0xC) | 0x40000000;
                *(int *)(g3 - 0xC) = *(int *)(g3 - 0xC) | 0x80000000;
                *(int *)(g3 - 0xC) = *(int *)(g3 - 0xC) | 0x20000000;
                *(int *)(g3 - 0xC) = *(int *)(g3 - 0xC) | 0x10000000;
                *(int *)(g3 - 0xC) = *(int *)(g3 - 0xC) | 0x04000000;
            }
            break;
        case 5:
            break;
        }
    }
    v = *(int *)(s2 + 0x24);
    if (v >= 0) {
        char *e = (char *)(v * 0x58 + *(int *)(s2 + 0x1C));
        *(unsigned char *)(e + 0x50) = *(unsigned char *)(e + 0x50) | 1;
    }
    *(int *)(s2 + 0x48) = *(int *)(s2 + 0x48) | 1;
}
