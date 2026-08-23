/* sn-2.95.3-136 matched TU. */

extern char *D_00773250[];
extern int D_0076A7A4;

__attribute__((section(".text.func_0037C630")))
int func_0037C630(char *o) {
    unsigned int k;
    char *r;
    r = D_00773250[*(short *)(o + 0x20)];
    k = (*(unsigned char *)(*(int *)(r + 4) + 0xB) >> 2) & 3;
    if (k >= 2) return 0;
    if (D_0076A7A4 == 2) return (((*(unsigned short *)(o + 0x2E) >> 2) ^ 1) & 1);
    return (((*(unsigned short *)(o + 0x2E) >> 1) ^ 1) & 1);
}

__attribute__((section(".text.func_002DA940")))
float func_002DA940(float a, float b) {
    float d = a - b;
    if (d > 3.14159274f) return d - 6.28318548f;
    if (d < -3.14159274f) return d + 6.28318548f;
    return d;
}
