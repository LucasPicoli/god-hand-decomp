/* TU: cEvent [event] - recovered C++ class. */
#include "godhand/cEvent.h"
extern unsigned int D_00747A84;
extern int D_00586B34;
extern char D_00747470[];

extern void InitSubState_2975F8(cEvent *, int);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void classFADE_start(char *, int, int, int, int, int, int);
/* Start the cutscene `no`: take the player's position and angle, lock the
 * player's camera state and fade in unless the fade bit is set. */
__attribute__((section(".text.cEvent_playStart")))
void cEvent_playStart(cEvent *self, int no) {
    char *player;
    float *src;
    float *dst;
    unsigned long b;
    InitSubState_2975F8(self, no);
    D_00747A84 = D_00747A84 | 0x20000000;
    /* raw form: the typed members let the flags load float above the global store */
    *(char *)((char *)self + CEVENT_OFFSET(skipOk)) = 0;
    *(int *)((char *)self + CEVENT_OFFSET(flags)) |= CEVENT_F_ACTIVE;
    player = Obj0000_Get_D_00747A94_2DB6B0();
    src = *(float **)(player + 0xF0);
    dst = self->pos;
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    self->angle = *(float *)(player + 0x104);
    *(float *)(player + 0x54C) = 60.0f;
    self->state = 0;
    self->phase = 0;
    self->unk06 = 0;
    self->unk07 = 0;
    b = D_00586B34;
    if (((b >> 3) & 1) == 0) {} else {
        classFADE_start(D_00747470, 0, 0xA, 0, 0xFF000000, 0xFF000000, 0);
    }
}

extern int D_003C2F84;
extern char D_0044A890[];
extern char D_00583F20[];
extern int func_002962A8(int);
extern void func_003A6C58(void *, void *, int);
extern int cDvd_FileExist(void *, void *);
extern void SetFieldsCESignalSemaSleep_2D5AA0(int, int);
extern void cScenario_startSoftEvent(int, int);
extern void cScenario__endSoftEvent(int);
extern void cEvent_playStart(cEvent *, int);

/* Start a cutscene: build the data file name, and if it exists play it and
 * wait until it ends. */
__attribute__((section(".text.cEvent_playStartWait")))
void cEvent_playStartWait(cEvent *self, int no) {
    int name[8];
    int id = func_002962A8(no);
    unsigned long a, b;
    func_003A6C58(name, D_0044A890, id);
    if (cDvd_FileExist(D_00583F20, name) == 0) return;
    while (a = D_00747A84, b = (a >> 4) & 1, b != 0) {
        SetFieldsCESignalSemaSleep_2D5AA0(*(int *)(D_003C2F84 + 0x20), 1);
    }
    cScenario_startSoftEvent(D_003C2F84, 4);
    cEvent_playStart(self, id);
    while (self->flags & CEVENT_F_ACTIVE) {
        SetFieldsCESignalSemaSleep_2D5AA0(*(int *)(D_003C2F84 + 0x20), 1);
    }
    cScenario__endSoftEvent(D_003C2F84);
}
