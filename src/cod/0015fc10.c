/* sn-2.95.3-136 matched TU. */

extern int func_003950F8(int a0, int a1);
extern void classCFILTER_TAG_initialize(void *);
extern void classCFILTER_TAG_Filter_main(void *);
extern int D_00566E30;
extern int D_00752D08;
extern int D_00747A2C;
extern char D_00586C00;

/* sn-2.95.3-136 matched TU. The busy-wait do/while is a CALL-loop
   (jal func_003950F8 in the body) -> one errata pad nop
   (needs --call-loop-pad).
   `base = &D_00747A2C; base[1]` materialises the symbol address in a register
   (lui/addiu) instead of folding %lo into the load, matching retail. */









__attribute__((section(".text.func_0015FC10")))
void func_0015FC10(void) {
    int *base;

    D_00566E30 = 1;
    do {
        D_00566E30 = func_003950F8(1, 0);
    } while (D_00566E30 != 0);

    base = &D_00747A2C;
    D_00752D08 = *(volatile int *)0x10000800;

    if ((base[1] & 0x04000000) == 0) {
        classCFILTER_TAG_initialize(&D_00586C00);
        classCFILTER_TAG_Filter_main(&D_00586C00);
    }

    D_00752D08 = D_00752D08 - *(volatile int *)0x10000800;
}
