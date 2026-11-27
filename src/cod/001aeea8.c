/* func_001AEEA8 — stash a1 at +0x986; when phase byte +0x2F5 == 1, run the
 * 0x30F348 handler and fire func_002A8578 against record field 0x14 or 0x18
 * depending on the handler's low bit.  sn-2.95.3-136. */

#include "godhand/motion.h"
#include "godhand/cObj.h"
extern int irand(void *a0);

__attribute__((section(".text.func_001AEEA8")))
void func_001AEEA8(void *a0, int a1){
    cObj *s0 = a0;
    int v0;
    *(short *)((char *)s0 + 0x986) = (short)a1;
    if (s0->phase == 1) {
        if (irand(s0) & 1) {
            v0 = *(int *)((char *)s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x14) + v0, 0, 0, 0.0f, 0, 0);
        } else {
            v0 = *(int *)((char *)s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x18) + v0, 0, 0, 0.0f, 0, 0);
        }
    }
}
