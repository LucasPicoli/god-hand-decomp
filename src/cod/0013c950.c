/* sn-2.95.3-136 matched TU. */

extern void cIDBase_move(void *a0);
extern int D_00747A24[];

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_0013C950")))
void func_0013C950(char *self)
{
    char *p;
    char *p2;
    char *p3;
    int *g;
    int n;
    long t;
    float r;
    float r0;
    float cur;
    unsigned short tick;

    if (*(int *)(self + 0x94) == 0) return;
    p = *(char **)(self + 0x9C);
    if (p == 0) return;
    t = D_00747A24[0];
    if ((((unsigned long)t >> 3) & 1UL) == 1UL) return;
    g = D_00747A24;
    if (g[2] < 0) return;
    n = *(short *)(p + 0x548);
    if (n == 0) return;
    if (g[0x18] & 0x20000000) {
        *(int *)(self + 0xA0) = *(int *)(self + 0xA0) & 0xBFFFFFFFU;
        return;
    }
    if (!(*(int *)(self + 0xA0) & 0x40000000)) {
        r0 = (float)*(short *)(p + 0x54A) / (float)n;
        *(float *)(self + 0xAC) = r0;
        *(float *)(self + 0xB0) = r0;
        switch (*(int *)(p + 0x564)) {
        case 0x250:
            *(int *)(self + 0xB8) = 1;
            *(float *)(*(int *)(self + 0xBC) + 0x70) = 0.155f;
            *(float *)(*(int *)(self + 0xBC) + 0x74) = 0.5f;
            *(float *)(*(int *)(self + 0xBC) + 0x78) = 0.1715f;
            *(float *)(*(int *)(self + 0xBC) + 0x7C) = 0.5625f;
            *(float *)(*(int *)(self + 0xC0) + 0x70) = 0.155f;
            *(float *)(*(int *)(self + 0xC0) + 0x74) = 0.625f;
            *(float *)(*(int *)(self + 0xC0) + 0x78) = 0.1715f;
            *(float *)(*(int *)(self + 0xC0) + 0x7C) = 0.6875f;
            break;
        case 0x251:
            *(int *)(self + 0xB8) = 1;
            *(float *)(*(int *)(self + 0xBC) + 0x70) = 0.155f;
            *(float *)(*(int *)(self + 0xBC) + 0x74) = 0.5f;
            *(float *)(*(int *)(self + 0xBC) + 0x78) = 0.1715f;
            *(float *)(*(int *)(self + 0xBC) + 0x7C) = 0.5625f;
            *(float *)(*(int *)(self + 0xC0) + 0x70) = 0.155f;
            *(float *)(*(int *)(self + 0xC0) + 0x74) = 0.625f;
            *(float *)(*(int *)(self + 0xC0) + 0x78) = 0.1715f;
            *(float *)(*(int *)(self + 0xC0) + 0x7C) = 0.6875f;
            break;
        case 0x260:
            *(int *)(self + 0xB8) = 9;
            *(float *)(*(int *)(self + 0xBC) + 0x70) = 0.155f;
            *(float *)(*(int *)(self + 0xBC) + 0x74) = 0.758f;
            *(float *)(*(int *)(self + 0xBC) + 0x78) = 0.1715f;
            *(float *)(*(int *)(self + 0xBC) + 0x7C) = 0.8125f;
            *(float *)(*(int *)(self + 0xC0) + 0x70) = 0.155f;
            *(float *)(*(int *)(self + 0xC0) + 0x74) = 0.875f;
            *(float *)(*(int *)(self + 0xC0) + 0x78) = 0.1715f;
            *(float *)(*(int *)(self + 0xC0) + 0x7C) = 0.9375f;
            break;
        case 0x252:
            *(int *)(self + 0xB8) = 4;
            *(float *)(*(int *)(self + 0xBC) + 0x70) = 0.28f;
            *(float *)(*(int *)(self + 0xBC) + 0x74) = 0.5f;
            *(float *)(*(int *)(self + 0xBC) + 0x78) = 0.3005f;
            *(float *)(*(int *)(self + 0xBC) + 0x7C) = 0.5625f;
            *(float *)(*(int *)(self + 0xC0) + 0x70) = 0.28f;
            *(float *)(*(int *)(self + 0xC0) + 0x74) = 0.625f;
            *(float *)(*(int *)(self + 0xC0) + 0x78) = 0.3005f;
            *(float *)(*(int *)(self + 0xC0) + 0x7C) = 0.6875f;
            break;
        case 0x264:
            *(int *)(self + 0xB8) = 10;
            *(float *)(*(int *)(self + 0xBC) + 0x70) = 0.155f;
            *(float *)(*(int *)(self + 0xBC) + 0x74) = 0.758f;
            *(float *)(*(int *)(self + 0xBC) + 0x78) = 0.1715f;
            *(float *)(*(int *)(self + 0xBC) + 0x7C) = 0.8125f;
            *(float *)(*(int *)(self + 0xC0) + 0x70) = 0.155f;
            *(float *)(*(int *)(self + 0xC0) + 0x74) = 0.875f;
            *(float *)(*(int *)(self + 0xC0) + 0x78) = 0.1715f;
            *(float *)(*(int *)(self + 0xC0) + 0x7C) = 0.9375f;
            break;
        case 0x265:
            *(int *)(self + 0xB8) = 6;
            *(float *)(*(int *)(self + 0xBC) + 0x70) = 0.155f;
            *(float *)(*(int *)(self + 0xBC) + 0x74) = 0.758f;
            *(float *)(*(int *)(self + 0xBC) + 0x78) = 0.1715f;
            *(float *)(*(int *)(self + 0xBC) + 0x7C) = 0.8125f;
            *(float *)(*(int *)(self + 0xC0) + 0x70) = 0.155f;
            *(float *)(*(int *)(self + 0xC0) + 0x74) = 0.875f;
            *(float *)(*(int *)(self + 0xC0) + 0x78) = 0.1715f;
            *(float *)(*(int *)(self + 0xC0) + 0x7C) = 0.9375f;
            break;
        case 0x256:
            *(float *)(*(int *)(self + 0xBC) + 0x70) = 0.405f;
            *(float *)(*(int *)(self + 0xBC) + 0x74) = 0.5f;
            *(float *)(*(int *)(self + 0xBC) + 0x78) = 0.4305f;
            *(float *)(*(int *)(self + 0xBC) + 0x7C) = 0.5625f;
            *(float *)(*(int *)(self + 0xC0) + 0x70) = 0.405f;
            *(float *)(*(int *)(self + 0xC0) + 0x74) = 0.625f;
            *(float *)(*(int *)(self + 0xC0) + 0x78) = 0.4305f;
            *(float *)(*(int *)(self + 0xC0) + 0x7C) = 0.6875f;
            if (*(int *)(self + 0xB8) != 8) {
                *(int *)(self + 0xB8) = 5;
            }
            break;
        case 0x27E:
            *(float *)(*(int *)(self + 0xBC) + 0x70) = 0.28f;
            *(float *)(*(int *)(self + 0xBC) + 0x74) = 0.758f;
            *(float *)(*(int *)(self + 0xBC) + 0x78) = 0.3005f;
            *(float *)(*(int *)(self + 0xBC) + 0x7C) = 0.8125f;
            *(float *)(*(int *)(self + 0xC0) + 0x70) = 0.28f;
            *(float *)(*(int *)(self + 0xC0) + 0x74) = 0.875f;
            *(float *)(*(int *)(self + 0xC0) + 0x78) = 0.3005f;
            *(float *)(*(int *)(self + 0xC0) + 0x7C) = 0.9375f;
            *(int *)(self + 0xB8) = 11;
            break;
        }
        *(int *)(self + 0xA0) = *(int *)(self + 0xA0) | 0x40000000;
        *(short *)(self + 0xB4) = 0;
    }
    p2 = *(char **)(self + 0x9C);
    cur = *(float *)(self + 0xAC);
    r = (float)*(short *)(p2 + 0x54A) / (float)*(short *)(p2 + 0x548);
    if (cur != r) {
        *(short *)(self + 0xB4) = 0x28;
    }
    *(float *)(*(int *)(self + 0xBC) + 0x40) = r;
    tick = *(unsigned short *)(self + 0xB4);
    if (tick == 0) {
        float a8;
        *(float *)(*(int *)(self + 0xC0) + 0x40) = *(float *)(self + 0xA8);
        a8 = *(float *)(self + 0xA8);
        *(float *)(self + 0xA8) = a8 - (a8 - r) * 0.07f;
    } else {
        *(short *)(self + 0xB4) = tick - 1;
    }
    *(float *)(self + 0xAC) = r;
    *(float *)(*(int *)(self + 0xC8) + 0x3C) =
        *(float *)(*(int *)(self + 0xC8) + 0x3C) + 10.0f;
    {
        char *ea;
        char *eb;
        ea = *(char **)(self + 0xC8);
        eb = *(char **)(ea + 0x1C);
        if (*(float *)(eb + 0xC) <= *(float *)(ea + 0x3C)) {
            *(float *)(ea + 0x3C) = *(float *)(eb + 0xC);
        }
    }
    *(float *)(*(int *)(self + 0xCC) + 0x38) =
        *(float *)(*(int *)(self + 0xCC) + 0x38) + 10.0f;
    {
        char *fa;
        char *fb;
        fa = *(char **)(self + 0xCC);
        fb = *(char **)(fa + 0x1C);
        if (*(float *)(fb + 0x8) <= *(float *)(fa + 0x38)) {
            *(float *)(fa + 0x38) = *(float *)(fb + 0x8);
        }
    }
    if (!(*(int *)(self + 0xA0) & 0x20000000)) {
        *(float *)(*(int *)(self + 0xC8) + 0x3C) = -100.0f;
        *(float *)(*(int *)(self + 0xCC) + 0x38) = -100.0f;
    }
    p3 = *(char **)(self + 0x9C);
    switch (*(int *)(p3 + 0x564)) {
    case 0x250:
        break;
    case 0x251: {
        unsigned short h = *(unsigned short *)(self + 0xB4);
        *(int *)(self + 0xB8) = 1;
        if (h % 3 != 0) {
            *(int *)(self + 0xB8) = 3;
        } else if (r < 0.5f) {
            *(int *)(self + 0xB8) = 3;
        }
        break;
    }
    case 0x260:
        if (*(unsigned short *)(self + 0xB4) == 0x27) {
            *(float *)(self + 0xB0) = *(float *)(self + 0xA8);
        }
        *(char *)(*(int *)(self + 0xC0) + 0x4F) =
            (int)((*(float *)(self + 0xA8) - *(float *)(self + 0xAC)) /
                  (*(float *)(self + 0xB0) - *(float *)(self + 0xAC)) * 128.0f);
        break;
    case 0x264:
        if (*(unsigned short *)(self + 0xB4) == 0x27) {
            *(float *)(self + 0xB0) = *(float *)(self + 0xA8);
        }
        *(char *)(*(int *)(self + 0xC0) + 0x4F) =
            (int)((*(float *)(self + 0xA8) - *(float *)(self + 0xAC)) /
                  (*(float *)(self + 0xB0) - *(float *)(self + 0xAC)) * 128.0f);
        break;
    case 0x265:
        if (*(unsigned short *)(self + 0xB4) == 0x27) {
            *(float *)(self + 0xB0) = *(float *)(self + 0xA8);
        }
        *(char *)(*(int *)(self + 0xC0) + 0x4F) =
            (int)((*(float *)(self + 0xA8) - *(float *)(self + 0xAC)) /
                  (*(float *)(self + 0xB0) - *(float *)(self + 0xAC)) * 128.0f);
        break;
    }
    *(char *)(*(int *)(self + 0xC4) + 0x8B) = *(unsigned char *)(self + 0xB8) - 1;
    cIDBase_move(self);
}
