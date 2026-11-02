/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cCoreSave.h"
#include "godhand/cDamageUnit.h"

extern char D_00574380[];
extern char D_00568240[];
extern void cWorldTime_gameInit(void *w);
extern void cCamManager_setPlCamera(void *cam, int on);
extern void cEmManage_reset(void *m);
extern void func_001FDEA8(void *p);
extern void cHeatSys_Initialize(void *h);
extern void Obj0000_Clear_Fields_00_08_0C_0E_10_12_1F6CF8(void *p);
extern int cDamageUnit_SetDamageCollActive(cDamageUnit *unit, int on);
extern int KeySlotTable_set(void *tbl, int key, int value);
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
    func_001FDEA8(D_00574380);
    cHeatSys_Initialize(D_005CB000);
    Obj0000_Clear_Fields_00_08_0C_0E_10_12_1F6CF8(D_00568240);
    cCoreSave_gameInit(&D_00569B70);
    self->rate = 0.5f;
}

/* The unit past its node list: the two hit values. */
typedef struct DamageUnitHit {
    cDamageUnit base;                   /* 0x00 */
    char unk40[6];
    short hitA;                         /* 0x46 */
    char unk48[4];
    int hitB;                           /* 0x4C */
} DamageUnitHit;

typedef struct DamageFiveObj {
    char unk000[0x670];
    DamageUnitHit *unit0;               /* 0x670 */
    char unk674[4];
    DamageUnitHit *unit1;               /* 0x678 */
    char unk67C[4];
    DamageUnitHit *unit2;               /* 0x680 */
    char unk684[4];
    DamageUnitHit *unit3;               /* 0x688 */
    char unk68C[4];
    DamageUnitHit *unit4;               /* 0x690 */
} DamageFiveObj;

/* Switch all five damage units off: clear their hit values and deactivate every node. */
__attribute__((section(".text.DamageFiveObj_clearHits")))
void DamageFiveObj_clearHits(DamageFiveObj *self)
{
    self->unit0->hitA = 0;
    self->unit0->hitB = 0;
    cDamageUnit_SetDamageCollActive(&self->unit0->base, 0);
    self->unit1->hitA = 0;
    self->unit1->hitB = 0;
    cDamageUnit_SetDamageCollActive(&self->unit1->base, 0);
    self->unit2->hitA = 0;
    self->unit2->hitB = 0;
    cDamageUnit_SetDamageCollActive(&self->unit2->base, 0);
    self->unit3->hitA = 0;
    self->unit3->hitB = 0;
    cDamageUnit_SetDamageCollActive(&self->unit3->base, 0);
    self->unit4->hitA = 0;
    self->unit4->hitB = 0;
    cDamageUnit_SetDamageCollActive(&self->unit4->base, 0);
}

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct PoolOwner {
    char unk00[0xC0];
    Vec3 *pos;                          /* 0xC0 */
} PoolOwner;

typedef struct PoolObj {
    char unk00[0x14];
    char keyTable[0x20];                /* 0x14 key slot table */
    PoolOwner *owner;                   /* 0x34 */
} PoolObj;

typedef struct SpawnRec {
    Vec3 pos;                           /* 0x00 */
    char unk0C[4];
    Vec3 cur;                           /* 0x10 */
    char unk1C[0xC];
    PoolObj *obj;                       /* 0x28 */
    short kind;                         /* 0x2C */
    char started;                       /* 0x2E */
} SpawnRec;

extern char D_005E8040[];               /* object pool */
extern PoolObj *Pool_createObjWithTable(void *pool, int a1, int a2, int a3, int t0);


/* Create the pool object for the record, register key 1, copy its owner position into cur and pos and mark the record started. Returns -1 when the pool is full. */
__attribute__((section(".text.SpawnRec_create")))
int SpawnRec_create(SpawnRec *self, int a1, int a2, int a3, int t0, int value)
{
    Vec3 *cur;
    Vec3 *src;

    self->obj = Pool_createObjWithTable(D_005E8040, a1, a2, a3, t0);
    if (self->obj == 0) {
        return -1;
    }
    KeySlotTable_set(self->obj->keyTable, 1, value);
    src = self->obj->owner->pos;
    cur = &self->cur;
    if (cur != src) {
        self->cur.x = src->x;
        cur->y = src->y;
        cur->z = src->z;
    }
    if (&self->pos != cur) {
        self->pos.x = self->cur.x;
        self->pos.y = cur->y;
        self->pos.z = cur->z;
    }
    self->started = 1;
    return self->kind;
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
