/* SN ProDG ee-gcc 2.95.3 matched TU. */
#define CGAMEOBJ_NO_TYPEDEF             /* this TU calls the constructor cGameObj */
#include "godhand/cGameObj.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/globals.h"

extern int D_007854C8;
extern void cGameObj__tf(void);
extern void SetField_0_4_8_31EEA8(void *, void *, void *);
extern void cObjBase__tf(void);
#include "godhand/motion.h"
#include "godhand/cObj.h"
extern void cObjBase_addNullSpeed_Rotation(void *, float);
extern void cObjBase_addNullSpeed(void *, float);

__attribute__((section(".text.IsStateByteIdle_10B5F0")))
int IsStateByteIdle_10B5F0(unsigned char *a0) {
    int c;
    if (a0[0x2F4] != 0)
        return 0;
    c = a0[0x2F5];
    if (c != 0 && c != 0xA)
        return 0;
    return 1;
}

__attribute__((section(".text.cPlBase")))
void *cPlBase(void *a0) {
    void *r;
    cGameObj(a0);
    *(int **)((char*)a0 + 0x214) = &D_0041B598;
    r = a0;
    *(int **)((char*)a0 + 0x4AC) = &D_0041B590;
    return r;
}

__attribute__((section(".text.cPlBase__dtor")))
void cPlBase__dtor(void *a0, int flags) {
    *(int **)((char*)a0 + 0x214) = &D_0041B598;
    cCollisionSolidManage_ReleaseUnit(&D_00462FC0, a0);
    cGameObj__dtor(a0, flags);
}

__attribute__((section(".text.cPlBase__tf")))
void *cPlBase__tf(void) {
    if (D_007854C8 == 0) {
        cGameObj__tf();
        SetField_0_4_8_31EEA8(&D_007854C8, &D_0041B638, &D_007854D8);
    }
    return &D_007854C8;
}

__attribute__((section(".text.GetOrInitSingletonAlt_101E48")))
void *GetOrInitSingletonAlt_101E48(void) {
    if (D_007854E8 == 0) {
        cObjBase__tf();
        SetField_0_4_8_31EEA8(&D_007854E8, &D_0041B710, &D_007854F8);
    }
    return &D_007854E8;
}

__attribute__((section(".text.UpdateAttackMoveState_102BD8")))
void UpdateAttackMoveState_102BD8(cObj *a0) {
    void *r = Getplayer();
    switch (a0->step) {
    case 0: {
        void *p = *(void **)((char *)a0 + 0x304);
        void *q = (void *)(*(int *)((char *)p + 0x24) + (int)p);
        func_002A8578(a0, q, q, 5, 0.0f, 0, 0);
        a0->step = a0->step + 1;
    }
    case 1:
        *(float *)((char *)r + 0x15F0) = D_003BC7C0;
        if (moveMotion(a0) != 0) {
            a0->mode = 0;
            a0->phase = 0;
            a0->step = 0;
            a0->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(a0, 1.0f);
        cObjBase_addNullSpeed(a0, 1.0f);
        break;
    default:
        break;
    }
}
