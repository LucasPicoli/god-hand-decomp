/* sn-2.95.3-136: func_00382D30, menu page update: show the "no data" prompt when there is no
 * list, otherwise run cursor input, page/scroll handlers and redraw the window frame. */
#include "godhand/menuCtl.h"
extern void func_002E0DE8(int a0, int a1, int a2, void *a3);
extern void func_00380DC0(char *a0);
extern void func_00381010(char *a0, char *a1, unsigned char a2);
extern void func_00380678(void *a0, int a1, int a2, int a3, int a4);
extern void func_00382F00(void *a0, unsigned char *a1);
extern int func_00382F40(void *a0, void *a1);
extern void func_003833B0(void *a0, unsigned char *a1);
extern void func_003833F8(void *a0, unsigned char *a1);
extern void func_00383438(void *a0, unsigned char *a1);
extern void func_00383478(char *a0, char *a1);
extern void func_00383518(void *a0, void *a1);
extern void func_003835A0(void *a0, SlotView *a1);
extern void func_00384198(unsigned char *a0);
extern char D_0045CA00[];
extern char D_0045CA20[];

__attribute__((section(".text.func_00382D30")))
int func_00382D30(MenuCtl *self, MenuPad *arg)
{
    MenuPage *s2 = &self->page;

    if (s2->count == 0) {
        if ((arg->trg & MENUPAD_DPAD) != 0) {
            self->next = 0;
            return 1;
        }
        func_002E0DE8(0xE, 0xA, 0xE, D_0045CA00);
        func_002E0DE8(0xD, 0xC, 8, D_0045CA20);
        return 1;
    }
    if (s2->result != 0) {
        if ((arg->trg & MENUPAD_DPAD) != 0)
            s2->result = 0;
    } else {
        func_00382F00(self, s2);
        if (self->row != 0 || self->state == 0) {
            if ((arg->trg & MENUPAD_CANCEL) != 0 && self->state == 0) {
                self->next = 0;
                s2->status = 0;
                return 1;
            }
            if ((arg->trg & MENUPAD_DECIDE) != 0) {
                if ((arg->hold & 2) != 0)
                    func_00380DC0(self);
                if (func_00382F40(self, s2) != 0) {
                    func_00384198(self);
                    func_00380678(self, 0x18, self->row * 8 + 0xA0, 0x80006060, 0xFFF8);
                    return 1;
                }
            }
            func_003833B0(self, s2);
            if ((arg->trg & MENUPAD_NEXT) != 0)
                func_003833F8(self, s2);
            if ((arg->trg & MENUPAD_PREV) != 0)
                func_00383438(self, s2);
            func_00381010(self, arg, 4);
            func_00383478(self, arg);
        }
        func_00383518(self, arg);
        func_003835A0(self, s2);
    }
    func_00384198(self);
    func_00380678(self, 0x18, self->row * 8 + 0xA0, 0x80006060, 0xFFF8);
    return 1;
}
