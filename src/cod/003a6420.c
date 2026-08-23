/* sn-2.95.3-136 matched TU. */

extern int __srefill(void *fp);
extern void __smakebuf(void *fp);
extern long __sseek(void *cookie, long offset, int whence);

/* newlib libc/stdio/fseek.c -- fseek. */

extern void func_003A61F0(void *ptr);			/* __sinit */
extern int func_003A6020(void *fp);			/* fflush */
extern int func_003ADFA8(void *ptr, int fd, void *st);	/* _fstat_r */




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

struct _reent {
  int	_errno;
  char	_pad0[0x34];
  int	__sdidinit;
};

struct stat {
  unsigned char _pad0[4];
  unsigned int st_mode;
  unsigned char _pad1[8];
  long	st_size;
  unsigned char _pad2[88];
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

typedef unsigned int size_t;

#define EOF (-1)
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define ESPIPE 29
#define EINVAL 22

#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SRD  0x0004
#define __SWR  0x0008
#define __SRW  0x0010
#define __SEOF 0x0020
#define __SAPP 0x0100
#define __SOPT 0x0400
#define __SNPT 0x0800
#define __SOFF 0x1000
#define __SMOD 0x2000

#define S_IFMT	0170000
#define S_IFREG	0100000

#define HASUB(fp) ((fp)->_ub._base != 0)

__attribute__((section(".text.func_003A6420")))
int func_003A6420(register FILE *fp, long offset, int whence)
{
  register struct _reent *ptr;
  long (*seekfn)(void *, long, int);
  long target;
  long curoff;
  size_t n;
  struct stat st;
  int havepos;

  /* Make sure stdio is set up.  */

  CHECK_INIT (fp);
  ptr = fp->_data;

  /* If we've been doing some writing, and we're in append mode
     then we don't really know where the filepos is.  */

  if (fp->_flags & __SAPP && fp->_flags & __SWR)
    {
      /* So flush the buffer and seek to the end.  */
      func_003A6020 (fp);
    }

  /* Have to be able to seek.  */

  if ((seekfn = fp->_seek) == 0)
    {
      ptr->_errno = ESPIPE;	/* ??? */
      return EOF;
    }

  /*
   * Change any SEEK_CUR to SEEK_SET, and check `whence' argument.
   * After this, whence is either SEEK_SET or SEEK_END.
   */

  switch (whence)
    {
    case SEEK_CUR:
      /*
       * In order to seek relative to the current stream offset,
       * we have to first find the current stream offset a la
       * ftell (see ftell for details).
       */
      func_003A6020 (fp);	/* may adjust seek offset on append stream */
      if (fp->_flags & __SOFF)
	curoff = fp->_offset;
      else
	{
	  curoff = (*seekfn) (fp->_cookie, (long) 0, SEEK_CUR);
	  if (curoff == -1L)
	    return EOF;
	}
      if (fp->_flags & __SRD)
	{
	  curoff -= fp->_r;
	  if (HASUB (fp))
	    curoff -= fp->_ur;
	}
      else if (fp->_flags & __SWR && fp->_p != 0)
	curoff += fp->_p - fp->_bf._base;

      offset += curoff;
      whence = SEEK_SET;
      havepos = 1;
      break;

    case SEEK_SET:
    case SEEK_END:
      havepos = 0;
      break;

    default:
      ptr->_errno = EINVAL;
      return EOF;
    }

  /*
   * Can only optimise if:
   *	reading (and not reading-and-writing);
   *	not unbuffered; and
   *	this is a `regular' Unix file (and hence seekfn==__sseek).
   * We must check __NBF first, because it is possible to have __NBF
   * and __SOPT both set.
   */

  if (fp->_bf._base == 0)
    __smakebuf (fp);
  if (fp->_flags & (__SWR | __SRW | __SNBF | __SNPT))
    goto dumb;
  if ((fp->_flags & __SOPT) == 0)
    {
      if (seekfn != __sseek
	  || fp->_file < 0
	  || func_003ADFA8 (ptr, fp->_file, &st)
	  || (st.st_mode & S_IFMT) != S_IFREG)
	{
	  fp->_flags |= __SNPT;
	  goto dumb;
	}
      fp->_blksize = 1024;
      fp->_flags |= __SOPT;
    }

  /*
   * We are reading; we can try to optimise.
   * Figure out where we are going and where we are now.
   */

  if (whence == SEEK_SET)
    target = offset;
  else
    {
      if (func_003ADFA8 (ptr, fp->_file, &st))
	goto dumb;
      target = st.st_size + offset;
    }

  if (!havepos)
    {
      if (fp->_flags & __SOFF)
	curoff = fp->_offset;
      else
	{
	  curoff = (*seekfn) (fp->_cookie, (long) 0, SEEK_CUR);
	  if (curoff == -1L)
	    goto dumb;
	}
      curoff -= fp->_r;
      if (HASUB (fp))
	curoff -= fp->_ur;
    }

  /*
   * Compute the number of bytes in the input buffer (pretending
   * that any ungetc() input has been discarded).  Adjust current
   * offset backwards by this count so that it represents the
   * file offset for the first byte in the current input buffer.
   */

  if (HASUB (fp))
    {
      curoff += fp->_r;		/* kill off ungetc */
      n = fp->_up - fp->_bf._base;
      curoff -= n;
      n += fp->_ur;
    }
  else
    {
      n = fp->_p - fp->_bf._base;
      curoff -= n;
      n += fp->_r;
    }

  /*
   * If the target offset is within the current buffer,
   * simply adjust the pointers, clear EOF, undo ungetc(),
   * and return.
   */

  if ((fp->_flags & __SMOD) == 0 && target >= curoff && target < curoff + n)
    {
      register int o = target - curoff;

      fp->_p = fp->_bf._base + o;
      fp->_r = n - o;
      fp->_flags &= ~__SEOF;
      return 0;
    }

  /*
   * The place we want to get to is not within the current buffer,
   * but we can still be kind to the kernel copyout mechanism.
   * By aligning the file offset to a block boundary, we can let
   * the kernel use the VM hardware to map pages instead of
   * copying bytes laboriously.  Using a block boundary also
   * ensures that we only read one block, rather than two.
   */

  curoff = target & ~(fp->_blksize - 1);
  if ((*seekfn) (fp->_cookie, curoff, SEEK_SET) == -1L)
    goto dumb;
  fp->_r = 0;
  fp->_flags &= ~__SEOF;
  n = target - curoff;
  if (n)
    {
      if (__srefill (fp) || fp->_r < n)
	goto dumb;
      fp->_p += n;
      fp->_r -= n;
    }
  return 0;

  /*
   * We get here if we cannot optimise the seek ... just
   * do it.  Allow the seek function to change fp->_bf._base.
   */

dumb:
  if (func_003A6020 (fp) || (*seekfn) (fp->_cookie, offset, whence) == -1L)
    return EOF;
  /* success: clear EOF indicator and discard ungetc() data */
  fp->_p = fp->_bf._base;
  fp->_r = 0;
  fp->_flags &= ~__SEOF;
  return 0;
}
