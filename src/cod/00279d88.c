/* sn-2.95.3-136 */
#include "godhand/cModel.h"
#include "godhand/cEm00.h"
#include "godhand/vu0.h"

#define EMSETUP_EMNO        0x23F
#define EMSETUP_TURN_RATE   0.02f

/* Where func_0028EBF0 places the model's parts. */
typedef struct EmPlace {
    char unk00[0x10];
    cVec pos;                           /* 0x10 */
    float rot;                          /* 0x20 */
    char unk24[0xD];
    unsigned char unk31;                /* 0x31 0xFF */
    char unk32[0xE];
} EmPlace;

extern char D_00462FC0[];

extern int func_00279F68(char *a0);
extern int func_0028EBF0(void *self, void *src, int arg);
extern void cModel_calcParts(cModel *self);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(cModel *self);
extern void cCollisionSolidManage_SetActive(int a0, int a1, int a2);
extern void cParts_setRotationOrder(char *arg0, int arg1);

/* Set up enemy 0x23F: load its model, place the parts at the origin and turn its collision on. */
__attribute__((section(".text.func_00279D88")))
int func_00279D88(cEm00 *self)
{
    EmPlace place;

    VU0_SQC2_VF0(&place, 0x10);
    place.unk31 = 0xFF;
    self->emNo = EMSETUP_EMNO;
    place.pos.x = 0.0f;
    place.pos.y = 0.0f;
    place.pos.z = 0.0f;
    place.rot = 0.0f;
    if (func_00279F68((char *)self) != 0) {
        func_0028EBF0(self, &place, 0);
        self->target = 0;
        self->watchArg = 0;
        cModel_calcParts(self);
        IK_InverseKinematics(self->ik, self);
        cModel_calcWorldParts(self);
        self->active = 1;
        self->link = -1;
        cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
        cParts_setRotationOrder((char *)self, 4);
        self->vital = self->vitalMax = 1;
        self->turnRate = EMSETUP_TURN_RATE;
        self->turnArg = 0;
        self->unk617 = 0;
        return 1;
    }
    return 0;
}
