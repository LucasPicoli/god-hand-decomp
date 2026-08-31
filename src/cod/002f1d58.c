/* sn-2.95.3-136 matched TU. */

extern int D_0044EDC0;
extern int D_0044EDE8;
extern int D_00741DC8;
extern void StoreVecFromFieldB0_2B6160(void *dst, void *self);
extern void CopyVec16From20_B62E0(void *dst, void *self);
extern void cNode_setLocalScale(void *self, void *v);
extern void func_002B60D0(void *dst, void *self);
extern void ForwardToAllNodes_14D700(void *a0, long a1, int a2);
extern void func_0014E778(void *a0, long a1);
extern void func_002D9F68(void *, int, ...);
extern void func_0014D7D0(void *a0);

/* sn-2.95.3-136 matched TU. */
















__attribute__((section(".text.func_002F1D58")))
int func_002F1D58(char *o, char *src) {
    float v[4];
    float v2[4];
    int res;
    char *q;
    long mask;
    unsigned int t;

    q = *(char **)(o + 0x110);
    *(float *)(o + 0x300) = *(float *)(src + 0x40);
    *(int *)(o + 0x2B4) = *(unsigned char *)(q + 0x12E);
    *(int *)(o + 0x2DC) = *(signed char *)(q + 0x18C);
    *(int *)(o + 0x2E0) = *(unsigned char *)(q + 0x18D);
    *(int *)(o + 0x2B8) = *(signed char *)(q + 0x18E);
    *(char *)(o + 0x2E8) = *(unsigned char *)(q + 0x18F);
    *(float *)(o + 0x2EC) = (float)*(signed char *)(q + 0x190) * 0.1f + 1.0f;
    *(float *)(o + 0x2F0) = (float)*(signed char *)(q + 0x191) * 0.1f + 1.0f;
    *(float *)(o + 0x2F4) = (float)*(signed char *)(q + 0x192) * 0.03141593f;
    *(float *)(o + 0x2F8) = (float)*(signed char *)(q + 0x193) * 0.005f + 0.0f;
    *(float *)(o + 0x2BC) = *(float *)(q + 0x13C) * 0.01f;
    *(float *)(o + 0x2C4) = *(float *)(q + 0x140) * 0.01f;
    *(float *)(o + 0x2CC) = *(float *)(q + 0x144) * 0.1f;
    *(float *)(o + 0x2C0) = *(float *)(q + 0x148) * 0.01f;
    *(float *)(o + 0x2C8) = *(float *)(q + 0x14C) * 0.01f;
    *(float *)(o + 0x2D0) = *(float *)(q + 0x150) * 0.1f;

    if (func_002F1B60(o) == 0) {
        return 0;
    }
    {
        char *w = *(char **)(o + 0x2B0);
        signed char c;
        if (w == 0) {
            return 0;
        }
        c = *(signed char *)(*(char **)(o + 0x110) + 0x196);
        if (c != 0) {
            *(char *)(w + 0x2B5) = c;
        }
    }
    if (*(signed char *)(*(char **)(o + 0x110) + 0x197) != 0) {
        *(int *)(*(char **)(o + 0x2B0) + 0x250) |= 0x10000;
        *(short *)(*(char **)(o + 0x2B0) + 0x2AE) = 0x1770;
    }
    {
        char *d = *(char **)(o + 0x2B0);
        float *dst;
        *(int *)(o + 0x11C) &= 0xBFFFFFFF;
        StoreVecFromFieldB0_2B6160(v, o);
        dst = (float *)*(char **)(d + 0xF0);
        if (dst != v) {
            dst[0] = v[0];
            dst[1] = v[1];
            dst[2] = v[2];
        }
    }
    CopyVec16From20_B62E0(v, o);
    v[2] = v[0];
    cNode_setLocalScale(o, v);
    {
        char *d = *(char **)(o + 0x2B0);
        float *dst = (float *)(d + 0x110);
        if (dst != v) {
            dst[0] = v[0];
            dst[1] = v[1];
            dst[2] = v[2];
        }
    }
    func_002B60D0(v2, o);
    {
        char *d = *(char **)(o + 0x2B0);
        float *dst = (float *)(d + 0x100);
        if (dst != v2) {
            dst[0] = v2[0];
            dst[1] = v2[1];
            dst[2] = v2[2];
        }
    }
    *(float *)(*(char **)(o + 0x2B0) + 0x240) = *(float *)(o + 0x188);
    *(float *)(*(char **)(o + 0x2B0) + 0x244) = *(float *)(o + 0x18C);
    *(float *)(*(char **)(o + 0x2B0) + 0x248) = *(float *)(o + 0x190);
    *(float *)(*(char **)(o + 0x2B0) + 0x24C) = *(float *)(o + 0x194);

    t = *(unsigned char *)(o + 0x247);
    switch (t) {
    case 0:
        mask = 0x8000000044L;
        goto go;
    case 1:
        mask = 0x8000000048L;
        goto go;
    case 2:
        mask = 0x80000000A1L;
        goto go;
    case 3:
        mask = 0x8000000041L;
        goto go;
    case 4:
        mask = 0x8000000068L;
        goto go;
    case 5:
        mask = 0x80000000A4L;
        goto go;
    case 6:
        mask = 0x8000000009L;
        goto go;
    case 7:
        mask = 0x8000000042L;
        goto go;
    case 8:
        mask = 0x8000000006L;
        goto go;
    default:
        func_002D9F68(o, (int)&D_0044EDC0, *(unsigned char *)(o + 0x102), t);
        return 0;
    }
go:
    ForwardToAllNodes_14D700(*(char **)(o + 0x2B0), mask, 0);
    ForwardToAllNodes_14D700(*(char **)(o + 0x2B0), mask, 1);
    if ((*(int *)(o + 0x11C) & 0x80000) != 0) {
        func_0014E778(*(char **)(o + 0x2B0), 0x51011L);
    }
    {
        int f = *(int *)(o + 0x11C);
        if ((f & 0x2000) != 0) {
            if ((f & 0x4000) != 0) {
                char *d = *(char **)(o + 0x2B0);
                *(int *)(d + 0x2C0) = 3;
                *(short *)(d + 0x2AC) = 1;
            } else {
                char *d = *(char **)(o + 0x2B0);
                *(int *)(d + 0x2C0) = 3;
                *(short *)(d + 0x2AC) = 2;
            }
        } else if ((f & 0x4000) != 0) {
            char *d = *(char **)(o + 0x2B0);
            *(int *)(d + 0x2C0) = 3;
            *(short *)(d + 0x2AC) = 5;
        }
    }
    {
        int n = *(int *)(o + 0x2B8);
        if (n != 0) {
            if (func_00306CC8(&D_00741DC8, *(int *)(o + 0x2B4), n - 1, &res) == 0) {
                func_002D9F68(o, (int)&D_0044EDE8);
            }
            *(int *)(*(char **)(o + 0x2B0) + 0x4D0) = res;
        }
    }
    if (*(float *)(o + 0x2EC) != 1.0f || *(float *)(o + 0x2F0) != 1.0f ||
        *(float *)(o + 0x2F4) != 0.0f || *(float *)(o + 0x2F8) != 0.0f) {
        func_0014D7D0(*(char **)(o + 0x2B0));
        *(char *)(o + 0x2E9) = 1;
    }
    {
        char *d = *(char **)(o + 0x2B0);
        *(int *)(d + 0x254) |= 0x8000000;
    }
    {
        char *w = *(char **)(o + 0x2B0);
        char *vt = *(char **)(w + 0x214);
        (*(void (**)(char *))(vt + 0x54))(w + *(short *)(vt + 0x50));
    }
    return 1;
}
