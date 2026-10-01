/* TU: Poker [casino] - recovered C++ class. */
#include "godhand/Poker.h"
#include "godhand/vu0.h"

extern void func_001DD340();
extern void SetCustomIDNumberIndexed_1DD648();
extern int D_00569B70;
extern void func_001D6E20();
extern void func_001D6F30();
extern void func_001DD238();
extern int cCoreSave_getGold();
extern void PokerId_Move();
extern void PokerId__Trans();

typedef struct PokerSuitIds {
    int w[POKER_SUIT_NUM];
} PokerSuitIds;

typedef struct PokerInitFrame {
    int suitId[POKER_SUIT_NUM];     /* sp+0x00 model id per suit */
    float pos[4];                       /* sp+0x10 */
} PokerInitFrame;

extern int D_0042B270[POKER_SUIT_NUM];
extern float D_00568150[4];
extern BlackJackCardObj *CreateObj(int id, int a1);
extern void cOmTrump_Initialize(BlackJackCardObj *obj, int rank);
extern void func_001DF890(Poker *self);

/* Flag-word address of a deck card. A helper so the +0x2E68 stays out of the lw/sw displacement, as retail has it. */
static __inline__ unsigned int *CardFlagAddr(char *p)
{
    return (unsigned int *)p;
}

#define CARD_SCALE 1.39f

/* Set up a table of the given level: pick the top bet, build all 52 card objects. */
__attribute__((section(".text.Poker_Initialize")))
void Poker_Initialize(Poker *self, int level)
{
    PokerInitFrame f;
    unsigned short n;
    BlackJackCard *deck;
    float *pos;
    int suit;
    int rank;

    self->level = level;
    switch (level) {
    case 0:
        self->betMax = 100;
        break;
    case 1:
        self->betMax = 300;
        break;
    case 2:
        self->betMax = 500;
        break;
    case 3:
        self->betMax = 1000;
        break;
    }
    suit = 0;
    *(PokerSuitIds *)f.suitId = *(PokerSuitIds *)D_0042B270;
    n = suit;
    pos = f.pos;
    deck = self->deck;
    for (suit = 0; suit < POKER_SUIT_NUM; suit++) {
        for (rank = 0; rank < POKER_RANK_NUM; rank++) {
            BlackJackCardObj *obj = CreateObj(f.suitId[suit], 0xFFFF);
            float *src = D_00568150;

            if (obj != 0) {
                unsigned int *fl;
                BlackJackCard *card;

                VU0_LQC2(4, src, 0);
                VU0_SQC2(4, &f, 0x10);
                card = &deck[n];
                card->obj = obj;
                cOmTrump_Initialize(obj, rank);
                card->obj->vtbl[14].pfn((char *)card->obj + card->obj->vtbl[14].delta, pos);
                fl = CardFlagAddr((char *)self + 0x2E68 + n * 8);
                n += 1;
                card->obj->scale[0] = CARD_SCALE;
                card->obj->scale[1] = CARD_SCALE;
                card->obj->scale[2] = CARD_SCALE;
                card->obj->flags |= 2;
                *fl |= 1;
            }
        }
    }
    func_001DF890(self);
}

__attribute__((section(".text.Poker_Release")))
void Poker_Release(void) {
    func_001DF940();
}


__attribute__((section(".text.Poker_SetDefaultDisp")))
void Poker_SetDefaultDisp(int a0) {
    func_001DD340(a0);
    SetCustomIDNumberIndexed_1DD648(a0, 0, 0x32);
    SetCustomIDNumberIndexed_1DD648(a0, 1, 0x14);
    SetCustomIDNumberIndexed_1DD648(a0, 2, 0xF);
    SetCustomIDNumberIndexed_1DD648(a0, 3, 0xA);
    SetCustomIDNumberIndexed_1DD648(a0, 4, 0x8);
    SetCustomIDNumberIndexed_1DD648(a0, 5, 0x8);
    SetCustomIDNumberIndexed_1DD648(a0, 6, 0x3);
    SetCustomIDNumberIndexed_1DD648(a0, 7, 0x2);
}

typedef struct PokerStateEnt {
    short delta;
    short pad;
    void (*fn)();
} PokerStateEnt;
extern PokerStateEnt D_003BE000[];  /* replaces extern char D_003BE000[] */
/* Per-frame update: run the current state handler, then update the hand and the display. */
__attribute__((section(".text.Poker_Main")))
void Poker_Main(Poker *self)
{
    int s1;
    BlackJackCard **s0;
    BlackJackCard **s3;
    int i = self->state;
    short off = D_003BE000[i].delta;
    void (*fn)() = D_003BE000[i].fn;
    fn((char *)self + off);

    s3 = self->hand;
    s1 = 4;
    s0 = s3;
    do {
        if (*s0 != 0) {
            func_001D6E20(*s0);
        }
        s1 = s1 - 1;
        s0 = s0 + 1;
    } while (s1 >= 0);

    s0 = s3;
    s1 = 4;
    do {
        if (*s0 != 0) {
            func_001D6F30(*s0);
        }
        s1 = s1 - 1;
        s0 = s0 + 1;
    } while (s1 >= 0);

    func_001DD238(self, cCoreSave_getGold(&D_00569B70));
    PokerId_Move(self);
    PokerId__Trans(self);
}
