/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"



__attribute__((section(".text.getToolVer")))
int getToolVer(char *str, int *maj, int *min)
{
    char *p;

    p = strstr(str, D_00459C48);
    if (p == 0) return 0;
    convAsciiToDigit(convAsciiToDigit(p + 4, maj) + 1, min);
    return 1;
}
