/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    unsigned char b[0x14];
} sceDmaEnv;

#define D_CTRL (*(volatile unsigned int *)0x1000E000)
#define D_STAT (*(volatile unsigned int *)0x1000E010)

extern int              D_0045DFE0[10];
extern volatile unsigned int *D_003F8590[10];

extern void func_003970C8(sceDmaEnv *env, int size);
extern int  sceDmaPutEnv(sceDmaEnv *env);

__attribute__((section(".text.func_00397128")))
int func_00397128(int mode)
{
    sceDmaEnv env;
    int i;
    int old;

    old = D_CTRL & 1;
    for (i = 0; i < 10; i++) {
        if (D_0045DFE0[i] != 0) {
            volatile unsigned int *p = D_003F8590[i];

            p[0x80 / 4] = 0;
            p[0x00 / 4] = 0;
            p[0x30 / 4] = 0;
            p[0x10 / 4] = 0;
            p[0x50 / 4] = 0;
            p[0x40 / 4] = 0;
        }
    }
    D_STAT = 0xFF1F;
    D_STAT = D_STAT & 0xFF1F0000;
    func_003970C8(&env, 0x14);
    sceDmaPutEnv(&env);
    if (mode == 1)
        D_CTRL = D_CTRL | 1;
    return old;
}
