/* include/godhand/scrTex.h - the five screen-sized texture slots (sn code at 0x30CF10).
 *
 * func_0030CF10 fills the table D_00752780 once at boot: every slot is
 * as wide and as high as the screen, and differs only in the GS TEX0 bits
 * that say which frame buffer page it points at (TBP0, PSM and so on).
 * D_003C1180 and D_003C118C are the screen width and height.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SCRTEX_H
#define GODHAND_SCRTEX_H

#define SCRTEX_NUM          5
#define SCRTEX_KIND_NONE    0xFF

/* GS TEX0 fields: TBW (width in 64-pixel blocks) at bit 14, TW (log2 of the width) at bit 26. */
#define GS_TEX0_TBW(w)      ((long)(((w) + 63) / 64) << 14)
#define GS_TEX0_TW(log2w)   ((long)(log2w) << 26)

#define SCRTEX_TEX0_A       0x600000000L    /* TEX0 high bits shared by four slots */
#define SCRTEX_TEX0_B       0x500000000L    /* TEX0 high bits of the third slot */

typedef struct ScrTex {
    unsigned char used;                 /* 0x00 */
    unsigned char kind;                 /* 0x01 SCRTEX_KIND_NONE until a picture is loaded */
    unsigned char flag;                 /* 0x02 */
    char unk03;
    short w;                            /* 0x04 */
    short h;                            /* 0x06 */
    int unk08;                          /* 0x08 */
    char unk0C[0x18 - 0x0C];
    long tex0;                          /* 0x18 GS TEX0 register */
    long unk20;                         /* 0x20 */
    char unk28[0xB0 - 0x28];
} ScrTex;                               /* 0xB0 */
typedef char ScrTex_size_check[sizeof(ScrTex) == 0xB0 ? 1 : -1];

extern ScrTex D_00752780[SCRTEX_NUM];

#endif
