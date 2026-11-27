/* SN ProDG ee-gcc 2.95.3 matched TU. */

#include "godhand/motion.h"
#include "godhand/globals.h"
#include "godhand/cObj.h"
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern void func_00123938(void *a0, int a1);

__attribute__((section(".text.UpdateStatePhase2F6_10CC58")))
void UpdateStatePhase2F6_10CC58(void *a0) {
    cObj *s0 = a0;
    int v0;
    int v1;
    switch (s0->step) {
    case 0:
        v0 = *(int *)((char *)s0 + 0x304);
        *(short *)((char *)s0 + 0x5E0) = 0;
        *(short *)((char *)s0 + 0x5E2) = 0;
        func_002A8578(s0, *(int *)(v0 + 0x220) + v0, *(int *)(v0 + 0x278) + v0, 3, 0.0f, 0, 0);
        *(int *)((char *)s0 + 0x15B0) = 0x10;
        s0->step = s0->step + 1;
        /* fallthrough */
    case 1:
        *(float *)((char *)s0 + 0x15F0) = D_003BD48C;
        v1 = *(int *)((char *)s0 + 0x15B0);
        if (v1 != 0) {
            *(int *)((char *)s0 + 0x15B0) = v1 - 1;
            InvokeVirtualAtField214AndForward_124E68(s0, 0.19634954f);
        }
        if (moveMotion(s0) != 0) {
            s0->mode = 0;
            s0->phase = 0;
            s0->step = 0;
            s0->stepArg = 0;
        }
        break;
    }
    func_00123938(s0, 1);
}
