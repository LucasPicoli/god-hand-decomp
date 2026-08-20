/* sn-2.95.3-136 matched TU. */

extern int cCoreSave_getGameLevel(void *a0);
extern int Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(void *a0);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float heat);
extern char *D_00569B70;
extern unsigned short D_005CAC94;
extern int D_005CB000;

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_0012C0F8")))
short func_0012C0F8(void *a0, int a1)
{
    char *s1 = (char *)a0;
    short old;
    float f;
    int orig;
    int d;

    orig = a1;
    old = *(short *)(s1 + 0x54A);
    switch (cCoreSave_getGameLevel(&D_00569B70)) {
    case 1:
    default:
        f = 0.6f;
        break;
    case 2:
        f = 0.8f;
        break;
    case 3:
    case 4:
        f = 1.0f;
        break;
    case 5:
        f = 1.2f;
        break;
    }
    if (Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(&D_00569B70) == 0 &&
        (*(int *)(D_00569B70 + 0x14) & 0x4000000) == 0) {
        f *= 0.5f;
    } else {
        f *= 0.75f;
    }
    if ((Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(&D_00569B70) ^ 2) != 0) {
        unsigned short lv = D_005CAC94;
        if (lv >= 2) {
            if (lv >= 4) {
                f *= 0.7f;
            } else if (lv >= 3) {
                f *= 0.8f;
            } else {
                f *= 0.9f;
            }
        }
    }
    a1 = (int)((float)a1 * f + 0.5f);
    if (a1 > 0x7D00) {
        a1 = 0x7D00;
    }
    if (orig > 0) {
        if (a1 <= 0) {
            a1 = 1;
        }
    }
    d = *(unsigned short *)(s1 + 0x54A) - a1;
    *(short *)(s1 + 0x54A) = d;
    if ((d << 16) <= 0) {
        *(short *)(s1 + 0x54A) = 0;
    }
    if (old >= 0xB) {
        if (*(short *)(s1 + 0x54A) <= 0) {
            *(short *)(s1 + 0x54A) = 1;
        }
    }
    if (a1 > 0) {
        float r = 1.0f / (float)*(short *)(s1 + 0x548);
        float g = (float)a1 * r * 10.0f;
        if (10.0f < g) {
            g = 10.0f;
        }
        cHeatSys_AddHeatGage(&D_005CB000, 0, g);
    }
    return *(short *)(s1 + 0x54A);
}
