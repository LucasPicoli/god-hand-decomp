/* sn-2.95.3-136: func_001DA4E8, poker panel slide-in sequence. */
#include "godhand/Poker.h"
extern void Panel_slide(void *a0, int a1);
extern void func_001DE088(char *a0, unsigned char a1);
extern void func_001DE170(char *a0, unsigned char a1);
extern void func_001DE258(char *a0, unsigned char a1);
extern void func_001DE340(char *a0, unsigned char a1);
extern void CustomIDOwner_setSlideState(void *a0, unsigned char a1);
extern void PanelWork_setModeB(char *a0, unsigned char a1);
extern void CustomIDOwner_setSlideStateB(void *a0, unsigned char a1);
extern void PokerUi_slidePanel(void *a0, int a1);
extern void Panel_slideSidePanelArrows(void *a0, int a1);
extern void func_001DEE40(void *a0, int a1);
extern void UiPanel_setSlideMode(char *a0, unsigned char a1);

static inline unsigned char DecCount(int *p)
{
    if (*p == 0) {
        return 1;
    }
    *p = *p - 1;
    return 0;
}

__attribute__((section(".text.func_001DA4E8")))
void func_001DA4E8(Poker *self)
{
    switch (self->phase) {
    case 0:
        self->timer = 0x1E;
        self->unk3045 = 0;
        self->phase += 1;
        break;
    case 1:
        if (DecCount(&self->timer) == 0) {
            break;
        }
        Panel_slide(self, 3);
        func_001DE088((char *)self, 3);
        func_001DE170((char *)self, 3);
        func_001DE258((char *)self, 3);
        func_001DE340((char *)self, 3);
        CustomIDOwner_setSlideState(self, 3);
        PanelWork_setModeB((char *)self, 3);
        self->timer = 0x1E;
        self->phase += 1;
        break;
    case 2: {
        char *ui;
        int v;

        if (DecCount(&self->timer) == 0) {
            break;
        }
        ui = POKER_UI(self);
        CustomIDOwner_setSlideStateB(ui, 2);
        PokerUi_slidePanel(ui, 2);
        Panel_slideSidePanelArrows(ui, 2);
        v = self->payout;
        self->bet = v;
        func_001DEE40(ui, v);
        UiPanel_setSlideMode(ui, 2);
        self->phase = 0;
        self->state = 0xD;
        break;
    }
    }
}
