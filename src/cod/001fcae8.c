/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cCoreSave.h"
#include "godhand/cDamageGive.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cDamageManage.h"
extern char D_00568240[];
extern void cWorldTime_gameInit(void *w);
extern void cCamManager_setPlCamera(void *cam, int on);
extern void cEmManage_reset(void *m);
extern void func_001FDEA8(void *p);
extern void cHeatSys_Initialize(void *h);
extern void Obj0000_Clear_Fields_00_08_0C_0E_10_12_1F6CF8(void *p);
extern void func_002A87E8(void *self, int arg);

extern char D_005864F0[];               /* enemy manager */

#define ACTION_SPECIAL  0x211           /* action id this count applies to */

/* While the object runs action 0x211, count the enemies of its actor type in the four groups 0x200, 0x203, 0x227 and 0x22A. */
__attribute__((section(".text.cOmBase_countGroupsInAction211")))
int cOmBase_countGroupsInAction211(cOmBase *self)
{
    int n;

    /* the xor spelling is what gives retail's xori + bnel; a plain != gives li + bnel */
    if ((self->emNo ^ ACTION_SPECIAL) != 0) {
        return 0;
    }
    n = func_002919C0(D_005864F0, self->actorId, 0x200);
    n += func_002919C0(D_005864F0, self->actorId, 0x203);
    n += func_002919C0(D_005864F0, self->actorId, 0x227);
    n += func_002919C0(D_005864F0, self->actorId, 0x22A);
    return n;
}

extern char D_0061A990[];               /* cWorldTime */
extern char D_00463050[];               /* cCamManager */
extern char D_005864F0[];               /* cEmManage */

extern char D_005CB000[];               /* cHeatSys */

extern int D_00747A24;                  /* system state flags */








#define SYS_FLAG_NEW_GAME  0x10

typedef struct GameInitObj {
    char started;                       /* 0x00 */
    char unk01[0x1AB];
    float rate;                         /* 0x1AC */
} GameInitObj;

/* Start a new game: initialise every manager, set the system flag, mark the object started and set its rate to 0.5. */
__attribute__((section(".text.GameInitObj_start")))
void GameInitObj_start(GameInitObj *self)
{
    cWorldTime_gameInit(D_0061A990);
    D_00747A24 |= SYS_FLAG_NEW_GAME;
    cCamManager_setPlCamera(D_00463050, 0);
    self->started = 1;
    cEmManage_reset(D_005864F0);
    func_001FDEA8(&D_00574380);
    cHeatSys_Initialize(D_005CB000);
    Obj0000_Clear_Fields_00_08_0C_0E_10_12_1F6CF8(D_00568240);
    cCoreSave_gameInit(&D_00569B70);
    self->rate = 0.5f;
}

typedef struct DamageFiveObj {
    char unk000[0x670];
    cDamageGive *unit0;                 /* 0x670 */
    char unk674[4];
    cDamageGive *unit1;                 /* 0x678 */
    char unk67C[4];
    cDamageGive *unit2;                 /* 0x680 */
    char unk684[4];
    cDamageGive *unit3;                 /* 0x688 */
    char unk68C[4];
    cDamageGive *unit4;                 /* 0x690 */
} DamageFiveObj;

/* Park all five damage gives: clear their attack kind and power and deactivate every node. */
__attribute__((section(".text.DamageFiveObj_clearHits")))
void DamageFiveObj_clearHits(DamageFiveObj *self)
{
    self->unit0->kind = 0;
    self->unit0->power = 0;
    cDamageUnit_SetDamageCollActive((cDamageUnit *)self->unit0, 0);
    self->unit1->kind = 0;
    self->unit1->power = 0;
    cDamageUnit_SetDamageCollActive((cDamageUnit *)self->unit1, 0);
    self->unit2->kind = 0;
    self->unit2->power = 0;
    cDamageUnit_SetDamageCollActive((cDamageUnit *)self->unit2, 0);
    self->unit3->kind = 0;
    self->unit3->power = 0;
    cDamageUnit_SetDamageCollActive((cDamageUnit *)self->unit3, 0);
    self->unit4->kind = 0;
    self->unit4->power = 0;
    cDamageUnit_SetDamageCollActive((cDamageUnit *)self->unit4, 0);
}

/* Take a cylinder unit from the pool for the node (-1 when none is left), store owner under key 1, copy the shape's position into posB and posB into posA, and mark the node ready. Returns the node's id. */
__attribute__((section(".text.cDamageNode_attachCylinder")))
int cDamageNode_attachCylinder(cDamageNode *self, int group, const struct cMatrix *mtx, const cVec *ofs,
                               const cVec *rot, float height, float radius, cDamageUnit *owner)
{
    cVec *cur;
    cVec *src;

    self->unit = Pool_createObjWithTable(&D_005E8040, group, mtx, ofs, rot, height, radius);
    if (self->unit == 0) {
        return -1;
    }
    KeySlotTable_set(self->unit->keyTable, 1, (int)owner);
    src = self->unit->shape->pos;
    cur = &self->posB;
    if (cur != src) {
        self->posB.x = src->x;
        cur->y = src->y;
        cur->z = src->z;
    }
    if (&self->posA != cur) {
        self->posA.x = self->posB.x;
        self->posA.y = cur->y;
        self->posA.z = cur->z;
    }
    self->ready = 1;
    return self->id;
}

#define MODE_NUM  2

/* One mode entry: this-adjust, method index (or negative: handler is inline), table offset in the object. */
typedef struct ModeEnt {
    short delta;                        /* 0x0 added to this before the call */
    short index;                        /* 0x2 slot in the method table, negative: handler inline at +4 */
    short tblOff;                       /* 0x4 where the method table pointer sits in the object */
    short pad6;
} ModeEnt;

typedef struct { char b[0x10]; } ModeTbl;
extern ModeTbl D_00448C68;              /* the two entries */

/* Phase tick: call the handler the current phase's table entry names (a method table entry, or an inline handler for a negative index), then run the shared post step. A phase of 2 or more resets to 0 first. */
__attribute__((section(".text.cOmBase_tickPhaseTable288570")))
void cOmBase_tickPhaseTable288570(cOmBase *self)
{
    ModeEnt tbl[MODE_NUM];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    *(ModeTbl *)tbl = D_00448C68;
    if (self->phase >= MODE_NUM) {
        self->phase = 0;
    }
    i8 = self->phase * 8;
    e = (char *)tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)self + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)tbl + i8 + 4);
    }
    f0 = tbl[self->phase].delta;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)self + arg));
    func_002A87E8(self, 0);
}
