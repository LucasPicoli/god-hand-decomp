/* sn-2.95.3-136 matched TU. */
#include "godhand/globals.h"

extern float SetMotionStep(void *a0, float f12);
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
extern float Adjust_theta(float f12);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cEm00_startJumpSetup(void *a0);

extern float Turn_dest_dir(float f12, float f13, float f14);
extern void cModel_calcNullPart(void *a0);
extern void Add_nullspeedDir(void *a0, float f12);
__attribute__((section(".text.func_0010C300")))
void func_0010C300(void *a0)
{
    cGameObj *s0 = a0;
    int t0;
    int v0;
    void *q;
    int p1;
    int p2;
    float v;
    float sp;
    if (s0->hp <= 0) {
        s0->hp = 1;
    }
    if (*(unsigned short *)((char *)s0 + 0x5F2) == 3) {
        s0->speedRate = 1.6f;
        SetMotionStep(s0, 1.6f);
    } else {
        s0->speedRate = 1.3f;
        SetMotionStep(s0, 1.3f);
    }
    switch (s0->step) {
    case 0:
        *(short *)((char *)s0 + 0x5E0) = 0;
        *(short *)((char *)s0 + 0x5E2) = 0;
        if (*(char *)((char *)s0 + 0x648) >= 0xB) {
            *(char *)((char *)s0 + 0x648) = 0xA;
        }
        t0 = *(int *)((char *)s0 + 0x304);
        q = *(void **)((char *)s0 + 0x6A0);
        p1 = *(int *)(t0 + 0x58) + t0;
        p2 = *(int *)(t0 + 0x5C) + t0;
        if (q != 0) {
            func_002A8578(q, *(int *)(t0 + 0x370) + t0, *(int *)(t0 + 0x38C) + t0,
                          0xA, 0.0f, 0, 0);
            v0 = *(int *)((char *)s0 + 0x304);
            p1 = *(int *)(v0 + 0x34C) + v0;
            p2 = *(int *)(v0 + 0x350) + v0;
        }
        func_002A8578(s0, p1, p2, 0xA, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    case 1:
        *(float *)((char *)s0 + 0x15F0) = D_003BD480;
        if (*(int *)((char *)s0 + 0x5D8) != 4) {
            if (*(unsigned char *)((char *)s0 + 0x61F) != 0) {
                v = *(float *)((char *)s0 + 0x608) - 0.52359879f;
                if (v < 0.0f) {
                    v = 0.0f;
                }
                v = v * 0.400000006f;
                if (D_003BD478 < v) {
                    v = D_003BD478;
                }
                if (*(float *)((char *)s0 + 0x604) < 0.0f) {
                    v = -v;
                }
                s0->rot.y = s0->rot.y + v;
                s0->rot.y = Adjust_theta(s0->rot.y);
            }
            moveMotion(s0);
            cObjBase_addNullSpeed_Rotation(s0, 1.0f);
            cObjBase_addNullSpeed(s0, 1.0f);
        } else {
            v = Turn_dest_dir(s0->rot.y, *(float *)((char *)s0 + 0x15FC), 0.39269909f);
            s0->rot.y = s0->rot.y + v;
            s0->rot.y = Adjust_theta(s0->rot.y);
            moveMotion(s0);
            cModel_calcNullPart(s0);
            Add_nullspeedDir(s0, *(float *)((char *)s0 + 0x15FC));
        }
        break;
    }
    if (*(unsigned char *)((char *)s0 + 0x61F) != 0) {
        if (*(float *)((char *)s0 + 0x60C) < 10000.0f) {
            *(char *)((char *)s0 + 0x1601) = 2;
        }
    }
    if (func_00123938(s0, 0) == 0) {
        cEm00_startJumpSetup(s0);
    }
}
