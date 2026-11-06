/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

extern void func_0038C768(struct _IO_FILE *f, char *b, char *eb, int a); /* _IO_setb */
extern int _IO_free_backup_area(struct _IO_FILE *fp);      /* _IO_free_backup_area */
extern void _IO_switch_to_main_get_area(struct _IO_FILE *fp);
extern void _IO_switch_to_backup_area(struct _IO_FILE *fp);
extern int _IO_least_marker(struct _IO_FILE *fp);
extern void *func_003A7C70(unsigned int n);                       /* malloc */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *p);             /* free */
extern void *func_003A5148(void *d, const void *s, unsigned int n); /* memcpy */
extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */

extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);                    /* __errno */
#define errno (*Obj0000_Get_D_003FA62C_3A4FB8())
#define EBADF 9
#define ESPIPE 29

extern void func_0038D140(struct _IO_FILE *fp);     /* _IO_unsave_markers */
extern void _IO_flush_all_linebuffered(void);
#define _IO_do_flush(_f) _IO_do_write(_f, (_f)->_IO_write_base, (_f)->_IO_write_ptr-(_f)->_IO_write_base)

/* libio fileops.c :: _IO_file_underflow */
__attribute__((section(".text.func_00392BA0")))
int func_00392BA0(struct _IO_FILE *fp) {
    _IO_ssize_t count;

    if (fp->_flags & 4) {
        errno = EBADF;
        return -1;
    }
    if (fp->_IO_read_ptr < fp->_IO_read_end)
        return *(unsigned char *) fp->_IO_read_ptr;

    if (fp->_IO_buf_base == 0)
        func_0038C7F0(fp);

    if (fp->_flags & (0x200 | 2))
        _IO_flush_all_linebuffered();

    _IO_switch_to_get_mode(fp);

    fp->_IO_read_base = fp->_IO_read_ptr = fp->_IO_buf_base;
    fp->_IO_read_end = fp->_IO_buf_base;
    fp->_IO_write_base = fp->_IO_write_ptr = fp->_IO_write_end
        = fp->_IO_buf_base;

    count = (*fp->vtable->__read.pfn)(fp, fp->_IO_buf_base,
                                      fp->_IO_buf_end - fp->_IO_buf_base);
    if (count <= 0) {
        if (count == 0)
            fp->_flags |= 0x10;
        else
            fp->_flags |= 0x20, count = 0;
    }
    fp->_IO_read_end += count;
    if (count == 0)
        return -1;
    if (fp->_offset != -1)
        fp->_offset += count;
    return *(unsigned char *) fp->_IO_read_ptr;
}
