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

/* libio fileops.c :: _IO_file_close_it */
__attribute__((section(".text._IO_file_close_it")))
int _IO_file_close_it(struct _IO_FILE *fp) {
    int write_status, close_status;
    if (!(fp->_fileno >= 0))
        return -1;

    write_status = _IO_do_flush(fp);

    func_0038D140(fp);

    close_status = (*fp->vtable->__close.pfn)(fp);

    func_0038C768(fp, 0, 0, 0);
    (fp->_IO_read_base = 0, fp->_IO_read_ptr = 0, fp->_IO_read_end = 0);
    (fp->_IO_write_base = fp->_IO_write_ptr = 0, fp->_IO_write_end = 0);

    _IO_un_link(fp);
    fp->_flags = 0xFBAD0000 | 0x240C;
    fp->_fileno = -1;
    fp->_offset = -1;

    return close_status ? close_status : write_status;
}
