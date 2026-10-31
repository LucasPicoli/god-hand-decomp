/* sn-2.95.3-136 */
#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int irand(void);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern int func_0026F1D8(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void func_002705D8(void *a0);
extern char D_005FEE00[];

/* Enemy wait step: steps 0 and 1 play the wait motion (two variants by move flag 0x200) for a random 5 or 30..119
 * frames, steps 2 and 3 play the end motion and then hand over, with sound 0x8C when the 0x17CC timer still runs. */
__attribute__((section(".text.func_00257E90")))
void func_00257E90(cEm00 *self)
{
    int motion;
    int p1;
    int p2;

    switch (self->step) {
    case 0:
        motion = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        if (self->moveFlags & 0x200) {
            p1 = EM_RES_REC(self->resource, 0x1CE8);
            p2 = EM_RES_REC(self->resource, 0x1CEC);
        } else {
            p1 = EM_RES_REC(self->resource, 0x1CF0);
            p2 = EM_RES_REC(self->resource, 0x1CF4);
        }
        func_002A8578(self, p1, p2, 0.0f, 3, motion, 0);
        if (irand() & 1) {
            self->timerA = 5;
        } else {
            self->timerA = (unsigned int)irand() % 90 + 30;
        }
        self->step++;
    case 1:
        moveMotion(self);
        if (self->timerA > 0) {
            self->timerA--;
        } else {
            self->step = 2;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2:
        motion = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        if (self->moveFlags & 0x200) {
            p1 = EM_RES_REC(self->resource, 0x1D40);
            p2 = EM_RES_REC(self->resource, 0x1D44);
        } else {
            p1 = EM_RES_REC(self->resource, 0x1D48);
            p2 = EM_RES_REC(self->resource, 0x1D4C);
        }
        func_002A8578(self, p1, p2, 0.0f, 3, motion, 0);
        self->step++;
    case 3:
        if (moveMotion(self) != 0) {
            if (func_0026F1D8(self) != 0) {
                cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x8C, self, 0, 0, 0, 0);
                func_00270C78(self);
            } else {
                func_002705D8(self);
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
}
