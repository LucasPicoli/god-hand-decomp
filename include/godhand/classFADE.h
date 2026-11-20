/* include/godhand/classFADE.h - classFADE, the screen fade.
 *
 * One fade object lives at D_00747470. start begins a fade between two
 * colours over a number of frames, status reports where it is (the state
 * byte at 0x1C), kill stops it and setOt chooses the ordering table
 * range it draws into.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CLASSFADE_H
#define GODHAND_CLASSFADE_H

#define FADE_STATE_DONE_BIT   2         /* bit of `state` that is set when the fade has run out */

typedef struct classFADE {
    long tag;                           /* 0x00 GS primitive tag for the fade sprite (by type) */
    short x;                            /* 0x08 screen rectangle, 12.4 fixed */
    short y;                            /* 0x0A */
    short w;                            /* 0x0C */
    short h;                            /* 0x0E */
    int col;                            /* 0x10 colour faded from */
    int col2;                           /* 0x14 colour faded to */
    unsigned short time;                /* 0x18 frames, shifted by the frame-rate scale */
    unsigned short count;               /* 0x1A frames run */
    unsigned char state;                /* 0x1C 0 idle, bit 2 set once the fade has finished */
    unsigned char kind;                 /* 0x1D */
    short unk1E;
    unsigned int otMin;                 /* 0x20 ordering table range, first */
    unsigned int otMax;                 /* 0x24 and last */
} classFADE;

extern classFADE D_00747470;

/* state is the initial state byte (start sets bit 0); type picks the GS
 * primitive (0, 1 or 2); time is in frames. */
extern void classFADE_start(classFADE *self, int kind, int state, unsigned int type,
                            unsigned int col, unsigned int col2, int time);
extern void classFADE_kill(classFADE *self);
extern int classFADE_status(classFADE *self);
extern void classFADE_setOt(classFADE *self, int ot, int pri);

#endif
