/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002C0ED0")))
int func_002C0ED0(int base, unsigned int sel) {
    int *p = (int *)(base + 0x50);
    switch (sel) {
    case 0: {
        int zero = 0;
        return *p < zero;
    }
    case 1: {
        int mask = 0x20000000;
        return (*p & mask) != 0;
    }
    case 2: {
        int mask = 0x10000000;
        return (*p & mask) != 0;
    }
    case 3: {
        int f = *p;
        int mask = 0x40000000;
        int zero = 0;
        return (f < zero) ^ ((f & mask) != 0);
    }
    case 4: {
        int mask = 0x8000000;
        return (*p & mask) != 0;
    }
    case 5: {
        int f = *p;
        int mask = 0x8000000;
        int r = 0;
        if (f < 0) {
            r = (f & mask) != 0;
        }
        return r;
    }
    case 6: {
        int mask = 0x4000000;
        return (*p & mask) != 0;
    }
    case 7: {
        int mask = 0x2000000;
        return (*p & mask) != 0;
    }
    default:
        return 0;
    }
}
