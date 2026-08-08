/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_0037ABA0")))
void func_0037ABA0(void *a0, void *a1) {
    unsigned short f;
    int sel;

    if (*(int *)((char *)a0 + 0x38) & 0xA000) {
        f = **(unsigned short **)a1;
        sel = *(signed char *)((char *)a1 + 8);
        switch (sel) {
        case 2:
            if (f & 0x10) {
                f &= ~0x10;
                f |= 0x20;
            } else {
                f &= ~0x20;
                f |= 0x10;
            }
            break;
        case 3:
            if (f & 0x1) {
                f &= ~0x1;
                f |= 0x2;
            } else {
                f &= ~0x2;
                f |= 0x1;
            }
            break;
        case 5:
            if (f & 0x1) {
                f &= ~0x1;
                f |= 0x2;
            } else {
                f &= ~0x2;
                f |= 0x1;
            }
            break;
        case 6:
            if (f & 0x10) {
                f &= ~0x10;
                f |= 0x20;
            } else {
                f &= ~0x20;
                f |= 0x10;
            }
            break;
        case 0:
        case 7:
            f ^= 0x2;
            break;
        case 1:
        case 4:
        case 8:
            f ^= 0x1;
            break;
        default:
            break;
        }
        **(unsigned short **)a1 = f;
    }
}
