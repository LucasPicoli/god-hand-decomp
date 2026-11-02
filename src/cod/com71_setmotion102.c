/* cOm71_SetMotion102 — play motion 0x5 on the object's model (field 0x54).
 * sn-2.95.3-136. */

#include "godhand/motion.h"

__attribute__((section(".text.cOm71_SetMotion102")))
void cOm71_SetMotion102(void *a0) {
    char *v0 = *(char **)((char *)a0 + 0x304);
    func_002A8578(a0, (char *)(*(int *)(v0 + 0x54) + (int)v0), 0, 0x5, 0.0f, 0, 0);
}
