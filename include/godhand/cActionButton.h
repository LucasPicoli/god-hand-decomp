/* include/godhand/cActionButton.h - cActionButton, the on-screen action prompts.
 *
 * The manager hands out entries (func_001F7798 finds a free one). An entry
 * is one prompt: a priority, a matrix it is drawn with and up to a few
 * commands. setCommandList fills a fresh entry from a command list and
 * registers it. Each command is a 0xC-byte record that is split into
 * three parallel tables the entry points at (D_005685B0, D_00568650 and
 * D_005686A0 are the table storage).
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CACTIONBUTTON_H
#define GODHAND_CACTIONBUTTON_H

#define ACTBTN_ENT_USED    1            /* bit 0 of flags: the entry is in use */
#define ACTBTN_DEFAULT_LIFE 0x32
#define ACTBTN_DEFAULT_KIND 3

/* One command of a list. */
typedef struct COMMAND_LIST {
    int cmd;                            /* 0x00 */
    unsigned short id;                  /* 0x04 */
    char unk06[2];
    unsigned char arg;                  /* 0x08 */
    char unk09[3];
} COMMAND_LIST;                         /* 0xC */

typedef struct cActionButtonEnt {
    unsigned int flags;                 /* 0x00 */
    struct cActionButtonEnt *next;      /* 0x04 */
    char unk08[4];
    int unk0C;                          /* 0x0C */
    int unk10;                          /* 0x10 callback */
    int unk14;                          /* 0x14 callback argument */
    int priority;                       /* 0x18 */
    int life;                           /* 0x1C */
    int unk20;                          /* 0x20 */
    int kind;                           /* 0x24 */
    void *matrix;                       /* 0x28 the matrix the prompt is drawn with */
    int unk2C;                          /* 0x2C */
    unsigned short unk30;               /* 0x30 */
    short unk32;                        /* 0x32 */
    unsigned char cmdNum;               /* 0x34 commands in the tables */
    unsigned char unk35;                /* 0x35 */
    unsigned char unk36;                /* 0x36 */
    char unk37[1];
    int *cmdTbl;                        /* 0x38 */
    unsigned short *idTbl;              /* 0x3C */
    unsigned char *argTbl;              /* 0x40 */
} cActionButtonEnt;                     /* 0x44 */

typedef struct cActionButton {
    char unk000[0xF4];
    char head[0x10];                    /* 0xF4 entry list heads */
    cActionButtonEnt ent[8];            /* 0x104 */
} cActionButton;

/* The game object (D_003BD6E8) as the prompts see it. */
typedef struct ActBtnGame {
    char unk0000[0xEA0];
    char anim[0x90];                    /* 0xEA0 */
    unsigned int flags;                 /* 0xF30 */
    char unkF34[0x12C2 - 0xF34];
    unsigned short frame;               /* 0x12C2 */
} ActBtnGame;

extern int ReturnOne_1F6FA0(cActionButtonEnt *ent);
extern int GetNextAnimIndex_1451E0(void *anim);
extern void BlendSetup_load(void *anim, int *cmdTbl, unsigned short *idTbl,
                          unsigned char *argTbl, int cmdNum, int start);

/* Set action button 0xB (handler func_002DBB90) while the player is up, free and not caught. */
void func_002DBB08(void);

#endif
