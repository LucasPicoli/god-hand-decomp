/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern char D_00583F20[];
extern unsigned char D_0044D070;
extern void cDvd_cancel(char *, int);
extern void func_00322F58(void);
extern void UnlinkAndCoalesceNode_2A9680(int, void *);
extern cBgmData *cSnd_GetBgmData(cSnd *, int);
extern cBgmHead *cBgmData_GetHeadPtr(cBgmData *);
extern cBgmTbl *cBgmData_GetTblPtr(cBgmData *, int);
extern void cBgmData_Reset(cBgmData *);
extern void cBgmData_Relocate(cBgmData *);
extern void cBgmData_AddLoadBits(cBgmData *, int);
extern char D_00603A40[];
extern char D_0044CF78[];
extern unsigned int D_00747A34;
extern void func_003A6A20(char *, int, int, int);
extern void cSeData_AddLoadBits(cSeData *, int);
extern void cSeData_Release(cSeData *);
extern void cSeData_SelectHeap(cSeData *);
extern void cSeData_SetFailed(cSeData *);

/* Release everything a bgm data slot holds and reset it. */
__attribute__((section(".text.cBgmData_Reset")))
void cBgmData_Reset(cBgmData *d)
{
    if (cBgmData_IsReadDone(d) == 0)
        cDvd_cancel(D_00583F20, d->f1C);
    if (cBgmData_HasLoadBits(d, 4) == 1 && cBgmData_HasLoadBits(d, 8) == 0 && func_00323000(d->f18) == 2)
        func_00322F58();
    if (d->head != 0)
        UnlinkAndCoalesceNode_2A9680((int)d->pool, d->head);
    if (d->f14 != 0)
        UnlinkAndCoalesceNode_2A9680((int)d->pool, d->f14);
    func_003A52F0(d, 0, 0x44);
    d->f20 = -1;
    d->f18 = -1;
    d->name[0] = D_0044D070;
}

/* Advance the bgm data slot's load state by one step. */
__attribute__((section(".text.cBgmData_UpdateLoad")))
void cBgmData_UpdateLoad(cBgmData *d)
{
    if (cBgmData_HasLoadBits(d, 1) != 0 && cBgmData_IsReady(d) != 1) {
        if (cBgmData_HasLoadBits(d, 2) == 0) {
            if (cBgmData_IsReadDone(d) == 1) {
                cBgmData_Relocate(d);
                if (cBgmData_PrepareDecode(d) == 0)
                    cBgmData_Reset(d);
            }
        } else {
            if (cBgmData_HasLoadBits(d, 4) == 1 && func_00323000(d->f18) == 3)
                cBgmData_AddLoadBits(d, 8);
        }
    }
}

/* Resolve the slot's bank table entry once; 1 on success. */
__attribute__((section(".text.cSeData_ResolveBank")))
int cSeData_ResolveBank(cSeData *d)
{
    int base;

    if (d->f1C != 0)
        return 0;
    base = d->buf->f28;
    if (base != (int)d->buf) {
        d->f1C = cSeData_HeapAlloc(d, d->buf->f2C);
        if (d->f1C == 0)
            return 0;
        if ((D_00747A34 & 0x10000000) != 0)
            func_003A6A20(D_0044CF78, d->f3C, d->bankId, d->buf->f2C);
        d->f34 = func_002D30E0(D_00603A40, base, d->f1C, d->buf->f2C);
    }
    cSeData_AddLoadBits(d, 0x20);
    return 1;
}

/* Start loading bank bankId from buffer buf into the slot; 1 when it is usable. */
__attribute__((section(".text.cSeData_LoadFromBuf")))
int cSeData_LoadFromBuf(cSeData *d, int bankId, cSeBuf *buf, int f3C)
{
    if (d->state != 0)
        cSeData_Release(d);
    d->bankId = bankId;
    d->f3C = f3C;
    d->state = 1;
    cSeData_SelectHeap(d);
    d->buf = buf;
    cSeData_AddLoadBits(d, 0x181);
    if (cSeData_CheckImage(d) != 0) {
        if (cSeData_IsBankIdle(d) != 1)
            return 1;
        if (cSeData_AllocSysMem(d) != 0 && cSeData_ResolveBank(d) != 0)
            return 1;
    }
    cSeData_SetFailed(d);
    return 0;
}
