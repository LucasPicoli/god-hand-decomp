/* cygnus-2.96: DTX init (reference counted): clear the EE work area, start the RPC client, allocate
 * the IOP buffer, open remote slot 0 and install its callbacks. */
#include "godhand/globals.h"
extern void *D_003E9068;
extern void *func_003A52F0(void *dst, int c, int n);
extern void func_00332508(void);
extern int sceSifAllocIopHeap(int size);
extern void func_003260C8(const char *fmt, ...);
extern void *func_00332178(int id, int buf, int arg2, int bufsize);
extern void func_00332378(void *rmt, void (*fn)(void *obj, void *data), int arg);
extern void func_00332388(void *rmt, void (*fn)(void *obj, void *data), int arg);
extern void func_0033B050(void *unused, void *p);
extern void func_0033B0F0(void *unused, void *out);
extern int DTX_CallUrpc(int fno, int a1, int a2, int a3, int a4);

__attribute__((section(".text.func_0033B218")))
void func_0033B218(void)
{
    if (D_003E8DD4 == 0) {
        func_003A52F0(D_003E9070, 0, 0x8D0);
        func_00332508();
        D_003E906C = 0x880;
        D_003E8DD8 = (int)(D_003E9070 + 0x40) & ~0x3F;
        if (D_003E8DDC == 0) {
            D_003E8DDC = sceSifAllocIopHeap(0x8D0);
            if (D_003E8DDC == 0) {
                func_003260C8(D_00455DC8);
                while (1) {
                }
            }
        }
        D_003E8DE0 = (D_003E8DDC + 0x40) & ~0x3F;
        D_003E9068 = func_00332178(0, D_003E8DD8, D_003E8DE0, D_003E906C);
        if (D_003E9068 == 0) {
            func_003260C8(D_00455DF8);
            while (1) {
            }
        }
        func_00332378(D_003E9068, func_0033B050, 0);
        func_00332388(D_003E9068, func_0033B0F0, 0);
        DTX_CallUrpc(3, 0, 0, 0, 0);
    }
    D_003E8DD4++;
}
