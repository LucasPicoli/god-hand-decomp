/* Trivial field setter (store-rotation order). */

__attribute__((section(".text.sfply_InitFlowCnt")))
void sfply_InitFlowCnt(void *a0) { *(long long *)((char *)a0 + 0x0) = 0; *(long long *)((char *)a0 + 0x8) = 0; *(long long *)((char *)a0 + 0x10) = 0; }
