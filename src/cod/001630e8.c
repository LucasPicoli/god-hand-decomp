/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00583EC0[];
extern unsigned char *D_00586B28;
extern unsigned char *D_003C23A4;

static inline void setxy(unsigned char *p, float a, float b)
{
    unsigned char *r1;
    unsigned char *r2;

    r1 = *(unsigned char **)(p + 0x80);
    *(float *)(r1 + 0x38) = a;
    r2 = *(unsigned char **)(p + 0x80);
    *(float *)(r2 + 0x3C) = b;
}

__attribute__((section(".text.func_001630E8")))
void func_001630E8(unsigned char *p)
{
    unsigned char *q;
    unsigned char *r;
    unsigned int v;
    unsigned int hi;
    unsigned int t;
    unsigned int u;
    int ofs;

    ofs = 0x1C;
    q = D_00583EC0 + ofs;
    if (q == 0) {
        return;
    }
    if (*(int *)D_00586B28 & 1) {
        v = *(unsigned short *)(D_00586B28 + 8);
        hi = v >> 8;
        if (hi != 0) {
            u = (hi << 4) + 0x2013;
            t = u + (v & 0xFF);
        } else {
            t = 0x20A3;
        }
    } else {
        v = *(unsigned short *)(q + 0x10);
        hi = v >> 8;
        if (hi != 0) {
            u = (hi << 4) + 0x2013;
            t = u + (v & 0xFF);
        } else {
            t = 0x20A3;
        }
    }
    switch (hi) {
    case 0:
        setxy(p, 254.0f, 289.0f);
        break;
    case 1:
        setxy(p, 102.0f, 266.0f);
        break;
    case 2:
        setxy(p, 167.0f, 195.0f);
        break;
    case 3:
        setxy(p, 134.0f, 92.0f);
        break;
    case 4:
        setxy(p, 235.0f, 126.0f);
        break;
    case 5:
        setxy(p, 320.0f, 190.0f);
        break;
    case 6:
        setxy(p, 320.0f, 88.0f);
        break;
    case 7:
        setxy(p, 408.0f, 88.0f);
        break;
    case 8:
        setxy(p, 455.0f, 47.0f);
        break;
    }
    r = *(unsigned char **)(p + 0x80);
    if (t >= 0x20A4) {
        t = 0x20A3;
    }
    *(float *)(p + 0x128) = *(float *)(r + 0x38);
    *(float *)(p + 0x12C) = *(float *)(r + 0x3C);
    *(unsigned short *)(D_003C23A4 + 0xBEE) = t;
    *(unsigned short *)(*(unsigned char **)(p + 0xE4) + 0x90) = 0x2022;
    *(unsigned short *)(*(unsigned char **)(p + 0xE8) + 0x90) = 0x2022;
}
