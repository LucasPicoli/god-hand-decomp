/* include/godhand/libio.h - the libio records the ee-2.9 stdio units share.
 *
 * _IO_FILE is the 0x54-byte stream: the get, put and reserve areas, the
 * backup area, the marker list, the list link, the file number, the 64-bit
 * offset and the jump table at 0x50. EE `long` is 64 bit, so _IO_ssize_t
 * and _IO_pos_t are too. An _IO_marker records a position in a stream.
 */
#ifndef GODHAND_LIBIO_H
#define GODHAND_LIBIO_H

/* _IO_FILE._flags bits. */
#define _IO_LINKED     0x80     /* on _IO_list_all */
#define _IO_IN_BACKUP  0x100    /* the get area is the backup area */

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

struct _IO_marker {
    struct _IO_marker *_next;   /* 0x00 */
    struct _IO_FILE *_sbuf;     /* 0x04 */
    int _pos;                   /* 0x08 */
};

extern struct _IO_FILE *D_003F50F8;     /* _IO_list_all */

/* Leave put mode: flush pending output and make the get area current. */
int _IO_switch_to_get_mode(struct _IO_FILE *fp);
/* Copy n bytes of data into the put area, overflowing as it fills; the count written. */
_IO_size_t _IO_default_xsputn(struct _IO_FILE *f, const void *data, _IO_size_t n);
/* Write to_do bytes of data through the jump table and reset the put area. */
int _IO_do_write(struct _IO_FILE *fp, const char *data, _IO_size_t to_do);
/* __overflow: hand ch to the stream's overflow entry. */
int func_0038C3F0(struct _IO_FILE *f, int ch);
/* _IO_doallocbuf: give the stream a buffer unless it has one. */
void func_0038C7F0(struct _IO_FILE *fp);
/* __uflow: the next character, moving the get pointer past it. */
int func_0038C688(struct _IO_FILE *fp);
/* _IO_ungetc. */
int func_0038EAB0(int c, struct _IO_FILE *fp);
/* The next character without moving the get pointer; EOF at the end. */
int __underflow(struct _IO_FILE *fp);
/* Copy the get area from the oldest marker into the backup area; 0, or EOF when out of memory. */
int save_for_backup(struct _IO_FILE *fp);
/* Put the stream at the head of _IO_list_all unless it is linked already. */
void _IO_link_in(struct _IO_FILE *fp);
/* Take the stream out of _IO_list_all when it is linked. */
void _IO_un_link(struct _IO_FILE *fp);
/* Put c in the put area, or hand it to __overflow when the area is full. */
int _IO_putc(int c, struct _IO_FILE *fp);

#endif
