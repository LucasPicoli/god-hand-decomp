/* sn-2.95.3-136: append an image upload (BITBLTBUF/TRXREG/TRXDIR + IMAGE data tag) to the double-buffered
 * DMA packet list and queue it. Sibling of func_00150DC8. */
#include "godhand/gameWork.h"

typedef unsigned long u64;

extern int D_007476B0;
extern char D_00754C80[];
extern void func_0031A650(void *queue, int kind, int id, void *start, void *end);

#define IMAGEUP_MAX  0x280

/* The image upload list: a count, then one slot per upload holding a packet for each frame buffer. */
typedef struct ImageUpList {
    char unk00[0x3C];
    int num;                            /* 0x3C uploads queued */
    char slot[IMAGEUP_MAX][2][0xC0];    /* 0x40 */
} ImageUpList;

__attribute__((section(".text.func_00151168")))
int func_00151168(ImageUpList *list, int src, int psm, int dbp, int unused, int width, int height, int mode, int kind)
{
    int n;
    char *p;
    int qwc;

    if (mode >= 0 && (D_00747A2C.unk00 & 0x800))
        return -1;
    n = list->num;
    if (n == IMAGEUP_MAX)
        return -1;
    p = list->slot[n][D_007476B0 & 1];
    list->num = n + 1;
    width /= 2;
    if (psm == 0x14)
        height /= 4;
    else if (psm == 0x13)
        height /= 2;
    qwc = (width * height) >> 2;
    *(u64 *)p = ((u64)((int)(p + 0x70) & 0x0FFFFFFF) << 32) | 0x20000006;
    *(int *)(p + 0xC) = 0x50000006;
    *(u64 *)(p + 0x20) = ((u64)dbp << 32) | ((u64)(width / 64) << 48);
    *(u64 *)(p + 0x40) = width | ((u64)height << 32);
    *(u64 *)(p + 0x60) = (u64)(unsigned int)(qwc | 0x8000) | ((u64)0x8000 << 44);
    *(u64 *)(p + 0x70) = (u64)(unsigned int)(qwc | 0x30000000)
                              | ((u64)(src & 0x0FFFFFFF) << 32);
    *(int *)(p + 0x7C) = qwc | 0x50000000;
    if (kind == 0 || kind == 3)
        func_0031A650(D_00754C80, 1, 0xE, p, p + 0x80);
    else if (kind == 2)
        func_0031A650(D_00754C80, 6, 8, p, p + 0x80);
    else if (kind == 1)
        func_0031A650(D_00754C80, 1, 2, p, p + 0x80);
    return 0;
}
