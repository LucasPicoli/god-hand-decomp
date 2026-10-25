/* include/godhand/SndCue.h - timed cue slots on a sound sequence owner.
 *
 * The owner holds eight 0x14-byte cue slots from 0x40. A slot is live while
 * its flags are nonzero. A live slot that has not fired counts delay down once
 * per update and fires (SNDCUE_F_FIRED set, then handled) when it reaches 0.
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SNDCUE_H
#define GODHAND_SNDCUE_H

#define SNDCUE_NUM      8       /* cue slots per owner */
#define SNDCUE_F_FIRED  0x02    /* flags: the cue already fired */

typedef struct SndCueSlot {
    unsigned short flags;       /* 0x00 nonzero while the slot is in use */
    char unk02[0x10];
    unsigned short delay;       /* 0x12 updates left before the cue fires */
} SndCueSlot;                   /* 0x14 */

/* One script command: a wait in updates, then the cue slot and handler to run. */
typedef struct SndCueCmd {
    int wait;                   /* 0x00 updates to wait before the command runs */
    unsigned char kind;         /* 0x04 cue slot the command acts on */
    unsigned char sub;          /* 0x05 handler index */
    char unk06[0x0A];
} SndCueCmd;                    /* 0x10 */

#define SNDCUE_F_DONE   0x1000  /* owner flags: the script stopped itself */

typedef struct SndCueOwner {
    unsigned short flags;       /* 0x00 */
    char unk02[0x2E];
    SndCueCmd *pc;              /* 0x30 the next script command */
    char unk34[4];
    int wait;                   /* 0x38 updates left before the next command */
    signed char kind;           /* 0x3C cue slot of the command in flight */
    signed char sub;            /* 0x3D handler index of the command in flight */
    char unk3E[2];
    SndCueSlot cue[SNDCUE_NUM]; /* 0x40 */
} SndCueOwner;

typedef char SndCueSlot_chk_size[sizeof(SndCueSlot) == 0x14 ? 1 : -1];

#endif
