/* Trivial field setter (store-rotation order). */

__attribute__((section(".text.mpslib_InitPack")))
void mpslib_InitPack(void *a0) { *(long long *)((char *)a0 + 0x0) = -1; *(int *)((char *)a0 + 0x8) = -1; *(int *)((char *)a0 + 0xc) = -1; }
