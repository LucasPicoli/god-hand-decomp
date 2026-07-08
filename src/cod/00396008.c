/* ee-2.9-991111 matched TU. */

extern int GsGetIMR(void);
extern void GsPutIMR(int mask);

__attribute__((section(".text.func_00396008")))
int func_00396008(int newMask) {
    int old = GsGetIMR();
    GsPutIMR(newMask);
    return old;
}
