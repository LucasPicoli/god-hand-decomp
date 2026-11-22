/* sn-2.95.3-136: func_00140718, rebuilds the item draw order with the selected item first (bright) and
 * the others dimmed, nearest-left items before the right ones. */
#include "godhand/cIDBase.h"

/* One menu item: a cIDBase display padded to 0x50 bytes. */
typedef struct IDMenuItem {
    cIDBaseObj base;
    char unk48[0x50 - 0x48];
} IDMenuItem;

typedef struct IDItemMenu {
    char pad0[0xC0];
    IDMenuItem item[8];                 /* 0x0C0 */
    char pad340[0x18];
    unsigned char count;                /* 0x358 */
    char pad359[3];
    IDMenuItem *order[10];              /* 0x35C */
    signed char wait;                   /* 0x384 */
} IDItemMenu;


__attribute__((section(".text.func_00140718")))
void func_00140718(IDItemMenu *m, int sel, int force)
{
    int i;
    int n;

    if (m->wait != 0 && force == 0)
        return;
    m->wait += 10;
    n = 1;
    m->order[0] = &m->item[sel];
    cIDBase_getIDWork(&m->item[sel].base, 0)->colorBase.c[3] = 0x80;
    for (i = sel - 1; i >= 0; i--) {
        m->order[n++] = &m->item[i];
        cIDBase_getIDWork(&m->item[i].base, 0)->colorBase.c[3] = 0x20;
    }
    for (i = sel + 1; i < m->count; i++) {
        m->order[n++] = &m->item[i];
        cIDBase_getIDWork(&m->item[i].base, 0)->colorBase.c[3] = 0x20;
    }
}
