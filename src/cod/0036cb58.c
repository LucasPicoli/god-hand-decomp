/* Byte-identical to RE4 PS2 (SLUS-21134) 0x002DE468 — shared engine code.
 * Constant-initialises two sub-objects (ints at a0+0x8, bytes at a0+0x14) plus
 * a flag at a0+0x4. Reproducing retail requires (a) base pointers for each
 * sub-object — retail uses `addiu v1,a0,0x14` / `addiu v0,a0,0x8` — and (b)
 * naming the constants so the compiler materialises 0x1F before 0x64, matching
 * retail's register assignment (0x64 -> $a1). */

__attribute__((section(".text.sfxalp_InitHn")))
void sfxalp_InitHn(void *a0) {
    char *p = (char *)a0;
    signed char *s2 = (signed char *)(p + 0x14);
    int *s1 = (int *)(p + 0x8);
    int c1f = 0x1F, c64 = 0x64, c1 = 1, c40 = 0x40, cm80 = -0x80;
    s1[2] = c64;
    s1[1] = c1f;
    s1[0] = 0;
    *(int *)(p + 0x4) = c1;
    s2[2] = cm80;
    s2[1] = c40;
    s2[0] = 0;
}
