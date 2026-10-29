/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cDvd.h"
#include "godhand/cOmBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"

extern char D_0044CE28[];
extern char D_0044CE30[];
extern void *cSnd_GetSeData(cSnd *self, int bank);
extern void *cSnd_GetBgmData(cSnd *self, int bank);
extern void cSeData_Release(void *seData);
extern void cSnd_SeLoadFile(cSnd *self, int bank, char *name);
extern int cSnd_SeIsLoaded(cSnd *self, int bank);
extern void cBgmData_Reset(void *bgm);
extern int cBgmData_LoadNumbered(void *bgm, int a1, int a2);
extern int cBgmData_IsEmpty(void *bgm);
extern int cBgmData_IsReady(void *bgm);
extern void cScenario_sleepFrames(int frames);
extern char D_00580D40[];
extern int FindEntryValue_1FF9C0(char *table, char *name, int *size, char *key);
extern void func_001B6FB8(void *self);
extern void cOmDoor_setObjCollisionCenterOnly(void *self);
extern void SetFlagBit_1BD698(void *self);
extern void func_001BDD88(void *self, float f);
extern float fRand0_1(void);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);

/* cSnd_LoadStartupBanks: load the sound banks 0 and 3 from disc and the first BGM, waiting a frame at a time until
 * each is ready. Returns early when the BGM bank has nothing to load. */
__attribute__((section(".text.cSnd_LoadStartupBanks")))
void cSnd_LoadStartupBanks(cSnd *self)
{
    cSeData_Release(cSnd_GetSeData(self, 0));
    cSnd_SeLoadFile(self, 0, D_0044CE28);
    while (cSnd_SeIsLoaded(self, 0) == 0) {
        cScenario_sleepFrames(1);
    }
    cSeData_Release(cSnd_GetSeData(self, 3));
    cSnd_SeLoadFile(self, 3, D_0044CE30);
    while (cSnd_SeIsLoaded(self, 3) == 0) {
        cScenario_sleepFrames(1);
    }
    cBgmData_Reset(cSnd_GetBgmData(self, 0));
    cBgmData_LoadNumbered(cSnd_GetBgmData(self, 0), 0, 0);
    if (cBgmData_IsEmpty(cSnd_GetBgmData(self, 0)) == 1) {
        return;
    }
    while (cBgmData_IsReady(cSnd_GetBgmData(self, 0)) == 0) {
        cScenario_sleepFrames(1);
    }
}

/* cDvd_ReadToBuffer: queue a read of a named file into a caller buffer (rounded up to 64 bytes). id 0 takes
 * the next job id; size overrides the size in bytes. Returns the job id, 0 on failure. */
__attribute__((section(".text.cDvd_ReadToBuffer")))
int cDvd_ReadToBuffer(cDvd *self, char *name, unsigned int buf, int id, int size, int arg70, int arg6C)
{
    cDvdJob *job;
    int fileNo;

    if ((buf & 0x3F) != 0) {
        buf = (buf + 0x3F) & 0xFFFFFFC0;
    }
    job = cDvd_takeFreeJob(self);
    if (job == 0) {
        return 0;
    }
    fileNo = FindEntryValue_1FF9C0(D_00580D40, name, &job->size, job->unk0C);
    job->fileNo = fileNo;
    job->align = 0;
    job->blockNum = (unsigned int)(job->size + 0x7FF) >> 11;
    if (fileNo < 0) {
        return 0;
    }
    job->state = 1;
    if (id == 0) {
        job->id = func_00201788(self);
    } else {
        job->id = id;
    }
    job->buf = (void *)buf;
    job->arg6C = arg6C;
    job->arg70 = arg70;
    if (size != 0) {
        job->blockNum = (unsigned int)(size + 0x7FF) >> 11;
    }
    if (self->cur == 0) {
        func_00201290(self);
    }
    return job->id;
}

/* The vector the object keeps at 0x600. */
#define OBJ_VEC600(self)  ((cVec *)((char *)(self) + 0x600))

/* Obj_initPosVec600: initialise the object: base setup, store (5.78, 5.5, 0.2) in the vector at 0x600, run
 * the two follow-up steps and start the 5.6 effect. Returns 1. */
__attribute__((section(".text.Obj_initPosVec600")))
int Obj_initPosVec600(void *self)
{
    cVec v;
    func_001B6FB8(self);
    v.x = 5.78f;
    v.y = 5.5f;
    v.z = 0.2f;
    v.w = 1.0f;
    cVec_copy3(OBJ_VEC600(self), &v);
    cOmDoor_setObjCollisionCenterOnly(self);
    SetFlagBit_1BD698(self);
    func_001BDD88(self, 5.6f);
    return 1;
}

typedef struct DropEntry {
    int item;                   /* 0x0 item id */
    float weight;               /* 0x4 chance */
} DropEntry;

typedef struct DropTable { DropEntry e[5]; } DropTable;

extern DropTable D_00428068;


/* cGameObj_pickDropItem: when the object has no drop item yet (0xFFFF), pick one from the five-entry weighted
 * table D_00428068 with a random number; if it runs past the last weight the item is 0x3E2. */
__attribute__((section(".text.cGameObj_pickDropItem")))
void cGameObj_pickDropItem(cGameObj *self)
{
    DropTable tbl;
    float r;
    unsigned int i;

    if (self->dropItem == 0xFFFF) {
        r = fRand0_1();
        tbl = D_00428068;
        for (i = 0; i < 5; i++) {
            if (r < tbl.e[i].weight) {
                self->dropItem = tbl.e[i].item;
                return;
            }
            r = r - tbl.e[i].weight;
        }
        self->dropItem = 0x3E2;
    }
}

/* One row of the phase table: this adjustment, a data-block selector and the method (or an index). */
struct Entry_func_00122C48 { short f0; short f2; short f4; short f6; };
struct Table_func_00122C48 { struct Entry_func_00122C48 e[1]; };
extern struct Table_func_00122C48 D_003BD458;

/* The player's mode-2 handler, entry 2 of the mode table D_003BD0B8. Clear the 0x640 and 0x698 links, update the base,
 * force phase 0 when the phase byte (0x2F5) is 2 or more, then call the method the phase table names for it. */
__attribute__((section(".text.StepPlayerMode2ByPhase_122C48")))
void StepPlayerMode2ByPhase_122C48(cEm00 *self)
{
    char *s0 = (char *)self;
    char *e;
    int i8;
    int f0;
    int type;
    int arg;
    int (*fp)(int);
    long entry;

    Obj0000_Clear_Fields_640_648_124E58(s0);
    CallWithAndClearField698_12AC28(s0);
    func_0012B928(s0);
    if (self->phase >= 2) {
        self->phase = 0;
    }
    i8 = self->phase * 8;
    e = (char *)&D_003BD458 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BD458 + i8 + 4);
    }
    f0 = D_003BD458.e[self->phase].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}
