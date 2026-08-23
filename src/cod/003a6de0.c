/* sn-2.95.3-136 matched TU. */

/* newlib libc/stdio -- transcribed. */

extern long func_003AE008(void *, int, long, int);	/* _lseek_r */
extern long func_003AE128(void *, int, char const *, int);	/* _write_r */

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


#define __SOFF 0x1000
#define __SAPP 0x0100
#define SEEK_END 2

__attribute__((section(".text.__swrite")))
int __swrite(void *cookie, char const *buf, int n)
{
  register FILE *fp = (FILE *) cookie;

  if (fp->_flags & __SAPP)
    (void) func_003AE008 (fp->_data, fp->_file, (int) 0, SEEK_END);
  fp->_flags &= ~__SOFF;	/* in case FAPPEND mode is set */
  return func_003AE128 (fp->_data, fp->_file, buf, n);
}
