/* cActionButtonUnit_setExit — if the button state (a0+0x35) is 1, set a global
 * exit flag (0x20000000) in the game object's prompt screen flags; then always
 * notify cActionButtonEnt_reset.  Call shape (notify outside the guard) recovered via
 * decomp-permuter.  sn-2.95.3-136. */
#include "godhand/DispMgr.h"

extern void cActionButtonEnt_reset(void *);

__attribute__((section(".text.cActionButtonUnit_setExit")))
void cActionButtonUnit_setExit(void *a0) {
    if (*(unsigned char *)((char *)a0 + 0x35) == 1) {
        D_003BD6E8->screen.flags |= 0x20000000;
    }
    cActionButtonEnt_reset(a0);
}
