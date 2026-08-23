/* sn-2.95.3-136 matched TU. */

extern int D_00747A10;

__attribute__((section(".text.SetEventFrame")))
void SetEventFrame(int n) {
    if (n < 2) {
        D_00747A10 = 2;
    } else {
        D_00747A10 = n;
    }
}

__attribute__((section(".text.func_002ACC28")))
void func_002ACC28(int *p, int m, int on) {
    if (on != 0) {
        p[0] = p[0] | m;
    } else {
        p[0] = p[0] & ~m;
    }
}

__attribute__((section(".text.func_0031D098")))
unsigned int func_0031D098(unsigned int *p) {
    unsigned int v = *p * 0x19660D + 0x3C6EF35F;
    *p = v;
    return v;
}

__attribute__((section(".text.func_002744B8")))
int func_002744B8(unsigned char *p) {
    unsigned int t;
    if ((*(int *)(p + 0x564) ^ 0x211) != 0) {
        return 0;
    }
    t = *(unsigned int *)(p + 0x16D4) & 0x20;
    return 0 < t;
}
