/* cOm71_SetMotionKokeru — play the "kokeru" (fall) motion 0x5 with two model
 * sub-pointers (fields 0x4C, 0x50), then set flag 0x8 at 0x600.  sn-2.95.3-136. */

#include "godhand/motion.h"

__attribute__((section(".text.cOm71_SetMotionKokeru")))
void cOm71_SetMotionKokeru(void *a0) {
    char *v0 = *(char **)((char *)a0 + 0x304);
    func_002A8578(a0, (char *)(*(int *)(v0 + 0x4C) + (int)v0),
                  (char *)(*(int *)(v0 + 0x50) + (int)v0), 0x5, 0.0f, 0, 0);
    *(int *)((char *)a0 + 0x600) |= 0x8;
}
