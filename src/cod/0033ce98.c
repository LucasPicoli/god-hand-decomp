/* cygnus-2.96: stream/SFD/sound singletons. */
#include "godhand/criStm.h"
#include "godhand/globals.h"

typedef struct AdxStatHn {
    char unk00[0x0E];
    char stat;                  /* 0x0E */
    char unk0F[0xE8 - 0x0F];
    int fE8;                    /* 0xE8 */
} AdxStatHn;

extern void func_0033F130(const char *msg);

__attribute__((section(".text.func_0033CE98")))
int func_0033CE98(AdxStatHn *h)
{
    if (h->stat == 1 && h->fE8 != 0) {
        return 2;
    }
    if (h == 0) {
        func_0033F130(D_004568D0);
        return -1;
    }
    return h->stat;
}
