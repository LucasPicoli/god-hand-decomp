/* sn-2.95.3-136 matched TU. */

extern long __sseek(void *, long, int);

/* newlib libc/stdio/makebuf.c -- __smakebuf. */

extern int func_003ADFA8(void *, int, void *);	/* _fstat_r */


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
  long	(*_seek)(void *_cookie, long _offset, int _whence);
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

struct stat {
  unsigned char _pad0[4];
  unsigned int st_mode;
  unsigned char _pad1[104];
};

#define __SNBF 0x0002
#define __SOPT 0x0400
#define __SNPT 0x0800

#define S_IFMT	0170000
#define S_IFREG	0100000
#define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)

#define BUFSIZ 1024

__attribute__((section(".text.__smakebuf")))
void __smakebuf(register FILE *fp)
{
  struct stat st;

  if (fp->_flags & __SNBF)
    {
      fp->_bf._base = fp->_p = fp->_nbuf;
      fp->_bf._size = 1;
      return;
    }
  if (fp->_file < 0 || func_003ADFA8 (fp->_data, fp->_file, &st) < 0)
    {
      /* do not try to optimise fseek() */
      fp->_flags |= __SNPT;
    }
  else
    {
      if (S_ISREG (st.st_mode) && fp->_seek == __sseek)
	{
	  fp->_flags |= __SOPT;
	  fp->_blksize = BUFSIZ;
	}
      else
	fp->_flags |= __SNPT;
    }

  fp->_flags |= __SNBF;
  fp->_bf._base = fp->_p = fp->_nbuf;
  fp->_bf._size = 1;
}
