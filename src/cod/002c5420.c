/* ee-2.9-990721 matched TU. */

extern char *D_00754C38;

__attribute__((section(".text.cScrArray_SearchScroll")))
void *cScrArray_SearchScroll(void *a0, long key) {
    char **end = *(char ***)(D_00754C38 + 0x8);
    char **p = *(char ***)(D_00754C38 + 0x4);
    char **lim;
    char *s;
    if (p < end) {
        lim = end;
        do {
            s = *p;
            p++;
            if (*(long *)(*(char **)(s + 0x320) + 8) == key) return s;
        } while (p < lim);
    }
    return 0;
}
