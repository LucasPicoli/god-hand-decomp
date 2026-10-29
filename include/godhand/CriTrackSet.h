/* include/godhand/CriTrackSet.h - a CRI middleware object with numbered tracks.
 *
 * Track numbers run from 0 to CRI_TRNO_MAX. Each track keeps a level of its
 * own; the level a track's handle receives is the shared base plus that
 * track level. Names are ours; unnamed fields stay as unkNNN padding.
 */
#ifndef GODHAND_CRITRACKSET_H
#define GODHAND_CRITRACKSET_H

#define CRI_TRNO_MAX  0x20

typedef struct CriTrackSet {
    char unk000[0xC];
    void *handle[CRI_TRNO_MAX + 1];     /* 0x00C per-track handles */
    char unk090[0x158];
    int baseLevel;                      /* 0x1E8 */
    int trackLevel[CRI_TRNO_MAX + 1];   /* 0x1EC */
} CriTrackSet;

/* CriTrackSet_setTrackLevel on the set ply, under the middleware lock. */
extern void func_0032EC78(int ply, int trno, int level);

#endif
