/* sn-2.95.3-136 matched TU. */

extern int D_00747A0C;
extern char *D_0077E524;
extern char *D_0077E52C;

__attribute__((section(".text.cEmManage_GetEm")))
void *cEmManage_GetEm(char *self, unsigned char id) {
    char *node;
    char *em;
    if (id == 0xFF) return 0;
    node = *(char **)(self + 0x500);
    while (node != 0) {
        em = *(char **)(node + 8);
        if (*(unsigned short *)(em + 0x640) == (unsigned short)id) return em;
        node = *(char **)(node + 4);
    }
    return 0;
}

__attribute__((section(".text.cMessage_getRubyAddr")))
void *cMessage_getRubyAddr(char *a0, unsigned short code) {
    if (D_00747A0C == 0) {
        int i = (code >> 12) * 4;
        int j = (code & 0xFFF) * 8;
        char *base = *(char **)(a0 + i);
        int off = *(int *)(base + j + 8);
        if (off != 0) return base + off;
        return 0;
    }
    return 0;
}

__attribute__((section(".text.func_003B2500")))
void func_003B2500(int id) {
    if (id < 0) {
        *(int *)(D_0077E524 + (id & 0x7FFFFFFF) * 12) = 0;
    } else {
        *(int *)(D_0077E52C + id * 12) = 0;
    }
}
