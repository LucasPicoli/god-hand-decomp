/* sn-2.95.3-136 matched TU. */

extern int cModel_setupModel(void *a, void *b, void *c, int d, int e);
extern void cModel_calcParts(void *m);
extern void func_00276C88(void *a0);
extern float D_003BD880;
extern void func_0027A600(void *a0);
extern void func_0027B0F8(void *a0);
extern void func_00283968(void *a0);
extern void func_00284350(void *a0);

__attribute__((section(".text.func_00276808")))
int func_00276808(char *p)
{
    char hold[16];
    char *base;
    int ok;
    int cnt;

    ok = 0;
    base = *((char **) (p + 0x304));
    if (cModel_setupModel(p, (void *) (*((int *) (base + 0x4)) + (int) base),
                          (void *) (*((int *) (base + 0x8)) + (int) base),
                          0, 0) != 0) {
        char *e1;

        cnt = *((unsigned char *) (p + 0x2B4));
        *((int *) (p + 0x2F0)) |= 0x40;
        p[0x531] = -1;
        ok = 1;
        *((unsigned int *) (p + 0x250)) |= 0x10000;
        *((int *) (p + 0x21B0)) = 0;
        *((int *) hold) = cnt;
        if (cnt != 0) {
            e1 = *((char **) *((char **) (p + 0x278)));
        } else {
            e1 = 0;
        }
        if (e1 != 0) {
            char *e2;
            char *e3;
            float *d;
            float *s;
            int c2;
            int c3;

            c2 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c2;
            if (c2 != 0) {
                e2 = *((char **) *((char **) (p + 0x278)));
            } else {
                e2 = 0;
            }
            d = (float *) (e2 + 0xE0);
            s = &D_003BD880;
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
            c3 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c3;
            if (c3 != 0) {
                e3 = *((char **) *((char **) (p + 0x278)));
            } else {
                e3 = 0;
            }
            {
                float *d2 = (float *) *((char **) (e3 + 0xD0));
                float *s2 = &D_003BD880;

                d2[0] = s2[0];
                d2[1] = s2[1];
                d2[2] = s2[2];
            }
        }
        cModel_calcParts(p);
        func_00276C88(p);
    }
    return ok;
}

__attribute__((section(".text.func_0027A180")))
int func_0027A180(char *p)
{
    char hold[16];
    char *base;
    int ok;
    int cnt;

    ok = 0;
    base = *((char **) (p + 0x304));
    if (cModel_setupModel(p, (void *) (*((int *) (base + 0x4)) + (int) base),
                          (void *) (*((int *) (base + 0x8)) + (int) base),
                          0, 0) != 0) {
        char *e1;

        cnt = *((unsigned char *) (p + 0x2B4));
        *((int *) (p + 0x2F0)) |= 0x40;
        p[0x531] = -1;
        ok = 1;
        *((unsigned int *) (p + 0x250)) |= 0x10000;
        *((int *) (p + 0x21B0)) = 0;
        *((int *) hold) = cnt;
        if (cnt != 0) {
            e1 = *((char **) *((char **) (p + 0x278)));
        } else {
            e1 = 0;
        }
        if (e1 != 0) {
            char *e2;
            char *e3;
            float *d;
            float *s;
            int c2;
            int c3;

            c2 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c2;
            if (c2 != 0) {
                e2 = *((char **) *((char **) (p + 0x278)));
            } else {
                e2 = 0;
            }
            d = (float *) (e2 + 0xE0);
            s = &D_003BD880;
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
            c3 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c3;
            if (c3 != 0) {
                e3 = *((char **) *((char **) (p + 0x278)));
            } else {
                e3 = 0;
            }
            {
                float *d2 = (float *) *((char **) (e3 + 0xD0));
                float *s2 = &D_003BD880;

                d2[0] = s2[0];
                d2[1] = s2[1];
                d2[2] = s2[2];
            }
        }
        cModel_calcParts(p);
        func_0027A600(p);
    }
    return ok;
}

__attribute__((section(".text.func_0027AC70")))
int func_0027AC70(char *p)
{
    char hold[16];
    char *base;
    int ok;
    int cnt;

    ok = 0;
    base = *((char **) (p + 0x304));
    if (cModel_setupModel(p, (void *) (*((int *) (base + 0x4)) + (int) base),
                          (void *) (*((int *) (base + 0x8)) + (int) base),
                          0, 0) != 0) {
        char *e1;

        cnt = *((unsigned char *) (p + 0x2B4));
        *((int *) (p + 0x2F0)) |= 0x40;
        p[0x531] = -1;
        ok = 1;
        *((unsigned int *) (p + 0x250)) |= 0x10000;
        *((int *) (p + 0x21B0)) = 0;
        *((int *) hold) = cnt;
        if (cnt != 0) {
            e1 = *((char **) *((char **) (p + 0x278)));
        } else {
            e1 = 0;
        }
        if (e1 != 0) {
            char *e2;
            char *e3;
            float *d;
            float *s;
            int c2;
            int c3;

            c2 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c2;
            if (c2 != 0) {
                e2 = *((char **) *((char **) (p + 0x278)));
            } else {
                e2 = 0;
            }
            d = (float *) (e2 + 0xE0);
            s = &D_003BD880;
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
            c3 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c3;
            if (c3 != 0) {
                e3 = *((char **) *((char **) (p + 0x278)));
            } else {
                e3 = 0;
            }
            {
                float *d2 = (float *) *((char **) (e3 + 0xD0));
                float *s2 = &D_003BD880;

                d2[0] = s2[0];
                d2[1] = s2[1];
                d2[2] = s2[2];
            }
        }
        cModel_calcParts(p);
        func_0027B0F8(p);
    }
    return ok;
}

__attribute__((section(".text.func_002834E8")))
int func_002834E8(char *p)
{
    char hold[16];
    char *base;
    int ok;
    int cnt;

    ok = 0;
    base = *((char **) (p + 0x304));
    if (cModel_setupModel(p, (void *) (*((int *) (base + 0x4)) + (int) base),
                          (void *) (*((int *) (base + 0x8)) + (int) base),
                          0, 0) != 0) {
        char *e1;

        cnt = *((unsigned char *) (p + 0x2B4));
        *((int *) (p + 0x2F0)) |= 0x40;
        p[0x531] = -1;
        ok = 1;
        *((unsigned int *) (p + 0x250)) |= 0x10000;
        *((int *) (p + 0x21B0)) = 0;
        *((int *) hold) = cnt;
        if (cnt != 0) {
            e1 = *((char **) *((char **) (p + 0x278)));
        } else {
            e1 = 0;
        }
        if (e1 != 0) {
            char *e2;
            char *e3;
            float *d;
            float *s;
            int c2;
            int c3;

            c2 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c2;
            if (c2 != 0) {
                e2 = *((char **) *((char **) (p + 0x278)));
            } else {
                e2 = 0;
            }
            d = (float *) (e2 + 0xE0);
            s = &D_003BD880;
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
            c3 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c3;
            if (c3 != 0) {
                e3 = *((char **) *((char **) (p + 0x278)));
            } else {
                e3 = 0;
            }
            {
                float *d2 = (float *) *((char **) (e3 + 0xD0));
                float *s2 = &D_003BD880;

                d2[0] = s2[0];
                d2[1] = s2[1];
                d2[2] = s2[2];
            }
        }
        cModel_calcParts(p);
        func_00283968(p);
    }
    return ok;
}

__attribute__((section(".text.func_00283EC8")))
int func_00283EC8(char *p)
{
    char hold[16];
    char *base;
    int ok;
    int cnt;

    ok = 0;
    base = *((char **) (p + 0x304));
    if (cModel_setupModel(p, (void *) (*((int *) (base + 0x4)) + (int) base),
                          (void *) (*((int *) (base + 0x8)) + (int) base),
                          0, 0) != 0) {
        char *e1;

        cnt = *((unsigned char *) (p + 0x2B4));
        *((int *) (p + 0x2F0)) |= 0x40;
        p[0x531] = -1;
        ok = 1;
        *((unsigned int *) (p + 0x250)) |= 0x10000;
        *((int *) (p + 0x21B0)) = 0;
        *((int *) hold) = cnt;
        if (cnt != 0) {
            e1 = *((char **) *((char **) (p + 0x278)));
        } else {
            e1 = 0;
        }
        if (e1 != 0) {
            char *e2;
            char *e3;
            float *d;
            float *s;
            int c2;
            int c3;

            c2 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c2;
            if (c2 != 0) {
                e2 = *((char **) *((char **) (p + 0x278)));
            } else {
                e2 = 0;
            }
            d = (float *) (e2 + 0xE0);
            s = &D_003BD880;
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
            c3 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c3;
            if (c3 != 0) {
                e3 = *((char **) *((char **) (p + 0x278)));
            } else {
                e3 = 0;
            }
            {
                float *d2 = (float *) *((char **) (e3 + 0xD0));
                float *s2 = &D_003BD880;

                d2[0] = s2[0];
                d2[1] = s2[1];
                d2[2] = s2[2];
            }
        }
        cModel_calcParts(p);
        func_00284350(p);
    }
    return ok;
}
