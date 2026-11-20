/* sn-2.95.3-136 matched TU. */

#include "godhand/CustomIDWork.h"
#include "godhand/DispMgr.h"

extern void SetCustomIDDispOneOrAll_1F4778(void *self, int entry, int on);
extern void CustomIDWork_SetNumber(CustomIDWork *work, int n);
extern void CustomIDWork_SetMessNo(CustomIDWork *work, int messNo);
extern int ReturnOne_1F6FA0(void *self);
extern void BlendSetup_load(void *table, int a, int b, int c, int d, int e);

#define TIME_ROW_NUM       7          /* rows in the table */
#define TIME_DISP_FIRST    0x2D       /* three display entries per row, from here */
#define TIME_DISP_RANK     0x68       /* one more entry per row: the rank mark */
#define TIME_ROW_SIZE      0x174      /* bytes between the number records of two rows */
#define TIME_MIN_OFFSET    0x162C     /* minutes number record of row 0 */
#define TIME_SEC_OFFSET    0x16A8     /* seconds number record of row 0 */
#define TIME_MESS_OFFSET   0x32C0     /* message record of row 0 (0x7C bytes each) */
#define TIME_MESS_NONE     0x102B     /* message shown when the row has no time */
#define TIME_SECS_PER_MIN  60

/* Fills row `idx` of the time table: hides its entries, then shows the time
 * (val seconds as minutes and seconds) with visibility `show`, or the "no
 * time" message when val is 0. Does nothing for a row of 7 or more. */
__attribute__((section(".text.CustomIDOwner_setTimeRow")))
void CustomIDOwner_setTimeRow(void *self, unsigned short idx, int val, int show)
{
    int disp;
    int minutes;
    int seconds;

    if (idx >= TIME_ROW_NUM)
        return;
    disp = idx * 3 + TIME_DISP_FIRST;
    SetCustomIDDispOneOrAll_1F4778(self, disp, 0);
    SetCustomIDDispOneOrAll_1F4778(self, disp + 1, 0);
    SetCustomIDDispOneOrAll_1F4778(self, disp + 2, 0);
    SetCustomIDDispOneOrAll_1F4778(self, idx + TIME_DISP_RANK, 0);
    if (val != 0) {
        minutes = val / TIME_SECS_PER_MIN;
        seconds = val % TIME_SECS_PER_MIN;
        CustomIDWork_SetNumber((CustomIDWork *)((char *)self + TIME_MIN_OFFSET + idx * TIME_ROW_SIZE), minutes);
        CustomIDWork_SetNumber((CustomIDWork *)((char *)self + TIME_SEC_OFFSET + idx * TIME_ROW_SIZE), seconds);
        SetCustomIDDispOneOrAll_1F4778(self, disp, show);
        SetCustomIDDispOneOrAll_1F4778(self, disp + 1, show);
        SetCustomIDDispOneOrAll_1F4778(self, disp + 2, show);
    } else {
        CustomIDWork_SetMessNo((CustomIDWork *)((char *)self + TIME_MESS_OFFSET + idx * 0x7C), TIME_MESS_NONE);
        SetCustomIDDispOneOrAll_1F4778(self, idx + TIME_DISP_RANK, show);
    }
}

#define GAME_F_ANIM_DONE  0x20000000
#define ANIM_NONE         (-2)        /* GetNextAnimIndex answer: nothing queued */
#define STEP_BLEND_FRAMES 0x2D
#define STEP_WAIT_FRAMES  2

/* One animation node. */
typedef struct AnimNode {
    char unk00[0x2C];
    int index;                          /* 0x2C animation index being played */
    unsigned short counter;             /* 0x30 copy of the game counter */
    short frames;                       /* 0x32 countdown */
    unsigned char mode;                 /* 0x34 */
    unsigned char step;                 /* 0x35 */
    unsigned char busy;                 /* 0x36 1 while an animation runs */
    char unk37;
    int blendA;                         /* 0x38 */
    int blendB;                         /* 0x3C */
    int blendC;                         /* 0x40 */
} AnimNode;

#define GAME_FLAGS()    (D_003BD6E8->screen.flags)

/* Per-frame step of an animation node. */
__attribute__((section(".text.AnimNode_stepPlayback")))
int AnimNode_stepPlayback(AnimNode *self)
{
    int idx;

    if (self->busy == 1)
        return 0;
    self->index = 0x1F;
    if (self->frames <= 0) {
        if (ReturnOne_1F6FA0(self) == 0) {
            if (self->step == 1)
                GAME_FLAGS() |= GAME_F_ANIM_DONE;
            self->step = 0;
            return 0;
        }
    } else {
        self->frames = self->frames - 1;
    }
    idx = GetNextAnimIndex_1451E0(&D_003BD6E8->screen);
    if (idx >= 0) {
        if (self->step == 1)
            GAME_FLAGS() |= GAME_F_ANIM_DONE;
        self->index = idx;
        self->busy = 1;
        self->frames = STEP_WAIT_FRAMES;
        return 1;
    }
    switch (self->step) {
    case 0:
        if (idx != ANIM_NONE)
            return 1;
        BlendSetup_load(&D_003BD6E8->screen, self->blendA, self->blendB, self->blendC, self->mode, self->counter);
        self->step = self->step + 1;
        self->frames = STEP_BLEND_FRAMES;
        /* fall through */
    case 1:
        self->counter = D_003BD6E8->screen.cur + 1;
        break;
    }
    return 1;
}

/* Quicksort of two parallel arrays: key[] (halfwords) decides the order and
 * val[] (words) is permuted the same way. Sorts the range lo..hi inclusive. */
__attribute__((section(".text.SortPair_quicksort")))
void SortPair_quicksort(short *key, int *val, int lo, int hi)
{
    short pivot = key[(lo + hi) / 2];
    int i = lo;
    int j = hi;
    int bound;

    for (;;) {
        short t;
        int v;

        while (key[i] < pivot)
            i++;
        while (pivot < key[j])
            j--;
        if (i >= j) {
            i--;
            break;
        }
        t = key[i];
        key[i] = key[j];
        key[j] = t;
        v = val[i];
        val[i] = val[j];
        val[j] = v;
        i++;
        j--;
    }
    if (lo < i) {
        bound = i;
        SortPair_quicksort(key, val, lo, bound);
    }
    bound = j + 1;
    if (bound < hi)
        SortPair_quicksort(key, val, j + 1, hi);
}
