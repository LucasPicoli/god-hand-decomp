#include "godhand/globals.h"
typedef struct {
    char pad0[0x4C];
    int chbuf; /* 0x4C */
    int pool; /* 0x50 */
    int num; /* 0x54 */
    int work; /* 0x58 */
} ChMgr;
extern ChMgr D_00766CE8;
extern void UTY_MemsetDword(int dst, int c, int n);
extern void func_0036C438(int pool, int size);
extern void UTY_MemcpyDword(ChMgr *mgr, char *name, unsigned int n);

__attribute__((section(".text.mpvlib_InitWork")))
void mpvlib_InitWork(int num, int addr)
{
    int work = (addr + 0x3F) & ~0x3F;
    int chbuf;
    int pool;

    UTY_MemsetDword(work, 0, (num * 0x118) + 0x800);
    chbuf = work + num * 0x440;
    pool = chbuf + 0x420;
    func_0036C438(pool, 0x1BE0);
    UTY_MemcpyDword(&D_00766CE8, D_0045A420, 0x10);
    D_00766CE8.chbuf = chbuf;
    D_00766CE8.pool = pool;
    D_00766CE8.num = num;
    D_00766CE8.work = work;
}
