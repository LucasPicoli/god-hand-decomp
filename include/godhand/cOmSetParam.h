/* include/godhand/cOmSetParam.h - cOmSetParam, the room's object placement list.
 *
 * A room file holds a table of object placements in the SMO format (see
 * SmoData.h): a header with the entry count and the format version, then
 * 0x40-byte entries. cOmSetParam_setOmData binds the block to the reader and
 * creates one object for every entry, running the object's three setup
 * methods on the entry. Version 2 entries also carry a spawn key pair that is
 * copied to the object.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact. A field we can't name yet keeps its offset as its name
 * (unkNN).
 */
#ifndef GODHAND_COMSETPARAM_H
#define GODHAND_COMSETPARAM_H

#include "godhand/SmoData.h"

#define OMSET_ENTRY_SIZE    0x40
#define OMSET_VER_KEYED     2        /* first SMO version whose entries carry keys */
#define OMSET_KIND_STANDIN  0x2C3    /* entry kind that needs a stand-in enemy loaded */
#define OMSET_F_BIG         0x80     /* entry flags: create the large variant */
#define OMSET_SIZE_SMALL    0x300    /* added to the object number */
#define OMSET_SIZE_BIG      0x400
#define OMSET_MIN_SCALE     0.001f

/* One placement of an object in the room file. */
typedef struct cOmSetEntry {
    char unk00[0x10];
    char pos[0x10];                  /* 0x10 passed to the third setup method */
    int kind;                        /* 0x20 */
    unsigned char objNo;             /* 0x24 object number, plus the size class */
    char unk25[3];
    float scale;                     /* 0x28 */
    char unk2C[2];
    unsigned char flags;             /* 0x2E OMSET_F_* */
    unsigned char owner;             /* 0x2F copied to the object in keyed files */
    long key0;                       /* 0x30 spawn key, checked against the room save */
    long key1;                       /* 0x38 */
} cOmSetEntry;

typedef struct cOmSetParam {
    SmoReader reader;                /* 0x00 */
} cOmSetParam;

typedef char cOmSetEntry_chk_size[sizeof(cOmSetEntry) == OMSET_ENTRY_SIZE ? 1 : -1];
typedef char cOmSetEntry_chk_key[(int)&((cOmSetEntry *)0)->key0 == 0x30 ? 1 : -1];

#endif /* GODHAND_COMSETPARAM_H */
