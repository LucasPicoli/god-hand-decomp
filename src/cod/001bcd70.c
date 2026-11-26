/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 -fno-gcse */
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

extern int cDamageUnit_SetDamageCollActive(void *a0, int a1);
extern void *cModel_getMeshPtr(void *a0, int a1);
extern void cModel_calcParts(void *a0);
extern void func_001BCB38(char *a0, int a1, float *a2, float *a3);

#define PARTSBOX_MESH_LATE  0x2000      /* cModelNode.dispFlags bit set on both meshes */

/* A cOmBase object with a damage unit and its own count of placed parts. */
typedef struct cOmPartsBox {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    void *damage;                       /* 0x600 damage unit, 0 when none */
    char unk604[0x624 - 0x604];
    signed char partCount;              /* 0x624 parts placed by func_001BCB38 */
} cOmPartsBox;

/* Switches the damage unit off, shows mesh 0 and hides mesh 1, hides the model,
 * clears the skip-local and skip-parent bits of parts 1.., then places each
 * part from a 1/100 copy of the knock vector with y raised by 0.02. */
__attribute__((section(".text.func_001BCD70")))
void func_001BCD70(cOmPartsBox *self)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, n;
    unsigned int j;
    cOmBase *obj1, *obj2;
    int b1, b2, t;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    cVec *knock;

    if (self->damage != 0) cDamageUnit_SetDamageCollActive(self->damage, 0);
    knock = &self->base.knock;
    ((cModelNode *)cModel_getMeshPtr(self, 1))->dispFlags |= CMODEL_NODE_HIDE;
    ((cModelNode *)cModel_getMeshPtr(self, 0))->dispFlags &= ~CMODEL_NODE_HIDE;
    ((cModelNode *)cModel_getMeshPtr(self, 0))->dispFlags |= PARTSBOX_MESH_LATE;
    ((cModelNode *)cModel_getMeshPtr(self, 1))->dispFlags |= PARTSBOX_MESH_LATE;
    v = (float *)(frame + 0x20);
    i = 1;
    self->base.objFlags |= CMODEL_F_HIDDEN;

    /* The child lookups are cOmBase_childAt inlined with a variable lower bound; each
     * writes the child count to the bottom stack slot, a dead store retail keeps. The
     * do-while(0) around the loop raises the reference counts of its pseudos, which
     * gives retail's a0..a2 picks. */
    if (i < self->partCount && (b1 = (t = self->base.partNum), t != i)) {
        do {
        lo = 0;
        m1 = ~CPARTS_NO_LOCAL;
        m2 = ~CPARTS_NO_PARENT;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1), (n >= lo && i < b1));
        if (ok1) obj1 = self->base.children[i]; else obj1 = 0;
        obj1->partFlags &= m1;
        ok2 = ((*(int *)frame = b2 = self->base.partNum), (n >= lo && i < b2));
        if (ok2) obj2 = self->base.children[i]; else obj2 = 0;
        obj2->partFlags &= m2;
        i++;
        n++;
        if (i < self->partCount && (b1 = (t = self->base.partNum), t != i)) goto loop;
        } while (0);
    }

    cModel_calcParts(self);
    VU0_LQC2(4, knock, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.02f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < self->partCount; j++) {
        if (self->base.partNum == j) break;
        func_001BCB38((char *)self, j, (float *)(frame + 0x10), v);
    }
}
