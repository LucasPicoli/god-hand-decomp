/* cygnus-2.96 matched TU. */

extern int MPV_GoNextDelimSj();
extern int D_00455A30;
extern int D_00455920;
extern int D_00455A40;
extern int D_00455950;
extern int GetArrayElemA0C_35A1C8(void *, int);
extern void func_0034CDF8(void *, int);
extern void func_0035A4D0(void *, int);
extern int func_0036C448;
extern int D_00766CE8;
extern void Thunk_func_0033B658(void *);
extern void Thunk_func_0033B670(void *);
extern void func_0034C250(int a0, int a1, int a2, void *a3);
extern int sfmps_CopySj(int a0, int a1, int a2);

__attribute__((section(".text.func_0036BCD0")))
int func_0036BCD0(int a0, int a1, int a2) {
    int *p = (int *)(a0 + 0x250);
    int n = *(int *)(a0 + 0x194);
    int s1;
    if (*(int *)(a0 + 0x384) != 0) {
        *(int *)(a0 + 0x384) = 0;
        *(int *)(a0 + 0x388) += 1;
        p[3] += 1;
        if (n == 0) {
            return -2;
        }
        p[4] += 1;
    }
    s1 = (n == 0) ? -2 : -3;
    for (;;) {
        int r = MPV_GoNextDelimSj(a2);
        if (r == 0) break;
        if ((r & a1) != 0) { s1 = 0; break; }
        if (func_0036BDA0(a2, 1, 4) != 4) break;
    }
    return s1;
}

__attribute__((section(".text.func_00339360")))
int func_00339360(int a0, int a1, int a2, int *a3) {
    int s0;
    if (a0 == 0) {
        func_00338A48(&D_00455A30, &D_00455920);
        return 0;
    }
    if (*(int *)(a0 + 4) == 0) {
        func_00338A48(&D_00455A40, &D_00455950);
        return 0;
    }
    if (a1 == 0) {
        s0 = 0;
    } else if (a1 == 1) {
        int c = *(int *)(a0 + 0xC);
        s0 = (c < a2) ? c : a2;
    } else {
        int (*fp)() = *(int (**)())(a0 + 0x1C);
        s0 = 0;
        if (fp != 0) {
            fp(*(int *)(a0 + 0x20), -3);
        }
    }
    *a3 = s0;
    return (s0 == a2) ? 1 : 0;
}

__attribute__((section(".text.func_003518D8")))
int func_003518D8(void *a0) {
    void *s0 = a0;
    char *s1 = (char *)s0 + 0xD30;
    int *s2 = *(int **)((char *)s0 + 0x1FC0);
    int a1;
    if (GetArrayElemA0C_35A1C8(s0, 6) == 0) {
        a1 = func_003519A8(s0);
    } else {
        a1 = func_00351A08(s0);
        if (a1 < 0) return -1;
    }
    if (a1 > 0) {
        func_0034CDF8(s0, a1);
        *(int *)((char *)s2 + 0x88) = *(int *)((char *)s2 + 0x88) + 1;
        if (func_00356358(s0) != 0) {
            *(int *)(s1 + 0x160) = func_00356C58(s0) + 1;
        }
    }
    func_0035A4D0(s1 + 0x3C, 0x7FFFFFFF);
    func_0035A4D0(s1 + 0x68, -1);
    *(int *)((char *)s2 + 0x78) = 0xC0;
    return 0;
}

void func_0036C518(int, int);
int Obj0000_Set_D_00766D44_Check_Field_188_NE_2(int);
int func_00369F20(int, int);
int Obj0000_Get_Field_3B4_Via_func_0036CD98(int, int, int);

__attribute__((section(".text.func_0036C450")))
int func_0036C450(int a0, int a1, int a2) {
    int *base;
    if (a1 == 8 && a2 == 0)
        a2 = (int)&func_0036C448;
    if (a0 == 0) {
        func_0036C518(a1, a2);
        base = &D_00766CE8;
    } else {
        if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(a0))
            return func_00369F20(0, 0xFF030202);
        base = (int *)(a0 + 0x190);
    }
    base[a1] = a2;
    Obj0000_Get_Field_3B4_Via_func_0036CD98(a0, a1, a2);
    return 0;
}

typedef struct {
    char _0;
    signed char state;   /* 0x1 */
    char _2;
    signed char b3;      /* 0x3 */
    int w4;              /* 0x4 */
    int _8, _c, _10;
    int w14;             /* 0x14 */
    int _18, _1c;
    int w20;             /* 0x20 */
} S;

int func_00328098(int);
int func_00328140(int);
void func_00323A00(void *);

__attribute__((section(".text.func_00324108")))
void func_00324108(S *s) {
    signed char b3;
    if (s->state == 2) {
        int r, d;
        s->state = func_00328098(s->w4);
        r = func_00328140(s->w4);
        d = r - s->w14;
        s->w20 = d;
        if ((unsigned)((unsigned char)s->state - 3) < 2u) {
            s->w14 += d;
            func_00323A00(s);
        }
    }
    b3 = s->b3;
    if (b3 == 1) {
        int t = func_00328098(s->w4);
        if (t == b3) {
            int r = func_00328140(s->w4);
            s->w20 = r - s->w14;
            func_00323A00(s);
            s->state = t;
            s->b3 = 0;
        }
    }
}

__attribute__((section(".text.func_0034CF38")))
int func_0034CF38(int base, int *out1, int *out2)
{
    int local[4];
    int *s0 = (int *)(base + 0xD30);
    int s4;

    Thunk_func_0033B658(local);
    if (s0[0x7D] - s0[0x7E] <= 0) {
        *out1 = -1;
        s4 = 0;
    } else {
        *out2 = s0[0x7B];
        *out1 = ((int *)base)[0x3CB + (s0[0x7E] % 32)];
        s0[0x7E] = s0[0x7E] + 1;
        s4 = 1;
    }
    Thunk_func_0033B670(local);
    return s4;
}

__attribute__((section(".text.func_0034F008")))
int func_0034F008(int a0, int a1, int a2, int a3) {
    int local[4];
    int v1 = *(int *)(a0 + 0x1F90);
    int x0, r, s4;
    int (*cb1)(int, int);
    int (*cb2)(int, int);
    if (v1 == 8) return 1;
    func_0034C250(a0, v1, a1, local);
    x0 = local[0];
    cb1 = (int (*)(int, int))local[1];
    cb2 = (int (*)(int, int))local[2];
    s4 = local[3];
    if (x0 == 0) return 1;
    r = sfmps_CopySj(x0, a2, a3);
    if (r == 1) {
        if (cb1) cb1(a0, a1);
        if (cb2) cb2(s4, a1);
    }
    return r;
}
