/* sn-2.95.3-136 matched TU. */

#include "godhand/cDamageUnit.h"
#include "godhand/cDvd.h"

extern void CustomIDWork_SetMessNo(void *work, int messNo);
extern void cDamageUnit_SetDamageCollActive(cDamageUnit *self, int active);
extern void cOmWeapon_SetBreak(int weapon);

/* cCollisionShape: copy the position vector in, then call the shape's virtual update (vt[10]). */


#define CSHAPE_VT_UPDATE  10            /* 0x50 into the delta/index/pfn table */

/* The shape past its vtable pointer: the position at 0x110. */
typedef struct cCollisionShapePos {
    cCollisionShape base;               /* 0x000 */
    char unk104[0xC];
    float pos[3];                       /* 0x110 */
} cCollisionShapePos;

__attribute__((section(".text.cCollisionShape_setPos")))
void cCollisionShape_setPos(cCollisionShapePos *self, float *pos) {
    float *dst = self->pos;
    cDamageVtEnt *ent;
    if (dst != pos) {
        dst[0] = pos[0];
        dst[1] = pos[1];
        dst[2] = pos[2];
    }
    ent = &self->base.vt[CSHAPE_VT_UPDATE];
    ((void (*)(void *))ent->pfn)((char *)self + ent->delta);
}

/* Put message `messNo` on the second display element, then switch both elements on or off. */
#define UIPANEL_WORK_SIZE  0x7C         /* sizeof(CustomIDWork) */

typedef struct UiPanelWork {
    char unk00[UIPANEL_WORK_SIZE];
} UiPanelWork;

typedef struct UiPanel {
    char unk00[0x580];
    UiPanelWork work[2];                /* 0x580 the two display elements */
} UiPanel;


extern void func_001E7538(UiPanel *self, int no, int on);   /* show or hide element no, 2 = both */

__attribute__((section(".text.UiPanel_setMessAndShow")))
void UiPanel_setMessAndShow(UiPanel *self, int messNo, int on) {
    CustomIDWork_SetMessNo(&self->work[1], messNo);
    func_001E7538(self, 0, on);
    func_001E7538(self, 1, on);
}

/* Switch both damage units off: clear their hit values and deactivate every node. */


/* The unit past its node list: the two hit values the init sets to 0x30/0x48 and 0x32. */
typedef struct DamageUnitHit {
    cDamageUnit base;                   /* 0x00 */
    char unk40[6];
    short hitA;                         /* 0x46 */
    char unk48[4];
    int hitB;                           /* 0x4C */
} DamageUnitHit;

typedef struct DamagePairObj {
    char unk000[0x66C];
    DamageUnitHit *unitA;               /* 0x66C */
    DamageUnitHit *unitB;               /* 0x670 */
} DamagePairObj;



__attribute__((section(".text.DamagePairObj_clearHits")))
void DamagePairObj_clearHits(DamagePairObj *self) {
    self->unitA->hitA = 0;
    self->unitA->hitB = 0;
    cDamageUnit_SetDamageCollActive(&self->unitA->base, 0);
    self->unitB->hitA = 0;
    self->unitB->hitB = 0;
    cDamageUnit_SetDamageCollActive(&self->unitB->base, 0);
}

/* cDvd: give all 32 jobs back, then reset the running job, the id counter and the queue length. */


__attribute__((section(".text.cDvd_init")))
void cDvd_init(cDvd *self) {
    cDvdJob *job = self->job;
    int i;
    for (i = CDVD_JOB_NUM - 1; i >= 0; i--) {
        func_00201228(self, job);
        job++;
    }
    self->idCounter = 0;
    self->queueNum = 0;
    self->cur = 0;
}

/* Enemy 0x211: break each of its 8 held weapons and forget the handles. */
#define EM_NO_WEAPON_HOLDER  0x211      /* emNo of the enemy that holds the weapons */
#define EM_WEAPON_NUM        8

/* The enemy record: the number at 0x564 and the weapon handle array at 0x710. */
typedef struct EmWeaponHolder {
    char unk000[0x564];
    int emNo;                           /* 0x564 */
    char unk568[0x1A8];
    int weapon[EM_WEAPON_NUM];          /* 0x710 weapon handles, 0 = empty slot */
} EmWeaponHolder;



__attribute__((section(".text.cEm_breakHeldWeapons")))
void cEm_breakHeldWeapons(EmWeaponHolder *self) {
    unsigned int i;
    /* The xor spelling is what gives retail's xori + bnez; a plain == gives li + bne. */
    if ((self->emNo ^ EM_NO_WEAPON_HOLDER) == 0) {
        for (i = 0; i < EM_WEAPON_NUM; i++) {
            if (self->weapon[i] != 0) {
                cOmWeapon_SetBreak(self->weapon[i]);
                self->weapon[i] = 0;
            }
        }
    }
}
