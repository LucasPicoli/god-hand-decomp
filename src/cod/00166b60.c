/* sn-2.95.3-136 matched TU. */

extern void cIDBase_trans();

__attribute__((section(".text.func_00166B60")))
void func_00166B60(char *a0) {
    switch (*(signed char *)(a0 + 0x5A)) {
    case 2:
    case 3:
        cIDBase_trans(a0 + 0xE0);
        /* fall through */
    case 0:
    case 1:
    case 4:
    default:
        cIDBase_trans(a0);
    }
}
