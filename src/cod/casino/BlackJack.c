/* TU: BlackJack [casino] - recovered C++ class. */
#include "godhand/BlackJack.h"
#include "include_asm.h"

extern int D_00569B70;
extern void func_001D0CE8();
extern void func_001D0DF8();
extern void func_001D5780();
extern int GetTimerValue_1FA710();
extern void BlackJackId_Move();
extern void BlackJackId__Trans();

__attribute__((section(".text.BlackJack_Release")))
void BlackJack_Release(void) {
    func_001D4F48();
}

extern char D_00463050[];


typedef struct BlackJackStateEnt {
    short delta;
    short pad;
    void (*fn)();
} BlackJackStateEnt;
extern BlackJackStateEnt D_003BDF58[];  /* replaces extern char D_003BDF58[] */
/* Per-frame update: run the current state handler, then update both hands, the display and the id entries. */
__attribute__((section(".text.BlackJack_Main")))
void BlackJack_Main(BlackJack *self)
{
    int s1;
    BlackJackCard **s0;
    BlackJackCard **s3;
    int i = self->state;
    short off = D_003BDF58[i].delta;
    void (*fn)() = D_003BDF58[i].fn;
    fn((char *)self + off);

    s3 = self->handA;
    s1 = 4;
    s0 = s3;
    do {
        if (*s0 != 0) {
            func_001D0CE8(*s0);
        }
        s1 = s1 - 1;
        s0 = s0 + 1;
    } while (s1 >= 0);

    s0 = s3;
    s1 = 4;
    s3 = self->handB;
    do {
        if (*s0 != 0) {
            func_001D0DF8(*s0);
        }
        s1 = s1 - 1;
        s0 = s0 + 1;
    } while (s1 >= 0);

    s0 = s3;
    s1 = 4;
    do {
        if (*s0 != 0) {
            func_001D0CE8(*s0);
        }
        s1 = s1 - 1;
        s0 = s0 + 1;
    } while (s1 >= 0);

    s0 = s3;
    s1 = 4;
    do {
        if (*s0 != 0) {
            func_001D0DF8(*s0);
        }
        s1 = s1 - 1;
        s0 = s0 + 1;
    } while (s1 >= 0);

    func_001D5780(self, GetTimerValue_1FA710(&D_00569B70));
    BlackJackId_Move(self);
    BlackJackId__Trans(self);
}

/* Switch to the table camera and copy the eye and target positions into it. */
__attribute__((section(".text.BlackJack_SetBlackJackCamera")))
void BlackJack_SetBlackJackCamera(BlackJack *self, float *a1, float *a2) {
    float *dst1;
    float *dst2;

    cCamManager_setSubScrCamera(D_00463050, 0);
    self->camera = D_00463050 + 0xC90;
    dst1 = (float *)(D_00463050 + 0xEA0);
    if (a1 != dst1) {
        dst1[0] = a1[0];
        dst1[1] = a1[1];
        dst1[2] = a1[2];
    }
    dst2 = (float *)(self->camera + 0x200);
    if (dst2 != a2) {
        dst2[0] = a2[0];
        dst2[1] = a2[1];
        dst2[2] = a2[2];
    }
}


__attribute__((section(".text.BlackJack_ClearBlackJackCamera")))
void BlackJack_ClearBlackJackCamera(void) {
    cCamManager_setPlCamera(D_00463050, 0);
}
