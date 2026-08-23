/* sn-2.95.3-136 matched TU. */

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00381010")))
void func_00381010(char *a0, char *a1, unsigned char m) {
    int v;
    unsigned int w;
    if (*(int *)(a1 + 0x38) & 0x1000) {
        v = *(unsigned char *)(a0 + 4);
        if (v != 0) *(unsigned char *)(a0 + 4) = v - 1;
        else *(unsigned char *)(a0 + 4) = m;
    }
    if (*(int *)(a1 + 0x38) & 0x4000) {
        w = *(unsigned char *)(a0 + 4);
        if (w < m) *(unsigned char *)(a0 + 4) = w + 1;
        else *(unsigned char *)(a0 + 4) = 0;
    }
}
