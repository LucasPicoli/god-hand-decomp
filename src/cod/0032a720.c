#include "godhand/globals.h"
typedef struct {
    char pad0[3];
    signed char nch;
    int sj;
    char pad8[4];
    int rna;
    char pad10[0x42 - 0x10];
    short pan[(0xAC - 0x42) / 2];
    char padAC;
    signed char mode;
} AdxPanHn;

extern void func_0033F130(const char *msg);
extern int func_003278E8(int sj, int ch);
extern int Obj3270_GetVia4_0033CE98_77A0(int sj);
extern void Obj3260_Tramp_003387C8_D3F8(int rna, int ch, int pan);

__attribute__((section(".text.func_0032A720")))
void func_0032A720(AdxPanHn *a, int ch, int pan)
{
    int base;
    int out;

    if (a == 0) {
        func_0033F130(D_004521C8);
        return;
    }
    if (a->mode == 1) {
        base = func_003278E8(a->sj, ch);
        if (base == -128)
            base = 0;
    } else {
        base = 0;
    }
    if (D_003C7410 != 0) {
        out = 0;
    } else if (pan == -128) {
        if (Obj3270_GetVia4_0033CE98_77A0(a->sj) == 2)
            out = ch == 0 ? -15 : 15;
        else
            out = 0;
        out += base;
    } else {
        out = pan + base;
    }
    a->pan[ch] = pan;
    if (ch < a->nch)
        Obj3260_Tramp_003387C8_D3F8(a->rna, ch, out);
    else
        func_0033F130(D_004521F8);
}
