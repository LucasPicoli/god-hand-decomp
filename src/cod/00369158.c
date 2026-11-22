/* Byte-identical to RE4 PS2 (SLUS-21134) 0x002DAB68 — shared engine code.
 * Fills a 0x28-byte struct with -1; the leading 0x10 bytes are written as two
 * 64-bit stores (the EE merges adjacent -1 words into sd). */

__attribute__((section(".text.mpslib_InitPket")))
void mpslib_InitPket(void *a0) {
    char *p = (char *)a0;
    *(long long *)(p + 0x0) = -1;
    *(long long *)(p + 0x8) = -1;
    *(int *)(p + 0x10) = -1;
    *(int *)(p + 0x14) = -1;
    *(int *)(p + 0x18) = -1;
    *(int *)(p + 0x1C) = -1;
    *(int *)(p + 0x20) = -1;
    *(int *)(p + 0x24) = -1;
}
