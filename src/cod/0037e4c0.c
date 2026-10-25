/* sn-2.95.3-136 matched TU. */

#include "godhand/MenuBrowse.h"

extern void func_0037E670(MenuBrowse *self);

/* Step the browser by one pad frame: pick, move the cursor, turn pages, step the sub index and put the page top under the cursor. */
__attribute__((section(".text.func_0037E4C0")))
void func_0037E4C0(MenuBrowse *self, MenuPad *pad)
{
    int bit;
    MenuBrowseList *list = self->list;
    MenuBrowse *me;
    unsigned int last;
    unsigned int n = (list->end - list->begin) >> 3;

    /* Retail keeps the count, the object and the page bit in second registers: the copies are separate variables here. */
    bit = MENUBROWSE_TRG_PAGE_UP;
    last = n;
    me = self;
    if (pad->press & MENUPAD_DECIDE) {
        func_0037E670(me);
        return;
    }
    if (pad->trg & MENUPAD_TRG_UP) {
        if (self->cursor == 0) {
            me->cursor = last - 1;
        } else {
            me->cursor = self->cursor - 1;
        }
    }
    if (pad->trg & MENUPAD_TRG_DOWN) {
        if (me->cursor < last - 1) {
            self->cursor = self->cursor + 1;
        } else {
            me->cursor = 0;
        }
    }
    if (n > MENUBROWSE_PAGE) {
        if (pad->trg & bit) {
            if (me->top >= MENUBROWSE_PAGE) {
                me->top = me->top - MENUBROWSE_PAGE;
            } else {
                self->top = (last - 1) / MENUBROWSE_PAGE * MENUBROWSE_PAGE;
            }
            self->cursor = me->top;
        }
        if (pad->trg & (bit = MENUBROWSE_TRG_PAGE_DOWN)) {
            if (self->top < last / MENUBROWSE_PAGE * MENUBROWSE_PAGE) {
                self->top = self->top + MENUBROWSE_PAGE;
            } else {
                self->top = 0;
            }
            self->cursor = self->top;
        }
    }
    if (pad->trg & MENUBROWSE_TRG_SUB_UP) {
        if (me->sub == 0) {
            me->sub = MENUBROWSE_SUB_MAX;
        } else {
            me->sub = me->sub - 1;
        }
    }
    if (pad->trg & MENUBROWSE_TRG_SUB_DOWN) {
        if (self->sub < MENUBROWSE_SUB_MAX) {
            self->sub = self->sub + 1;
        } else {
            me->sub = 0;
        }
    }
    me->top = self->cursor / MENUBROWSE_PAGE * MENUBROWSE_PAGE;
}
