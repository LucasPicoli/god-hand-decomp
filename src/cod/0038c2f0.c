/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"
/* libio genops.c :: _IO_switch_to_get_mode */
__attribute__((section(".text._IO_switch_to_get_mode")))
int _IO_switch_to_get_mode(struct _IO_FILE *fp) {
    if (fp->_IO_write_ptr > fp->_IO_write_base)
        if ((*fp->vtable->__overflow.pfn)(fp, -1) == -1)
            return -1;
    if (fp->_flags & 0x100)
        fp->_IO_read_base = fp->_IO_backup_base;
    else {
        fp->_IO_read_base = fp->_IO_buf_base;
        if (fp->_IO_write_ptr > fp->_IO_read_end)
            fp->_IO_read_end = fp->_IO_write_ptr;
    }
    fp->_IO_read_ptr = fp->_IO_write_ptr;

    fp->_IO_write_base = fp->_IO_write_ptr = fp->_IO_write_end = fp->_IO_read_ptr;

    fp->_flags &= ~0x800;
    return 0;
}
