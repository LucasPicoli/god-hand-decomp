/* sn-2.95.3-136 matched TU. */

extern void __smakebuf(void *fp);

/* sn-2.95.3-136 matched TU. */



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
#define NULL 0
#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SRD  0x0004
#define __SWR  0x0008
#define __SRW  0x0010
#define __SEOF 0x0020

/* newlib libc/stdio/wsetup.c -- __swsetup. */
__attribute__((section(".text.__swsetup")))
int __swsetup(register FILE *fp)
{
    /* make sure stdio is set up */
    CHECK_INIT (fp);

    /*
     * If we are not writing, we had better be reading and writing.
     */
    if ((fp->_flags & __SWR) == 0) {
        if ((fp->_flags & __SRW) == 0) {
            return EOF;
        }
        if (fp->_flags & __SRD) {
            fp->_flags &= ~(__SRD | __SEOF);
            fp->_r = 0;
            fp->_p = fp->_bf._base;
        }
        fp->_flags |= __SWR;
    }

    /*
     * Make a buffer if necessary, then set _w.
     */
    if (fp->_bf._base == NULL) {
        __smakebuf (fp);
    }

    if (fp->_flags & __SLBF) {
        fp->_w = 0;
        fp->_lbfsize = -fp->_bf._size;
    } else {
        fp->_w = fp->_flags & __SNBF ? 0 : fp->_bf._size;
    }

    return 0;
}
