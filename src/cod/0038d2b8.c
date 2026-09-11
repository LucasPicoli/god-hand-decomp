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
#define NULL 0
#define u_char unsigned char
#define u_long unsigned long
#define __P(x) x
#define MAXEXP 308
#define MAXFRACT 39
#define _IO_USE_DTOA

typedef char *_IO_va_list;
#define va_arg(ap, type) (*(type *)((ap += 8) - 8))

extern unsigned char D_0045F039[];          /* _ctype_ + 1 */
#define isspace(c) (D_0045F039[(int)(c)] & 8)
#define isupper(c) (D_0045F039[(int)(c)] & 1)

extern short D_003F4B30[17];                /* basefix */
#define basefix D_003F4B30

extern int _IO_getc(struct _IO_FILE *fp);
extern int func_0038EAB0(int c, struct _IO_FILE *fp);      /* _IO_ungetc */
#define _IO_ungetc func_0038EAB0
extern double func_003903E8(const char *, char **);        /* _IO_strtod */
#define _IO_strtod func_003903E8
extern const unsigned char *func_0038E030(char *tab, const unsigned char *fmt);
#define __sccl func_0038E030
extern unsigned long func_003A9228(const char *, char **, int);  /* strtoul */
extern long func_003AD0C0(const char *, char **, int);           /* strtol  */
#define strtoul func_003A9228
#define strtol  func_003AD0C0

#define _IO_peekc_unlocked(_fp) \
       ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end \
	  && __underflow (_fp) == EOF ? EOF \
	: *(unsigned char *) (_fp)->_IO_read_ptr)
#define _IO_peekc(_fp) _IO_peekc_unlocked (_fp)

#define _IO_XSGETN(FP, DATA, N) ((*(FP)->vtable->__xsgetn.pfn)(FP, DATA, (_IO_size_t)(N)))


#ifndef	NO_FLOATING_POINT
#define FLOATING_POINT
#endif

#ifdef FLOATING_POINT
#define	BUF	(MAXEXP+MAXFRACT+3)	/* 3 = sign + decimal point + NUL */
#else
#define	BUF	40
#endif

/*
 * Flags used during conversion.
 */
#define	LONG		0x01	/* l: long or double */
#define	LONGDBL		0x02	/* L: long double; unimplemented */
#define	SHORT		0x04	/* h: short */
#define	SUPPRESS	0x08	/* suppress assignment */
#define	POINTER		0x10	/* weird %p pointer (`fake hex') */
#define	NOSKIP		0x20	/* do not skip blanks */
#define	WIDTH		0x40	/* width */

/*
 * The following are used in numeric conversions only:
 * SIGNOK, NDIGITS, DPTOK, and EXPOK are for floating point;
 * SIGNOK, NDIGITS, PFXOK, and NZDIGITS are for integral.
 */
#define	SIGNOK		0x40	/* +/- is (still) legal */
#define	NDIGITS		0x80	/* no digits detected */

#define	DPTOK		0x100	/* (float) decimal point is still legal */
#define	EXPOK		0x200	/* (float) exponent (e+3, etc) still legal */

#define	PFXOK		0x100	/* 0x prefix is (still) legal */
#define	NZDIGITS	0x200	/* no zero digits detected */

/*
 * Conversion types.
 */
#define	CT_CHAR		0	/* %c conversion */
#define	CT_CCL		1	/* %[...] conversion */
#define	CT_STRING	2	/* %s conversion */
#define	CT_INT		3	/* integer, i.e., strtol or strtoul */
#define	CT_FLOAT	4	/* floating, i.e., strtod */

#define u_char unsigned char
#define u_long unsigned long

int
__attribute__((section(".text._IO_vfscanf")))
_IO_vfscanf (struct _IO_FILE *fp, char const *fmt0, _IO_va_list ap, int *errp)
{
	register const u_char *fmt = (const u_char *)fmt0;
	register int c;		/* character from format, or conversion */
	register _IO_ssize_t width;	/* field width, or 0 */
	register char *p;	/* points into all kinds of strings */
	register int n;		/* handy integer */
	register int flags = 0;	/* flags as defined above */
	register char *p0;	/* saves original value of p when necessary */
	int nassigned;		/* number of fields assigned */
	int nread;		/* number of characters consumed from fp */
	/* Assignments to base and ccfn are just to suppress warnings from gcc.*/
	int base = 0;		/* base argument to strtol/strtoul */
	typedef u_long (*strtoulfn) __P((const char*, char**, int));
	strtoulfn ccfn = 0;
	/* conversion function (strtol/strtoul) */
	char ccltab[256];	/* character class table for %[...] */
	char buf[BUF];		/* buffer for numeric conversions */
	int seen_eof = 0;


	nassigned = 0;
	nread = 0;
	for (;;) {
		c = *fmt++;
		if (c == 0)
			goto done;
		if (isspace(c)) {
			for (;;) {
			        c = _IO_getc(fp);
				if (c == EOF) {
				  seen_eof++;
				  break;
				}
				if (!isspace(c)) {
				    _IO_ungetc (c, fp);
				    break;
				}
				nread++;
			}
			continue;
		}
		if (c != '%')
			goto literal;
		width = 0;
		flags = 0;
		/*
		 * switch on the format.  continue if done;
		 * break once format type is derived.
		 */
again:		c = *fmt++;
		switch (c) {
		case '%':
literal:
		        n = _IO_getc(fp);
			if (n == EOF)
			    goto eof_failure;
			if (n != c) {
			    _IO_ungetc (n, fp);
			    goto match_failure;
			}
			nread++;
			continue;

		case '*':
			if (flags) goto control_failure;
			flags = SUPPRESS;
			goto again;
		case 'l':
			if (flags & ~(SUPPRESS | WIDTH)) goto control_failure;
			flags |= LONG;
			goto again;
		case 'L':
			if (flags & ~(SUPPRESS | WIDTH)) goto control_failure;
			flags |= LONGDBL;
			goto again;
		case 'h':
			if (flags & ~(SUPPRESS | WIDTH)) goto control_failure;
			flags |= SHORT;
			goto again;

		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			if (flags & ~(SUPPRESS | WIDTH)) goto control_failure;
			flags |= WIDTH;
			width = width * 10 + c - '0';
			goto again;

		/*
		 * Conversions.
		 * Those marked `compat' are for 4.[123]BSD compatibility.
		 *
		 * (According to ANSI, E and X formats are supposed
		 * to the same as e and x.  Sorry about that.)
		 */
		case 'D':	/* compat */
			flags |= LONG;
			/* FALLTHROUGH */
		case 'd':
			c = CT_INT;
			ccfn = (strtoulfn)strtol;
			base = 10;
			break;

		case 'i':
			c = CT_INT;
			ccfn = (strtoulfn)strtol;
			base = 0;
			break;

		case 'O':	/* compat */
			flags |= LONG;
			/* FALLTHROUGH */
		case 'o':
			c = CT_INT;
			ccfn = strtoul;
			base = 8;
			break;

		case 'u':
			c = CT_INT;
			ccfn = strtoul;
			base = 10;
			break;

		case 'X':
		case 'x':
			flags |= PFXOK;	/* enable 0x prefixing */
			c = CT_INT;
			ccfn = strtoul;
			base = 16;
			break;

#ifdef FLOATING_POINT
		case 'E': case 'F':
		case 'e': case 'f': case 'g':
			c = CT_FLOAT;
			break;
#endif

		case 's':
			c = CT_STRING;
			break;

		case '[':
			fmt = __sccl(ccltab, fmt);
			flags |= NOSKIP;
			c = CT_CCL;
			break;

		case 'c':
			flags |= NOSKIP;
			c = CT_CHAR;
			break;

		case 'p':	/* pointer format is like hex */
			flags |= POINTER | PFXOK;
			c = CT_INT;
			ccfn = strtoul;
			base = 16;
			break;

		case 'n':
			if (flags & SUPPRESS)	/* ??? */
				continue;
			if (flags & SHORT)
				*va_arg(ap, short *) = nread;
			else if (flags & LONG)
				*va_arg(ap, long *) = nread;
			else
				*va_arg(ap, int *) = nread;
			continue;

		/*
		 * Disgusting backwards compatibility hacks.	XXX
		 */
		case '\0':	/* compat */
		        nassigned = EOF;
			goto done;

		default:	/* compat */
			if (isupper(c))
				flags |= LONG;
			c = CT_INT;
			ccfn = (strtoulfn)strtol;
			base = 10;
			break;
		}

		/*
		 * We have a conversion that requires input.
		 */
		if (_IO_peekc(fp) == EOF)
			goto eof_failure;

		/*
		 * Consume leading white space, except for formats
		 * that suppress this.
		 */
		if ((flags & NOSKIP) == 0) {
		    n = (unsigned char)*fp->_IO_read_ptr;
		    while (isspace(n)) {
			fp->_IO_read_ptr++;
			nread++;
			n = _IO_peekc(fp);
			if (n == EOF)
			    goto eof_failure;
		    }
		    /* Note that there is at least one character in
		       the buffer, so conversions that do not set NOSKIP
		       can no longer result in an input failure. */
		}

		/*
		 * Do the conversion.
		 */
		switch (c) {

		case CT_CHAR:
			/* scan arbitrary characters (sets NOSKIP) */
			if (width == 0) /* FIXME! */
				width = 1;
			if (flags & SUPPRESS) {
			    _IO_size_t sum = 0;
			    for (;;) {
			        n = fp->_IO_read_end - fp->_IO_read_ptr;
				if (n < (int)width) {
				    sum += n;
				    width -= n;
				    fp->_IO_read_ptr += n;
				    if (__underflow(fp) == EOF)
					if (sum == 0)
					    goto eof_failure;
					else {
					    seen_eof++;
					    break;
					}
				} else {
				    sum += width;
				    fp->_IO_read_ptr += width;
				    break;
				}
			    }
			    nread += sum;
			} else {
			    _IO_size_t r =

			      _IO_XSGETN (fp, (char*)va_arg(ap, char*), width);
			    if (r != width)
				goto eof_failure;
			    nread += r;
			    nassigned++;
			}
			break;

		case CT_CCL:
			/* scan a (nonempty) character class (sets NOSKIP) */
			if (width == 0)
				width = ~0;	/* `infinity' */
			/* take only those things in the class */
			if (flags & SUPPRESS) {
				n = 0;
				while (ccltab[(unsigned char)*fp->_IO_read_ptr]) {
				    n++, fp->_IO_read_ptr++;
				    if (--width == 0)
					break;
				    if (_IO_peekc(fp) == EOF) {
					if (n == 0)
					    goto eof_failure;
					seen_eof++;
					break;
				    }
				}
				if (n == 0)
					goto match_failure;
			} else {
			    p0 = p = va_arg(ap, char *);
			    while (ccltab[(unsigned char)*fp->_IO_read_ptr]) {
				*p++ = *fp->_IO_read_ptr++;
				if (--width == 0)
				    break;
				if (_IO_peekc(fp) == EOF) {
				    if (p == p0)
					goto eof_failure;
				    seen_eof++;
				    break;
				}
			    }
			    n = p - p0;
			    if (n == 0)
				goto match_failure;
			    *p = 0;
			    nassigned++;
			}
			nread += n;
			break;

		case CT_STRING:
			/* like CCL, but zero-length string OK, & no NOSKIP */
			if (width == 0)
				width = ~0;
			if (flags & SUPPRESS) {
				n = 0;
				while (!isspace((unsigned char)*fp->_IO_read_ptr)) {
					n++, fp->_IO_read_ptr++;
					if (--width == 0)
						break;
					if (_IO_peekc(fp) == EOF) {
					    seen_eof++;
					    break;
					}
				}
				nread += n;
			} else {
				p0 = p = va_arg(ap, char *);
				while (!isspace((unsigned char)*fp->_IO_read_ptr)) {
					*p++ = *fp->_IO_read_ptr++;
					if (--width == 0)
						break;
					if (_IO_peekc(fp) == EOF) {
					    seen_eof++;
					    break;
					}
				}
				*p = 0;
				nread += p - p0;
				nassigned++;
			}
			continue;

		case CT_INT:
			/* scan an integer as if by strtol/strtoul */
			if (width == 0 || width > sizeof(buf) - 1)
				width = sizeof(buf) - 1;
			flags |= SIGNOK | NDIGITS | NZDIGITS;
			for (p = buf; width; width--) {
				c = (unsigned char)*fp->_IO_read_ptr;
				/*
				 * Switch on the character; `goto ok'
				 * if we accept it as a part of number.
				 */
				switch (c) {

				/*
				 * The digit 0 is always legal, but is
				 * special.  For %i conversions, if no
				 * digits (zero or nonzero) have been
				 * scanned (only signs), we will have
				 * base==0.  In that case, we should set
				 * it to 8 and enable 0x prefixing.
				 * Also, if we have not scanned zero digits
				 * before this, do not turn off prefixing
				 * (someone else will turn it off if we
				 * have scanned any nonzero digits).
				 */
				case '0':
					if (base == 0) {
						base = 8;
						flags |= PFXOK;
					}
					if (flags & NZDIGITS)
					    flags &= ~(SIGNOK|NZDIGITS|NDIGITS);
					else
					    flags &= ~(SIGNOK|PFXOK|NDIGITS);
					goto ok;

				/* 1 through 7 always legal */
				case '1': case '2': case '3':
				case '4': case '5': case '6': case '7':
					base = basefix[base];
					flags &= ~(SIGNOK | PFXOK | NDIGITS);
					goto ok;

				/* digits 8 and 9 ok iff decimal or hex */
				case '8': case '9':
					base = basefix[base];
					if (base <= 8)
						break;	/* not legal here */
					flags &= ~(SIGNOK | PFXOK | NDIGITS);
					goto ok;

				/* letters ok iff hex */
				case 'A': case 'B': case 'C':
				case 'D': case 'E': case 'F':
				case 'a': case 'b': case 'c':
				case 'd': case 'e': case 'f':
					/* no need to fix base here */
					if (base <= 10)
						break;	/* not legal here */
					flags &= ~(SIGNOK | PFXOK | NDIGITS);
					goto ok;

				/* sign ok only as first character */
				case '+': case '-':
					if (flags & SIGNOK) {
						flags &= ~SIGNOK;
						goto ok;
					}
					break;

				/* x ok iff flag still set & 2nd char */
				case 'x': case 'X':
					if (flags & PFXOK && p == buf + 1) {
						base = 16;	/* if %i */
						flags &= ~PFXOK;
						goto ok;
					}
					break;
				}

				/*
				 * If we got here, c is not a legal character
				 * for a number.  Stop accumulating digits.
				 */
				break;
		ok:
				/*
				 * c is legal: store it and look at the next.
				 */
				*p++ = c;
				fp->_IO_read_ptr++;
				if (_IO_peekc(fp) == EOF) {
				    seen_eof++;
				    break;		/* EOF */
				}
		        }
			/*
			 * If we had only a sign, it is no good; push
			 * back the sign.  If the number ends in `x',
			 * it was [sign] '0' 'x', so push back the x
			 * and treat it as [sign] '0'.
			 */
			if (flags & NDIGITS) {
				if (p > buf)
					(void) _IO_ungetc(*(u_char *)--p, fp);
				goto match_failure;
			}
			c = ((u_char *)p)[-1];
			if (c == 'x' || c == 'X') {
				--p;
				(void) _IO_ungetc (c, fp);
			}
			if ((flags & SUPPRESS) == 0) {
				u_long res;

				*p = 0;
				res = (*ccfn)(buf, (char **)NULL, base);
				if (flags & POINTER)
					*va_arg(ap, void **) = (void *)res;
				else if (flags & SHORT)
					*va_arg(ap, short *) = res;
				else if (flags & LONG)
					*va_arg(ap, long *) = res;
				else
					*va_arg(ap, int *) = res;
				nassigned++;
			}
			nread += p - buf;
			break;

#ifdef FLOATING_POINT
		case CT_FLOAT:
			/* scan a floating point number as if by strtod */
			if (width == 0 || width > sizeof(buf) - 1)
				width = sizeof(buf) - 1;
			flags |= SIGNOK | NDIGITS | DPTOK | EXPOK;
			for (p = buf; width; width--) {
				c = (unsigned char)*fp->_IO_read_ptr;
				/*
				 * This code mimicks the integer conversion
				 * code, but is much simpler.
				 */
				switch (c) {

				case '0': case '1': case '2': case '3':
				case '4': case '5': case '6': case '7':
				case '8': case '9':
					flags &= ~(SIGNOK | NDIGITS);
					goto fok;

				case '+': case '-':
					if (flags & SIGNOK) {
						flags &= ~SIGNOK;
						goto fok;
					}
					break;
				case '.':
					if (flags & DPTOK) {
						flags &= ~(SIGNOK | DPTOK);
						goto fok;
					}
					break;
				case 'e': case 'E':
					/* no exponent without some digits */
					if ((flags&(NDIGITS|EXPOK)) == EXPOK) {
						flags =
						    (flags & ~(EXPOK|DPTOK)) |
						    SIGNOK | NDIGITS;
						goto fok;
					}
					break;
				}
				break;
		fok:
				*p++ = c;
				fp->_IO_read_ptr++;
				if (_IO_peekc(fp) == EOF) {
				    seen_eof++;
				    break;	/* EOF */
				}
			}
			/*
			 * If no digits, might be missing exponent digits
			 * (just give back the exponent) or might be missing
			 * regular digits, but had sign and/or decimal point.
			 */
			if (flags & NDIGITS) {
				if (flags & EXPOK) {
					/* no digits at all */
					while (p > buf)
					    _IO_ungetc (*(u_char *)--p, fp);
					goto match_failure;
				}
				/* just a bad exponent (e and maybe sign) */
				c = *(u_char *)--p;
				if (c != 'e' && c != 'E') {
					(void) _IO_ungetc (c, fp);/* sign */
					c = *(u_char *)--p;
				}
				(void) _IO_ungetc (c, fp);
			}
			if ((flags & SUPPRESS) == 0) {
				double res;
				*p = 0;
#ifdef _IO_USE_DTOA
				res = _IO_strtod(buf, NULL);
#else
				res = atof(buf);
#endif
				if (flags & LONG)
					*va_arg(ap, double *) = res;
				else
					*va_arg(ap, float *) = res;
				nassigned++;
			}
			nread += p - buf;
			break;
#endif /* FLOATING_POINT */
		}
	}
eof_failure:
	seen_eof++;
input_failure:
	if (nassigned == 0)
	    nassigned = -1;
control_failure:
match_failure:
	if (errp)
	    *errp |= 2;
done:
	if (errp && seen_eof)
		*errp |= 1;
	return (nassigned);
}
