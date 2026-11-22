/* sn-2.95.3-136 matched TU. */

#include "godhand/cScenario.h"
#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/cOmBase.h"
#include "godhand/cDamageManage.h"
#include "godhand/globals.h"

extern unsigned int D_00747A84;
extern void func_0028E858(void);
extern char D_007474A0[];
extern void *SearchData(void *name, void *table, int which);
extern unsigned int D_00747A78;
extern char *D_005CAFF0;
extern void func_001582A0(void *self, void *link, float f12, float f13, int a2, int a3, int t0);
extern void cParts_setRotationOrder(void *self, int order);
extern void cModel_calcParts(void *self);
extern char D_00747AC0[];
extern void StoreVecFromFieldB0_2B6160(cVec *dst, void *obj);
extern void func_002E28F0(void *obj, float y);
extern char D_00583F20[];
extern char D_005E6900[];
extern void FileLoader_readWholeFile(void *self);
extern void func_00397128(int a0);
extern void func_0030ABD8(void);
extern void func_00395058(void);
extern void sceGsResetGraph(int mode, int inter, int omode, int ffmode);
extern void sceGsSyncV(int mode);
extern void cDvd_init(void *dvd);
extern void func_002C9D20(void *snd);
extern void MoviePool_init(void *res);
extern void SlotIds_sendSetup(void *card);
extern void func_0031A718(void *arg);
extern void func_002BE4E8(void *arg);

/* Start the scripted task func_0028E858 for this object: begin soft event 2,
 * clear bit 16 of the system flags, run the task and flag its work record as
 * a soft-event task. */





__attribute__((section(".text.cScenario_startSoftTask")))
void cScenario_startSoftTask(void *self) {
    int no;
    char *works;
    cScenario_startSoftEvent(D_003C2F84, 2);
    D_00747A84 &= 0xFFFEFFFF;
    no = cScenario_taskExec(D_003C2F84, (void *)func_0028E858, self, 1);
    works = D_003C2F84->task.works;     /* dead read: it changes retail's register choice (see cOmScripted_startSeq) */
    if (no >= 0) {
        cTaskWork *e = (cTaskWork *)(no * TASKMGR_WORK_SIZE + (int)D_003C2F84->task.works);
        e->attr = e->attr | SCENARIO_TASK_SOFT_EVENT;
    }
}

/* Look the menu data up twice in the table D_0044B100 (which 0, which 1) and
 * keep both in D_003C23A4; then set the object's timer to 900 and clear its
 * state byte. */



typedef struct DataPair {
    void *data;                         /* 0x0 */
    char unk4[8];
    void *tex;                          /* 0xC */
} DataPair;

extern DataPair *D_003C23A4;


#define MENU_TIMER_INIT  900

typedef struct MenuObj {
    char unk0000[0xBDA];
    short timer;                        /* 0xBDA */
    char unkBDC[0x14];
    unsigned char state;                /* 0xBF0 */
} MenuObj;

__attribute__((section(".text.cMenu_loadDataTables")))
void cMenu_loadDataTables(MenuObj *self) {
    char *sys = D_007474A0;
    D_003C23A4->data = SearchData(*(void **)(sys + 0x558), D_0044B100, 0);
    D_003C23A4->tex = SearchData(*(void **)(sys + 0x558), D_0044B100, 1);
    self->timer = MENU_TIMER_INIT;
    self->state = 0;
}

/* Per-frame refresh: unless system flag bit 28 is set, call func_001582A0 when
 * the part at 0x4D0 is set and idle; then, if flag bit 0 of 0x2F8 is set, copy
 * the camera position (D_005CAFF0 + 0x220) into the part and set rotation
 * order 4. Always recalc the model parts. */
typedef struct PartObj {
    char unk000[0x100];
    float pos[3];                       /* 0x100 */
    char unk10C[0x1EC];
    unsigned int flags;                 /* 0x2F8 */
    char unk2FC[0x1D4];
    void *link;                         /* 0x4D0 */
    unsigned char busy;                 /* 0x4D4 */
} PartObj;







#define SYS_FLAG_HOLD   0x10000000
#define PART_FLAG_FOLLOW 0x1

__attribute__((section(".text.PartObj_refresh")))
void PartObj_refresh(PartObj *self) {
    if ((D_00747A78 & SYS_FLAG_HOLD) == 0) {
        if (self->link != 0 && self->busy == 0)
            func_001582A0(self, self->link, 1.0f, 0.0f, 0, 0, 0);
        if ((self->flags & PART_FLAG_FOLLOW) != 0) {
            float *dst = self->pos;
            float *src = (float *)(D_005CAFF0 + 0x220);
            if (dst != src) {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
            cParts_setRotationOrder(self, 4);
        }
        cModel_calcParts(self);
    }
}

/* Create the six damage-give volumes of the object (slots from 0xBB0): each
 * is kind 3 with a unit sphere at the origin of the global D_00747AC0,
 * hit values 0x55 and 100, switched off, with bit 0 of its flags set. */
typedef struct GiveOwner {
    char unk000[0xBB0];
    cDamageGive *give[6];                   /* 0xBB0 */
} GiveOwner;

#define GIVE_COUNT      6
#define GIVE_KIND       3
#define GIVE_ATTACK_KIND      0x55
#define GIVE_POWER      100






__attribute__((section(".text.GiveOwner_createGiveVolumes")))
void GiveOwner_createGiveVolumes(GiveOwner *self) {
    unsigned int i = 0;
    cDamageGive **slot = self->give;
    do {
        float v[4];
        i++;
        *slot = cDamageManage_CreateDamageGive(&D_00574380, GIVE_KIND, 0);
        if (*slot != 0) {
            v[0] = 0.0f;
            v[1] = 0.0f;
            v[2] = 0.0f;
            v[3] = 1.0f;
            cDamageUnit_AddDamageCollSphere((cDamageUnit *)*slot, (const struct cMatrix *)D_00747AC0, (const cVec *)v, 1.0f);
            (*slot)->kind = GIVE_ATTACK_KIND;
            (*slot)->power = GIVE_POWER;
            cDamageUnit_SetDamageCollActive((cDamageUnit *)*slot, 0);
            (*slot)->flags |= 1;
        }
        slot++;
    } while (i < GIVE_COUNT);
}

/* Ground follow: unless the grounded flag (bit 1 of 0x2CC) is already set,
 * cast a line from 1 unit above the object's position to 11 units below it;
 * on a hit keep the hit height at 0x2D0 and set the flag. While the flag is
 * set, hand the kept height to func_002E28F0. */



#define DROP_UP     1.0f
#define DROP_DOWN   11.0f
#define GROUNDED    0x2


extern int ChkLine(void *a0, void *a1, void *a2, void *a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);


#define FRAME ((char *)&pos - 0x30)

__attribute__((section(".text.Pos_followGround")))
void Pos_followGround(char *self)
{
    cVec pos;                           /* sp+0x30 object position */
    cVec from;                          /* sp+0x40 */
    cVec to;                            /* sp+0x50 */
    cVec hit;                           /* sp+0x60 */
    cVec normal;                        /* sp+0x70 */

    if ((*(unsigned int *)(self + 0x2CC) & GROUNDED) == 0) {
        StoreVecFromFieldB0_2B6160(&pos, self);
        VU0_LQC2(4, &pos, 0);
        VU0_SQC2(4, FRAME, 0x40);
        VU0_LQC2(4, &pos, 0);
        VU0_SQC2(4, FRAME, 0x50);
        VU0_SQC2_VF0(FRAME, 0x60);
        VU0_SQC2_VF0(FRAME, 0x70);
        from.y += DROP_UP;
        to.y -= DROP_DOWN;
        if (ChkLine(&from, &to, &hit, &normal, 2, 0, 0, 0, 0, 0, 0, 0, 1) != 0) {
            *(float *)(self + 0x2D0) = hit.y;
            *(unsigned int *)(self + 0x2CC) |= GROUNDED;
        }
    }
    if ((*(unsigned int *)(self + 0x2CC) & GROUNDED) != 0)
        func_002E28F0(self, *(float *)(self + 0x2D0));
}

/* System bring-up from the boot argument `arg`: read the boot file, load the
 * two resource tables, reset the graphics (interlace mode chosen by the
 * display flag D_007474A0[0x578]), start the disc, sound, resource and card
 * modules, then run the two final steps. */






















__attribute__((section(".text.System_bringUp")))
void System_bringUp(void *arg) {
    char *sys;
    int r;
    FileLoader_readWholeFile(arg);
    do {
        r = func_002BE240(arg, D_0044C048, 0, 0);
    } while (r < 0);
    do {
        r = func_002BE240(arg, D_0044C068, 0, 0);
    } while (r < 0);
    func_00397128(1);
    func_0030ABD8();
    func_00395058();
    sys = D_007474A0;
    if ((*(int *)(sys + 0x578) ^ 1) == 0)
        sceGsResetGraph(0, 1, 3, 0);
    else
        sceGsResetGraph(0, 1, 2, 0);
    sceGsSyncV(0);
    cDvd_init(D_00583F20);
    func_002C9D20(&D_005FEE00);
    MoviePool_init(D_005E79D0);
    SlotIds_sendSetup(D_005E6900);
    func_0031A718(arg);
    func_002BE4E8(arg);
}
