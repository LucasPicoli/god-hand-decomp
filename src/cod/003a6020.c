/* sn-2.95.3-136 matched TU. */

/* newlib libc/stdio/fflush.c -- fflush. */

extern int func_003A6830(void *ptr, int (*function)(void *));	/* _fwalk */
extern void func_003A61F0(void *ptr);				/* __sinit */
struct _reent;

struct __sbuf {
	unsigned char *_base;
	int	_size;
};

typedef struct __sFILE {
  unsigned char *_p;
  int	_r;
  int	_w;
  short	_flags;
  short	_file;
  struct __sbuf _bf;
  int	_lbfsize;

  void	*_cookie;
  int	(*_read)(void *_cookie, char *_buf, int _n);
  int	(*_write)(void *_cookie, const char *_buf, int _n);
  int	(*_seek)(void *_cookie, int _offset, int _whence);
  int	(*_close)(void *_cookie);

  struct __sbuf _ub;
  unsigned char *_up;
  int	_ur;

  unsigned char _ubuf[3];
  unsigned char _nbuf[1];

  struct __sbuf _lb;

  int	_blksize;
  int	_offset;

  struct _reent *_data;
} FILE;

struct _reent {
  char _pad0[0x38];
  int __sdidinit;
};

extern struct _reent *D_003FA62C;	/* _impure_ptr */
#define _REENT D_003FA62C

#define CHECK_INIT(fp) \
  do								\
    {								\
      if ((fp)->_data == 0)					\
	(fp)->_data = _REENT;					\
      if (!(fp)->_data->__sdidinit)				\
	func_003A61F0 ((fp)->_data);				\
    }								\
  while (0)

#define EOF (-1)
#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SWR  0x0008
#define __SERR 0x0040

__attribute__((section(".text.func_003A6020")))
int func_003A6020(register FILE *fp)
{
  register unsigned char *p;
  register int n, t;

  if (fp == 0)
    return func_003A6830 (_REENT, (int (*)(void *)) func_003A6020);

  CHECK_INIT (fp);

  t = fp->_flags;
  if ((t & __SWR) == 0)
    return 0;

  if ((p = fp->_bf._base) == 0)
    return 0;

  n = fp->_p - p;		/* write this much */

  /*
   * Set these immediately to avoid problems with longjmp
   * and to allow exchange buffering (via setvbuf) in user
   * write function.
   */
  fp->_p = p;
  fp->_w = t & (__SLBF | __SNBF) ? 0 : fp->_bf._size;

  while (n > 0)
    {
      t = (*fp->_write) (fp->_cookie, (char *) p, n);
      if (t <= 0)
	{
	  fp->_flags |= __SERR;
	  return EOF;
	}
      p += t;
      n -= t;
    }
  return 0;
}
