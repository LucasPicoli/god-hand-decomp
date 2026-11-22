/* cygnus-2.96: func_003580E8, in mode 4 check whether timer 0x36 (started on first use with the
 * longest whole-second span the tick rate allows) has passed the current position. */
#include "godhand/globals.h"
extern int func_0035AAC8(void *self, int *pos, int *len);
extern int GetArrayElemA0C_35A1C8(void *self, int idx);
extern void func_0035A000(void *self, int idx, int val);
extern int func_0035AEC8(int limit, int scale, int pos, int len);

__attribute__((section(".text.func_003580E8")))
int func_003580E8(char *self)
{
    int pos;
    int len;
    int limit;
    char *sub = self + 0x950;

    if (*(int *)(self + 0x48) != 4)
        goto fail;
    if (*(int *)(self + 0x50) == 1 || *(int *)(sub + 0x20) == 1)
        return 0;
    if (func_0035AAC8(self, &pos, &len) != 0) {
    fail:
        return 0;
    }
    if (pos >= 0) {
        limit = GetArrayElemA0C_35A1C8(self, 0x36);
        if (limit == -1) {
            limit = 0x7FFFFFFF / D_003EE278 * 1000 - 1000;
            func_0035A000(self, 0x36, limit);
        }
        return func_0035AEC8(limit, 1000, pos, len) != 0;
    }
    return 0;
}
