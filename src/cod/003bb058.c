/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136: libstdc++ basic_string<char>::Rep::clone, from std/bastring.h. */
#include "godhand/globals.h"

typedef unsigned int size_t;

typedef struct Rep {
    size_t len;                 /* 0x0 */
    size_t res;                 /* 0x4 */
    size_t ref;                 /* 0x8 */
    int selfish;                /* 0xC */
} Rep;

extern void *func_003A7C70(size_t);                           /* malloc */
extern void *func_0031D6E8(size_t);                           /* _S_oom_malloc */
extern void *func_0031D928(size_t);                           /* _S_refill */
extern void func_003A5148(char *, const char *, size_t);      /* memcpy */

/* Rep::copy: copy n characters to data() + pos. */
static __inline__ void Rep_copy(Rep *self, size_t pos, const char *s, size_t n)
{
    if (n)
        func_003A5148((char *)(self + 1) + pos, s, n);
}

/* Rep::clone: make an unshared copy of a string body and return its characters. */
__attribute__((section(".text.func_003BB058")))
char *func_003BB058(Rep *self)
{
    size_t ss;
    size_t i;
    size_t nb;
    Rep *p;

    ss = self->len + 1;
    i = 16;
    while (i < ss)
        i *= 2;
    nb = i + 16;
    if (nb > 128) {
        void *r = func_003A7C70(nb);
        if (r == 0)
            r = func_0031D6E8(nb);
        p = (Rep *)r;
    } else {
        size_t idx;
        void **fl;
        void *q;
        idx = (nb + 7) / 8;
        idx = idx - 1;
        fl = D_003C4030 + idx;
        q = *fl;
        if (q == 0) {
            p = (Rep *)func_0031D928((nb + 7) & ~7);
        } else {
            *fl = *(void **)q;
            p = (Rep *)q;
        }
    }
    p->res = i;
    p->ref = 1;
    p->selfish = 0;
    Rep_copy(p, 0, (char *)(self + 1), self->len);
    p->len = self->len;
    return (char *)(p + 1);
}
