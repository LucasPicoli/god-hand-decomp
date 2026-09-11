/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

extern void *func_003A5148(void *d, const void *s, int n);   /* memcpy */

__attribute__((section(".text.copy2area")))
int copy2area(char *d0, int n0, char *d1, int n1,
              char *src, int len, char *src2, int len2)
{
    int tot = len + len2;
    int rem;

    if (n0 + n1 < tot)
        return 0;
    if (len >= n0) {
        func_003A5148(d0, src, n0);
        func_003A5148(d1, src + n0, len - n0);
        func_003A5148(d1 + len - n0, src2, len2);
    } else {
        rem = n0 - len;
        if (len2 >= rem) {
            func_003A5148(d0, src, len);
            func_003A5148(d0 + len, src2, rem);
            func_003A5148(d1, src2 + n0 - len, len2 - rem);
        } else {
            func_003A5148(d0, src, len);
            func_003A5148(d0 + len, src2, len2);
        }
    }
    return tot;
}
