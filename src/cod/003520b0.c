/* Byte-identical to RE4 PS2 (SLUS-21134) 0x002C9CC8 — shared engine code.
 * Clears the first 0xC bytes, then initialises a sub-object at +0x10 via a base
 * pointer (a0+0x10): a 64-bit -1 at +0x10, -1 at +0x1C, 0 at +0x18. The zero
 * stores are written ascending so the scheduler rotates +0x8 to the front. */

__attribute__((section(".text.sfmpv_InitComplementPts")))
void sfmpv_InitComplementPts(void *a0) {
    char *p = (char *)a0;
    int *q = (int *)(p + 0x10);
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x8) = 0;
    *(long long *)q = -1;
    q[3] = -1;
    q[2] = 0;
}
