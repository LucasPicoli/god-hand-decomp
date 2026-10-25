/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBreakable.h"

extern int func_001B6FB8(cOmBreakable *self);    /* cOmBase constructor step */
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void *cDamageManage_CreateDamageGive(void *mgr, int kind, void *owner);
extern int cDamageUnit_AddDamageCollSphere(void *unit, void *mtx, float *ofs, float r);
extern void cDamageUnit_SetDamageCollActive(void *unit, int on);

extern cMeshNode *cModel_getMeshPtr(cOmBreakable *self, int idx);
extern char D_00574380[];                        /* the damage manager */

/* Set up a breakable with a 0.6 x 1.5 x 0.6 damage-take box and a radius 1 damage-give sphere, one hit point, and hide its first mesh while it is whole. */
__attribute__((section(".text.cOmBreakable_setupSmallBox")))
int cOmBreakable_setupSmallBox(cOmBreakable *em)
{
    cVec v[4];             /* size twice, offset, rotation */
    cVec *ofs;
    cVec *rot;
    cVec *size;
    float *ov;
    void *slot;
    void *give;
    int i, idx, lo, cnt1, cnt2;
    unsigned char ok1, ok2;
    cOmBreakPiece *pieceA;
    cOmBreakPiece *pieceB;

    func_001B6FB8(em);
    size = &v[1];
    ofs = &v[2];
    v[0].x = 0.6f;
    v[0].y = 1.5f;
    v[0].z = 0.6f;
    v[1].y = 1.5f;
    v[0].w = 1.0f;
    v[1].x = 0.6f;
    v[1].z = 0.6f;
    size->w = 1.0f;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    ofs->w = 1.0f;
    slot = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->dmgTake = slot;
    if (slot != 0) {
        rot = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        rot->w = 1.0f;
        func_001FD9D8(slot, em->base.mtx, ofs, rot, size);
    }
    give = cDamageManage_CreateDamageGive(D_00574380, 0, (char *)em);
    em->dmgGive = give;
    if (give != 0) {
        ov = &v[3].x;
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        ov[3] = 1.0f;
        cDamageUnit_AddDamageCollSphere(give, em->base.mtx, ov, 1.0f);
        *(short *)(((char *)em->dmgGive) + 0x46) = 0x2E;
        *(int *)(((char *)em->dmgGive) + 0x4C) = 0;
        cDamageUnit_SetDamageCollActive(em->dmgGive, 0);
    }
    em->base.hp = em->base.hpMax = 1;
    em->wait = 30;
    cModel_getMeshPtr(em, 0)->dispFlags |= COMBREAK_MESH_HIDE;
    cModel_getMeshPtr(em, 1)->dispFlags &= ~COMBREAK_MESH_HIDE;
    i = COMBREAK_PIECE_FIRST;
    if (em->base.childNum != i) {
        lo = 0;
        idx = 1;
        while (1) {
            /* cOmBase_childAt written out twice: its count store into v[1] is a dead store retail keeps */
            ok1 = ((*(int *)&v[1] = cnt1 = em->base.childNum), (idx >= lo && i < cnt1));
            if (ok1) pieceA = (cOmBreakPiece *)em->base.children[i]; else pieceA = 0;
            pieceA->partFlags |= COMBREAK_PART_NO_LOCAL;
            ok2 = ((*(int *)&v[1] = cnt2 = em->base.childNum), (idx >= lo && i < cnt2));
            if (ok2) pieceB = (cOmBreakPiece *)em->base.children[i]; else pieceB = 0;
            pieceB->partFlags |= COMBREAK_PART_NO_PARENT;
            i++;
            idx++;
            if (!(i < COMBREAK_PIECE_END && em->base.childNum != i)) break;
        }
    }
    return 1;
}
