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
#define _IO_LEFT 02
#define _IO_RIGHT 04
#define _IO_INTERNAL 010
#define _IO_SHOWPOINT 0400

extern int _IO_putc(int c, struct _IO_FILE *fp);
extern _IO_ssize_t _IO_padn(struct _IO_FILE *fp, int pad, _IO_ssize_t count);
extern char *_IO_dtoa(double d, int mode, int ndigits, int *decpt,
			   int *sign, char **rve);            /* _IO_dtoa */

#define _IO_sputn(__fp, __s, __n) ((*(__fp)->vtable->__xsputn.pfn)(__fp, __s, __n))

/* libio outfloat.c :: _IO_outfloat */
__attribute__((section(".text._IO_outfloat")))
int _IO_outfloat (double value, struct _IO_FILE *sb, int type, int width,
		  int precision, int flags, int sign_mode, int fill)
{
  int count = 0;
#define PUT(x) do {if (_IO_putc(x, sb) < 0) goto error; count++;} while (0)
#define PUTN(p, n) \
  do {int _n=n; count+=_n; if (_IO_sputn(sb, p,_n) != _n) goto error;} while(0)
#define PADN(fill, n) \
  do {int _n = n; count+=_n; if (_IO_padn(sb, fill, _n) != _n) goto error;} while (0)
  int pad_kind = flags & (_IO_LEFT|_IO_RIGHT|_IO_INTERNAL);
  int skip_zeroes = 0;
  int show_dot = (flags & _IO_SHOWPOINT) != 0;
  int decpt;
  int sign;
  int mode;
  int exponent_size;
  int print_sign;
  int trailing_zeroes, useful_digits;
  int padding, unpadded_width;
  char *p;
  char *exponent_start;
  register int i;
#define EBUF_SIZE 12
#define EBUF_END &ebuf[EBUF_SIZE]
  char ebuf[EBUF_SIZE];
  char *end;
  int exp = 0;
  switch (type)
    {
    case 'f':
      mode = 3;
      break;
    case 'e':
    case 'E':
      exp = type;
      mode = 2;
      if (precision != 999)
	precision++;  /* Add one to include digit before decimal point. */
      break;
    case 'g':
    case 'G':
      exp = type == 'g' ? 'e' : 'E';
      if (precision == 0) precision = 1;
      if (!(flags & _IO_SHOWPOINT))
	skip_zeroes = 1;
      type = 'g';
      mode = 2;
      break;
    }
  /* Do the actual convension */
  if (precision == 999 && mode != 3)
    mode = 0;
  p = _IO_dtoa(value, mode, precision, &decpt, &sign, &end);
  useful_digits = end-p;
  exponent_start = EBUF_END;
  if (mode == 0)
    precision = useful_digits;
  /* Check if we need to emit an exponent. */
  if (mode != 3 && decpt != 9999)
    {
      i = decpt - 1;
      if ((type != 'g' && type != 'F') || i < -4 || i >= precision)
	{
	  /* Print the exponent into ebuf.
	     We write ebuf in reverse order (right-to-left). */
	  char sign;
	  if (i >= 0)
	    sign = '+';
	  else
	    sign = '-', i = -i;
	  /* Note: ANSI requires at least 2 exponent digits. */
	  do {
	    *--exponent_start = (i % 10) + '0';
	    i /= 10;
	  } while (i >= 10);
	  *--exponent_start = i + '0';
	  *--exponent_start = sign;
	  *--exponent_start = exp;
	}
    }
  exponent_size = EBUF_END - exponent_start;
  if (mode == 1)
    precision = 1;
  /* If we print an exponent, always show just one digit before point. */
  if (exponent_size)
    decpt = 1;
  if (decpt == 9999)
    { /* Infinity or NaN */
      decpt = useful_digits;
      precision = 0;
      show_dot = 0;
    }

  if (skip_zeroes)
    trailing_zeroes = 0;
  else if (type == 'f')
    trailing_zeroes = useful_digits <= decpt ? precision
      : precision-(useful_digits-decpt);
  else if (exponent_size) /* 'e' 'E' or 'g' format using exponential notation*/
    trailing_zeroes = precision - useful_digits;
  else /* 'g' format not using exponential notation. */
    trailing_zeroes = useful_digits <= decpt ? precision - decpt
      : precision-useful_digits;
  if (trailing_zeroes < 0) trailing_zeroes = 0;

  if (trailing_zeroes != 0 || useful_digits > decpt)
    show_dot = 1;
  if (sign_mode == 0)
    print_sign = sign ? '-' : 0;
  else if (sign_mode == '+')
    print_sign = sign ? '-' : '+';
  else /* if (sign_mode == ' ') */
    print_sign = sign ? '-' : ' ';

  /* Calculate the width (before padding). */
  unpadded_width =
    (print_sign != 0) + trailing_zeroes + exponent_size + show_dot
      + useful_digits
	+ (decpt > useful_digits ? decpt - useful_digits
	   : decpt > 0 ? 0 : 1 - decpt);

  padding = width > unpadded_width ? width - unpadded_width : 0;
  if (padding > 0 && pad_kind != _IO_LEFT && pad_kind != _IO_INTERNAL)
    PADN(fill, padding); /* Default (right) adjust */
  if (print_sign)
    PUT(print_sign);
  if (pad_kind == _IO_INTERNAL && padding > 0)
    PADN(fill, padding);
  if (decpt > 0)
    {
      if (useful_digits >= decpt)
	PUTN(p, decpt);
      else
	{
	  PUTN(p, useful_digits);
	  PADN('0', decpt-useful_digits);
	}
      if (show_dot)
	{
	  PUT('.');
	  /* Print digits after the decimal point. */
	  if (useful_digits > decpt)
	    PUTN(p + decpt, useful_digits-decpt);
	}
    }
  else
    {
      PUT('0');
      if (show_dot)
	{
	  PUT('.');
	  PADN('0', -decpt);
	  /* Print digits after the decimal point. */
	  PUTN(p, useful_digits);
	}
    }
  PADN('0', trailing_zeroes);
  if (exponent_size)
    PUTN(exponent_start, exponent_size);
  if (pad_kind == _IO_LEFT && padding > 0) /* Left adjustment*/
    PADN(fill, padding);
  return count;
 error:
  return EOF;
}
