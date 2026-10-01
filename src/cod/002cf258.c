/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"
#define CSND_ATTR(s)     (*(int *)((char *)(s) + 0x50))
#define CSND_DEF_ATTR(s) (*(int *)((char *)(s) + 0x58))

extern int Obj0000_Get_D_0076A7A4_3756F0(int);
extern int cDvd_Check();
extern char D_00583F20[];

__attribute__((section(".text.func_002CF258")))
short func_002CF258(int a0, short *obj)
{
    if (Obj0000_Get_D_0076A7A4_3756F0(a0) == 2)
        return obj[0x9];   /* 0x12 */
    return obj[0x8];       /* 0x10 */
}

__attribute__((section(".text.func_002CF298")))
short func_002CF298(short *obj)
{
    if (Obj0000_Get_D_0076A7A4_3756F0((int)obj) == 2)
        return obj[0x17];   /* 0x2E */
    return obj[0x16];       /* 0x2C */
}

/* Is the sound-effect slot free? */
__attribute__((section(".text.func_002CFC78")))
int func_002CFC78(cSeData *d) { return d->state == CSEDATA_STATE_FREE; }

/* Is the sound-effect slot loaded and usable? */
__attribute__((section(".text.cSeData_IsAlive")))
int cSeData_IsAlive(cSeData *d) { return d->state == CSEDATA_STATE_ALIVE; }

/* Did loading the sound-effect slot fail? */
__attribute__((section(".text.func_002CFC88")))
int func_002CFC88(cSeData *d) { return d->state == CSEDATA_STATE_FAILED; }

/* Is the bgm data record empty? */
__attribute__((section(".text.func_002CFF78")))
int func_002CFF78(cBgmData *d) { return d->state == 0; }

/* Is the bgm data record fully loaded? */
__attribute__((section(".text.func_002CFF68")))
int func_002CFF68(cBgmData *d) { return d->state == CBGMDATA_STATE_READY; }

/* Mark a used sound-effect slot as failed. */
__attribute__((section(".text.func_002CFC98")))
void func_002CFC98(cSeData *d) { if (d->state != CSEDATA_STATE_FREE) d->state = CSEDATA_STATE_FAILED; }

/* Are all the load bits in mask set? */
__attribute__((section(".text.func_002CFD38")))
int func_002CFD38(cSeData *d, unsigned int mask) { return (~d->flags & mask) == 0; }

/* Is the bank free in the sound driver? */
__attribute__((section(".text.func_002CF868")))
int func_002CF868(cSeData *d) { return func_00375128(d->bankIdS) == 0; }

__attribute__((section(".text.func_002CFE28")))
int func_002CFE28(cSeData *d) { return func_002CD7C8((int)d->head); }

__attribute__((section(".text.func_002CFE48")))
int func_002CFE48(int *a0) { return func_002CD890(a0[3]); }

/* Set load bits on a bgm data record; returns the new bits. */
__attribute__((section(".text.func_002D0350")))
int func_002D0350(cBgmData *d, int bits) { return d->state |= bits; }

/* Are all the load bits in mask set on a bgm data record? */
__attribute__((section(".text.func_002D03D0")))
int func_002D03D0(cBgmData *d, int mask) { return (~d->state & mask) == 0; }

/* Set attribute bits; returns the new word. */
__attribute__((section(".text.func_002D0748")))
int func_002D0748(cSnd *self, int bits) { return CSND_ATTR(self) |= bits; }

/* Clear attribute bits; returns the new word. */
__attribute__((section(".text.func_002D0758")))
int func_002D0758(cSnd *self, int bits) { return CSND_ATTR(self) &= ~bits; }

__attribute__((section(".text.func_002D0578")))
int func_002D0578(int *a0, int a1) {
    int *p = (int *)a0[0xC];
    if (!p) return 0;
    return p[4] + (a1 << 3);
}

__attribute__((section(".text.func_002D0598")))
int func_002D0598(int *a0, int a1) {
    int *p = (int *)a0[0xC];
    if (!p) return 0;
    return p[5] + (a1 << 4);
}

__attribute__((section(".text.func_002D05B8")))
int func_002D05B8(int *a0, int a1) {
    int *p = (int *)a0[0xC];
    if (!p) return 0;
    return p[7] + (a1 << 1);
}

/* Set the playback attribute word and apply it. */
__attribute__((section(".text.func_002D0728")))
int func_002D0728(cSnd *self, int attr) { CSND_ATTR(self) = attr; return func_002D0820(self); }

/* The table header of a loaded bgm data record, or 0. */
__attribute__((section(".text.cBgmData_GetHeadPtr")))
cBgmHead *cBgmData_GetHeadPtr(cBgmData *d) {
    if (!func_002CFF68(d)) return 0;
    return d->head;
}

/* Is the sound-effect slot's disc request finished (or absent)? */
__attribute__((section(".text.func_002CF830")))
int func_002CF830(cSeData *d) {
    int req = d->f38;
    if (req == 0) return 1;
    return cDvd_Check(D_00583F20, req) == 0;
}

/* Is the bgm data's disc request finished (or absent)? */
__attribute__((section(".text.func_002D0318")))
int func_002D0318(cBgmData *d) {
    int req = d->f1C;
    if (req == 0) return 1;
    return cDvd_Check(D_00583F20, req) == 0;
}

/* Set the default attribute word and make it current. */
__attribute__((section(".text.cSnd_SetBgmDefAttr")))
int cSnd_SetBgmDefAttr(cSnd *self, int attr) { CSND_DEF_ATTR(self) = attr; return func_002D0728(self, attr); }

/* Add bits to the default attribute word and to the current one. */
__attribute__((section(".text.func_002D07A8")))
int func_002D07A8(cSnd *self, int bits) { CSND_DEF_ATTR(self) |= bits; return func_002D0748(self, bits); }

/* Remove bits from the default attribute word and from the current one. */
__attribute__((section(".text.func_002D07D8")))
int func_002D07D8(cSnd *self, int bits) { CSND_DEF_ATTR(self) &= ~bits; return func_002D0758(self, bits); }

/* Entry n of the bgm table of a loaded record, or 0. */
__attribute__((section(".text.cBgmData_GetTblPtr")))
int cBgmData_GetTblPtr(cBgmData *d, int n) {
    if (!func_002CFF68(d)) return 0;
    return (int)d->tbl + (n << 5);
}

extern int D_00603A40;

/* Add load bits to a sound-effect slot; once the image is complete, mark it alive. */
__attribute__((section(".text.func_002CFCB0")))
void func_002CFCB0(cSeData *d, int bits)
{
    d->flags |= bits;                           /* 0x4 */
    if (func_002CFD38(d, 0x7F) == 1) {
        if (func_002CFD38(d, 0x80) == 0) {
            cSeBuf *p = d->buf;                 /* 0x10 */
            if (p->f20 != (int)p)               /* 0x20 */
                func_002A9648((int)d->pool, p, p->f20 - (int)p, 0x10);
            func_002CFCB0(d, 0x80);
        }
        d->state = CSEDATA_STATE_ALIVE;
    }
}

/* Hand the loaded bank's image to the sound driver and set its parameters. */
__attribute__((section(".text.func_002CFB60")))
void func_002CFB60(cSeData *d)
{
    cSeBuf *p = d->buf;                 /* 0x10 */
    func_00374B70(d->bankIdS, d->f14, d->sysMem, d->f1C, p->f18);
    func_00375988(d->bankIdS, d->f14, d->sysMem, d->f1C);
    func_002CFCB0(d, 0x40);
}

/* Reserve IOP memory for the bank image; 1 when the slot is ready for the next step. */
__attribute__((section(".text.func_002CF888")))
int func_002CF888(cSeData *d)
{
    cSeBuf *p;
    if (d->sysMem != 0)
        return 0;
    p = d->buf;
    if (p->f20 != (int)p)
        d->f30 = func_002D3050(&D_00603A40, p->f20, &d->sysMem, p->f24);
    func_002CFCB0(d, 0x10);
    return 1;
}

/* Load bank bankId through cSeData_LoadFile; on success remember arg in the slot. */
__attribute__((section(".text.func_002CF6F8")))
int func_002CF6F8(cSeData *d, int bankId, int arg)
{
    int buf[16];
    int r;
    func_002CFE68(d, bankId, arg, buf);
    r = cSeData_LoadFile(d, bankId, buf);
    if (r == 1)
        d->f3C = arg;
    return r;
}

/* Rebase the pointers of a loaded bgm table once and point the record at its entries. */
__attribute__((section(".text.func_002D0360")))
void func_002D0360(cBgmData *d)
{
    cBgmHead *h = d->head;
    if (h->relocated == 0) {
        h->tblOfs += (int)h;
        h = d->head;
        if (h->f08 != 0) {
            h->f08 += (int)h;
            h = d->head;
        }
        h->relocated = 1;
    }
    d->tbl = (void *)d->head->tblOfs;
    func_002D0350(d, 2);
}

/* The playback attribute word. */
__attribute__((section(".text.func_002D0770")))
int func_002D0770(cSnd *self) { return CSND_ATTR(self); }
