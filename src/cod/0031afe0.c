/* sn-2.95.3-136 matched TU. */

#include "godhand/PadRec.h"

extern int D_00747A0C;
extern unsigned int D_00747A34;
extern int D_00747A78;
extern unsigned int D_003C3D50[64];
extern unsigned int D_003C3E50[64];
extern void func_0031B410(void *ctx, void *out);
extern void func_0031B4B8(void *ctx, void *out);
extern void func_0031B2E0(void *ctx, void *out);
extern void func_002E0DE8(int, int, int, const char *, ...);
extern void func_00379838(char *);
extern void func_00379910(char *);
extern char D_0045B350[];
extern char D_0045B360[];
extern char D_0045B5C0[];
extern char D_0045B5D8[];
extern char D_0045B5F0[];
extern char D_0045B4C0[];
extern char D_0045B608[];
extern char D_0045B620[];
extern char D_0045B460[];
extern char D_0045B478[];
extern char D_0045B638[];
extern char D_0045B650[];
extern char D_0045B3E8[];
extern char D_0045B400[];
extern char D_0045B668[];
extern char D_0045B680[];
extern char D_0045B550[];
extern char D_0045B698[];
extern char D_0045B6B0[];
extern char D_0045B560[];
extern char D_0045B578[];
extern char D_0045B590[];
extern char D_0045B5A8[];
extern int D_003F2610[];

/* sn-2.95.3-136: turns one raw controller sample into the game's pad record (0x31AFE0). Keeps the previous bits, maps the three 64-button words through a mask table into bit sets, sets the stick direction bits, derives the pressed and released edges, then either hands the record to the replay or hold hook, or copies the analog bytes across and scores the stick turn. Raw offsets from PadRec.h: a typed member access lets the scheduler move loads across the plain int globals, which retail does not. */











#define PAD_SYS_REPLAY  0x2000000       /* D_00747A78 bits */
#define PAD_SYS_SKIP_BIT 5              /* with REPLAY: the replay hook is skipped */
#define PAD_SYS_HOLD_BIT 4              /* the hold hook runs */
#define PAD_SYS_MASKALT 0x800           /* D_00747A34: use the second mask table */

/* Analog byte i of the sample and of the record (the record's block starts at 0x68, the sample's at 0x60). */
#define PAD_A_IN(i)   (*((unsigned char *)in + PADSAMPLE_OFFSET(analog) + (i)))
#define PAD_A_OUT(i)  (*((unsigned char *)out + PADREC_OFFSET(analog) + (i)))

__attribute__((section(".text.PadRec_update")))
void PadRec_update(void *ctx, char *out, char *in)
{
    unsigned int *tbl;
    unsigned int i;
    unsigned long bit;
    unsigned long cur, old, edge;
    unsigned int wcur, wold;
    unsigned long oldHeld;
    unsigned int oldDir;
    unsigned long sa, sb;
    long tl;

    *(unsigned long *)(out + PADREC_OFFSET(setB)) = 0;
    oldHeld = *(unsigned long *)(out + PADREC_OFFSET(held));
    oldDir = *(unsigned int *)(out + PADREC_OFFSET(dir));
    *(unsigned long *)(out + PADREC_OFFSET(heldOld)) = oldHeld;
    *(unsigned int *)(out + PADREC_OFFSET(dirOld)) = oldDir;
    *(unsigned long *)(out + PADREC_OFFSET(held)) = 0;
    *(unsigned long *)(out + PADREC_OFFSET(setC)) = 0;
    *(unsigned int *)(out + PADREC_OFFSET(dir)) = 0;
    bit = 1;
    if (D_00747A0C == 0) {
        tbl = D_003C3D50;
    } else {
        tbl = D_003C3E50;
    }
    if (D_00747A34 & PAD_SYS_MASKALT) {
        tbl = D_003C3E50;
    }
    for (i = 0; i < 0x40; i++) {
        if (*(unsigned int *)(in + PADSAMPLE_OFFSET(held)) & *tbl) {
            *(unsigned long *)(out + PADREC_OFFSET(held)) |= bit;
        }
        if (*(unsigned int *)(in + PADSAMPLE_OFFSET(heldB)) & *tbl) {
            *(unsigned long *)(out + PADREC_OFFSET(setB)) |= bit;
        }
        if (*(unsigned int *)(in + PADSAMPLE_OFFSET(heldC)) & *tbl) {
            *(unsigned long *)(out + PADREC_OFFSET(setC)) |= bit;
        }
        tbl++;
        bit <<= 1;
    }
    if (*(signed char *)(in + 0x70) > 0) *(unsigned int *)(out + PADREC_OFFSET(dir)) |= 0x80;
    if (*(signed char *)(in + 0x70) < 0) *(unsigned int *)(out + PADREC_OFFSET(dir)) |= 0x40;
    if (*(signed char *)(in + 0x71) > 0) *(unsigned int *)(out + PADREC_OFFSET(dir)) |= 0x10;
    if (*(signed char *)(in + 0x71) < 0) *(unsigned int *)(out + PADREC_OFFSET(dir)) |= 0x20;
    if (*(signed char *)(in + 0x72) > 0) *(unsigned int *)(out + PADREC_OFFSET(dir)) |= 0x8;
    if (*(signed char *)(in + 0x72) < 0) *(unsigned int *)(out + PADREC_OFFSET(dir)) |= 0x4;
    if (*(signed char *)(in + 0x73) > 0) *(unsigned int *)(out + PADREC_OFFSET(dir)) |= 0x1;
    if (*(signed char *)(in + 0x73) < 0) *(unsigned int *)(out + PADREC_OFFSET(dir)) |= 0x2;
    cur = *(unsigned long *)(out + PADREC_OFFSET(held));
    old = *(unsigned long *)(out + PADREC_OFFSET(heldOld));
    wcur = *(unsigned int *)(out + PADREC_OFFSET(dir));
    wold = *(unsigned int *)(out + PADREC_OFFSET(dirOld));
    edge = cur ^ old;
    *(unsigned long *)(out + PADREC_OFFSET(pressed)) = edge & cur;
    *(unsigned long *)(out + PADREC_OFFSET(released)) = edge & old;
    *(unsigned int *)(out + PADREC_OFFSET(dirNew)) = (wcur ^ wold) & wcur;
    sa = D_00747A78;
    if (sa & PAD_SYS_REPLAY) {
        sb = sa >> PAD_SYS_SKIP_BIT;
        if (!(sb & 1)) {
            func_0031B410(ctx, out);
            return;
        }
    }
    sa = D_00747A78;
    sb = sa >> PAD_SYS_HOLD_BIT;
    tl = sb & 1;
    if (tl != 0) {
        func_0031B4B8(ctx, out);
        return;
    }
    *(unsigned long *)(out + PADREC_OFFSET(state)) = *(unsigned long *)(out + PADREC_OFFSET(held));
    PAD_A_OUT(0x00) = PAD_A_IN(0x00);
    PAD_A_OUT(0x01) = PAD_A_IN(0x01);
    PAD_A_OUT(0x02) = PAD_A_IN(0x02);
    PAD_A_OUT(0x03) = PAD_A_IN(0x03);
    PAD_A_OUT(0x07) = PAD_A_IN(0x07);
    PAD_A_OUT(0x06) = PAD_A_IN(0x06);
    PAD_A_OUT(0x04) = PAD_A_IN(0x04);
    PAD_A_OUT(0x05) = PAD_A_IN(0x05);
    PAD_A_OUT(0x08) = PAD_A_IN(0x08);
    PAD_A_OUT(0x0B) = PAD_A_IN(0x0B);
    PAD_A_OUT(0x09) = PAD_A_IN(0x09);
    PAD_A_OUT(0x0A) = PAD_A_IN(0x0A);
    PAD_A_OUT(0x0C) = PAD_A_IN(0x0C);
    PAD_A_OUT(0x0D) = PAD_A_IN(0x0D);
    PAD_A_OUT(0x0E) = PAD_A_IN(0x0E);
    PAD_A_OUT(0x0F) = PAD_A_IN(0x0F);
    PAD_A_OUT(0x10) = PAD_A_IN(0x10);
    PAD_A_OUT(0x11) = PAD_A_IN(0x11);
    PAD_A_OUT(0x12) = PAD_A_IN(0x12);
    PAD_A_OUT(0x13) = PAD_A_IN(0x13);
    *(float *)(out + PADREC_OFFSET(stickX)) = *(float *)(in + PADSAMPLE_OFFSET(stickX));
    *(float *)(out + PADREC_OFFSET(stickY)) = *(float *)(in + PADSAMPLE_OFFSET(stickY));
    func_0031B2E0(ctx, out);
}

/* sn-2.95.3-136: debug screen page for the record at self + 0xCC (0x379190). Prints its values in rows of group 0x1B; a record flagged 0x8000 prints three placeholder rows instead. Clone of func_003794D0 for the other record kind. */




























#define DBG_GROUP   0x1B

__attribute__((section(".text.DebugPage_printRecordRows")))
void DebugPage_printRecordRows(char *self)
{
    char *p = self + 0xCC;
    int x = DBG_GROUP;

    if (*(unsigned short *)(p + 0xE) & 0x8000) {
        func_002E0DE8(DBG_GROUP, 3, 0xD, D_0045B350);
        func_002E0DE8(DBG_GROUP, 4, 0xD, D_0045B360);
        func_002E0DE8(DBG_GROUP, 5, 0xD, D_0045B350);
        return;
    }
    func_002E0DE8(DBG_GROUP, 3, 8, D_0045B5C0, *(short *)(p + 4));
    if (*(unsigned char *)(p + 6) & 1) {
        func_002E0DE8(DBG_GROUP, 4, 8, D_0045B5D8);
    } else {
        func_002E0DE8(DBG_GROUP, 4, 8, D_0045B5F0);
    }
    func_002E0DE8((short)x, 5, 8, D_0045B4C0, *(signed char *)(p + 7));
    if (*(unsigned short *)(p + 0xC) & 2) {
        func_002E0DE8((short)x, 6, 8, D_0045B608);
    } else {
        func_002E0DE8((short)x, 6, 8, D_0045B620);
    }
    if (*(unsigned short *)(p + 0xC) & 1) {
        func_002E0DE8((unsigned int)(x << 16) >> 16, 7, 8, D_0045B460);
    } else {
        func_002E0DE8((unsigned int)(x << 16) >> 16, 7, 8, D_0045B478);
    }
    func_002E0DE8((short)x, 8, 8, D_0045B638, *(int *)(p + 0x40));
    func_002E0DE8((short)x, 9, 8, D_0045B650, *(int *)(p + 0x44));
    func_002E0DE8((short)x, 0xB, 8, D_0045B3E8, *(short *)(p + 0x34));
    func_002E0DE8((short)x, 0xC, 8, D_0045B400, *(short *)(p + 0x36));
    func_002E0DE8((short)x, 0xD, 8, D_0045B668, *(short *)(p + 0x38));
    func_002E0DE8((short)x, 0xE, 8, D_0045B680, *(short *)(p + 0x3A));
    func_002E0DE8((short)x, 0x10, 8, D_0045B550, D_003F2610[*(signed char *)(p + 8)]);
    func_002E0DE8((short)x, 0x11, 8, D_0045B698, *(short *)(p + 0x3C));
    func_002E0DE8((short)x, 0x12, 8, D_0045B6B0, *(short *)(p + 0x3E));
    func_002E0DE8((short)x, 0x14, 8, D_0045B560, *(signed char *)(p + 0x58));
    func_002E0DE8((short)x, 0x15, 8, D_0045B578, *(signed char *)(p + 0x59));
    func_002E0DE8((short)x, 0x16, 8, D_0045B590, *(signed char *)(p + 0x5A));
    func_002E0DE8((short)x, 0x17, 8, D_0045B5A8, *(signed char *)(p + 0x5B));
    func_00379838(self);
    func_00379910(self);
}
