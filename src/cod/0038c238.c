/* ee-2.9-991111 matched TU. */

#define NULL 0
#include "godhand/libio.h"


/* libio genops.c :: _IO_least_marker */
__attribute__((section(".text._IO_least_marker")))
_IO_size_t _IO_least_marker(struct _IO_FILE *fp) {
    _IO_ssize_t least_so_far = fp->_IO_read_end - fp->_IO_read_base;
    struct _IO_marker *mark;
    for (mark = fp->_markers; mark != NULL; mark = mark->_next)
        if (mark->_pos < least_so_far)
            least_so_far = mark->_pos;
    return least_so_far;
}
