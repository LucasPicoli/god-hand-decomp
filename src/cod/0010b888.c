/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_00126770(void *a0);
#include "godhand/motion.h"
#include "godhand/pl00.h"
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void func_001CF3A8(void *a0);

__attribute__((section(".text.pl00_SubscreenMode")))
void pl00_SubscreenMode(void *a0, int a1) {
    pl00 *s0 = a0;
    int v0;
    if (a1 != 0) {
        s0->base.mode = 5;
        *(unsigned char *)((char *)s0 + 0x420) = *(unsigned char *)((char *)s0 + 0x420) | 1;
        s0->base.hitFlash = 5.0f;
        s0->base.phase = 0;
        s0->base.step = 0;
        s0->base.stepArg = 0;
    } else {
        *(unsigned char *)((char *)s0 + 0x420) = *(unsigned char *)((char *)s0 + 0x420) & 0xFE;
        pl00_clearMotionCam(s0, 0, 0);
        func_00126770(s0);
        v0 = *(int *)((char *)s0 + 0x304);
        s0->base.mode = 0;
        s0->base.phase = 0;
        s0->base.step = 0;
        s0->base.stepArg = 0;
        func_002A8578(s0, *(int *)(v0 + 0x28) + v0, *(int *)(v0 + 0x2C) + v0, 0, 0.0f, 0, 0);
        moveMotion(s0);
        cModel_calcParts(s0);
        IK_InverseKinematics((char *)s0 + 0x448, s0);
        cModel_calcWorldParts(s0);
        if (*(int *)((char *)s0 + 0x6A8) != 0) {
            func_001CF3A8(*(void **)((char *)s0 + 0x6A8));
            cModel_calcParts(*(void **)((char *)s0 + 0x6A8));
        }
    }
}

__attribute__((section(".text.pl00_SubscreenMotSet")))
void pl00_SubscreenMotSet(void *a0, int a1) {
    pl00 *s0 = a0;
    func_001269E0(a0, a1, 1);
    s0->base.mode = 5;
    s0->base.step = 2;
    s0->base.phase = 0;
    s0->base.stepArg = 0;
}
