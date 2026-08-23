/* ee-2.9-991111 matched TU. */

/* compiler: ee-2.9-991111 ; extra keys: none */
__attribute__((section(".text.func_003BACA0")))
int func_003BACA0(int mode) {
    int r;
    r = 0;
    switch (mode) {
    case 0:
        while (*(volatile int *)0x10002010 < 0) ;
        r = 0;
        break;
    case 1:
        r = (unsigned int)*(volatile int *)0x10002010 >> 31;
        break;
    }
    return r;
}
