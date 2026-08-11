/* sn-2.95.3-136 matched TU. */

/* SN ProDG ee-gcc 2.95.3 matched TU. */

__attribute__((section(".text.cOmItem_setBlockObj")))
void cOmItem_setBlockObj(void *a0, signed char *a1) {
    long acc = 0;
    int i = 0;
    if (*a1 != 0) {
        do {
            acc |= (long)*a1 << (i * 8);
            i++;
            a1++;
            if (i >= 8) break;
        } while (*a1 != 0);
    }
    *(long *)((char *)a0 + 0x668) = acc;
}
