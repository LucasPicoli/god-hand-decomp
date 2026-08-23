/* cygnus-2.96 matched TU. */

/* compiler: cygnus-2.96 ; extra keys: none */
__attribute__((section(".text.SFD_CalcYccPlane")))
void SFD_CalcYccPlane(char *buf, int w, int h, char *out) {
    int mw;
    int mh;
    int bw;
    int bh;
    char *p;

    mw = (w + 15) / 16;
    bw = (mw * 16 + 63) / 64;
    bh = (mw * 8 + 63) / 64;
    mh = (h + 15) / 16;
    *(short *)(out + 0xE) = bw * 64;
    *(short *)(out + 0xC) = bh * 64;
    *(int *)(out + 0x8) = (int)buf;
    p = buf + bw * mh * 1024;
    *(int *)(out + 0x0) = (int)p;
    *(int *)(out + 0x4) = (int)(p + bh * mh * 512);
}

__attribute__((section(".text.func_00366678")))
void func_00366678(int *p) {
    int h = p[2] / 16;
    int w = p[3] / 32;
    unsigned char *init = (unsigned char *)p[1];
    unsigned char *base;
    int i, j, k, m;
    unsigned char *s, *d;
    if (h > 0) {
        base = init;
        i = h;
        do {
            d = base + 3;
            s = d + (w << 10) - 1;
            for (j = 0; j < w; j++) {
                for (k = 0; k < 16; k++) {
                    for (m = 15; m >= 0; m--) {
                        *d = (*s >> 1) + 1;
                        s += 4;
                        d += 4;
                    }
                }
            }
            base += w << 11;
        } while (--i != 0);
    }
}
