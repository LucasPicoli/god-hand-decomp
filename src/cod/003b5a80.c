/* ee-2.9-991111 matched TU. */
#include "godhand/globals.h"

/* ee-2.9-991111 */

typedef struct { int f[16]; } Cd;
typedef struct { char b[4]; } T4;



extern Cd D_00781B80;
extern char D_00781980[];

__attribute__((section(".text.func_003B5A80")))
int func_003B5A80(void)
{
    Cd *cd;
    int i;

    if (D_003FAEF8 < 0) {
retry:
        cd = &D_00781B80;
        if (sceSifBindRpc(cd, 0x80000006, 0) < 0)
            return -1;
        if (cd->f[9] != 0) {
            D_003FAEF8 = 0;
            if (func_003B3128(cd, 0xFF, 0, 0, 0, D_00781980, 4, 0, 0) < 0)
                return 0xFFFEFFFF;
            *(T4 *)D_00781BA8 = *(T4 *)D_00781980;
            return 0;
        }
        for (i = 0x100000; i != -1; i--)
            ;
        goto retry;
    }
    return 0;
}
