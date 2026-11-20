/* include/godhand/TrackSet.h - TrackSet, the five tracked objects of the game object.
 *
 * The game object (DispMgr) keeps one at 0x1E90. func_0013F558 adds an object
 * to it unless tracking is off or the object opts out.
 *
 * Field names are ours, taken from the functions that read and write them.
 * Offsets are exact. A field we can't name yet stays as unkNN padding.
 */
#ifndef GODHAND_TRACKSET_H
#define GODHAND_TRACKSET_H

#define TRACK_SLOT_NUM     5

typedef struct TrackObj {
    char unk000[0x2F0];
    unsigned int trackFlags;            /* 0x2F0 */
} TrackObj;

typedef struct TrackSlot {
    char data[0x50];
} TrackSlot;

typedef struct TrackSet {
    char unk000[0xA8];
    int state[TRACK_SLOT_NUM];          /* 0x0A8 */
    char unkBC[4];
    TrackSlot slot[TRACK_SLOT_NUM];     /* 0x0C0 */
    TrackObj *obj[TRACK_SLOT_NUM];      /* 0x250 */
    char unk264[0xF4];
    unsigned char count;                /* 0x358 slots in use */
    char unk359[3];
    TrackSlot *slotPtr[TRACK_SLOT_NUM]; /* 0x35C */
} TrackSet;

/* Add obj to the first free slot unless tracking is off or obj opts out. */
void func_0013F558(TrackSet *self, TrackObj *obj);

#endif
