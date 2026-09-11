/* ee-2.9-991111 matched TU. */

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

struct _IO_marker {
    struct _IO_marker *_next;   /* 0x00 */
    struct _IO_FILE *_sbuf;     /* 0x04 */
    int _pos;                   /* 0x08 */
};

extern struct _IO_FILE *D_003F50F8;                 /* _IO_list_all */
extern void func_0038C768(struct _IO_FILE *f, char *b, char *eb, int a); /* _IO_setb */
extern int _IO_free_backup_area(struct _IO_FILE *fp);      /* _IO_free_backup_area */
extern void _IO_switch_to_main_get_area(struct _IO_FILE *fp);
extern void _IO_switch_to_backup_area(struct _IO_FILE *fp);
extern int _IO_switch_to_get_mode(struct _IO_FILE *fp);
extern int save_for_backup(struct _IO_FILE *fp);
extern int _IO_least_marker(struct _IO_FILE *fp);
extern void *func_003A7C70(unsigned int n);                       /* malloc */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *p);             /* free */
extern void *func_003A5148(void *d, const void *s, unsigned int n); /* memcpy */
extern void *func_003A51F4(void *d, const void *s, unsigned int n); /* memmove */
extern int __underflow(struct _IO_FILE *fp);      /* __underflow */

extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);                    /* __errno */
#define errno (*Obj0000_Get_D_003FA62C_3A4FB8())
#define EBADF 9
#define ESPIPE 29

extern void _IO_link_in(struct _IO_FILE *fp);
extern void _IO_un_link(struct _IO_FILE *fp);
extern void func_0038D140(struct _IO_FILE *fp);     /* _IO_unsave_markers */
extern void func_0038C7F0(struct _IO_FILE *fp);     /* _IO_doallocbuf */
extern void _IO_flush_all_linebuffered(void);
extern int _IO_do_write(struct _IO_FILE *fp, const char *data, _IO_size_t to_do);
extern int func_0038C3F0(struct _IO_FILE *f, int ch);   /* __overflow */
extern _IO_size_t _IO_default_xsputn(struct _IO_FILE *f, const void *data, _IO_size_t n);

extern const char D_0045D7E0[16];   /* blanks */
extern const char D_0045D7F0[16];   /* zeroes */

#define EOF (-1)
extern int func_0038C688(struct _IO_FILE *fp);                       /* __uflow */
extern int _IO_sputbackc(struct _IO_FILE *fp, int c);
extern void *func_003A4FC8(const void *s, int c, _IO_size_t n);      /* memchr */

/* libio iogetline.c :: _IO_getline_info */
__attribute__((section(".text._IO_getline_info")))
_IO_size_t _IO_getline_info(struct _IO_FILE *fp, char *buf, _IO_size_t n,
			    int delim, int extract_delim, int *eof)
{
  char *ptr = buf;
  if (eof) *eof = 0;
  while (n != 0)
    {
      _IO_ssize_t len = fp->_IO_read_end - fp->_IO_read_ptr;
      if (len <= 0)
	{
	  int c = func_0038C688 (fp);
	  if (c == EOF)
	    {
	      if (eof) *eof = c;
	      break;
	    }
	  if (c == delim)
	    {
	      if (extract_delim > 0)
		*ptr++ = c;
	      else if (extract_delim < 0)
		_IO_sputbackc (fp, c);
	      return ptr - buf;
	    }
	  *ptr++ = c;
	  n--;
	}
	else
	  {
	    char *t;
	    if ((_IO_size_t) len >= n)
	      len = n;
	    t = (char *) func_003A4FC8 ((void *) fp->_IO_read_ptr, delim, len);
	    if (t != 0)
	      {
		_IO_size_t old_len = ptr-buf;
		len = t - fp->_IO_read_ptr;
		if (extract_delim >= 0)
		  {
		    ++t;
		    if (extract_delim > 0)
		      ++len;
		  }
		func_003A5148 ((void *) ptr, (void *) fp->_IO_read_ptr, len);
		fp->_IO_read_ptr = t;
		return old_len + len;
	      }
	    func_003A5148 ((void *) ptr, (void *) fp->_IO_read_ptr, len);
	    fp->_IO_read_ptr += len;
	    ptr += len;
	    n -= len;
	  }
    }
  return ptr - buf;
}
