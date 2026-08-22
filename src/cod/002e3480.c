/* sn-2.95.3-136 matched TU. */

extern void *InitObject_2FBCC8(void *this);
extern char D_0044E300[];
extern char D_0044E8C8[];
extern void func_002D9F68(void *this, void *tbl, int n);
extern char D_0044EB50[];

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002E3480")))
void *func_002E3480(char *this) {
    InitObject_2FBCC8(this);

    *(int *)(this + 0x2B0) = 0;
    *(float *)(this + 0x2D4) = 1.0f;
    *(char **)(this + 0xF0) = D_0044E300;
    *(int *)(this + 0x2B4) = 0;
    *(int *)(this + 0x2B8) = 0;
    *(int *)(this + 0x2C0) = 0;
    *(int *)(this + 0x2C4) = 0;
    *(int *)(this + 0x2C8) = 0;
    *(int *)(this + 0x2D8) = 0;
    *(int *)(this + 0x2DC) = 0;
    *(int *)(this + 0x2BC) = 0;
    *(int *)(this + 0x30C) = 0;
    *(int *)(this + 0x324) = 0;
    *(int *)(this + 0x330) = 0;
    *(int *)(this + 0x334) = 0;
    *(int *)(this + 0x338) = 0;
    *(int *)(this + 0x33C) = 0;

    return this;
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002EBF08")))
void *func_002EBF08(char *this) {
    InitObject_2FBCC8(this);

    *(int *)(this + 0x2B0) = 0;
    *(float *)(this + 0x2D4) = 1.0f;
    *(char **)(this + 0xF0) = D_0044E8C8;
    *(int *)(this + 0x2B4) = 0;
    *(int *)(this + 0x2B8) = 0;
    *(int *)(this + 0x2BC) = 0;
    *(int *)(this + 0x2C0) = 0;
    *(int *)(this + 0x2C4) = 0;
    *(int *)(this + 0x2C8) = 0;
    *(int *)(this + 0x2D8) = 0;
    *(int *)(this + 0x2DC) = 0;

    return this;
}

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002EFCA8")))
int func_002EFCA8(char *this, char *src) {
    char *p;

    *(float *)(this + 0x2C4) = *(float *)(src + 0x40);
    p = *(char **)(this + 0x110);
    *(int *)(this + 0x2B0) = *(int *)(p + 0x16C);
    *(int *)(this + 0x2B4) = *(unsigned char *)(p + 0x170);
    *(int *)(this + 0x2B8) = *(signed char *)(p + 0x18C);
    *(short *)(this + 0x2BC) = *(unsigned char *)(p + 0x18D);
    *(unsigned char *)(this + 0x2BE) = *(unsigned char *)(p + 0x18E);
    *(unsigned char *)(this + 0x2BF) = *(unsigned char *)(p + 0x18F);
    *(unsigned char *)(this + 0x2C0) = *(unsigned char *)(p + 0x190);
    if ((unsigned int)*(int *)(this + 0x2B8) >= 2) {
        return 0;
    }
    if ((unsigned int)*(unsigned char *)(this + 0x2BF) >= 2) {
        return 0;
    }
    return (unsigned int)*(unsigned char *)(this + 0x2C0) < 2;
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002F00E0")))
int func_002F00E0(char *this) {
    char *p = *(char **)(this + 0x110);
    int n;

    *(float *)(this + 0x2B0) = *(float *)(p + 0x13C) * 0.01f;
    *(float *)(this + 0x2B4) = *(float *)(p + 0x140) * 0.01f;
    *(float *)(this + 0x2D0) = *(float *)(p + 0x144) * 0.01f;
    *(float *)(this + 0x2C8) = *(float *)(p + 0x148) * 0.1f;
    *(float *)(this + 0x2CC) = *(float *)(p + 0x14C) * 0.1f;
    *(float *)(this + 0x2DC) = *(float *)(p + 0x150) * 0.1f;
    n = *(unsigned char *)(p + 0x18C);
    *(unsigned char *)(this + 0x2E0) = n;
    *(unsigned char *)(this + 0x2E1) = *(unsigned char *)(p + 0x18D);
    *(unsigned char *)(this + 0x2E2) = *(unsigned char *)(p + 0x18E);
    if ((unsigned int)n >= 3) {
        func_002D9F68(this, D_0044EB50, *(unsigned char *)(this + 0x2E0));
    }
    *(float *)(this + 0x2B8) = *(float *)(this + 0x2B0);
    *(float *)(this + 0x2BC) = *(float *)(this + 0x2B4);
    *(float *)(this + 0x2D4) = *(float *)(this + 0x2D0);
    return 1;
}
