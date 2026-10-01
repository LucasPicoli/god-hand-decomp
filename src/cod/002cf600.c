/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern cBgmData *cSnd_GetBgmData(cSnd *, int);
extern cBgmHead *cBgmData_GetHeadPtr(cBgmData *);
extern cBgmTbl *cBgmData_GetTblPtr(cBgmData *, int);
extern void cBgmData_Reset(cBgmData *);
extern int D_00747A2C;
extern char D_0044CF68[];
extern char D_00583F20[];
extern void cSeData_Release(cSeData *);
extern void func_002CFD50(cSeData *);
extern int cDvd_FileExist(char *, char *);
extern int cDvd_ReadAlloc(char *, char *, void *, void *, int, int, int, int);
extern void func_002CFCB0(cSeData *, int);
extern char D_00603A40[];
extern char D_0044CFB8[];

/* Load bank bankId from the file named by arg; 1 when the data arrived. */
__attribute__((section(".text.cSeData_LoadFile")))
int cSeData_LoadFile(cSeData *d, int bankId, int arg)
{
    char name[0x40];

    if (d->state != 0) {
        if (D_00747A2C >= 0)
            return 0;
        cSeData_Release(d);
    }
    d->bankId = bankId;
    d->state = 1;
    d->f3C = 0x7FFFFFFF;
    func_002CFD50(d);
    func_003A6C58(name, D_0044CF68, arg);
    if (cDvd_FileExist(D_00583F20, name) == 0 ||
        (d->f38 = cDvd_ReadAlloc(D_00583F20, name, &d->buf, d->pool, 0, 0, 0, 0)) == 0 ||
        d->buf == 0) {
        cSeData_Release(d);
        return 0;
    } else {
        func_002CFCB0(d, 1);
        return 1;
    }
}

/* Both lookups of the slot's two table keys succeed. */
__attribute__((section(".text.cSeData_HasBankKeys")))
int cSeData_HasBankKeys(cSeData *d)
{
    if (func_002D2EE8(D_00603A40, d->f30) == 0 || func_002D2EE8(D_00603A40, d->f34) == 0)
        return 0;
    return 1;
}

/* Validate the loaded bank image and rebase its pointers once; 1 when usable. */
__attribute__((section(".text.cSeData_CheckImage")))
int cSeData_CheckImage(cSeData *d)
{
    cSeBuf *b;

    if (func_003A5BD8(d->buf, D_0044CFB8, 3) != 0)
        return 0;
    b = d->buf;
    if (b->version != 1.1f)
        return 0;
    if (b->f10 == 0)
        return 0;
    if (b->relocated == 0) {
        b->f10 += (int)b;
        d->buf->f20 += (int)b;
        d->buf->f28 += (int)b;
        if (d->buf->f18 != 0)
            d->buf->f18 += (int)b;
        d->buf->relocated = 1;
    }
    b = d->buf;
    d->f14 = b->f10;
    if (d->f3C == 0x7FFFFFFF)
        d->f3C = b->f08;
    d->f28 = d->bankId + 0x82;
    d->f20 = d->buf->f18;
    func_002CFCB0(d, 4);
    if (d->buf->f30 != 0) {
        if (func_002CFBC0(d) == 0)
            func_002CFCB0(d, 8);
    } else {
        func_002CFCB0(d, 8);
    }
    func_002CFCB0(d, 2);
    return 1;
}
