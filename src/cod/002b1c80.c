/* sn-2.95.3-136: func_002B1C80, draw a message panel's text: skip the ruby records already past the
 * shown text, set the font up by the panel kind and draw it (twice, with the outline, unless kind 2). */
#include "godhand/cMessDrawFont.h"
#include "godhand/messPanel.h"

extern cMessDrawFont D_005E7510;
extern int D_00747A0C;
extern void cMessDrawFont_setEnvInit(void *f);
extern void cMessDrawFont_setBodyData(void *f, void *body, void *end, int a3);
extern void cMessDrawFont_setRubyData(void *f, void *top, void *cur);
extern void cMessDrawFont_setDrawCounter(int *f, int a, int b);
extern void func_002ACC28(int *f, int a, int b);
extern void cMessDrawFont_setDrawPos(void *f, int mode, float x, float y);
extern void func_002AF698(void *f, float x, float y);
extern void func_002AF668(void *f, float x, float y);
extern void func_002AF6A8(int *f, int a, int b);
extern void func_002AF6B8(char *f, int a);
extern void func_002AF6E0(char *f, int a);
extern void func_002AF708(void *f, int a);
extern void cMessDrawFont_draw(void *f, int a, int b);

__attribute__((section(".text.func_002B1C80")))
void func_002B1C80(Panel *m)
{
    unsigned short *r;
    long t;

    t = m->flags;
    if (!(((unsigned long)t >> 4) & 1))         /* PANEL_F_TEXT */
        return;
    m->ruby = m->rubyTop;
    while ((r = m->ruby) != 0) {
        if (r[0] == 0xFFFF)
            m->ruby = 0;
        else if (m->body + r[0] < m->bodyEnd)
            m->ruby = r + (r[2] + 3);
        else
            break;
    }
    cMessDrawFont_setEnvInit(&D_005E7510);
    cMessDrawFont_setBodyData(&D_005E7510, m->body, m->bodyEnd, m->unk8C);
    cMessDrawFont_setRubyData(&D_005E7510, m->rubyTop, m->ruby);
    cMessDrawFont_setDrawCounter(&D_005E7510, m->unk84, m->unk68);
    func_002ACC28(&D_005E7510, 4, 0);
    if (m->kind == 2) {
        cMessDrawFont_setDrawPos(&D_005E7510, 0, (float)(short)m->curX, (float)(short)m->curY);
        func_002AF698(&D_005E7510, m->scaleA, m->scaleB);
        func_002AF668(&D_005E7510, (float)m->ofsX, (float)m->ofsY);
        func_002AF6A8(&D_005E7510, m->align, 0);
    } else if (m->kind == 3) {
        cMessDrawFont_setDrawPos(&D_005E7510, 0, (float)(short)m->curX, (float)(short)m->curY);
        func_002AF698(&D_005E7510, m->scaleA, m->scaleB);
        func_002AF668(&D_005E7510, (float)m->ofsX, (float)m->ofsY);
        func_002AF6A8(&D_005E7510, 4, 0);
    } else {
        cMessDrawFont_setDrawPos(&D_005E7510, 3, (float)(short)m->curX, (float)(short)m->curY);
        func_002AF6A8(&D_005E7510, 4, 0);
        if (D_00747A0C == 0)
            func_002AF698(&D_005E7510, 0.9f, 1.0f);
        else
            func_002AF698(&D_005E7510, 0.9f, 1.1f);
    }
    func_002AF6B8(&D_005E7510, 1);
    func_002AF6E0(&D_005E7510, 0);
    t = m->flags;
    if ((((unsigned long)t >> 5) & 1UL) == 1UL)  /* PANEL_F_COLOUR */
        func_002AF708(&D_005E7510, m->unk94);
    cMessDrawFont_draw(&D_005E7510, 0, 0);
    if (m->kind != 2) {
        func_002AF6E0(&D_005E7510, 1);
        cMessDrawFont_draw(&D_005E7510, 0, 0);
        func_002AF6E0(&D_005E7510, 0);
    }
}
