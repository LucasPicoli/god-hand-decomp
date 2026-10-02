/* sn-2.95.3-136 matched TU. */

#include "godhand/cEmSetParam.h"

/* Marks the table's file as not in use, then loads the given room file. */
__attribute__((section(".text.cEmSetParam_rewriteDataSet")))
void cEmSetParam_rewriteDataSet(cEmSetParam *self, cEmSetFile *file)
{
    D_005E8658.block->flags &= ~EMSET_LOADED;
    func_00294B98(self, file);
}

/* Sets the starting health of entry id; a value of 0 or less keeps the default. */
__attribute__((section(".text.func_002954D0")))
void func_002954D0(cEmSetParam *self, int id, int vital)
{
    cEmSetEntry *entry = func_002BEF60(&D_005E8658, id);

    if (entry != 0) {
        if (vital > 0)
            entry->vital = vital;
        else
            entry->vital = 0;
    }
}
