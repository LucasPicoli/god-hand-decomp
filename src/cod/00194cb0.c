/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00194CB0")))
void func_00194CB0(char *o) {
    int t;
    unsigned char s = *(unsigned char *)(o + 0x2F6);
    unsigned char u;
    if (s == 0) goto init;
    if (s == 1) goto dec;
    return;
init:
    *(short *)(o + 0xAF0) = 0;
    *(unsigned char *)(o + 0x2F6) = 1;
    *(unsigned char *)(o + 0x2F7) = 0;
dec:
    t = *(unsigned short *)(o + 0xAF0) - 1;
    *(short *)(o + 0xAF0) = t;
    if ((short)t >= 0) return;
    u = *(unsigned char *)(o + 0x2F5);
    *(unsigned char *)(o + 0x2F5) = 2;
    *(unsigned char *)(o + 0xAF2) = u;
    *(unsigned char *)(o + 0x2F6) = 0;
    *(unsigned char *)(o + 0x2F7) = 0;
}
