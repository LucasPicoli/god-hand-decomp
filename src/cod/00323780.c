/* cygnus-2.96 matched TU. */

extern int MPV_SearchDelim(int, int, int);
extern int MPV_CheckDelim(int);
extern struct S2 { int a; int b; } D_00457B10;
extern int D_00457BD8;
extern int D_00457BE0;
extern int func_00345848;
extern void MWSFSVM_Error();
extern int Cmp_a1_Eq_0x37B0(int *, int);
extern int D_003DA5F0;
extern char D_003DA5F8;
extern char D_00459300[];
extern int D_003EE0A0;
extern void func_00351B70(void *a0, int a1);
extern void func_00323AA0(int a0);
extern void sfbuf_SetSupSj(void *a0, void *a1, void *a2, int a3);
extern void func_0034BFA8(void *a0, int a1, int a2);
extern int GetArrayElemA0C_35A1C8();
extern int SFHDS_ProcessHdr();
extern int Obj34D8_CopyVec3_From98_To934();
extern int MPS_SetErrFn();
extern void func_0034FE78();

__attribute__((section(".text.func_0034A748")))
int func_0034A748(int a0)
{
    int *v0;
    int s0, s2;
    int r;

    v0 = (int *)((char *)a0 + 0x1FFC);
    s2 = *(int *)((char *)v0 + 0x14);
    s0 = *(int *)((char *)v0 + 0x10);

    r = func_0034CA30(a0, s2);
    if (r == 1)
        return r;

    r = func_0034CA30(a0, s0);
    if (r != 1)
        return r;

    r = func_0034A7F0(a0);
    if (r == 0)
        return r;

    return func_0034CA00(a0, s2, 1);
}

__attribute__((section(".text.func_0036A708")))
int func_0036A708(int a0, int a1)
{
    int s0, s1;
    int v1, v0;

    s0 = a1;
    s1 = a0;

    v1 = *(int *)(s1 + 0x35C);
    if (v1 != 0)
        return v1;

    v1 = MPV_SearchDelim(*(int *)(s0 + 0), *(int *)(s0 + 4), 0x40);
    if (v1 == 0)
        return *(int *)(s1 + 0x35C);

    v1 += 4;
    v1 = MPV_SearchDelim(v1, *(int *)(s0 + 4) - (v1 - *(int *)(s0 + 0)), -1);
    if (v1 == 0)
        return *(int *)(s1 + 0x35C);

    v1 = MPV_CheckDelim(v1);
    v0 = v1 & 0x10;
    if (v0 != 0)
        *(int *)(s1 + 0x35C) = 2;
    else if (v1 != 0)
        *(int *)(s1 + 0x35C) = 1;
    return *(int *)(s1 + 0x35C);
}

__attribute__((section(".text.func_00345780")))
int func_00345780(int a0)
{
    struct S2 sp;

    sp = D_00457B10;
    sp.b = a0;

    if (Cmp_a1_Eq_0x37B0(&D_00457BD8, 0x37B0) != 1) {
        MWSFSVM_Error(&D_00457BE0);
        return -1;
    }

    if (func_0034DB60(&sp) != 0) {
        func_00345750(-0x12D);
    } else {
        if (func_0034DE20(0, &func_00345848, 0) != 0)
            func_00345750(-0x12F);
    }
}

void func_00335500(void *);
void func_003A52F0(void *, int, int);
void func_00335DD8(void);
void func_00335D18(int, int);

__attribute__((section(".text.func_00335E60")))
void func_00335E60(void)
{
    int cmp;
    int i;
    char *p;

    if (--D_003DA5F0 != 0) {
        return;
    }

    cmp = 1;
    p = &D_003DA5F8;
    for (i = 0x1F; i >= 0; p += 0x238, i--) {
        if (*p == cmp) {
            func_00335500(p);
        }
    }

    func_003A52F0(&D_003DA5F8, 0, 0x4700);
    func_00335DD8();
    func_00335D18(0, 0);
}

int Forward328098_349B88(int);
void func_00349AD0(int, int, int, int, int);
int Forward3281C8_349B48(int);
int func_00345750();
void MWSFSVM_Error();
void func_00342FF8(void *);

__attribute__((section(".text.func_00348FF0")))
int func_00348FF0(void *a0)
{
    void *s0;
    int r;

    s0 = a0;
    r = Forward328098_349B88(*(int *)((char *)s0 + 0x40));

    if (r == 2) {
        return -1;
    }

    {
        void *obj = *(void **)((char *)s0 + 0x1BC);
        if (obj != 0) {
            int *vtbl = *(int **)obj;
            void (*fn)(void *) = (void (*)(void *))vtbl[5];
            fn(obj);
        }
    }

    func_00349AD0(
        *(int *)((char *)s0 + 0x40),
        *(int *)((char *)s0 + 0x1A4),
        *(int *)((char *)s0 + 0x1B0),
        *(int *)((char *)s0 + 0x1B4),
        *(int *)((char *)s0 + 0x1B8));

    r = Forward3281C8_349B48(*(int *)((char *)s0 + 0x40));

    if (r == -1) {
        *(int *)((char *)s0 + 4) = 4;
        func_00345750(-0x66);
        MWSFSVM_Error(D_00459300, *(int *)((char *)s0 + 0x1A4));
        *(int *)((char *)s0 + 0x1AC) = 0;
        return -1;
    }

    func_00342FF8(s0);
    return 1;
}

void func_00349718(void *, int);
void func_00349728(void *, int);
void func_003572F8(int);
void func_00349158(void *);
int Obj0000_Get_Field_44_LT_1_If_Field_48_In_1_4(int);

__attribute__((section(".text.func_00349630")))
int func_00349630(void *a0)
{
    void *s0;
    int s1;
    int s2;

    s0 = a0;
    s2 = *(int *)((char *)s0 + 0x3C);
    func_00349718(s0, 1);
    s1 = *(int *)s0;

    if (s1 != 1) {
        func_00349718(s0, 0);
        return 0;
    }

    D_003EE0A0 = (int)s0;
    func_00349728(s0, 1);
    func_003572F8(s2);
    func_00349728(s0, 0);

    if (*(int *)((char *)s0 + 4) == 0) {
        *(int *)((char *)s0 + 0x68) = 0;
    } else {
        *(int *)((char *)s0 + 0x68) = s1;
        func_00349158(s0);
    }

    func_00349718(s0, 0);
    return (unsigned int)(Obj0000_Get_Field_44_LT_1_If_Field_48_In_1_4(s2) ^ 1) > 0;
}

__attribute__((section(".text.sfmpv_DiscardSec")))
int sfmpv_DiscardSec(void *a0, void *a1) {
    int buf[4];
    void *s0;
    void *s1;
    int s2;
    int s3;

    s0 = a1;
    s1 = a0;
    s2 = 4;
    s3 = 0x80;

    while (1) {
        void (*fn6)(void *, int, int, int *) =
            *(void (**)(void *, int, int, int *))((char *)*(void **)s0 + 0x18);
        fn6(s0, 1, 4, buf);

        if (buf[1] != s2) break;
        if (MPV_CheckDelim(buf[0]) != s3) break;

        {
            void (*fn8)(void *, int, int *) =
                *(void (**)(void *, int, int *))((char *)*(void **)s0 + 0x20);
            fn8(s0, 0, buf);
        }
        func_00351B70(s1, 4);
    }

    {
        int (*fn7)(void *, int, int *) =
            *(int (**)(void *, int, int *))((char *)*(void **)s0 + 0x1C);
        return fn7(s0, 1, buf);
    }
}

__attribute__((section(".text.func_00323780")))
int func_00323780(int a0, int a1, int a2, int a3) {
    int s4, s3, s1, s0, s2;

    s4 = a0;
    s3 = a1;
    s1 = a2;
    s0 = a3;

    func_003228C0(1, 0, s4, s3, -1);
    s2 = func_003234D0();

    if (s2 != 0) {
        int r = func_00323700(s2, s4, s3, s1, s0);
        if (r < 0) {
            func_00323AA0(s2);
            s2 = 0;
        }
    }

    func_003228C0(1, 1, s4, s3, -1);
    return s2;
}

__attribute__((section(".text.func_0034BC00")))
int func_0034BC00(char *a0, int *a1, int *a2, int a3, void *t0) {
    int buf[8];
    char *s0;
    char *s1;
    int s2;
    int s3;
    int v1;

    s0 = a0 + a3 * 116;
    a2 = a2 + a3;
    a1 = a1 + a3;

    v1 = *a2;
    s1 = s0 + 16;

    if (v1 == 0) {
        s3 = 0;
        s2 = 4;
    } else {
        int r;
        s3 = 1;
        r = func_0034BCC0(buf, *a1, v1, t0);
        s2 = 5;
        if (r != 0) return r;
        sfbuf_SetSupSj(s1, buf, s0, 1);
    }

    func_0034BFA8(s0, s2, s3);
    return 0;
}

__attribute__((section(".text.func_0034D210")))
int func_0034D210(int a0, int a1, int a2) {
    int (*fn)();
    int elem;
    int sz;
    int *p;

    fn = (int (*)())GetArrayElemA0C_35A1C8(a0, 0x4B);
    elem = GetArrayElemA0C_35A1C8(a0, 0x4C);
    if (fn) {
        fn(elem, a1, a2);
    }
    p = (int *)(a0 + 0x78);
    if (*p != 0) {
        return 0;
    }
    sz = 0x800;
    if (a2 < 0x801) sz = a2;
    func_00366960(a0 + 0x10C, a1, sz);
    *(int *)((char *)p + 0x90) = sz;
    SFHDS_ProcessHdr(p);
    Obj34D8_CopyVec3_From98_To934(a0);
    func_0034D2D8(a0);
    return 1;
}

__attribute__((section(".text.func_0034FD28")))
int func_0034FD28(int a0) {
    void *s1;
    int *s2;

    s2 = (int *)(a0 + 0x2198);
    *(int *)(a0 + 0x1F7C) = (int)s2;
    func_0034FDF0(s2);

    s1 = func_00368FE8();
    if (!s1) {
        return func_0034DD70(0, 0xFF000D08, a0);
    }
    if (MPS_SetErrFn(s1, func_0034FE78)) {
        Tramp_MPS_Destroy_34FEE0(s1);
        return func_0034DD70(0, 0xFF000D09);
    }
    *s2 = (int)s1;
    return 0;
}
