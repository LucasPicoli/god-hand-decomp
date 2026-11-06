/* ee-2.9-991111 matched TU. */


#include "godhand/libio.h"

struct stat {
    unsigned int st_dev;      /* 0x00 */
    unsigned int st_mode;     /* 0x04 */
    unsigned int st_nlink;    /* 0x08 */
    unsigned int st_uid;      /* 0x0C */
    long st_size;             /* 0x10 */
    char _pad[0x58];          /* 0x18 */
};

extern void func_0038D140(struct _IO_FILE *fp);   /* _IO_unsave_markers */


/* libio fileops.c :: _IO_file_seekoff */
__attribute__((section(".text.func_00392F00")))
_IO_pos_t func_00392F00(struct _IO_FILE *fp, _IO_ssize_t offset, int dir, int mode) {
    _IO_pos_t result;
    _IO_ssize_t delta, new_offset;
    long count;
    int must_be_exact = (fp->_IO_read_base == fp->_IO_read_end
                         && fp->_IO_write_base == fp->_IO_write_ptr);

    if (mode == 0)
        dir = 1, offset = 0;

    if (fp->_IO_write_ptr > fp->_IO_write_base || (fp->_flags & 0x800))
        if (_IO_switch_to_get_mode(fp))
            return -1;

    if (fp->_IO_buf_base == 0) {
        func_0038C7F0(fp);
        (fp->_IO_write_base = fp->_IO_write_ptr = fp->_IO_buf_base,
         fp->_IO_write_end = fp->_IO_buf_base);
        (fp->_IO_read_base = fp->_IO_buf_base, fp->_IO_read_ptr = fp->_IO_buf_base,
         fp->_IO_read_end = fp->_IO_buf_base);
    }

    switch (dir) {
    case 1:
        offset -= fp->_IO_read_end - fp->_IO_read_ptr;
        if (fp->_offset == -1)
            goto dumb;
        offset += fp->_offset;

        dir = 0;
        break;
    case 0:
        break;
    case 2:
        {
            struct stat st;
            if ((*fp->vtable->__stat.pfn)(fp, &st) == 0
                && (st.st_mode & 0xF000) == 0x8000) {
                offset += st.st_size;
                dir = 0;
            } else
                goto dumb;
        }
    }

    if (fp->_offset != -1 && fp->_IO_read_base != 0
        && !(fp->_flags & _IO_IN_BACKUP)) {
        _IO_pos_t rel_offset = (offset - fp->_offset
                                + (fp->_IO_read_end - fp->_IO_read_base));
        if (rel_offset >= 0) {
            if (rel_offset <= fp->_IO_read_end - fp->_IO_read_base) {
                (fp->_IO_read_base = fp->_IO_buf_base,
                 fp->_IO_read_ptr = fp->_IO_buf_base + rel_offset,
                 fp->_IO_read_end = fp->_IO_read_end);
                (fp->_IO_write_base = fp->_IO_write_ptr = fp->_IO_buf_base,
                 fp->_IO_write_end = fp->_IO_buf_base);
                return offset;
            }
        }
    }

    if (fp->_flags & 4)
        goto dumb;

    new_offset = offset & ~(fp->_IO_buf_end - fp->_IO_buf_base - 1);
    delta = offset - new_offset;
    if (delta > fp->_IO_buf_end - fp->_IO_buf_base) {
        new_offset = offset;
        delta = 0;
    }
    result = (*fp->vtable->__seek.pfn)(fp, new_offset, 0);
    if (result < 0)
        return -1;
    if (delta == 0)
        count = 0;
    else {
        count = (*fp->vtable->__read.pfn)(fp, fp->_IO_buf_base,
                                          (must_be_exact
                                           ? delta : fp->_IO_buf_end - fp->_IO_buf_base));
        if (count < delta) {
            offset = count == -1 ? delta : delta - count;
            dir = 1;
            goto dumb;
        }
    }
    (fp->_IO_read_base = fp->_IO_buf_base, fp->_IO_read_ptr = fp->_IO_buf_base + delta,
     fp->_IO_read_end = fp->_IO_buf_base + count);
    (fp->_IO_write_base = fp->_IO_write_ptr = fp->_IO_buf_base,
     fp->_IO_write_end = fp->_IO_buf_base);
    fp->_offset = result + count;
    fp->_flags = (fp->_flags & ~0x10) | (0 & 0x10);
    return offset;
 dumb:

    func_0038D140(fp);
    result = (*fp->vtable->__seek.pfn)(fp, offset, dir);
    if (result != -1)
        fp->_flags = (fp->_flags & ~0x10) | (0 & 0x10);
    fp->_offset = result;
    (fp->_IO_read_base = fp->_IO_buf_base, fp->_IO_read_ptr = fp->_IO_buf_base,
     fp->_IO_read_end = fp->_IO_buf_base);
    (fp->_IO_write_base = fp->_IO_write_ptr = fp->_IO_buf_base,
     fp->_IO_write_end = fp->_IO_buf_base);
    return result;
}
