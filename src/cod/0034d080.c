/* Trivial field setter (store-rotation order). */

__attribute__((section(".text.SFHDS_InitFhd")))
void SFHDS_InitFhd(void *a0) { *(int *)((char *)a0 + 0x0) = 0; *(int *)((char *)a0 + 0x4) = 0; *(int *)((char *)a0 + 0x8) = 0; *(int *)((char *)a0 + 0xc) = 0; *(int *)((char *)a0 + 0x90) = 0; }
