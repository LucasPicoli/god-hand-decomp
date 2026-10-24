/* sn-2.95.3-136 */
#include "godhand/menuCtl.h"

extern const char D_0045C270[];
extern int func_00323000(int ptid);
extern void func_00323A70(int adxf);
extern int func_00323E80(int a0, int a1, int a2);
extern void *func_0031C8B8(int size, int align);
extern void func_003A6A20(const char *s);

/* Once the partition has loaded, opens the selected file and starts reading
 * its first sector into a new buffer; reports and closes it when the buffer
 * can't be allocated. */
__attribute__((section(".text.func_0037FC28")))
void func_0037FC28(FileSel *self)
{
    FileSelWork *work = &self->work;

    if (func_00323000(0xFF) != 3) {
        return;
    }
    work->req = func_00323918(0xFF, self->cursor);
    work->buf = func_0031C8B8(0x800, 0x40);
    if (work->buf == 0) {
        func_003A6A20(D_0045C270);
        work->err = 1;
        func_00323A70(work->req);
        self->state = 10;
    } else {
        func_00323E80(work->req, 1, (int)work->buf);
        self->state = 5;
    }
}
