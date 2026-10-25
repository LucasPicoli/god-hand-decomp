/* include/godhand/mwsfReq.h - the request slots of an MWSF play handle (cygnus code at 0x342FF8).
 * Same handle as MwsfHn in mwsfHn.h; this view names the three 0x10-byte slots at 0x1BC.
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_MWSFREQ_H
#define GODHAND_MWSFREQ_H

typedef struct MwsfReqSlot {
    int key;                    /* 0x00 */
    int p1;                     /* 0x04 */
    int p2;                     /* 0x08 */
    int p3;                     /* 0x0C */
} MwsfReqSlot;

typedef struct MwsfReqHn {
    char unk00[0x3C];
    void *sfd;                  /* 0x3C */
    char unk40[0x1BC - 0x40];
    int id;                     /* 0x1BC request id, 0 when none */
    MwsfReqSlot slot[3];        /* 0x1C0 */
} MwsfReqHn;

/* The request record SFD_SetRequest-style calls take (0x18 bytes). */
typedef struct MwsfReq {
    int kind;                   /* 0x00 */
    int id;                     /* 0x04 */
    int p1;                     /* 0x08 */
    int p2;                     /* 0x0C */
    int p3;                     /* 0x10 */
    int unk14;                  /* 0x14 */
} MwsfReq;

#define MWSFREQ_ERR  (-0x138)   /* error passed to func_00345750 when the request fails */

extern int func_00359270(void *sfd, MwsfReq *req);
extern int func_00345750(int err);
extern int MWSFSVM_Error(char *msg);

#endif
