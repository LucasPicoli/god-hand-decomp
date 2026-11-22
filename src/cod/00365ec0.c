/* cygnus-2.96 matched TU. */
#include "godhand/SfdYuv.h"

/* Fill the luma and the two chroma blocks of the YUV tables, then the luma
 * ramp: alpha << 6 on one side of lo..hi, 0 on the other and a linear slope
 * between them, falling when mode is 1 and rising otherwise. */
__attribute__((section(".text.CFT_MakeArgb8888AlpLumiTbl")))
void CFT_MakeArgb8888AlpLumiTbl(int mode, int lo, int hi, SfdYuvTab *tab)
{
    SfdYuvEnt *luma = tab->luma;
    SfdYuvEnt *blue = tab->blue;
    SfdYuvEnt *red = tab->red;
    int i;
    short y;
    int c;
    int alpha;
    int range;
    float scale;

    alpha = func_00360D50();
    for (i = 0; i < SFDYUV_NUM; i++) {
        y = (i - SFDYUV_LUMA_BIAS) * SFDYUV_Y_SCALE + SFDYUV_ROUND;
        c = i - SFDYUV_CHROMA_BIAS;
        luma[i].h4 = y;
        luma[i].h2 = y;
        luma[i].h0 = y;
        blue[i].h4 = c * SFDYUV_B_U + SFDYUV_ROUND;
        blue[i].h2 = c * SFDYUV_G_U + SFDYUV_ROUND;
        blue[i].h0 = 0;
        blue[i].h6 = 0;
        red[i].h2 = c * SFDYUV_G_V + SFDYUV_ROUND;
        red[i].h0 = c * SFDYUV_R_V + SFDYUV_ROUND;
        red[i].h4 = 0;
        red[i].h6 = 0;
    }
    range = hi - lo;
    scale = (float)alpha / (float)range;
    if (mode == 1) {
        for (i = 0; i < SFDYUV_NUM; i++) {
            if (i < lo) {
                luma[i].h6 = alpha << 6;
            } else if (i > hi) {
                luma[i].h6 = 0;
            } else {
                luma[i].h6 = (int)((range - (i - lo)) * scale) << 6;
            }
        }
    } else {
        for (i = 0; i < SFDYUV_NUM; i++) {
            if (i < lo) {
                luma[i].h6 = 0;
            } else if (i > hi) {
                luma[i].h6 = alpha << 6;
            } else {
                luma[i].h6 = (int)((i - lo) * scale) << 6;
            }
        }
    }
}
