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

/* libio genops.c :: _IO_default_setbuf */
__attribute__((section(".text._IO_default_setbuf")))
struct _IO_FILE *_IO_default_setbuf(struct _IO_FILE *fp, char *p, _IO_ssize_t len) {
    if ((*fp->vtable->__sync.pfn)(fp) == -1)
        return 0;
    if (p == 0 || len == 0) {
        fp->_flags |= 2;
        func_0038C768(fp, fp->_shortbuf, fp->_shortbuf + 1, 0);
    } else {
        fp->_flags &= ~2;
        func_0038C768(fp, p, p + len, 0);
    }
    fp->_IO_write_base = fp->_IO_write_ptr = fp->_IO_write_end = 0;
    fp->_IO_read_base = fp->_IO_read_ptr = fp->_IO_read_end = 0;
    return fp;
}
