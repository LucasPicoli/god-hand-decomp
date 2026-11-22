#include "godhand/menuCtl.h"
#include "godhand/globals.h"

typedef struct FileName {
    long a;
    unsigned short b;
    unsigned char c;
} FileName;

typedef struct FileNameSel {
    char pad0[0x3C];
    char *name;
} FileNameSel;

typedef struct FileLoadWork {
    unsigned char state;
    unsigned char err;
    char pad2[0x30 - 2];
    SlotInfoA info;
} FileLoadWork;

extern int func_00381B38(FileNameSel *sel, SlotInfoA *info, FileLoadWork *work);
extern void func_0032DE88(int handle, int a1);
extern void func_0032DEF8(int handle, int a1);
extern void func_0032DF70(int handle, int a1, int a2);
extern void func_003821D8(FileNameSel *sel, FileLoadWork *work);
extern void func_003825A8(FileNameSel *sel, FileLoadWork *work);
extern char *func_003A53A8(char *dst, const char *src);
extern void func_0032D9B8(int handle, char *name, int a2);
extern int func_0032E040(int handle, int a1);
extern FileName D_0045C7F0;
extern FileName D_0077BF80;

__attribute__((section(".text.func_00381BC8")))
int func_00381BC8(FileNameSel *sel, FileLoadWork *work)
{
    SlotInfoA *info = &work->info;
    int r;
    int len;
    char *src;
    FileName *d;

    r = func_00381B38(sel, info, work);
    if (r != 0) {
        work->err = r;
        return 1;
    }
    func_0032DE88(info->handle, 1);
    func_0032DEF8(info->handle, 1);
    func_0032DF70(info->handle, 1, 1);
    func_003821D8(sel, work);
    func_003825A8(sel, work);
    d = &D_0077BF80;
    d->a = D_0045C7F0.a;
    d->b = D_0045C7F0.b;
    d->c = D_0045C7F0.c;
    len = ((int *)sel->name)[-4];
    if (len == 0) {
        src = D_0045C800;
    } else {
        sel->name[len] = 0;
        src = sel->name;
    }
    func_003A53A8((char *)d, src);
    func_0032D9B8(info->handle, (char *)&D_0077BF80, 0);
    work->state = 0;
    func_0032E040(info->handle, 0);
    return 0;
}
