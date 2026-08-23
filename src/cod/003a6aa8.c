/* sn-2.95.3-136 matched TU. */

extern void __smakebuf(void *fp);

/* newlib libc/stdio/refill.c -- __srefill. */

extern void func_003A61F0(void *ptr);			/* __sinit */
extern int func_003A6020(void *fp);			/* fflush */
extern int func_003A6A88(void *fp);			/* lflush */
extern int func_003A6830(void *ptr, int (*function)(void *));	/* _fwalk */


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
#define __SRD  0x0004
#define __SWR  0x0008
#define __SRW  0x0010
#define __SEOF 0x0020
#define __SERR 0x0040
#define __SMOD 0x2000

#define HASUB(fp) ((fp)->_ub._base != 0)

__attribute__((section(".text.__srefill")))
int __srefill(register FILE *fp)
{
  CHECK_INIT (fp);

  fp->_r = 0;			/* largely a convenience for callers */

  /* SysV does not make this test; take it out for compatibility */
  if (fp->_flags & __SEOF)
    return EOF;

  /* if not already reading, have to be reading and writing */
  if ((fp->_flags & __SRD) == 0)
    {
      if ((fp->_flags & __SRW) == 0)
	return EOF;
      /* switch to reading */
      if (fp->_flags & __SWR)
	{
	  if (func_003A6020 (fp))
	    return EOF;
	  fp->_flags &= ~__SWR;
	  fp->_w = 0;
	  fp->_lbfsize = 0;
	}
      fp->_flags |= __SRD;
    }
  else
    {
      /*
       * We were reading.  If there is an ungetc buffer,
       * we must have been reading from that.  Drop it,
       * restoring the previous buffer (if any).  If there
       * is anything in that buffer, return.
       */
      if (HASUB (fp))
	{
	  if ((fp->_r = fp->_ur) != 0)
	    {
	      fp->_p = fp->_up;
	      return 0;
	    }
	}
    }

  if (fp->_bf._base == 0)
    __smakebuf (fp);

  /*
   * Before reading from a line buffered or unbuffered file,
   * flush all line buffered output files, per the ANSI C
   * standard.
   */
  if (fp->_flags & (__SLBF | __SNBF))
    (void) func_003A6830 (fp->_data, func_003A6A88);
  fp->_p = fp->_bf._base;
  fp->_r = (*fp->_read) (fp->_cookie, (char *) fp->_p, fp->_bf._size);
  fp->_flags &= ~__SMOD;	/* buffer contents are again pristine */
  if (fp->_r <= 0)
    {
      if (fp->_r == 0)
	fp->_flags |= __SEOF;
      else
	{
	  fp->_r = 0;
	  fp->_flags |= __SERR;
	}
      return EOF;
    }
  return 0;
}
