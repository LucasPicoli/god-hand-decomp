/* Trivial field setter (store-rotation order). */

__attribute__((section(".text.DTR_Start")))
void DTR_Start(void *a0) { *(signed char *)((char *)a0 + 0x1) = 1; *(int *)((char *)a0 + 0x3c) = 0; }
