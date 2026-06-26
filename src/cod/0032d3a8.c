/* cygnus-2.96 matched TU. */

extern void func_00329D38(int a0, int a1);
extern int Obj34D8_SetGlobalEE0B8_IfField48(int a0, int a1);
extern int GetArrayElemA0C_35A1C8(int a0, int a1);
extern void func_003A52F0(int a0, int a1, int a2);
extern int MPSLIB_CheckHn();
extern int MPSLIB_SetErr();
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern void Obj33F8_Tramp_0033B670_FC88(void);
extern void func_0035A810(void *, void *, int *, int *);
extern void viBufDelete(void *a0);
extern int ReturnK_003EE2BC_00358A38_358A38(void);
extern void func_0039A998(void *a0);
extern void func_0039AA48(void);
extern void func_00356868(void *a0);
extern unsigned char D_003F1AC8[];
extern unsigned char *D_003F1ABC;
extern unsigned char D_003F1C48[];
extern void func_00366C50(int a0, int a1, int a2);
extern void func_00368E68(int a0);
extern int D_003F1A98;
extern int D_00760DB0;
extern int D_00760DB4;
extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(void *);
extern void M2VERR_SetCode(int, unsigned int);
extern void func_00368E80(void *a);
extern void func_00369118(void *a);
extern void func_00369130(void *a);
extern void func_00369158(void *a);
extern void func_00366EC0(void);
extern void func_0034C890(char *a0, int a1, int *a2);
extern void func_0034CAF8(int a0, int *a1, int *a2);
extern long long func_0034CCB0(long long a0, int a1);
extern void func_00368B18(char *a0, char *a1, int a2);
extern void func_00349F80(void *a0, int a1, int *out);
extern void func_00366960(int a0, int a1, int a2);
extern void func_00349FB0(void *a0, int a1, int *out);

__attribute__((section(".text.func_0032EFE8")))
void func_0032EFE8(int *a0) {
    int s2, s3;
    int *s1, *s0;
    s0 = a0;
    s3 = 0;
    s2 = func_0032F4C8(*(int *)((char *)s0 + 4));
    if (s2 > 0) {
        s1 = (int *)((char *)s0 + 0xC);
        s0 = (int *)((char *)s0 + 0x94);
        do {
            func_00329D38(*s1, *s0);
            s1++;
            s0++;
            s3++;
        } while (s3 < s2);
    }
}

__attribute__((section(".text.func_0034B648")))
void func_0034B648(int a0, int a1) {
    int s0, s1;
    int v0, v1;
    s0 = a0;
    v0 = Obj34D8_SetGlobalEE0B8_IfField48(a0, a1);
    s1 = a1;
    if (v0) {
        func_0034DD70(0, 0xFF0001A3);
        return;
    }
    v0 = GetArrayElemA0C_35A1C8(s0, 6);
    if (!v0) {
        return;
    }
    v0 = *(int *)(s0 + 0x2114);
    v1 = *(int *)(v0 + 0xC);
    ((void (*)(int, int))v1)(s0, s1);
}

__attribute__((section(".text.func_00359370")))
void func_00359370(int a0, int a1, int a2) {
    int s2, s1, s0, v1;
    s1 = (a1 + 7) & -8;
    v1 = s1 - a1;
    s0 = a2 - v1;
    s2 = a0;
    func_003A52F0(s1, 0, s0);
    v1 = s0 + 0xF;
    if (s0 < 0) {
        s0 = v1;
    }
    *(int *)s2 = s1;
    s0 = s0 >> 4;
    *(int *)(s2 + 4) = s0;
    *(int *)(s2 + 8) = 0;
    *(int *)(s2 + 0xC) = 0;
    *(int *)(s2 + 0x10) = 0;
}

__attribute__((section(".text.func_00368C60")))
int func_00368C60(int a0, int a1) {
    int s0 = a0;
    int s1 = a1;
    if (!MPSLIB_CheckHn(a0, a1)) {
        *(long long *)(s1 + 0x0) = *(long long *)(s0 + 0xA8);
        *(long long *)(s1 + 0x8) = *(long long *)(s0 + 0xB0);
        *(long long *)(s1 + 0x10) = *(long long *)(s0 + 0xB8);
        *(long long *)(s1 + 0x18) = *(long long *)(s0 + 0xC0);
        *(long long *)(s1 + 0x20) = *(long long *)(s0 + 0xC8);
        return 0;
    }
    return MPSLIB_SetErr(0, 0xFF020203);
}

__attribute__((section(".text.func_0032D3A8")))
int func_0032D3A8(int a0, int a1, int a2, int a3) {
    int s1;
    int s0;
    int s3;
    int s2;
    int sp_buf[3];
    int r;

    s1 = a0;
    s0 = a1;
    s3 = a2;
    s2 = a3;

    func_003A52F0(sp_buf, 0, 0xC);
    sp_buf[0] = s1;
    sp_buf[1] = s0;
    sp_buf[2] = 0;
    Obj33F8_Tramp_0033B658_FC70();
    r = func_0032D430(sp_buf, s3, s2);
    Obj33F8_Tramp_0033B670_FC88();
    return r;
}

__attribute__((section(".text.func_00357E58")))
int func_00357E58(int a0) {
    int *s0;
    int t;
    int v0;
    int v1;
    int a1;
    int *obj;
    int *vt;

    s0 = (int*)a0;
    t = *(int*)((char*)s0 + 0x200C);
    v0 = t << 3;
    v0 -= t;
    v0 <<= 2;
    v0 += t;
    v0 <<= 2;
    s0 = (int*)((char*)s0 + v0 + 0x1320);
    obj = *(int**)((char*)s0 + 4);
    vt = *(int**)obj;
    v0 = ((int(*)(int*, int))vt[9])(obj, 1);
    a1 = *(int*)((char*)s0 + 0xC);
    v1 = (a1 * 4 + a1) * 16 / 100;
    if (v0 < v1) {
        return 0;
    }
    return 1;
}

__attribute__((section(".text.func_0035A8E8")))
int func_0035A8E8(void *a0) {
    void *s0;
    int s1;
    int v0;
    int v1;
    int sp0;
    int sp4;
    s0 = a0;
    v0 = GetArrayElemA0C_35A1C8(s0, 6);
    if (!v0) {
        return 0;
    }
    s1 = GetArrayElemA0C_35A1C8(s0, 0x33);
    if (!s1) {
        return 0;
    }
    func_0035A810(s0, (char *)s0 + 0xD30, &sp0, &sp4);
    v0 = sp0;
    v1 = sp4;
    v0 = v0 / v1;
    return s1 < v0;
}

__attribute__((section(".text.func_00351170")))
int func_00351170(void *a0) {
    void *s0;
    int s2;
    int s1;
    int v0;
    int v1;

    s0 = a0;
    s2 = *(int *)((char *)s0 + 0x1FC8);
    s1 = func_0034C7B0(s0, s2);
    v0 = func_0034CAD0(s0, s2);
    v1 = *(int *)((char *)s0 + 0x28);
    s1 -= v0;
    if (s1 < v1) {
        return func_0034DD70(s0, 0xFF000F1C);
    }
    return 0;
}

__attribute__((section(".text.func_003567E0")))
void func_003567E0(void *a0) {
    void *s1;
    void *s0;
    int v0;

    s1 = a0;
    v0 = func_00356358(s1);
    if (v0 == 0) {
        return;
    }
    s0 = *(void **)((char *)s1 + 0x1FC0);
    viBufDelete((void *)((char *)s0 + 0x1198));
    v0 = ReturnK_003EE2BC_00358A38_358A38();
    if (v0 == 1) {
        func_0039AA48();
        func_00356868(s1);
        return;
    }
    func_0039A998((void *)((char *)s0 + 0x1150));
}

__attribute__((section(".text.func_0036BFB0")))
void func_0036BFB0(void)
{
    unsigned char *p;
    int i;
    int fill;

    p = D_003F1AC8;
    i = 0x17F;
    do {
        *p++ = 0;
        i--;
    } while (i >= 0);

    i = 0;
    do {
        *p++ = (unsigned char)i;
        i++;
    } while (i < 0x100);

    fill = -1;
    i = 0x17F;
    do {
        *p++ = (unsigned char)fill;
        i--;
    } while (i >= 0);

    D_003F1ABC = D_003F1C48;
}

__attribute__((section(".text.func_00368D60")))
int func_00368D60(int a0, int a1) {
    int *s0;
    int s1;
    int v0;
    int i;

    v0 = a1;
    s0 = &D_003F1A98;
    s1 = a0;
    *s0 = v0;
    func_00366C50(v0, 0, (s1 << 6) + 4);
    func_00368E68(*s0);
    v0 = *s0;
    *(int *)(v0 + 0xC) = s1;
    v0 = v0 + 0x10;
    if (s1 > 0) {
        i = s1;
        do {
            *(int *)v0 = 1;
            i--;
            v0 = v0 + 0x100;
        } while (i != 0);
    }
    return 0;
}

typedef int (*vtfn)(void *);
typedef void (*vtfnv)(void *);

typedef struct Obj_s {
    vtfn *vtable;
} Obj;






__attribute__((section(".text.func_0034CBB0")))
void func_0034CBB0(void) {
    char buf[8];
    Obj *s0;

    s0 = func_003395A0(buf, 8, 0);
    D_00760DB0 = s0->vtable[4](s0);
    ((vtfnv)s0->vtable[3])(s0);
    s0 = func_00338B90(buf, 8);
    D_00760DB4 = s0->vtable[4](s0);
    ((vtfnv)s0->vtable[3])(s0);
}

__attribute__((section(".text.func_0036DBE0")))
void func_0036DBE0(void *a0, int *a1, int *a2, int *a3)
{
    char *s0 = (char *)a0 + 0x160;
    int r;
    r = Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(a0);
    if (r == 0) {
        *a1 = *(int *)(s0 + 0x2D8) << 11;
        *a2 = *(int *)(s0 + 0xE4);
        *a3 = -1;
        return;
    }
    M2VERR_SetCode(0, 0xFF03020F);
}

struct block32_00368BC8 { long long a, b, c, d; } __attribute__((packed));

__attribute__((section(".text.func_00368BC8")))
int func_00368BC8(int a0, int a1) {
    if (MPSLIB_CheckHn((void *)a0)) {
        return MPSLIB_SetErr(0, 0xFF020202u);
    }
    *(struct block32_00368BC8 *)a1 = *(struct block32_00368BC8 *)((char *)a0 + 0x28);
    return 0;
}

__attribute__((section(".text.func_00369078")))
void *func_00369078(void *a0) {
    void *s0;
    int s1;
    s0 = a0;
    s1 = 2;
    func_00366C50(a0, 0, 0x40);
    *(int *)((char *)s0 + 0x00) = s1;
    func_00368E80((char *)s0 + 4);
    *(int *)((char *)s0 + 0x10) = s1;
    func_00369118((char *)s0 + 0x18);
    func_00369130((char *)s0 + 0x28);
    func_00369130((char *)s0 + 0x48);
    func_00369130((char *)s0 + 0x68);
    func_00369130((char *)s0 + 0x88);
    func_00369158((char *)s0 + 0xA8);
    *(int *)((char *)s0 + 0xD0) = 0;
    *(int *)((char *)s0 + 0xD4) = (int)func_00366EC0;
    *(int *)((char *)s0 + 0xD8) = 0;
    *(int *)((char *)s0 + 0xDC) = 0;
    *(int *)((char *)s0 + 0xE0) = 0;
    *(int *)((char *)s0 + 0xE4) = 0;
    *(int *)((char *)s0 + 0xE8) = 0;
    return s0;
}

__attribute__((section(".text.func_0034AA20")))
void func_0034AA20(char *a0) {
    int local;
    int buf1;
    int buf2;
    int *base;
    int s1;

    base = (int *)((int)a0 + 0x1FFC);
    s1 = base[2];
    func_0034C890(a0, base[4], &local);

    if (!local) return;

    func_0034CAF8(local, &buf1, &buf2);

    *(long long *)((char *)a0 + 0x9B8) = func_0034CCB0(*(long long *)((char *)a0 + 0x9B8), buf1);
    *(long long *)((char *)a0 + 0x9C0) = func_0034CCB0(*(long long *)((char *)a0 + 0x9C0), buf2);

    func_0034CAF8(*(int *)((int)s1 + 4), &buf1, &buf2);

    *(long long *)((char *)a0 + 0x9D0) = func_0034CCB0(*(long long *)((char *)a0 + 0x9D0), buf1);
    *(long long *)((char *)a0 + 0x9D8) = func_0034CCB0(*(long long *)((char *)a0 + 0x9D8), buf2);
}

__attribute__((section(".text.func_00366E18")))
void func_00366E18(int *a0, int a1, int *a2, int *a3, int *a4) {
    void (*fn)(int *, int);
    *a3 = 0;
    *a4 = 0;
    if (MPSLIB_CheckHn(a0)) {
        MPSLIB_SetErr(0, 0xFF020301, (int)a2, a3, a4);
        return;
    }
    fn = (void (*)(int *, int))(*(int *)((char *)a0 + 0xD4));
    fn(a0, a1);
}

__attribute__((section(".text.func_0034FA28")))
void func_0034FA28(char *a0, int *out0, int *out4)
{
    int lbuf[8];
    int *s3;
    char *s4;
    int s0;
    int s1;
    int s2;

    s0 = 0;
    s1 = 0;
    s2 = 0;
    s3 = *(int **)((char *)a0 + 0x1F7C);
    s4 = (char *)s3[0];
    do {
        func_00368B18(s4, (char *)lbuf, s0);
        s0++;
        if (lbuf[2] >= s1) s1 = lbuf[2];
        if (lbuf[3] >= s2) s2 = lbuf[3];
    } while (s0 < 3);
    s3[1] = s2;
    s3[2] = s1;
    *out0 = s1;
    *out4 = s3[1];
}

__attribute__((section(".text.func_0034A038")))
void func_0034A038(void *a0, int a1, int a2, int *a3)
{
    int local[2];
    int *s1;
    int s3;
    int s0;

    s1 = *(int **)((char *)a0 + 0x2004);
    s3 = *(int *)((char *)s1 + 4);
    func_00349F80((void *)s3, *(int *)((char *)s1 + 8), local);
    s0 = local[1];
    if (a2 < s0) s0 = a2;
    if (0x19000 < s0) s0 = 0x19000;
    func_00366960(local[0], a1, s0);
    func_00349FB0((void *)s3, s0, local);
    *(int *)((char *)s1 + 0x48) += s0;
    *a3 = s0;
}
