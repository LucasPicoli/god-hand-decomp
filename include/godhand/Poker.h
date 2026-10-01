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
    char unk303C[0xC];
    int unk3048;                        /* 0x3048 */
    int unk304C;                        /* 0x304C */
    char unk3050;                       /* 0x3050 */
    char unk3051;
    short cardId[POKER_HAND_NUM];       /* 0x3052 card ids, POKER_CARD_NONE = empty slot */
} Poker;                                /* 0x305C */

#endif
