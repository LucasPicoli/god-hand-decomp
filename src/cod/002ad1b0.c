/* sn-2.95.3-136 matched TU. */

extern void func_00309000(void *a0);
extern char D_005CB3B0[];

__attribute__((section(".text.func_002AD1B0")))
void func_002AD1B0(void *a0, int a1) {
    char *b;
    char *p;
    int i;

    if (a1 == 0xFFFF && a0 != 0) {
        /* Materialise the base symbol first, then add 0x744 as a separate
           addu: writing `D_005CB3B0 + 0x744` directly folds the offset into
           the %hi/%lo reloc and drops an instruction. */
        b = D_005CB3B0;
        p = b + 0x744;
        for (i = 0x27F; i != -1; i--) {
            func_00309000(p);
            p += 0xAC;
        }
    }
}
