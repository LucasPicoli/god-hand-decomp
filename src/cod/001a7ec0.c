/* sn-2.95.3-136 matched TU. */

#include "godhand/cMovie.h"
#include "godhand/cE3.h"
#include "godhand/cOm53.h"
#include "godhand/cMc.h"

extern void func_002B4A50(cMovie *self);
extern void func_002D42F8(cMovieTrack *track);
extern void cE3_stepMenuClock(cE3 *self);
extern void cE3_runDemo(cE3 *self);
extern void KeyStop(void);
extern void *Getplayer(void);
extern unsigned int D_00747A84;
extern void func_0();
extern char cEvent_nullStr00[];
extern void func_00394F20(void *dll);
extern void cHeap_free(void *heap, void *block);
extern char D_00754230[];

/* 1 while the track holds a player. The unsigned char result is what makes
 * the compiler build the 0/1 with a branch, as retail does. */
static __inline__ unsigned char cMovieTrack_inUse(cMovieTrack *t) {
    if (t->handle != 0) return 1;
    return 0;
}

/* 1 when no track holds a player. */
__attribute__((section(".text.cMovie_isIdle")))
int cMovie_isIdle(cMovie *self) {
    cMovieTrack *t;
    int i;
    func_002B4A50(self);
    t = self->track;
    for (i = 0; i < MOVIE_TRACK_NUM; i++, t++) {
        if (cMovieTrack_inUse(t) == 1) return 0;
    }
    return 1;
}

/* Hand the active track, if there is one, to func_002D42F8. */
__attribute__((section(".text.cMovie_haltActive")))
void cMovie_haltActive(void) {
    cMovieTrack *track = func_002B4F98();
    if (track)
        func_002D42F8(track);
}

/* Run the step for the current state: the menu or the demo. */
__attribute__((section(".text.cE3_exec")))
void cE3_exec(cE3 *self) {
    switch (self->state) {
    case CE3_STATE_MENU:
        cE3_stepMenuClock(self);
        break;
    case CE3_STATE_DEMO:
        cE3_runDemo(self);
        break;
    }
}

/* The system flag words D_00747A24, D_00747A78 and D_00747A84 sit in one
 * block. Retail forms the first two as byte offsets from D_00747A84, and only
 * that spelling matches. */
#define SYSFLAG_BELOW(base, delta) (*(unsigned int *)((char *)(base) - (delta)))
#define SYS_LOCK_FLAGS  0xC             /* D_00747A78 */
#define SYS_MODE_FLAGS  0x60            /* D_00747A24 */

#define SYS_ENDING_A    0x40000040      /* D_00747A84 */
#define SYS_PAD_LOCK    0x2000          /* D_00747A78 */
#define SYS_LOCK_MORE_A 0x400000
#define SYS_LOCK_MORE_B 0x100000
#define SYS_MODE_BIT    8               /* D_00747A24 */

/* Switch the game into the ending: lock the pad, raise the system flags,
 * set the player's flash value to 100.0, then enter state 1 with the ending kind. */
__attribute__((section(".text.cE3_setEnding")))
void cE3_setEnding(cE3 *self, int kind) {
    char *sys = (char *)&D_00747A84;
    *(unsigned int *)sys |= SYS_ENDING_A;
    SYSFLAG_BELOW(sys, SYS_LOCK_FLAGS) |= SYS_PAD_LOCK;
    KeyStop();
    SYSFLAG_BELOW(sys, SYS_LOCK_FLAGS) |= SYS_LOCK_MORE_A;
    SYSFLAG_BELOW(sys, SYS_LOCK_FLAGS) |= SYS_LOCK_MORE_B;
    SYSFLAG_BELOW(sys, SYS_MODE_FLAGS) |= SYS_MODE_BIT;
    *(float *)((char *)Getplayer() + 0x54C) = 100.0f;
    self->ending = kind;
    self->state = CE3_STATE_DEMO;
}

/* Put enemy `em` in the first empty rider slot, counting from the ring head
 * and wrapping at 16. 1 on success, 0 when every slot is taken. The wrap is
 * written as a flag times the index, with the flag in its own local: a
 * comparison written inline there becomes a conditional move. */
__attribute__((section(".text.cOm53_setGetOnEm")))
int cOm53_setGetOnEm(cOm53 *self, unsigned int em) {
    unsigned int i, k, j, inRing;
    unsigned char *rider = self->rider;
    unsigned char *slot;
    for (i = 0; i < COM53_RIDER_NUM; i++) {
        k = self->head + i;
        inRing = k < COM53_RIDER_NUM;
        j = inRing * k;
        slot = rider + j;
        if (*slot == COM53_RIDER_NONE) {
            *slot = em;
            self->riderNum = self->riderNum + 1;
            return 1;
        }
    }
    return 0;
}

/* The stripped log string: address 0 in config/SLUS_215.03.lcf, the symbol
 * the cEvent log calls use. */





/* Unload the module if it is loaded, then free its block. */
__attribute__((section(".text.cMc_DllRelease")))
void cMc_DllRelease(cMc *self) {
    if (self->loaded == 1) {
        func_0(cEvent_nullStr00);
        func_00394F20(self->dll);
        self->loaded = 0;
    }
    if (self->dll != 0) {
        cHeap_free(D_00754230, self->dll);
        self->dll = 0;
    }
}
