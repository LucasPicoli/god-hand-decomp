/* sn-2.95.3-136: func_001AB730, gimmick open/close step: play the open motion with the solid
 * collision off, flash its damage collision when the motion ends, then close it again. */
#include "godhand/cOmBase.h"
#include "godhand/cDamageGive.h"
#include "godhand/cCoreSave.h"
extern char D_00462FC0[];
extern void cCollisionSolidManage_SetActive(void *mgr, void *obj, int on);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cDamageUnit_SetDamageCollFlashActiveById(char *unit, int id, int on, short time);

/* A gimmick that opens with a motion, flashes its damage volume and closes again. */
typedef struct cOmOpenClose {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x608 - 0x5E0];
    cDamageGive *give;                  /* 0x608 */
    char unk60C[0x620 - 0x60C];
    int giveId;                         /* 0x620 id of the volume to flash */
    char unk624[0x9D0 - 0x624];
    int flags;                          /* 0x9D0 bit 30 set while the open motion plays */
    int timer;                          /* 0x9D4 set to 30 when it has closed */
} cOmOpenClose;

#define OPENCLOSE_OPENING  0x40000000

__attribute__((section(".text.func_001AB730")))
void func_001AB730(cOmOpenClose *self)
{
    cDamageGive *give;
    int mot;

    cCoreSave_getGameLevel(&D_00569B70);
    switch (self->base.step) {
    case 0:
        self->flags |= OPENCLOSE_OPENING;
        cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
        {
            int v0 = self->base.texKey;

            func_002A8578(self, *(int *)(v0 + 0x34) + v0, 0, 0.0f, 0xA, 0, 0);
        }
        self->base.step = self->base.step + 1;
    case 1:
        if (moveMotion(self) != 0) {
            self->flags &= ~OPENCLOSE_OPENING;
            {
                int v0 = self->base.texKey;

                mot = *(int *)(v0 + 0x38) + v0;
            }
            give = self->give;
            if (give != 0) {
                give->activeTime = 0x3C;
                cDamageUnit_SetDamageCollFlashActiveById((char *)self->give, self->giveId, 1, 0x3C);
            }
            func_002A8578(self, mot, 0, 0.0f, 0xA, 0, 0);
            self->base.step = self->base.step + 1;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2:
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 3:
        if (moveMotion(self) != 0) {
            self->timer = 0x1E;
            cCollisionSolidManage_SetActive(D_00462FC0, self, 1);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    }
}
