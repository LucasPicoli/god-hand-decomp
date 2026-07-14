/* sn-2.95.3-136 matched TU. */

extern void cIDBase_restartAnim(void *);

__attribute__((section(".text.func_0013E010")))
void func_0013E010(char *a0) {
    unsigned short i;
    unsigned short j;
    int off;
    char *b;

    for (i = 0; i < 8; i++) {
        off = i * 0x50;
        cIDBase_restartAnim(a0 + (off + 0x90));
        *(char *)(off + (int)a0 + 0xAC) = 1;
    }

    b = a0 + 0x33C;
    for (j = 0; j < 8; j++) {
        b[j] = -1;
    }
}
