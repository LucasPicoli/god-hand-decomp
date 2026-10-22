/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/cDamageUnit.h"
#include "godhand/vu0.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmHitVolumeSetup.h"

#define BREAK_FIRST_PIECE   6
#define BREAK_PIECE_END     15
#define BREAK_PUSH_SCALE    0.005f
#define BREAK_PUSH_LIFT     0.099999994f
#define BREAK_EFFECT        10
#define BREAK_DONE          0x80000000

/* An attack volume the object owns; bit 0 of flags keeps it live. */
typedef struct BreakVol {
    char unk00[0x8];
    int flags;                          /* 0x08 */
} BreakVol;

/* A breakable map object: two damage units, three attack volumes and the
 * pieces it scatters, held as children from BREAK_FIRST_PIECE up. */
typedef struct cOmBreakable {
    cOmBase base;
    char unk5E0[0x24];
    cDamageUnit *dmgA;                  /* 0x604 */
    cDamageUnit *dmgB;                  /* 0x608 */
    BreakVol *vol[3];                   /* 0x60C */
    char unk618[0x3B8];
    unsigned int flags;                 /* 0x9D0 */
} cOmBreakable;

typedef struct BreakFrame {
    cVec push;                          /* 0x00 */
    cVec rot;                           /* 0x10 */
} BreakFrame;

extern char D_00462FC0[];

extern void cCollisionSolidManage_SetActive(int a0, int a1, int a2);
extern void func_001AA8D8(char *a0, int a1, float *a2, float *a3);

/* Break the object: switch its damage and collision off, scatter every piece
 * along the knock vector and start the break effect. */
__attribute__((section(".text.func_001AAB10")))
void func_001AAB10(cOmBreakable *self)
{
    BreakFrame f __attribute__((aligned(16)));
    unsigned int i;

    if (self->dmgB != 0) {
        cDamageUnit_SetDamageCollActive(self->dmgB, 0);
    }
    if (self->dmgA != 0) {
        cDamageUnit_SetDamageCollActive(self->dmgA, 0);
    }
    if (self->vol[0] != 0) {
        self->vol[0]->flags &= ~1;
    }
    if (self->vol[1] != 0) {
        self->vol[1]->flags &= ~1;
    }
    if (self->vol[2] != 0) {
        self->vol[2]->flags &= ~1;
    }
    cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
    VU0_LQC2(4, &self->base.knock, 0);
    VU0_SQC2(4, &f, 0);
    cVec_set4(&f.rot, 0.0f, 0.0f, 0.0f, 1.0f);
    VU0_VSCALE_XYZ_MEM(&f, 0, BREAK_PUSH_SCALE);
    f.push.y += BREAK_PUSH_LIFT;
    for (i = BREAK_FIRST_PIECE; i < BREAK_PIECE_END && self->base.childNum != i; i++) {
        func_001AA8D8((char *)self, i, &f.push.x, &f.rot.x);
    }
    SetEffect(1, BREAK_EFFECT, self, 0, BREAK_EFFECT, (unsigned int)self);
    self->flags |= BREAK_DONE;
}
