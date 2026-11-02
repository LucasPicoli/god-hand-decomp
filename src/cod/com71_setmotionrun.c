/* cOm71_SetMotionRun — play the run motion 0x5; when the global mode flag
 * D_00747A50 is 0x305, with a single model sub-pointer (field 0x14), otherwise
 * with a second one (field 0x18) as well.  sn-2.95.3-136. */

extern unsigned short D_00747A50;
#include "godhand/motion.h"

__attribute__((section(".text.cOm71_SetMotionRun")))
void cOm71_SetMotionRun(void *a0) {
    char *v0;
    if (D_00747A50 == 0x305) {
        v0 = *(char **)((char *)a0 + 0x304);
        func_002A8578(a0, (char *)(*(int *)(v0 + 0x14) + (int)v0), 0, 0x5, 0.0f, 0, 0);
    } else {
        v0 = *(char **)((char *)a0 + 0x304);
        func_002A8578(a0, (char *)(*(int *)(v0 + 0x14) + (int)v0),
                      (char *)(*(int *)(v0 + 0x18) + (int)v0), 0x5, 0.0f, 0, 0);
    }
}
