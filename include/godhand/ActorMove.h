/* include/godhand/ActorMove.h - ActorMove, the motion state an actor steps through.
 *
 * A motion runs from a script of 16-bit commands (0x8C). Four phase bytes at
 * 0xC to 0xF carry where the step stands; the flags word at 0x14 marks a step
 * in progress (bit 3), an ending motion (bit 6) and a reset (bit 12).
 *
 * Field names are ours, taken from the methods that read and write them
 * (ActorMove_resetMotion in src/cod/00144b50.c, func_002B42F0). Offsets are
 * exact. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_ACTORMOVE_H
#define GODHAND_ACTORMOVE_H

#define ACTORMOVE_FLAG_STEP     0x8         /* flags: a step is running */
#define ACTORMOVE_BIT_ENDING    6           /* flags bit: the motion is ending */
#define ACTORMOVE_FLAG_RESET    0x1000      /* flags: the motion was reset */

/* Script commands: the type is the high byte, the argument the next halfword. */
#define ACTORMOVE_CMD_TYPE      0xFF00
#define ACTORMOVE_CMD_END       0x8000      /* go to the end phase */
#define ACTORMOVE_CMD_RESTART   0x9000      /* restart with the move in the argument */

#define ACTORMOVE_PHASE_END     7

typedef struct ActorMove {
    char unk00[0xC];
    unsigned char phase0;               /* 0x0C */
    unsigned char phase1;               /* 0x0D */
    unsigned char phase2;               /* 0x0E */
    unsigned char phase3;               /* 0x0F */
    char unk10[4];
    unsigned int flags;                 /* 0x14 ACTORMOVE_FLAG_* */
    char unk18[4];
    int unk1C;                          /* 0x1C */
    int idB;                            /* 0x20 */
    char unk24[8];
    unsigned char mode;                 /* 0x2C */
    unsigned char unk2D;                /* 0x2D */
    short unk2E;                        /* 0x2E */
    signed char idA;                    /* 0x30 */
    char unk31[0x13];
    unsigned char unk44;                /* 0x44 */
    char unk45[7];
    unsigned char unk4C;                /* 0x4C */
    char unk4D[3];
    int unk50;                          /* 0x50 */
    char unk54[0x38];
    unsigned short *script;             /* 0x8C the running command */
    char unk90[0x22];
    unsigned char unkB2;                /* 0xB2 */
} ActorMove;

typedef char ActorMove_chk_script[((int)&((ActorMove *)0)->script == 0x8C) ? 1 : -1];
typedef char ActorMove_chk_b2[((int)&((ActorMove *)0)->unkB2 == 0xB2) ? 1 : -1];

/* Set the four phase bytes. The stores are written in retail's order, phase3 first. */
static __inline__ void ActorMove_setPhase(ActorMove *self, int p0, int p1, int p2, int p3)
{
    self->phase0 = p0;
    self->phase1 = p1;
    self->phase2 = p2;
    self->phase3 = p3;
}

extern void func_002B21F0(ActorMove *self, int move);

#endif
