#include "godhand/globals.h"
extern char *func_003A95A8(char *s);

__attribute__((section(".text.func_003A9620")))
char *func_003A9620(int value, char *str, int base)
{
    unsigned int u;
    int neg;
    int i;

    u = (unsigned int)value;
    neg = (int)(u >> 31);
    if (neg) {
        if (base == 10)
            u = 0u - u;
    }
    i = 0;
    do {
        str[i] = D_003FA998[u % (unsigned int)base];
        u = u / (unsigned int)base;
        i = i + 1;
    } while (u != 0);
    if (neg) {
        str[i] = '-';
        i = i + 1;
    }
    str[i] = 0;
    return func_003A95A8(str);
}
