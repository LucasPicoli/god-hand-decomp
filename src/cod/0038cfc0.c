/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

extern void _IO_switch_to_main_get_area(struct _IO_FILE *fp);
extern void _IO_switch_to_backup_area(struct _IO_FILE *fp);
extern int _IO_least_marker(struct _IO_FILE *fp);

extern void func_0038C768(struct _IO_FILE *f, char *b, char *eb, int a); /* _IO_setb */
extern int _IO_free_backup_area(struct _IO_FILE *fp);      /* _IO_free_backup_area */

extern void *func_003A7C70(unsigned int n);                       /* malloc */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *p);             /* free */
extern void *func_003A5148(void *d, const void *s, unsigned int n); /* memcpy */
extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */
/* libio genops.c :: _IO_init_marker */
__attribute__((section(".text._IO_init_marker")))
void _IO_init_marker(struct _IO_marker *marker, struct _IO_FILE *fp) {
    marker->_sbuf = fp;
    if (fp->_flags & 0x800)
        _IO_switch_to_get_mode(fp);
    if (fp->_flags & _IO_IN_BACKUP)
        marker->_pos = fp->_IO_read_ptr - fp->_IO_read_end;
    else
        marker->_pos = fp->_IO_read_ptr - fp->_IO_read_base;

    marker->_next = fp->_markers;
    fp->_markers = marker;
}
