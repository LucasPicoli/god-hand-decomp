/* cygnus-2.96 matched TU. */

__attribute__((section(".text.SFSET_SetCond")))
void SFSET_SetCond(void *a0, int a1, int a2) {
    if (sfset_IsCondValid()) {
        ((int *)a0)[a1 + 0xA0C/4] = a2;
    }
}
