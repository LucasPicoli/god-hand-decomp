/* sn-2.95.3-136 matched TU. */

/* newlib libc/stdio -- transcribed. */

extern void *func_003A7C70(unsigned int);	/* malloc */

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


#define _ATEXIT_SIZE 32

struct _atexit {
  struct _atexit *_next;
  int _ind;
  void (*_fns[_ATEXIT_SIZE])(void);
};

struct _reent {
  char _pad0[0x148];
  struct _atexit *_atexit;
  struct _atexit _atexit0;
};

extern struct _reent *D_003FA62C;	/* _impure_ptr */
#define _REENT D_003FA62C


__attribute__((section(".text.func_003A7B88")))
int func_003A7B88(void (*fn)(void))
{
  register struct _atexit *p;

  if ((p = _REENT->_atexit) == 0)
    _REENT->_atexit = p = &_REENT->_atexit0;
  if (p->_ind >= _ATEXIT_SIZE)
    {
      if ((p = (struct _atexit *) func_003A7C70 (sizeof *p)) == 0)
	return -1;
      p->_ind = 0;
      do { } while (0);
      *(struct _atexit * volatile *) &p->_next = _REENT->_atexit;
      do { } while (0);
      _REENT->_atexit = p;
    }
  p->_fns[p->_ind++] = fn;
  return 0;
}
