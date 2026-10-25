/* include/godhand/tweenSet.h - an object that eases several short values toward targets.
 *
 * Each channel is 8 bytes: a current short, a target short and a word the
 * stepper func_00378070 uses. Channels start at 0x38. activeMask has one bit
 * per channel that still moves; dirty (bit 0 of the halfword at 0x10) tells
 * the owner that some channel changed. Field names are ours, from the methods
 * that touch them; offsets are exact. A field nobody has named yet stays as
 * unkNNN padding.
 */
#ifndef GODHAND_TWEENSET_H
#define GODHAND_TWEENSET_H

#define TWEENSET_DIRTY 0x1

typedef struct TweenChan {
    short cur;                          /* 0x00 */
    short target;                       /* 0x02 */
    int step;                           /* 0x04 stepper state */
} TweenChan;                            /* 0x08 */

typedef struct TweenSet {
    char unk00[0x10];
    unsigned short flags10;             /* 0x10 */
    char unk12[0x26];
    TweenChan chan[1];                  /* 0x38 one per channel */
    char unk40[0x18];
    int activeMask;                     /* 0x58 */
} TweenSet;

extern void func_00378070(TweenChan *ch);

#endif
