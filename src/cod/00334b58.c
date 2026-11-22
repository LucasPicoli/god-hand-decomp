/* Byte-identical to RE4 PS2 (SLUS-21134) 0x00197C20 — shared engine code.
 * Clamps (a0->0x28 << 11) down to the 64-bit field at a0->0x8, then returns
 * the low 32 bits sign-extended. The 64-bit shift is kept (not folded to sll)
 * because the value feeds the unsigned 64-bit compare/min. */

__attribute__((section(".text.htci_getnumtr_lower")))
int htci_getnumtr_lower(void *a0) {
    unsigned long long t = (unsigned long long)((long long)*(int *)((char *)a0 + 0x28) << 11);
    unsigned long long u = *(unsigned long long *)((char *)a0 + 0x8);
    if (u < t) t = u;
    return (int)(t & 0xFFFFFFFFu);
}
