#include "godhand/globals.h"
#include "godhand/criCbTbl.h"
extern void *func_003A52F0(void *d, int c, unsigned int n);
extern char D_003E9970[];
extern char D_007588C0[];
extern char D_007588C8[];

__attribute__((section(".text.func_0033BDD8")))
void func_0033BDD8(void)
{
    int i;
    int *p;

    func_003A52F0(D_003E9970, 0, 0x20);
    func_003A52F0(&D_007588A0, 0, sizeof(D_007588A0));
    func_003A52F0(&D_007588A8, 0, sizeof(D_007588A8));
    func_003A52F0(D_007588C0, 0, 8);
    func_003A52F0(D_007588C8, 0, 8);
    p = D_003E9950;
    for (i = 0; i < 6; i++) {
        *p++ = 0;
    }
    D_007588B8 = 0;
}
