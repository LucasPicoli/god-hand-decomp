/* sn-2.95.3-136 matched TU. */

typedef struct {
    char pad0[0x80];
    char *parts[64];
} Owner;

typedef struct {
    float f[10];
} TblEnt;

typedef struct {
    TblEnt a[5];
    float b[8];
} Tbl;


extern char D_005FEC58[];
extern Tbl D_0041F250;
extern int D_00747A0C;

#define PART(bit, idv, k)                                                   \
    if ((*(int *)(t + 0xC) & (bit)) && n < 2) {                             \
        *(short *)(s->parts[n + 0x2B] + 0x90) = (idv);                      \
        *(float *)(s->parts[n + 0x2B] + 0x40) = D_0041F250.a[D_00747A0C].f[k]; \
        *(int *)(s->parts[n + 0x29] + 0x2C) &= ~0x8000000;                  \
        n++;                                                                \
    }

__attribute__((section(".text.func_0016EE10")))
void func_0016EE10(Owner *s, unsigned short a1)
{
    unsigned char n = 0;
    char *t;

    t = func_002C9060(D_005FEC58, a1);
    if (t == 0)
        return;
    PART(0x10, 0x30C7, 1)
    PART(0x20, 0x30C8, 2)
    PART(0x40, 0x30C9, 3)
    PART(0x80, 0x30CA, 4)
    PART(0x100, 0x30CB, 5)
    PART(0x200, 0x30CC, 6)
    PART(0x400, 0x30CD, 7)
    PART(0x800, 0x30CE, 8)
    PART(0x1000, 0x30CF, 9)
    PART(0x8, 0x30C6, 0)
}
