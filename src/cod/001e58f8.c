/* sn-2.95.3-136 */
#include "godhand/Slot2.h"

#define SLOT2_PRIZE_NUM    9
#define SLOT2_ST_RESULT    3

/* A winning row: the symbol each reel must show. */
typedef struct Slot2Prize {
    int sym[SLOT2_REEL_NUM];
} Slot2Prize;

typedef struct Slot2PrizeTbl {
    Slot2Prize e[SLOT2_PRIZE_NUM];
} Slot2PrizeTbl;

extern Slot2PrizeTbl D_0042B9D8;

/* Look the line through rows r0, r1, r2 of the three reels up in the prize table; on a hit go to that prize's result screen and return. */
#define SLOT2_JUDGE_LINE(self, tbl, i, r0, r1, r2)                                                        \
    for ((i) = 0; (i) < SLOT2_PRIZE_NUM; (i)++) {                                                         \
        if ((self)->reel[0].sym[r0] == (tbl).e[i].sym[0] && (self)->reel[1].sym[r1] == (tbl).e[i].sym[1]  \
            && (self)->reel[2].sym[r2] == (tbl).e[i].sym[2]) {                                            \
            switch (i) {                                                                                  \
            case 0:                                                                                       \
                (self)->state = SLOT2_ST_RESULT;                                                          \
                (self)->step = 1;                                                                         \
                (self)->phase = 0;                                                                        \
                return;                                                                                   \
            case 1:                                                                                       \
                (self)->state = SLOT2_ST_RESULT;                                                          \
                (self)->step = 2;                                                                         \
                (self)->phase = 0;                                                                        \
                return;                                                                                   \
            case 2:                                                                                       \
                (self)->state = SLOT2_ST_RESULT;                                                          \
                (self)->step = 3;                                                                         \
                (self)->phase = 0;                                                                        \
                return;                                                                                   \
            default:                                                                                      \
                (self)->state = SLOT2_ST_RESULT;                                                          \
                (self)->step = 4;                                                                         \
                (self)->phase = 0;                                                                        \
                return;                                                                                   \
            }                                                                                             \
        }                                                                                                 \
    }

/* Judge the lines the bet pays (bet 1 the middle row, bet 2 also the top and bottom rows, bet 3 also both diagonals); no win goes to result step 5. */
__attribute__((section(".text.Slot2_JudgeLines")))
void Slot2_JudgeLines(Slot2 *self)
{
    Slot2PrizeTbl tbl = D_0042B9D8;
    int i;

    switch (self->betLv) {
    case 3:
        SLOT2_JUDGE_LINE(self, tbl, i, 0, 1, 2);
        SLOT2_JUDGE_LINE(self, tbl, i, 2, 1, 0);
    case 2:
        SLOT2_JUDGE_LINE(self, tbl, i, 0, 0, 0);
        SLOT2_JUDGE_LINE(self, tbl, i, 2, 2, 2);
    case 1:
        SLOT2_JUDGE_LINE(self, tbl, i, 1, 1, 1);
        break;
    }
    self->state = SLOT2_ST_RESULT;
    self->step = 5;
    self->phase = 0;
}
