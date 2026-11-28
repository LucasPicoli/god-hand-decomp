/* sn-2.95.3-136 matched TU. */
#include "godhand/gameWork.h"
#include "godhand/sceDma.h"
#include "godhand/cSnd.h"
#include "godhand/cMovie.h"
#include "godhand/sync.h"
#include "godhand/vblank.h"

#define GS_CSR      ((volatile unsigned long *)0x12001000)
#define GS_CSR_FIELD_SHIFT 13
#define EE_T0_COUNT ((volatile int *)0x10000000)

/* Sends the waiting packet once GIF is idle and at least limit vblanks have
 * passed. A macro, not an inline function: retail reads limit after the DMA
 * test, where an inline function reads it before the call. With limit 0 the
 * test always passes, and retail still reads the counter. */
#define VBLANK_SEND_PACKET(limit)                                               \
    {                                                                           \
        if (D_00753D84 != 0 && sceDmaSync(SCE_DMA_GIF, 1, 0) == 0               \
            && D_00753D80 >= (limit)) {                                         \
            sceDmaSend(SCE_DMA_GIF, D_00752D80);                                \
            D_00753D84 = 0;                                                     \
        }                                                                       \
    }

/* Vblank handler: counts the vblank, sends the waiting packet, steps the sound
 * (NTSC) or restarts timer 0 after a movie start (PAL), and latches the field. */
__attribute__((section(".text.func_0030B148")))
int func_0030B148(void)
{
    D_00753D80++;
    if (!GameWork_isPal()) {
        VBLANK_SEND_PACKET(D_007474A0.unk569)
        func_002CA690(&D_005FEE00);
    } else {
        VBLANK_SEND_PACKET(0)
        if (D_003C3CD4 != 0) {
            D_003C3CD4 = 0;
            *EE_T0_COUNT = 0;
        }
    }
    D_007474A0.field = (*GS_CSR >> GS_CSR_FIELD_SHIFT) & 1;
    GH_SYNC();
    GH_EI();
    return 1;
}
