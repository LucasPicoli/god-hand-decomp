/* include/godhand/SndReq.h - the queue of sound-channel requests at D_0076E590.
 *
 * Eight 0x70-byte records. A record is free while used is 0. The flags byte
 * says whether the record is a channel command (applied with func_003772D8)
 * or a channel start request (applied with func_00376F18). Field names are
 * ours; offsets are exact.
 */
#ifndef GODHAND_SNDREQ_H
#define GODHAND_SNDREQ_H

#define SNDREQ_NUM          8       /* records in the queue */
#define SNDREQ_F_COMMAND    0x10    /* flags: a channel command, not a start */

typedef struct SndReq {
    unsigned short used;        /* 0x00 nonzero while queued */
    char unk02[6];
    unsigned char flags;        /* 0x08 SNDREQ_F_* */
    char unk09[0x70 - 0x09];
} SndReq;                       /* 0x70 */

typedef char SndReq_chk_size[sizeof(SndReq) == 0x70 ? 1 : -1];

extern SndReq D_0076E590[SNDREQ_NUM];

#endif
