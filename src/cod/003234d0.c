/* cygnus-2.96 matched TU. */

#include "godhand/criFs.h"
#include "godhand/globals.h"
#include "godhand/adxfObj.h"

extern int dvci_get_fstate(char *name, CriFileStat *info);
extern void PushGlobalD8478History_331C78(int id);
extern int dvCiCdSearchFile(CriFileStat *info, char *dir);
extern void func_003260C8(char *fmt, char *dir);
extern char D_003D9C90[];
extern char D_00454328[];

/* Returns the found flag of the named file, searching the disc for it once when
 * the cached state has not located it; 0 when the search fails. */
__attribute__((section(".text.dvCi_getFileSizeUnchecked")))
int dvCi_getFileSizeUnchecked(char *name)
{
    CriFileStat info;

    dvci_get_fstate(name, &info);
    if (info.found == 0) {
        func_00333390(name, D_003D9C90);
        PushGlobalD8478History_331C78(0x8400);
        func_00398DA0(0);
        PushGlobalD8478History_331C78(0x8401);
        if (dvCiCdSearchFile(&info, D_003D9C90) == 0) {
            func_003260C8(D_00454328, D_003D9C90);
            return 0;
        }
    }
    return info.found;
}

/* Take a free pool slot, give it a buffer and initialise it. 0 on failure. */
__attribute__((section(".text.adxf_CreateAdxFs")))
AdxfObj *adxf_CreateAdxFs(void) {
    AdxfObj *obj = adxf_AllocAdxFs();
    if (obj == 0) {
        func_0033F130(D_004515E8);
        return 0;
    }
    obj->buf = func_00327D00(0, ADXFOBJ_BUF_LEN);
    if (obj->buf == 0) {
        func_0033F130(D_00451620);
        return 0;
    }
    obj->used = obj->kind = ADXFOBJ_STATE_USED;
    obj++;  /* no-op pair: shifts the allocation and sched1 so the 0x200 load */
    obj--;  /* comes first and the stores keep source order, as retail has */
    obj->unk18 = 0;
    obj->unk1C = 0;
    obj->unk20 = 0;
    obj->flag02 = 0;
    obj->unk08 = 0;
    obj->flag03 = 0;
    obj->param = ADXFOBJ_DEF_PARAM;
    return obj;
}
