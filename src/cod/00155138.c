/* sn-2.95.3-136 matched TU. */

extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);

__attribute__((section(".text.cOl22_setOpenFix")))
void cOl22_setOpenFix(unsigned char *p)
{
    char hold[16];
    char *e1;
    int cnt;

    if (p[0x601] != 0) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e1 = *((char **) *((char **) (p + 0x278)));
    } else {
        e1 = 0;
    }
    if (e1 != 0) {
        char *e2;
        int c2;
        int *q;

        c2 = *((unsigned char *) (p + 0x2B4));
        *((int *) hold) = c2;
        if (c2 != 0) {
            e2 = *((char **) *((char **) (p + 0x278)));
        } else {
            e2 = 0;
        }
        q = (int *) (e2 + 0x100); *((float *) (e2 + 0x100)) = -1.5707964f; q[1] = 0; q[2] = 0;
    }
    p[0x601] = 1;
    p[0x600] = 0;
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
}

__attribute__((section(".text.cOl22_setCloseFix")))
void cOl22_setCloseFix(unsigned char *p)
{
    char hold[16];
    char *e1;
    int st;
    int cnt;

    st = p[0x601];
    if (st != 1) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (st < cnt) {
        e1 = (char *) *((int *) (*((int *) (p + 0x278)) + 4));
    } else {
        e1 = 0;
    }
    if (e1 != 0) {
        char *e2;
        int c2;
        int *q;
        int i2;

        c2 = *((unsigned char *) (p + 0x2B4));
        *((int *) hold) = c2;
        i2 = 1;
        if (i2 < c2) {
            e2 = (char *) *((int *) (*((int *) (p + 0x278)) + 4));
        } else {
            e2 = 0;
        }
        q = (int *) (e2 + 0x100);
        *((float *) (e2 + 0x100)) = 1.5707964f;
        q[1] = 0;
        q[2] = 0;
    }
    p[0x601] = 0;
    p[0x600] = 0;
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
}

__attribute__((section(".text.cOm4f_setOpenFix")))
void cOm4f_setOpenFix(unsigned char *p)
{
    char hold[16];
    char *e1;
    int cnt;

    if (p[0x761] != 0) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e1 = *((char **) *((char **) (p + 0x278)));
    } else {
        e1 = 0;
    }
    if (e1 != 0) {
        char *e2;
        int c2;
        int *q;

        c2 = *((unsigned char *) (p + 0x2B4));
        *((int *) hold) = c2;
        if (c2 != 0) {
            e2 = *((char **) *((char **) (p + 0x278)));
        } else {
            e2 = 0;
        }
        q = (int *) (e2 + 0x100);
        *((float *) (e2 + 0x100)) = *((float *) (p + 0x794));
        q[1] = 0;
        q[2] = 0;
    }
    p[0x761] = 1;
    p[0x760] = 0;
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
}

__attribute__((section(".text.cOm4f_setCloseFix")))
void cOm4f_setCloseFix(unsigned char *p)
{
    char hold[16];
    char *e1;
    int cnt;

    if (p[0x761] != 1) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e1 = *((char **) *((char **) (p + 0x278)));
    } else {
        e1 = 0;
    }
    if (e1 != 0) {
        char *e2;
        int c2;
        int *q;

        c2 = *((unsigned char *) (p + 0x2B4));
        *((int *) hold) = c2;
        if (c2 != 0) {
            e2 = *((char **) *((char **) (p + 0x278)));
        } else {
            e2 = 0;
        }
        q = (int *) (e2 + 0x100);
        *((float *) (e2 + 0x100)) = *((float *) (p + 0x798));
        q[1] = 0;
        q[2] = 0;
    }
    p[0x761] = 0;
    p[0x760] = 0;
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
}

__attribute__((section(".text.func_00155138")))
int func_00155138(char *p)
{
    char hold[16];
    char *o;
    unsigned short h;
    int n;
    int i;
    int acc;

    o = *((char **) (p + 0x388));
    *((int *) hold) = (int) o;
    h = *((unsigned short *) (o + 0xA));
    n = h & 0xFF;
    p[0x385] = (char) h;
    if (n >= 0x11) {
        return 0;
    }
    i = 0;
    acc = 0;
    do {
        acc += func_001551C0(p, i) << 1;
        i++;
    } while (--n != 0);
    return acc;
}

__attribute__((section(".text.func_00155248")))
int func_00155248(char *p)
{
    char hold[16];
    char *o;
    unsigned short h;
    int n;
    int i;
    int acc;

    o = *((char **) (p + 0x388));
    *((int *) hold) = (int) o;
    h = *((unsigned short *) (o + 0xA));
    n = h & 0xFF;
    p[0x385] = (char) h;
    if (n >= 0x11) {
        return 0;
    }
    i = 0;
    acc = 0;
    do {
        acc += func_001552D0(p, i) << 1;
        i++;
    } while (--n != 0);
    return acc;
}

__attribute__((section(".text.func_001B3548")))
void func_001B3548(unsigned char *p)
{
    char hold[16];
    char *e;
    int cnt;
    int i2;
    float pi;
    float v;

    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    i2 = 2;
    if (i2 < cnt) {
        e = (char *) *((int *) (*((int *) (p + 0x278)) + 8));
    } else {
        e = 0;
    }
    pi = 3.1415927410125732f;
    v = (*((float *) (e + 0x100)) - pi) * 0.8999999761581421f + pi;
    *((float *) (e + 0x100)) = v;
    if (3.054326057434082f <= v) {
        *((float *) (e + 0x100)) = pi;
        p[0x2F5] = 2;
    }
}

__attribute__((section(".text.func_001B1938")))
void func_001B1938(unsigned char *p)
{
    char hold[16];
    char *e;
    int cnt;
    int i1;
    float x;
    float one;

    if (*((unsigned short *) (p + 0x2FE)) != 0x364) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    i1 = 1;
    if (i1 < cnt) {
        e = (char *) *((int *) (*((int *) (p + 0x278)) + 4));
    } else {
        e = 0;
    }
    if (e != 0) {
        x = *((float *) (p + 0x630)) * 0.006666666828095913f;
        one = 1.0f;
        if (one < x) {
            x = one;
        }
        if (x < 0.0f) {
            x = 0.0f;
        }
        *((float *) (e + 0x108)) = (one - x) * 1.5707963705062866f;
    }
}

__attribute__((section(".text.func_001C2378")))
void func_001C2378(char *p)
{
    char hold[16];
    char *obj;
    char *e;
    int cnt;
    int idx;
    int ok;
    float *d;
    float *s;

    obj = *((char **) (p + 0x630));
    ok = 0;
    if (obj != 0) {
        cnt = *((unsigned char *) (obj + 0x2B4));
        idx = *((int *) (p + 0x634));
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
        d = (float *) *((char **) (p + 0xF0));
        s = (float *) (p + 0x640);
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
        sceVu0ApplyMatrix(*((char **) (p + 0xF0)), e + 0x80,
                          *((char **) (p + 0xF0)));
    }
}

__attribute__((section(".text.cOmThrow_SetFall")))
void cOmThrow_SetFall(unsigned char *p)
{
    char hold[16];
    char *e;
    int cnt;

    p[0x2F4] = 0;
    p[0x2F5] = 2;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
    *((int *) (p + 0x610)) = 0;
    *((float *) (p + 0x614)) = 0.06499999761581421f;
    *((int *) (p + 0x618)) = 0;
    *((int *) (p + 0x644)) = 0;
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

        d = *((float **) (e + 0xD0));
        s = (float *) (p + 0x630);
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
        *((int *) (e + 0x100)) = 0;
        *((int *) (e + 0x104)) = 0;
        *((int *) (e + 0x108)) = 0;
    }
}

__attribute__((section(".text.func_001C8D48")))
void func_001C8D48(unsigned char *p)
{
    char hold[16];
    char *e;
    int cnt;

    p[0x2F4] = 0;
    p[0x2F5] = 3;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
    *((int *) (p + 0x610)) = 0;
    *((float *) (p + 0x614)) = 0.06499999761581421f;
    *((int *) (p + 0x618)) = 0;
    *((int *) (p + 0x644)) = 0;
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

        d = *((float **) (e + 0xD0));
        s = (float *) (p + 0x630);
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
        *((int *) (e + 0x100)) = 0;
        *((int *) (e + 0x104)) = 0;
        *((int *) (e + 0x108)) = 0;
    }
}
