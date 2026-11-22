/* Trivial field setter (store-rotation order). */

__attribute__((section(".text.SFHDS_FinishFhd")))
void SFHDS_FinishFhd(void *a0) { *(int *)((char *)a0 + 0x0) = 0; *(int *)((char *)a0 + 0xc) = 0; *(int *)((char *)a0 + 0x90) = 0; }
