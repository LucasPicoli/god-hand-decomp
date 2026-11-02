/* sn-2.95.3-136 matched TU. */

extern float func_001E9078(void *self);
extern unsigned int func_0031ED08(float f);

#define FULL_TURN  360.0f

typedef struct Ring1E8EB8 {
    char unk00[0x54];
    int slot[(0xA8 - 0x54) / 4];        /* 0x54 the ring of entries, count in `num` */
    int next;                           /* 0xA8 entry after the current one */
    int cur;                            /* 0xAC the current entry */
    int prev;                           /* 0xB0 entry before the current one */
    unsigned short num;                 /* 0xB4 entries in the ring */
} Ring1E8EB8;

/* Picks the ring entry that the angle falls in and stores it with its two
 * neighbours (wrapping at both ends). */
__attribute__((section(".text.Ring_pickByAngle")))
void Ring_pickByAngle(Ring1E8EB8 *self)
{
    unsigned int idx;
    float angle = func_001E9078(self);
    idx = func_0031ED08(angle / (FULL_TURN / self->num));
    if (idx == self->num - 1) {
        self->next = self->slot[0];
    } else {
        self->next = self->slot[idx + 1];
    }
    self->cur = self->slot[idx];
    if (idx == 0) {
        self->prev = self->slot[self->num - 1];
    } else {
        self->prev = self->slot[idx - 1];
    }
}
