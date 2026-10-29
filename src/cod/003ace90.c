/* sn-2.95.3-136 */

#include "godhand/newlibStdio.h"
#include "godhand/newlibStdlib.h"

/* newlib libc/stdlib/strtol.c. */

#define LONG_MAX 0x7FFFFFFFFFFFFFFFL
#define LONG_MIN (-LONG_MAX - 1L)
#define ERANGE 34

/* _strtol_r: convert a string to a long in the given base, setting errno on overflow. */
__attribute__((section(".text.func_003ACE90")))
long func_003ACE90(struct _reent *rptr, const char *nptr, char **endptr, int base)
{
    const char *s = nptr;
    unsigned long acc;
    int c;
    unsigned long cutoff;
    int neg = 0, any, cutlim;

    do {
        c = *s++;
    } while (D_0045F039[c] & 8);
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) &&
        c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
    cutlim = cutoff % (unsigned long)base;
    cutoff /= (unsigned long)base;
    for (acc = 0, any = 0;; c = *s++) {
        if (D_0045F039[c] & 4)
            c -= '0';
        else if (D_0045F039[c] & 3)
            c -= (D_0045F039[c] & 1) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = neg ? LONG_MIN : LONG_MAX;
        rptr->_errno = ERANGE;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = (char *)(any ? s - 1 : nptr);
    return acc;
}
