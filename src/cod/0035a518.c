/* Byte-identical to RE4 PS2 (SLUS-21134) 0x002D1FC0 — shared engine code.
 * Zero-clears a 0x20-byte struct. The unusual store order (0x1E short first,
 * 0x1C short last in the jr delay slot) is reproduced by writing the field that
 * must land first LAST in source: the ee-gcc scheduler rotates the trailing
 * store to the front. */

__attribute__((section(".text.SFTIM_InitTcode")))
void SFTIM_InitTcode(void *a0) {
    *(int *)((char *)a0 + 0x0) = 0;
    *(int *)((char *)a0 + 0x4) = 0;
    *(int *)((char *)a0 + 0x8) = 0;
    *(int *)((char *)a0 + 0xC) = 0;
    *(int *)((char *)a0 + 0x10) = 0;
    *(int *)((char *)a0 + 0x14) = 0;
    *(int *)((char *)a0 + 0x18) = 0;
    *(short *)((char *)a0 + 0x1C) = 0;
    *(short *)((char *)a0 + 0x1E) = 0;
}
