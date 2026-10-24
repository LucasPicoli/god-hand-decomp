/* ee-2.9-991111 matched TU. */

extern unsigned long GsGetIMR(void);
extern unsigned long GsPutIMR(unsigned long mask);

__attribute__((section(".text.func_00396008")))
unsigned long func_00396008(unsigned long newMask) {
    unsigned long old = GsGetIMR();
    GsPutIMR(newMask);
    return old;
}
