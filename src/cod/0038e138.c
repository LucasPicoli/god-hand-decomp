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

extern const char D_0045D7E0[16];   /* blanks */
extern const char D_0045D7F0[16];   /* zeroes */

/* libio iopadn.c :: _IO_padn */
__attribute__((section(".text._IO_padn")))
_IO_ssize_t _IO_padn(struct _IO_FILE *fp, int pad, _IO_ssize_t count) {
  char padbuf[16];
  const char *padptr;
  int i;
  _IO_size_t written = 0;
  _IO_size_t w;

  if (pad == ' ')
    padptr = D_0045D7E0;
  else if (pad == '0')
    padptr = D_0045D7F0;
  else
    {
      for (i = 16; --i >= 0; )
        padbuf[i] = pad;
      padptr = padbuf;
    }
  for (i = count; i >= 16; i -= 16)
    {
      w = (*fp->vtable->__xsputn.pfn)(fp, padptr, 16);
      written += w;
      if (w != 16)
        return written;
    }

  if (i > 0)
    {
      w = (*fp->vtable->__xsputn.pfn)(fp, padptr, i);
      written += w;
    }
  return written;
}
