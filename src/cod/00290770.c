/* sn-2.95.3-136 matched TU. */

#include "godhand/cGameObj.h"
#include "godhand/cEma2.h"
#include "godhand/cEmSetParam.h"

extern void func_002A8B90(cGameObjSortEnt *first, cGameObjSortEnt *last, void *tag, void *tagB, void *tagC);
extern void func_002A8AA8(cGameObjSortEnt *first, int holeIndex, int len, long val, void *tag);
extern void func_002A8C48(cGameObjSortEnt *first, cGameObjSortEnt *last, void *tag);
extern int Obj0000_IsSet_Field_16D0_Bit_1_26ECC0(cGameObj *obj);
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);
extern void func_002956F0(cEmSetParam *setParam, cEmActor *em);
extern void func_002956A0(cEmSetParam *setParam, cEmActor *em);
extern void ReleaseObj(cEmActor *em);

/* STL __partial_sort: heap the first [first, middle) entries, then let every
 * entry in [middle, last) that sorts before the heap's top replace the top.
 * The heap is sorted at the end. top is a separate copy of first that every
 * call reads, which is how retail keeps both registers. */
__attribute__((section(".text.func_002A8D30")))
void func_002A8D30(cGameObjSortEnt *first, cGameObjSortEnt *middle, cGameObjSortEnt *last, void *unused, void *tag)
{
    cGameObjSortEnt *i;
    cGameObjSortEnt *top;

    top = first;
    func_002A8B90(top, middle, tag, 0, 0);
    for (i = middle; i < last; ++i) {
        top = first;
        if (cGameObjSortEnt_less(i, top)) {
            cGameObjSortEnt val = *i;
            cGameObjSortEnt copy = val;

            *i = *top;
            func_002A8AA8(top, 0, middle - top, cGameObjSortEnt_pack(&copy), tag);
        }
    }
    func_002A8C48(top, middle, tag);
}

/* 1 when some listed enemy other than skip, with an actor id in 0x200..0x24F
 * and the 0x16D0 bit 1 flag set, is within radius of pos (compared squared,
 * in the xz plane). */
__attribute__((section(".text.func_00291AC8")))
int func_00291AC8(cEmManage *self, cVec *pos, cEmActor *skip, float radius)
{
    cEmSlot *slot;
    cGameObj *em;
    float dist;
    float range;
    int tooHigh;
    int id;

    for (slot = self->list.top; slot != 0; slot = slot->next) {
        em = (cGameObj *)slot->em;
        if (em == 0)
            continue;
        if (em == (cGameObj *)skip)
            continue;
        id = em->actorId;
        if (id < 0x200)
            continue;
        tooHigh = id >= 0x250;
        if (tooHigh)
            continue;
        if (Obj0000_IsSet_Field_16D0_Bit_1_26ECC0(em) == 0)
            continue;
        dist = capVu0MagnitudeSqXZ(em->pos, pos);
        range = radius * radius;
        if (dist < range)
            return 1;
    }
    return 0;
}

/* Releases the listed enemy em: tells the placement list about it, deletes
 * the actor, unlinks and clears its slot and updates the counts. Returns 1
 * when em was listed, 0 when it was not. */
__attribute__((section(".text.cEmManage_ReleaseEm")))
int cEmManage_ReleaseEm(cEmManage *self, cEmActor *em)
{
    cEmSlot *slot;
    int kind;

    func_002956F0(&D_00586AB0, em);
    for (slot = self->list.top; slot != 0; slot = slot->next) {
        if (slot->em != em)
            continue;
        func_002956A0(&D_00586AB0, em);
        ReleaseObj(em);
        cEmList_unlink(&self->list, slot);
        kind = slot->kind;
        cEmManage_clearSlot(slot);
        if (cEmManage_countKind(self, kind) == 0)
            self->kindNum--;
        self->emNum--;
        return 1;
    }
    return 0;
}
