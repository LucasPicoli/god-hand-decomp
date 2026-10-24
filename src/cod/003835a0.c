/* sn-2.95.3-136: file-select menu states and slot info refresh (0x3835A0..). */

#include "godhand/menuCtl.h"

extern int func_0032DC58(int handle);
extern int func_0032DCD0(int handle, int a1);
extern void func_0032A160(int handle, int *info, void *buf);
extern int func_0032B6E0(int handle);
extern float func_0032AE10(int handle);
extern int func_0032D0C0(int handle);
extern void *func_0031C8B8(int size, int align);
extern int func_003A6A20(const char *fmt, ...);
extern int func_00323E80(int a0, int a1, int a2);
extern int func_003244C8(int req);
extern char D_0045CA58[];

void func_00383708(FileSel *sel, MenuPad *pad);
void func_003837E8(FileSel *sel);

__attribute__((section(".text.func_003835A0")))
void func_003835A0(void *unused, SlotView *v)
{
    char buf[16];

    if (v->flags & 1) {
        SlotInfoA *a = &v->a;

        if (a->handle != 0) {
            v->stat = func_0032DC58(a->handle);
        } else {
            v->stat = -1;
        }
        if (v->stat < 0) {
            return;
        }
        {
            int h = func_0032DCD0(a->handle, 0);

            if (h != 0) {
                func_0032A160(h, &a->info, buf);
            }
        }
    } else {
        SlotInfoB *b = &v->b;

        if (b->handle != 0) {
            v->stat = GuardedCall_00329FD0_329F98(b->handle);
        } else {
            v->stat = -1;
        }
        if (v->stat < 0) {
            return;
        }
        func_0032A160(b->handle, &b->info, buf);
        b->size = func_0032B6E0(b->handle);
        b->time = func_0032AE10(b->handle);
        b->stamp = func_0032D0C0(b->handle);
    }
}

__attribute__((section(".text.func_00383708")))
void func_00383708(FileSel *sel, MenuPad *pad)
{
    FileSelWork *w = &sel->work;
    FileList *list = w->list;
    void *buf;

    if (pad->trg & 0x8000) {
        sel->cursor = (sel->cursor == 0 ? list->count : sel->cursor) - 1;
    } else if (pad->trg & 0x2000) {
        if (sel->cursor < list->count - 1) {
            sel->cursor++;
        } else {
            sel->cursor = 0;
        }
    } else {
        return;
    }
    w->busy = 0;
    w->req = func_00323918(0xFF, sel->cursor);
    if ((w->buf = buf = func_0031C8B8(0x800, 0x40)) == 0) {
        func_003A6A20(D_0045CA58);
        w->err = 1;
    } else {
        func_00323E80(w->req, 1, buf);
        sel->state = 1;
    }
}

__attribute__((section(".text.func_003837E8")))
void func_003837E8(FileSel *sel)
{
    FileSelWork *w = &sel->work;

    if (func_003244C8(w->req) != 3) {
        return;
    }
    if (func_0037FD28(sel, w)) {
        sel->state = 0;
    } else {
        sel->state = 2;
    }
}
