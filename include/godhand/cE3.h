/* include/godhand/cE3.h - cE3, the E3 trade-show demo flow.
 *
 * cE3 is a small state object: a state byte at 0x00 (0 = menu, 1 = demo
 * run), a menu cursor at 0x02 and the ending kind at 0x03. The menu draws
 * its two entries through func_002E0D60 and moves the cursor with the pad
 * edges in D_007474A0 (0x2000 down, 0x8000 up). setEnding switches the
 * game into the ending and records which one.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CE3_H
#define GODHAND_CE3_H

#define CE3_STATE_MENU   0
#define CE3_STATE_DEMO   1
#define CE3_MENU_LAST    0x78       /* highest cursor value */

/* The game state block D_007474A0 as far as the E3 flow reads it. */
#define CE3_PAD_DOWN   0x2000
#define CE3_PAD_UP     0x8000
#define CE3_ROOM_END   0x20             /* room id with no demo clock */
#define CE3_W_NO_CLOCK 0x4000           /* flags5E4: skip the clock stop test */
#define CE3_W_BLOCKED  0x2000000        /* flags5E4: no ending now */

typedef struct cE3World {
    char unk00[0x98];
    unsigned int edge;                  /* 0x98 buttons that went down this frame */
    char unk9C[0x58C - 0x9C];
    int unk58C;                         /* 0x58C negative while no stage runs */
    char unk590[0x5B0 - 0x590];
    unsigned short room;                /* 0x5B0 */
    char unk5B2[0x5E4 - 0x5B2];
    unsigned int flags5E4;              /* 0x5E4 */
} cE3World;

/* The block D_00747A2C: the menu runs only while bit 0x800 of its flag word
 * (0x08) is set and the byte 0x4FC before it is non-zero. */
#define CE3_SYS_MENU_ON    0x800
#define CE3_SYS_BYTE_BELOW 0x4FC

typedef struct cE3Sys {
    char unk00[8];
    unsigned int flags;                 /* 0x08 */
} cE3Sys;

typedef struct cE3 {
    unsigned char state;                /* 0x00 CE3_STATE_* */
    unsigned char phase;                /* 0x01 step of the demo run: 0 start the fade, 1 wait for it, 2 done */
    unsigned char cursor;               /* 0x02 menu cursor, read as signed for the range tests */
    unsigned char ending;               /* 0x03 which ending setEnding was given */
} cE3;

#endif
