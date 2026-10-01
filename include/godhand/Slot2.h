/* include/godhand/Slot2.h - the second slot machine.
 *
 * Slot2 is the casino slot machine game object, sibling of Slot1. It is a
 * state machine: `state` picks the screen, `step` walks one screen through its
 * stages, `timer` counts frames down between stages. Three reels sit at
 * +0x58, +0x140 and +0x228, 0xE8 bytes each. A layer object sits at +0x400
 * and a custom-ID work at +0x450.
 *
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_SLOT2_H
#define GODHAND_SLOT2_H

#define SLOT2_REEL_NUM     3
#define SLOT2_REEL_SIZE    0xE8
#define SLOT2_BET_MAX      3         /* bet level 0..3 */

/* Every part of the machine runs the same small state machine: a screen,
 * a step inside it and a phase inside the step. */
typedef struct Slot2Reel {
    int unk00;
    int state;                      /* 0x04 */
    int step;                       /* 0x08 */
    int phase;                      /* 0x0C */
    char unk10[0x98];
    int sym[3];                     /* 0xA8 symbol on the top, middle, bottom row */
    char unkB4[0xC];
    unsigned int doneFlag;          /* 0xC0 bit 0 set once the reel stopped */
    char unkC4[0x24];
} Slot2Reel;                        /* 0xE8 */

typedef struct Slot2Panel {         /* the prize board at +0x310 */
    int unk00;
    int state;                      /* 0x04 */
    int step;                       /* 0x08 */
    int phase;                      /* 0x0C */
    char unk10[0x44];
    unsigned int doneFlag;          /* 0x54 bit 0 = the board is settled */
} Slot2Panel;                       /* 0x58 */

typedef struct Slot2 {
    char unk00[4];
    int state;                      /* 0x004 screen */
    int step;                       /* 0x008 stage inside the screen */
    int phase;                      /* 0x00C stage inside the step */
    int timer;                      /* 0x010 frames until the next stage */
    char unk14[0x14];
    int coinUnit;                   /* 0x028 gold per paid coin */
    int coinNum;                    /* 0x02C coins still to pay */
    char unk30[0x24];
    unsigned int endFlag;           /* 0x054 bit 0 = the game is over */
    Slot2Reel reel[SLOT2_REEL_NUM]; /* 0x058 */
    Slot2Panel panel;               /* 0x310 */
    int betCost;                    /* 0x368 gold per bet level */
    int unk36C[6];                  /* 0x36C prize per line */
    char unk384[0x44];
    int lineLayer;                  /* 0x3C8 layer shown for the line marks */
    char unk3CC[4];
    unsigned short slotId;          /* 0x3D0 */
    unsigned short betLv;           /* 0x3D2 */
    int jackpotLine;                /* 0x3D4 prize line 2..5 */
    unsigned char pattern;          /* 0x3D8 reel pattern, 0..4 */
    char unk3D9[3];
    int camera;                     /* 0x3DC camera record in use */
    unsigned short markFlag[5];     /* 0x3E0 bit 15 = start lit, bit 14 = on */
    char unk3EA[2];
    int seId[3];                    /* 0x3EC sound handle per reel */
    char unk3F8[8];
    char layer[0x50];               /* 0x400 */
    char customId[0x5A];            /* 0x450 */
    unsigned short scroll;          /* 0x4AA */
    char unk4AC[0x5D4];
    unsigned short menuSel;         /* 0xA80 menu cursor 0..7 */
} Slot2;                            /* at least 0xA82 */

/* Fails to compile if a field drifts from the offset retail uses. */
typedef char Slot2_layer_check[(int)&((Slot2 *)0)->layer == 0x400 ? 1 : -1];
typedef char Slot2_seId_check[(int)&((Slot2 *)0)->seId == 0x3EC ? 1 : -1];
typedef char Slot2_menuSel_check[(int)&((Slot2 *)0)->menuSel == 0xA80 ? 1 : -1];

#endif
