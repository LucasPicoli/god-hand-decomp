/* sn-2.95.3-136: walk-to-target step: start the walk motion and turn to the target, then advance
 * until the enemy stalls or reaches the target, and push the null speed. */
#include "godhand/cEm00.h"
#include "godhand/vecInline.h"
#include "godhand/cObjBase.h"

extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern int moveMotion(void *a0);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void cObjBase_addNullSpeed_Rotation(cObjBase *self, float scale);
extern void cObjBase_addNullSpeed(cObjBase *self, float scale);

#define WALK_STALL_FRAMES  2            /* stalled frames in a row that end the walk */

__attribute__((section(".text.func_00114AC0")))
void func_00114AC0(cEm00 *self)
{
    float r;
    float d;

    switch (self->step) {
    case 0:
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_002A8578(self, EM_RES_REC(self->resource, 0x48), EM_RES_REC(self->resource, 0x4C), 3, 0.0f, 0, 0);
        cGameObj_SetTgtTurn(self, &self->unk580, 3.1415927f);
        self->stepVar.count = 0;
        self->unk1590.x = 99999.9f;
        self->unk1590.y = 99999.9f;
        self->unk1590.z = 99999.9f;
        self->step += 1;
    case 1:
        self->unk434 |= 8;
        moveMotion(self);
        d = capVu0MagnitudeSqXZ(&self->unk1590, &self->posA);
        r = self->unk1588 * 0.5f;
        if (d < r * r) {
            if (++self->stepVar.count >= WALK_STALL_FRAMES) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
        } else {
            self->stepVar.count = 0;
        }
        vec3_copy(&self->unk1590.x, &self->posA.x);
        d = capVu0MagnitudeSqXZ(self->pos, &self->unk580);
        if (d < 4.0f) {
            self->mode = 0;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
        }
        self->stepVec.x = 0.0f;
        self->stepVec.y = 0.0f;
        /* retail stores the distance-based speed, then overwrites it with 2.0 */
        self->stepVec.z = d > 6.25f ? 2.0f : 1.0f;
        self->stepVec.z = 2.0f;
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
}
