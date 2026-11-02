/* sn-2.95.3-136, -fmove-all-movables: retail hoists the 64-bit constants into saved
 * registers before the loop and sets up the i*32+0x1F counter after them. */
#include "godhand/gsPacket.h"

#define CLEAR_PRIM   0x306              /* a sprite, with FST and context 2 set */
#define CLEAR_Z      0xFFFF
#define CLEAR_STRIP  32                 /* scissor strip width, pixels */

/* Clear frame buffer p to black, one 32-pixel scissored strip at a time. */
__attribute__((section(".text.func_0029FDE0")))
void func_0029FDE0(char *ctx, int p)
{
    int i;

    PushEntryAtField10000_299868(ctx, GS_TEXFLUSH, GS_TEXFLUSH_DATA);
    PushEntryAtField10000_299868(ctx, GS_PRIM, CLEAR_PRIM);
    PushEntryAtField10000_299868(ctx, GS_FRAME_2,
        GS_SET_FRAME((D_003C11AC + D_003C11C8 * p) >> 5, D_003C1180 / 128, 0, 0));
    for (i = 0; i < D_003C1180 / 64; i++) {
        PushEntryAtField10000_299868(ctx, GS_SCISSOR_2,
            GS_SET_SCISSOR(i * CLEAR_STRIP, i * CLEAR_STRIP + CLEAR_STRIP - 1, 0, D_003C11B4 - 1));
        PushEntryAtField10000_299868(ctx, GS_XYZ3,
            GS_SET_XYZ((GS_WINDOW_CENTER - D_003C1180 / 2) << 4, D_00586B80 << 4, CLEAR_Z));
        PushEntryAtField10000_299868(ctx, GS_XYZ2,
            GS_SET_XYZ(GS_WINDOW_CENTER << 4, (D_00586B80 + D_003C11B4) << 4, CLEAR_Z));
    }
}
