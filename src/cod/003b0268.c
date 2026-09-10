/* ee-2.9-991111 matched TU. */

extern int _sceSnprintf(void *cb, void *state, int a, int b, void *ap);
extern void func_003B7AA8(char *s);
extern int D_003FAE4C;
extern char D_0077E3A0[];
extern int Tramp_003B4AD8_1F6E98(void *buf, int n);
extern char D_003FAE30[];
extern int NoOp_1F6ED8(void *buf, int n);
extern int CreateSema(struct SemaParam *p);
extern char D_00460370[];
extern char D_00460380[];
extern int D_003FAF18;
extern int D_003FAF1C;

/* ee-2.9-991111 */

__attribute__((section(".text.func_003B1DE8")))
int func_003B1DE8(char **pp, int *pn, int c)
{
    char *p;
    if (*pn == 0)
        return 1;
    if (c < 0x100) {
        if (*pn == 1)
            c = 0;
        p = *pp;
        *p = c;
        p = p + 1;
        *pn = *pn - 1;
        *pp = p;
        return 1;
    }
    **pp = 0;
    return 0;
}

/* ee-2.9-991111 */



typedef void *va_list;
#define va_start(ap, last) (ap = (void *)((char *)__builtin_next_arg(last) - 0x20))
#define va_end(ap)

__attribute__((section(".text._sceSnprintf_pf")))
int _sceSnprintf_pf(void *cb, void *state, int *pn, int fmt, ...) {
    int n;
    va_list ap;
    va_start(ap, fmt);
    n = _sceSnprintf(cb, state, *pn, fmt, ap);
    *pn = *pn - n;
    return n;
}

/* ee-2.9-991111 */





__attribute__((section(".text.deci2Putchar")))
void deci2Putchar(int c)
{
    int n;
    if (D_003FAE4C >= 0x7E) {
        D_003FAE4C = 0;
        D_0077E3A0[0x7F] = 0;
        func_003B7AA8(D_0077E3A0);
    }
    n = D_003FAE4C;
    if (c == 0xA) {
        D_003FAE4C = 0;
        D_0077E3A0[n] = c;
        D_0077E3A0[n + 1] = 0;
        func_003B7AA8(D_0077E3A0);
        return;
    }
    D_003FAE4C = n + 1;
    D_0077E3A0[n] = c;
}

/* ee-2.9-991111 */





__attribute__((section(".text.write")))
int write(int fd, void *buf, int n)
{
    if (fd == 1 || fd == 2) {
        if (*(int *)(D_003FAE30 + 0x10) == 0) {
            if (func_001F6E68() == 0)
                return -1;
            *(int *)(D_003FAE30 + 0x10) = 1;
        }
        return Tramp_003B4AD8_1F6E98(buf, n);
    }
    return -1;
}

/* ee-2.9-991111 */





__attribute__((section(".text.read")))
int read(int fd, void *buf, int n)
{
    if (fd == 0) {
        if (*(int *)(D_003FAE30 + 0x10) == 0) {
            if (func_001F6E68() == 0)
                return -1;
            *(int *)(D_003FAE30 + 0x10) = 1;
        }
        return NoOp_1F6ED8(buf, n);
    }
    return -1;
}

/* ee-2.9-991111 */

struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};







__attribute__((section(".text.supplement_crt0")))
void supplement_crt0(void)
{
    struct SemaParam s1;
    struct SemaParam s2;

    s1.maxCount = 1;
    s1.initCount = 1;
    s1.option = (unsigned int)D_00460370;
    s2.maxCount = 1;
    s2.initCount = 1;
    s2.option = (unsigned int)D_00460380;
    D_003FAF18 = CreateSema(&s1);
    D_003FAF1C = CreateSema(&s2);
}
