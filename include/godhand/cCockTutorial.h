/* include/godhand/cCockTutorial.h - cCockTutorial, the cockfight tutorial panels.
 *
 * cCockTutorial is a cIDBase display object. roomInit loads the tutorial
 * message pack for the room (once, through the disc reader), initialises
 * the display and looks up seven display entries by id into `ent`. Two of
 * them start hidden, two show message 0x200C and the first is shrunk to 0.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CCOCKTUTORIAL_H
#define GODHAND_CCOCKTUTORIAL_H

#include "godhand/cIDBase.h"

#define COCKTUT_ENT_NUM   7
#define COCKTUT_MSG_PACK  0x1D          /* message pack number of the tutorial */
#define COCKTUT_MSG_NONE  0xFFFF

typedef struct cCockTutorial {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x90 - sizeof(cIDBaseObj)];
    cIDBaseEnt *ent[COCKTUT_ENT_NUM];   /* 0x90 display entries looked up by id 0..6 */
    char unkAC2[0xAC - 0x90 - 4 * COCKTUT_ENT_NUM];
    unsigned short curMsg;              /* 0xAC */
    char unkAE[2];
    void *data;                         /* 0xB0 the loaded message pack, 0 before the first load */
    int readId;                         /* 0xB4 disc read request */
    unsigned char unkB8;                /* 0xB8 */
} cCockTutorial;

#endif
