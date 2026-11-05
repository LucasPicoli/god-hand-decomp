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
#define _IO_do_flush(_f) _IO_do_write(_f, (_f)->_IO_write_base, (_f)->_IO_write_ptr-(_f)->_IO_write_base)

/* libio fileops.c :: _IO_file_overflow */
__attribute__((section(".text.func_00392CD0")))
int func_00392CD0(struct _IO_FILE *f, int ch) {
    if (f->_flags & 8) {
        f->_flags |= 0x20;
        errno = EBADF;
        return -1;
    }
    if ((f->_flags & 0x800) == 0) {
        if (f->_IO_write_base == 0) {
            func_0038C7F0(f);
            (f->_IO_read_base = f->_IO_buf_base, f->_IO_read_ptr = f->_IO_buf_base,
             f->_IO_read_end = f->_IO_buf_base);
        }
        if (f->_IO_read_ptr == f->_IO_buf_end)
            f->_IO_read_end = f->_IO_read_ptr = f->_IO_buf_base;
        f->_IO_write_ptr = f->_IO_read_ptr;
        f->_IO_write_base = f->_IO_write_ptr;
        f->_IO_write_end = f->_IO_buf_end;
        f->_IO_read_base = f->_IO_read_ptr = f->_IO_read_end;

        if (f->_flags & (0x200 + 2))
            f->_IO_write_end = f->_IO_write_ptr;
        f->_flags |= 0x800;
    }
    if (ch == -1)
        return _IO_do_flush(f);
    if (f->_IO_write_ptr == f->_IO_buf_end)
        if (_IO_do_flush(f) == -1)
            return -1;
    *f->_IO_write_ptr++ = ch;
    if ((f->_flags & 2)
        || ((f->_flags & 0x200) && ch == '\n'))
        if (_IO_do_flush(f) == -1)
            return -1;
    return (unsigned char) ch;
}
