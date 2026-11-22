/* Byte-identical to RE4 PS2 (SLUS-21134) 0x00184720 — shared engine code.
 * Returns (a0->0x14 << 11) sign-extended into 32 bits. The unsigned-long-long
 * cast + 0xFFFFFFFF mask force ee-gcc's 64-bit dsll + truncate + sign-extend. */

__attribute__((section(".text.dvci_getnumtr_lower")))
int dvci_getnumtr_lower(void *a0) {
    return (int)(((unsigned long long)*(int *)((char *)a0 + 0x14) << 11) & 0xFFFFFFFFu);
}
