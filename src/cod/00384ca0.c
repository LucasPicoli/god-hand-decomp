/* sn-2.95.3-136: func_00384CA0, menu page update (same family as func_00382D30): show the "no data" prompt when
 * there is no list, otherwise run cursor input and page handlers, refresh the selected entry's model info and redraw
 * the window frame. */
#include "godhand/menuCtl.h"
extern void func_002E0DE8(int a0, int a1, int a2, void *a3);
extern void func_00380DC0(char *a0);
extern void func_00380D68(void *a0, void *a1);
extern int func_00380F80(void *a0, void *a1, void *a2);
extern void func_00380F10(void *a0, void *a1, void *a2);
extern void func_00380E88(void *a0, void *a1, void *a2);
extern void func_00381010(char *a0, char *a1, unsigned char a2);
extern void func_00380678(void *a0, int a1, int a2, int a3, int a4);
extern int func_00384EC8(MenuCtl *a0, MenuList *a1);
extern void func_00384FA8(void *a0, void *a1);
extern void func_003854B0(unsigned char *a0);
extern int GuardedCall_00329FD0_329F98(int a0);
extern void func_0032A160(int a0, void *a1, void *a2);
extern int func_0032B6E0(int a0);
extern float func_0032AE10(int a0);
extern int func_0032D0C0(int a0);
extern char D_0045CD90[];
extern char D_0045CDB0[];

__attribute__((section(".text.func_00384CA0")))
int func_00384CA0(MenuCtl *self, MenuPad *arg)
{
    char buf[16];
    MenuList *s1 = &self->list;
    MenuInfo *s2 = &self->list.work;
    int v;

    if (s1->dir == 0) {
        if ((arg->trg & MENUPAD_DPAD) != 0) {
            self->next = 0;
            return 1;
        }
        func_002E0DE8(0xE, 0xA, 0xE, D_0045CD90);
        func_002E0DE8(0xD, 0xC, 8, D_0045CDB0);
        return 1;
    }
    if (s1->result != 0) {
        if ((arg->trg & MENUPAD_DPAD) != 0)
            s1->result = 0;
    } else {
        func_00380D68(self, s2);
        if (self->row != 0 || self->state == 0) {
            if ((arg->trg & MENUPAD_CANCEL) != 0) {
                self->next = 0;
                s1->status = 0;
                return 1;
            }
            if ((arg->trg & MENUPAD_DECIDE) != 0) {
                if ((arg->hold & 2) != 0)
                    func_00380DC0(self);
                if (func_00384EC8(self, s1) != 0) {
                    func_003854B0(self);
                    func_00380678(self, 0x18, self->row * 8 + 0xA0, 0x80006060, 0xFFF8);
                    return 1;
                }
            }
            v = func_00380F80(self, s2, s1);
            if (v != 0)
                s1->result = v;
            if ((arg->trg & MENUPAD_NEXT) != 0)
                func_00380F10(self, s2, s1);
            if ((arg->trg & MENUPAD_PREV) != 0)
                func_00380E88(self, s2, s1);
            func_00381010(self, arg, 4);
        }
        func_00384FA8(self, arg);
        if (s2->handle != 0)
            s1->status = GuardedCall_00329FD0_329F98(s2->handle);
        else
            s1->status = -1;
        if (s1->status >= 0) {
            func_0032A160(s2->handle, &s2->loopStart, buf);
            s2->loopEnd = func_0032B6E0(s2->handle);
            s2->rate = func_0032AE10(s2->handle);
            s2->unk1C = func_0032D0C0(s2->handle);
        }
    }
    func_003854B0(self);
    func_00380678(self, 0x18, self->row * 8 + 0xA0, 0x80006060, 0xFFF8);
    return 1;
}
