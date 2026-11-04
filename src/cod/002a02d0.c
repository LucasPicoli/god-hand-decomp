/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

#include "godhand/gsPacket.h"

typedef unsigned int u_int;

__attribute__((section(".text.func_002A02D0")))
void func_002A02D0(char *ctx, int p1, int p2, int xo, int yo, int fix)
{
    int i;
    int yh = yo >> 1;

    PushEntryAtField10000_299868(ctx, 0x3F, 0xFF);
    PushEntryAtField10000_299868(ctx, 0, 0x356);
    PushEntryAtField10000_299868(ctx, 0x4D,
        GS_SET_FRAME((D_003C11AC + D_003C11C8 * p2) >> 5, D_003C1180 / 128, 0, 0));
    PushEntryAtField10000_299868(ctx, 0x43, GS_SET_ALPHA(0, 1, 2, 1, fix));
    PushEntryAtField10000_299868(ctx, 7,
        GS_SET_TEX0(D_003C11AC + D_003C11C8 * p1, D_003C1180 / 128, 0, 8, D_003C11BC, 1, 1, 0, 0, 1, 0, 2));
    PushEntryAtField10000_299868(ctx, 0x15, 0x60);
    for (i = 0; i < D_003C1180 / 64; i++) {
        PushEntryAtField10000_299868(ctx, 0x41,
            GS_SET_SCISSOR(i * 32, i * 32 + 0x1F, 0, D_003C11B4 - 1));
        PushEntryAtField10000_299868(ctx, 3,
            GS_SET_UV(*(u_int *)(ctx + 0x10018) << 4, *(u_int *)(ctx + 0x10018) << 4));
        PushEntryAtField10000_299868(ctx, 0xD,
            GS_SET_XYZ(((0x800 - D_003C1180 / 2) << 4) + xo, (D_00586B80 << 4) + yh, 0xFFFF));
        PushEntryAtField10000_299868(ctx, 3,
            GS_SET_UV((D_003C1180 / 2 << 4) + *(u_int *)(ctx + 0x10018) * 0x12,
                      (D_003C118C / 2 << 4) + *(u_int *)(ctx + 0x10018) * 0x12));
        PushEntryAtField10000_299868(ctx, 5,
            GS_SET_XYZ(0x8000 + xo, ((D_00586B80 + D_003C118C / 2) << 4) + yh, 0xFFFF));
    }
    *(int *)(ctx + 0x10018) ^= 1;
}
