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
extern int _IO_sputbackc(struct _IO_FILE *fp, int c);
extern void *func_003A4FC8(const void *s, int c, _IO_size_t n);      /* memchr */

/* libio iogetline.c :: _IO_getline_info */
__attribute__((section(".text._IO_getline_info")))
_IO_size_t _IO_getline_info(struct _IO_FILE *fp, char *buf, _IO_size_t n,
			    int delim, int extract_delim, int *eof)
{
  char *ptr = buf;
  if (eof) *eof = 0;
  while (n != 0)
    {
      _IO_ssize_t len = fp->_IO_read_end - fp->_IO_read_ptr;
      if (len <= 0)
	{
	  int c = func_0038C688 (fp);
	  if (c == EOF)
	    {
	      if (eof) *eof = c;
	      break;
	    }
	  if (c == delim)
	    {
	      if (extract_delim > 0)
		*ptr++ = c;
	      else if (extract_delim < 0)
		_IO_sputbackc (fp, c);
	      return ptr - buf;
	    }
	  *ptr++ = c;
	  n--;
	}
	else
	  {
	    char *t;
	    if ((_IO_size_t) len >= n)
	      len = n;
	    t = (char *) func_003A4FC8 ((void *) fp->_IO_read_ptr, delim, len);
	    if (t != 0)
	      {
		_IO_size_t old_len = ptr-buf;
		len = t - fp->_IO_read_ptr;
		if (extract_delim >= 0)
		  {
		    ++t;
		    if (extract_delim > 0)
		      ++len;
		  }
		func_003A5148 ((void *) ptr, (void *) fp->_IO_read_ptr, len);
		fp->_IO_read_ptr = t;
		return old_len + len;
	      }
	    func_003A5148 ((void *) ptr, (void *) fp->_IO_read_ptr, len);
	    fp->_IO_read_ptr += len;
	    ptr += len;
	    n -= len;
	  }
    }
  return ptr - buf;
}
