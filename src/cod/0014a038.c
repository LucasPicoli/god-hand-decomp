/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/cEmSetParam.h"
#include "godhand/cEma2.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float f);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void func_0026B240(void *a0, int a1, int a2, int a3);
extern unsigned char D_00747A50[];
extern void MtxInitCoord(float *mtx, cVec *pos, cVec *rot, cVec *scale, int order);
extern void MtxInverse(float *dst, float *src);
extern void func_0030A2E0(float *dst, float *a, float *b);
extern void func_00156D70(cParts *dst, cParts *src, float *m, float blend);
extern void func_001501D0(cParts *part, int flags);
extern void Adjust_theta_vec(cVec *v);
extern void MtxInitTransVec(cParts *part, cVec *trans);
extern void MtxMulRotVec(cParts *dst, cParts *src, cVec *rot, int order);
extern void MtxMulScaleVec(cParts *dst, cParts *src, cVec *scale);
extern void MtxMultiply(float *dst, float *a, cParts *b);
extern void func_002BEDC8(cEmSetTable *table, int arg);
extern void func_002BEDE8(cEmSetTable *table, int entryNum, cEmSetEntry *entry);
extern void func_00295600(cEmSetParam *self);
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);
extern void cEma2_setDamage(cEma2 *self);

/* func_00242388: an enemy that circles the player, turning its aim toward
 * the player each frame, and spawns an effect each time a motion contact
 * flag rises. */












__attribute__((section(".text.func_00242388")))
void func_00242388(cEm00 *self)
{
    cEm00 *player;
    int res;
    int motion;
    int r;

    switch (self->step) {
    case 0:
        motion = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        res = self->resource;
        func_002A8578(self, EM_RES_REC(res, 0x1560), EM_RES_REC(res, 0x1564), 0.0f, 0, motion, 0);
        self->timer = 150.0f;
        self->step = self->step + 1;
    case 1:
        player = Getplayer();
        cGameObj_SetTgtTurn(self, player->pos, self->speedRate * 0.19634954f);
        {
            int fa = 0x10000;
            int fb = 0x20000;

            self->emFlags = (self->emFlags | fa) | fb;
        }
        moveMotion(self);
        if (self->timer > 0.0f) {
            self->timer = self->timer - self->speedRate;
        } else if (self->playerDist < 400.0f) {
            self->step = self->step + 1;
        }
        if (D_00747A50[1] == 5 && self->playerDist < 400.0f) {
            float d, ad;
            cEm00 *q = Getplayer();

            ad = (d = q->pos->y - self->pos->y);
            if (d < 0.0f) {
                ad = -d;
            }
            if (ad < 1.5f) {
                func_002705D8(self);
            }
            d = 0.0f;
        }
        break;
    case 2:
        motion = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        res = self->resource;
        func_002A8578(self, EM_RES_REC(res, 0x1678), EM_RES_REC(res, 0x167C), 0.0f, 0,
                      (self->unk5F8 = 1, self->timerC = 1, motion), 0);
        self->step = self->step + 1;
    case 3:
        player = Getplayer();
        cGameObj_SetTgtTurn(self, player->pos, self->speedRate * 0.19634954f);
        {
            int fa = 0x10000;
            int fb = 0x20000;

            self->emFlags = (self->emFlags | fa) | fb;
        }
        if (moveMotion(self) != 0) {
            self->step = 0;
        }
        break;
    }
    if (self->moveFlags & 1) {
        if (self->unk5F8 != 0) {
            self->unk5F8 = 0;
            r = func_0026AA30(self, 0x365);
            if (r != 0) {
                func_0026B240(self, r, 0x365, 0xA);
            }
        }
    } else {
        self->unk5F8 = 1;
    }
    if (self->moveFlags & 2) {
        if (self->timerC != 0) {
            self->timerC = 0;
            r = func_0026AA30(self, 0x365);
            if (r != 0) {
                func_0026B240(self, r, 0x365, 0x10);
            }
        }
    } else {
        self->timerC = 1;
    }
}

/* Rebuild the model's matrix when it is a near model, and blend each part
 * that is not left to its parent toward the model's blend weight. */
__attribute__((section(".text.cModel_calcWorldParts")))
void cModel_calcWorldParts(cModel *self) {
    float m[16] __attribute__((aligned(16)));
    cVec *scale;
    float *dst;
    cParts *part;
    unsigned long flags;
    int i;

    if (self->objFlags & CMODEL_F_NEAR) {
        if (!(self->objFlags & CMODEL_F_NO_CALC)) {
            scale = &self->scale;
            MtxInitCoord(self->mtx, self->pos, &self->rot, scale, self->rotOrder);
            dst = &self->scaleCalc.x;
            if (dst != &scale->x) {
                dst[0] = scale->x;
                dst[1] = scale->y;
                dst[2] = scale->z;
            }
        }
        i = 0;
        part = self->next;
        if (self->partNum != 0) {
            do {
                flags = part->partFlags;
                if (((flags >> 4) & 1) == 0) {
                    if (self->blend > 0.0f && (flags & CPARTS_NO_BLEND) == 0) {
                        MtxInverse(m, part->parent->mtx);
                        func_0030A2E0(m, m, part->mtx);
                        func_00156D70(part, part, part->mtxBind, self->blend);
                    }
                    func_001501D0(part, self->objFlags);
                }
                i++;
                part = part->next;
            } while (i < self->partNum);
        }
    }
}

/* Rebuild the model's matrix and every part's matrix from its rotation,
 * scale and anchor, then multiply it into its parent's. */
__attribute__((section(".text.func_0014A170")))
void func_0014A170(cModel *self) {
    cVec rot;
    float x, y, z;
    cParts *part;
    unsigned long flags;
    int i;

    if (!(self->objFlags & CMODEL_F_NO_CALC)) {
        MtxInitCoord(self->mtx, self->pos, &self->rot, &self->scale, self->rotOrder);
    }
    i = 0;
    part = self->next;
    if (self->partNum != 0) {
        do {
            Adjust_theta_vec(&part->rot);
            x = part->rot.x + part->rotAdd.x;
            y = part->rot.y + part->rotAdd.y;
            z = part->rot.z + part->rotAdd.z;
            rot.x = x;
            rot.y = y;
            rot.z = z;
            rot.w = 1.0f;
            Adjust_theta_vec(&rot);
            flags = part->partFlags;
            if (((flags >> 3) & 1) == 0) {
                MtxInitTransVec(part, part->anchor);
                MtxMulRotVec(part, part, &rot, 0);
                MtxMulScaleVec(part, part, &part->scale);
            }
            flags = part->partFlags;
            if (((flags >> 4) & 1) == 0) {
                MtxMultiply(part->mtx, part->parent->mtx, part);
            }
            i++;
            part = part->next;
        } while (i < self->partNum);
    }
}

/* Takes a room file: checks its tag, hands its entry array to the table
 * object and marks the table loaded. Returns 1 on success, and also 1 when
 * the table is already loaded; 0 for a missing file, a wrong tag or an
 * empty one. */
__attribute__((section(".text.func_00294B98")))
int func_00294B98(cEmSetParam *self, cEmSetFile *file)
{
    if ((D_005E8658.block->flags & EMSET_LOADED) == 0) {
        if (file == 0)
            return 0;
        self->file = file;
        if (file->tag != EMSET_TAG) {
            self->file = 0;
            return 0;
        }
        if (file->entryNum == 0) {
            func_002BEDC8(&D_005E8658, 0);
            D_005E8658.block->flags |= EMSET_LOADED;
            self->file = 0;
            return 0;
        }
        self->entry = file->entry;
        func_002BEDE8(&D_005E8658, file->entryNum, self->entry);
        func_00295600(self);
        D_005E8658.block->flags |= EMSET_LOADED;
    }
    return 1;
}

/* Damages every listed cEma2 that is alive and no farther than 2 units
 * (compared squared, in the xz plane) from pos. */
__attribute__((section(".text.func_00292D18")))
void func_00292D18(cEmManage *self, cVec *pos)
{
    cEmSlot *slot;
    cEma2 *em;

    for (slot = self->list.top; slot != 0; slot = slot->next) {
        em = (cEma2 *)slot->em;
        if (em == 0)
            continue;
        if (func_003A5678(D_0044A7A8, em->base.kindName) != 0)
            continue;
        if (em->base.hp <= 0)
            continue;
        if (4.0f < capVu0MagnitudeSqXZ(em->base.pos, pos))
            continue;
        cEma2_setDamage(em);
    }
}

/* The first listed cEma2 that is alive and within radius of pos (compared
 * squared, in the xz plane), or 0. */
__attribute__((section(".text.func_00292DC8")))
cEma2 *func_00292DC8(cEmManage *self, cVec *pos, float radius)
{
    cEmSlot *slot;
    cEma2 *em;
    float dist;
    float range;

    for (slot = self->list.top; slot != 0; slot = slot->next) {
        em = (cEma2 *)slot->em;
        if (em == 0)
            continue;
        if (func_003A5678(D_0044A7A8, em->base.kindName) != 0)
            continue;
        if (em->base.hp <= 0)
            continue;
        dist = capVu0MagnitudeSqXZ(em->base.pos, pos);
        range = radius * radius;
        if (range < dist)
            continue;
        return em;
    }
    return 0;
}
