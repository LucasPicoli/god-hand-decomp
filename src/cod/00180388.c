/* sn-2.95.3-136 matched TU. */

extern float D_00567FF0[];
extern float D_00568020[];
extern float D_00567FC0[];

__attribute__((section(".text.cOl2b_setOpenFix")))
void cOl2b_setOpenFix(unsigned char *p)
{
    char hold[16];
    float *s;
    int i;
    int z;

    if (*((int *) (p + 0xA24)) == 1) {
        return;
    }
    s = D_00567FF0;
    i = 0;
    z = 0;
    do {
        char *e;
        int cnt;
        unsigned char ok;

        ok = ((*((int *) hold) = cnt = *((unsigned char *) (p + 0x2B4))), (i >= z && i < cnt));
        if (ok) {
            e = *((char **) (*((char **) (p + 0x278)) + i * 4));
        } else {
            e = 0;
        }
        if (e != 0) {
            float *d;

            d = (float *) (e + 0x100);
            if (d != s) {
                *((float *) (e + 0x100)) = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
        }
        i++;
        s += 4;
    } while (i < 3);
    *((int *) (p + 0xA24)) = 1;
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
}

__attribute__((section(".text.cOl2b_setCloseFix")))
void cOl2b_setCloseFix(unsigned char *p)
{
    char hold[16];
    float *s;
    int i;
    int z;

    if (*((int *) (p + 0xA24)) == 2) {
        return;
    }
    s = D_00568020;
    i = 0;
    z = 0;
    do {
        char *e;
        int cnt;
        unsigned char ok;

        ok = ((*((int *) hold) = cnt = *((unsigned char *) (p + 0x2B4))), (i >= z && i < cnt));
        if (ok) {
            e = *((char **) (*((char **) (p + 0x278)) + i * 4));
        } else {
            e = 0;
        }
        if (e != 0) {
            float *d;

            d = (float *) (e + 0x100);
            if (d != s) {
                *((float *) (e + 0x100)) = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
        }
        i++;
        s += 4;
    } while (i < 3);
    *((int *) (p + 0xA24)) = 2;
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
}

__attribute__((section(".text.cOl2b_setInitFix")))
void cOl2b_setInitFix(unsigned char *p)
{
    char hold[16];
    float *s;
    int i;
    int z;

    if (*((int *) (p + 0xA24)) == 0) {
        return;
    }
    s = D_00567FC0;
    i = 0;
    z = 0;
    do {
        char *e;
        int cnt;
        unsigned char ok;

        ok = ((*((int *) hold) = cnt = *((unsigned char *) (p + 0x2B4))), (i >= z && i < cnt));
        if (ok) {
            e = *((char **) (*((char **) (p + 0x278)) + i * 4));
        } else {
            e = 0;
        }
        if (e != 0) {
            float *d;

            d = (float *) (e + 0x100);
            if (d != s) {
                *((float *) (e + 0x100)) = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
        }
        i++;
        s += 4;
    } while (i < 3);
    *((int *) (p + 0xA24)) = 0;
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
}
