/* sn-2.95.3-136 matched TU. */

#include "godhand/cModel.h"
#include "godhand/cObjBase.h"
#include "godhand/vu0.h"
#include "godhand/cEmManage.h"
#include "godhand/cEma2.h"

extern int D_007476B0;
extern char D_00754C80[];
extern cModelNode *cModel_getMeshPtr(cModel *self, int idx);
extern void cModel_setNodeMaterial(cModel *self, cModelNode *node);
extern void cModel_queueNodeKind6(cModel *self, cModelNode *node, short id);
extern void cModel_queueNodeKind4(cModel *self, cModelNode *node, short id);
extern void cModel_queuePacket(cModel *self, short id);
extern void func_0014C5A0(cModel *self, short id);
extern void func_0031A600(void *queue, int kind, int id, void *packet);
extern void KillEffect(void *owner, int handle, int arg);
extern void SetEffectPos(int kind, int id, int arg, void *pos, int handle, float scale);
extern int SetEffect(int kind, int id, void *owner, void *param, int handle, void *owner2);
extern char D_005864E0[];
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);

typedef int (*cModelVoidFn)(void *self);
typedef void (*cModelDrawFn)(void *self, int id, int arg);

/* Queue every mesh of the model for the screen layer, then its extra packets
 * for this frame's parity. Does nothing when virtual method 6 returns nonzero. */
__attribute__((section(".text.cModel_Trans_screen")))
void cModel_Trans_screen(cModel *self) {
    char hold[16] __attribute__((aligned(16)));
    int parity = D_007476B0 & 1;
    cMeshData *data;
    cModelNode *node;
    unsigned char i;
    int id;
    int multi;

    if (CVCALL_FN(self, 6, cModelVoidFn)(CVCALL_THIS(self, 6)) != 0) {
        return;
    }
    self->objFlags &= 0xFFDFFFFF;
    id = self->id;
    node = cModel_getMeshPtr(self, 0);
    if (node != 0) {
        if ((self->objFlags & 0x80) == 0) {
            cModel_setNodeMaterial(self, node);
        }
        data = node->data;
        *(int *)hold = (int)data;
        multi = data->num >= 2;
        if (!multi) {
            CVCALL_FN(self, 4, cModelDrawFn)(CVCALL_THIS(self, 4), id, 0);
            do {
                cModel_queueNodeKind6(self, node, id);
                node = node->next;
            } while (node != 0);
            cModel_queuePacket(self, id);
        } else {
            CVCALL_FN(self, 5, cModelDrawFn)(CVCALL_THIS(self, 5), id, 0);
            do {
                cModel_queueNodeKind4(self, node, id);
                node = node->next;
            } while (node != 0);
            func_0014C5A0(self, id);
        }
    }
    for (i = 2; i != 0; i--) {
        if (self->extraPacket[i - 1][parity] != 0) {
            func_0031A600(D_00754C80, 4, 5, self->extraPacket[i - 1][parity]);
        }
    }
}

extern void SetEffectParts(int kind, int id, void *owner, int part, int handle,
                           float x, float y, float z, float w);

/* Field f of the effect entry at base, formed as retail does: the entry index
 * is scaled into base first and the table offset is added at the access. */
#define SEQEFF_AT(base, f) (((cSeqEffect *)((base) + COBJBASE_OFFSET(seqEffect)))->f)

/* Run the actor's effect list: start or stop each entry as its flags say. */
__attribute__((section(".text.cObjBase_SetSeqEffect")))
void cObjBase_SetSeqEffect(cObjBase *self) {
    cEffectParam param;
    cVec *scale;
    unsigned int i;
    void *owner;
    char *base;
    unsigned int flags;
    int part;
    int kind;
    int handle;
    int id;

    param.color.x = 1.0f;
    param.color.y = 1.0f;
    param.color.z = 1.0f;
    param.color.w = 1.0f;
    VU0_SQC2_VF0(&param, 0x10);         /* zeroes unk10 */
    VU0_SQC2_VF0(&param, 0x20);         /* zeroes unk20 */
    scale = &param.scale;               /* retail holds this address for y, z and w */
    param.scale.x = 1.0f;
    scale->y = 1.0f;
    scale->z = 1.0f;
    scale->w = 1.0f;
    param.size = 1.0f;
    param.unk4C = -1;
    param.unk4F = 0xFF;
    param.unk44 = 0;
    param.flags = 0;
    param.unk4D = 0;
    param.unk4E = 0;
    param.unk50 = 0;
    VU0_SQC2_VF0(&param, 0x60);         /* zeroes unk60 */
    param.size = self->scale.y;
    param.unk70 = 0;
    param.unk72 = 0;
    param.unk74 = 0;
    param.unk78 = 0;
    for (i = 0; i < self->seqEffectNum; i++) {
        base = (char *)self + i * 12;
        flags = SEQEFF_AT(base, flags);
        if ((flags & SEQEFF_SKIP) && self->seqSkip != 0) {
            continue;
        }
        kind = SEQEFF_AT(base, kind);
        handle = self->seqEffect[i].handle;
        id = SEQEFF_AT(base, id);
        part = SEQEFF_AT(base, part);
        if (flags & SEQEFF_KILL) {
            KillEffect((flags & SEQEFF_OWNED) ? self : 0, handle, 2);
            continue;
        }
        owner = (flags & SEQEFF_OWNED) ? self : 0;
        if (part == 0xFF) {
            if (flags & SEQEFF_AT_POS) {
                SetEffectPos(kind, id, 0, self->pos, -1, 1.0f);
            } else if (self->motionFlags & 2) {
                param.flags |= EFFECT_PARAM_LOOP;
                SetEffect(kind, id, owner, &param, handle, owner);
            } else {
                SetEffect(kind, id, owner, &param, handle, owner);
            }
        } else {
            SetEffectParts(kind, id, owner, part, handle, 0.0f, 0.0f, 0.0f, 1.0f);
        }
    }
}

/* Looks through the loaded actor data for an enemy of one of three groups
 * (ids 0x202/0x208/0x278, 0x207/0x20D/0x270, 0x21D/0x276) and returns the
 * sound bank of that group, 0xFFFF when none is loaded. When out is given
 * it receives the actor id and the bank. */
__attribute__((section(".text.cEmManage_pickStandInEm")))
int cEmManage_pickStandInEm(cEmManage *self, SET_EM_DATA *out)
{
    unsigned int i;
    int id;

    for (i = 0; i < cDataManager_countReady(D_005864E0); i++) {
        id = cDataManager_getReadyKind(D_005864E0, i);
        switch (id) {
        case 0x202:
        case 0x208:
        case 0x278:
            if (out != 0) {
                out->objId = id;
                out->seBank = 0x20F;
            }
            return 0x20F;
        case 0x207:
        case 0x20D:
        case 0x270:
            if (out != 0) {
                out->objId = id;
                out->seBank = 0x210;
            }
            return 0x210;
        case 0x21D:
        case 0x276:
            if (out != 0) {
                out->objId = id;
                out->seBank = 0x226;
            }
            return 0x226;
        }
    }
    return 0xFFFF;
}

/* 1 when some listed enemy (not in the actor id range 0x2A0..0x2FF) is in
 * move mode 1 or phase 2 and within radius of pos, compared squared in
 * the xz plane. */
__attribute__((section(".text.cEmManage_ckEnemyActiveNear")))
int cEmManage_ckEnemyActiveNear(cEmManage *self, cVec *pos, float radius)
{
    cEmSlot *slot;
    cGameObj *em;
    float dist;
    float range;

    for (slot = self->list.top; slot != 0; slot = slot->next) {
        em = (cGameObj *)slot->em;
        if (em == 0)
            continue;
        if (cGameObj_idInRange(em, 0x2A0, 0x300) & 0xFF)
            continue;
        if (em->mode != 1 && em->phase != 2)
            continue;
        dist = capVu0MagnitudeSqXZ(em->pos, pos);
        range = radius * radius;
        if (dist < range)
            return 1;
    }
    return 0;
}
