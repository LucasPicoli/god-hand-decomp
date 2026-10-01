/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern cBgmData *cSnd_GetBgmData(cSnd *, int);
extern cBgmHead *cBgmData_GetHeadPtr(cBgmData *);
extern cBgmTbl *cBgmData_GetTblPtr(cBgmData *, int);
extern void cBgmData_Reset(cBgmData *);
extern void cSndBgmNode_FadeOut(cSndBgmNode *, float);
extern cSnd D_005FEE00;
extern char D_00583F20[];
extern void cSnd_SeVoiceCallAll(cSnd *, int, int);
extern void cDvd_cancel(char *, int);
extern void func_00322F58(void);
extern void UnlinkAndCoalesceNode_2A9680(int, void *);
extern void func_00375A78(int);
extern void Tramp_sceSifFreeSysMemory_3B5A50(int);
extern void cSeData_HeapFree(cSeData *, int);
extern void cSeData_Release(cSeData *);
extern void cSeData_SetFailed(cSeData *);
extern void cSeData_AddLoadBits(cSeData *, int);
extern void cSeData_RegisterBank(cSeData *);

/* fields cSnd.h does not name yet; see cSnd_fields.h */
#define CSND_FLAGS_AC(s) (*(unsigned int*)((char *)(s) + 0xac))
#define CSND_FLAGS_B0(s) (*(unsigned int*)((char *)(s) + 0xb0))
#define CSND_F44(s) (*(int*)((char *)(s) + 0x44))
#define CSND_F48(s) (*(int*)((char *)(s) + 0x48))
#define CSND_F128(s) (*(int*)((char *)(s) + 0x128))
#define CSND_F138(s) (*(int*)((char *)(s) + 0x138))










extern struct cSndEnv {
    char unk00[0x5B0];
    unsigned short stageNo;     /* 0x5B0 */
} D_007474A0;



/* Switch to the bgm of the current stage: fade the other requests, reset the control state. */
__attribute__((section(".text.cSnd_BgmStageChange")))
void cSnd_BgmStageChange(cSnd *self)
{
    cSndBgmNode *node;
    int keep = cSnd_GetStageBgmReq(self, D_007474A0.stageNo);

    for (node = self->bgmHead; node != 0; node = node->next) {
        if (node->state2 != 2 && node->reqNo != keep)
            cSndBgmNode_FadeOut(node, 15.0f);
    }
    if (D_007474A0.stageNo != 0x20 && D_007474A0.stageNo != 0x23) {
        CSND_FLAGS_B0(self) |= 0x200000;
        CSND_FLAGS_AC(self) |= 0x200000;
        CSND_F128(self) = -2;
    }
    CSND_F44(self) = 0;
    CSND_F138(self) = 3;
    CSND_F48(self) = 0;
}

/* Map the enemies in the scene to a bgm request: -2 when none applies. */
__attribute__((section(".text.cSnd_BgmReqFromEnemies")))
int cSnd_BgmReqFromEnemies(void *self)
{
    int req = -2;
    if (cSnd_IsEnemyAlive(self, 0x209) != 0)
        req = 0x1B;
    else if (cSnd_IsEnemyAlive(self, 0x223) != 0)
        req = 0x2E;
    else if (cSnd_IsEnemyAlive(self, 0x220) != 0 || cSnd_IsEnemyAlive(self, 0x221) != 0 ||
             cSnd_IsEnemyAlive(self, 0x222) != 0)
        req = 1;
    return req;
}

/* Release everything a bgm data slot holds and clear it. */
__attribute__((section(".text.cSeData_Release")))
void cSeData_Release(cSeData *d)
{
    cSnd_SeVoiceCallAll(&D_005FEE00, d->bankId, 0);
    if (cSeData_IsReadDone(d) == 0)
        cDvd_cancel(D_00583F20, d->f38);
    if (cSeData_HasLoadBits(d, 4) == 1 && cSeData_HasLoadBits(d, 8) == 0 && func_00323000(d->f28) == 2)
        func_00322F58();
    if (d->buf != 0) {
        if (cSeData_HasLoadBits(d, 0x100) == 0) {
            void *b = d->buf;
            void *pool = d->pool;
            if (b != 0)
                UnlinkAndCoalesceNode_2A9680((int)pool, b);
        }
        func_00375A78(d->bankIdS);
    }
    if (d->sysMem != 0)
        Tramp_sceSifFreeSysMemory_3B5A50(d->sysMem);
    if (d->f1C != 0)
        cSeData_HeapFree(d, d->f1C);
    if (d->f24 != 0)
        UnlinkAndCoalesceNode_2A9680((int)d->pool, (void *)d->f24);
    func_003A52F0(d, 0, 0x40);
    d->f28 = -1;
    d->f3C = -1;
}

/* Step the sound-effect slot's load state machine once. */
__attribute__((section(".text.cSeData_Update")))
void cSeData_Update(cSeData *d)
{
    int r;

    if (cSeData_HasLoadBits(d, 1) == 0)
        return;
    if (d->state != CSEDATA_STATE_FREE) {
        if (cSeData_IsFailed(d) == 1) {
            if (func_00375128(d->bankIdS) != 0)
                return;
            if (cSeData_HasBankKeys(d) == 0)
                return;
            if (cSeData_HasLoadBits(d, 4) == 1 && cSeData_HasLoadBits(d, 8) == 0 && func_00323000(d->f28) == 2)
                return;
            cSeData_Release(d);
            return;
        }
        if (d->state != CSEDATA_STATE_LOADING)
            return;
    }
    if (cSeData_HasLoadBits(d, 2) == 0) {
        if (cSeData_IsReadDone(d) != 1)
            return;
        r = cSeData_CheckImage(d);
    } else {
        if (cSeData_HasLoadBits(d, 0x20) != 0)
            goto loaded;
        if (cSeData_HasLoadBits(d, 0x10) == 0) {
            if (cSeData_AllocSysMem(d) == 0)
                return;
        }
        if (cSeData_IsBankIdle(d) != 1)
            return;
        r = cSeData_ResolveBank(d);
    }
    if (r == 0)
        cSeData_SetFailed(d);
    return;
loaded:
    if (cSeData_HasLoadBits(d, 4) == 1 && cSeData_HasLoadBits(d, 8) == 0 && func_00323000(d->f28) == 3)
        cSeData_AddLoadBits(d, 8);
    if (cSeData_HasBankKeys(d) == 1)
        cSeData_RegisterBank(d);
}
