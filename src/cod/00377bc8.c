/* sn-2.95.3-136: reset a state block and its buffers (0x377BC8). */
#include "godhand/sndBank.h"
#include "godhand/seqNode.h"
#include "godhand/sndTiming.h"
#include "godhand/globals.h"

extern char D_0076B1C0[];
extern void *func_003A52F0(void *p, int c, int n);
extern void func_00377CB8(void);
extern void func_00377D58(void);
extern void func_00377D80(void);
extern void func_00377E28(void);
extern void func_00377ED0(void);
extern void func_00378540(void);

__attribute__((section(".text.func_00377BC8")))
void func_00377BC8(void)
{
    func_003A52F0(&D_0076A790, 0, sizeof(SndTiming));
    __builtin_memcpy(&D_0076A790, D_0045A600, 14);
    D_0076A790.unkA8 = 0xFFFFFFFF;
    D_0076A790.unk1C = 1;
    D_0076A790.unk20 = 0xD37;
    func_00377CB8();
    func_003A52F0(&D_0076A880, 0, 0x104);
    func_003A52F0(D_0076A9C0, 0, sizeof(D_0076A9C0));
    func_003A52F0(D_0076B1C0, 0, 0x800);
    func_00377D58();
    func_00377D80();
    func_00377E28();
    func_00377ED0();
    func_00378540();
}
