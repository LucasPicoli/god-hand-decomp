#include "godhand/cGameObj.h"

/* cGameObj_getLockOnPos — virtual dispatch: call the handler at (*(a0+0x214))->0x84 with
 * a0 advanced by the short offset at +0x80.  The do-while block boundaries +
 * pointer-copy chain are load-bearing for the instruction schedule (recovered
 * via decomp-permuter); a naive form is 3 words off.  sn-2.95.3-136. */

/* Calls the lock-on method of the object's method table. The nested
 * do-while blocks and the pointer copies keep the instruction schedule. */
__attribute__((section(".text.cGameObj_getLockOnPos")))
void cGameObj_getLockOnPos(cGameObj *self)
{
    cGameObjVt *vt = self->vt;
    cGameObjVt *new_var3;
    cGameObjVt *new_var2;
    cGameObjVt *new_var;
    void (**new_var4)(void *);
    short ofs = vt->lockOnDelta;
    new_var3 = vt;
    new_var2 = new_var3;
    new_var = new_var2;
    do { do { (*(new_var4 = &new_var->lockOn))((char *)self + ofs); } while (0); } while (0);
}
