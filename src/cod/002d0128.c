/* sn-2.95.3-136: cBgmData_LoadNumbered, read bgm data file number req of part kind into the slot;
 * 1 when the data arrived. */
#include "godhand/heapArena.h"
#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"
#include "godhand/globals.h"

extern void cBgmData_Reset(cBgmData *);
extern int cBgmData_AddLoadBits(cBgmData *, int);
extern int func_003A6C58(char *buf, const char *fmt, ...);
extern int cDvd_FileExist(char *, char *);
extern int cDvd_ReadAlloc(char *, char *, void *, void *, int, int, int, int);
extern char D_00583F20[];

__attribute__((section(".text.cBgmData_LoadNumbered")))
int cBgmData_LoadNumbered(cBgmData *d, int kind, int req)
{
    char name[0x40];

    d->pool = &D_00754210;
    d->f18 = kind + 0x80;
    d->f20 = req;
    switch (d->f18) {
    case 0x80:
        func_003A6C58(name, D_0044D078, req);
        break;
    case 0x81:
        func_003A6C58(name, D_0044D088, req);
        break;
    }
    if (cDvd_FileExist(D_00583F20, name) == 0)
        return 0;
    d->f1C = cDvd_ReadAlloc(D_00583F20, name, &d->head, d->pool, 0, 0, 0, 0);
    if (d->f1C == 0 || d->head == 0) {
        cBgmData_Reset(d);
        return 0;
    } else {
        cBgmData_AddLoadBits(d, 1);
        return 1;
    }
}
