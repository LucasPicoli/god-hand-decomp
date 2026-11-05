/* sn-2.95.3-136 matched TU. */
#include "godhand/libio.h"

extern char D_0061B7C0[];
extern char D_0071B840[];

/* The marker's position relative to its stream's read position; -1 when it has no stream. */
__attribute__((section(".text._IO_marker_delta")))
int _IO_marker_delta(struct _IO_marker *mark) {
    int cur_pos;

    if (mark->_sbuf == 0) {
        return -1;
    }
    if (mark->_sbuf->_flags & _IO_IN_BACKUP) {
        cur_pos = mark->_sbuf->_IO_read_ptr - mark->_sbuf->_IO_read_end;
    } else {
        cur_pos = mark->_sbuf->_IO_read_ptr - mark->_sbuf->_IO_read_base;
    }
    return mark->_pos - cur_pos;
}

__attribute__((section(".text.PushEsp")))
void PushEsp(unsigned int p){unsigned int o=p-(unsigned int)D_0061B7C0;*(unsigned int*)(D_0071B840+((o>>15)<<2))|=0x80000000U>>((o>>10)&0x1F);}

struct StreamBase {
    char pad[0x10];
    long flags;
};

__attribute__((section(".text.skip__7istreami")))
int skip__7istreami(struct StreamBase **self, int i) {
    struct StreamBase *b = *self;
    long f = b->flags;
    int old = f & 1;

    if (i) {
        b->flags = f | 1;
    } else {
        b->flags = f & -2;
    }
    return old;
}
