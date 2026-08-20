/* sn-2.95.3-136 matched TU. */

extern void func_00185E68(void *a0, int a1);
extern void func_00185F50(void *a0, int a1);
extern int D_006046C0;
extern void cSpline_setBasePoint(void *a0, void *a1);
extern void cSpline_getPoint(void *a0, void *a1, float a2);
extern int D_003C23B0;

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_00184FE0")))
void func_00184FE0(void *a0) {
    char *s0 = (char *)a0;
    float f1 = (float)*(short *)(s0 + 0x626) / (float)*(short *)(s0 + 0x634);
    switch (*(unsigned char *)(s0 + 0x659)) {
    case 0:
        if (f1 <= 0.5f) { func_00185E68(s0, 1); *(unsigned char *)(s0 + 0x659) += 1; }
        break;
    case 1:
        if (f1 <= 0.0f) { func_00185E68(s0, 4); *(unsigned char *)(s0 + 0x659) += 1; }
        break;
    case 2:
        *(unsigned char *)(s0 + 0x660) = 1;
        break;
    }
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001850B0")))
void func_001850B0(void *a0) {
    char *s0 = (char *)a0;
    float f1 = (float)*(short *)(s0 + 0x628) / (float)*(short *)(s0 + 0x636);
    switch (*(unsigned char *)(s0 + 0x65A)) {
    case 0:
        if (f1 <= 0.5f) { func_00185F50(s0, 1); *(unsigned char *)(s0 + 0x65A) += 1; }
        break;
    case 1:
        if (f1 <= 0.0f) { func_00185F50(s0, 4); *(unsigned char *)(s0 + 0x65A) += 1; }
        break;
    case 2:
        *(unsigned char *)(s0 + 0x661) = 1;
        break;
    }
}

/* sn-2.95.3-136 matched TU.  fp_hazard_rules: "mtc1" */






__attribute__((section(".text.func_002EDEA0")))
void func_002EDEA0(void *a0, void *a1, void *a2, int a3) {
    char *arr = (char *)a1;
    int n = *(int *)((char *)a0 + 0x2E4);
    int q = a3 / n;
    int r = a3 % n;
    float t = (float)r / (float)n;
    if (q == 0) {
        cSpline_setBasePoint(&D_006046C0, arr);
        cSpline_getPoint(&D_006046C0, a2, t);
    } else {
        cSpline_setBasePoint(&D_006046C0, arr + (q * 16 - 16));
        cSpline_getPoint(&D_006046C0, a2, t + 1.0f);
    }
}

/* frameless leaf. */



__attribute__((section(".text.func_002B04C0")))
int func_002B04C0(void *a0, void *a1, void *a2) {
    char *ctx = (char *)a0;
    unsigned short *p = (unsigned short *)a1;
    char *out = (char *)a2;
    unsigned short v = *p;
    if ((v >> 15) == 0) return 0;
    switch (v & 0xFF00) {
    case 0xB000:
        *(float *)out = (float)p[1] / 100.0f;
        return 1;
    case 0xB200:
        *(int *)(out + 4) = (p[1] << 16) | p[2];
        return 1;
    case 0xB300:
        *(int *)(out + 4) = *(int *)((char *)&D_003C23B0
            + *(int *)(ctx + 0x50) * 4 + *(int *)(ctx + 0x4C) * 20);
        return 1;
    case 0xB600:
        *(int *)(out + 4) = *(int *)((char *)&D_003C23B0
            + p[1] * 4 + *(int *)(ctx + 0x4C) * 20);
        return 1;
    case 0xB700:
        *(int *)(out + 8) |= 1;
        return 1;
    case 0xB800:
        *(unsigned int *)(out + 8) &= 0xFFFFFFFE;
        return 1;
    }
    return 0;
}
