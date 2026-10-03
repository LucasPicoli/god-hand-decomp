/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void Obj2810_SetState_2_a1(char *a0, int a1);
extern void SetBytes2F4Mode2_2831B0(char *a0, char a1);
extern void ClearBytes2F4To2F7_283170(char *a0);
extern void func_0026DB00(void *a0, int a1, int a2);

/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * cCoreSave_getGameLevel, Obj2810_SetState_2_a1, SetBytes2F4Mode2_2831B0,
 * ClearBytes2F4To2F7_283170, func_002A8578 and 4 more. */
__attribute__((section(".text.func_00249EF8"))) void func_00249EF8(cEm00 *self)
{
    float one;

    self->emFlags = self->emFlags | 0x30400;
    switch (self->step) {
        case 0: {
            int t0, b, b2, a1v, a2v;
            self->unk1864 = 0;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = self->resource;
            a1v = EM_RES_REC(b, 0x3D64);
            a2v = EM_RES_REC(b, 0x3D68);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                b2 = self->resource;
                a2v = EM_RES_REC(b2, 0x3D6C);
                if (self->sub0 != 0)
                    Obj2810_SetState_2_a1((char *)self->sub0, 1);
                if (self->sub1 != 0)
                    SetBytes2F4Mode2_2831B0((char *)self->sub1, 1);
                if (self->sub2 != 0)
                    ClearBytes2F4To2F7_283170((char *)self->sub2);
            } else {
                if (self->sub0 != 0)
                    Obj2810_SetState_2_a1((char *)self->sub0, 0);
                if (self->sub1 != 0)
                    SetBytes2F4Mode2_2831B0((char *)self->sub1, 0);
                if (self->sub2 != 0)
                    ClearBytes2F4To2F7_283170((char *)self->sub2);
            }
            func_002A8578(self, a1v, a2v, 0.0f, 0xA, t0, 0);
        }
            self->step++;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0xA1;
                self->step = 0;
                self->stepArg = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
    if (self->moveFlags & 1) {
        func_0026DB00(self, 2, 0);
    }
}
