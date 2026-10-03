/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/cModel.h"
#include "godhand/cGameObj.h"

extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int func_00291010(void *a0, void *a1, void *a2, int a3, int t0, float f12, float f13, float f14);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void cModel_calcNullPart(void *a0);
extern void Add_nullspeed(void *a0);
extern void func_002A74E0(void *a0, void *a1, int a2);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float fRand0_1(void);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern unsigned char D_005864F0[];
extern unsigned char D_00462FC0[];
extern unsigned char D_005FEE00[];
extern void *Getplayer(void);
extern int cCoreSave_getGameLevel(void *a0);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern float capVu0Atan2(float y, float x);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern int irand(void);
extern char D_00569B70[];
extern int GetField_2B1_14B638(cModel *self);
extern cModelNode *cModel_getMeshPtr(cModel *self, int idx);
extern void func_001F91D0(cBox *dst, cBox *src);
extern void cGameObjSortEnt_pushHeap(cGameObjSortEnt *first, int holeIndex, int topIndex, long val, void *tag);

/* cEm00_updateKnockDrift: a knocked-about enemy that drifts toward a goal and starts a
 * move once it is close to it or the player gets in range. */



















__attribute__((section(".text.cEm00_updateKnockDrift")))
void cEm00_updateKnockDrift(cEm00 *self)
{
    float buf[4] __attribute__((aligned(16)));
    int inFront = 1;
    float *p;
    cVec *dst;
    cVec *src;

    {
        float *q = (float *)self->pos;
        VU0_LQC2(4, q, 0);
        VU0_SQC2(4, buf, 0);
    }
    if (func_00291010(D_005864F0, buf, 0, 1, 0, self->rot.y, 10.0f, 3.14159274f) == 0) {
        inFront = 0;
    }
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    switch (self->step) {
    case 0: {
        int b = self->resource;
        self->gotoFlags = self->gotoFlags & 0xFFFFFFFE;
        func_002A8578(self, EM_RES_REC(b, 0x28), EM_RES_REC(b, 0x2C), 0.0f, 0xA, 0, 0);
        dst = &self->home;
        src = self->pos;
        if (dst != src) {
            self->home.x = src->x;
            dst->y = src->y;
            dst->z = src->z;
        }
        self->step = self->step + 1;
    }
    case 1:
        self->gotoFlags = self->gotoFlags | 2;
        p = (float *)self->pos;
        p[0] = p[0] * 0.99f + self->home.x * 0.01f;
        {
            float *p2 = (float *)self->pos;

            p2[2] = p2[2] * 0.99f + self->home.z * 0.01f;
        }
        moveMotion(self);
        cModel_calcNullPart(self);
        Add_nullspeed(self);
        if ((self->gotoFlags & 0x40) != 0) {
            break;
        }
        if (CEM00_LOBYTE(self->unk1560) != 5) {
            if (self->playerDist < 16.0f) {
                if (cEma2_ckLineToPlayer(self) != 0) {
                    self->step = 2;
                }
            }
            if (inFront == 0) {
                self->step = 2;
            }
        }
        if ((self->gotoFlags & 8) != 0) {
            self->step = 2;
        }
        if (self->unk15BC <= 0.0f) {
            self->unk15BC = fRand0_1() * 90.0f + 90.0f;
            if (inFront != 0) {
                cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5A, self, 0, 0, 0, 0);
            }
        }
        break;
    case 2: {
        int b = self->resource;
        func_002A8578(self, EM_RES_REC(b, 0x30), EM_RES_REC(b, 0x34), 0.0f, 0xA, 0, 0);
        self->gotoFlags = self->gotoFlags & 0xFFFFFFFE;
        CEM00_LOBYTE(self->unk1560) = 0;
        self->step = self->step + 1;
    }
    case 3:
        if (moveMotion(self) != 0) {
            if (capVu0MagnitudeSqXZ(&self->unk1590, self->pos) < 1.0f) {
                float dy;
                float ady;

                ady = (dy = self->unk1590.y - self->pos->y);
                if (dy < 0.0f) {
                    ady = -dy;
                }
                if (ady < 1.0f) {
                    self->mode = 0;
                    self->phase = 0;
                    self->step = (dy = 0);
                    self->stepArg = 0;
                    break;
                }
            }
            func_002A74E0(self, &self->unk1590, 1);
            func_002A7CA0(self, &self->unk1570);
            self->mode = 0;
            self->phase = 4;
            self->step = 0;
            self->stepArg = 0;
        }
        cModel_calcNullPart(self);
        Add_nullspeed(self);
        break;
    }
}

/* cEm00_stepWatchTargetAttack: a fighter that watches another enemy and, once its own
 * cooldown is over and the player is alive, turns toward the player and
 * picks an attack. */













__attribute__((section(".text.cEm00_stepWatchTargetAttack")))
void cEm00_stepWatchTargetAttack(cEm00 *self)
{
    unsigned char fr[0x20] __attribute__((aligned(16)));
    cVec *cpos;
    float d;
    cEm00 *player;
    cEm00 *target;
    cOmBase *child;
    int go;
    float yaw;
    float ad;

    player = Getplayer();
    target = self->target;
    self->unk1560 = self->unk1560 | 2;
    switch (self->step) {
    case 0: {
        int res = self->resource;
        func_002A8578(self, EM_RES_REC(res, 0x10), EM_RES_REC(res, 0x14), 0.0f, 5, 0, 0);
        self->step = self->step + 1;
    }
    case 1:
        if (moveMotion(self) == 0) {
            return;
        }
        if (player->vital <= 0) {
            return;
        }
        if (0.0f < self->unk15B4) {
            return;
        }
        if (target == 0) {
            return;
        }
        if (target->vital <= 0) {
            return;
        }
        go = 0;
        if (36.0f < target->playerDist) {
            go = 1;
        }
        if (0.5235988f < target->unk760) {
            go = 1;
        }
        if (cCoreSave_getGameLevel(D_00569B70) >= 3) {
            if (target->vital <= target->vitalMax / 2) {
                go = 1;
            }
        }
        if (cCoreSave_getGameLevel(D_00569B70) >= 5) {
            go = 1;
        }
        if (go == 0) {
            return;
        }
        child = cOmBase_childAt((cOmBase *)self, (int *)fr, 0);
        if (child == 0) {
            return;
        }
        VU0_SQC2_VF0(fr, 0x10);
        *(float *)(fr + 0x10) = 0.0f;
        *(float *)(fr + 0x14) = 0.0f;
        *(float *)(fr + 0x18) = 1.0f;
        sceVu0ApplyMatrix(fr + 0x10, child->mtx, fr + 0x10);
        {
            cVec *q = child->pos;

            VU0_LQC2(4, fr, 0x10);
            VU0_LQC2(5, q, 0x0);
        }
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, fr, 0x10);
        yaw = capVu0Atan2(*(float *)(fr + 0x10), *(float *)(fr + 0x18));
        cpos = child->pos;
        player = Getplayer();
        ad = (d = Turn_dest(cpos, player->pos, yaw, 3.14159274f));
        if (d < 0.0f) {
            ad = -d;
        }
        if (!(ad < 0.5235988f)) {
            return;
        }
        if (100.0f < target->playerDist && (irand() & 1) != 0 && cCoreSave_getGameLevel(D_00569B70) < 3) {
            goto charge;
        }
        if (cCoreSave_getGameLevel(D_00569B70) == 1) {
charge:
            self->stepArg = 0;
            self->mode = 0;
            self->step = (d = 0);
            self->phase = 2;
        } else {
            self->phase = 1;
            self->unk15B4 = 450.0f;
            self->step = 0;
            self->stepArg = 0;
            self->mode = 0;
        }
        break;
    }
}

/* Append a mesh node to the model's list and grow the model's box by the
 * node's own box; the first mesh sets the box. */
__attribute__((section(".text.cModel_addMesh")))
void cModel_addMesh(cModel *self, cModelNode *node, cBox *box) {
    int num = GetField_2B1_14B638(self);
    if (num == 0) {
        self->meshHead = node;
    } else {
        cModel_getMeshPtr(self, num - 1)->next = node;
    }
    self->meshNum++;
    if (self->meshNum == 1) {
        self->box = *box;
    } else {
        func_001F91D0(&self->box, box);
    }
}

/* STL __unguarded_partition: split [first, last) around pivot and return the
 * split point. Both scans stop at an entry that does not sort on their side. */
__attribute__((section(".text.cGameObjSortEnt_unguardedPartition")))
cGameObjSortEnt *cGameObjSortEnt_unguardedPartition(cGameObjSortEnt *first, cGameObjSortEnt *last, cGameObjSortEnt pivot)
{
    for (;;) {
        while (cGameObjSortEnt_less(first, &pivot))
            ++first;
        --last;
        while (cGameObjSortEnt_less(&pivot, last))
            --last;
        if (!(first < last))
            return first;
        {
            cGameObjSortEnt tmp = *first;
            *first = *last;
            *last = tmp;
        }
        ++first;
    }
}

/* STL __unguarded_linear_insert: move the entries before last up by one
 * while val sorts before them, then drop val into the hole. The caller
 * guarantees an entry that does not sort after val sits in front. */
__attribute__((section(".text.cGameObjSortEnt_unguardedLinearInsert")))
void cGameObjSortEnt_unguardedLinearInsert(cGameObjSortEnt *last, cGameObjSortEnt val, void *tag)
{
    cGameObjSortEnt *next = last - 1;

    while (cGameObjSortEnt_less(&val, next)) {
        *last = *next;
        last = next;
        next--;
    }
    *last = val;
}

/* STL __adjust_heap: sink the hole at holeIndex to the bottom along the
 * larger child, then float val back up with the push-heap step. */
__attribute__((section(".text.cGameObjSortEnt_adjustHeap")))
void cGameObjSortEnt_adjustHeap(cGameObjSortEnt *first, int holeIndex, int len, cGameObjSortEnt val, void *tag)
{
    cGameObjSortEnt copy;
    int topIndex = holeIndex;
    int child = 2 * holeIndex + 2;

    while (child < len) {
        if (cGameObjSortEnt_less(first + child, first + (child - 1)))
            child--;
        first[holeIndex] = first[child];
        holeIndex = child;
        child = 2 * (child + 1);
    }
    if (child == len) {
        first[holeIndex] = first[child - 1];
        holeIndex = child - 1;
    }
    copy = val;
    cGameObjSortEnt_pushHeap(first, holeIndex, topIndex, cGameObjSortEnt_pack(&copy), tag);
}
