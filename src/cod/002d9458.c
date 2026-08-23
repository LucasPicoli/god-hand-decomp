/* sn-2.95.3-136 matched TU. */

typedef struct {
    int a[5];
} T20;

__attribute__((section(".text.func_002D9458")))
void *func_002D9458(void *dst, void *src) {
    unsigned char *d;
    unsigned char *s;
    unsigned char *di;
    unsigned char *si;
    unsigned char *dq;
    unsigned char *sq;
    int i;
    int j;
    int k;

    d = (unsigned char *)dst;
    s = (unsigned char *)src;

    d[0x0] = s[0x0];
    d[0x1] = s[0x1];
    d[0x2] = s[0x2];
    d[0x3] = s[0x3];
    d[0x4] = s[0x4];
    d[0x5] = s[0x5];
    d[0x6] = s[0x6];
    d[0x7] = s[0x7];
    d[0x8] = s[0x8];
    d[0x9] = s[0x9];
    d[0xA] = s[0xA];
    d[0xB] = s[0xB];
    d[0xC] = s[0xC];
    d[0xD] = s[0xD];
    d[0xE] = s[0xE];
    d[0xF] = s[0xF];
    *(float *)(d + 0x10) = *(float *)(s + 0x10);
    *(float *)(d + 0x14) = *(float *)(s + 0x14);
    *(float *)(d + 0x18) = *(float *)(s + 0x18);
    *(float *)(d + 0x1C) = *(float *)(s + 0x1C);
    *(float *)(d + 0x20) = *(float *)(s + 0x20);
    *(float *)(d + 0x24) = *(float *)(s + 0x24);
    {
        float *sv = (float *)(s + 0x30);
        float *dv = (float *)(d + 0x30);
        if (dv != sv) {
            dv[0] = sv[0];
            dv[1] = sv[1];
            dv[2] = sv[2];
        }
    }
    {
        float *dv = (float *)(d + 0x40);
        float *sv = (float *)(s + 0x40);
        if (dv != sv) {
            dv[0] = sv[0];
            dv[1] = sv[1];
            dv[2] = sv[2];
        }
    }
    {
        float *dv = (float *)(d + 0x50);
        float *sv = (float *)(s + 0x50);
        if (dv != sv) {
            dv[0] = sv[0];
            dv[1] = sv[1];
            dv[2] = sv[2];
        }
    }
    d[0x60] = s[0x60];
    d[0x61] = s[0x61];
    d[0x62] = s[0x62];
    d[0x63] = s[0x63];
    *(float *)(d + 0x64) = *(float *)(s + 0x64);
    *(float *)(d + 0x68) = *(float *)(s + 0x68);
    d[0x6C] = s[0x6C];
    d[0x6D] = s[0x6D];
    d[0x6E] = s[0x6E];
    d[0x6F] = s[0x6F];
    *(float *)(d + 0x70) = *(float *)(s + 0x70);
    *(float *)(d + 0x74) = *(float *)(s + 0x74);
    *(int *)(d + 0x78) = *(int *)(s + 0x78);

    di = d + 0x80;
    i = 0xFF;
    si = s + 0x80;
    do {
        *(unsigned short *)(di + 0x0) = *(unsigned short *)(si + 0x0);
        *(unsigned short *)(di + 0x2) = *(unsigned short *)(si + 0x2);
        *(int *)(di + 0x4) = *(int *)(si + 0x4);
        {
            float *dv = (float *)(di + 0x10);
            float *sv = (float *)(si + 0x10);
            if (dv != sv) {
                dv[0] = sv[0];
                dv[1] = sv[1];
                dv[2] = sv[2];
            }
        }
        {
            float *dv = (float *)(di + 0x20);
            float *sv = (float *)(si + 0x20);
            if (dv != sv) {
                dv[0] = sv[0];
                dv[1] = sv[1];
                dv[2] = sv[2];
            }
        }
        {
            float *dv = (float *)(di + 0x30);
            float *sv = (float *)(si + 0x30);
            if (dv != sv) {
                dv[0] = sv[0];
                dv[1] = sv[1];
                dv[2] = sv[2];
            }
        }
        *(float *)(di + 0x40) = *(float *)(si + 0x40);
        *(float *)(di + 0x44) = *(float *)(si + 0x44);
        *(float *)(di + 0x48) = *(float *)(si + 0x48);
        {
            int *dw = (int *)(di + 0x4C);
            int *sw;
            j = 1;
            sw = (int *)(si + 0x4C);
            do {
                *dw = *sw;
                sw++;
                dw++;
                j--;
            } while (j != -1);
        }
        *(int *)(di + 0x54) = *(int *)(si + 0x54);
        *(int *)(di + 0x58) = *(int *)(si + 0x58);
        *(unsigned short *)(di + 0x5C) = *(unsigned short *)(si + 0x5C);
        *(unsigned short *)(di + 0x5E) = *(unsigned short *)(si + 0x5E);
        di[0x60] = si[0x60];
        di[0x61] = si[0x61];
        *(unsigned short *)(di + 0x62) = *(unsigned short *)(si + 0x62);
        di += 0x70;
        si += 0x70;
        i--;
    } while (i != -1);

    dq = d + 0x7080;
    sq = s + 0x7080;
    k = 0x2F;
    do {
        *(T20 *)dq = *(T20 *)sq;
        dq += 0x14;
        sq += 0x14;
        k--;
    } while (k != -1);

    *(int *)(d + 0x7440) = *(int *)(s + 0x7440);
    return d;
}
