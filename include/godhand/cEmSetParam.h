/* include/godhand/cEmSetParam.h - cEmSetParam, the room's enemy placement list.
 *
 * A room file holds a table of enemy placements (the game's SET_EM_DATA
 * source records). cEmSetParam_setEmData checks the file tag, hands the entry
 * array to the table object D_005E8658 and keeps the file and the array
 * pointer in the cEmSetParam object (D_00586AB0). setEmAll walks the table
 * once to load every needed actor and sound bank, then creates the enemies
 * of every entry that is not marked done. setEm creates one entry's enemy.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact. A field we can't name yet keeps its offset as its name
 * (unkNN). The entry record is at least 0x18 bytes and its stride is not
 * known here.
 */
#ifndef GODHAND_CEMSETPARAM_H
#define GODHAND_CEMSETPARAM_H

#include "godhand/cEmManage.h"

#define EMSET_TAG        0x534D45     /* "EMS", the first word of a room file */
#define EMSET_LOADED     0x80000000   /* word 0 of the table block: file in use */
#define EMSET_OBJ_BASE   0x200        /* an entry's objNo / seBank add this */
#define EMSET_STOP       1            /* cEmSetParam.stopFlag */
#define EMSET_ENTRY_DONE 1            /* cEmSetEntry.done: already created */

/* Entry positions are stored in 1/20 units, rotation in 1/100 degrees. */
#define EMSET_POS_SCALE  0.05f
#define EMSET_ROT_SCALE  0.017453292f
#define EMSET_ROT_PER_RAD 57.2957763671875f  /* 1 / EMSET_ROT_SCALE, as the game rounds it */

/* One placement of an enemy in the room file. */
typedef struct cEmSetEntry {
    short pos[3];                   /* 0x00 x, y, z in EMSET_POS_SCALE units */
    short rot;                      /* 0x06 EMSET_ROT_SCALE units */
    unsigned int flags;             /* 0x08 bit 31 set once handled */
    int seNo;                       /* 0x0C passed on as SET_EM_DATA.seNo */
    unsigned char appPattern;       /* 0x10 */
    unsigned char seBank;           /* 0x11 + EMSET_OBJ_BASE */
    unsigned char objNo;            /* 0x12 + EMSET_OBJ_BASE is the actor id */
    unsigned char entryNo;          /* 0x13 cEmManage_GetEm's key */
    unsigned char done;             /* 0x14 EMSET_ENTRY_DONE */
    char unk15;
    short vital;                    /* 0x16 starting health, 0 keeps the default */
} cEmSetEntry;

/* The room file: its tag, the entry count and the entries from 0x0C on. */
typedef struct cEmSetFile {
    int tag;                        /* 0x00 EMSET_TAG */
    int entryNum;                   /* 0x04 */
    int unk08;
    cEmSetEntry entry[1];           /* 0x0C */
} cEmSetFile;

/* The block the table object points at. Only its flag word is known. */
typedef struct cEmSetBlock {
    unsigned int flags;             /* 0x00 EMSET_LOADED */
} cEmSetBlock;

/* The table object D_005E8658 that indexes the entries of the loaded file. */
typedef struct cEmSetTable {
    cEmSetBlock *block;             /* 0x00 */
} cEmSetTable;

typedef struct cEmSetParam {
    unsigned char stopFlag;         /* 0x00 EMSET_STOP: skip the next setEmAll */
    char unk01[3];
    int unk04;                      /* 0x04 room number, read by func_00294F70 */
    cEmSetFile *file;               /* 0x08 the file validated by func_00294B98 */
    cEmSetEntry *entry;             /* 0x0C its entry array */
} cEmSetParam;

#define EMSETPARAM_OFFSET(field) ((int)&((cEmSetParam *)0)->field)
typedef char cEmSetParam_chk_file[EMSETPARAM_OFFSET(file) == 0x8 ? 1 : -1];
typedef char cEmSetParam_chk_entry[EMSETPARAM_OFFSET(entry) == 0xC ? 1 : -1];
typedef char cEmSetEntry_chk_vital[(int)&((cEmSetEntry *)0)->vital == 0x16 ? 1 : -1];

/* The table object and the one cEmSetParam object. */
extern cEmSetTable D_005E8658;
extern cEmSetParam D_00586AB0;

#endif /* GODHAND_CEMSETPARAM_H */
