/* Byte-identical to RE4 PS2 (SLUS-21134) 0x002D3718 — shared engine code.
 * Initialises a few fields then fills 0x14..0x1C with 8 via a 3-iteration
 * down-counted loop (cc1 emits the R5900 short-loop nops itself). The loop
 * counter is written first in the for-init so it lands in $v1 and the pointer
 * in $v0, matching retail's register assignment. */

__attribute__((section(".text.sftrn_InitTrData")))
void sftrn_InitTrData(void *a0, int a1) {
    char *p = (char *)a0;
    int i;
    int *q;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0xC) = a1;
    *(int *)(p + 0x10) = 8;
    for (i = 2, q = (int *)(p + 0x1C); i >= 0; i--) {
        *q = 8;
        q--;
    }
    *(int *)(p + 0x20) = -1;
}
