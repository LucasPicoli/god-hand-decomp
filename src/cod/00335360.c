/* cygnus-2.96 matched TU. */

extern char D_003DA5F8[];

__attribute__((section(".text.lsc_Alloc")))
char *lsc_Alloc(void) {
    char *r = 0;
    int i;
    for (i = 0; i < 0x20; i++) {
        if (D_003DA5F8[i * 568] == 0) { r = &D_003DA5F8[i * 568]; break; }
    }
    return r;
}
