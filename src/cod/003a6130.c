/* sn-2.95.3-136 matched TU. */

/* newlib libc/stdio -- transcribed. */

extern void func_003A61F0(void *);	/* __sinit */

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


__attribute__((section(".text.func_003A6130")))
int func_003A6130(FILE *f)
{
  CHECK_INIT (f);
  return f->_file;
}
