/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cEma2.h"

extern void func_0028EBF0(cEma2 *self, SET_EM_DATA *data, void *arg);
extern int func_0028AC58(cEma2 *self);
extern int cDamageUnit_AddDamageCollSphere(int unit, void *joint, cVec *offset, float radius);
extern cMeshNode *cModel_getMeshPtr_14B730(void *model, char *name);

/* The int stored at byte ofs of the motion block, plus the block address. */
static __inline__ int motionBlock_at(char *block, int ofs) {
    return *(int *)(block + ofs) + (int)block;
}

/* Hides a mesh node, if the model has it. */
static __inline__ void cMeshNode_hide(cMeshNode *node) {
    if (node != 0)
        node->dispFlags |= 1;
}

/* Shows a mesh node again, if the model has it. */
static __inline__ void cMeshNode_show(cMeshNode *node) {
    if (node != 0)
        node->dispFlags &= ~1;
}

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void moveMotion(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void cParts_setRotationOrder(void *a0, int a1);
extern void cObjBase_KageInit(void *a, void *b, void *c);
extern int cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern void cCollisionSolidManage_CreateUnit(void *a0, void *a1, int a2, float f);
extern void cCollisionSolidManage_CreateSphere(void *a0, void *a1, void *a2, void *a3, float f);
extern float fRand0_1(void);

extern int Rnd(void);
extern int D_00462FC0;
extern char D_00574380[];
extern char D_003C3F68[];
extern char D_00448DB8[];
extern char D_00448DC0[];
extern char D_00448DC8[];
extern char D_00448DD0[];
extern char D_00448DD8[];
extern char D_00448DE0[];
extern char D_00448DE8[];
extern char D_00448DF0[];
struct sph { int a; float b; int c; float d; };
/* Sets up the enemy from its room entry: copies the entry, clears the state
 * bytes, picks the motion set, builds the damage spheres and the solid
 * collision, looks up the eight meshes and rolls the item it drops.
 * Returns 0 if the model can't be loaded. */
__attribute__((section(".text.func_002897F0")))
int func_002897F0(cEma2 *self, SET_EM_DATA *data, void *arg)
{
    cVec centre;
    cVec first;
    cVec *offset;
    SET_EM_DATA *set = &self->setData;
    char *motion;
    cOmBase *child;
    int n;
    unsigned int roll;

    set->objId = data->objId;
    cVec_copy3(&set->pos, &data->pos);
    set->rot = data->rot;
    set->flags = data->flags;
    set->seBank = data->seBank;
    set->seNo = data->seNo;
    set->appPattern = data->appPattern;
    set->entryNo = data->entryNo;
    /* The room entry's number is also the enemy number. */
    self->base.emNo = data->seBank;
    if (func_0028AC58(self) == 0) {
        return 0;
    }
    func_0028EBF0(self, data, arg);
    {
        float one_one = 1.1f;
        self->unk616 = 1;
        self->base.scale[2] = one_one;
        self->base.scale[1] = one_one;
        self->base.scale[0] = one_one;
        self->base.unk531 = 0;
        self->base.hpMax = 500;
        self->base.hp = 500;
    }
    self->base.mode = 0;
    self->base.phase = 0;
    self->base.step = 0;
    self->base.stepArg = 0;
    switch (self->base.emNo) {
    default:
        motion = self->base.motionData;
        func_002A8578(self, motionBlock_at(motion, 0x50), motionBlock_at(motion, 0x54), 0.0f, 0, 0, 0);
        break;
    case 0x2A7: case 0x2AB:
        motion = self->base.motionData;
        func_002A8578(self, motionBlock_at(motion, 0x78), motionBlock_at(motion, 0x7C), 0.0f, 0, 0, 0);
        break;
    }
    moveMotion(self);
    cModel_calcParts(self);
    IK_InverseKinematics(self->base.ik, self);
    cModel_calcWorldParts(self);
    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    cVec_copy3(&self->escPos, self->base.pos);
    cParts_setRotationOrder(self, 4);
    cObjBase_KageInit(self, self->shadow, D_003C3F68);
    self->damageTake = cDamageManage_CreateDamageTake(D_00574380, self, 1);

    /* Four damage spheres, each centred on a joint of the model. */
    n = self->base.childNum;
    *(int *)&centre.x = n;
    {
        int one = 1;
        if (one < n) {
            child = self->base.children[1];
        } else {
            child = 0;
        }
    }
    first.x = 0;
    first.y = 0;
    first.z = 0;
    offset = &first;
    offset->w = 1.0f;
    self->hitSphere[0] = cDamageUnit_AddDamageCollSphere(self->damageTake, child->mtx, offset, 0.25f);
    n = self->base.childNum;
    *(int *)&centre.x = n;
    {
        int three = 3;
        if (three < n) {
            child = self->base.children[3];
        } else {
            child = 0;
        }
    }
    centre.w = 1.0f;
    centre.x = 0;
    centre.y = 0;
    centre.z = 0;
    self->hitSphere[1] = cDamageUnit_AddDamageCollSphere(self->damageTake, child->mtx, &centre, 0.25f);
    n = self->base.childNum;
    *(int *)&centre.x = n;
    {
        int joint19 = 0x13;
        if (joint19 < n) {
            child = self->base.children[0x13];
        } else {
            child = 0;
        }
    }
    centre.w = 1.0f;
    centre.x = 0;
    centre.y = 0;
    centre.z = 0;
    self->hitSphere[2] = cDamageUnit_AddDamageCollSphere(self->damageTake, child->mtx, &centre, 0.25f);
    n = self->base.childNum;
    *(int *)&centre.x = n;
    {
        int joint23 = 0x17;
        if (joint23 < n) {
            child = self->base.children[0x17];
        } else {
            child = 0;
        }
    }
    centre.x = 0;
    centre.y = 0;
    centre.z = 0;
    centre.w = 1.0f;
    self->hitSphere[3] = cDamageUnit_AddDamageCollSphere(self->damageTake, child->mtx, &centre, 0.25f);

    cCollisionSolidManage_CreateUnit(&D_00462FC0, self, 5, 0.2f);
    centre.w = 1.0f;
    centre.y = 0.5f;
    centre.x = 0;
    centre.z = 0;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, self, self->base.mtx, &centre, 0.5f);

    /* The goal's first word holds flags, its w the random wait. */
    *(int *)&self->goal.z = 0;
    self->goal.y = 0.02f;
    self->goal.w = fRand0_1() * 90.0f + 90.0f;
    self->mesh[0] = cModel_getMeshPtr_14B730(self, D_00448DB8);
    self->mesh[1] = cModel_getMeshPtr_14B730(self, D_00448DC0);
    self->mesh[2] = cModel_getMeshPtr_14B730(self, D_00448DC8);
    self->mesh[3] = cModel_getMeshPtr_14B730(self, D_00448DD0);
    self->mesh[4] = cModel_getMeshPtr_14B730(self, D_00448DD8);
    self->mesh[5] = cModel_getMeshPtr_14B730(self, D_00448DE0);
    self->mesh[6] = cModel_getMeshPtr_14B730(self, D_00448DE8);
    self->mesh[7] = cModel_getMeshPtr_14B730(self, D_00448DF0);
    cMeshNode_hide(self->mesh[0]);
    cMeshNode_hide(self->mesh[1]);
    cMeshNode_hide(self->mesh[2]);
    cMeshNode_hide(self->mesh[3]);
    cMeshNode_hide(self->mesh[4]);
    cMeshNode_hide(self->mesh[5]);
    cMeshNode_hide(self->mesh[6]);
    cMeshNode_hide(self->mesh[7]);
    cMeshNode_show(self->mesh[0]);
    cMeshNode_show(self->mesh[4]);
    *(unsigned char *)&self->aim.y = 1;
    roll = Rnd() & 0xF;
    self->base.dropItem = 0x3C1;
    if (roll >= 7) self->base.dropItem = 0x3C8;
    if (roll >= 13) self->base.dropItem = 0x3D1;
    if (roll >= 15) self->base.dropItem = 0x3D0;
    if ((Rnd() & 7) == 0) self->base.dropItem = 0x3D8;
    if (self->setData.flags & 0x10000000)
        *(int *)&self->goal.x |= 0x40;
    return 1;
}
