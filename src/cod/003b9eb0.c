/* cygnus-2.96: func_003B9EB0, takes a free 0x3C-byte work record for a buffer of at least 0x1800 bytes and
 * marks it in use. */
#include "godhand/globals.h"
typedef struct {
    int used; /* 0x00 */
    int pad4;
    void *buf; /* 0x08 */
    int size; /* 0x0C */
    char pad10[0x18 - 0x10];
    int state; /* 0x18 */
} WorkRec;
extern void func_003B9DE0(char *msg);
extern WorkRec *func_003B9F60(void);
extern void *func_003A52F0(void *d, int c, unsigned int n);
extern void func_003B9FB8(WorkRec *w);

__attribute__((section(".text.func_003B9EB0")))
WorkRec *func_003B9EB0(void *buf, int size)
{
    WorkRec *w;

    if (buf == 0) {
        func_003B9DE0(D_00460888);
        return 0;
    }
    if (size < 0x1800) {
        func_003B9DE0(D_004608B0);
        return 0;
    }
    w = func_003B9F60();
    if (w != 0) {
        func_003A52F0(w, 0, 0x3C);
        func_003B9FB8(w);
        w->buf = buf;
        w->size = size;
        w->state = 2;
        w->used = 1;
    }
    return w;
}
