/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
extern void func_00124EC0(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

__attribute__((section(".text.UpdateAttackState2F6_1161E0")))
void UpdateAttackState2F6_1161E0(void *a0) {
    cGameObj *s0 = a0;
    int v0;
    float one;
    s0->hitFlash = 5.0f;
    *(int *)((char *)s0 + 0x15F4) = *(int *)((char *)s0 + 0x15F4) | 0x2080;
    switch (s0->step) {
    case 0:
        *(short *)((char *)s0 + 0x5E0) = 0;
        *(short *)((char *)s0 + 0x5E2) = 0;
        func_001268F0(s0);
        Obj0000_Clear_Fields_640_648_124E58(s0);
        v0 = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x8D8) + v0, *(int *)(v0 + 0x8DC) + v0, 0, 0.0f, 0, 0);
        s0->step = s0->step + 1;
        /* fallthrough */
    case 1:
        one = 1.0f;
        func_00124EC0(s0);
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}
