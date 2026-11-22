/* ee-2.9-991111 matched TU. */
#include "godhand/globals.h"

/* ee-2.9-991111 */

extern void func_003B6600(int a, int b);

extern void kFindAddress(void);
extern void func_003B6470(void);

__attribute__((section(".text.InitSystemCallTableAddress")))
void InitSystemCallTableAddress(void)
{
    char *p;
    char *q;
    char *a;
    char *b;

    func_003B6600(D_003FAF08[0], D_003FAF08[1]);
    func_003B6600(D_003FAF08[2], D_003FAF08[3]);
    p = (char *)FindAddress((void *)0x80000000, (void *)0x80080000, (void *)kFindAddress);
    q = (char *)FindAddress((void *)0x80000000, (void *)0x80080000, (void *)func_003B6470);
    a = p - 0x20C;
    b = q - 0x168;
    while (a != b) {
        if (a < b) {
            p = (char *)FindAddress(p + 4, (void *)0x80080000, (void *)kFindAddress);
            a = p - 0x20C;
        } else {
            q = (char *)FindAddress(q + 4, (void *)0x80080000, (void *)func_003B6470);
            b = q - 0x168;
        }
    }
    D_003FAF00 = a;
}
