/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"
extern void *func_003A5148(void *dst, const void *src, _IO_size_t n); /* memcpy */

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
