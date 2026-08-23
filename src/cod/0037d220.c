/* sn-2.95.3-136 matched TU. */

extern char D_0076B9C0[];

__attribute__((section(".text.func_0037D220")))
char *func_0037D220(unsigned char mask, short id) {
    char *p = D_0076B9C0;
    int e = (int)D_0076B9C0 + 0xF00;
    do {
        if (*(unsigned short *)p != 0) {
            if ((*(unsigned char *)(p + 0xC) & 0x10) == 0) {
                if ((*(unsigned char *)(p + 0xD) & mask) != 0) {
                    if (*(short *)(p + 0x20) == id) return p;
                }
            }
        }
        p += 0x50;
    } while ((int)p < e);
    return 0;
}
