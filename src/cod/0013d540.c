/* sn-2.95.3-136 matched TU. */

extern int cIDBase_getIDWork(void *this, int idx);
extern void func_0013D698(void *this);
extern void func_0013D7B0(void *this);
extern void func_0013DA98(void *this);
extern void func_0013DB50(void *this);
extern void CustomIDWork_Main(void *p);
extern void cIDBase_move(void *p);
extern char *D_00569B70;

/* func_0013D540 — sn-2.95.3-136, --call-loop-pad.
   The CustomIDWork_Main sweep (for j=4; j>=0; j--) is the padded call-loop
   (bgez close). */










struct Obj { char _pad[0x94]; int ids[11]; };

__attribute__((section(".text.func_0013D540")))
void func_0013D540(void *this) {
    char *base = (char *)this;
    struct Obj *o = (struct Obj *)this;
    unsigned short i;
    int j;
    char *pD0;
    char *p;

    for (i = 0; i < 11; i++) {
        o->ids[i] = cIDBase_getIDWork(this, i);
    }

    switch (*(unsigned short *)(base + 0x92)) {
    case 0:
        func_0013D698(this);
        break;
    case 1:
        func_0013D7B0(this);
        break;
    case 2:
        func_0013DA98(this);
        break;
    }

    if ((*(int *)(D_00569B70 + 0x14) & 0x04000000) != 0) {
        *(int *)(*(char **)(base + 0x98) + 0x2C) |= 0x08000000;
        *(int *)(*(char **)(base + 0xA4) + 0x2C) |= 0x08000000;
        *(int *)(*(char **)(base + 0x94) + 0x2C) |= 0x08000000;
        func_0013DB50(this);
    }

    pD0 = base + 0xD0;
    p = base + 0x120;
    for (j = 4; j >= 0; j--) {
        CustomIDWork_Main(p);
        p += 0x7C;
    }
    cIDBase_move(pD0);
    cIDBase_move(this);
}
