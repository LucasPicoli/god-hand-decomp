/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002A7CA0")))
unsigned char func_002A7CA0(char *a0, float *a1) {
    float *v0 = (float *)(a0 + 0x520);
    if (a1 != v0) {
        a1[0] = *(float *)(a0 + 0x520);
        a1[1] = v0[1];
        a1[2] = v0[2];
    }
    return *(unsigned char *)(a0 + 0x530);
}
