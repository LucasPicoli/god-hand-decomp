/* include/godhand/GsImageObj.h - an object that owns one GS image upload
 * packet (GsLoadImagePacket, see gsLoadImage.h) at offset 0xB0. Its upload
 * routine fills the packet for a texture of any pixel format: it picks the
 * bytes per pixel row from the format, splits the image into the rows that
 * fit one 0x80000-byte block, and writes the DMA chain.
 *
 * Offsets are exact; fields nobody has named stay as unkNN padding.
 */
#ifndef GODHAND_GSIMAGEOBJ_H
#define GODHAND_GSIMAGEOBJ_H

#include "godhand/gsLoadImage.h"

#define GSIMAGE_PKT_OFFSET   0xB0
#define GSIMAGE_BLOCK_BYTES  0x80000    /* the most image bytes one chain moves */

/* GS pixel storage modes the upload accepts (the rest are ignored). */
#define GS_PSM_CT32    0x00
#define GS_PSM_CT24    0x01
#define GS_PSM_CT16    0x02
#define GS_PSM_CT16S   0x0A
#define GS_PSM_T8      0x13
#define GS_PSM_T4      0x14
#define GS_PSM_T8H     0x1B
#define GS_PSM_T4HL    0x24
#define GS_PSM_T4HH    0x2C
#define GS_PSM_Z32     0x30
#define GS_PSM_Z24     0x31
#define GS_PSM_Z16     0x32
#define GS_PSM_Z16S    0x3A

typedef struct GsImageObj {
    char unk000[GSIMAGE_PKT_OFFSET];
    GsLoadImagePacket pkt;              /* 0x0B0 */
} GsImageObj;

typedef char GsImageObj_chk_pkt[((int)&((GsImageObj *)0)->pkt == 0xB0) ? 1 : -1];

extern void GsImageObj_upload(GsImageObj *self, int psm, int tbp, int tbw, int w, int h, char *data);

#endif
