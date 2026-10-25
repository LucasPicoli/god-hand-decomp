/* include/godhand/SfdYuv.h - the YUV to RGB lookup tables of a Sofdec decoder (cygnus code at 0x365EC0).
 *
 * The tables hold 256 entries of four 16-bit words each, in three blocks:
 * the luma term, the blue and green terms of the blue difference, the red
 * and green terms of the red difference. The first block's fourth word is
 * a clamp ramp that the same routine fills in for the chroma range.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SFDYUV_H
#define GODHAND_SFDYUV_H

#define SFDYUV_NUM       256
#define SFDYUV_LUMA_BIAS 16
#define SFDYUV_CHROMA_BIAS 128
#define SFDYUV_ROUND     0.5f

/* BT.601 coefficients scaled by 64, the units the tables are kept in. */
#define SFDYUV_Y_SCALE   74.495995f
#define SFDYUV_R_V       102.144f
#define SFDYUV_B_U       129.088f
#define SFDYUV_G_U       (-25.088f)
#define SFDYUV_G_V       (-52.031998f)

typedef struct SfdYuvEnt {
    short h0, h2, h4, h6;               /* 0x00 */
} SfdYuvEnt;                            /* 8 */

typedef struct SfdYuvTab {
    SfdYuvEnt luma[SFDYUV_NUM];         /* 0x000 h0, h2, h4 = Y; h6 = ramp */
    SfdYuvEnt blue[SFDYUV_NUM];         /* 0x800 h4 = B-U, h2 = G-U */
    SfdYuvEnt red[SFDYUV_NUM];          /* 0x1000 h0 = R-V, h2 = G-V */
} SfdYuvTab;

extern int func_00360D50(void);

#endif
