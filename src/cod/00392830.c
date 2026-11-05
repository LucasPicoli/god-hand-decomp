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

extern int open(const char *path, int flags, int prot);  /* open */
#define EINVAL 22

/* libio fileops.c :: _IO_file_fopen */
__attribute__((section(".text.func_00392830")))
struct _IO_FILE *func_00392830(struct _IO_FILE *fp, const char *filename, const char *mode) {
  int oflags = 0, omode;
  int read_write, fdesc;
  int oprot = 0666;
  if (fp->_fileno >= 0)
    return 0;
  switch (*mode++)
    {
    case 'r':
      omode = 0;
      read_write = 8;
      break;
    case 'w':
      omode = 1;
      oflags = 0x200|0x400;
      read_write = 4;
      break;
    case 'a':
      omode = 1;
      oflags = 0x200|0x8;
      read_write = 4|0x1000;
      break;
    default:
      errno = EINVAL;
      return 0;
    }
  if (mode[0] == '+' || (mode[0] == 'b' && mode[1] == '+'))
    {
      omode = 2;
      read_write &= 0x1000;
    }
  fdesc = open(filename, omode|oflags, oprot);
  if (fdesc < 0)
    return 0;
  fp->_fileno = fdesc;
  fp->_flags = (fp->_flags & ~(4+8+0x1000)) | (read_write & (4+8+0x1000));
  if (read_write & 0x1000)
    if ((*fp->vtable->__seekoff.pfn)(fp, (_IO_ssize_t)0, 2, 1|2)
        == -1 && errno != ESPIPE)
      return 0;
  _IO_link_in (fp);
  return fp;
}
