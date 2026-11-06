/* ee-2.9-991111 matched TU. */

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

#define EOF (-1)
#define _IO_LINE_BUF 0x200
#define _IO_CURRENTLY_PUTTING 0x800

/* libio fileops.c :: _IO_file_xsputn */
__attribute__((section(".text._IO_file_xsputn")))
_IO_size_t _IO_file_xsputn(struct _IO_FILE *f, const void *data, _IO_size_t n)
{
  register const char *s = (char *) data;
  _IO_size_t to_do = n;
  int must_flush = 0;
  _IO_size_t count;

  if (n <= 0)
    return 0;

  count = f->_IO_write_end - f->_IO_write_ptr;
  if ((f->_flags & _IO_LINE_BUF) && (f->_flags & _IO_CURRENTLY_PUTTING))
    {
      count = f->_IO_buf_end - f->_IO_write_ptr;
      if (count >= n)
	{
	  register const char *p;
	  for (p = s + n; p > s; )
	    {
	      if (*--p == '\n')
		{
		  count = p - s + 1;
		  must_flush = 1;
		  break;
		}
	    }
	}
    }
  if (count > 0)
    {
      if (count > to_do)
	count = to_do;
      if (count > 20)
	{
	  register char *q = f->_IO_write_ptr;
	  func_003A5148 (q, s, count);
	  s += count;
	}
      else
	{
	  register char *p = f->_IO_write_ptr;
	  register int i = (int) count;
	  while (--i >= 0)
	    *p++ = *s++;
	}
      f->_IO_write_ptr += count;
      to_do -= count;
    }
  if (to_do + must_flush > 0)
    {
      _IO_size_t block_size, dont_write;
      if (func_0038C3F0 (f, EOF) == EOF)
	return n - to_do;

      block_size = f->_IO_buf_end - f->_IO_buf_base;
      dont_write = block_size >= 128 ? to_do % block_size : 0;

      count = to_do - dont_write;
      if (_IO_do_write (f, s, count) == EOF)
	return n - to_do;
      to_do = dont_write;

      if (dont_write)
	to_do -= _IO_default_xsputn (f, s+count, dont_write);
    }
  return n - to_do;
}
