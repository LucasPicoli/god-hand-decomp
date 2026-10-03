/* sn-2.95.3-136 matched TU. */

/* Add an object to the tracked set (5 slots) unless tracking is off or the object opts out. */
#define TRACK_SLOT_NUM     5
#define TRACK_SYS_OFF      0x20000000   /* D_00747A84 bit 29: tracking disabled */
#define TRACK_OBJ_NO_TRACK 0x1000       /* object flag word at 0x2F0 */

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

extern unsigned int D_00747A84;

__attribute__((section(".text.func_0013F558")))
void func_0013F558(TrackSet *self, TrackObj *obj)
{
    if ((D_00747A84 & TRACK_SYS_OFF) == 0 && (obj->trackFlags & TRACK_OBJ_NO_TRACK) == 0) {
        unsigned int n = self->count;
        if (n < TRACK_SLOT_NUM) {
            do {
                self->obj[n] = obj;
                self->slotPtr[n] = &self->slot[n];
                self->state[n] = 0;
                self->count++;
            } while (0);
        }
    }
}
