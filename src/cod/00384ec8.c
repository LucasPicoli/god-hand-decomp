#include "godhand/menuCtl.h"

extern void func_0032B188(int handle, int a1);
extern void func_0032A9F0(int handle, int a1);
extern void func_0032A6D0(int handle, int a1, int a2);
extern void func_0032B300(int handle, void *a1);
extern void func_0032BDC0(int handle, int a1, int idx);

__attribute__((section(".text.func_00384EC8")))
int func_00384EC8(MenuCtl *ctl, MenuList *list)
{
    MenuInfo *work = &list->work;
    MenuInfo *info = &list->info;
    int r;

    r = func_00380AE8(ctl, work, (MenuList *)list);
    if (r != 0) {
        list->result = r;
        return 1;
    }
    func_0032B188(work->handle, 1);
    work->f00 = list->info.f00;
    work->f04 = info->f04;
    work->f08 = info->f08;
    work->f0C = info->f0C;
    func_0032A9F0(work->handle, list->unk04);
    func_0032A6D0(work->handle, 0, list->unk08);
    func_0032A6D0(work->handle, 1, list->unk0A);
    list->unk00 = 0;
    func_0032B300(work->handle, 0);
    func_0032BDC0(work->handle, (int)list->dir, ctl->cursor);
    return 0;
}
