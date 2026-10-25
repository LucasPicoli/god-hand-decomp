/* sn-2.95.3-136: func_003808A0, menu page update (same family as func_00384CA0): run cursor input and page handlers
 * for the current 0x48-byte page, then refresh the selected entry's model info (and the ADX stream counters when the
 * 0x3 toggle is on) and redraw the window frame. */
#include "godhand/menuCtl.h"
extern void func_00380DC0(MenuCtl *a0);
extern void func_00380D68(void *a0, void *a1);
extern int func_00380B70(MenuCtl *a0, MenuSlot *a1);
extern int MenuCtl_pollStreamAndRefresh(void *a0, void *a1, void *a2);
extern void func_00380F10(void *a0, void *a1, void *a2);
extern void func_00380E88(void *a0, void *a1, void *a2);
extern void func_00380E10(MenuCtl *a0);
extern void func_00381010(MenuCtl *a0, MenuPad *a1, unsigned char a2);
extern void func_00381070(void *a0, void *a1);
extern void func_00381478(void *a0);
extern void func_00380678(void *a0, int a1, int a2, int a3, int a4);
extern int GuardedCall_00329FD0_329F98(int a0);
extern void func_0032A160(int a0, int *a1, void *a2);
extern int func_0032B6E0(int a0);
extern float func_0032AE10(int a0);
extern int func_0032D0C0(int a0);
extern int func_0032AD10(int a0);
extern int ADXPS2_GetNumDataSjtmp(int a0, int a1);
extern int func_003261A8(int a0, int a1);

__attribute__((section(".text.func_003808A0")))
int func_003808A0(MenuCtl *self, MenuPad *arg)
{
    char buf[16];
    MenuSlot *slot = &self->slot[self->slotNo];
    MenuInfo *snd = &slot->info;
    int v;

    if (slot->result != 0) {
        if ((arg->press & MENUPAD_DPAD) != 0)
            slot->result = 0;
    } else {
        func_00380D68(self, snd);
        if ((arg->press & MENUPAD_CANCEL) != 0) {
            self->next = 0;
            slot->status = 0;
            return 1;
        }
        if ((arg->press & 4) != 0)
            self->detail ^= 1;
        if ((arg->press & MENUPAD_DECIDE) != 0) {
            if ((arg->hold & 2) != 0)
                func_00380DC0(self);
            if (func_00380B70(self, slot) != 0) {
                func_00381478(self);
                func_00380678(self, 0x18, self->row * 8 + 0x78, 0x80006060, 0xFFF8);
                return 1;
            }
        }
        v = MenuCtl_pollStreamAndRefresh(self, snd, slot);
        if (v != 0)
            slot->result = v;
        if ((arg->press & MENUPAD_NEXT) != 0)
            func_00380F10(self, snd, slot);
        if ((arg->press & MENUPAD_PREV) != 0)
            func_00380E88(self, snd, slot);
        if ((arg->press & 1) != 0)
            func_00380E10(self);
        func_00381010(self, arg, 4);
        func_00381070(self, arg);
        slot = &self->slot[self->slotNo];
        if (snd->handle != 0)
            slot->status = GuardedCall_00329FD0_329F98(snd->handle);
        else
            slot->status = -1;
        if (slot->status >= 0) {
            func_0032A160(snd->handle, &snd->time, buf);
            snd->unk14 = func_0032B6E0(snd->handle);
            snd->unk18 = func_0032AE10(snd->handle);
            snd->unk1C = func_0032D0C0(snd->handle);
            if (self->detail != 0) {
                snd->unk24 = func_0032AD10(snd->handle);
                snd->unk28 = ADXPS2_GetNumDataSjtmp(snd->handle, 0);
                snd->unk2C = func_003261A8(snd->handle, 0);
            }
        }
    }
    func_00381478(self);
    func_00380678(self, 0x18, self->row * 8 + 0x78, 0x80006060, 0xFFF8);
    return 1;
}
