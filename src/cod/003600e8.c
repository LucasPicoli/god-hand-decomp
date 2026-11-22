#include "godhand/globals.h"
extern char D_0045A068[];
extern void sfxzmv_GetZfrmInf(void *a0, const char *key, const char *sect, char **out, int *len);
extern int sscanf(const char *s, const char *fmt, ...);
extern long long func_0031DE10(long long v, int idx);

__attribute__((section(".text.SFXZ_GetZfrmRange")))
void SFXZ_GetZfrmRange(void *src, int idx, int *a, int *b)
{
    char *p;
    char *q;
    int len;
    long long v;
    long long name;
    long long x;
    int y;

    sfxzmv_GetZfrmInf(src, D_0045A078, D_0045A068, &p, &len);
    if (p == 0) {
        *a = 0;
        *b = 0x7FFFFFFF;
        return;
    }
    sscanf(p, D_0045A080, &v);
    sfxzmv_GetZfrmInf(src, D_0045A088, D_0045A068, &p, &len);
    q = p;
    if (q == 0) {
        *a = 0x7FFFFFFF;
        return;
    }
    sscanf(q + (int)func_0031DE10(v, idx), D_0045A090, &name, &x, &y);
    *a = x;
    *b = y;
}
