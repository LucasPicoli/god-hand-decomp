/* include/godhand/cIDLifeBar.h - a cIDBase life bar that follows an owner's hp.
 *
 * The bar reads hp / hpMax of the object at 0x9C, eases its drawn value
 * toward it and splits the value over four display entries: the first unit
 * fills the main segment, anything above one spills into a second segment.
 * An older value trails behind as a ghost segment and fades with a counter.
 *
 * Offsets are exact. A field nobody has named yet stays as unkNN padding.
 */
#ifndef GODHAND_CIDLIFEBAR_H
#define GODHAND_CIDLIFEBAR_H

#include "godhand/cIDBase.h"
#include "godhand/cGameObj.h"

#define IDLIFE_F_INIT     0x40000000    /* flags: the bar has been set up */
#define IDLIFE_FADE_TICKS 0x28          /* frames the ghost value holds before it eases */
#define IDLIFE_EASE       0.07f
#define IDLIFE_ALPHA_MAX  128.0f

typedef struct cIDLifeBar {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x94 - 0x48];
    int active;                         /* 0x94 nonzero while the bar is shown */
    char unk98[4];
    cGameObj *owner;                    /* 0x9C object whose hp is shown */
    unsigned int flags;                 /* 0xA0 IDLIFE_F_* */
    char unkA4[4];
    float cur;                          /* 0xA8 drawn value, eased toward target */
    float target;                       /* 0xAC hp ratio times two */
    float ref;                          /* 0xB0 value the fade is measured against */
    float shown;                        /* 0xB4 */
    float ghost;                        /* 0xB8 older value, drawn as the trailing segment */
    unsigned char alpha;                /* 0xBC */
    char unkBD;
    unsigned short fade;                /* 0xBE counts down from IDLIFE_FADE_TICKS */
    cIDBaseEnt *ent[4];                 /* 0xC0 */
} cIDLifeBar;

#endif
