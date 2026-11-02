/* cOm71_SetMotion010 — play motion 0xA on the object's model: resolve the
 * model base (*(a0+0x304)) + its 0x38 field, and forward to the motion engine
 * func_002A8578 with rate 0 and blend 0.0.  sn-2.95.3-136. */

#include "godhand/motion.h"

__attribute__((section(".text.cOm71_SetMotion010")))
void cOm71_SetMotion010(void *a0) {
    char *v0 = *(char **)((char *)a0 + 0x304);
    func_002A8578(a0, (char *)(*(int *)(v0 + 0x38) + (int)v0), 0, 0xA, 0.0f, 0, 0);
}
