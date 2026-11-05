/* ee-2.9-991111 matched TU. */

extern int write(int fd, const void *buf, int n);

#include "godhand/libio.h"



/* libio fileops.c :: _IO_file_write */
__attribute__((section(".text.func_003932B8")))
_IO_ssize_t func_003932B8(struct _IO_FILE *f, const void *data, _IO_ssize_t n) {
    _IO_ssize_t to_do = n;
    while (to_do > 0) {
        _IO_ssize_t count = write(f->_fileno, data, to_do);
        if (count == -1) {
            f->_flags |= 0x20;
            break;
        }
        to_do -= count;
        data = (void *) ((char *) data + count);
    }
    n -= to_do;
    if (f->_offset >= 0)
        f->_offset += n;
    return n;
}
