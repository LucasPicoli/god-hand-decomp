/* sn-2.95.3-136 matched TU. */

extern unsigned short D_0076E910;

__attribute__((section(".text.func_00387430")))
int func_00387430(short idx) {
    unsigned short flags;
    int result;
    int t;

    if (func_003779D0(idx)) {
        return 1;
    }
    flags = *(unsigned short *)((char *)&D_0076E910 + idx * 0xA0);
    if (flags != 0) {
        result = (flags & 2) ? 6 : 2;
        result = (flags & 4) ? (result | 8) : result;
        t = result;
        result = (flags & 0x10) | t;
        result = (flags & 0x8000) ? (result | 0x20) : result;
        return result;
    }
    return 0;
}
