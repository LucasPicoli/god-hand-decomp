/* cygnus-2.96: func_00360878, scans a buffer for a tag signature and reports the last hit and its length. */
#include "godhand/globals.h"
extern int func_003A50B4(const void *a, const void *b, int n);
extern int func_00360940(char *p);

__attribute__((section(".text.func_00360878")))
void func_00360878(char *data, int size, int *out, int *outLen)
{
    int i;

    *outLen = 0;
    *out = 0;
    if (data == 0 || size <= 0)
        return;
    for (i = 0; i < size; i++, data++) {
        if (func_003A50B4(data, D_0045A258, 1) == 0 && func_003A50B4(data, D_0045A1E8, 8) == 0) {
            *out = (int)data;
            *outLen = func_00360940(data);
        }
    }
}
