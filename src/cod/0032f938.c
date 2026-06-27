/* cygnus-2.96 matched TU. */

extern void func_003A52F0(void *p, int v, int n);
extern void func_0035FF98(int);
extern int D_003EE800;
extern void func_0036CB58(int);
extern int D_003F1EC8;

__attribute__((section(".text.func_0032F938")))
void func_0032F938(unsigned char *a0) {
    func_003A52F0(a0, 0, 0x18B8);
    *(int *)(a0 + 0x210) = 1;
    *(int *)(a0 + 0x1894) = 1;
    *(short *)(a0 + 0x189A) = 1;
    *(short *)(a0 + 0x1898) = 0;
    *(short *)(a0 + 0x189C) = 0;
    *(short *)(a0 + 0x189E) = 0;
    a0[0xC] = 1;
}

__attribute__((section(".text.func_0034A6F8")))
int func_0034A6F8(int a0, int *a1, int *a2) {
    int *r = func_0034B618(a0);
    if (r == 0) return -1;
    *a1 = r[3];
    *a2 = r[4];
    return 0;
}

__attribute__((section(".text.func_0035FEF0")))
int func_0035FEF0(void) {
    int *s0 = (int *)func_0035FF48();
    if (s0 == 0) return 0;
    func_0035FF98((int)s0);
    D_003EE800 += 1;
    *s0 = 1;
    return (int)s0;
}

__attribute__((section(".text.func_0036CAB0")))
int func_0036CAB0(void) {
    int *s0 = (int *)func_0036CB08();
    if (s0 == 0) return 0;
    func_0036CB58((int)s0);
    D_003F1EC8 += 1;
    *s0 = 1;
    return (int)s0;
}
