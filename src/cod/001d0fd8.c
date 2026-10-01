/* sn-2.95.3-136 matched TU. */

#include "godhand/BlackJack.h"
#include "godhand/vu0.h"
#include "godhand/cIDBase.h"

extern int D_003BD6E8;
extern void func_00143A90();
extern int D_00569B70;
extern int D_0042AFE0[BLACKJACK_SUIT_NUM];
extern float D_00568050[4];
extern BlackJackCardObj *CreateObj(int id, int a1);
extern void cOmTrump_Initialize(BlackJackCardObj *obj, int rank);
extern void func_001D4DF0(BlackJack *self);
extern void BlackJackId_SetDefaultDisp(BlackJack *self);
extern void CustomIDWork_SetNumber_1D5760(BlackJack *self, int n);
extern int GetTimerValue_1FA710(int *save);
extern void func_001D5780(BlackJack *self, int gold);
extern int *D_003C2384;
extern void *D_003C2380;
extern unsigned char *D_003C23A4;
extern int D_005E7510;
extern int D_007474A0;
extern char D_0044AF20[];
extern char D_0044AF28[];
extern char D_0044AF30[];
extern void *SearchData(void *a, void *b, int c);
extern void cFont_setTextureAddr(void *a0, int a1, void *a2, void *a3);
extern void cMessDrawFont_setEnvInit(void *a0);
extern void func_002AF6A8(void *a0, int a1, int a2);

/* State 0, first call: start the table sound-bank load and mark setup done. */
__attribute__((section(".text.func_001D4480")))
void func_001D4480(BlackJack *self)
{
    if (self->phase == 0) {
        func_00143A90(D_003BD6E8 + 0x1AE0);
        self->flags |= BLACKJACK_FLAG_SETUP;
        self->phase += 1;
    }
}

/* Both sides have stood: compare the totals and pick the result state (0xE dealer wins, 0xF player wins, 0x10 push, 0x11 blackjack). */
__attribute__((section(".text.func_001D3430")))
void func_001D3430(BlackJack *self)
{
    int player = func_001D4720(self);
    int dealer = func_001D47E8(self);

    if (func_001D48B0(self) != 0) {
        if (func_001D4918(self) != 0) {
            self->phase = 0;
            self->state = 0x10;
            return;
        }
        self->phase = 0;
        self->state = 0x11;
        return;
    }
    if (func_001D49B0(self) != 0) {
        self->phase = 0;
        self->state = 0xF;
        return;
    }
    if (player == 0x15) {
        if (func_001D4918(self) != 0) {
            self->phase = 0;
            self->state = 0xF;
            return;
        }
        if (dealer == player) {
            self->phase = 0;
            self->state = 0x10;
            return;
        }
        self->phase = 0;
        self->state = 0xE;
        return;
    }
    if (player >= 0x15)
        return;
    if (dealer < player) {
        self->phase = 0;
        self->state = 0xE;
        return;
    }
    if (dealer >= 0x16) {
        self->phase = 0;
        self->state = 0xE;
        return;
    }
    if (player == dealer) {
        self->phase = 0;
        self->state = 0x10;
        return;
    }
    self->phase = 0;
    self->state = 0xF;
    return;
}

typedef struct BlackJackSuitIds {
    int w[BLACKJACK_SUIT_NUM];
} BlackJackSuitIds;

typedef struct BlackJackInitFrame {
    int suitId[BLACKJACK_SUIT_NUM];     /* sp+0x00 model id per suit */
    float pos[4];                       /* sp+0x10 */
} BlackJackInitFrame;












/* Flag-word address of a deck card. A helper so the +0x1638 stays out of the lw/sw displacement, as retail has it. */
static __inline__ unsigned int *CardFlagAddr(char *p)
{
    return (unsigned int *)p;
}

#define CARD_SCALE 1.39f

/* Set up a table of the given level: pick the top bet, build all 52 card objects. */
__attribute__((section(".text.BlackJack_Initialize")))
void BlackJack_Initialize(BlackJack *self, int level)
{
    BlackJackInitFrame f;
    unsigned short n;
    BlackJackCard *deck;
    float *pos;
    int suit;
    int rank;

    self->level = level;
    switch (level) {
    case 0:
        self->betMax = 300;
        break;
    case 1:
        self->betMax = 500;
        break;
    case 2:
        self->betMax = 1000;
        break;
    case 3:
        self->betMax = 2000;
        break;
    }
    suit = 0;
    *(BlackJackSuitIds *)f.suitId = *(BlackJackSuitIds *)D_0042AFE0;
    n = suit;
    pos = f.pos;
    deck = self->deck;
    for (suit = 0; suit < BLACKJACK_SUIT_NUM; suit++) {
        for (rank = 0; rank < BLACKJACK_RANK_NUM; rank++) {
            BlackJackCardObj *obj = CreateObj(f.suitId[suit], 0xFFFF);
            float *src = D_00568050;

            if (obj != 0) {
                unsigned int *fl;
                BlackJackCard *card;

                VU0_LQC2(4, src, 0);
                VU0_SQC2(4, &f, 0x10);
                card = &deck[n];
                card->obj = obj;
                cOmTrump_Initialize(obj, rank);
                card->obj->vtbl[14].pfn((char *)card->obj + card->obj->vtbl[14].delta, pos);
                fl = CardFlagAddr((char *)self + 0x1638 + n * 8);
                n += 1;
                card->obj->scale[0] = CARD_SCALE;
                card->obj->scale[1] = CARD_SCALE;
                card->obj->scale[2] = CARD_SCALE;
                card->obj->flags |= 2;
                *fl |= 1;
            }
        }
    }
    func_001D4DF0(self);
    BlackJackId_SetDefaultDisp(self);
    CustomIDWork_SetNumber_1D5760(self, 0);
    func_001D5780(self, GetTimerValue_1FA710(&D_00569B70));
}

/* Bind a packed message resource: look up its font textures and the cursor
 * sprite, then reset the shared message-draw environment. 1 on success. */
__attribute__((section(".text.cIDBase_setPackedMessData")))
int cIDBase_setPackedMessData(cIDBaseObj *self, int resNo, int arg)
{
    void *packed;
    char *g;
    int mode;

    packed = func_002ACD78(*D_003C2384, resNo, arg + 1);
    if (packed == 0) return 0;
    self->packed = packed;
    g = (char *)&D_007474A0;
    mode = *(int *)(g + 0x56C);
    if (mode == 0) {
        void *t = SearchData(packed, D_0044AF20, 0);
        cFont_setTextureAddr(D_003C2380, 3, t, SearchData(packed, D_0044AF28, 0));
    } else if (mode >= 0) {
        if (mode < 7) {
            void *t = SearchData(*(void **)(g + 0x558), D_0044AF20, 0);
            cFont_setTextureAddr(D_003C2380, 3, t, SearchData(packed, D_0044AF28, 0));
        }
    }
    *(void **)(D_003C23A4 + 0x8) = SearchData(packed, D_0044AF30, 0);
    cMessDrawFont_setEnvInit(&D_005E7510);
    func_002AF6A8(&D_005E7510, 2, 0);
    return 1;
}
