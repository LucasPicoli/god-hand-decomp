/* sn-2.95.3-136 matched TU. */

extern void func_00290028(void *p);
extern unsigned int Forward30F348_31CFE0(void);
extern char D_00754C38[];

__attribute__((section(".text.func_00290110")))
void func_00290110(void *obj) {
    char *base = (char *)obj;
    char *end = base + 0x500;
    char *p = base;
    int *q;
    char *d;
    unsigned int i;

    do {
        func_00290028(p);
        p += 0x14;
    } while (p < end);

    *(int *)(base + 0x500) = 0;
    *(int *)(base + 0x504) = 0;
    *(int *)(base + 0x508) = 0;
    *(int *)(base + 0x50C) = 0;
    *(int *)(base + 0x55C) = 0;
    *(float *)(base + 0x548) = 1.0f;
    *(unsigned char *)(base + 0x53F) = Forward30F348_31CFE0() % 5;
    q = (int *)(base + 0x574);
    *(char *)(base + 0x53E) = 0;
    *(char *)(base + 0x540) = 0;
    *(char *)(base + 0x541) = 0;
    *(int *)(base + 0x560) = 0;
    *(int *)(base + 0x564) = 0;
    *(int *)(base + 0x568) = 0;
    *(int *)(base + 0x56C) = 0;
    *(int *)(base + 0x570) = 0;
    *(int *)(base + 0x588) = 0;
    *(int *)(base + 0x58C) = 0;
    *(int *)(base + 0x590) = 0;
    *(int *)(base + 0x594) = 0;
    for (i = 0; i < 2; i++) {
        *(int *)(base + 0x5AC + i * 4) = 0;
    }
    for (i = 0; i < 5; i++) {
        q[i] = 0;
    }
    *(char *)(base + 0x518) = 0;
    d = D_00754C38;
    *(char *)(d + 0x4) = 0;
    *(int *)(d + 0x8) = 0;
    *(int *)(d + 0xC) = 0;
    *(char *)(base + 0x5B5) = 0;
}
