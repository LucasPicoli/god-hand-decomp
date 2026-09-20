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

__attribute__((section(".text.func_00369020")))
MPS *func_00369020(void)
{
    MPSLIB *lib = D_003F1A98;
    MPS *p;
    MPS *q;
    Sint32 i = 0;
    Sint32 n;

    n = lib->num;
    q = lib->hn;
    if (n > 0) {
        p = q;
        do {
            if (p->f0 == 1) {
                return p;
            }
            p++;
            i++;
        } while (i < n);
    }
    return 0;
}
