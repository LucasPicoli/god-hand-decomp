/* sn-2.95.3-136: func_0037A020, moves the current column's selection up/down on pad bits 0x20000000/0x10000000; returns 1 if it changed. */
typedef struct {
    short v[3];
} SelCols;

typedef struct {
    char unk0[7];
    signed char col;
    char unk8[0xE];
    SelCols sel;
    short timer[3];
    char unk22[0x12];
    unsigned int pad;
} SelObj;

extern short SdeTblTestBlkNoCheck(SelObj *o, short idx, int dir);

__attribute__((section(".text.func_0037A020")))
int func_0037A020(SelObj *o)
{
    SelCols *sel = &o->sel;
    short old = sel->v[o->col];
    short v = old;

    if (o->pad & 0x20000000)
        v = SdeTblTestBlkNoCheck(o, old - 1, -1);
    if (o->pad & 0x10000000)
        v = SdeTblTestBlkNoCheck(o, old + 1, 1);
    if (v != old) {
        sel->v[o->col] = v;
        o->timer[o->col] = 0;
        return 1;
    }
    return 0;
}
