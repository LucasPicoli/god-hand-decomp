/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmDamageBox.h"
#include "godhand/player.h"

extern int func_001B6FB8(cOmDamageBox *self);    /* cOmBase constructor step */
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void *cDamageManage_CreateDamageGive(void *mgr, int kind, void *owner);
extern int cDamageUnit_AddDamageCollSphere(void *unit, void *mtx, float *ofs, float r);
extern int cDamageUnit_AddDamageCollCylinder(void *unit, void *mtx, float *ofs, float *rot, float h, float r);
extern void cDamageUnit_SetDamageCollActive(void *unit, int on);
extern void cOmBase_setMeshDispFromLayer(cOmDamageBox *self, int a, int b);
extern char D_00574380[];                        /* the damage manager */

/* Set up a 0.872 x 1.34 damage-take cylinder and a radius 2.5 damage-give sphere sized by the player's power, 50 hit points, and flag every piece. */
__attribute__((section(".text.cOmDamageBox_setupGuard")))
int cOmDamageBox_setupGuard(cOmDamageBox *em)
{
    cVec v[4];             /* size twice, offset, rotation */
    cVec *ofs;
    cVec *rot;
    float *ov;
    void *slot;
    void *give;
    cOmDamageBoxPlayer *pl;
    int i, idx, lo, cnt1, cnt2;
    unsigned char ok1, ok2;
    cOmBreakPiece *pieceA;
    cOmBreakPiece *pieceB;

    func_001B6FB8(em);
    ofs = &v[2];
    v[0].x = 0.872f;
    v[0].y = 1.34f;
    v[0].z = 0.872f;
    v[1].y = 1.34f;
    v[0].w = 1.0f;
    v[1].x = 0.872f;
    v[1].z = 0.872f;
    v[1].w = 1.0f;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    ofs->w = 1.0f;
    give = cDamageManage_CreateDamageGive(D_00574380, 3, (char *)em);
    em->dmgGive = give;
    if (give != 0) {
        pl = (cOmDamageBoxPlayer *)Getplayer();
        ov = &v[3].x;
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        ov[3] = 1.0f;
        cDamageUnit_AddDamageCollSphere(em->dmgGive, em->base.mtx, ov, 2.5f);
        *(short *)(((char *)em->dmgGive) + 0x46) = 0x52;
        *(int *)(((char *)em->dmgGive) + 0x4C) = (int)(pl->power * 80.0f);
        cDamageUnit_SetDamageCollActive(em->dmgGive, 0);
    }
    slot = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->dmgTake = slot;
    if (slot != 0) {
        rot = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        rot->w = 1.0f;
        cDamageUnit_AddDamageCollCylinder(slot, em->base.mtx, &ofs->x, &rot->x, v[1].y, v[1].x * 0.5f);
    }
    em->unk65C = 0;
    em->base.hp = em->base.hpMax = 50;
    cOmBase_setMeshDispFromLayer(em, 0, 1);
    cOmBase_setMeshDispFromLayer(em, 0x40, 0);
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
            if (!(i < 7 && em->base.childNum != i)) break;
        }
    }
    return 1;
}
