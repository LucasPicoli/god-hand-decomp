/* cygnus-2.96: func_0035F288, fills a frame info block from a picture source; type 2 is reported as
 * type 1, type 3 also carries two half-height chroma planes. */
#include "godhand/sfxlib.h"
#include "godhand/globals.h"

typedef struct Sfx Sfx;

typedef struct SfdPicSrc {
    unsigned int type;                  /* 0x00 */
    void *y_ptr;                        /* 0x04 */
    int y_height;                       /* 0x08 */
    int y_pitch;                        /* 0x0C */
    char pad10[4];
    void *u_ptr;                        /* 0x14 */
    int u_height;                       /* 0x18 */
    int u_pitch;                        /* 0x1C */
    char pad20[4];
    void *v_ptr;                        /* 0x24 */
    int v_height;                       /* 0x28 */
    int v_pitch;                        /* 0x2C */
    char pad30[0x14];
    int width;                          /* 0x44 */
} SfdPicSrc;

typedef struct SfdFrmInf {
    unsigned int type;                  /* 0x00 */
    void *y_ptr;                        /* 0x04 */
    int y_width;                        /* 0x08 */
    int y_pitch;                        /* 0x0C */
    int y_height;                       /* 0x10 */
    void *u_ptr;                        /* 0x14 */
    int u_width;                        /* 0x18 */
    int u_pitch;                        /* 0x1C */
    int u_height;                       /* 0x20 */
    void *v_ptr;                        /* 0x24 */
    int v_width;                        /* 0x28 */
    int v_pitch;                        /* 0x2C */
    int v_height;                       /* 0x30 */
} SfdFrmInf;

__attribute__((section(".text.func_0035F288")))
void func_0035F288(Sfx *sfx, SfdPicSrc *src, SfdFrmInf *inf)
{
    switch (src->type) {
    case 1:
        inf->type = src->type;
        inf->y_ptr = src->y_ptr;
        inf->y_width = src->width;
        inf->y_pitch = src->y_pitch;
        inf->y_height = src->y_height;
        break;
    case 2:
        inf->type = 1;
        inf->y_ptr = src->y_ptr;
        inf->y_width = src->width;
        inf->y_pitch = src->y_pitch;
        inf->y_height = src->y_height;
        break;
    case 3:
        inf->type = src->type;
        inf->y_ptr = src->y_ptr;
        inf->y_width = src->width;
        inf->u_ptr = src->u_ptr;
        inf->y_pitch = src->y_pitch;
        inf->v_ptr = src->v_ptr;
        inf->y_height = src->y_height;
        inf->u_width = src->width / 2;
        inf->u_pitch = src->u_pitch;
        inf->u_height = src->u_height;
        inf->v_width = src->width / 2;
        inf->v_pitch = src->v_pitch;
        inf->v_height = src->v_height;
        break;
    default:
        SFXLIB_Error(sfx, src, D_00459F20);
        break;
    }
}
