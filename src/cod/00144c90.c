/* sn-2.95.3-136: func_00144C90, set up the 5 x 5 table of ID works and place each entry on its column and row. */
#include "godhand/cIDBaseScreen.h"

/* row[j].id.playing, spelled as raw bytes: the typed self->row[j].id.playing changes the address arithmetic. */
#define IDWORK_F1C(self, j) (*((unsigned char *)(self) + (j) * 0x50 + 0x11C))

extern cObjSimpleVec3 D_003BD880;
extern void cIDBase_initIDWork(void *w, int id);
extern void cIDBase_restartAnim(void *w);

static inline void vcpy(cObjSimpleVec3 *d, cObjSimpleVec3 *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

__attribute__((section(".text.func_00144C90")))
void func_00144C90(cIDBaseScreen *self)
{
    unsigned short i;
    unsigned short j;
    unsigned short k;
    cIDBaseEnt *e;
    float sc;

    vcpy(&self->pos, &D_003BD880);
    self->pos.x = 155.0f;
    self->pos.y = -59.0f;
    for (i = 0; i < SCR_ROW_NUM; i++) {
        for (j = 0; j < SCR_ROW_NUM; j++) {
            cIDBase_initIDWork(&self->row[j].id, i);
            cIDBase_restartAnim(&self->row[j].id);
            IDWORK_F1C(self, j) = 0;
            self->tbl[j][i] = cIDBase_getIDWork(&self->row[j].id, i);
        }
    }
    for (i = 0; i < 4; i++) {
        if (i == 1) {
            self->tbl[1][0]->colorBase.word = self->tbl[1][0]->src->colorBase;
        } else {
            self->tbl[i][0]->colorBase.word = 0x50808080;
        }
        sc = D_0041E880[i];
        self->tbl[i][1]->tex = self->tex[i];
        self->tbl[i][0]->sclX = 0;
        self->tbl[i][0]->sclY = 0;
        self->tbl[i][0]->posX = self->tbl[i][0]->posX + self->pos.x + (self->tbl[i][0]->f68 * sc - self->tbl[i][0]->f68) * 0.5f;
        self->tbl[i][0]->posY = self->tbl[i][0]->posY + self->pos.y + i * 32;
        self->tbl[i][1]->sclX = 0;
        self->tbl[i][1]->sclY = 0;
        self->rowY[i] = self->tbl[i][0]->posY;
        self->rowX[i] = self->tbl[i][0]->posX;
    }
    self->tbl[4][1]->tex = self->tex[i];  /* i is 4 here; tex[4] does not match */
    self->tbl[4][0]->sclX = 0;
    self->tbl[4][0]->sclY = 0;
    self->tbl[4][1]->sclX = 0;
    self->tbl[4][1]->sclY = 0;
    self->tbl[4][0]->posX = self->tbl[4][0]->posX + self->pos.x - self->tbl[4][0]->f68 * 0.5f;
    self->tbl[4][0]->posY = self->tbl[3][0]->posY;
    e = self->tbl[4][0];
    self->rowX[4] = e->posX;
    self->rowY[4] = e->posY;
    e->flags |= IDENT_FLAG_CHILD;
    self->phase = 1;
    self->step = 0;
    self->unk2A4 = 0;
    self->color0 = 0x80808080;
    self->color1 = 0x80808080;
    for (k = 0; k < 5; k++) {
        cIDBase_move(&self->row[k].id);
    }
}
