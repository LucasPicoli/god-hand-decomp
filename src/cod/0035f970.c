/* cygnus-2.96 matched TU. */
#include "godhand/sfxlib.h"
#include "godhand/StageBuf.h"
#include "godhand/globals.h"

extern int D_003EE338[];                /* [0] open handle count, [1] number of records */

/* Open an SFX handle: take a free record, check the work size, set the record
 * up over the work buffer and create its Z and A handles. */
__attribute__((section(".text.func_0035F970")))
StageBuf *func_0035F970(int work, int size, int a2, int a3)
{
    StageBuf *hn;
    void *zhn;
    void *ahn;

    hn = func_0035FA88();
    if (hn == 0)
        return 0;
    if (func_0035FB78(size, a2, a3) != 1) {
        SFXLIB_Error(0, 0, D_00459FE0);
        return 0;
    }
    StageBuf_init(hn, work, size);
    zhn = func_0035FEF0();
    if (zhn == 0) {
        SFXLIB_Error(0, 0, D_0045A010);
        func_0035FB88((int)hn);
        return 0;
    }
    hn->zhn = zhn;
    ahn = func_0036CAB0();
    if (ahn == 0) {
        SFXLIB_Error(0, 0, D_0045A030);
        func_0035FB88((int)hn);
        return 0;
    }
    D_003EE338[0]++;
    hn->ahn = ahn;
    return hn;
}
