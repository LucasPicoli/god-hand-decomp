/* sn-2.95.3-136: newlib _strtoul_r. D_0045F039 is _ctype_ + 1 (bits: 1 upper, 2 lower, 4 digit, 8 space). */
extern unsigned char D_0045F039[];

struct _reent { int _errno; };

__attribute__((section(".text.func_003A9018")))
unsigned long func_003A9018(struct _reent *rptr, const char *nptr, char **endptr, int base)
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
    cutoff = (unsigned long)-1 / (unsigned long)base;
    cutlim = (unsigned long)-1 % (unsigned long)base;
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
        acc = (unsigned long)-1;
        rptr->_errno = 34;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = (char *)(any ? s - 1 : nptr);
    return acc;
}
