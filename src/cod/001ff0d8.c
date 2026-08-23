/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_001FF0D8")))
int func_001FF0D8(int *p) {
    unsigned long t;
    unsigned long b;
    if (p[1] != 0) {
        return 1;
    }
    t = p[2];
    b = (t >> 2) & 1;
    if (b != 0) {
        return 0;
    }
    return p[4] != 0;
}

__attribute__((section(".text.func_0031D108")))
float func_0031D108(unsigned int *seed) {
    unsigned int s;
    float f;
    s = *seed * 0x19660D + 0x3C6EF35F;
    *seed = s;
    *(unsigned int *)&f = (s & 0x7FFFFF) | 0x3F800000;
    return f + f - 2.0f - 1.0f;
}
