/* sn-2.95.3-136 matched TU. */

extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);

__attribute__((section(".text.func_001CF3A8")))
void func_001CF3A8(char *p)
{
    char hold[16];
    char *obj;
    char *o2;
    char *e;
    int idx;
    int cnt;
    int ok;
    float *d;
    float *s;

    obj = *((char **) (p + 0x600));
    ok = 0;
    if (obj != 0) {
        cnt = *((unsigned char *) (obj + 0x2B4));
        idx = *((int *) (p + 0x604));
        /* The store keeps `cnt` alive to the compare; the second statement in
           the `then` block is what stops gcc turning the branch into a movz. */
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
        if (e != 0) {
            d = (float *) *((char **) (p + 0xF0));
            s = (float *) (p + 0x610);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            sceVu0ApplyMatrix(*((char **) (p + 0xF0)), e + 0x80,
                              *((char **) (p + 0xF0)));
            o2 = *((char **) (p + 0x600));
            {
                float *d2 = (float *) (p + 0x100);
                float *s2 = (float *) (o2 + 0x100);

                if (d2 != s2) {
                    d2[0] = s2[0];
                    d2[1] = s2[1];
                    d2[2] = s2[2];
                }
            }
            obj = *((char **) (p + 0x600));
            *((float *) (p + 0x24C)) = *((float *) (obj + 0x24C));
            if (*((int *) (obj + 0x250)) & 0x10) {
                *((unsigned int *) (p + 0x250)) |= 0x10;
            } else {
                *((unsigned int *) (p + 0x250)) &= 0xFFFFFFEF;
            }
        }
    }
}

__attribute__((section(".text.func_00279B20")))
void func_00279B20(char *p)
{
    char hold[16];
    char *obj;
    char *o2;
    char *e;
    int idx;
    int cnt;
    int ok;
    float *d;
    float *s;

    obj = *((char **) (p + 0x1580));
    ok = 0;
    if (obj != 0) {
        cnt = *((unsigned char *) (obj + 0x2B4));
        idx = *((int *) (p + 0x1584));
        /* The store keeps `cnt` alive to the compare; the second statement in
           the `then` block is what stops gcc turning the branch into a movz. */
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
        if (e != 0) {
            d = (float *) *((char **) (p + 0xF0));
            s = (float *) (p + 0x1590);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            sceVu0ApplyMatrix(*((char **) (p + 0xF0)), e + 0x80,
                              *((char **) (p + 0xF0)));
            o2 = *((char **) (p + 0x1580));
            {
                float *d2 = (float *) (p + 0x100);
                float *s2 = (float *) (o2 + 0x100);

                if (d2 != s2) {
                    d2[0] = s2[0];
                    d2[1] = s2[1];
                    d2[2] = s2[2];
                }
            }
            obj = *((char **) (p + 0x1580));
            *((float *) (p + 0x24C)) = *((float *) (obj + 0x24C));
            if (*((int *) (obj + 0x250)) & 0x10) {
                *((unsigned int *) (p + 0x250)) |= 0x10;
            } else {
                *((unsigned int *) (p + 0x250)) &= 0xFFFFFFEF;
            }
        }
    }
}

__attribute__((section(".text.func_00279FF0")))
void func_00279FF0(char *p)
{
    char hold[16];
    char *obj;
    char *o2;
    char *e;
    int idx;
    int cnt;
    int ok;
    float *d;
    float *s;

    obj = *((char **) (p + 0x1580));
    ok = 0;
    if (obj != 0) {
        cnt = *((unsigned char *) (obj + 0x2B4));
        idx = *((int *) (p + 0x1584));
        /* The store keeps `cnt` alive to the compare; the second statement in
           the `then` block is what stops gcc turning the branch into a movz. */
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
        if (e != 0) {
            d = (float *) *((char **) (p + 0xF0));
            s = (float *) (p + 0x1590);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            sceVu0ApplyMatrix(*((char **) (p + 0xF0)), e + 0x80,
                              *((char **) (p + 0xF0)));
            o2 = *((char **) (p + 0x1580));
            {
                float *d2 = (float *) (p + 0x100);
                float *s2 = (float *) (o2 + 0x100);

                if (d2 != s2) {
                    d2[0] = s2[0];
                    d2[1] = s2[1];
                    d2[2] = s2[2];
                }
            }
            obj = *((char **) (p + 0x1580));
            *((float *) (p + 0x24C)) = *((float *) (obj + 0x24C));
            if (*((int *) (obj + 0x250)) & 0x10) {
                *((unsigned int *) (p + 0x250)) |= 0x10;
            } else {
                *((unsigned int *) (p + 0x250)) &= 0xFFFFFFEF;
            }
        }
    }
}

__attribute__((section(".text.func_0027D300")))
void func_0027D300(char *p)
{
    char hold[16];
    char *obj;
    char *o2;
    char *e;
    int idx;
    int cnt;
    int ok;
    float *d;
    float *s;

    obj = *((char **) (p + 0x1580));
    ok = 0;
    if (obj != 0) {
        cnt = *((unsigned char *) (obj + 0x2B4));
        idx = *((int *) (p + 0x1584));
        /* The store keeps `cnt` alive to the compare; the second statement in
           the `then` block is what stops gcc turning the branch into a movz. */
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
        if (e != 0) {
            d = (float *) *((char **) (p + 0xF0));
            s = (float *) (p + 0x1590);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            sceVu0ApplyMatrix(*((char **) (p + 0xF0)), e + 0x80,
                              *((char **) (p + 0xF0)));
            o2 = *((char **) (p + 0x1580));
            {
                float *d2 = (float *) (p + 0x100);
                float *s2 = (float *) (o2 + 0x100);

                if (d2 != s2) {
                    d2[0] = s2[0];
                    d2[1] = s2[1];
                    d2[2] = s2[2];
                }
            }
            obj = *((char **) (p + 0x1580));
            *((float *) (p + 0x24C)) = *((float *) (obj + 0x24C));
            if (*((int *) (obj + 0x250)) & 0x10) {
                *((unsigned int *) (p + 0x250)) |= 0x10;
            } else {
                *((unsigned int *) (p + 0x250)) &= 0xFFFFFFEF;
            }
        }
    }
}

__attribute__((section(".text.func_0027E950")))
void func_0027E950(char *p)
{
    char hold[16];
    char *obj;
    char *o2;
    char *e;
    int idx;
    int cnt;
    int ok;
    float *d;
    float *s;

    obj = *((char **) (p + 0x1580));
    ok = 0;
    if (obj != 0) {
        cnt = *((unsigned char *) (obj + 0x2B4));
        idx = *((int *) (p + 0x1584));
        /* The store keeps `cnt` alive to the compare; the second statement in
           the `then` block is what stops gcc turning the branch into a movz. */
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
        if (e != 0) {
            d = (float *) *((char **) (p + 0xF0));
            s = (float *) (p + 0x1590);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            sceVu0ApplyMatrix(*((char **) (p + 0xF0)), e + 0x80,
                              *((char **) (p + 0xF0)));
            o2 = *((char **) (p + 0x1580));
            {
                float *d2 = (float *) (p + 0x100);
                float *s2 = (float *) (o2 + 0x100);

                if (d2 != s2) {
                    d2[0] = s2[0];
                    d2[1] = s2[1];
                    d2[2] = s2[2];
                }
            }
            obj = *((char **) (p + 0x1580));
            *((float *) (p + 0x24C)) = *((float *) (obj + 0x24C));
            if (*((int *) (obj + 0x250)) & 0x10) {
                *((unsigned int *) (p + 0x250)) |= 0x10;
            } else {
                *((unsigned int *) (p + 0x250)) &= 0xFFFFFFEF;
            }
        }
    }
}

__attribute__((section(".text.func_00280DB8")))
void func_00280DB8(char *p)
{
    char hold[16];
    char *obj;
    char *o2;
    char *e;
    int idx;
    int cnt;
    int ok;
    float *d;
    float *s;

    obj = *((char **) (p + 0x1580));
    ok = 0;
    if (obj != 0) {
        cnt = *((unsigned char *) (obj + 0x2B4));
        idx = *((int *) (p + 0x1584));
        /* The store keeps `cnt` alive to the compare; the second statement in
           the `then` block is what stops gcc turning the branch into a movz. */
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
        if (e != 0) {
            d = (float *) *((char **) (p + 0xF0));
            s = (float *) (p + 0x1590);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            sceVu0ApplyMatrix(*((char **) (p + 0xF0)), e + 0x80,
                              *((char **) (p + 0xF0)));
            o2 = *((char **) (p + 0x1580));
            {
                float *d2 = (float *) (p + 0x100);
                float *s2 = (float *) (o2 + 0x100);

                if (d2 != s2) {
                    d2[0] = s2[0];
                    d2[1] = s2[1];
                    d2[2] = s2[2];
                }
            }
            obj = *((char **) (p + 0x1580));
            *((float *) (p + 0x24C)) = *((float *) (obj + 0x24C));
            if (*((int *) (obj + 0x250)) & 0x10) {
                *((unsigned int *) (p + 0x250)) |= 0x10;
            } else {
                *((unsigned int *) (p + 0x250)) &= 0xFFFFFFEF;
            }
        }
    }
}

__attribute__((section(".text.func_00283070")))
void func_00283070(char *p)
{
    char hold[16];
    char *obj;
    char *o2;
    char *e;
    int idx;
    int cnt;
    int ok;
    float *d;
    float *s;

    obj = *((char **) (p + 0x1580));
    ok = 0;
    if (obj != 0) {
        cnt = *((unsigned char *) (obj + 0x2B4));
        idx = *((int *) (p + 0x1584));
        /* The store keeps `cnt` alive to the compare; the second statement in
           the `then` block is what stops gcc turning the branch into a movz. */
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
        if (e != 0) {
            d = (float *) *((char **) (p + 0xF0));
            s = (float *) (p + 0x1590);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            sceVu0ApplyMatrix(*((char **) (p + 0xF0)), e + 0x80,
                              *((char **) (p + 0xF0)));
            o2 = *((char **) (p + 0x1580));
            {
                float *d2 = (float *) (p + 0x100);
                float *s2 = (float *) (o2 + 0x100);

                if (d2 != s2) {
                    d2[0] = s2[0];
                    d2[1] = s2[1];
                    d2[2] = s2[2];
                }
            }
            obj = *((char **) (p + 0x1580));
            *((float *) (p + 0x24C)) = *((float *) (obj + 0x24C));
            if (*((int *) (obj + 0x250)) & 0x10) {
                *((unsigned int *) (p + 0x250)) |= 0x10;
            } else {
                *((unsigned int *) (p + 0x250)) &= 0xFFFFFFEF;
            }
        }
    }
}
