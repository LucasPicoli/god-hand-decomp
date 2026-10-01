/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern cBgmData *cSnd_GetBgmData(cSnd *, int);
extern cBgmHead *cBgmData_GetHeadPtr(cBgmData *);
extern cBgmTbl *cBgmData_GetTblPtr(cBgmData *, int);
extern void func_002CFF90(cBgmData *);
extern void func_002CD4A8(cSndBgmNode *, float);
extern cSnd D_005FEE00;
extern char D_00583F20[];
extern void func_002CBE68(cSnd *, int, int);
extern void func_00200F50(char *, int);
extern void func_00322F58(void);
extern void UnlinkAndCoalesceNode_2A9680(int, void *);
extern void func_00375A78(int);
extern void Tramp_sceSifFreeSysMemory_3B5A50(int);
extern void func_002CFE48(cSeData *, int);
extern void func_002CF310(cSeData *);
extern void func_002CFC98(cSeData *);
extern void func_002CFCB0(cSeData *, int);
extern void func_002CFB60(cSeData *);

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
__attribute__((section(".text.func_002D0850")))
void func_002D0850(cSnd *self)
{
    cSndBgmNode *node;
    int keep = func_002D0D70(self, D_007474A0.stageNo);

    for (node = self->bgmHead; node != 0; node = node->next) {
        if (node->state2 != 2 && node->reqNo != keep)
            func_002CD4A8(node, 15.0f);
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
__attribute__((section(".text.func_002D0CD0")))
int func_002D0CD0(void *self)
{
    int req = -2;
    if (func_002D0C10(self, 0x209) != 0)
        req = 0x1B;
    else if (func_002D0C10(self, 0x223) != 0)
        req = 0x2E;
    else if (func_002D0C10(self, 0x220) != 0 || func_002D0C10(self, 0x221) != 0 ||
             func_002D0C10(self, 0x222) != 0)
        req = 1;
    return req;
}

/* Release everything a bgm data slot holds and clear it. */
__attribute__((section(".text.func_002CF310")))
void func_002CF310(cSeData *d)
{
    func_002CBE68(&D_005FEE00, d->bankId, 0);
    if (func_002CF830(d) == 0)
        func_00200F50(D_00583F20, d->f38);
    if (func_002CFD38(d, 4) == 1 && func_002CFD38(d, 8) == 0 && func_00323000(d->f28) == 2)
        func_00322F58();
    if (d->buf != 0) {
        if (func_002CFD38(d, 0x100) == 0) {
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
        func_002CFE48(d, d->f1C);
    if (d->f24 != 0)
        UnlinkAndCoalesceNode_2A9680((int)d->pool, (void *)d->f24);
    func_003A52F0(d, 0, 0x40);
    d->f28 = -1;
    d->f3C = -1;
}

/* Step the sound-effect slot's load state machine once. */
__attribute__((section(".text.func_002CF440")))
void func_002CF440(cSeData *d)
{
    int r;

    if (func_002CFD38(d, 1) == 0)
        return;
    if (d->state != CSEDATA_STATE_FREE) {
        if (func_002CFC88(d) == 1) {
            if (func_00375128(d->bankIdS) != 0)
                return;
            if (func_002CF9A8(d) == 0)
                return;
            if (func_002CFD38(d, 4) == 1 && func_002CFD38(d, 8) == 0 && func_00323000(d->f28) == 2)
                return;
            func_002CF310(d);
            return;
        }
        if (d->state != CSEDATA_STATE_LOADING)
            return;
    }
    if (func_002CFD38(d, 2) == 0) {
        if (func_002CF830(d) != 1)
            return;
        r = func_002CFA08(d);
    } else {
        if (func_002CFD38(d, 0x20) != 0)
            goto loaded;
        if (func_002CFD38(d, 0x10) == 0) {
            if (func_002CF888(d) == 0)
                return;
        }
        if (func_002CF868(d) != 1)
            return;
        r = func_002CF8E8(d);
    }
    if (r == 0)
        func_002CFC98(d);
    return;
loaded:
    if (func_002CFD38(d, 4) == 1 && func_002CFD38(d, 8) == 0 && func_00323000(d->f28) == 3)
        func_002CFCB0(d, 8);
    if (func_002CF9A8(d) == 1)
        func_002CFB60(d);
}
