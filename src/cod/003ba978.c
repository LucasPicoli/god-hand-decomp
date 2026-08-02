/* ee-2.9-991111 matched TU. */

/* clone */



__attribute__((section(".text.setD4_CHCR")))
void setD4_CHCR(int a0) {
    int r = func_003B63A0();
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 | 0x10000;
    *(volatile unsigned int *)0x1000B000 = a0;
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 & 0xFFFEFFFF;
    if (r != 0) {
        func_003B63F0();
    }
}
