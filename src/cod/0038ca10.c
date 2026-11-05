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

/* libio genops.c :: _IO_default_xsgetn */
__attribute__((section(".text._IO_default_xsgetn")))
_IO_size_t _IO_default_xsgetn(struct _IO_FILE *fp, void *data, _IO_size_t n) {
    _IO_size_t more = n;
    char *s = (char*) data;
    for (;;) {
        _IO_ssize_t count = fp->_IO_read_end - fp->_IO_read_ptr;
        if (count > 0) {
            if ((_IO_size_t) count > more)
                count = more;
            if (count > 20) {
                func_003A5148(s, fp->_IO_read_ptr, count);
                s += count;
                fp->_IO_read_ptr += count;
            } else if (count <= 0)
                count = 0;
            else {
                char *p = fp->_IO_read_ptr;
                int i = (int) count;
                while (--i >= 0)
                    *s++ = *p++;
                fp->_IO_read_ptr = p;
            }
            more -= count;
        }
        if (more == 0 || __underflow(fp) == -1)
            break;
    }
    return n - more;
}
