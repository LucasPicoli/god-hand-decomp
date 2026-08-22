/* sn-2.95.3-136 matched TU. */

extern void func_001C6C30(void *a0, void *a1);
extern float DoubleFloatMinusHalf_31D020(void);
extern void cModel_calcParts(void *a0);
extern void func_001C6A90(void *a0, int a1, void *a2, void *a3, int t0);

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.cObjSimple_SetParentInfo")))
void cObjSimple_SetParentInfo(char *a, unsigned char *obj, int idx, float *v1,
                              float *v2)
{
    char hold[16];
    float *d;

    if (obj == 0) {
        return;
    }
    if (idx != -1) {
        char *e;
        int ok;
        int cnt;

        ok = 0;
        cnt = *((unsigned char *) (obj + 0x2B4));
        *((int *) hold) = cnt;
        if (idx >= 0) {
            ok = idx < cnt;
            cnt = 0;
        }
        if (ok & 0xFF) {
            e = *((char **) (*((char **) (obj + 0x278)) + idx * 4));
        } else {
            e = 0;
        }
        if (e == 0) {
            return;
        }
    }
    *((char **) (a + 0x30B0)) = (char *) obj;
    *((int *) (a + 0x30B4)) = idx;
    d = (float *) (a + 0x30C0);
    if (d != v1) {
        d[0] = v1[0];
        d[1] = v1[1];
        d[2] = v1[2];
    }
    d = (float *) (a + 0x30D0);
    if (d != v2) {
        d[0] = v2[0];
        d[1] = v2[1];
        d[2] = v2[2];
    }
    a[0x4E0] = 1;
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.cOmSub_initMove3_y")))
void cOmSub_initMove3_y(char *a, unsigned char *obj, int idx, void *v)
{
    char hold[16];
    char *e;

    if (obj != 0) {
        if (idx >= 0) {
            char *e2;
            int cnt;

            cnt = *((unsigned char *) (obj + 0x2B4));
            *((int *) hold) = cnt;
            if (idx < cnt) {
                e2 = *((char **) (*((char **) (obj + 0x278)) + idx * 4));
            } else {
                e2 = 0;
            }
            e = e2;
        } else {
            e = (char *) obj;
        }
        if (e != 0) {
            float *d;
            float *s;

            *((char **) (a + 0x4)) = (char *) obj;
            *((char **) (a + 0x8)) = e;
            if (idx >= 0) {
                *((char **) (a + 0x40)) = *((char **) (e + 0xD0));
            } else {
                *((char **) (a + 0x40)) = *((char **) (e + 0xF0));
            }
            d = (float *) (a + 0x70);
            s = *((float **) (a + 0x40));
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            d = (float *) (a + 0x80);
            s = (float *) (e + 0x100);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
        }
    }
    func_001C6C30(a, v);
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.cOmThrow_SetThrow")))
void cOmThrow_SetThrow(unsigned char *p, float *v)
{
    char hold[16];
    char *e;
    int cnt;
    float *d;
    float *s;

    p[0x2F4] = 0;
    p[0x2F5] = 1;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
    d = (float *) (p + 0x610);
    s = v;
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
    *((int *) (p + 0x644)) = 0;
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e = *((char **) *((char **) (p + 0x278)));
    } else {
        e = 0;
    }
    if (e != 0) {
        float *dd;
        float *ss;

        dd = *((float **) (e + 0xD0));
        ss = (float *) (p + 0x630);
        if (dd != ss) {
            dd[0] = ss[0];
            dd[1] = ss[1];
            dd[2] = ss[2];
        }
        *((int *) (e + 0x100)) = 0;
        *((int *) (e + 0x104)) = 0;
        *((float *) (e + 0x108)) =
            DoubleFloatMinusHalf_31D020() * 0.5235987901687622f + 0.5235987901687622f;
        p[0x640] = 0;
    }
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.cOmWeapon_setThrow")))
void cOmWeapon_setThrow(unsigned char *p, float *v, int n)
{
    char hold[16];
    char *obj;
    char *e;
    int cnt;

    obj = *((char **) (p + 0x600));
    if (obj != 0) {
        float *d;
        float *s;

        d = (float *) (p + 0x490);
        s = *((float **) (obj + 0xF0));
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
    }
    *((float *) (p + 0x24C)) = 1.0f;
    *((unsigned int *) (p + 0x250)) = *((unsigned int *) (p + 0x250)) & 0xFFFFFFEF;
    *((int *) (p + 0x600)) = 0;
    *((int *) (p + 0x630)) = 0;
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e = *((char **) *((char **) (p + 0x278)));
    } else {
        e = 0;
    }
    if (e != 0) {
        float *d;
        float *s;

        *((int *) (e + 0x148)) = (int) p;
        *((int *) (e + 0x100)) = 0;
        *((int *) (e + 0x104)) = 0;
        *((int *) (e + 0x108)) = 0;
        cModel_calcParts(p);
        d = (float *) (p + 0x640);
        s = v;
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
        *((int *) (p + 0x670)) = n;
        p[0x2F4] = 0;
        p[0x2F5] = 3;
        p[0x2F6] = 0;
        p[0x2F7] = 0;
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.cOmWeapon_setThrowPL")))
void cOmWeapon_setThrowPL(unsigned char *p, float *v)
{
    char hold[16];
    char *obj;
    char *e;
    int cnt;

    obj = *((char **) (p + 0x600));
    if (obj != 0) {
        float *d;
        float *s;

        d = (float *) (p + 0x490);
        s = *((float **) (obj + 0xF0));
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
    }
    *((float *) (p + 0x24C)) = 1.0f;
    *((unsigned int *) (p + 0x250)) = *((unsigned int *) (p + 0x250)) & 0xFFFFFFEF;
    *((int *) (p + 0x600)) = 0;
    *((int *) (p + 0x630)) = 0;
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e = *((char **) *((char **) (p + 0x278)));
    } else {
        e = 0;
    }
    if (e != 0) {
        float *d;
        float *s;

        *((int *) (e + 0x148)) = (int) p;
        *((int *) (e + 0x100)) = 0;
        *((int *) (e + 0x104)) = 0;
        *((float *) (e + 0x108)) =
            DoubleFloatMinusHalf_31D020() * 0.5235987901687622f + 0.5235987901687622f;
        cModel_calcParts(p);
        d = (float *) (p + 0x640);
        s = v;
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
        p[0x2F4] = 0;
        p[0x2F5] = 5;
        p[0x2F6] = 0;
        p[0x2F7] = 0;
    }
}

static inline int GetLayerObj(char *a0, int *frame, int idx)
{
    int b;

    *frame = b = *(unsigned char *)(a0 + 0x2B4);
    if (idx >= 0 && idx < b) {
        return *(int *)(*(int *)(a0 + 0x278) + idx * 4);
    }
    return 0;
}

__attribute__((section(".text.func_001CFB28")))
void func_001CFB28(char *p, float *pos, int a2)
{
    unsigned char frame[0x10];
    char *m;
    float *d;
    char *e;

    m = *(char **)(p + 0x600);
    if (m != 0) {
        m = *(char **)(m + 0xF0);
        d = (float *)(p + 0x490);
        if (d != (float *)m) { d[0] = ((float *)m)[0]; d[1] = ((float *)m)[1]; d[2] = ((float *)m)[2]; }
    }
    *(float *)(p + 0x24C) = 1.0f;
    *(int *)(p + 0x250) = *(int *)(p + 0x250) & 0xFFFFFFEF;
    *(int *)(p + 0x600) = 0;
    *(int *)(p + 0x630) = 0;
    e = (char *)GetLayerObj(p, (int *)frame, 0);
    if (e != 0) {
        *(int *)(e + 0x148) = (int)p;
        *(int *)(e + 0x100) = 0;
        *(int *)(e + 0x104) = 0;
        *(int *)(e + 0x108) = 0;
        *(int *)(*(int *)(e + 0xD0) + 0x0) = 0;
        *(int *)(*(int *)(e + 0xD0) + 0x4) = 0;
        *(int *)(*(int *)(e + 0xD0) + 0x8) = 0;
        cModel_calcParts(p);
        {
            float *d2 = (float *)(p + 0x640);
            if (d2 != pos) { d2[0] = pos[0]; d2[1] = pos[1]; d2[2] = pos[2]; }
        }
        *(int *)(p + 0x670) = a2;
        *(unsigned char *)(p + 0x2F5) = 4;
        *(unsigned char *)(p + 0x2F4) = 0;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
    }
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001C6968")))
void func_001C6968(char *a, int n, void *v)
{
    func_001C6A90(a, n, v, a + 0x80, 1);
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001C6A60")))
void func_001C6A60(char *a, int n, void *v, int fl)
{
    func_001C6A90(a, n, a + 0x70, v, fl | 2);
}
