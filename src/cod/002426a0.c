#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void *Getplayer(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_00281260(void *a0);
extern void ClearBytes2F4To2F7_283170(void *a0);
extern void func_002495E0(void *a0, float f);
extern int D_005850B0;
extern char D_005CB000[];

/* Phase machine on the step byte, 4 case labels. Calls cCollisionSolidManage_SetActive,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, moveMotion, cObjBase_addNullSpeed_Rotation,
 * cObjBase_addNullSpeed and 1 more. */
__attribute__((section(".text.func_002426A0"))) void func_002426A0(cEm00 *self)
{
    float one;

    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    self->emFlags |= 0x11000;
    self->emFlags |= 0x20000;
    switch (self->step) {
        case 0: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int id = self->emNo;
            int b = self->resource;
            int p1 = EM_RES_REC(b, 0x3F4);
            int p2 = EM_RES_REC(b, 0x3F8);
            float f = 0.0f;

            if (id == 0x215) {
                f = 25.0f;
            }
            func_002A8578(self, p1, p2, f, 10, t0, 0);
            self->emFlags = self->emFlags & 0xDFFFFFFF;
            self->step++;
        }
        case 1:
            one = 1.0f;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            if (0.0f < *(float *)((char *)self + 0x16C0)) {
                func_002705D8(self);
            }
            if ((self->emFlags & 0x20000000) != 0) {
                self->step = 2;
            }
            break;
        case 2: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int res = self->resource;

            func_002A8578(self, EM_RES_REC(res, 0x1B58), EM_RES_REC(res, 0x1B5C), 0.0f, 3, t0, 0);
            self->step++;
        }
        case 3:
            if (moveMotion(self) != 0) {
                self->step = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
}

/* Phase machine on the step byte, 2 case labels. Calls capVu0MagnitudeSqXZ, Getplayer,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, func_00281260, ClearBytes2F4To2F7_283170 and 5
 * more. */
__attribute__((section(".text.func_00249960"))) void func_00249960(cEm00 *self)
{
    int v0;
    int t0;
    float one;
    unsigned char *hs;
    capVu0MagnitudeSqXZ(*((void **)(((char *)Getplayer()) + 0xF0)), &D_005850B0);
    *((int *)(((char *)self + 0x16D0))) = (*((int *)(((char *)self + 0x16D0)))) | 0x30400;
    switch (*((unsigned char *)(((char *)self + 0x2F6)))) {
        do {
            case 0:
                *((char *)(((char *)self + 0x1864))) = 0;
                t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
                v0 = *((int *)(((char *)self + 0x304)));
                func_002A8578(self, (*((int *)(v0 + 0x3D34))) + v0, (*((int *)(v0 + 0x3D38))) + v0,
                              0.0f, 10, t0, 0);
                if ((*((void **)(((char *)self + 0x748)))) != 0) {
                    func_00281260(*((void **)(((char *)self + 0x748))));
                }
                if ((*((void **)(((char *)self + 0x74C)))) != 0) {
                    ClearBytes2F4To2F7_283170(*((void **)(((char *)self + 0x74C))));
                }
                if ((*((void **)(((char *)self + 0x750)))) != 0) {
                    ClearBytes2F4To2F7_283170(*((void **)(((char *)self + 0x750))));
                }
                *((int *)(((char *)self + 0x16D0))) =
                    (*((int *)(((char *)self + 0x16D0)))) & 0xFCFFFFFF;
                *((unsigned char *)(((char *)self + 0x2F6))) =
                    (*((unsigned char *)(((char *)self + 0x2F6)))) + 1;
            case 1:
                func_002495E0(self, 0.0f);
                moveMotion(self);
                one = 1.0f;
                cObjBase_addNullSpeed_Rotation(self, one);
                cObjBase_addNullSpeed(self, one);
                hs = (unsigned char *)D_005CB000;
                break;
        } while (0);
        default:
            hs = (unsigned char *)D_005CB000;
            break;
    }

    if (hs[0x10] == 0) {
        func_00262AA8(self);
    }
}
