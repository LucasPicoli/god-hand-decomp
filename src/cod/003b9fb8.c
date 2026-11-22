/* Trivial field setter (store-rotation order). */

__attribute__((section(".text.ac3cnv_reset")))
void ac3cnv_reset(void *a0) { *(int *)((char *)a0 + 0x4) = 0; *(int *)((char *)a0 + 0x1c) = 0; *(int *)((char *)a0 + 0x20) = 0; *(int *)((char *)a0 + 0x24) = 0; }
