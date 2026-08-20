/* sn-2.95.3-136 matched TU. */

extern int D_00569B70;
extern unsigned int D_00568240;
extern unsigned int D_00747A84;
extern unsigned short D_00747A50;
extern unsigned short D_005CAC94;
extern int D_003BF160[];
extern int Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(void *a0);
extern int cCoreSave_getGameLevel(void *a0);

/* sn-2.95.3-136 matched TU. */










__attribute__((section(".text.cCoreSave_addGameLevelPoint")))
void cCoreSave_addGameLevelPoint(void *a0, int a1)
{
    int *p;
    long v;
    int lv;
    int nl;
    int q;
    float f;

    if (*(int *)a0 == 0) {
        return;
    }
    if ((D_00747A84 & 0x400000) != 0) {
        return;
    }
    if (Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(a0) == 2) {
        return;
    }
    p = *(int **)&D_00569B70;
    if ((*(int *)((char *)p + 0x14) & 0x4000000) != 0) {
        v = *(unsigned int *)&D_00568240;
        if (((v >> 1) & 1) == 0) {
            return;
        }
    }
    lv = cCoreSave_getGameLevel(a0);
    if (a1 > 0) {
        switch (cCoreSave_getGameLevel(a0) - 1) {
        default:
        case 0: f = 1.5f; break;
        case 1: f = 1.2f; break;
        case 2: f = 1.0f; break;
        case 3: f = 0.7f; break;
        case 4: f = 0.5f; break;
        }
        if (D_005CAC94 >= 2) {
            f = f * 0.8f;
        }
    } else {
        switch (cCoreSave_getGameLevel(a0) - 1) {
        default:
        case 0: f = 1.0f; break;
        case 1: f = 1.0f; break;
        case 2: f = 1.0f; break;
        case 3: f = 1.0f; break;
        case 4: f = 1.0f; break;
        }
        if (D_00747A50 == 0x801) {
            f = f * 0.8f;
        }
    }
    a1 = (int)((float)a1 * f);
    if (a1 < -1000) {
        a1 = -1000;
    }
    *(unsigned short *)(*(int *)a0 + 0x1C) += a1;
    if (*(short *)(*(int *)a0 + 0x1C) < 0) {
        *(short *)(*(int *)a0 + 0x1C) = 0;
    }
    if (Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(a0) == 0) {
        q = *(int *)a0;
        if (*(short *)(q + 0x1C) > D_003BF160[1] - 1) {
            *(short *)(q + 0x1C) = D_003BF160[1] - 1;
        }
    } else {
        q = *(int *)a0;
        if (*(short *)(q + 0x1C) > D_003BF160[4] - 1) {
            *(short *)(q + 0x1C) = D_003BF160[4] - 1;
        }
    }
    nl = cCoreSave_getGameLevel(a0);
    if (nl < lv - 1) {
        nl = lv - 1;
    }
    if (nl == 4) {
        nl = 3;
    }
    if (lv < nl) {
        *(char *)(*(int *)a0 + 0x1E) = 1;
    }
    if (nl < lv) {
        q = *(int *)a0;
        nl = nl - 1;
        if (nl < 0) {
            nl = 0;
        }
        if (*(char *)(q + 0x1E) != 0) {
            *(unsigned char *)(q + 0x1E) -= 1;
            *(short *)(*(int *)a0 + 0x1C) = D_003BF160[nl];
        }
    }
}
