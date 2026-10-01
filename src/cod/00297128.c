/* sn-2.95.3-136 matched TU. */

#include "godhand/cEvent.h"

extern char D_0044A960[];
extern char D_00583F20[];
extern int D_003C3CF0;
extern int cDvd_ReadAlloc(void *, void *, void *, void *, int, int, int, int);
extern int D_00569B70;
extern int D_003C2F84;
extern int D_003C2558;
extern unsigned int D_00747A84[];
extern unsigned int D_00747A80;
extern int D_00586B30[];
extern char D_00586AB0[];
extern unsigned char D_00604700[];
extern short D_005CAE40;
extern char D_00747470[];
extern void cEvent_releaseWork(cEvent *);
extern void UnlinkAndCoalesceNode_2A9680(int, void *);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern char *GetJacket(void);
extern void SetObjectTransform_2C4440(int, char *, float, float, float, float);
extern void func_0();
extern void ClearDisplayText_2974F0(cEvent *);
extern void func_00297660(cEvent *);
extern void cEmSetParam_setEmAll(char *);
extern void Set_bg_mode(int, int, int, int);
extern void classFADE_start(char *, int, int, int, int, int, int);
extern void Obj0000_Set_D_003C2555_One_2B65F0(int);

/* Start reading the cutscene's display text; mark the record once the data
 * pointer has been filled in. */
__attribute__((section(".text.cEvent_startLoadText")))
void cEvent_startLoadText(cEvent *self) {
    int name[8];
    char *fmt = D_0044A960;
    func_003A6C58(name, fmt, func_00297B80(self));
    /* raw store: the typed member lets the D_003C3CF0 load float above it */
    *(int *)((char *)self + CEVENT_OFFSET(textData)) = 0;
    self->loadHandle = cDvd_ReadAlloc(D_00583F20, name, &self->textData, (void *)D_003C3CF0, 0, 0, 0, 0);
    if (self->textData != 0) {
        self->flags |= CEVENT_F_TEXT_DATA;
    }
}

/* Tear the cutscene down: free its data, clear the player's cutscene flags
 * (object offsets 0x250 and 0x6A8 are the flag word and the partner pointer),
 * put the player back, clear the cutscene globals and restore the screen. */
__attribute__((section(".text.cEvent_endPlay")))
void cEvent_endPlay(cEvent *self) {
    char *player;
    char *jacket;
    char *partner;
    unsigned long flagsA;
    unsigned long flagsB;
    unsigned long shiftB;
    unsigned long shiftA;
    unsigned long fadeBit;
    unsigned long selfByte0;
    long bit0A;
    long bit0B;
    unsigned int objFlags;
    unsigned int jacketFlags;
    cEventTextHdr *text;
    char *res;

    cEvent_releaseWork(self);
    text = self->textData;
    if (text != 0) {
        UnlinkAndCoalesceNode_2A9680(((int *)text)[-8], text);
    }
    *(int *)(D_00569B70 + 0x14) &= ~0x40000000;
    player = Obj0000_Get_D_00747A94_2DB6B0();
    jacket = GetJacket();
    objFlags = *(unsigned int *)(player + 0x250) & 0xFFFF7FFF;
    *(unsigned int *)(player + 0x250) = objFlags & 0xFFFFFFFD;
    if (jacket != 0) {
        jacketFlags = *(unsigned int *)(jacket + 0x250) & 0xFFFF7FFF;
        *(unsigned int *)(jacket + 0x250) = jacketFlags & 0xFFFFFFFD;
    }
    partner = *(char **)(player + 0x6A8);
    if (partner != 0) {
        *(unsigned int *)(partner + 0x250) &= 0xFFFF7FFF;
        *(unsigned int *)(*(char **)(player + 0x6A8) + 0x250) &= 0xFFFFFFFD;
    }
    SetObjectTransform_2C4440(D_003C2F84, player, self->pos[0], self->pos[1], self->pos[2], self->angle);
    /* D_00747A84[-3] is D_00747A78: the negative index is what puts retail's
     * single base register on D_00747A84. */
    D_00747A84[0] &= 0xDFFFFFFF;
    D_00747A84[-3] = (D_00747A84[-3] | 0x40000000) & 0xFFDFFFFF;
    selfByte0 = *(unsigned char *)&self->flags;
    if ((selfByte0 >> 7) != 0) {
        func_0(cEvent_nullStr00);
        ClearDisplayText_2974F0(self);
        res = (char *)self->resData;
        if (res != 0) {
            UnlinkAndCoalesceNode_2A9680(((int *)res)[-8], res);
        }
        self->resData = 0;
    }
    func_00297660(self);
    flagsA = D_00586B30[1];
    shiftA = flagsA >> 6;
    fadeBit = shiftA & 1;
    if (fadeBit != 0) goto skip;
    if ((flagsA & 0x800) != 0) goto skip;
    bit0A = flagsA & 1;
    if (bit0A != 0) goto skip;
    cEmSetParam_setEmAll(D_00586AB0);
    Set_bg_mode(1, D_00604700[0], D_00604700[1], D_00604700[2]);
    D_00747A80 &= 0xFDFFFFFF;
    classFADE_start(D_00747470, 0, 8, 0, 0xFF000000, 0, 15);
    D_005CAE40 = 15;
skip:
    flagsB = D_00586B30[1];
    bit0B = flagsB & 1;
    if (bit0B != 0) {
        D_00747A80 &= 0xFDFFFFFF;
    }
    shiftB = flagsB >> 6;
    bit0A = shiftB & 1;
    if (bit0A == 0) {
        Obj0000_Set_D_003C2555_One_2B65F0(D_003C2558);
    }
}
