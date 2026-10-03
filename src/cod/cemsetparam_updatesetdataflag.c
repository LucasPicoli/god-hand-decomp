#include "godhand/cEmSetParam.h"

/* cEmSetParam_updateSetDataFlag — look up the set-data entry for id a1 in the
 * D_005E8658 table (func_002BEF60); if found, store the user pointer a2 at its
 * 0x8 field.  sn-2.95.3-136. */

extern cEmSetEntry *func_002BEF60(cEmSetTable *table, int id);

/* Stores the flag word of entry id, if the table has that entry. */
__attribute__((section(".text.cEmSetParam_updateSetDataFlag")))
void cEmSetParam_updateSetDataFlag(cEmSetParam *self, int id, unsigned int flags) {
    cEmSetEntry *entry = func_002BEF60(&D_005E8658, id);
    if (entry)
        entry->flags = flags;
}
