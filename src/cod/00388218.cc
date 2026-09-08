/* ee-2.9-991111 matched TU. */

/* --- LANE LB2 prelude: gcc-2.95.2 libio headers, inlined --- */
/* LANE LB2 — a stand-in for the generated _G_config.h.
   Every macro and typedef here is transcribed from the generated copy the SCE
   EE runtime ships (_G_LIB_VERSION "2.8-ee-001003").  Nothing is added.
   EE `long` is 64 bit, so _G_off_t, _G_fpos_t and _G_ssize_t are 64 bit and
   _G_size_t is 32 bit. */
#define _G_LIB_VERSION "2.8-ee-001003"
#define _G_NAMES_HAVE_UNDERSCORE 0
#define _G_VTABLE_LABEL_HAS_LENGTH 1
#define _G_VTABLE_LABEL_PREFIX "_vt$"
#define _G_HAVE_ST_BLKSIZE 1

typedef          int   _G_int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int  _G_uint8_t __attribute__((__mode__(__QI__)));
typedef          int  _G_int16_t __attribute__((__mode__(__HI__)));
typedef unsigned int _G_uint16_t __attribute__((__mode__(__HI__)));
typedef          int  _G_int32_t __attribute__((__mode__(__SI__)));
typedef unsigned int _G_uint32_t __attribute__((__mode__(__SI__)));
typedef          int  _G_int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int _G_uint64_t __attribute__((__mode__(__DI__)));
__extension__ typedef long long _G_llong;
__extension__ typedef unsigned long long _G_ullong;

typedef unsigned long _G_clock_t;
typedef short _G_dev_t;
typedef long _G_fpos_t;
typedef unsigned short _G_gid_t;
typedef unsigned short _G_ino_t;
typedef int _G_mode_t;
typedef unsigned short _G_nlink_t;
typedef long _G_off_t;
typedef int _G_pid_t;
#ifndef __PTRDIFF_TYPE__
#define __PTRDIFF_TYPE__ int
#endif
typedef __PTRDIFF_TYPE__ _G_ptrdiff_t;
typedef unsigned long _G_sigset_t;
#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__ unsigned int
#endif
typedef __SIZE_TYPE__ _G_size_t;
typedef long _G_time_t;
typedef unsigned short _G_uid_t;
typedef int _G_wchar_t;

#define _G_BUFSIZ 1024
#define _G_FOPEN_MAX 20
#define _G_FILENAME_MAX 1024
#define _G_ARGS(ARGLIST) ARGLIST
#if !defined (__GNUG__) || defined (__STRICT_ANSI__)
#define _G_NO_NRV
#endif
typedef long _G_ssize_t;
typedef int _G_wint_t;
/* retail mangles streambuf::vscan as PCcPcP3ios, so _IO_va_list is `char *` */
typedef char *_G_va_list;
#define _G_signal_return_type void
#define _G_sprintf_return_type int
#define _G_HAVE_ATEXIT 0
#define _G_HAVE_SYS_RESOURCE 0
#define _G_HAVE_SYS_TIMES 1
#define _G_HAVE_SYS_SOCKET 0
#define _G_HAVE_SYS_CDEFS 0
#define _G_HAVE_SYS_WAIT 1
#define _G_HAVE_UNISTD 1
#define _G_HAVE_DIRENT 0
#define _G_HAVE_CURSES 0
#define _G_MATH_H_INLINES 0
#define _G_HAVE_BOOL 1
#define _G_HAVE_PRINTF_FP 0
#define _G_HAVE_LONG_DOUBLE_IO 0
#undef NULL
#define NULL 0
#if !defined(_G_DLLEXTERN)
#define _G_DLLEXTERN
#endif

/* ---- libio.h ---- */
/* Copyright (C) 1991, 92, 93, 94, 95, 97, 98 Free Software Foundation, Inc.
   This file is part of the GNU IO Library.
   Written by Per Bothner <bothner@cygnus.com>.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2, or (at
   your option) any later version.

   This library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library; see the file COPYING.  If not, write to
   the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA.

   As a special exception, if you link this library with files
   compiled with a GNU compiler to produce an executable, this does
   not cause the resulting executable to be covered by the GNU General
   Public License.  This exception does not however invalidate any
   other reasons why the executable file might be covered by the GNU
   General Public License.  */

#ifndef _IO_STDIO_H
#define _IO_STDIO_H

#define _IO_pos_t _G_fpos_t /* obsolete */
#define _IO_fpos_t _G_fpos_t
#define _IO_size_t _G_size_t
#define _IO_ssize_t _G_ssize_t
#define _IO_off_t _G_off_t
#define _IO_pid_t _G_pid_t
#define _IO_uid_t _G_uid_t
#define _IO_HAVE_SYS_WAIT _G_HAVE_SYS_WAIT
#define _IO_HAVE_ST_BLKSIZE _G_HAVE_ST_BLKSIZE
#define _IO_BUFSIZ _G_BUFSIZ
#define _IO_va_list _G_va_list
#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
#define _IO_fpos64_t _G_fpos64_t
#define _IO_off64_t _G_off64_t
#endif

#ifdef _G_NEED_STDARG_H
/* This define avoids name pollution if we're using GNU stdarg.h */
# define __need___va_list
# ifdef __GNUC_VA_LIST
#  undef _IO_va_list
#  define _IO_va_list __gnuc_va_list
# endif /* __GNUC_VA_LIST */
#endif

#ifndef __P
# if _G_HAVE_SYS_CDEFS
# else
#  ifdef __STDC__
#   define __P(p) p
#  else
#   define __P(p) ()
#  endif
# endif
#endif /*!__P*/

#ifndef __PMT
# ifdef __STDC__
#  define __PMT(p) p
# else
#  define __PMT(p) ()
# endif
#endif /*!__P*/

/* For backward compatibility */
#ifndef _PARAMS
# define _PARAMS(protos) __P(protos)
#endif /*!_PARAMS*/

#ifndef __STDC__
# define const
#endif
#define _IO_UNIFIED_JUMPTABLES 1
#if !_G_HAVE_PRINTF_FP
# define _IO_USE_DTOA 1
#endif

#ifndef EOF
# define EOF (-1)
#endif
#ifndef NULL
# if defined __GNUG__ && \
    (__GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 8))
#  define NULL (__null)
# else
#  if !defined(__cplusplus)
#   define NULL ((void*)0)
#  else
#   define NULL (0)
#  endif
# endif
#endif

#define _IOS_INPUT	1
#define _IOS_OUTPUT	2
#define _IOS_ATEND	4
#define _IOS_APPEND	8
#define _IOS_TRUNC	16
#define _IOS_NOCREATE	32
#define _IOS_NOREPLACE	64
#define _IOS_BIN	128

/* Magic numbers and bits for the _flags field.
   The magic numbers use the high-order bits of _flags;
   the remaining bits are available for variable flags.
   Note: The magic numbers must all be negative if stdio
   emulation is desired. */

#define _IO_MAGIC 0xFBAD0000 /* Magic number */
#define _OLD_STDIO_MAGIC 0xFABC0000 /* Emulate old stdio. */
#define _IO_MAGIC_MASK 0xFFFF0000
#define _IO_USER_BUF 1 /* User owns buffer; don't delete it on close. */
#define _IO_UNBUFFERED 2
#define _IO_NO_READS 4 /* Reading not allowed */
#define _IO_NO_WRITES 8 /* Writing not allowd */
#define _IO_EOF_SEEN 0x10
#define _IO_ERR_SEEN 0x20
#define _IO_DELETE_DONT_CLOSE 0x40 /* Don't call close(_fileno) on cleanup. */
#define _IO_LINKED 0x80 /* Set if linked (using _chain) to streambuf::_list_all.*/
#define _IO_IN_BACKUP 0x100
#define _IO_LINE_BUF 0x200
#define _IO_TIED_PUT_GET 0x400 /* Set if put and get pointer logicly tied. */
#define _IO_CURRENTLY_PUTTING 0x800
#define _IO_IS_APPENDING 0x1000
#define _IO_IS_FILEBUF 0x2000
#define _IO_BAD_SEEN 0x4000

/* These are "formatting flags" matching the iostream fmtflags enum values. */
#define _IO_SKIPWS 01
#define _IO_LEFT 02
#define _IO_RIGHT 04
#define _IO_INTERNAL 010
#define _IO_DEC 020
#define _IO_OCT 040
#define _IO_HEX 0100
#define _IO_SHOWBASE 0200
#define _IO_SHOWPOINT 0400
#define _IO_UPPERCASE 01000
#define _IO_SHOWPOS 02000
#define _IO_SCIENTIFIC 04000
#define _IO_FIXED 010000
#define _IO_UNITBUF 020000
#define _IO_STDIO 040000
#define _IO_DONT_CLOSE 0100000
#define _IO_BOOLALPHA 0200000


struct _IO_jump_t;  struct _IO_FILE;

/* Handle lock.  */
#ifdef _IO_MTSAFE_IO
# if defined __GLIBC__ && __GLIBC__ >= 2
#  if __GLIBC_MINOR__ > 0
#  else
#  endif
#  define _IO_LOCK_T _IO_lock_t *
# else
/*# include <comthread.h>*/
# endif
#else
# if defined(__GLIBC__) && __GLIBC__ >= 2
   typedef void _IO_lock_t;
#  define _IO_LOCK_T void *
# else
#  ifdef __linux__
    struct _IO_lock_t { void *ptr; short int field1; short int field2; };
#   define _IO_LOCK_T struct _IO_lock_t
#  else
    typedef void _IO_lock_t;
#  endif
# endif
#endif


/* A streammarker remembers a position in a buffer. */

struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  /* If _pos >= 0
 it points to _buf->Gbase()+_pos. FIXME comment */
  /* if _pos < 0, it points to _buf->eBptr()+_pos. FIXME comment */
  int _pos;
#if 0
    void set_streampos(streampos sp) { _spos = sp; }
    void set_offset(int offset) { _pos = offset; _spos = (streampos)(-2); }
  public:
    streammarker(streambuf *sb);
    ~streammarker();
    int saving() { return  _spos == -2; }
    int delta(streammarker&);
    int delta();
#endif
};

struct _IO_FILE {
  int _flags;		/* High-order word is _IO_MAGIC; rest is flags. */
#define _IO_file_flags _flags

  /* The following pointers correspond to the C++ streambuf protocol. */
  /* Note:  Tk uses the _IO_read_ptr and _IO_read_end fields directly. */
  char* _IO_read_ptr;	/* Current read pointer */
  char* _IO_read_end;	/* End of get area. */
  char* _IO_read_base;	/* Start of putback+get area. */
  char* _IO_write_base;	/* Start of put area. */
  char* _IO_write_ptr;	/* Current put pointer. */
  char* _IO_write_end;	/* End of put area. */
  char* _IO_buf_base;	/* Start of reserve area. */
  char* _IO_buf_end;	/* End of reserve area. */
  /* The following fields are used to support backing up and undo. */
  char *_IO_save_base; /* Pointer to start of non-current get area. */
  char *_IO_backup_base;  /* Pointer to first valid character of backup area */
  char *_IO_save_end; /* Pointer to end of non-current get area. */

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _blksize;
#ifdef _G_IO_IO_FILE_VERSION
  _IO_off_t _old_offset;
#else
  _IO_off_t _offset;
#endif

#define __HAVE_COLUMN /* temporary */
  /* 1+column number of pbase(); 0 is unknown. */
  unsigned short _cur_column;
  char _unused;
  char _shortbuf[1];

  /*  char* _save_gptr;  char* _save_egptr; */

#ifdef _IO_LOCK_T
  _IO_LOCK_T _lock;
#endif
#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
  _IO_off64_t _offset;
  int _unused2[16];	/* Make sure we don't get into trouble again.  */
#endif
};

#ifndef __cplusplus
typedef struct _IO_FILE _IO_FILE;
#endif

#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
#define _IO_stdin_ _IO_2_1_stdin_
#define _IO_stdout_ _IO_2_1_stdout_
#define _IO_stderr_ _IO_2_1_stderr_
#endif

struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_stdin_, _IO_stdout_, _IO_stderr_;
#define _IO_stdin ((_IO_FILE*)(&_IO_stdin_))
#define _IO_stdout ((_IO_FILE*)(&_IO_stdout_))
#define _IO_stderr ((_IO_FILE*)(&_IO_stderr_))


/* Define the user-visible type, with user-friendly member names.  */
typedef struct
{
  _IO_ssize_t (*read) __PMT ((struct _IO_FILE *, void *, _IO_ssize_t));
  _IO_ssize_t (*write) __PMT ((struct _IO_FILE *, const void *, _IO_ssize_t));
  _IO_fpos_t (*seek) __PMT ((struct _IO_FILE *, _IO_off_t, int));
  int (*close) __PMT ((struct _IO_FILE *));
} _IO_cookie_io_functions_t;

/* Special file type for fopencookie function.  */
struct _IO_cookie_file
{
  struct _IO_FILE file;
  const void *vtable;
  void *cookie;
  _IO_cookie_io_functions_t io_functions;
};


#ifdef __cplusplus
extern "C" {
#endif

extern int __underflow __P ((_IO_FILE *));
extern int __uflow __P ((_IO_FILE *));
extern int __overflow __P ((_IO_FILE *, int));

#define _IO_getc_unlocked(_fp) \
       ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end ? __uflow (_fp) \
	: *(unsigned char *) (_fp)->_IO_read_ptr++)
#define _IO_peekc_unlocked(_fp) \
       ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end \
	  && __underflow (_fp) == EOF ? EOF \
	: *(unsigned char *) (_fp)->_IO_read_ptr)

#define _IO_putc_unlocked(_ch, _fp) \
   (((_fp)->_IO_write_ptr >= (_fp)->_IO_write_end) \
    ? __overflow (_fp, (unsigned char) (_ch)) \
    : (unsigned char) (*(_fp)->_IO_write_ptr++ = (_ch)))

#define _IO_feof_unlocked(__fp) (((__fp)->_flags & _IO_EOF_SEEN) != 0)
#define _IO_ferror_unlocked(__fp) (((__fp)->_flags & _IO_ERR_SEEN) != 0)

extern int _IO_getc __P ((_IO_FILE *__fp));
extern int _IO_putc __P ((int __c, _IO_FILE *__fp));
extern int _IO_feof __P ((_IO_FILE *__fp));
extern int _IO_ferror __P ((_IO_FILE *__fp));

extern int _IO_peekc_locked __P ((_IO_FILE *__fp));

/* This one is for Emacs. */
#define _IO_PENDING_OUTPUT_COUNT(_fp)	\
	((_fp)->_IO_write_ptr - (_fp)->_IO_write_base)

extern void _IO_flockfile __P ((_IO_FILE *));
extern void _IO_funlockfile __P ((_IO_FILE *));
extern int _IO_ftrylockfile __P ((_IO_FILE *));

#ifdef _IO_MTSAFE_IO
# define _IO_peekc(_fp) _IO_peekc_locked (_fp)
#else
# define _IO_peekc(_fp) _IO_peekc_unlocked (_fp)
# define _IO_flockfile(_fp) /**/
# define _IO_funlockfile(_fp) /**/
# define _IO_ftrylockfile(_fp) /**/
# define _IO_cleanup_region_start(_fct, _fp) /**/
# define _IO_cleanup_region_end(_Doit) /**/
#endif /* !_IO_MTSAFE_IO */


extern int _IO_vfscanf __P ((_IO_FILE *, const char *, _IO_va_list, int *));
extern int _IO_vfprintf __P ((_IO_FILE *, const char *, _IO_va_list));
extern _IO_ssize_t _IO_padn __P ((_IO_FILE *, int, _IO_ssize_t));
extern _IO_size_t _IO_sgetn __P ((_IO_FILE *, void *, _IO_size_t));

#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
extern _IO_fpos64_t _IO_seekoff __P ((_IO_FILE *, _IO_off64_t, int, int));
extern _IO_fpos64_t _IO_seekpos __P ((_IO_FILE *, _IO_fpos64_t, int));
#else
extern _IO_fpos_t _IO_seekoff __P ((_IO_FILE *, _IO_off_t, int, int));
extern _IO_fpos_t _IO_seekpos __P ((_IO_FILE *, _IO_fpos_t, int));
#endif

extern void _IO_free_backup_area __P ((_IO_FILE *));

#ifdef __cplusplus
}
#endif

#endif /* _IO_STDIO_H */

/* ---- streambuf.h ---- */
/* This is part of libio/iostream, providing -*- C++ -*- input/output.
Copyright (C) 1993 Free Software Foundation

This file is part of the GNU IO Library.  This library is free
software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option)
any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this library; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

As a special exception, if you link this library with files
compiled with a GNU compiler to produce an executable, this does not cause
the resulting executable to be covered by the GNU General Public License.
This exception does not however invalidate any other reasons why
the executable file might be covered by the GNU General Public License. */

#ifndef _STREAMBUF_H
#define _STREAMBUF_H
#ifdef __GNUG__
#pragma interface
#endif

/* #define _G_IO_THROW */ /* Not implemented:  ios::failure */

#define _IO_NEW_STREAMS // new optimizated stream representation

extern "C" {
}
//#include <_G_config.h>
#ifdef _G_NEED_STDARG_H
#endif
#ifndef _IO_va_list
#define _IO_va_list char *
#endif

#ifndef EOF
#define EOF (-1)
#endif
#ifndef NULL
#ifdef __GNUG__
#define NULL (__null)
#else
#define NULL (0)
#endif
#endif

#ifndef _IO_wchar_t
#if _G_IO_IO_FILE_VERSION == 0x20001
#define _IO_wchar_t _G_wchar_t
#else
#define _IO_wchar_t short
#endif
#endif

extern "C++" {
class istream; /* Work-around for a g++ name mangling bug. Fixed in 2.6. */
class ostream; class streambuf;

// In case some header files defines these as macros.
#undef open
#undef close

#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
typedef _IO_off64_t streamoff;
typedef _IO_fpos64_t streampos;
#else
typedef _IO_off_t streamoff;
typedef _IO_fpos_t streampos;
#endif
typedef _IO_ssize_t streamsize;

typedef unsigned long __fmtflags;
typedef unsigned char __iostate;

struct _ios_fields
{ // The data members of an ios.
    streambuf *_strbuf;
    ostream* _tie;
    int _width;
    __fmtflags _flags;
    _IO_wchar_t _fill;
    __iostate _state;
    __iostate _exceptions;
    int _precision;

    void *_arrays; /* Support for ios::iword and ios::pword. */
};

#define _IOS_GOOD	0
#define _IOS_EOF	1
#define _IOS_FAIL	2
#define _IOS_BAD	4

#define _IO_INPUT	1
#define _IO_OUTPUT	2
#define _IO_ATEND	4
#define _IO_APPEND	8
#define _IO_TRUNC	16
#define _IO_NOCREATE	32
#define _IO_NOREPLACE	64
#define _IO_BIN		128

#ifdef _STREAM_COMPAT
enum state_value {
    _good = _IOS_GOOD,
    _eof = _IOS_EOF,
    _fail = _IOS_FAIL,
    _bad = _IOS_BAD };
enum open_mode {
    input = _IO_INPUT,
    output = _IO_OUTPUT,
    atend = _IO_ATEND,
    append = _IO_APPEND };
#endif

class ios : public _ios_fields {
  ios& operator=(ios&);  /* Not allowed! */
  ios (const ios&); /* Not allowed! */
  public:
    typedef __fmtflags fmtflags;
    typedef int iostate;
    typedef int openmode;
    typedef _IO_ssize_t streamsize;
    enum io_state {
	goodbit = _IOS_GOOD,
	eofbit = _IOS_EOF,
	failbit = _IOS_FAIL,
	badbit = _IOS_BAD };
    enum open_mode {
	in = _IO_INPUT,
	out = _IO_OUTPUT,
	ate = _IO_ATEND,
	app = _IO_APPEND,
	trunc = _IO_TRUNC,
	nocreate = _IO_NOCREATE,
	noreplace = _IO_NOREPLACE,
	bin = _IOS_BIN, // Deprecated - ANSI uses ios::binary.
	binary = _IOS_BIN };
    enum seek_dir { beg, cur, end};
    typedef enum seek_dir seekdir;
    // NOTE: If adding flags here, before to update ios::bitalloc().
    enum { skipws=_IO_SKIPWS,
	   left=_IO_LEFT, right=_IO_RIGHT, internal=_IO_INTERNAL,
	   dec=_IO_DEC, oct=_IO_OCT, hex=_IO_HEX,
	   showbase=_IO_SHOWBASE, showpoint=_IO_SHOWPOINT,
	   uppercase=_IO_UPPERCASE, showpos=_IO_SHOWPOS,
	   scientific=_IO_SCIENTIFIC, fixed=_IO_FIXED,
	   unitbuf=_IO_UNITBUF, stdio=_IO_STDIO
#ifndef _IO_NEW_STREAMS
	   , dont_close=_IO_DONT_CLOSE // Don't delete streambuf on stream destruction
#endif
	   };
    enum { // Masks.
	basefield=dec+oct+hex,
	floatfield = scientific+fixed,
	adjustfield = left+right+internal
    };

#ifdef _IO_THROW
    class failure : public xmsg {
	ios* _stream;
      public:
	failure(ios* stream) { _stream = stream; }
	failure(string cause, ios* stream) { _stream = stream; }
	ios* rdios() const { return _stream; }
    };
#endif

    ostream* tie() const { return _tie; }
    ostream* tie(ostream* val) { ostream* save=_tie; _tie=val; return save; }

    // Methods to change the format state.
    _IO_wchar_t fill() const { return _fill; }
    _IO_wchar_t fill(_IO_wchar_t newf)
	{_IO_wchar_t oldf = _fill; _fill = newf; return oldf;}
    fmtflags flags() const { return _flags; }
    fmtflags flags(fmtflags new_val) {
	fmtflags old_val = _flags; _flags = new_val; return old_val; }
    int precision() const { return _precision; }
    int precision(int newp) {
	unsigned short oldp = _precision; _precision = (unsigned short)newp;
	return oldp; }
    fmtflags setf(fmtflags val) {
	fmtflags oldbits = _flags;
	_flags |= val; return oldbits; }
    fmtflags setf(fmtflags val, fmtflags mask) {
	fmtflags oldbits = _flags;
	_flags = (_flags & ~mask) | (val & mask); return oldbits; }
    fmtflags unsetf(fmtflags mask) {
	fmtflags oldbits = _flags;
	_flags &= ~mask; return oldbits; }
    int width() const { return _width; }
    int width(int val) { int save = _width; _width = val; return save; }

#ifdef _IO_THROW
    void _throw_failure() const { throw new ios::failure(this); }
#else
    void _throw_failure() const { }
#endif
    void clear(iostate state = 0) {
	_state = _strbuf ? state : state|badbit;
	if (_state & _exceptions) _throw_failure(); }
    void set(iostate flag) { _state |= flag;
	if (_state & _exceptions) _throw_failure(); }
    void setstate(iostate flag) { _state |= flag; // ANSI
	if (_state & _exceptions) _throw_failure(); }
    int good() const { return _state == 0; }
    int eof() const { return _state & ios::eofbit; }
    int fail() const { return _state & (ios::badbit|ios::failbit); }
    int bad() const { return _state & ios::badbit; }
    iostate rdstate() const { return _state; }
    operator void*() const { return fail() ? (void*)0 : (void*)(-1); }
    int operator!() const { return fail(); }
    iostate exceptions() const { return _exceptions; }
    void exceptions(iostate enable) {
	_exceptions = enable;
	if (_state & _exceptions) _throw_failure(); }

    streambuf* rdbuf() const { return _strbuf; }
    streambuf* rdbuf(streambuf *_s) {
      streambuf *_old = _strbuf; _strbuf = _s; clear (); return _old; }

    static int sync_with_stdio(int on);
    static void sync_with_stdio() { sync_with_stdio(1); }
    static fmtflags bitalloc();
    static int xalloc();
    void*& pword(int);
    void* pword(int) const;
    long& iword(int);
    long iword(int) const;

#ifdef _STREAM_COMPAT
    void unset(state_value flag) { _state &= ~flag; }
    void close();
    int is_open();
    int readable();
    int writable();
#endif

    // Used to initialize standard streams. Not needed in this implementation.
    class Init {
    public:
      Init () { }
    };

  protected:
    inline ios(streambuf* sb = 0, ostream* tie_to = 0);
    inline virtual ~ios();
    inline void init(streambuf* sb, ostream* tie = 0);
};

#if __GNUG__==1
typedef int _seek_dir;
#else
typedef ios::seek_dir _seek_dir;
#endif

// Magic numbers and bits for the _flags field.
// The magic numbers use the high-order bits of _flags;
// the remaining bits are abailable for variable flags.
// Note: The magic numbers must all be negative if stdio
// emulation is desired.

// A streammarker remembers a position in a buffer.
// You are guaranteed to be able to seek back to it if it is saving().
class streammarker : private _IO_marker {
    friend class streambuf;
    void set_offset(int offset) { _pos = offset; }
  public:
    streammarker(streambuf *sb);
    ~streammarker();
    int saving() { return  1; }
    int delta(streammarker&);
    int delta();
};

struct streambuf : public _IO_FILE { // protected??
    friend class ios;
    friend class istream;
    friend class ostream;
    friend class streammarker;
    const void *&_vtable() { return *(const void**)((_IO_FILE*)this + 1); }
  protected:
    static streambuf* _list_all; /* List of open streambufs. */
    _IO_FILE*& xchain() { return _chain; }
    void _un_link();
    void _link_in();
    char* gptr() const
      { return _IO_file_flags & _IO_IN_BACKUP ? _IO_save_base : _IO_read_ptr; }
    char* pptr() const { return _IO_write_ptr; }
    char* egptr() const
      { return _IO_file_flags & _IO_IN_BACKUP ? _IO_save_end : _IO_read_end; }
    char* epptr() const { return _IO_write_end; }
    char* pbase() const { return _IO_write_base; }
    char* eback() const
      { return _IO_file_flags & _IO_IN_BACKUP ? _IO_save_base : _IO_read_base;}
    char* base() const { return _IO_buf_base; }
    char* ebuf() const { return _IO_buf_end; }
    int blen() const { return _IO_buf_end - _IO_buf_base; }
    void xput_char(char c) { *_IO_write_ptr++ = c; }
    int xflags() { return _IO_file_flags; }
    int xflags(int f) {int fl = _IO_file_flags; _IO_file_flags = f; return fl;}
    void xsetflags(int f) { _IO_file_flags |= f; }
    void xsetflags(int f, int mask)
      { _IO_file_flags = (_IO_file_flags & ~mask) | (f & mask); }
    void gbump(int n)
      { _IO_file_flags & _IO_IN_BACKUP ? (_IO_save_base+=n):(_IO_read_ptr+=n);}
    void pbump(int n) { _IO_write_ptr += n; }
    void setb(char* b, char* eb, int a=0);
    void setp(char* p, char* ep)
      { _IO_write_base=_IO_write_ptr=p; _IO_write_end=ep; }
    void setg(char* eb, char* g, char *eg) {
      if (_IO_file_flags & _IO_IN_BACKUP) _IO_free_backup_area(this); 
      _IO_read_base = eb; _IO_read_ptr = g; _IO_read_end = eg; }
    char *shortbuf() { return _shortbuf; }

    int in_backup() { return _flags & _IO_IN_BACKUP; }
    // The start of the main get area:  FIXME:  wrong for write-mode filebuf?
    char *Gbase() { return in_backup() ? _IO_save_base : _IO_read_base; }
    // The end of the main get area:
    char *eGptr() { return in_backup() ? _IO_save_end : _IO_read_end; }
    // The start of the backup area:
    char *Bbase() { return in_backup() ? _IO_read_base : _IO_save_base; }
    char *Bptr() { return _IO_backup_base; }
    // The end of the backup area:
    char *eBptr() { return in_backup() ? _IO_read_end : _IO_save_end; }
    char *Nbase() { return _IO_save_base; }
    char *eNptr() { return _IO_save_end; }
    int have_backup() { return _IO_save_base != NULL; }
    int have_markers() { return _markers != NULL; }
    void free_backup_area();
    void unsave_markers(); // Make all streammarkers !saving().
    int put_mode() { return _flags & _IO_CURRENTLY_PUTTING; }
    int switch_to_get_mode();
    
    streambuf(int flags=0);
  public:
    static int flush_all();
    static void flush_all_linebuffered(); // Flush all line buffered files.
    virtual ~streambuf();
    virtual int overflow(int c = EOF); // Leave public for now
    virtual int underflow(); // Leave public for now
    virtual int uflow(); // Leave public for now
    virtual int pbackfail(int c);
//    virtual int showmany ();
    virtual streamsize xsputn(const char* s, streamsize n);
    virtual streamsize xsgetn(char* s, streamsize n);
    virtual streampos seekoff(streamoff, _seek_dir, int mode=ios::in|ios::out);
    virtual streampos seekpos(streampos pos, int mode = ios::in|ios::out);

    streampos pubseekoff(streamoff o, _seek_dir d, int mode=ios::in|ios::out)
      { return _IO_seekoff (this, o, d, mode); }
    streampos pubseekpos(streampos pos, int mode = ios::in|ios::out)
      { return _IO_seekpos (this, pos, mode); }
    streampos sseekoff(streamoff, _seek_dir, int mode=ios::in|ios::out);
    streampos sseekpos(streampos pos, int mode = ios::in|ios::out);
    virtual streambuf* setbuf(char* p, int len);
    virtual int sync();
    virtual int doallocate();

    int seekmark(streammarker& mark, int delta = 0);
    int sputbackc(char c);
    int sungetc();
    int unbuffered() { return _flags & _IO_UNBUFFERED ? 1 : 0; }
    int linebuffered() { return _flags & _IO_LINE_BUF ? 1 : 0; }
    void unbuffered(int i)
	{ if (i) _flags |= _IO_UNBUFFERED; else _flags &= ~_IO_UNBUFFERED; }
    void linebuffered(int i)
	{ if (i) _flags |= _IO_LINE_BUF; else _flags &= ~_IO_LINE_BUF; }
    int allocate() { // For AT&T compatibility
	if (base() || unbuffered()) return 0;
	else return doallocate(); }
    // Allocate a buffer if needed; use _shortbuf if appropriate.
    void allocbuf() { if (base() == NULL) doallocbuf(); }
    void doallocbuf();
    int in_avail() { return _IO_read_end - _IO_read_ptr; }
    int out_waiting() { return _IO_write_ptr - _IO_write_base; }
    streamsize sputn(const char* s, streamsize n) { return xsputn(s, n); }
    streamsize padn(char pad, streamsize n) { return _IO_padn(this, pad, n); }
    streamsize sgetn(char* s, streamsize n) { return _IO_sgetn(this, s, n); }
    int ignore(int);
    int get_column();
    int set_column(int);
    long sgetline(char* buf, _IO_size_t n, char delim, int putback_delim);
    int sputc(int c) { return _IO_putc(c, this); }
    int sbumpc() { return _IO_getc(this); }
    int sgetc() { return _IO_peekc(this); }
    int snextc() {
	if (_IO_read_ptr >= _IO_read_end && __underflow(this) == EOF)
	  return EOF;
	else return _IO_read_ptr++, sgetc(); }
    void stossc() { if (_IO_read_ptr < _IO_read_end) _IO_read_ptr++; }
    int vscan(char const *fmt0, _IO_va_list ap, ios* stream = NULL);
    int scan(char const *fmt0 ...);
    int vform(char const *fmt0, _IO_va_list ap);
    int form(char const *fmt0 ...);
#if 0 /* Work in progress */
    int column();  // Current column number (of put pointer). -1 is unknown.
    void column(int c);  // Set column number of put pointer to c.
#endif
    virtual streamsize sys_read(char* buf, streamsize size);
    virtual streamsize sys_write(const char*, streamsize);
    virtual streampos sys_seek(streamoff, _seek_dir);
    virtual int sys_close();
    virtual int sys_stat(void*); // Actually, a (struct stat*)
#if _G_IO_IO_FILE_VERSION == 0x20001
    virtual int showmanyc();
    virtual void imbue(void *);
#endif
};

// A backupbuf is a streambuf with full backup and savepoints on reading.
// All standard streambufs in the GNU iostream library are backupbufs.

class filebuf : public streambuf {
  protected:
    void init();
  public:
    static const int openprot; // Non-ANSI AT&T-ism:  Default open protection.
    filebuf();
    filebuf(int fd);
    filebuf(int fd, char* p, int len);
#if !_IO_UNIFIED_JUMPTABLES
    static filebuf *__new();
#endif
    ~filebuf();
    filebuf* attach(int fd);
    filebuf* open(const char *filename, const char *mode);
    filebuf* open(const char *filename, ios::openmode mode, int prot = 0664);
    virtual int underflow();
    virtual int overflow(int c = EOF);
    int is_open() const { return _fileno >= 0; }
    int fd() const { return is_open() ? _fileno : EOF; }
    filebuf* close();
    virtual int doallocate();
    virtual streampos seekoff(streamoff, _seek_dir, int mode=ios::in|ios::out);
    virtual streambuf* setbuf(char* p, int len);
    streamsize xsputn(const char* s, streamsize n);
    streamsize xsgetn(char* s, streamsize n);
    virtual int sync();
  protected: // See documentation in filebuf.C.
//    virtual int pbackfail(int c);
    int is_reading() { return eback() != egptr(); }
    char* cur_ptr() { return is_reading() ?  gptr() : pptr(); }
    /* System's idea of pointer */
    char* file_ptr() { return eGptr(); }
    // Low-level operations (Usually invoke system calls.)
    virtual streamsize sys_read(char* buf, streamsize size);
    virtual streampos sys_seek(streamoff, _seek_dir);
    virtual streamsize sys_write(const char*, streamsize);
    virtual int sys_stat(void*); // Actually, a (struct stat*)
    virtual int sys_close();
#if 0
    virtual uflow;
    virtual showmany;
#endif
};

inline void ios::init(streambuf* sb, ostream* tie_to) {
		_state = sb ? ios::goodbit : ios::badbit; _exceptions=0;
		_strbuf=sb; _tie = tie_to; _width=0; _fill=' ';
#ifdef _IO_NEW_STREAMS
		_flags=ios::skipws|ios::dec;
#else
		_flags=ios::skipws|ios::dec|ios::dont_close;
#endif
		_precision=6; _arrays = 0; }

inline ios::ios(streambuf* sb, ostream* tie_to) { init(sb, tie_to); }

inline ios::~ios() {
#ifndef _IO_NEW_STREAMS
    if (!(_flags & (unsigned int)ios::dont_close)) delete rdbuf();
#endif
    // It is safe to use naked operator delete[] as we know elements have no
    // dtor, and g++ does not add a new[] cookie for such cases.
    operator delete[] (_arrays);
}
} // extern "C++"
#endif /* _STREAMBUF_H */

/* ---- iostream.h ---- */
/*  This is part of libio/iostream, providing -*- C++ -*- input/output.
Copyright (C) 1993 Free Software Foundation

This file is part of the GNU IO Library.  This library is free
software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option)
any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this library; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

As a special exception, if you link this library with files
compiled with a GNU compiler to produce an executable, this does not cause
the resulting executable to be covered by the GNU General Public License.
This exception does not however invalidate any other reasons why
the executable file might be covered by the GNU General Public License. */

#ifndef _IOSTREAM_H
#ifdef __GNUG__
#pragma interface
#endif
#define _IOSTREAM_H


extern "C++" {
class istream; class ostream;
typedef ios& (*__manip)(ios&);
typedef istream& (*__imanip)(istream&);
typedef ostream& (*__omanip)(ostream&);

extern istream& ws(istream& ins);
extern ostream& flush(ostream& outs);
extern ostream& endl(ostream& outs);
extern ostream& ends(ostream& outs);

class ostream : virtual public ios
{
    // NOTE: If fields are changed, you must fix _fake_ostream in stdstreams.C!
    void do_osfx();
  public:
    ostream() { }
    ostream(streambuf* sb, ostream* tied=NULL);
    int opfx() {
	if (!good()) return 0;
	else { if (_tie) _tie->flush(); _IO_flockfile(_strbuf); return 1;} }
    void osfx() { _IO_funlockfile(_strbuf);
		  if (flags() & (ios::unitbuf|ios::stdio))
		      do_osfx(); }
    ostream& flush();
    ostream& put(char c) { _strbuf->sputc(c); return *this; }
#ifdef _STREAM_COMPAT
    /* Temporary binary compatibility.  REMOVE IN NEXT RELEASE. */
    ostream& put(unsigned char c) { return put((char)c); }
    ostream& put(signed char c) { return put((char)c); }
#endif
    ostream& write(const char *s, streamsize n);
    ostream& write(const unsigned char *s, streamsize n)
      { return write((const char*)s, n);}
    ostream& write(const signed char *s, streamsize n)
      { return write((const char*)s, n);}
    ostream& write(const void *s, streamsize n)
      { return write((const char*)s, n);}
    ostream& seekp(streampos);
    ostream& seekp(streamoff, _seek_dir);
    streampos tellp();
    ostream& form(const char *format ...);
    ostream& vform(const char *format, _IO_va_list args);

    ostream& operator<<(char c);
    ostream& operator<<(unsigned char c) { return (*this) << (char)c; }
    ostream& operator<<(signed char c) { return (*this) << (char)c; }
    ostream& operator<<(const char *s);
    ostream& operator<<(const unsigned char *s)
	{ return (*this) << (const char*)s; }
    ostream& operator<<(const signed char *s)
	{ return (*this) << (const char*)s; }
    ostream& operator<<(const void *p);
    ostream& operator<<(int n);
    ostream& operator<<(unsigned int n);
    ostream& operator<<(long n);
    ostream& operator<<(unsigned long n);
#if defined(__GNUC__)
    __extension__ ostream& operator<<(long long n);
    __extension__ ostream& operator<<(unsigned long long n);
#endif
    ostream& operator<<(short n) {return operator<<((int)n);}
    ostream& operator<<(unsigned short n) {return operator<<((unsigned int)n);}
#if _G_HAVE_BOOL
    ostream& operator<<(bool b) { return operator<<((int)b); }
#endif
    ostream& operator<<(double n);
    ostream& operator<<(float n) { return operator<<((double)n); }
#if _G_HAVE_LONG_DOUBLE_IO
    ostream& operator<<(long double n);
#else
    ostream& operator<<(long double n) { return operator<<((double)n); }
#endif
    ostream& operator<<(__omanip func) { return (*func)(*this); }
    ostream& operator<<(__manip func) {(*func)(*this); return *this;}
    ostream& operator<<(streambuf*);
#ifdef _STREAM_COMPAT
    streambuf* ostreambuf() const { return _strbuf; }
#endif
};

class istream : virtual public ios
{
    // NOTE: If fields are changed, you must fix _fake_istream in stdstreams.C!
protected:
    _IO_size_t _gcount;

    int _skip_ws();
  public:
    istream(): _gcount (0) { }
    istream(streambuf* sb, ostream*tied=NULL);
    istream& get(char* ptr, int len, char delim = '\n');
    istream& get(unsigned char* ptr, int len, char delim = '\n')
	{ return get((char*)ptr, len, delim); }
    istream& get(char& c);
    istream& get(unsigned char& c) { return get((char&)c); }
    istream& getline(char* ptr, int len, char delim = '\n');
    istream& getline(unsigned char* ptr, int len, char delim = '\n')
	{ return getline((char*)ptr, len, delim); }
    istream& get(signed char& c)  { return get((char&)c); }
    istream& get(signed char* ptr, int len, char delim = '\n')
	{ return get((char*)ptr, len, delim); }
    istream& getline(signed char* ptr, int len, char delim = '\n')
	{ return getline((char*)ptr, len, delim); }
    istream& read(char *ptr, streamsize n);
    istream& read(unsigned char *ptr, streamsize n)
      { return read((char*)ptr, n); }
    istream& read(signed char *ptr, streamsize n)
      { return read((char*)ptr, n); }
    istream& read(void *ptr, streamsize n)
      { return read((char*)ptr, n); }
    istream& get(streambuf& sb, char delim = '\n');
    istream& gets(char **s, char delim = '\n');
    int ipfx(int need = 0) {
	if (!good()) { set(ios::failbit); return 0; }
	else {
	  _IO_flockfile(_strbuf);
	  if (_tie && (need == 0 || rdbuf()->in_avail() < need)) _tie->flush();
	  if (!need && (flags() & ios::skipws)) return _skip_ws();
	  else return 1;
	}
    }
    int ipfx0() { // Optimized version of ipfx(0).
	if (!good()) { set(ios::failbit); return 0; }
	else {
	  _IO_flockfile(_strbuf);
	  if (_tie) _tie->flush();
	  if (flags() & ios::skipws) return _skip_ws();
	  else return 1;
	}
    }
    int ipfx1() { // Optimized version of ipfx(1).
	if (!good()) { set(ios::failbit); return 0; }
	else {
	  _IO_flockfile(_strbuf);
	  if (_tie && rdbuf()->in_avail() == 0) _tie->flush();
	  return 1;
	}
    }
    void isfx() { _IO_funlockfile(_strbuf); }
    int get() { if (!ipfx1()) return EOF;
		else { int ch = _strbuf->sbumpc();
		       if (ch == EOF) set(ios::eofbit);
		       isfx();
		       return ch;
		     } }
    int peek();
    _IO_size_t gcount() { return _gcount; }
    istream& ignore(int n=1, int delim = EOF);
    int sync ();
    istream& seekg(streampos);
    istream& seekg(streamoff, _seek_dir);
    streampos tellg();
    istream& putback(char ch) {
	if (good() && _strbuf->sputbackc(ch) == EOF) clear(ios::badbit);
	return *this;}
    istream& unget() {
	if (good() && _strbuf->sungetc() == EOF) clear(ios::badbit);
	return *this;}
    istream& scan(const char *format ...);
    istream& vscan(const char *format, _IO_va_list args);
#ifdef _STREAM_COMPAT
    istream& unget(char ch) { return putback(ch); }
    int skip(int i);
    streambuf* istreambuf() const { return _strbuf; }
#endif

    istream& operator>>(char*);
    istream& operator>>(unsigned char* p) { return operator>>((char*)p); }
    istream& operator>>(signed char*p) { return operator>>((char*)p); }
    istream& operator>>(char& c);
    istream& operator>>(unsigned char& c) {return operator>>((char&)c);}
    istream& operator>>(signed char& c) {return operator>>((char&)c);}
    istream& operator>>(int&);
    istream& operator>>(long&);
#if defined(__GNUC__)
    __extension__ istream& operator>>(long long&);
    __extension__ istream& operator>>(unsigned long long&);
#endif
    istream& operator>>(short&);
    istream& operator>>(unsigned int&);
    istream& operator>>(unsigned long&);
    istream& operator>>(unsigned short&);
#if _G_HAVE_BOOL
    istream& operator>>(bool&);
#endif
    istream& operator>>(float&);
    istream& operator>>(double&);
    istream& operator>>(long double&);
    istream& operator>>( __manip func) {(*func)(*this); return *this;}
    istream& operator>>(__imanip func) { return (*func)(*this); }
    istream& operator>>(streambuf*);
};

class iostream : public istream, public ostream
{
  public:
    iostream() { }
    iostream(streambuf* sb, ostream*tied=NULL);
};

class _IO_istream_withassign : public istream {
public:
  _IO_istream_withassign& operator=(istream&);
  _IO_istream_withassign& operator=(_IO_istream_withassign& rhs)
    { return operator= (static_cast<istream&> (rhs)); }
};

class _IO_ostream_withassign : public ostream {
public:
  _IO_ostream_withassign& operator=(ostream&);
  _IO_ostream_withassign& operator=(_IO_ostream_withassign& rhs)
    { return operator= (static_cast<ostream&> (rhs)); }
};

extern _IO_istream_withassign cin;
// clog->rdbuf() == cerr->rdbuf()
extern _IO_ostream_withassign cout, cerr;

extern _IO_ostream_withassign clog
;

extern istream& lock(istream& ins);
extern istream& unlock(istream& ins);
extern ostream& lock(ostream& outs);
extern ostream& unlock(ostream& outs);

struct Iostream_init { } ;  // Compatibility hack for AT&T library.

inline ios& dec(ios& i)
{ i.setf(ios::dec, ios::dec|ios::hex|ios::oct); return i; }
inline ios& hex(ios& i)
{ i.setf(ios::hex, ios::dec|ios::hex|ios::oct); return i; }
inline ios& oct(ios& i)
{ i.setf(ios::oct, ios::dec|ios::hex|ios::oct); return i; }
} // extern "C++"

#endif /*!_IOSTREAM_H*/

/* ---- body ---- */
#define LONGEST long long
int read_int(istream& stream, unsigned LONGEST& val, int& neg);
#define READ_INT(TYPE) \
istream& istream::operator>>(TYPE& i)\
{\
    unsigned LONGEST val; int neg;\
    if (read_int(*this, val, neg)) {\
	if (neg) val = -val;\
	i = (TYPE)val;\
    }\
    return *this;\
}
__attribute__((section(".text.__rs__7istreamRUx")))
READ_INT(unsigned long long)
