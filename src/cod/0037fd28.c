#include "godhand/menuCtl.h"
#include "godhand/globals.h"

extern void ADXF_Close(int req);
extern int strncasecmp(const char *a, const char *b, unsigned int n);
extern void func_0031C900(void *buf);
extern int func_00381B38(FileSel *sel, SlotInfoA *info, FileSelWork *work);
extern void func_0032DA28(int handle, int a1, int cursor);
extern void func_0032BB48(int handle, int a1, int cursor);

__attribute__((section(".text.func_0037FD28")))
int func_0037FD28(FileSel *sel, FileSelWork *work)
{
    int *b = (int *)work->buf;
    int r;
    MenuInfo *m;

    if (b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0)
        return 1;
    ADXF_Close(work->req);
    if (strncasecmp((char *)work->buf, D_0045C2A8, 4) == 0)
        work->unk02[1] |= 2;
    else
        work->unk02[1] &= ~2;
    func_0031C900(work->buf);
    if (work->unk02[1] & 2) {
        SlotInfoA *a = (SlotInfoA *)((char *)work + 0xCC);
        r = func_00381B38(sel, a, work);
        if (r == 0) {
            func_0032DA28(a->handle, 0xFF, sel->cursor);
            return 0;
        }
    } else {
        m = (MenuInfo *)((char *)work + 0x6C);
        r = func_00380AE8((MenuCtl *)sel, m, (MenuList *)work);
        if (r == 0)
            goto fail;
    }
    work->err = r;
    return 1;
fail:
    func_0032BB48(m->handle, 0xFF, sel->cursor);
    return 0;
}
