/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 -fno-gcse: cOmTwin setup. Creates the two helper objects and runs their init
 * method, makes the 1.0 x 2.0 x 1.0 damage-take volume, sets hp to 10, hides mesh layer 0 and
 * flags the child bodies 1..5 with mesh flags A and B. */
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/cOmTwin.h"
#include "godhand/cModel.h"

extern cOmBase *CreateObj(int id, int a1);
extern void cOmBase_setMeshDispFromLayer(void *model, int layer, int show);

__attribute__((section(".text.cOmTwin_setup")))
int cOmTwin_setup(cOmTwin *self)
{
    cVec v[4];
    cVec *size;
    cVec *ofs;
    cVec *rot;
    cOmTwinPart *part;
    void *slot;
    int i;
    int n, lo, b1, b2;
    unsigned char ok1, ok2;
    cOmTwinPart *obj1, *obj2;

    func_001B6FB8((cOmHitVolume *)self);
    self->partA = CreateObj(COMTWIN_KIND, 0xFFFF);
    self->partB = CreateObj(COMTWIN_KIND, 0xFFFF);
    /* One vt local per arm: a shared function-scope local changes the bytes. */
    part = (cOmTwinPart *)self->partA;
    if (part != 0) {
        cGameObjVt *vt = cGameObj_vt((struct cGameObj *)part);
        vt->initial((char *)part + vt->initialDelta);
        ((cOmTwinPart *)self->partA)->state &= ~COMTWIN_PART_LIVE;
    }
    part = (cOmTwinPart *)self->partB;
    if (part != 0) {
        cGameObjVt *vt = cGameObj_vt((struct cGameObj *)part);
        vt->initial((char *)part + vt->initialDelta);
        ((cOmTwinPart *)self->partB)->state &= ~COMTWIN_PART_LIVE;
    }
    size = &v[1];
    ofs = &v[2];
    v[0].x = 1.0f;
    v[0].y = 2.0f;
    v[0].z = 1.0f;
    v[0].w = 1.0f;
    v[1].x = 1.0f;
    v[1].y = 2.0f;
    v[1].z = 1.0f;
    size->w = 1.0f;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    ofs->w = 1.0f;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (struct cGameObj *)self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        rot = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        rot->w = 1.0f;
        func_001FD9D8(slot, (const struct cMatrix *)self->base.mtx, ofs, rot, size);
        cDamageUnit_SetDamageCollActive(self->damageTake, 1);
    }
    self->base.hpMax = 10;
    self->base.hp = 10;
    cOmBase_setMeshDispFromLayer(self, 0, 1);
    cOmBase_setMeshDispFromLayer(self, 0x40, 0);
    /* The child lookups are cOmBase_childAt inlined with a variable lower bound; each writes
     * the child count to the bottom stack slot, a dead store retail keeps. */
    i = 1;
    if (self->base.partNum != i) {
        lo = 0;
        n = 1;
        while (1) {
            ok1 = ((*(int *)&v[1] = b1 = self->base.partNum), (n >= lo && i < b1));
            if (ok1) obj1 = (cOmTwinPart *)self->base.children[i]; else obj1 = 0;
            obj1->meshFlags |= COMTWIN_CHILD_FLAG_A;
            ok2 = ((*(int *)&v[1] = b2 = self->base.partNum), (n >= lo && i < b2));
            if (ok2) obj2 = (cOmTwinPart *)self->base.children[i]; else obj2 = 0;
            obj2->meshFlags |= COMTWIN_CHILD_FLAG_B;
            i++;
            n++;
            if (!(i < COMTWIN_MAX_CHILDREN && self->base.partNum != i)) break;
        }
    }
    self->base.flags2 = (self->base.flags2 & ~1) | 0x80;
    return 1;
}
