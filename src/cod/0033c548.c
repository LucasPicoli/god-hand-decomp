/* cygnus-2.96: derive the three 16-bit key words from a key string through the log/exp tables in
 * D_00456080, once per seed. */
#include "godhand/globals.h"
extern void func_0033C520(void);

__attribute__((section(".text.func_0033C548")))
int func_0033C548(signed char *str, int len, short *k0, short *k1, short *k2)
{
    int i;
    short a;
    short b;
    short c;

    if (D_003E9D3C == 0)
        func_0033C520();
    *k0 = 0;
    *k1 = 0;
    *k2 = 0;
    if (str == 0 && len <= 0)
        return 0;
    a = D_00456080[0x100];
    for (i = 0; i < len; i++)
        a = D_00456080[(a * D_00456080[0x80 + str[i]]) % 1024];
    b = D_00456080[0x200];
    for (i = 0; i < len; i++)
        b = D_00456080[(b * D_00456080[0x80 + str[i]]) % 1024];
    c = D_00456080[0x300];
    for (i = 0; i < len; i++)
        c = D_00456080[(c * D_00456080[0x80 + str[i]]) % 1024];
    *k0 = a;
    *k1 = b;
    *k2 = c;
    return 0;
}
