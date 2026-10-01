/* include/godhand/BlackJack.h - the casino blackjack table.
 *
 * BlackJack is one object of 0x1836 bytes. Its first 0x1630 bytes
 * are the cIDBase / CustomIDWork display entries (BlackJackId works on
 * them). From 0x1630 on come the game fields named here: the card deck
 * (52 objects, each with a flag word), two hands of 5 card slots, a small
 * state machine (state, phase) and the bet.
 *
 * Offsets are exact. A field nobody has named yet stays as unkNNN padding.
 * Field names are ours, taken from the methods that read and write them.
 */
#ifndef GODHAND_BLACKJACK_H
#define GODHAND_BLACKJACK_H

#define BLACKJACK_DECK_NUM   52
#define BLACKJACK_HAND_NUM   5      /* card slots per hand */
#define BLACKJACK_SUIT_NUM   4
#define BLACKJACK_RANK_NUM   13
#define BLACKJACK_CARD_FACE_DOWN 0x2   /* BlackJackCardObj.flags */
#define BLACKJACK_CARD_NONE      0x34  /* cardIdA/B entry for an empty slot */

/* flags word at +0x1800 */
#define BLACKJACK_FLAG_SETUP     0x1    /* phase 0 ran once */
#define BLACKJACK_FLAG_BET_STEP  0x8    /* bet was changed this frame */

/* states at +0x1804 */
enum {
    BLACKJACK_STATE_BET = 1,
    BLACKJACK_STATE_DEAL = 2
};

/* One g++ 2.x virtual table entry: `this` adjust, then the function. */
typedef struct BlackJackVtEnt {
    short delta;
    short index;
    void (*pfn)(void *self, float *pos);
} BlackJackVtEnt;

/* The cOmTrump object behind one card. Only the fields BlackJack touches. */
typedef struct BlackJackCardObj {
    char unk000[0xF0];
    float *pos;                         /* 0x0F0 -> x of the card position */
    char unk0F4[0x1C];
    float scale[3];                     /* 0x110 */
    char unk11C[0xF8];
    BlackJackVtEnt *vtbl;               /* 0x214 g++ 2.x vtable pointer */
    char unk218[0x38];
    unsigned int flags;                 /* 0x250 bit 1 = card is face down */
} BlackJackCardObj;

typedef struct BlackJackCard {
    BlackJackCardObj *obj;              /* 0x0 cOmTrump object */
    unsigned int flags;                 /* 0x4 bit 0 = card is out of the deck, bit 1 = card is on screen */
} BlackJackCard;                        /* 0x8 */

typedef struct BlackJack {
    char unk0000[0x1630];
    int level;                          /* 0x1630 table level, 0..3 */
    BlackJackCard deck[BLACKJACK_DECK_NUM]; /* 0x1634 */
    BlackJackCard *handA[BLACKJACK_HAND_NUM];  /* 0x17D4 */
    BlackJackCard *handB[BLACKJACK_HAND_NUM];  /* 0x17E8 */
    unsigned short dealSlot;            /* 0x17FC hand slot being dealt */
    unsigned short dealSlotB;           /* 0x17FE hand B slot being dealt */
    int flags;                          /* 0x1800 BLACKJACK_FLAG_* */
    int state;                          /* 0x1804 */
    int phase;                          /* 0x1808 step inside the state */
    int timer;                          /* 0x180C frames left in the current step */
    int betMax;                         /* 0x1810 top bet for this level */
    int bet;                            /* 0x1814 */
    int payout;                         /* 0x1818 winnings being paid out, in gold */
    char *camera;                       /* 0x181C */
    char unk1820[2];
    short cardIdA[BLACKJACK_HAND_NUM];  /* 0x1822 card ids dealt to hand A */
    short cardIdB[BLACKJACK_HAND_NUM];  /* 0x182C card ids dealt to hand B */
} BlackJack;                            /* 0x1836 */

#endif
