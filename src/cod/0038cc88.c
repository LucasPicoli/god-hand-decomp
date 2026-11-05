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

/* libio genops.c :: _IO_default_finish */
__attribute__((section(".text.func_0038CC88")))
void func_0038CC88(struct _IO_FILE *fp, int dummy) {
    struct _IO_marker *mark;
    if (fp->_IO_buf_base && !(fp->_flags & 1)) {
        UpdateGlobalPtrWithParam_3A7CC0(fp->_IO_buf_base);
        fp->_IO_buf_base = fp->_IO_buf_end = 0;
    }

    for (mark = fp->_markers; mark != 0; mark = mark->_next)
        mark->_sbuf = 0;

    if (fp->_IO_save_base) {
        UpdateGlobalPtrWithParam_3A7CC0(fp->_IO_save_base);
        fp->_IO_save_base = 0;
    }

    _IO_un_link(fp);
}
