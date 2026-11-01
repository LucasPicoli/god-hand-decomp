/* sn-2.95.3-136 matched TU. */
#include "godhand/cIDBase.h"
#include "godhand/cCoreSave.h"
#include "godhand/gameWork.h"

typedef struct ContinueScreen {
    cIDBaseObj base;
    char unk48[0x48];
    unsigned char selection;
    char unk91;
    unsigned short step;
    cIDBaseEnt *ent[11];
} ContinueScreen;

typedef struct ContinueCounters {
    int unk00;
    int continueNum;
} ContinueCounters;

extern ContinueCounters D_005CAC90;
extern char D_005FEE00[];
extern void func_002AC9B8(ContinueScreen *self, cIDBaseEnt *ent, short reset);
extern void cIDBase_move(cIDBaseObj *self);
extern int cSnd_SeCall_2CB8A0(void *sound, int slot, int key, int idA, int idB, int a5, int a6);

#define CONTINUE_INPUT_UP   0x0008000004000000UL
#define CONTINUE_INPUT_DOWN 0x0004000008000000UL
#define CONTINUE_INPUT_OK   0x10000000UL
#define CONTINUE_SOUND_MOVE 0x15F
#define CONTINUE_SOUND_OK   0x15E

/* Handle the continue screen's two choices and advance its closing animation. */
__attribute__((section(".text.func_0013D7B0")))
void func_0013D7B0(ContinueScreen *self)
{
    if (D_007474A0.trg & CONTINUE_INPUT_UP) {
        if (self->selection == 1) {
            self->ent[3]->flags &= ~IDENT_FLAG_NO_DRAW;
            func_002AC9B8(self, self->ent[3], 0);
            self->ent[2]->flags |= IDENT_FLAG_NO_DRAW;
            self->selection = 0;
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, CONTINUE_SOUND_MOVE, -1, -1, 0, 0);
        } else {
            goto check_down;
        }
    } else {
check_down:
        if ((D_007474A0.trg & CONTINUE_INPUT_DOWN) && self->selection == 0) {
            self->ent[2]->flags &= ~IDENT_FLAG_NO_DRAW;
            func_002AC9B8(self, self->ent[2], 0);
            self->ent[3]->flags |= IDENT_FLAG_NO_DRAW;
            self->selection = 1;
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, CONTINUE_SOUND_MOVE, -1, -1, 0, 0);
        }
    }
    if (D_007474A0.trg & CONTINUE_INPUT_OK) {
        self->base.playing = 1;
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, CONTINUE_SOUND_OK, -1, -1, 0, 0);
        if (self->selection == 1) {
            cCoreSave_addContinueNum(&D_00569B70);
            D_005CAC90.continueNum++;
            self->ent[5]->flags &= ~IDENT_FLAG_NO_DRAW;
            func_002AC9B8(self, self->ent[5], 0);
            self->ent[2]->flags |= IDENT_FLAG_NO_DRAW;
        } else {
            self->ent[6]->flags &= ~IDENT_FLAG_NO_DRAW;
            func_002AC9B8(self, self->ent[6], 0);
            self->ent[3]->flags |= IDENT_FLAG_NO_DRAW;
        }
        self->ent[0]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->ent[9]->flags &= ~IDENT_FLAG_NO_TINT;
        func_002AC9B8(self, self->ent[9], 0);
        func_002AC9B8(self, self->ent[0], 0);
        cIDBase_move(&self->base);
        self->step++;
    }
    if ((unsigned short)self->ent[1]->jit[4] >= 16 && !(self->ent[1]->flags & IDENT_FLAG_NO_DRAW)) {
        self->ent[8]->flags &= ~IDENT_FLAG_NO_DRAW;
        cIDBase_move(&self->base);
    }
}
