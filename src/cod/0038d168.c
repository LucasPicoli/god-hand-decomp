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

/* libio genops.c :: _IO_default_pbackfail */
__attribute__((section(".text.func_0038D168")))
int func_0038D168(struct _IO_FILE *fp, int c) {
    if (fp->_IO_read_ptr <= fp->_IO_read_base) {
        if (fp->_IO_save_base != 0 && !(fp->_flags & _IO_IN_BACKUP))
            _IO_switch_to_backup_area(fp);

        if (!(fp->_IO_save_base != 0)) {
            int backup_size = 128;
            char *bbuf = (char *) func_003A7C70(backup_size);
            if (bbuf == 0)
                return -1;
            fp->_IO_save_base = bbuf;
            fp->_IO_save_end = fp->_IO_save_base + backup_size;
            fp->_IO_backup_base = fp->_IO_save_end;
            _IO_switch_to_backup_area(fp);
        } else if (fp->_IO_read_ptr <= fp->_IO_read_base) {
            _IO_size_t new_size;
            _IO_size_t old_size = fp->_IO_read_end - fp->_IO_read_base;
            char *new_buf;
            new_size = 2 * old_size;
            new_buf = (char *) func_003A7C70(new_size);
            if (new_buf == 0)
                return -1;
            func_003A5148(new_buf + (new_size - old_size), fp->_IO_read_base,
                          old_size);
            UpdateGlobalPtrWithParam_3A7CC0(fp->_IO_read_base);
            (fp->_IO_read_base = new_buf, fp->_IO_read_ptr = new_buf + (new_size - old_size),
             fp->_IO_read_end = new_buf + new_size);
            fp->_IO_backup_base = fp->_IO_read_ptr;
        }
    }
    --fp->_IO_read_ptr;
    if (c != -1 && *fp->_IO_read_ptr != c)
        *fp->_IO_read_ptr = c;
    return (unsigned char) *fp->_IO_read_ptr;
}
