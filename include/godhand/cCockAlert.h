/* include/godhand/cCockAlert.h - cCockAlert, a cockpit cIDBase display with
 * four entries.
 *
 * The class name is retail's: the vtable D_0041DC80 holds func_0013C220,
 * which builds it, and cCockAlert_refillEntries, which restarts it; its
 * type-info function (func_0013C558) registers "10cCockAlert" with base
 * "9cCockBase". The constructor stores the vtable pointer at 0x80
 * (0x1418EC). The method and field names are ours. The record is known up
 * to the end of `ent` (0xA8); its total size is not known.
 */
#ifndef GODHAND_CCOCKALERT_H
#define GODHAND_CCOCKALERT_H

#include "godhand/cIDBase.h"

#define COCKALERT_ENT_NUM 4

typedef struct cCockAlert {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x80 - sizeof(cIDBaseObj)];
    void *vtable;                       /* 0x80 */
    char unk84[0x90 - 0x84];
    int unk90;                          /* 0x90 */
    int sel;                            /* 0x94 */
    cIDBaseEnt *ent[COCKALERT_ENT_NUM]; /* 0x98 */
} cCockAlert;

typedef char cCockAlert_vtable_check[((int)&((cCockAlert *)0)->vtable == 0x80) ? 1 : -1];
typedef char cCockAlert_ent_check[((int)&((cCockAlert *)0)->ent == 0x98) ? 1 : -1];

#endif /* GODHAND_CCOCKALERT_H */
