/* cygnus-2.96: stream/SFD/sound singletons. */
#include "godhand/criStm.h"

typedef struct SndObj {
    char unk000[0x38];
    int state;                  /* 0x38 */
    char unk03C[0x48 - 0x3C];
    int f48;                    /* 0x48 */
    char unk04C[0x118 - 0x4C];
    int f118;                   /* 0x118 */
    char unk11C[0x134 - 0x11C];
    int f134;                   /* 0x134 */
} SndObj;

__attribute__((section(".text.calcNumberOfFrameCentreOffsets")))
void calcNumberOfFrameCentreOffsets(SndObj *o)
{
    if (o->f48 == 1 || o->f118 == 1 || o->f118 == 2) {
        o->state = 1;
    } else if (o->f134 == 1) {
        o->state = 3;
    } else {
        o->state = 2;
    }
}
