#include "godhand/cScenario.h"
#include "godhand/globals.h"
typedef struct { char pad[0x10]; unsigned char type; } LookupEnt;

extern int D_00747A30;
extern LookupEnt *func_002C5028(cScenario *sc, unsigned short id);
extern int func_003A6C58(char *buf, const char *fmt, ...);
extern void func_002BE838(void *a0, char *name, int a2);

__attribute__((section(".text.func_002BE708")))
void func_002BE708(void *self, int arg)
{
    char buf[64];
    unsigned short id = arg;
    LookupEnt *e = func_002C5028(D_003C2F84, id);
    unsigned int hi;
    int lo;

    if (e == 0 || e->type != 1) return;
    hi = id >> 8;
    lo = id & 0xFF;
    if (hi == 0 && lo >= 0x40) {
        if (lo < 0x46) goto set;
        if (lo < 0x4E) {
            if (lo >= 0x4C) {
            set:
                lo = 0x40;
            }
        }
    }
    if (D_00747A30 & 0x400) {
        if (hi == 15)
            func_003A6C58(buf, D_0044C0E0, 15, lo);
        else
            func_003A6C58(buf, D_0044C118, hi, lo);
    } else {
        if (hi == 15)
            func_003A6C58(buf, D_0044C150, 15, lo);
        else
            func_003A6C58(buf, D_0044C170, hi, lo);
    }
    func_002BE838(self, buf, 0);
}
