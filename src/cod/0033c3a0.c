/* cygnus-2.96 matched TU. */

/* compiler: cygnus-2.96 ; extra keys: c_flags_drop ["-f=-freorder-blocks"] */
__attribute__((section(".text.func_0033C3A0")))
int func_0033C3A0(unsigned char *a0) {
    unsigned char *p;
    p = a0;
    if (p[0] == 0xB) {
        if (p[1] == 0x77) {
            return 1;
        }
    }
    if (p[0] == 0x77) {
        if (p[1] == 0xB) {
            return 1;
        }
    }
    if (p[0x10] == 0xB) {
        if (p[0x11] == 0x77) {
            return 1;
        }
    }
    if (p[0x10] == 0x77) {
        if (p[0x11] == 0xB) {
            return 1;
        }
    }
    return 0;
}
