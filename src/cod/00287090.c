/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"

extern int moveMotion(void *a0);
extern void cModel_calcNullPart(void *a0);
extern void Add_nullspeed(void *a0);
extern float fRand0_1(void);
/* Phase machine on the step byte, 4 case labels. Calls cCollisionSolidManage_SetActive,
 * func_002A8578, moveMotion, cModel_calcNullPart, Add_nullspeed, cSnd_SeCall_2CBA48 and 3 more. */
__attribute__((section(".text.func_00287090"))) void func_00287090(cEm00 *self)
{
    int res;
    float f;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)self, 0);
    switch (self->step) {
        case 0:
            self->gotoFlags = self->gotoFlags | 1;
            res = EM_RES(self);
            func_002A8578(self, EM_RES_REC(res, 0x110), EM_RES_REC(res, 0x114), 0, 0.0f, 0, 0);
            self->timer = 10.0f;
            self->step = self->step + 1;
        case 1:
            moveMotion(self);
            cModel_calcNullPart(self);
            Add_nullspeed(self);
            f = self->timer - self->speedRate;
            self->timer = f;
            if (f <= 0.0f) {
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x60, (cObj *)self, 0, 0, 0, 0);
                self->timer = fRand0_1() * 60.0f + 90.0f;
            }
            break;
        case 2: {
            int b = EM_RES(self);
            self->hp = 0;
            func_002A8578(self, EM_RES_REC(b, 0x118), EM_RES_REC(b, 0x11C), 0, 0.0f, 0, 0);
        }
            func_0028FB08(self);
            cCoreSave_addKillNpcNum(&D_00569B70);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x5F, (cObj *)self, 0, 0, 0, 0);
            self->step = self->step + 1;
        case 3:
            moveMotion(self);
            cModel_calcNullPart(self);
            Add_nullspeed(self);
            break;
    }
}
