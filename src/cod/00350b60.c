/* cygnus-2.96 matched TU. */

extern void func_00350C58(void *a0, int a1);
extern void func_0035A000(void *a0, int a1, int a2);
extern int Obj0000_Set_D_00766D44_Check_Field_188_NE_2(int *);
extern char D_003F1AA0;
extern void *memcpy(void *, const void *, unsigned int);

__attribute__((section(".text.func_00350B60")))
void func_00350B60(char *a0) {
    int *p = (int *)(a0 + 0x950);
    int r = func_00355508(a0);
    if (r != -1) {
        if (func_00350BE8(a0, r) == 0)
            return;
    }
    func_00350C58(a0, 1);
    if (*p != 0)
        return;
    func_0035A000(a0, 5, 0);
}

__attribute__((section(".text.func_00369E98")))
void *func_00369E98(char *o, int a1, int a2) {
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

__attribute__((section(".text.func_0036A070")))
void func_0036A070(char *o) {
    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2((int *)o)) {
        func_00369F20(0, (void *)0xFF030211);
        return;
    }
    *(int *)(o + 0x408) = 1;
    if (*(int *)(o + 0x35C) == 2)
        func_0036C8D0((int *)o);
}

__attribute__((section(".text.func_0036A238")))
void *func_0036A238(char *o, int *p1, int *p2, int *p3) {
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

__attribute__((section(".text.func_0036A0D0")))
void *func_0036A0D0(char *o, void *dst) {
    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2((int *)o))
        return func_00369F20(0, (void *)0xFF03020C);
    memcpy(dst, o + 0x1D0, 0x80);
    return 0;
}
