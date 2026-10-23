/* sn-2.95.3-136: func_00141CE8, HUD panel reset: restart the panel animations, show the parts for the
 * game level and the god-item count, and reset the heat gauge values. */
#include "godhand/player.h"
#include "godhand/cCoreSave.h"
#include "godhand/cIDBase.h"

extern void cIDBase_restartAnim(cIDBaseObj *self);
extern float cHeatSys_GetHeatRatio(cHeatSys *self);
extern void func_002AC9B8(void *p, void *ent, int arg);

#define HUD_GOD_ITEM_NUM  6             /* god-item marks */
#define HUD_LEVEL_ENT     12            /* ent[] index of the first game-level mark */
#define IDENT_FLAG_400    0x00000400
#define IDENT_FLAG_1000   0x00001000

/* The HUD panel: four cIDBase objects, each followed by the work entries it drives. */
typedef struct HudPanel {
    cIDBaseObj base;                    /* 0x000 */
    char unk048[0x90 - 0x48];
    int unk090;                         /* 0x090 cleared on reset */
    char unk094[0x4];
    cIDBaseEnt *ent[18];                /* 0x098 */
    cIDBaseObj gauge;                   /* 0x0E0 */
    char unk128[0x130 - 0x128];
    cIDBaseEnt *godItem[HUD_GOD_ITEM_NUM]; /* 0x130 */
    char unk148[0x164 - 0x148];
    cIDBaseEnt *heatMark[6];            /* 0x164 */
    unsigned short level;               /* 0x17C game level shown, 0-based */
    char unk17E[0x2];
    int unk180;                         /* 0x180 cleared on reset */
    char unk184[0x190 - 0x184];
    cIDBaseObj frame;                   /* 0x190 */
    char unk1D8[0x1E8 - 0x1D8];
    cIDBaseEnt *frameEnt[10];           /* 0x1E8 */
    cIDBaseObj extra;                   /* 0x210 */
    char unk258[0x260 - 0x258];
    unsigned char godItemNum;           /* 0x260 */
    char unk261[0x3];
    float heat;                         /* 0x264 */
    float heatShown;                    /* 0x268 */
    char unk26C[0x3];
    unsigned char unk26F;               /* 0x26F cleared on reset */
} HudPanel;

__attribute__((section(".text.func_00141CE8")))
void func_00141CE8(HudPanel *self)
{
    int i;
    int n;
    cIDBaseObj *extra = &self->extra;
    cIDBaseObj *gauge = &self->gauge;
    cIDBaseObj *frame = &self->frame;

    self->unk090 = 0;
    cIDBase_restartAnim(&self->base);
    self->base.playing = 1;
    cIDBase_restartAnim(extra);
    extra->playing = 1;
    self->ent[12]->flags |= IDENT_FLAG_NO_DRAW;
    self->ent[13]->flags |= IDENT_FLAG_NO_DRAW;
    self->ent[14]->flags |= IDENT_FLAG_NO_DRAW;
    self->ent[15]->flags |= IDENT_FLAG_NO_DRAW;
    cIDBase_restartAnim(gauge);
    gauge->playing = 1;
    cIDBase_restartAnim(frame);
    frame->playing = 0;
    self->unk180 = 0;
    self->level = cCoreSave_getGameLevel(&D_00569B70);
    if (self->level == 4)
        self->level = 3;
    else if (self->level == 5)
        self->level = 4;
    self->level--;
    self->ent[self->level + HUD_LEVEL_ENT]->flags &= ~IDENT_FLAG_NO_DRAW;
    func_002AC9B8(self, self->ent[self->level + HUD_LEVEL_ENT], 0);
    self->frameEnt[5]->flags |= IDENT_FLAG_NO_DRAW;
    self->frameEnt[6]->flags |= IDENT_FLAG_NO_DRAW;
    self->frameEnt[7]->flags |= IDENT_FLAG_NO_DRAW;
    self->ent[12]->flags |= IDENT_FLAG_400;
    self->ent[13]->flags |= IDENT_FLAG_400;
    self->ent[14]->flags |= IDENT_FLAG_400;
    self->ent[15]->flags |= IDENT_FLAG_400;
    self->frameEnt[4]->flags |= IDENT_FLAG_1000;
    self->frameEnt[4]->sclX = 0.75f;
    self->frameEnt[4]->sclY = 0.75f;
    self->godItemNum = cCoreSave_getGodItemNum(&D_00569B70);
    n = cCoreSave_getGodItemNum(&D_00569B70);
    for (i = 0; i < HUD_GOD_ITEM_NUM; i++) {
        if (i < n)
            self->godItem[i]->flags &= ~IDENT_FLAG_NO_DRAW;
        else
            self->godItem[i]->flags |= IDENT_FLAG_NO_DRAW;
    }
    self->heat = cHeatSys_GetHeatRatio(&D_005CB000);
    self->heatShown = cHeatSys_GetHeatRatio(&D_005CB000);
    self->heatMark[0]->flags |= IDENT_FLAG_NO_DRAW;
    self->heatMark[1]->flags |= IDENT_FLAG_NO_DRAW;
    self->heatMark[2]->flags |= IDENT_FLAG_NO_DRAW;
    self->heatMark[3]->flags |= IDENT_FLAG_NO_DRAW;
    self->heatMark[4]->flags |= IDENT_FLAG_NO_DRAW;
    self->heatMark[5]->flags |= IDENT_FLAG_NO_DRAW;
    self->ent[17]->flags |= IDENT_FLAG_NO_DRAW;
    self->ent[6]->flags |= IDENT_FLAG_NO_DRAW;
    {
        cIDBaseObj *b = &self->frame;

        func_002AC9B8(self, self->ent[11], 1);
        self->ent[11]->colorBase.c[3] = 0;
        func_002AC9B8(b, self->frameEnt[0], 1);
        self->frameEnt[0]->colorBase.c[3] = 0;
        func_002AC9B8(b, self->frameEnt[8], 1);
        self->frameEnt[8]->colorBase.c[3] = 0;
        func_002AC9B8(b, self->frameEnt[9], 1);
        self->frameEnt[9]->colorBase.c[3] = 0x80;
    }
    self->unk26F = 0;
}
