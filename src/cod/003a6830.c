/* sn-2.95.3-136 matched TU. */

/* newlib libc/stdio -- transcribed. */


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


struct _glue {
  struct _glue *_next;
  int _niobs;
  FILE *_iobs;
};

struct _reent {
  char _pad0[0x1D8];
  struct _glue __sglue;
};


__attribute__((section(".text.func_003A6830")))
int func_003A6830(struct _reent *ptr, register int (*function)(FILE *))
{
  register FILE *fp;
  register int n, ret = 0;
  register struct _glue *g;

  for (g = &ptr->__sglue; g != 0; g = g->_next)
    for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
      if (fp->_flags != 0)
	ret |= (*function) (fp);

  return ret;
}
