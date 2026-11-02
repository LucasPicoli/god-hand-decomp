/* sn-2.95.3-136 */
#include "godhand/cIDBaseScreen.h"

/* Opening phase: grow the four row labels in, fill the five rows from the list, then scale the rows up. */
__attribute__((section(".text.func_00145460")))
void func_00145460(cIDBaseScreen *self)
{
    unsigned short i;
    unsigned short n;
    float s;

    n = self->cur;
    switch (self->step) {
    case 0:
        for (i = 0; i < 4; i++) {
            s = D_0041E880[i];
            self->tbl[i][0]->sclX += s / 3.0f;
            self->tbl[i][0]->sclY += s / 3.0f;
            if (self->tbl[i][0]->sclX > s - 0.001f) {
                self->tbl[i][0]->sclX = s;
                self->tbl[i][0]->sclY = s;
                if (self->step == 0)
                    self->step++;
            }
        }
        break;
    case 1:
        self->step++;
        self->scale = 1.0f;
        for (i = 0; i < SCR_ROW_NUM; i++) {
            self->tbl[i][1]->flags &= ~IDENT_FLAG_NO_DRAW;
            self->tbl[i][1]->tex = self->tex[n];
            if (self->attr[n] & SCR_ATTR_DIM)
                self->tbl[i][1]->colorBase.word = (self->tbl[i][1]->colorBase.word & 0xFF000000) | 0x303030;
            else
                self->tbl[i][1]->colorBase.word = (self->tbl[i][1]->colorBase.word & 0xFF000000) | 0x808080;
            self->tbl[i][1]->f70[0] = D_0041E840[0][0];
            self->tbl[i][1]->f70[1] = D_0041E840[0][1];
            self->tbl[i][1]->f70[2] = D_0041E840[0][2];
            self->tbl[i][1]->f70[3] = D_0041E840[0][3];
            self->tbl[i][0]->sclX = D_0041E880[i];
            self->tbl[i][0]->sclY = D_0041E880[i];
            n++;
            if (n >= self->listNum)
                n = 0;
        }
        for (i = 0; i < SCR_ROW_NUM; i++)
            cIDBase_move(&self->row[i].id);
        break;
    case 2:
        self->scale *= 0.3f;
        for (i = 0; i < SCR_ROW_NUM; i++) {
            self->tbl[i][1]->sclY = 1.0f - self->scale;
            self->tbl[i][1]->sclX = 1.0f - self->scale;
        }
        if (self->scale < 0.01f)
            self->step++;
        break;
    case 3:
        for (i = 0; i < SCR_ROW_NUM; i++) {
            self->tbl[i][1]->sclY = 1.0f;
            self->tbl[i][1]->sclX = 1.0f;
            self->tbl[i][0]->sclX = D_0041E880[i];
            self->tbl[i][0]->sclY = D_0041E880[i];
        }
        self->phase++;
        break;
    }
}
