/* sn-2.95.3-136 matched TU. */

#include "godhand/seqTrack.h"
#include "godhand/cModel.h"
#include "godhand/heapArena.h"
#include "godhand/cOmBase.h"
#include "godhand/cDamageManage.h"
#include "godhand/vu0.h"
#include "godhand/cGrid.h"

extern void cHeap_free(void *heap, void *p);
extern void *_MemoryAlloc(int size, int align, void *heap);
extern void func_00154A90(cModelNode *node, void *buf, int c);
extern void func_00155358(cModelNode *node, void *buf, int c);
extern void func_00148F50(cModelNode *node, cMeshData **data, void *box);
extern void func_001490B0(cModelNode *node, cMeshData **data, void *box);
extern char D_005CAE50[];

/* sn-2.95.3-136 matched TU. */


/* Copy one table entry of the track into each running kind-2 node it owns; part picks the table. */
__attribute__((section(".text.SeqTrack_copyPartTables")))
void SeqTrack_copyPartTables(SeqTrackTbl *trk, unsigned short part)
{
    int i;
    for (i = 0; i < SEQNODE_NUM; i++) {
        SeqNodeCopy *n = &D_0076CF20[i];
        if (n->flags == 0) continue;
        if ((n->kind & SEQNODE_KIND_LIVE) == 0) continue;
        if (n->owner != trk->id) continue;
        switch (part) {
        case SEQTRACK_PART_A:
            n->cfgA = trk->tblA[n->index / 2];
            n->cfgB = trk->tblB[n->index / 2];
            n->sub |= SEQNODE_SUB_A;
            break;
        case SEQTRACK_PART_B:
            n->cfgC = trk->tblC[n->index % 2];
            n->sub |= SEQNODE_SUB_B;
            break;
        }
    }
}

/* sn-2.95.3-136: model node setup with an allocating path; frees the old packet data, allocates new data from the arena (or the default one) and fills it (0x148420). */












__attribute__((section(".text.cModelNode_setupAlloc")))
int cModelNode_setupAlloc(cModelNode *node, cMeshData *data, int b, int flags, int n, void *box, void *arena)
{
    cMeshData *ref;
    void *buf;
    unsigned short num;
    int big;

    node->unk400 = b;
    node->unk384 = 0;
    node->dispFlags = flags;
    node->tag = 0;
    node->data = data;
    ref = data;
    num = data->num;
    node->meshNum = num;
    if (node->pktBuf != 0) {
        cHeap_free(((void **)node->pktBuf)[-8], (void *)node->pktBuf);
    }
    big = ref->num >= 2;
    if (big) {
        int size = func_00155138(node);
        if (arena == 0) {
            buf = _MemoryAlloc(size, 0x10, D_003C3CF0);
            node->pktBuf = (int)buf;
            if (buf == 0) {
                goto ng;
            }
            func_00154A90(node, buf, (int)arena);
        } else {
            buf = _MemoryAlloc(size, 0x10, arena);
            node->pktBuf = (int)buf;
            if (buf == 0) {
                goto ng;
            }
            func_00154A90(node, buf, (int)arena);
        }
    } else {
        int size = func_00155248(node);
        if (arena == 0) {
            node->pktBuf = (int)_MemoryAlloc(size, 0x10, D_003C3CF0);
        } else {
            node->pktBuf = (int)_MemoryAlloc(size, 0x10, arena);
        }
        {
            /* A volatile reload of pktBuf: retail reads the stored value back before the test. */
            int pb = *(volatile int *)&node->pktBuf;
            if (pb == 0) {
            ng:     /* one failure exit for both arms; per-arm returns do not match */
                return 0;
            }
            func_00155358(node, (void *)pb, 0);
        }
    }
    if (flags & CMODEL_NODE_BACK) {
        func_00148F50(node, &ref, box);
    } else {
        func_001490B0(node, &ref, box);
    }
    return 1;
}

/* sn-2.95.3-136 matched TU. */





/* The record this setup fills: a cOmBase plus a take, a short and two flags. */
typedef struct cOmBoxObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    short unk600;                       /* 0x600 cleared at setup */
    char unk602[0x60C - 0x602];
    cDamageTake *take;                  /* 0x60C */
    char unk610[0x770 - 0x610];
    unsigned char unk770;               /* 0x770 */
    unsigned char unk771;               /* 0x771 */
} cOmBoxObj;

/* The six face records func_0012EAD8 copies into the box. */
typedef struct cOmBoxFaces {
    cVec v[6];
} cOmBoxFaces;



extern cOmBoxFaces D_00422630;

static __inline__ void ombox_vec(cVec *v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

/* Sets the object up: a sphere take on the first child, 297 hit points and
 * the collision box. */
__attribute__((section(".text.cOmBoxObj_setup")))
int cOmBoxObj_setup(cOmBoxObj *self)
{
    cVec size;
    cVec center;
    int frame[3];
    cVec half;
    cOmBoxObj *owner;
    cVec zero;
    cOmBoxFaces faces;
    float *mtx;
    /* Steering found by the permuter: a copy of self, a second pointer for
     * the mtx read and one store through (*&box). The plain spelling builds
     * the same code with the face-argument registers rotated (164/177). */
    cOmBoxObj *box = self;

    func_001B6FB8(&box->base);
    ombox_vec(&size, 2.0f, 3.5f, 1.6f, 1.0f);
    ombox_vec(&center, 0.0f, 1.5f, 0.5f, 1.0f);
    box->take = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)box, 1);
    owner = box;
    if (box->take != 0) {
        cOmBase *child = cOmBase_childAt(&box->base, frame, 0);
        cDamageUnit_AddDamageCollSphere((cDamageUnit *)box->take,
                                        (const struct cMatrix *)child->mtx, &center, 0.7f);
        box->take->flags |= 1;
        cDamageUnit_SetDamageCollActive((cDamageUnit *)box->take, 1);
    }
    box->base.hpMax = 0x129;
    box->base.hp = 0x129;
    ombox_vec(&center, size.x, size.y, size.z, 1.0f);
    VU0_VADDX_XYZ_MEM(&center, 0, 0.1f);
    ombox_vec(&half, 0.0f, size.y * 0.5f, 0.0f, 1.0f);
    ombox_vec(&zero, 0.0f, 0.0f, 0.0f, 1.0f);
    faces = D_00422630;
    mtx = owner->base.mtx;
    func_0012EAD8(D_005CAE50, box, mtx, &half, &zero, &center,
                  &faces.v[0], &faces.v[1], &faces.v[2], &faces.v[3], &faces.v[4], &faces.v[5]);
    box->base.flags2 |= 0x188;
    box->base.scrFlags |= 0x10;
    box->unk770 = 0;
    box->unk771 = 0;
    (*&box)->unk600 = 0;
    return 1;
}
