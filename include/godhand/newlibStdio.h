/* include/godhand/newlibStdio.h - newlib stdio: FILE, struct _reent and the stdio entry points (sn code at 0x3A5F68..).
 *
 * Names are newlib's; offsets are exact.
 */
#ifndef GODHAND_NEWLIBSTDIO_H
#define GODHAND_NEWLIBSTDIO_H

typedef unsigned int size_t;

struct _reent;

struct __sbuf {
    unsigned char *_base;
    int _size;
};

typedef struct __sFILE {
    unsigned char *_p;          /* 0x00 */
    int _r;                     /* 0x04 */
    int _w;                     /* 0x08 */
    short _flags;               /* 0x0C */
    short _file;                /* 0x0E */
    struct __sbuf _bf;          /* 0x10 */
    int _lbfsize;               /* 0x18 */

    void *_cookie;              /* 0x1C */
    int (*_read)(void *_cookie, char *_buf, int _n);            /* 0x20 */
    int (*_write)(void *_cookie, const char *_buf, int _n);     /* 0x24 */
    long (*_seek)(void *_cookie, long _offset, int _whence);    /* 0x28 */
    int (*_close)(void *_cookie);                               /* 0x2C */

    struct __sbuf _ub;          /* 0x30 */
    unsigned char *_up;         /* 0x38 */
    int _ur;                    /* 0x3C */

    unsigned char _ubuf[3];     /* 0x40 */
    unsigned char _nbuf[1];     /* 0x43 */

    struct __sbuf _lb;          /* 0x44 */

    int _blksize;               /* 0x4C */
    int _offset;                /* 0x50 */

    struct _reent *_data;       /* 0x54 */
} FILE;

struct _glue {
    struct _glue *_next;
    int _niobs;
    FILE *_iobs;
};

#define _ATEXIT_SIZE 32

struct _atexit {
    struct _atexit *_next;
    int _ind;
    void (*_fns[_ATEXIT_SIZE])(void);
};

struct _reent {
    int _errno;                         /* 0x000 */
    FILE *_stdin;                       /* 0x004 */
    FILE *_stdout;                      /* 0x008 */
    FILE *_stderr;                      /* 0x00C */
    int _inc;                           /* 0x010 */
    char _emergency[25];                /* 0x014 */
    int _current_category;              /* 0x030 */
    const char *_current_locale;        /* 0x034 */
    int __sdidinit;                     /* 0x038 */
    void (*__cleanup)(struct _reent *); /* 0x03C */
    char unk40[0x108];                  /* 0x040: Bigint cache, cvt buffer, the _new union */
    struct _atexit *_atexit;            /* 0x148 */
    struct _atexit _atexit0;            /* 0x14C */
    void (**_sig_func)(int);            /* 0x1D4 */
    struct _glue __sglue;               /* 0x1D8 */
    FILE __sf[3];                       /* 0x1E4 */
};

extern struct _reent *D_003FA62C;       /* _impure_ptr */
#define _REENT D_003FA62C

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define __SLBF 0x0001   /* line buffered */
#define __SNBF 0x0002   /* unbuffered */
#define __SRD  0x0004   /* OK to read */
#define __SWR  0x0008   /* OK to write */
#define __SRW  0x0010   /* open for reading & writing */
#define __SEOF 0x0020   /* found EOF */
#define __SERR 0x0040   /* found error */
#define __SMBF 0x0080   /* _buf is from malloc */
#define __SAPP 0x0100   /* fdopen()ed in append mode */
#define __SSTR 0x0200   /* this is an sprintf/snprintf string */
#define __SOPT 0x0400   /* do fseek() optimisation */
#define __SNPT 0x0800   /* do not do fseek() optimisation */
#define __SOFF 0x1000   /* set iff _offset is in fact correct */
#define __SMOD 0x2000   /* true => fgetln modified _p text */

#define HASUB(fp) ((fp)->_ub._base != 0)

/* The parts of struct stat that _fstat_r fills and stdio reads. */
struct stat {
    char unk0[4];
    unsigned int st_mode;       /* 0x04 */
    char unk8[8];
    long st_size;               /* 0x10 */
    char unk18[88];
};

#define S_IFMT  0170000
#define S_IFREG 0100000
#define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)

struct __siov {
    const void *iov_base;
    size_t iov_len;
};

struct __suio {
    struct __siov *uio_iov;
    int uio_iovcnt;
    int uio_resid;
};

void func_003A61F0(int a0);                                          /* __sinit, as defined in 0014ea28.c */
int func_003A6290(int a0);                                           /* _cleanup_r, as defined in 00150048.c */

/* Run __sinit on the stream's reent block the first time it is used. */
#define CHECK_INIT(fp) \
  do                                    \
    {                                   \
      if ((fp)->_data == 0)             \
        (fp)->_data = _REENT;           \
      if (!(fp)->_data->__sdidinit)     \
        func_003A61F0 ((fp)->_data);    \
    }                                   \
  while (0)

int fflush(FILE *fp);
int func_003A6A88(int a0, int a1, int a2, int a3);                   /* lflush, as defined in 00150078.c */
int func_003A6830(struct _reent *ptr, int (*function)(FILE *));     /* _fwalk */
void __smakebuf(FILE *fp);
int __srefill(FILE *fp);
int func_003A6C10(FILE *fp);
int __swsetup(FILE *fp);
int __sfvwrite(FILE *fp, struct __suio *uio);
int __sread(void *cookie, char *buf, int n);
int __swrite(void *cookie, const char *buf, int n);
long __sseek(void *cookie, long offset, int whence);
int func_003A6EC8(void *cookie);                                    /* __sclose */
size_t func_003A6308(void *buf, size_t size, size_t count, FILE *fp);   /* fread */
int func_003AE598(int c, FILE *fp);                                 /* ungetc */
int __svfscanf(FILE *fp, const char *fmt0, char *ap);              /* ap: the caller's va_list */

#endif /* GODHAND_NEWLIBSTDIO_H */
