/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cCockGameOver.h"

extern void IconScreen_stepGrow(void *this);
extern void func_0013D7B0(void *this);
extern void IconScreen_waitChildDone(void *this);
extern void func_0013DB50(void *this);
extern void CustomIDWork_Main(void *p);

/* func_0013D540 — sn-2.95.3-136, --call-loop-pad.
   The CustomIDWork_Main sweep (for j=4; j>=0; j--) is the padded call-loop
   (bgez close). */











__attribute__((section(".text.func_0013D540")))
void func_0013D540(void *this) {
    char *base = (char *)this;
    cCockGameOver *o = this;
    unsigned short i;
    int j;
    cIDBaseObj *pD0;
    char *p;

    for (i = 0; i < COCKGAMEOVER_ENT_NUM; i++) {
        o->ent[i] = cIDBase_getIDWork(&o->base, i);
    }

    switch (*(unsigned short *)(base + 0x92)) {
    case 0:
        IconScreen_stepGrow(this);
        break;
    case 1:
        func_0013D7B0(this);
        break;
    case 2:
        IconScreen_waitChildDone(this);
        break;
    }

    if ((D_00569B70.data->flags & 0x04000000) != 0) {
        *(int *)(*(char **)(base + 0x98) + 0x2C) |= 0x08000000;
        *(int *)(*(char **)(base + 0xA4) + 0x2C) |= 0x08000000;
        *(int *)(*(char **)(base + 0x94) + 0x2C) |= 0x08000000;
        func_0013DB50(this);
    }

    pD0 = &o->base2;
    p = base + 0x120;
    for (j = 4; j >= 0; j--) {
        CustomIDWork_Main(p);
        p += 0x7C;
    }
    cIDBase_move(pD0);
    cIDBase_move(this);
}
