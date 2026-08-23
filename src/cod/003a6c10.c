/* sn-2.95.3-136 matched TU. */

extern int __srefill(void *);

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



#define EOF (-1)

__attribute__((section(".text.func_003A6C10")))
int func_003A6C10(register FILE *fp)
{
  if (__srefill (fp) == 0)
    {
      fp->_r--;
      return *fp->_p++;
    }
  return EOF;
}
