/* cygnus-2.96 matched TU. */

extern void sfmpv_SetTermDst(void *a0, int a1);
extern void SFSET_SetCond(void *a0, int a1, int a2);
extern int Obj0000_Set_D_00766D44_Check_Field_188_NE_2(int *);
extern char D_003F1AA0;
extern void *memcpy(void *, const void *, unsigned int);

__attribute__((section(".text.sfmpv_ChkTermFlg")))
void sfmpv_ChkTermFlg(char *a0) {
    int *p = (int *)(a0 + 0x950);
    int r = SFMPVF_GetNumFrm(a0);
    if (r != -1) {
        if (sfmpv_IsFinalFrmGotten(a0, r) == 0)
            return;
    }
    sfmpv_SetTermDst(a0, 1);
    if (*p != 0)
        return;
    SFSET_SetCond(a0, 5, 0);
}

__attribute__((section(".text.MPV_SetErrFunc")))
void *MPV_SetErrFunc(char *o, int a1, int a2) {
    char *p;
    if (o == 0) {
        p = &D_003F1AA0;
    } else {
        if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2((int *)o))
            return func_00369F20(0, (void *)0xFF030203);
        p = o + 0x250;
    }
    *(int *)(p + 0x0) = a1;
    *(int *)(p + 0x4) = a2;
    return 0;
}

__attribute__((section(".text.MPV_RequestStop")))
void MPV_RequestStop(char *o) {
    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2((int *)o)) {
        func_00369F20(0, (void *)0xFF030211);
        return;
    }
    *(int *)(o + 0x408) = 1;
    if (*(int *)(o + 0x35C) == 2)
        MPVM2V_RequestStop((int *)o);
}

__attribute__((section(".text.MPV_GetVbvBufSiz")))
void *MPV_GetVbvBufSiz(char *o, int *p1, int *p2, int *p3) {
    int a0v;
    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2((int *)o))
        return func_00369F20(0, (void *)0xFF03020F);
    *p1 = *(int *)(o + 0x2AC) << 11;
    *p2 = *(int *)(o + 0x2BC);
    a0v = *(int *)(o + 0x2A8);
    if (a0v == 0x3FFFF)
        *p3 = -1;
    else
        *p3 = (*(int *)(o + 0x2BC) * a0v) / 0x708;
    return 0;
}

__attribute__((section(".text.MPV_GetPicAtr")))
void *MPV_GetPicAtr(char *o, void *dst) {
    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2((int *)o))
        return func_00369F20(0, (void *)0xFF03020C);
    memcpy(dst, o + 0x1D0, 0x80);
    return 0;
}
