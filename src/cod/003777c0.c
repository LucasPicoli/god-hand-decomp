/* sn-2.95.3-136 matched TU. */

extern unsigned short D_0076E910;
extern unsigned short D_0076B340;

__attribute__((section(".text.func_003777C0")))
void func_003777C0(void) {
    int i;
    int j;
    char *ea;
    char *eb;
    unsigned short x;
    unsigned short y;
    unsigned short t;

    for (i = 0; i < 2; i++) {
        ea = (char *)(i * 0xA0 + (int)&D_0076E910);
        eb = (char *)(i * 0x100 + (int)&D_0076B340);
        x = *(unsigned short *)ea;
        if (x == 0) {
            continue;
        }
        if (*(int *)(ea + 4) != *(int *)(eb + 4)) {
            continue;
        }
        if (*(unsigned short *)eb & 0x8000) {
            if (x & 0x8000) {
                continue;
            }
            *(unsigned short *)ea = x | 0x8000;
        } else {
            if (x & 0x8000) {
                *(unsigned short *)ea = x & 0x7FFF;
            }
            if (*(unsigned short *)eb & 8) {
                t = *(unsigned short *)ea;
                if (!(t & 8)) {
                    *(unsigned short *)ea = t | 8;
                }
            }
            y = *(unsigned short *)eb;
            if (y & 0x200) {
                *(unsigned short *)ea = 0;
                *(int *)(ea + 4) = 0;
                for (j = 7; j >= 0; j--) {
                    *(int *)(ea + 0x18 + j * 4) = 0;
                }
            } else {
                t = *(unsigned short *)ea;
                if (t & 2) {
                    continue;
                }
                if (y & 2) {
                    *(unsigned short *)ea = t | 2;
                }
            }
        }
    }
}
