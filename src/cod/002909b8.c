/* sn-2.95.3-136 matched TU. */

extern char D_0071B940[];
extern unsigned int D_00741960[];

__attribute__((section(".text.func_003005D8")))
void func_003005D8(char *p) {
    unsigned int i = (unsigned int)(p - D_0071B940) / 0x260;
    D_00741960[i >> 5] |= 0x80000000U >> (i & 0x1F);
}

__attribute__((section(".text.cEmManage_ChkActiveEm")))
int cEmManage_ChkActiveEm(char *self, void *em) {
    char *node;
    if (em == 0) return 0;
    node = *(char **)(self + 0x500);
    while (node != 0) {
        if (*(void **)(node + 8) == em) {
            if (*(unsigned char *)(node + 0x10) == 1) return 1;
        }
        node = *(char **)(node + 4);
    }
    return 0;
}
