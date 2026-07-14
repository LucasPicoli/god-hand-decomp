/* sn-2.95.3-136 matched TU. */

extern void sceVu0UnitMatrix(void *m);
extern void func_002CD638(void);
extern void func_002CA220(void *a);
extern void func_002CA390(void *a, int b);
extern char D_005FFD80[];
extern char D_00601180[];
extern char D_005FEFF0[];
extern char D_005FFCF0[];

__attribute__((section(".text.func_002C9F58")))
void func_002C9F58(void *arg) {
    char *s = (char *)arg;
    char *p;
    float z;
    float one;
    int m;
    int i;

    z = 0.0f;
    one = 1.0f;

    *(int *)(s + 0x44) = 0;
    *(short *)(s + 0x12C) = 0;
    *(char **)(s + 0x34) = D_005FFD80;
    *(char **)(s + 0x38) = D_00601180;
    *(char **)(s + 0x3C) = D_005FEFF0;
    *(char **)(s + 0x40) = D_005FFCF0;
    *(unsigned int *)(s + 0x5C) = 0x80000000;
    *(unsigned int *)(s + 0x58) = 0x80000000;
    *(float *)(s + 0xC8) = z;
    *(unsigned int *)(s + 0x50) = 0x80000000;
    *(float *)(s + 0xC4) = z;
    *(int *)(s + 0x128) = -2;
    *(float *)(s + 0xC0) = z;
    *(float *)(s + 0xCC) = one;

    sceVu0UnitMatrix(s + 0xD0);

    *(int *)(s + 0x110) = 0;

    m = -1;
    p = s + 0x160;
    i = 0xF;
    for (; i >= 0; i--) {
        *(short *)(p + 0x2) = m;
        *(short *)(p + 0x0) = m;
        *(int *)(p + 0x4) = 0;
        p += 8;
    }

    *(int *)(s + 0x1E0) = 0;
    func_002CD638();
    func_002CA220(s);
    *(int *)(s + 0x130) = -1;
    func_002CA390(s, 0);
}
