/* cygnus-2.96 matched TU. */

#include "godhand/sftim.h"
#include "godhand/adxPly.h"
#include "godhand/SfdDec.h"

extern int sfply_IsAnyoneTerm(SftimHn *);
extern int Obj35C0_IsIndexedSet_1F3C_C380(SftimHn *, int);
extern char D_00452010[];
extern void func_00329848(void);
extern void func_00329870(AdxPly *ply);
extern void func_00329898(AdxPly *ply);
extern void func_00329ED8(AdxPly *ply);
extern void Obj3260_TrampChain_D2D8(void *p);
extern void func_00326718(void *p);
extern void func_003283E8(int stm, int a, int b);
extern void func_00327D90(int stm);
extern void func_00335500(void *p);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void ADXAMP_Destroy(void *amp);
extern SfdDecCfgA D_00766BA8;
extern SfdDecCfgB D_00766BD0;
extern SfdDecIds D_00766BD8;
extern void func_00354A70(StmSlot *s, int *ids, int n);
extern void func_00354B20(void *que);
extern void func_003520B0(void *win);
extern void func_00354B40(void *work);

/* Fields of the handle that sftim.h does not name yet (offsets from the handle). */
#define SFPLY_STATE(hn)   (*(int *)((char *)(hn) + 0x48))
#define SFPLY_PAUSED(hn)  (*(int *)((char *)(hn) + 0x50))
#define SFPLY_ERRF28(e)   (*(int *)((char *)(e) + 0x28))









/* Say whether the player may start: every gate must pass, then the elapsed time must still be positive. */
__attribute__((section(".text.sfply_CanStart")))
int sfply_CanStart(SftimHn *hn)
{
    int t[2];
    SfdErr *err = &hn->errInf;
    SftimWork *tim;
    int rate;
    int now;

    if (GetArrayElemA0C_35A1C8(hn, 0x43) == 0) {
        return 0;
    }
    if (GetArrayElemA0C_35A1C8(hn, 0xF) == 0) {
        return 0;
    }
    if (SFPLY_PAUSED(hn) != 0) {
        return 0;
    }
    if (SFPLY_STATE(hn) != 4) {
        return 0;
    }
    if (sfply_IsAnyoneTerm(hn) != 0) {
        return 0;
    }
    if (GetArrayElemA0C_35A1C8(hn, 5) == 1 && SFPLY_ERRF28(err) == 0) {
        return 0;
    }
    if (GetArrayElemA0C_35A1C8(hn, 6) == 1 && func_0034CAD0(hn, 2) > 0) {
        return 0;
    }
    if (Obj35C0_IsIndexedSet_1F3C_C380(hn, 1) != 0 && func_0034CAD0(hn, 0) > 0) {
        return 0;
    }
    if (GetArrayElemA0C_35A1C8(hn, 5) == 1 && func_00357DA0(hn) != 0) {
        return 0;
    }
    func_0035AB98(hn, &t[0], &t[1]);
    tim = &hn->tim;
    rate = tim->f288;
    now = tim->f284;
    now -= func_0036C920(GetArrayElemA0C_35A1C8(hn, 0x44), rate, 1000000);
    if (t[0] <= 0 || now <= 0) {
        return 0;
    }
    return func_0035AEC8(t[0], t[1], now, rate) == 0;
}

/* Release everything the player handle owns, in order, and clear the handle. */
__attribute__((section(".text.adxPly_destroy")))
void adxPly_destroy(AdxPly *ply)
{
    int i;
    int stm;
    void *p;
    SjObj *sj;

    if (ply == 0) {
        func_0033F130(D_00452010);
        return;
    }
    func_00329848();
    func_00329870(ply);
    func_00329898(ply);
    if (ply->stat == ADXPLY_STAT_RUN) {
        func_00329ED8(ply);
    }
    p = ply->rsv0C;
    if (p != 0) {
        ply->rsv0C = 0;
        Obj3260_TrampChain_D2D8(p);
    }
    p = ply->rsv04;
    if (p != 0) {
        ply->rsv04 = 0;
        func_00326718(p);
    }
    stm = ply->stm;
    if (stm != 0) {
        ply->stm = 0;
        func_003283E8(stm, 0, 0);
        func_00327D90(stm);
    }
    p = ply->rsv94;
    if (p != 0) {
        ply->rsv94 = 0;
        func_00335500(p);
    }
    Forward33B658_33E678();
    sj = ply->sjo;
    if (sj != 0) {
        ply->sjo = 0;
        sj->vt->destroy(sj);
    }
    for (i = 0; i < ply->maxnch; i++) {
        if (ply->sjiA[i] != 0) {
            SjObj *t = ply->sjiA[i];

            ply->sjiA[i] = 0;
            t->vt->destroy(t);
        }
        if (ply->sjiB[i] != 0) {
            SjObj *t = ply->sjiB[i];

            ply->sjiB[i] = 0;
            t->vt->destroy(t);
        }
        if (ply->sjiC[i] != 0) {
            SjObj *t = ply->sjiC[i];

            ply->sjiC[i] = 0;
            t->vt->destroy(t);
        }
    }
    p = ply->amp;
    if (p != 0) {
        ply->amp = 0;
        ADXAMP_Destroy(p);
    }
    func_003A52F0(ply, 0, ADXPLY_SIZE);
    ply->stat = 0;
    Forward33B670_33E690();
}

/* Set up the decoder manager: check the configuration, copy it in, clear the counters and timing window, and give each of the 16 slots its id and entry. */
__attribute__((section(".text.SfdDec_init")))
int SfdDec_init(void *hn, SfdDecMgr *mgr)
{
    int i;

    if (func_003549A8() != 0) {
        return func_0034DD70(0, 0xFF000F15);
    }
    mgr->cfgA = D_00766BA8;
    mgr->cfgB = D_00766BD0;
    mgr->ids = D_00766BD8;
    mgr->bufCnt = SFDDEC_DEF_BUFCNT;
    mgr->bufSize = SFDDEC_DEF_BUFSIZE;
    mgr->unk13C = 1;
    mgr->unk00 = 0;
    mgr->unk70 = 0;
    mgr->unk138 = 0;
    mgr->unk7C = 0;
    mgr->unk80 = 0;
    mgr->unk160 = 0;
    mgr->unk164 = 0;
    mgr->unk168 = 0;
    mgr->unk16C = 0;
    mgr->unk170 = 0;
    mgr->unk174 = 0;
    func_00354A70(mgr->slot, mgr->ids.w, SFDDEC_SLOT_NUM);
    mgr->unk84 = 0;
    mgr->unk88 = 0;
    func_00354B20(mgr->que);
    mgr->unk10C = -1;
    mgr->unk110 = 0;
    mgr->unk114 = 0x7FFFFFFF;
    func_003520B0(mgr->win);
    func_00354B40(mgr->work);
    for (i = SFDDEC_SLOT_NUM - 1; i >= 0; i--) {
        mgr->slot[i].unk54 = (int)&mgr->ent[i];
    }
    return 0;
}
