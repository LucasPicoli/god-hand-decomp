/* sn-2.95.3-136 matched TU. */

extern int write(int fd, const void *buf, int n);

/* sn-2.95.3-136 matched TU. */

/* newlib libc/stdio/ungetc.c -- ungetc.
 * This build replaces __submore with a diagnostic write(); the static
 * ungetc buffer is never grown. */

extern void func_003A61F0(void *ptr);		/* __sinit */
extern int func_003A6020(void *fp);		/* fflush */

extern char D_0045FC90[];			/* the overflow message */

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
#define __SRD  0x0004
#define __SWR  0x0008
#define __SRW  0x0010
#define __SEOF 0x0020

#define HASUB(fp) ((fp)->_ub._base != 0)

__attribute__((section(".text.func_003AE598")))
int func_003AE598(int c, register FILE *fp)
{
  if (c == EOF)
    return EOF;

  CHECK_INIT (fp);

  /* Try to fix up the file descriptor for reading. */
  fp->_flags &= ~__SEOF;
  if ((fp->_flags & __SRD) == 0)
    {
      /*
       * Not already reading: no good unless reading-and-writing.
       * Otherwise, flush any current write stuff.
       */
      if ((fp->_flags & __SRW) == 0)
	return EOF;
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

  c = (unsigned char) c;

  /*
   * If we are in the middle of ungetc'ing, just continue.
   * The static buffer cannot grow, so report and fail instead.
   */
  if (HASUB (fp))
    {
      if (fp->_r >= fp->_ub._size)
	{
	  write (1, D_0045FC90, 0x44);
	  return EOF;
	}
      *--fp->_p = c;
      fp->_r++;
      return c;
    }

  /*
   * If we can handle this by simply backing up, do so, but never
   * replace the original character.
   */
  if (fp->_bf._base != 0 && fp->_p > fp->_bf._base && fp->_p[-1] == c)
    {
      fp->_p--;
      fp->_r++;
      return c;
    }

  /*
   * Create an ungetc buffer.
   * Initially, we will use the `reserve' buffer.
   */
  fp->_ur = fp->_r;
  fp->_up = fp->_p;
  fp->_ub._base = fp->_ubuf;
  fp->_ub._size = sizeof (fp->_ubuf);
  fp->_ubuf[sizeof (fp->_ubuf) - 1] = c;
  fp->_p = &fp->_ubuf[sizeof (fp->_ubuf) - 1];
  fp->_r = 1;
  return c;
}

/* newlib mprec __multadd (0x003AE8F8). */
typedef struct _Bigint {
    struct _Bigint *_next;
    int _k;
    int _maxwds;
    int _sign;
    int _wds;
    unsigned int _x[1];
} _Bigint;

extern _Bigint *func_003AE818(void *ptr, int k);            /* _Balloc */
extern void func_003AE8C0(void *ptr, _Bigint *v);           /* _Bfree  */
extern void *func_003A5148(void *d, const void *s, int n);  /* memcpy  */

__attribute__((section(".text.func_003AE8F8")))
_Bigint *func_003AE8F8(void *ptr, _Bigint *b, int m, int a)
{
    int i, wds;
    unsigned int *x, y;
    unsigned int xi, z;
    _Bigint *b1;

    wds = b->_wds;
    x = b->_x;
    i = 0;
    do {
        xi = *x;
        y = (xi & 0xffff) * m + a;
        z = (xi >> 16) * m + (y >> 16);
        a = (int)(z >> 16);
        *x++ = (z << 16) + (y & 0xffff);
    } while (++i < wds);
    if (a) {
        if (wds >= b->_maxwds) {
            b1 = func_003AE818(ptr, b->_k + 1);
            func_003A5148((char *)&b1->_sign, (char *)&b->_sign,
                          b->_wds * sizeof(unsigned int) + 2 * sizeof(int));
            func_003AE8C0(ptr, b);
            b = b1;
        }
        b->_x[wds++] = a;
        b->_wds = wds;
    }
    return b;
}
