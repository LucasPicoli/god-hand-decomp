/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef signed int  Sint32;

typedef struct {
    Sint32 f0;
    Sint8  pad4[252];
} MPS;

typedef struct {
    Sint32 pad0[3];
    Sint32 num;
    MPS    hn[1];
} MPSLIB;

extern MPSLIB *D_003F1A98;

extern void MPS_Destroy(MPS *p);
extern void func_00366D20(void);
extern void func_00368AA8(void);

__attribute__((section(".text.func_00368DF0")))
void func_00368DF0(void)
{
    MPSLIB *lib = D_003F1A98;
    MPS *p;
    MPS *q;
    Sint32 i;
    Sint32 n;

    q = lib->hn;
    n = lib->num;
    if (n > 0) {
        p = q;
        i = n;
        do {
            if (p->f0 != 1) {
                MPS_Destroy(p);
            }
            i--;
            p++;
        } while (i != 0);
    }
    func_00366D20();
    func_00368AA8();
}
