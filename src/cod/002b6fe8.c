/* sn-2.95.3-136 matched TU. */

extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern void cModel_setMeshDisplay(void *model, char *name, int on);
extern char D_003BD880[];
extern char D_0044B4D8[];
extern char D_0044B4E0[];
extern char D_0044B4E8[];

#define CD(N)                                                                 \
    {                                                                         \
        int i = (N);                                                          \
        int n;                                                                \
        char *ep;                                                             \
        float *dp;                                                            \
        if (((*((int *) hold) = n = *((unsigned char *) (p + 0x2B4))),         \
             (i < n)))                                                        \
            ep = *((char **) (*((char **) (p + 0x278)) + (N) * 4));           \
        else                                                                  \
            ep = 0;                                                           \
        dp = *((float **) (ep + 0xD0));                                       \
        dp[0] = ((float *) D_003BD880)[0];                                    \
        dp[1] = ((float *) D_003BD880)[1];                                    \
        dp[2] = ((float *) D_003BD880)[2];                                    \
    }

#define CE(N)                                                                 \
    {                                                                         \
        int i = (N);                                                          \
        int n;                                                                \
        char *ep;                                                             \
        float *dp;                                                            \
        if (((*((int *) hold) = n = *((unsigned char *) (p + 0x2B4))),         \
             (i < n)))                                                        \
            ep = *((char **) (*((char **) (p + 0x278)) + (N) * 4));           \
        else                                                                  \
            ep = 0;                                                           \
        dp = (float *) (ep + 0xE0);                                           \
        dp[0] = ((float *) D_003BD880)[0];                                    \
        dp[1] = ((float *) D_003BD880)[1];                                    \
        dp[2] = ((float *) D_003BD880)[2];                                    \
    }

#define CD0()                                                                 \
    {                                                                         \
        int n;                                                                \
        char *ep;                                                             \
        float *dp;                                                            \
        if (((*((int *) hold) = n = *((unsigned char *) (p + 0x2B4))),         \
             (n != 0)))                                                       \
            ep = *((char **) *((char **) (p + 0x278)));                       \
        else                                                                  \
            ep = 0;                                                           \
        dp = *((float **) (ep + 0xD0));                                       \
        dp[0] = ((float *) D_003BD880)[0];                                    \
        dp[1] = ((float *) D_003BD880)[1];                                    \
        dp[2] = ((float *) D_003BD880)[2];                                    \
    }

#define CE0()                                                                 \
    {                                                                         \
        int n;                                                                \
        char *ep;                                                             \
        float *dp;                                                            \
        if (((*((int *) hold) = n = *((unsigned char *) (p + 0x2B4))),         \
             (n != 0)))                                                       \
            ep = *((char **) *((char **) (p + 0x278)));                       \
        else                                                                  \
            ep = 0;                                                           \
        dp = (float *) (ep + 0xE0);                                           \
        dp[0] = ((float *) D_003BD880)[0];                                    \
        dp[1] = ((float *) D_003BD880)[1];                                    \
        dp[2] = ((float *) D_003BD880)[2];                                    \
    }

__attribute__((section(".text.func_002B6FE8")))
void func_002B6FE8(char *p)
{
    char hold[16];
    int idx;
    int sel;
    char *obj;

    idx = *((int *) (p + 0x30B4));
    if (idx != -1) {
        char *o = *((char **) (p + 0x30B0));
        int n = *((unsigned char *) (o + 0x2B4));
        int ok = 0;
        char *ep;
        float *dd;
        float *ss;

        *((int *) hold) = n;
        if (idx >= 0) {
            ok = idx < n;
            n = 0;
        }
        if (ok & 0xFF)
            ep = *((char **) (*((char **) (o + 0x278)) + idx * 4));
        else
            ep = 0;
        dd = (float *) *((char **) (p + 0xF0));
        ss = (float *) (p + 0x30C0);
        if (dd != ss) {
            dd[0] = ss[0];
            dd[1] = ss[1];
            dd[2] = ss[2];
        }
        sceVu0ApplyMatrix(*((char **) (p + 0xF0)), ep + 0x80,
                          *((char **) (p + 0xF0)));
    } else {
        float *dd = (float *) *((char **) (p + 0xF0));
        float *ss = (float *) (p + 0x30C0);
        char *m;

        if (dd != ss) {
            dd[0] = ss[0];
            dd[1] = ss[1];
            dd[2] = ss[2];
        }
        m = *((char **) (p + 0xF0));
        sceVu0ApplyMatrix(m, *((char **) (p + 0x30B0)) + 0x80, m);
    }

    {
        char *o2 = *((char **) (p + 0x30B0));
        float *d2 = (float *) (p + 0x100);
        float *s2 = (float *) (o2 + 0x100);

        if (d2 != s2) {
            d2[0] = s2[0];
            d2[1] = s2[1];
            d2[2] = s2[2];
        }
    }

    sel = *((int *) (p + 0x30A4));
    switch (sel) {
    case 1:
        CD0()
        CD(1)
        CE0()
        CE(1)
        CD(17)
        CD(18)
        CE(17)
        CE(18)
        break;
    case 2:
        CD0()
        CD(1)
        CD(2)
        CE0()
        CE(1)
        CE(2)
        break;
    case 3:
        CD0()
        CD(1)
        CE0()
        CE(1)
        cModel_setMeshDisplay(*((char **) (p + 0x30B0)), D_0044B4D8, 0);
        cModel_setMeshDisplay(*((char **) (p + 0x30B0)), D_0044B4E0, 0);
        cModel_setMeshDisplay(*((char **) (p + 0x30B0)), D_0044B4E8, 0);
        break;
    case 4:
        CD0()
        CD(1)
        CD(2)
        CD(3)
        CD(4)
        CD(5)
        CD(6)
        CE0()
        CE(1)
        CE(2)
        CE(3)
        CE(4)
        CE(5)
        CE(6)
        break;
    case 0:
    case 5:
    default:
        break;
    }

    {
        char *o3 = *((char **) (p + 0x30B0));
        float *d3 = (float *) (p + 0x240);
        float *s3 = (float *) (o3 + 0x240);

        if (d3 != s3) {
            d3[0] = s3[0];
            d3[1] = s3[1];
            d3[2] = s3[2];
        }
    }
    obj = *((char **) (p + 0x30B0));
    *((float *) (p + 0x24C)) = *((float *) (obj + 0x24C));
    if (*((int *) (obj + 0x250)) & 0x10) {
        *((unsigned int *) (p + 0x250)) |= 0x10;
    } else {
        *((unsigned int *) (p + 0x250)) &= 0xFFFFFFEF;
    }
}
