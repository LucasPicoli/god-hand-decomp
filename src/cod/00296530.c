/* sn-2.95.3-136 matched TU. */

extern int UpdateSequenceState_296C28(int);

__attribute__((section(".text.func_00296530")))
void func_00296530(int a0) {
    int flags;
    long t;

    flags = *(int *)(a0 + 0x8);
    t = flags;
    if (!(((unsigned long)t >> 3) & 1)) {
        if (flags & 1) {
            switch (*(signed char *)(a0 + 0x4)) {
            case 0:
                if (func_002965F0(a0) == 0) {
                    return;
                }
            case 1:
                if (func_00296818(a0) == 0) {
                    return;
                }
            case 2:
                if (func_00296958(a0) == 0) {
                    return;
                }
            case 3:
                if (UpdateSequenceState_296C28(a0) == 0) {
                    return;
                }
            case 4:
                func_00297038(a0);
            }
        }
    } else {
        func_00296DD8(a0);
    }
}
