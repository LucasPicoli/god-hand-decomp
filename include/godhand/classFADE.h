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
    char unk00[0x1C];
    unsigned char state;                /* 0x1C 0 idle, bit 2 set once the fade has finished */
    char unk1D[3];
    unsigned int otMin;                 /* 0x20 ordering table range, first */
    unsigned int otMax;                 /* 0x24 and last */
} classFADE;

extern classFADE D_00747470;

extern void classFADE_start(classFADE *self, int a, int b, int c, unsigned int from, unsigned int to, int frames);
extern void classFADE_kill(classFADE *self);

#endif
