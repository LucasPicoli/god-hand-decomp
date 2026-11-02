/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cHeatSys.h"
#include "godhand/cObjBase.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/rand.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

extern void SetEffectPos(int kind, int id, void *owner, cVec *pos, int handle, float size);

#define RES(off) EM_RES_REC(self->resource, off)

/* Four motions, each started by an even step and played by the odd step after
 * it: step 5 ends the phase when its motion ends with the watched enemy alive,
 * step 7 when its motion ends. On the first frame with a motion-end bit set it
 * puts a spark near child 6 and hits the watched enemy on the player's behalf,
 * for 10 (bit 0) and 30 (bit 1), each adding 0.5 to the player's heat gauge. */
__attribute__((section(".text.func_0027CB58")))
void func_0027CB58(cEm00 *self)
{
    int frame[3];
    cEm00 *target;
    cOmBase *part;
    cGameObj *player;

    target = self->target;
    switch (self->step) {
    case 0:
        func_002A8578((int)self, RES(0xC8), RES(0xCC), 0, 0.0f, 0, 0);
        self->partYaw = 0.0f;
        self->step++;
    case 1:
        moveMotion(self);
        break;
    case 2:
        func_002A8578((int)self, RES(0xD0), RES(0xD4), 5, 0.0f, 0, 0);
        self->step++;
    case 3:
        moveMotion(self);
        break;
    case 4:
        func_002A8578((int)self, RES(0xD8), RES(0xDC), 5, 0.0f, 0, 0);
        self->step++;
    case 5:
        if (moveMotion(self) != 0 && target != 0 && target->vital > 0) {
            self->mode = 0;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
        }
        break;
    case 6:
        func_002A8578((int)self, RES(0xA8), RES(0xAC), 5, 0.0f, 0, 0);
        self->step++;
    case 7:
        if (moveMotion(self) != 0) {
            self->mode = 0;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
        }
        break;
    }
    if (self->moveFlags & 3) {
        if (self->unk56A != 0) {
            part = cOmBase_childAt((cOmBase *)self, frame, 6);
            if (part != 0) {
                cVec spark;

                VU0_SQC2_VF0_MEM(&spark, 0);
                spark.x = fRand1_1() * 0.1f;
                spark.y = fRand1_1() * 0.1f + 0.1f;
                spark.z = fRand0_1() * 0.1f + 0.2f;
                cVec_applyMatrix(&spark, part->mtx);
                SetEffectPos(0, 0x4F, 0, &spark, -1, 1.0f);
            }
        }
        if (target != 0) {
            player = Getplayer();
            if (self->moveFlags & 1) {
                CEM00_VCALL(target, hit, 10, player, 0, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 0.5f);
            }
            if (self->moveFlags & 2) {
                CEM00_VCALL(target, hit, 30, player, 0, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 0.5f);
            }
        }
        self->unk56A = 0;
    } else {
        self->unk56A = 1;
    }
}
