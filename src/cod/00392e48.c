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

/* libio fileops.c :: _IO_file_sync */
__attribute__((section(".text._IO_file_sync")))
int _IO_file_sync(struct _IO_FILE *fp) {
    _IO_size_t delta;
    int retval = 0;

    if (fp->_IO_write_ptr > fp->_IO_write_base)
        if (_IO_do_write(fp, fp->_IO_write_base,
                         fp->_IO_write_ptr - fp->_IO_write_base)) return -1;
    delta = fp->_IO_read_ptr - fp->_IO_read_end;
    if (delta != 0) {
        _IO_ssize_t new_pos = (*fp->vtable->__seek.pfn)(fp, delta, 1);
        if (new_pos != (_IO_ssize_t) -1)
            fp->_IO_read_end = fp->_IO_read_ptr;
        else if (errno == ESPIPE)
            ;
        else
            retval = -1;
    }
    if (retval != -1)
        fp->_offset = -1;
    return retval;
}
