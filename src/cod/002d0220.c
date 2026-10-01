/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern cBgmData *cSnd_GetBgmData(cSnd *, int);
extern cBgmHead *cBgmData_GetHeadPtr(cBgmData *);
extern cBgmTbl *cBgmData_GetTblPtr(cBgmData *, int);
extern void func_002CFF90(cBgmData *);
extern char D_005FEE00[];
extern char D_00580D40[];
extern char D_0044D0B0[];
extern char D_0044D0C0[];
extern char D_0044D0D8[];
extern void *EnsureInitThenForward_2A9538_30EE08(int, int, void *);
extern int FindEntryValue_1FF9C0(char *, char *, int, int);
extern void func_002D0350(cBgmData *, int);
extern int func_002D0128(cBgmData *, int, int);
extern char D_00754210[];
extern char D_00583F20[];
extern char D_0044D0A0[];
extern int cDvd_FileExist(char *, char *);
extern int cDvd_ReadAlloc(char *, char *, void *, void *, int, int, int, int);

/* Is the request reqNo of bgm part 0 playing? */
__attribute__((section(".text.func_002D1578")))
int func_002D1578(void *unused, int reqNo)
{
    return func_002D22B0(D_005FEE00, 0, reqNo) != 0;
}

/* Allocate the decode buffer for the slot's table and register it; 1 on success. */
__attribute__((section(".text.func_002D03E8")))
int func_002D03E8(cBgmData *d)
{
    char name[0x40];
    int key;

    if (func_002CFF68(d) == 1)
        return 0;
    d->f14 = EnsureInitThenForward_2A9538_30EE08(((((unsigned int)(*(int *)d->head) + 0x8E) >> 1) << 2), 0x10, d->pool);
    switch (d->f18) {
    case 0x80:
        func_003A6C58(name, D_0044D0B0, d->f20);
        break;
    case 0x81:
        if (d->f20 != -1)
            func_003A6C58(name, D_0044D0C0, d->f20);
        else
            func_003A6C58(name, D_0044D0D8, d->name);
        break;
    }
    key = FindEntryValue_1FF9C0(D_00580D40, name, 0, 0);
    if (func_00322A68(d->f18, 0, key, d->f14) != 0)
        return 0;
    func_002D0350(d, 4);
    return 1;
}

/* Like func_002D0128 for a named table; 1 when the data arrived. */
__attribute__((section(".text.func_002D0220")))
int func_002D0220(cBgmData *d, int kind, int req)
{
    char name[0x40];

    d->f18 = kind + 0x80;
    d->f20 = -1;
    d->pool = D_00754210;
    func_003A57C4(d->name, req);
    switch (d->f18) {
    case 0x80:
        return 0;
    case 0x81:
        func_003A6C58(name, D_0044D0A0, req);
        break;
    }
    if (cDvd_FileExist(D_00583F20, name) == 0)
        return 0;
    d->f1C = cDvd_ReadAlloc(D_00583F20, name, &d->head, d->pool, 0, 0, 0, 0);
    if (d->f1C == 0 || d->head == 0) {
        func_002CFF90(d);
        return 0;
    } else {
        func_002D0350(d, 1);
        return 1;
    }
}
