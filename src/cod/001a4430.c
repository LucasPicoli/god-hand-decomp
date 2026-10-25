/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/ColiseumBattle.h"
#include "godhand/cMovie.h"

extern void func_001B6FB8(void *self);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void cDamageUnit_AddDamageCollSphere(void *unit, void *mtx, cVec *pos, float radius);
extern void cOm4f_setOpenCloseRot(void *self, float a, float b);
extern void cOm4f_setCloseFix(void *self);
extern void cOm4f_setEventMode(void *self, int mode);
extern int D_00574380;
extern void displayScrollLayer(int layer, int show);
extern void cHeap_free(void *heap, void *p);
extern void Forward342910_342888(int handle);
extern void Obj3260_Tramp_00337C88_D208(void);
extern void Forward3443E0_3443C8(int handle);
extern void sndDrv_start(void);
extern void func_003A11F8(void);
extern char D_0044CD20[];
extern char D_0044CD40[];
extern char D_0044CD60[];
extern char D_0044CD80[];
extern char D_0044CDA0[];
extern char D_0044CDA8[];
extern char D_0044CDC8[];
extern int IsEntryActive_1C2490(int entry);
extern void ColiseumBattle_DefeatAllEnemies(ColiseumBattle *self);
extern void cEmSetParam_setEm(void *param, int slot);
extern void cEmWrap_StartAction(void *act);
extern char D_00586AB0[];
extern void sceVu0ApplyMatrix(cVec *dst, void *mtx, cVec *src);

#define OM4F_LIFE        0x270F         /* hit points, max and current */
#define OM4F_SPHERE_R    0.5f           /* hit sphere radius */
#define OM4F_ROT         1.0471976f      /* open/close angle: pi / 3 radians */
#define COMBASE_FLAG2_B3 0x08

/* The door body past cOmBase: open/close state bytes, the damage unit and the sphere centre. */
typedef struct Om4fObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x180];
    unsigned char active;               /* 0x760 */
    unsigned char open;                 /* 0x761 */
    unsigned char lock;                 /* 0x762 */
    unsigned char eventMode;            /* 0x763 */
    void *damage;                       /* 0x764 */
    char unk768[8];
    cVec sphere;                        /* 0x770 */
} Om4fObj;

/* Set the door up: a hit sphere of 0.5 at (0, 0, 0.7) through the damage manager, 9999 life, the open/close rotation, closed, unlocked, event mode 1. Returns 1. */
__attribute__((section(".text.cOm4f_construct")))
int cOm4f_construct(Om4fObj *self)
{
    cVec c;
    void *dmg;
    func_001B6FB8(self);
    c.x = 0.0f;
    c.y = 0.0f;
    c.z = 0.7f;
    c.w = 1.0f;
    dmg = cDamageManage_CreateDamageTake(&D_00574380, self, 1);
    self->damage = dmg;
    if (dmg != 0) {
        cDamageUnit_AddDamageCollSphere(dmg, self->base.mtx, &c, OM4F_SPHERE_R);
    }
    self->base.hpMax = OM4F_LIFE;
    self->base.hp = OM4F_LIFE;
    cVec_copy3(&self->sphere, &c);
    cOm4f_setOpenCloseRot(self, OM4F_ROT, -OM4F_ROT);
    self->base.flags2 |= COMBASE_FLAG2_B3;
    self->lock = 0;
    self->active = 0;
    cOm4f_setCloseFix(self);
    cOm4f_setEventMode(self, 1);
    return 1;
}

#define SLOT2_MARK_NUM      5
#define SLOT2_SEL_SHIFT     11          /* selector sits in bits 11..13 of the blink word */
#define BLINK_ARMED         0x8000
#define BLINK_ON            0x4000

typedef struct { int w[SLOT2_MARK_NUM]; } MarkTbl;

/* The mark layer ids and the blink word of the Slot2 object. */
typedef struct Slot2Marks {
    char unk000[0x400];
    int layer[0x2B];                    /* 0x400 mark layer ids, indexed through the mark table */
    unsigned short blink;               /* 0x4AC */
} Slot2Marks;

extern MarkTbl D_0042B8D0;              /* layer index of each mark */

/* Select a mark: store the selector (index below 5) in the blink word, arm the blink when armFlag is set, then show only the selected mark layer (showAll) or hide all five. */
__attribute__((section(".text.Slot2_selectMark")))
void Slot2_selectMark(Slot2Marks *self, unsigned int sel, int showAll, int armFlag)
{
    MarkTbl tbl;
    int i;
    int *p;
    sel = sel & 0xFFFF;
    tbl = D_0042B8D0;
    if (sel < SLOT2_MARK_NUM) {
        self->blink = sel << SLOT2_SEL_SHIFT;
        if (armFlag) {
            self->blink |= BLINK_ARMED;
        }
        if (showAll) {
            self->blink |= BLINK_ON;
            i = 0;
            p = tbl.w;
            for (; i < SLOT2_MARK_NUM; i++) {
                displayScrollLayer(self->layer[*p], i == sel);
                p++;
            }
        } else {
            p = tbl.w;
            for (i = SLOT2_MARK_NUM - 1; i >= 0; i--) {
                displayScrollLayer(self->layer[*p], 0);
                p++;
            }
        }
    }
}

#define FREE_BUF(p) if ((p) != 0) cHeap_free(*(void **)((char *)(p) - 0x20), (p))

#define RES_SIZE        0xAC            /* bytes cleared at the end */
#define RES_NONE        (-1)

/* Release everything the track owns and reset it: the effect buffer when flags is negative, the player handle, the five heap buffers; clear the whole record and set the two ids to -1 and the luminance pair to 31 and 100. */
__attribute__((section(".text.ResHolder_release")))
void ResHolder_release(cMovieTrack *self)
{
    if (self->flags < 0) {
        if (self->handle != 0) {
            Forward342910_342888(self->handle);
        }
        FREE_BUF(self->fxbuf);
        self->fxbuf = 0;
        Obj3260_Tramp_00337C88_D208();
    }
    if (self->handle != 0) {
        Forward3443E0_3443C8(self->handle);
    }
    FREE_BUF(self->buf04);
    FREE_BUF(self->work);
    FREE_BUF(self->stm[0]);
    FREE_BUF(self->stm[1]);
    FREE_BUF(self->img);
    self->handle = 0;
    self->buf04 = 0;
    self->work = 0;
    self->stm[0] = 0;
    self->stm[1] = 0;
    self->img = 0;
    self->cell18 = 0;
    func_003A52F0(self, 0, RES_SIZE);
    self->id58 = RES_NONE;
    self->lumi0 = 0x1F;
    self->lumi1 = 0x64;
    self->id5C = RES_NONE;
}

extern char D_005E8140[];               /* request queue */








#define REQ_FILE_NUM  7                 /* length of the fourth request's name list */
#define REQ_LAST_NUM  0x13

/* Send the boot requests to the queue, retrying each until it is accepted: three plain ones, the 7 entry list, then (after two setup calls with no argument) the 0x13 entry list. */
__attribute__((section(".text.System_sendBootRequests")))
void System_sendBootRequests(void)
{
    while (func_002BE240(D_005E8140, D_0044CD20, 0, 0) < 0) {
    }
    while (func_002BE240(D_005E8140, D_0044CD40, 0, 0) < 0) {
    }
    while (func_002BE240(D_005E8140, D_0044CD60, 0, 0) < 0) {
    }
    while (func_002BE240(D_005E8140, D_0044CD80, REQ_FILE_NUM, D_0044CDA0) < 0) {
    }
    sndDrv_start();
    func_003A11F8();
    while (func_002BE240(D_005E8140, D_0044CDA8, REQ_LAST_NUM, D_0044CDC8) < 0) {
    }
}

#define COLI_WAVE_STEP_IDLE   0         /* phase: first call, defeat the field */
#define COLI_WAVE_STEP_SPAWN  1         /* phase: start each waiting enemy once its entry is active */

/* Arena enemy spawn step: phase 0 defeats every enemy; phase 1 starts the action of each of the three waiting enemy entries as it becomes active, counts it and clears its slot. */
__attribute__((section(".text.ColiseumBattle_spawnWaitingEnemies")))
void ColiseumBattle_spawnWaitingEnemies(ColiseumBattle *self)
{
    char buf[0x10];
    switch (self->phase) {
    case COLI_WAVE_STEP_IDLE:
        ColiseumBattle_DefeatAllEnemies(self);
        self->phase = self->phase + 1;
        break;
    case COLI_WAVE_STEP_SPAWN:
        if (self->unkC64[0] != 0 && IsEntryActive_1C2490(self->unkC64[0]) != 0) {
            buf[0] = 0;
            cEmSetParam_setEm(D_00586AB0, 0);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->unkC64[0] = 0;
        }
        if (self->unkC64[1] != 0 && IsEntryActive_1C2490(self->unkC64[1]) != 0) {
            buf[0] = 1;
            cEmSetParam_setEm(D_00586AB0, 1);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->unkC64[1] = 0;
        }
        if (self->unkC64[2] != 0 && IsEntryActive_1C2490(self->unkC64[2]) != 0) {
            buf[0] = 2;
            cEmSetParam_setEm(D_00586AB0, 2);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->unkC64[2] = 0;
        }
        break;
    }
}

typedef struct CatmullBasis { float m[16]; } CatmullBasis;

extern CatmullBasis D_0044E050;         /* the Catmull-Rom basis matrix */

/* Catmull-Rom spline through four control values at parameter t: transform (t^3, t^2, t, 1) by the basis matrix and weight the four values with the result. */
__attribute__((section(".text.ESLib_ESCatMullRom")))
float ESLib_ESCatMullRom(float t, float p0, float p1, float p2, float p3)
{
    CatmullBasis basis;
    cVec v;
    cVec *vp = &v;
    float t2 = t * t;
    float t3 = t2 * t;
    basis = D_0044E050;
    v.x = t3;
    v.y = t2;
    v.z = t;
    vp->w = 1.0f;
    sceVu0ApplyMatrix(vp, &basis, vp);
    return p0 * v.x + p1 * v.y + p2 * v.z + p3 * v.w;
}
