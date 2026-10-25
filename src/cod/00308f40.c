/* sn-2.95.3-136 matched TU. */

#include "godhand/menuCtl.h"
#include "godhand/sndBank.h"
#include "godhand/SndSlot.h"
#include "godhand/cIDParam.h"

extern void func_0032B118(int handle);
extern int sceSifInitRpc(int mode);
extern void func_00377BC8(void);
extern void func_00375860(void);
extern char D_0076A9C0[];
extern char D_0076B1C0[];
extern void ClearInvalidEntry_376400(SndSlot *slot);
extern void func_00376438(SndSlot *slot);
extern void func_00376720(SndSlot *slot);
extern void UpdateSlotState_3767B0(SndSlot *slot);
extern void UpdatePendingFlags_376820(SndSlot *slot);
extern void func_002E0DE8(int x, int y, int color, const char *fmt, ...);
extern char D_0045CD50[];
extern char D_0045CD60[];
extern char *D_003F2870[];
extern void func_003A52F0(void *dst, int fill, int size);

/* Poll the page's stream and refresh the list. Returns 3 or 4 (3 when the poll says -1), 0 when idle. */
__attribute__((section(".text.func_00380F80")))
int func_00380F80(MenuCtl *ctl, MenuInfo *info, MenuList *list)
{
    int st;

    if (info->handle == 0)
        goto none;
    st = func_0032B0B0(info->handle);
    if (st == 0)
        goto none;
    func_0032B118(info->handle);
    func_00380EB0(ctl, info, list);
    return st != -1 ? 4 : 3;
none: /* goto: the || cascade and an early return both move the shared return-0 block (measured), so it stays one label */
    return 0;
}

/* Start the sound driver: bring up RPC, point the command record at the two transfer buffers,
 * then post commands 0 and 1. Fields 0x4 and 0x8 of the record hold the two
 * transfer buffer addresses here. */
__attribute__((section(".text.func_00375318")))
void func_00375318(void)
{
    SndBankCmd *c = &D_0076A880;

    sceSifInitRpc(0);
    func_00377BC8();
    func_00375860();
    c->bank = (int)D_0076A9C0;
    c->id = (int)D_0076B1C0;
    func_003758E8(0);
    func_003758E8(1);
}

/* Per-frame pass over the sound slot table: validate a flagged slot, then advance every live one. */
__attribute__((section(".text.func_00376370")))
void func_00376370(void)
{
    int i;

    for (i = 0; i < SND_SLOT_NUM; i++) {
        SndSlot *slot = &D_00770850[i];
        if (slot->state != 0) {
            if (slot->state & SND_SLOT_CHECK) {
                ClearInvalidEntry_376400(slot);
            } else {
                func_00376438(slot);
            }
            if (slot->state != 0) {
                func_00376720(slot);
                UpdateSlotState_3767B0(slot);
                UpdatePendingFlags_376820(slot);
            }
        }
    }
}

/* The sound test cursor as this page helper sees it: only the picked slot is read. */
typedef struct SndTestCursor {
    char unk00[4];
    unsigned char slot;         /* 0x04 */
} SndTestCursor;






/* Print the MUTE row of the sound test page for the picked slot. */
__attribute__((section(".text.func_00384BC8")))
void func_00384BC8(void *unused, SndTestCursor *cur, MenuSndInfo *info)
{
    if (cur->slot != 0) {
        func_002E0DE8(3, 0x18, 8, D_0045CD50, cur->slot - 1, D_003F2870[info->mute[cur->slot]]);
    } else {
        func_002E0DE8(3, 0x18, 8, D_0045CD60, D_003F2870[info->mute[cur->slot]]);
    }
}

/* Reset the parameter record to its defaults: 256 x 224 screen, unit scales, grey tint. */
__attribute__((section(".text.cIDParam_initialize")))
void cIDParam_initialize(cIDParam *self)
{
    func_003A52F0(self, 0, CIDPARAM_SIZE);
    self->kind = 6;
    self->level = 5;
    self->screenW = CIDPARAM_SCREEN_W;
    self->screenH = CIDPARAM_SCREEN_H;
    self->tint = CIDPARAM_TINT_GREY;
    self->unk02 = -1;
    self->unk03 = -1;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->scale48 = 1.0f;
    self->scale4C = 1.0f;
    self->scale28 = 1.0f;
    self->scale2C = 1.0f;
    self->scale30 = 1.0f;
    self->flag6A = 1;
    self->flag6B = 1;
    self->flag69 = 1;
    self->word6E = 1;
    self->word6C = 1;
    self->word1B0 = 1;
    self->word214 = 1;
    self->word278 = 1;
    self->tint2DC = CIDPARAM_TINT_GREY;
}
