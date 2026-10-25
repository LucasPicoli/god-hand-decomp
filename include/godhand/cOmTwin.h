/* include/godhand/cOmTwin.h - cOmTwin, a cOmBase object that owns a damage-take volume and two
 * helper objects of kind 0x3B6 (sn code at 0x1B57E8).
 *
 * The setup routine creates the two helpers, clears bit 31 of their state word (0x62C), makes
 * the damage-take box and flags the child bodies from index 1 up as mesh flag A (even slots)
 * and B. Offsets are exact; unknown spans stay unkNNN padding.
 */
#ifndef GODHAND_COMTWIN_H
#define GODHAND_COMTWIN_H

#include "godhand/cOmBase.h"

#define COMTWIN_KIND            0x3B6
#define COMTWIN_PART_LIVE       0x80000000      /* part state word bit cleared at setup */
#define COMTWIN_CHILD_FLAG_A    0x08            /* mesh flag A, as cOm1f */
#define COMTWIN_CHILD_FLAG_B    0x10            /* mesh flag B, as cOm1f */
#define COMTWIN_MAX_CHILDREN    6

/* A helper object as the setup sees it: its g++ 2.x vtable at 0x214 and a state word. */
typedef struct cOmTwinPart {
    char unk000[0x154];
    int meshFlags;                      /* 0x154 */
    char unk158[0x62C - 0x158];
    unsigned int state;                 /* 0x62C */
} cOmTwinPart;

typedef struct cOmTwin {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    void *damageTake;                   /* 0x600 damage-take volume, 0 when none */
    cOmBase *partA;                     /* 0x604 first helper object */
    cOmBase *partB;                     /* 0x608 second helper object */
} cOmTwin;

#endif
