/* include/godhand/cCockItem.h - cCockItem, the casino's item display.
 *
 * cCockItem is a cIDBase display of the key card and key counts (entries 0
 * and 1, cached in `ent`), with a second display at 0xB0 for a ticket whose
 * message pack LoadTicket reads from the disc into `ticket`. The DispMgr
 * holds one at 0x1910.
 *
 * Method names are the game's own where the symbol table has them. Field
 * names are ours, taken from the methods that read and write them. Offsets
 * are exact; a field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CCOCKITEM_H
#define GODHAND_CCOCKITEM_H

#include "godhand/cIDBase.h"

#define COCKITEM_ENT_NUM  2

typedef struct cCockItem {
    cIDBaseObj base;                    /* 0x000 the key card (entry 0) and key (entry 1) counts */
    char unk048[0x90 - sizeof(cIDBaseObj)];
    void *ticket;                       /* 0x090 the ticket's message pack, 0 when none is loaded */
    int readId;                         /* 0x094 disc read request */
    char unk098[4];
    cIDBaseEnt *ent[COCKITEM_ENT_NUM];  /* 0x09C */
    char unk0A4[0xB0 - 0xA4];
    cIDBaseObj ticketBase;              /* 0x0B0 the ticket display */
    char unk0F8[0x100 - 0xF8];
    int ticketSeed;                     /* 0x100 seed of the ticket entries; entry 0 is hidden while 0 */
    unsigned char showSecond;           /* 0x104 1: ticket entry 1 is shown too */
} cCockItem;

typedef char cCockItem_ent_check[((int)&((cCockItem *)0)->ent == 0x9C) ? 1 : -1];
typedef char cCockItem_ticketBase_check[((int)&((cCockItem *)0)->ticketBase == 0xB0) ? 1 : -1];
typedef char cCockItem_showSecond_check[((int)&((cCockItem *)0)->showSecond == 0x104) ? 1 : -1];

#endif
