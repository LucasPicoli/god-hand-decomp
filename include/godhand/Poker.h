/* include/godhand/Poker.h - the casino poker table.
 *
 * Poker is one object of about 0x3040 bytes. Its layout is the same idea as
 * BlackJack (see BlackJack.h): display entries first, then the card deck of
 * 52 objects with one flag word each, a hand of 5 card slots, the state
 * machine fields and the bet. Offsets are exact; unnamed fields stay as
 * unkNNN padding.
 */
#ifndef GODHAND_POKER_H
#define GODHAND_POKER_H

#include "godhand/BlackJack.h"   /* BlackJackCard, BlackJackCardObj, BlackJackVtEnt */

#define POKER_DECK_NUM   52
#define POKER_HAND_NUM   5
#define POKER_SUIT_NUM   4
#define POKER_RANK_NUM   13
#define POKER_CARD_NONE  0x34
#define POKER_CARD_RESET 0x9    /* BlackJackCard.flags of every card after a deck reset */

typedef struct Poker {
    char unk0000[0x2E60];
    int level;                          /* 0x2E60 table level, 0..3 */
    BlackJackCard deck[POKER_DECK_NUM]; /* 0x2E64 */
    BlackJackCard *hand[POKER_HAND_NUM]; /* 0x3004 */
    char node[8];                       /* 0x3018 display node, set up by Obj0000_Init_Fields_00_04 */
    int flags;                          /* 0x3020 */
    unsigned char state;                /* 0x3024 */
    unsigned char phase;                /* 0x3025 step inside the state */
    char unk3026[2];
    int timer;                          /* 0x3028 frames left in the current step */
    int unk302C;                        /* 0x302C */
    int betMax;                         /* 0x3030 top bet for this level */
    int bet;                            /* 0x3034 */
    int payout;                         /* 0x3038 */
    int unk303C;                        /* 0x303C */
    int choice;                         /* 0x3040 0 or 1 on the two-choice panel */
    unsigned char cursorOn;             /* 0x3044 1 while the choice is 0 */
    unsigned char unk3045;              /* 0x3045 cleared when the panels slide in */
    char unk3046[2];
    int unk3048;                        /* 0x3048 */
    int unk304C;                        /* 0x304C */
    char unk3050;                       /* 0x3050 */
    char unk3051;
    short cardId[POKER_HAND_NUM];       /* 0x3052 card ids, POKER_CARD_NONE = empty slot */
} Poker;                                /* 0x305C */

/* The table's UI record (a PanelObj) sits at 0x25B0 and is not typed in Poker yet. */
#define POKER_UI(self)  ((char *)(self) + 0x25B0)

/* Sorted rank patterns of the nine non-royal straights (A-5 .. 9-K). */
typedef struct PokerStraightTbl {
    int rank[9][POKER_HAND_NUM];
} PokerStraightTbl;                     /* 0xB4 */

extern PokerStraightTbl D_0042B418;

/* Sorted rank patterns of all ten straights (A-5 .. 10-A). */
typedef struct PokerStraightTbl10 {
    int rank[10][POKER_HAND_NUM];
} PokerStraightTbl10;                   /* 0xC8 */

extern PokerStraightTbl10 D_0042B4D0;

/* The hand as the hand-ranking helpers (0x1DC980..) see it, with the slot flags as an int. */
#define POKER_HAND_F_MARK   0x4         /* PokerHandSlot.flags: card belongs to the scored group */

typedef struct PokerHandCard {
    char unk000[0x604];
    int rank;                           /* 0x604 as BlackJackCardObj.rank */
} PokerHandCard;

typedef struct PokerHandSlot {
    PokerHandCard *card;                /* 0x00 */
    int flags;                          /* 0x04 */
} PokerHandSlot;

typedef struct PokerHandView {
    char unk0000[0x3004];
    PokerHandSlot *slot[POKER_HAND_NUM]; /* 0x3004 Poker.hand */
} PokerHandView;

#endif
