/* sn-2.95.3-136 matched TU. */

extern int __sfvwrite(void *, void *);

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


struct __siov {
	void	*_iov_base;
	int	_iov_len;
};
struct __suio {
	struct	__siov *uio_iov;
	int	uio_iovcnt;
	int	uio_resid;
};


__attribute__((section(".text.func_003A68C8")))
unsigned int func_003A68C8(const void *buf, unsigned int size, unsigned int count, FILE *fp)
{
  unsigned int n;
  struct __suio uio;
  struct __siov iov;

  iov._iov_base = (void *) buf;
  uio.uio_resid = iov._iov_len = n = count * size;
  uio.uio_iov = &iov;
  uio.uio_iovcnt = 1;

  /*
   * The usual case is success (__sfvwrite returns 0);
   * skip the divide if this happens, since divides are
   * generally slow and since this occurs whenever size==0.
   */

  if (__sfvwrite (fp, &uio) == 0)
    return count;
  return (n - uio.uio_resid) / size;
}
