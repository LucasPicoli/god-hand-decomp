#include "godhand/globals.h"
typedef struct {
    char pad0[0x4C];
    int chbuf; /* 0x4C */
    int pool; /* 0x50 */
    int num; /* 0x54 */
    int work; /* 0x58 */
} ChMgr;
extern ChMgr D_00766CE8;
extern void func_00366C50(int dst, int c, int n);
extern void func_0036C438(int pool, int size);
extern void func_0036D6B0(ChMgr *mgr, char *name, unsigned int n);

__attribute__((section(".text.func_0036C0B0")))
void func_0036C0B0(int num, int addr)
{
    int work = (addr + 0x3F) & ~0x3F;
    int chbuf;
    int pool;

    func_00366C50(work, 0, (num * 0x118) + 0x800);
    chbuf = work + num * 0x440;
    pool = chbuf + 0x420;
    func_0036C438(pool, 0x1BE0);
    func_0036D6B0(&D_00766CE8, D_0045A420, 0x10);
    D_00766CE8.chbuf = chbuf;
    D_00766CE8.pool = pool;
    D_00766CE8.num = num;
    D_00766CE8.work = work;
}
