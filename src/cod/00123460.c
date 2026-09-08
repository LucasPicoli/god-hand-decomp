/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void KillEffect(void *a0, int a1, int a2);
extern int cCoreSave_getCostumeNo(void *a0);
extern unsigned int cCoreSave_getGodItemNum(void *a0);
extern void cCoreSave_addGodItem(void *a0, int a1);
extern void cHeatSys_SetHeatGage(void *a0, float f12);
extern int cHeatSys_SubHeatGage(void *a0, int a1, float f12);
extern int cHeatSys_GetHeatLv(void *a0);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float SetField444SignedByFlag434_158288(void *a0, float f12);
extern void func_001CF6E0(int a0);
extern void func_001FC138(void *a0);

extern float D_003BD4A0;
extern int D_00747A2C;
extern char D_005CB000[];
extern int D_00569B70;

__attribute__((section(".text.func_00123460")))
void func_00123460(void *arg)
{
    char *s0 = (char *)arg;
    float g;
    int ph;

    g = D_003BD4A0;
    if (*(int *)(s0 + 0x6A8) != 0) {
        if ((*(int *)(s0 + 0x15F4) & 0x20) == 0) {
            func_001CF6E0(*(int *)(s0 + 0x6A8));
            *(int *)(s0 + 0x6A8) = 0;
            func_001FC138(&D_00569B70);
        }
    }
    ph = *(unsigned char *)(s0 + 0x2F4);
    if (ph == 5) {
        return;
    }
    if (ph == 6) {
        return;
    }

    if (D_00747A2C & 0x80000) {
        cHeatSys_SetHeatGage(D_005CB000, *(float *)D_005CB000);
        if (cCoreSave_getGodItemNum(&D_00569B70) < 3) {
            cCoreSave_addGodItem(&D_00569B70, 1);
        }
    }

    {
        int f1 = *(int *)(s0 + 0x15F4);
        int msk = f1 & 0x200;
        int ok = (msk == 0);
        unsigned char *h = (unsigned char *)D_005CB000;
        if (h[0x10] != 0) {
            if (ok) {
                if (f1 & 0x80000) {
                    g = g * 0.25f;
                }
                cHeatSys_SubHeatGage(h, 1, g * *(float *)(s0 + 0x5A8));
            }
        }
    }

    if (*(int *)(s0 + 0x15F4) & 0x20) {
        int lv;
        lv = cHeatSys_GetHeatLv(D_005CB000);
        if (lv == 0) {
            int sta = *(unsigned short *)(s0 + 0x5F2);
            if (sta != 0) {
                KillEffect(s0, 3, 2);
                *(unsigned short *)(s0 + 0x5F2) = 0;
            }
        } else {
            int stb = *(unsigned short *)(s0 + 0x5F2);
            if (stb != 1) {
            KillEffect(s0, 3, 2);
            *(unsigned short *)(s0 + 0x5F2) = 1;
            switch (cCoreSave_getCostumeNo(&D_00569B70)) {
            case 0:
            case 2:
            case 4:
            case 6:
            default:
                SetEffect(0, 0x25, Obj0000_Get_D_00747A94_2DB6B0(), 0, 3, 0xFFFFFFFFu);
                break;
            case 1:
            case 3:
            case 5:
            case 7:
                SetEffect(0, 0x73, Obj0000_Get_D_00747A94_2DB6B0(), 0, 3, 0xFFFFFFFFu);
                break;
            }
            }
        }
    } else {
        int st2 = *(unsigned short *)(s0 + 0x5F2);
        if (st2 != 3) {
            *(unsigned short *)(s0 + 0x5F2) = 3;
            switch (cCoreSave_getCostumeNo(&D_00569B70)) {
            case 0:
            case 2:
            case 4:
            case 6:
            default:
                SetEffect(0, 0x21, s0, 0, 3, 0xFFFFFFFFu);
                break;
            case 1:
            case 3:
            case 5:
            case 7:
                SetEffect(0, 0x72, Obj0000_Get_D_00747A94_2DB6B0(), 0, 3, 0xFFFFFFFFu);
                break;
            }
        }
    }

    *(float *)(s0 + 0x5DC) = 1.0f;
    *(float *)(s0 + 0x5A8) = 1.0f;
    SetField444SignedByFlag434_158288(s0, 1.0f);
}
