/* cActionButtonUnit_setExit — if the button state (a0+0x35) is 1, set a global
 * exit flag (0x20000000) in the manager at D_003BD6E8+0xF30; then always
 * notify func_001F7228.  Call shape (notify outside the guard) recovered via
 * decomp-permuter.  sn-2.95.3-136. */

extern void *D_003BD6E8;
extern void func_001F7228(void *);

__attribute__((section(".text.cActionButtonUnit_setExit")))
void cActionButtonUnit_setExit(void *a0) {
    if (*(unsigned char *)((char *)a0 + 0x35) == 1) {
        void *p = D_003BD6E8;
        *(int *)((char *)p + 0xF30) |= 0x20000000;
    }
    func_001F7228(a0);
}
