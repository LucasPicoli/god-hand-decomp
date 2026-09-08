/* ee-2.9-991111 matched TU. */

typedef unsigned int _IO_size_t;
typedef long _IO_ssize_t;
typedef long _IO_pos_t;

struct _IO_FILE;
struct _IO_marker;

typedef int (*_IO_fn)();
typedef long (*_IO_lfn)();
typedef long (*_IO_rw_fn)(struct _IO_FILE *, void *, _IO_ssize_t);
typedef long (*_IO_seek_fn)(struct _IO_FILE *, _IO_ssize_t, int);

struct _IO_jumpent { short d1; short d2; _IO_fn pfn; };
struct _IO_ljumpent { short d1; short d2; _IO_lfn pfn; };
struct _IO_rwent { short d1; short d2; _IO_rw_fn pfn; };
struct _IO_seekent { short d1; short d2; _IO_seek_fn pfn; };

struct _IO_jump_t {
    struct _IO_jumpent  __dummy;      /* 0x00 */
    struct _IO_jumpent  __finish;     /* 0x08 */
    struct _IO_jumpent  __overflow;   /* 0x10 */
    struct _IO_jumpent  __underflow;  /* 0x18 */
    struct _IO_jumpent  __uflow;      /* 0x20 */
    struct _IO_jumpent  __pbackfail;  /* 0x28 */
    struct _IO_jumpent  __xsputn;     /* 0x30 */
    struct _IO_jumpent  __xsgetn;     /* 0x38 */
    struct _IO_ljumpent __seekoff;    /* 0x40 */
    struct _IO_ljumpent __seekpos;    /* 0x48 */
    struct _IO_jumpent  __setbuf;     /* 0x50 */
    struct _IO_jumpent  __sync;       /* 0x58 */
    struct _IO_jumpent  __doallocate; /* 0x60 */
    struct _IO_rwent    __read;       /* 0x68 */
    struct _IO_rwent    __write;      /* 0x70 */
    struct _IO_seekent  __seek;       /* 0x78 */
    struct _IO_jumpent  __close;      /* 0x80 */
    struct _IO_jumpent  __stat;       /* 0x88 */
};

struct _IO_FILE {
    int _flags;                      /* 0x00 */
    char *_IO_read_ptr;              /* 0x04 */
    char *_IO_read_end;              /* 0x08 */
    char *_IO_read_base;             /* 0x0C */
    char *_IO_write_base;            /* 0x10 */
    char *_IO_write_ptr;             /* 0x14 */
    char *_IO_write_end;             /* 0x18 */
    char *_IO_buf_base;              /* 0x1C */
    char *_IO_buf_end;               /* 0x20 */
    char *_IO_save_base;             /* 0x24 */
    char *_IO_backup_base;           /* 0x28 */
    char *_IO_save_end;              /* 0x2C */
    struct _IO_marker *_markers;     /* 0x30 */
    struct _IO_FILE *_chain;         /* 0x34 */
    int _fileno;                     /* 0x38 */
    int _blksize;                    /* 0x3C */
    _IO_pos_t _offset;               /* 0x40 */
    unsigned short _cur_column;      /* 0x48 */
    signed char _vtable_offset;      /* 0x4A */
    char _shortbuf[1];               /* 0x4B */
    void *_lock;                     /* 0x4C */
    struct _IO_jump_t *vtable;       /* 0x50 */
};
extern void *func_003A5148(void *dst, const void *src, _IO_size_t n); /* memcpy */
extern int func_0038C3F0(struct _IO_FILE *f, int ch);                 /* __overflow */

/* libio genops.c :: _IO_default_xsputn */
__attribute__((section(".text._IO_default_xsputn")))
_IO_size_t _IO_default_xsputn(struct _IO_FILE *f, const void *data, _IO_size_t n) {
    const char *s = (char *) data;
    _IO_size_t more = n;
    if (more <= 0)
        return 0;
    for (;;) {
        _IO_ssize_t count = f->_IO_write_end - f->_IO_write_ptr;
        if (count > 0) {
            if ((_IO_size_t) count > more)
                count = more;
            if (count > 20) {
                func_003A5148(f->_IO_write_ptr, s, count);
                s += count;
                f->_IO_write_ptr += count;
            } else if (count <= 0)
                count = 0;
            else {
                char *p = f->_IO_write_ptr;
                _IO_ssize_t i;
                for (i = count; --i >= 0; )
                    *p++ = *s++;
                f->_IO_write_ptr = p;
            }
            more -= count;
        }
        if (more == 0 || func_0038C3F0(f, (unsigned char) *s++) == -1)
            break;
        more--;
    }
    return n - more;
}

/* libio iovfscanf.c :: __sccl
 * donor: sce_crt_libstdcxx/iovfscanf.o :: __sccl (1.000 exact)
 */
typedef unsigned char u_char;

__attribute__((section(".text.func_0038E030")))
char *func_0038E030(char *tab, const u_char *fmt) {
    register int c, n, v;

    /* first `clear' the whole table */
    c = *fmt++;         /* first char hat => negated scanset */
    if (c == '^') {
        v = 1;          /* default => accept */
        c = *fmt++;     /* get new first char */
    } else
        v = 0;          /* default => reject */
    /* should probably use memset here */
    for (n = 0; n < 256; n++)
        tab[n] = v;
    if (c == 0)
        return (char *) (fmt - 1); /* format ended before closing ] */

    v = 1 - v;
    for (;;) {
        tab[c] = v;             /* take character c */
    doswitch:
        n = *fmt++;             /* and examine the next */
        switch (n) {

        case 0:                 /* format ended too soon */
            return (char *) (fmt - 1);

        case '-':
            n = *fmt;
            if (n == ']' || n < c) {
                c = '-';
                break;          /* resume the for(;;) */
            }
            fmt++;
            do {                /* fill in the range */
                tab[++c] = v;
            } while (c < n);
            goto doswitch;

        case ']':               /* end of scanset */
            return (char *) fmt;

        default:                /* just another character */
            c = n;
            break;
        }
    }
    /* NOTREACHED */
}
