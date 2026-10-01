/* sn-2.95.3-136 matched TU. */

#include "godhand/cIDBase.h"

extern float Adjust_theta(float f12);
extern float capVu0Sin(float f12);
extern float capVu0Cos(float f12);
extern int D_005E7510;
extern int D_00747A0C;
extern void func_002AB9A8(cIDBaseObj *self, int a1);
extern void func_002AF710(void *env, int a1, int a2);
extern void func_002AF720(void *env, float a1);
extern void func_002AF698(void *env, float a1, float a2);
extern void func_002AF668(void *env, float a1, float a2);
extern void cMessDrawFont_setDrawPos(void *env, int align, float x, float y);
extern void func_002AF590(void *env, int id);
extern void func_002ACC28(void *env, int a1, int a2);
extern void cMessDrawFont_setDrawCounter(void *env, int a1, int a2);
extern void cMessDrawFont_draw(void *env, int a1, int a2);

/* Per-frame layout pass: work out every entry's final position, scale,
 * rotation and colour from its own values and its chain of parents. */
__attribute__((section(".text.func_002AA6E0")))
void func_002AA6E0(cIDBaseObj *self)
{
    int i;
    for (i = 0; i < self->entNum; i++) {
        cIDBaseEnt *ent = &self->ent[i];
        float sx, sy;
        if (ent == 0) continue;
        ent->drawRot = 0.0f;
        ent->drawSclX = ent->sclX;
        ent->drawSclY = ent->sclY;
        sx = ent->sclX;
        sy = ent->sclY;
        if (ent->parentRef >= 0) {
            cIDBaseEnt *p = ent->parent;
            if (p != 0) {
                float rot0 = ent->drawRot;
                unsigned long lowbyte;
                do {
                    if (ent->flags & IDENT_FLAG_SCL_PAR) {
                        ent->drawSclX = ent->drawSclX * p->sclX;
                        ent->drawSclY = ent->drawSclY * p->sclY;
                    }
                    sx = sx * p->sclX;
                    sy = sy * p->sclY;
                    lowbyte = (unsigned char)ent->flags;
                    if ((lowbyte >> 7) == 0) {
                        if (p->rotSpeed != rot0) {
                            ent->drawRot = Adjust_theta(ent->drawRot + p->rotSpeed);
                        }
                    }
                    p = p->parent;
                } while (p != 0);
            }
        }
        if (ent->drawRot != 0.0f) {
            float s = capVu0Sin(ent->drawRot);
            float c = capVu0Cos(ent->drawRot);
            ent->rotX = c * ent->posX - s * ent->posY;
            ent->rotY = s * ent->posX + c * ent->posY;
        } else {
            ent->rotX = ent->posX;
            ent->rotY = ent->posY;
        }
        if (ent->flags & IDENT_FLAG_OFF_PAR) {
            ent->rotX = ent->rotX * sx;
            ent->rotY = ent->rotY * sy;
        }
        ent->drawRot = Adjust_theta(ent->drawRot + ent->rotSpeed);
        ent->drawX = ent->rotX;
        ent->drawY = ent->rotY;
        ent->color.word = ent->colorBase.word;
        {
            float offY, offX;
            offX = ent->offX;
            offY = ent->offY;
            if (ent->parentRef >= 0) {
                cIDBaseEnt *p = ent->parent;
                if (p != 0) {
                    do {
                        unsigned long fl, bit;
                        fl = p->flags;
                        bit = (fl >> 4) & 1;
                        if (bit != 0) {
                            ent->kind = p->kind;
                        }
                        ent->drawX = ent->drawX + p->rotX;
                        ent->drawY = ent->drawY + p->rotY;
                        offX = offX + p->offX;
                        offY = offY + p->offY;
                        if (!(p->flags & IDENT_FLAG_NO_TINT)) {
                            if (!(ent->flags & IDENT_FLAG_NO_TINT)) {
                                ent->color.c[0] = (int)((float)(ent->color.c[0] * p->colorBase.c[0]) * 0.0078125f);
                                ent->color.c[1] = (int)((float)(ent->color.c[1] * p->colorBase.c[1]) * 0.0078125f);
                                ent->color.c[2] = (int)((float)(ent->color.c[2] * p->colorBase.c[2]) * 0.0078125f);
                                ent->color.c[3] = (int)((float)(ent->color.c[3] * p->colorBase.c[3]) * 0.0078125f);
                            }
                        }
                        p = p->parent;
                    } while (p != 0);
                }
            }
            ent->drawX = ent->drawX + offX;
            ent->drawY = ent->drawY + offY;
        }
    }
}

/* Draw a text entry: pick the alignment from b89, set up the shared message
 * environment (font, scale, position, message id) and draw it. */
__attribute__((section(".text.func_002AB0B8")))
void func_002AB0B8(cIDBaseObj *self, cIDBaseEnt *ent)
{
    int align = 1;
    int id;
    int kind;
    unsigned long fl, bit;
    func_002AB9A8(self, ent->b8B);
    kind = ent->b89;
    if (kind != 0) {
        if (kind >= 0) {
            if (!(kind > 4)) align = 0;
        }
    } else {
        align = 3;
    }
    if (self->mode == 6) {
        func_002AF710(&D_005E7510, ent->b8D, 5);
    } else {
        func_002AF710(&D_005E7510, self->mode, 5);
    }
    func_002AF720(&D_005E7510, (float)ent->h8E);
    func_002AF698(&D_005E7510, ent->drawSclX, ent->drawSclY);
    if (D_00747A0C == 0) {
        func_002AF668(&D_005E7510, 2.0f, -ent->drawSclY * 26.0f + 8.0f);
    } else {
        func_002AF668(&D_005E7510, 2.0f, -ent->drawSclY * 26.0f + 8.0f);
    }
    cMessDrawFont_setDrawPos(&D_005E7510, align, ent->drawX, ent->drawY);
    id = 0x3000;
    if (ent->msg != 0) id = ent->msg;
    func_002AF590(&D_005E7510, id);
    fl = ent->flags;
    bit = (fl >> 2) & 1;
    if (bit != 0) {
        func_002ACC28(&D_005E7510, 4, 1);
    } else {
        func_002ACC28(&D_005E7510, 4, 0);
    }
    if (ent->msg == 0) {
        if (ent->b8C != 0) {
            cMessDrawFont_setDrawCounter(&D_005E7510, 0, (ent->b8C - 1) * 30);
        }
    }
    cMessDrawFont_draw(&D_005E7510, 0, 0);
}
