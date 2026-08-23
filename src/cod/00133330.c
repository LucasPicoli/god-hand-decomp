/* sn-2.95.3-136 matched TU. */

extern char D_007474A0[];
extern unsigned int D_00754250[];
extern int D_003C3D08;

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.cCollisionScroll_SetLayerCollEnable")))
void cCollisionScroll_SetLayerCollEnable(char *a0, unsigned char kind, int on) {
    unsigned int i;
    char *e;
    char *p;
    if (*(char **)a0 == 0) {
        return;
    }
    for (i = 0; i < *(unsigned short *)(*(char **)a0 + 0x28); i++) {
        e = (char *)(i * 0x14 + *(int *)(a0 + 0x14));
        p = (char *)((*(unsigned short *)(e + 0xC) << 4) + *(int *)(a0 + 0x8));
        if (*(unsigned char *)(p + 0xD) == kind) {
            if (on != 0) {
                *(int *)(e + 0x10) = *(int *)(e + 0x10) & 0xFFFFFFFD;
            } else {
                *(int *)(e + 0x10) = *(int *)(e + 0x10) | 2;
            }
        }
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.func_0013D200")))
void func_0013D200(char *a0) {
    char *g;
    int w;
    int s;
    g = D_007474A0;
    if (*(unsigned short *)(g + 0x5B0) == 0x20) {
        return;
    }
    if (*(unsigned char *)(a0 + 0x93) != 0) {
        return;
    }
    if ((*(int *)(g + 0x5E4) & 0x40000000) != 0) {
        *(short *)(a0 + 0x90) = *(unsigned short *)(a0 + 0x90) - 1;
    } else if (*(unsigned char *)(a0 + 0x92) != 0) {
        *(short *)(a0 + 0x90) = *(unsigned short *)(a0 + 0x90) - 1;
    } else {
        *(short *)(a0 + 0x90) = *(unsigned short *)(a0 + 0x90) + 1;
    }
    s = *(short *)(a0 + 0x90);
    w = *(unsigned short *)(a0 + 0x90);
    if (s < 0) goto zero;
    if (s >= 7) {
        w = 6;
        goto store;
    }
    *(short *)(a0 + 0x90) = w;
    return;
zero:
    w = 0;
store:
    *(short *)(a0 + 0x90) = w;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_0014FE78")))
void func_0014FE78(char *a0) {
    char *p;
    unsigned int i;
    p = (char *)(*(int *)(a0 + 0x0) | 0x20000000);
    for (i = 0; i < (unsigned int)(*(int *)(a0 + 0x20) - 1); i++) {
        *(long *)(p + 0x8) = 0;
        *(long *)(p + 0x0) = ((long)(((int)p & 0xFFFFFFF) + 0x10) << 32) | 0x20000000;
        p += 0x10;
    }
    *(long *)(p + 0x8) = 0;
    *(long *)(p + 0x0) = ((long)(a0 + 0x10) << 32) | 0x20000000;
    *(long *)(a0 + 0x10) = 0x70000000;
    *(long *)(a0 + 0x18) = 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */



__attribute__((section(".text.func_0030F2B0")))
void func_0030F2B0(unsigned int s) {
    D_00754250[0] = s;
    for (D_003C3D08 = 1; D_003C3D08 < 0x270; D_003C3D08++) {
        D_00754250[D_003C3D08] = 1812433253UL * (D_00754250[D_003C3D08 - 1] ^ (D_00754250[D_003C3D08 - 1] >> 30)) + D_003C3D08;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.cArea_AreaGetCenterPos")))
void cArea_AreaGetCenterPos(char *a0, float *a1) {
    if (*(unsigned char *)(a0 + 0x1) == 1) goto t1;
    if (*(unsigned char *)(a0 + 0x1) == 2) goto t2;
    return;
t1:
    a1[0] = (*(float *)(a0 + 0x10) + *(float *)(a0 + 0x18) + *(float *)(a0 + 0x20) + *(float *)(a0 + 0x28)) * 0.25f;
    a1[1] = *(float *)(a0 + 0x4);
    a1[2] = (*(float *)(a0 + 0x14) + *(float *)(a0 + 0x1C) + *(float *)(a0 + 0x24) + *(float *)(a0 + 0x2C)) * 0.25f;
    return;
t2:
    a1[0] = *(float *)(a0 + 0x10);
    a1[1] = *(float *)(a0 + 0x4);
    a1[2] = *(float *)(a0 + 0x14);
}
