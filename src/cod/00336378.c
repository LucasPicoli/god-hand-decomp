/* cygnus-2.96 matched TU. */

/* compiler: cygnus-2.96 ; extra keys: c_flags_drop -f=-freorder-blocks (score with --drop-freorder-blocks) */
__attribute__((section(".text.func_00336378")))
int func_00336378(char *p, char **endp, int base) {
    int acc;
    unsigned char c;
    int d;
    acc = 0;
    for (;;) {
        c = *(unsigned char *)p;
        if ((unsigned int)(c - '0') < 10) {
            d = (signed char)c - 0x30;
        } else if ((unsigned int)(c - 'a') < 6) {
            d = (signed char)c - 0x57;
        } else if ((unsigned int)(c - 'A') < 6) {
            d = (signed char)c - 0x37;
        } else {
            break;
        }
        acc = acc * base + d;
        p++;
    }
    *endp = p;
    return acc;
}
