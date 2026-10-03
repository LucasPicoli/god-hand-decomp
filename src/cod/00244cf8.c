#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void *Getplayer(void);
extern void func_002A74E0(void *a0, int a1, int a2);

extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_007476B0;
extern char D_00462FC0[];

/* Phase machine on the step byte, 4 case labels. Calls cCollisionSolidManage_SetActive,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, moveMotion, func_002A74E0, Getplayer and 4
 * more. */
__attribute__((section(".text.func_00244CF8"))) void func_00244CF8(cEm00 *self)
{
    float one;

    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    switch (self->step) {
        case 0: {
            int t0, b;
            *(int *)((char *)self + 0x4A8) = *(int *)((char *)self + 0x4A8) | 0x80000000;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = self->resource;
            func_002A8578(self, EM_RES_REC(b, 0xD78), 0, 0.0f, 0, t0, 0);
        }
            moveMotion(self);
            self->step++;
        case 1:
            self->hitFlash = 2.0f;
            *(unsigned char *)((char *)self + 0x617) = 1;
            *(char *)((char *)self + 0x531) = -1;
            if ((*(int *)((char *)self + 0x1644) & 0x10008000) == 0) {
                if (self->emFlags & 0x200000) {
                    if (self->playerDist < 64.0f &&
                        (D_007476B0 & 7) == (*(int *)((char *)self + 0x17D0) & 7)) {
                        self->emFlags2 = self->emFlags2 & 0xF7FFFFFF;
                        func_002A74E0(self, *(int *)((char *)Getplayer() + 0xF0), 1);
                        if (func_002A7CA0(self, &self->unk16A0) != 0) {
                            self->emFlags2 = self->emFlags2 | 0x8000000;
                        }
                        if (*(float *)((char *)self + 0x510) < 8.0f) {
                            self->step = 2;
                        }
                    }
                    if (self->playerDist < 9.0f) {
                        self->step = 2;
                    }
                }
                if (self->unk16EC != 0) {
                    self->step = 2;
                }
            }
            if (self->emFlags & 0x20000000) {
                self->step = 2;
            }
            if (0.0f < *(float *)((char *)self + 0x16C0)) {
                self->step = 2;
            }
            break;
        case 2: {
            int t0, b;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = self->resource;
            func_002A8578(self, EM_RES_REC(b, 0xD78), EM_RES_REC(b, 0xD7C), 0.0f, 0, t0, 0);
        }
            *(float *)((char *)self + 0x1744) = 300.0f;
            *(char *)((char *)self + 0x531) = 3;
            *(int *)((char *)self + 0x4A8) = *(int *)((char *)self + 0x4A8) & 0x7FFFFFFF;
            self->hitFlash = 5.0f;
            self->step++;
        case 3:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
}
