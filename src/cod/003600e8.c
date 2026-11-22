#include "godhand/globals.h"
extern char D_0045A068[];
extern void func_00360200(void *a0, const char *key, const char *sect, char **out, int *len);
extern int func_003A6CE0(const char *s, const char *fmt, ...);
extern long long func_0031DE10(long long v, int idx);

__attribute__((section(".text.func_003600E8")))
void func_003600E8(void *src, int idx, int *a, int *b)
{
    char *p;
    char *q;
    int len;
    long long v;
    long long name;
    long long x;
    int y;

    func_00360200(src, D_0045A078, D_0045A068, &p, &len);
    if (p == 0) {
        *a = 0;
        *b = 0x7FFFFFFF;
        return;
    }
    func_003A6CE0(p, D_0045A080, &v);
    func_00360200(src, D_0045A088, D_0045A068, &p, &len);
    q = p;
    if (q == 0) {
        *a = 0x7FFFFFFF;
        return;
    }
    func_003A6CE0(q + (int)func_0031DE10(v, idx), D_0045A090, &name, &x, &y);
    *a = x;
    *b = y;
}
