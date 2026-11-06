/* ee-2.9-991111 matched TU. */

extern int _IO_adjust_column(unsigned int start, const char *line, int count);

#include "godhand/libio.h"


/* libio fileops.c :: _IO_do_write */
__attribute__((section(".text._IO_do_write")))
int _IO_do_write(struct _IO_FILE *fp, const char *data, _IO_size_t to_do) {
    _IO_size_t count;
    if (to_do == 0)
        return 0;
    if (fp->_flags & 0x1000)
        fp->_offset = -1;
    else if (fp->_IO_read_end != fp->_IO_write_base) {
        _IO_pos_t new_pos
            = (*fp->vtable->__seek.pfn)(fp, fp->_IO_write_base - fp->_IO_read_end, 1);
        if (new_pos == -1)
            return -1;
        fp->_offset = new_pos;
    }
    count = (*fp->vtable->__write.pfn)(fp, data, to_do);
    if (fp->_cur_column)
        fp->_cur_column = _IO_adjust_column(fp->_cur_column - 1, data, to_do) + 1;
    (fp->_IO_read_base = fp->_IO_buf_base, fp->_IO_read_ptr = fp->_IO_buf_base,
     fp->_IO_read_end = fp->_IO_buf_base);
    fp->_IO_write_base = fp->_IO_write_ptr = fp->_IO_buf_base;
    fp->_IO_write_end = ((fp->_flags & (0x200 + 0x2))
                         ? fp->_IO_buf_base : fp->_IO_buf_end);
    return count != to_do ? -1 : 0;
}
