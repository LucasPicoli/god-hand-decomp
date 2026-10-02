/* TU: cOm71 [object] - recovered C++ class. */
#include "include_asm.h"

extern void func_002A8578(void *a0, void *a1, void *a2, float f, int a3, int t0, int t1);
extern float SetMotionStep(void *a0, float f);

__attribute__((section(".text.cOm71_SetMotionWait")))
void cOm71_SetMotionWait(void *a0) {
    int base = *(int *)((char *)a0 + 0x304);
    func_002A8578(a0, (void *)(*(int *)(base + 0x10) + base), 0, 0.0f, 5, 0, 0);
    SetMotionStep(a0, 1.0f);
}


__attribute__((section(".text.cOm71_SetMotionTurn")))
void cOm71_SetMotionTurn(void *a0) {
    int base = *(int *)((char *)a0 + 0x304);
    func_002A8578(a0, (void *)(*(int *)(base + 0x20) + base), 0, 0.0f, 5, 0, 0);
}


__attribute__((section(".text.cOm71_SetMotion100")))
void cOm71_SetMotion100(void *a0) {
    int base = *(int *)((char *)a0 + 0x304);
    func_002A8578(a0, (void *)(*(int *)(base + 0x48) + base), 0, 0.0f, 5, 0, 0);
}

