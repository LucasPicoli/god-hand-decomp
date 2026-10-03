/* sn-2.95.3-136 matched TU. */

#include "godhand/cObjBase.h"
#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/cEma2.h"

extern unsigned int D_00747A84;
extern void VecRotVec(float *out, float *in, float *rot, int order);
extern void KillEffect(void *obj, int effNo, int mode);
extern cGameObj *Getplayer(void);
extern float capVu0Atan2(float x, float z);

/* Moves the object by its null-bone speed rotated about the y axis by yaw. */
__attribute__((section(".text.cObjBase_MoveByNullSpeed")))
void cObjBase_MoveByNullSpeed(cObjBase *self, float yaw, float scale) {
    float v[4] __attribute__((aligned(16)));
    float r[4] __attribute__((aligned(16)));
    float *rp;
    if (!(D_00747A84 & 0x20000000)) {
        VU0_SQC2_VF0(v, 0);
        v[0] = self->nullSpeed.x * self->scale.x * scale;
        v[1] = self->nullSpeed.y * self->scale.y * scale;
        v[2] = self->nullSpeed.z * self->scale.z * scale;
        rp = r;
        r[0] = 0;
        r[1] = yaw;
        r[2] = 0;
        rp[3] = 1.0f;
        VecRotVec(v, v, rp, 4);
        self->pos->x += v[0];
        self->pos->y += v[1];
        self->pos->z += v[2];
    }
}

__attribute__((section(".text.func_002A84A8")))
void func_002A84A8(cGameObj *self)
{
    cGameObjEffectList *list = self->effList;
    cGameObjEffect *eff;
    unsigned int i;

    if (list != 0) {
        eff = (cGameObjEffect *)((char *)list + list->entryOfs);
        for (i = 0; i < list->entryNum; i++, eff++) {
                if (eff->id != GAMEOBJ_EFF_NONE) {
                    if (eff->flags & GAMEOBJ_EFF_FLAG_FADE)
                        KillEffect(self, eff->id, 2);
                    else
                        KillEffect(self, eff->id, 0);
                }
        }
    }
    if (self->effNo != -1)
        KillEffect(self, self->effNo, self->effArg);
    self->effNo = -1;
    self->effArg = 2;
}

__attribute__((section(".text.func_002A8718")))
void func_002A8718(cGameObj *self)
{
    cGameObjEffectList *list = self->effList;
    cGameObjEffect *eff;
    unsigned int i;

    if (list != 0) {
        eff = (cGameObjEffect *)((char *)list + list->entryOfs);
        for (i = 0; i < list->entryNum; i++, eff++) {
                if (eff->id != GAMEOBJ_EFF_NONE) {
                    if (eff->flags & GAMEOBJ_EFF_FLAG_FADE)
                        KillEffect(self, eff->id, 2);
                    else
                        KillEffect(self, eff->id, 0);
                }
        }
    }
    if (self->effNo != -1)
        KillEffect(self, self->effNo, self->effArg);
    self->effNo = -1;
    self->effArg = 2;
}

#define EM_STANDIN_FLAGS  0x44000000    /* SET_EM_DATA.flags of the stand-in */
#define EM_STANDIN_APP    8             /* SET_EM_DATA.appPattern of the stand-in */

/* Enters a stand-in enemy at pos, turned to face the player. Returns the
 * enemy, or 0 when no stand-in actor is loaded. The locals share one frame
 * at the stack pointer: the vector stores use it as their base. */
__attribute__((section(".text.func_00292C28")))
cEmActor *func_00292C28(cEmManage *self, cVec *pos)
{
    struct {
        SET_EM_DATA data;               /* 0x00 */
        char pad34[0xC];
        cVec dir;                       /* 0x40 */
        cVec copy;                      /* 0x50 */
        cVec diff;                      /* 0x60 */
    } f;
    cVec *dst = &f.data.pos;
    cVec *target;
    float angle;

    VU0_SQC2_VF0(&f, 0x10);
    f.data.entryNo = EM_ENTRY_NONE;
    if (cEmManage_pickStandInEm(self, &f.data) == 0xFFFF)
        return 0;
    VU0_SQC2_VF0(&f, 0x40);
    target = Getplayer()->pos;
    VU0_SQC2_VF0(&f, 0x60);
    VU0_LQC2(4, target, 0);
    VU0_LQC2(5, pos, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, &f, 0x60);
    VU0_LQC2(4, &f.diff, 0);
    VU0_SQC2(4, &f, 0x50);
    f.dir.x = f.copy.x;
    f.dir.y = f.copy.y;
    f.dir.z = f.copy.z;
    angle = capVu0Atan2(f.copy.x, f.copy.z);
    if (dst != pos) {
        f.data.pos.x = pos->x;
        f.data.pos.y = pos->y;
        f.data.pos.z = pos->z;
    }
    f.data.rot = angle;
    f.data.flags = EM_STANDIN_FLAGS;
    f.data.appPattern = EM_STANDIN_APP;
    f.data.seNo = 0;
    return cEmManage_EntryEm(&D_005864F0, &f.data, 0, 0);
}
