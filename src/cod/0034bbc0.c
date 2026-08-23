/* cygnus-2.96 matched TU. */

__attribute__((section(".text.sfbuf_MakeBufPtr")))
void sfbuf_MakeBufPtr(int *d, int *s, int base) {
    int i = 0;
    do {
        int v = s[i];
        d[i] = base;
        i++;
        base = base + v;
    } while (i < 8);
}

__attribute__((section(".text._IO_init")))
void _IO_init(int *fp, int flags) {
    fp[0] = flags | 0xFBAD0000;
    fp[7] = 0;
    fp[8] = 0;
    fp[3] = 0;
    fp[1] = 0;
    fp[2] = 0;
    fp[4] = 0;
    fp[5] = 0;
    fp[6] = 0;
    fp[13] = 0;
    fp[9] = 0;
    fp[10] = 0;
    fp[11] = 0;
    fp[12] = 0;
    *(short *)((char *)fp + 0x48) = 0;
}
