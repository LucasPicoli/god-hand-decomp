/* sn-2.95.3-136 matched TU. */

#include "godhand/cEvent.h"

extern int cEvent_nullHookI();
extern void func_0();
extern void func_003A52F0(void *, int, int);
extern void func_00297CB0(void *, char *);
extern void func_00297CF8(void *, char *);
extern void func_00297D40(void *, char *);
extern void func_00297D88(void *, char *);
extern void func_00297DD0(void *, char *);
extern void func_00297E18(void *, char *);
extern void func_00297E60(void *, char *);
extern void func_00297EA8(void *, char *);
extern void func_00297EF0(void *, char *);
extern void func_00297F38(void *, char *);
extern void func_00297F80(void *, char *);
extern void func_00297FC8(void *, char *);
extern int D_00586B34;
extern int D_003C2558;
extern char D_00747470[];
extern void func_00297128(cEvent *);
extern void cEvent_startReleaseObj(cEvent *);
extern void classFADE_start(char *, int, int, int, int, int, int);
extern void Set_bg_mode(int, int, int, int);
extern void cNowLoading_executeTask(int);

/* Start the cutscene's work area; if either stripped check fails, flag the
 * record so the player skips the create step. */
__attribute__((section(".text.cEvent_startCreateWork")))
void cEvent_startCreateWork(cEvent *self) {
    if (cEvent_nullHookI(cEvent_nullStr00) == 0 || cEvent_nullHookI(cEvent_nullStr01) == 0) {
        self->flags |= CEVENT_F_NO_START;
    } else {
        func_0(cEvent_nullStr01);
        func_0(cEvent_nullStr01);
    }
}

/* Reset the cutscene systems: zero each stripped state block, then run the
 * stripped init hook on the first one with the argument we were given. */
__attribute__((section(".text.cEvent_clearSystem")))
void cEvent_clearSystem(cEvent *self, int dataNo) {
    func_003A52F0(cEvent_nullStr00, 0, 68);
    func_003A52F0(cEvent_nullStr01, 0, 24);
    func_003A52F0(cEvent_nullStr02, 0, 28);
    func_003A52F0(cEvent_nullStr03, 0, 24);
    func_003A52F0(cEvent_nullStr04, 0, 24);
    func_003A52F0(cEvent_nullStr05, 0, 220);
    func_003A52F0(cEvent_nullStr06, 0, 52);
    func_003A52F0(cEvent_nullStr07, 0, 1512);
    func_003A52F0(cEvent_nullStr08, 0, 24);
    func_003A52F0(cEvent_nullStr09, 0, 24);
    func_003A52F0(cEvent_nullStr10, 0, 120);
    func_003A52F0(cEvent_nullStr11, 0, 28);
    func_003A52F0(cEvent_nullStr12, 0, 24);
    func_003A52F0(cEvent_nullStr13, 0, 28);
    func_003A52F0(cEvent_nullStr14, 0, 28);
    func_0(cEvent_nullStr00, dataNo);
}

/* Hand each section of the loaded display-text data to its stripped
 * consumer. Every section is passed as 0 when its offset is 0. */
__attribute__((section(".text.func_002977E8")))
void func_002977E8(cEvent *self) {
    *(int *)(cEvent_nullStr00 + 8) = self->textData->kind;
    func_0(cEvent_nullStr01, CEVENT_TEXT_SEC(self->textData, 0x04), self->textData);
    func_0(cEvent_nullStr02, CEVENT_TEXT_SEC(self->textData, 0x08), self->textData->mode);
    func_0(cEvent_nullStr02, CEVENT_TEXT_SEC(self->textData, 0x0C), self->textData);
    func_00297CB0(cEvent_nullStr03, CEVENT_TEXT_SEC(self->textData, 0x50));
    func_00297CF8(cEvent_nullStr04, CEVENT_TEXT_SEC(self->textData, 0x18));
    func_0(cEvent_nullStr04, CEVENT_TEXT_SEC(self->textData, 0x1C));
    func_00297D40(cEvent_nullStr05, CEVENT_TEXT_SEC(self->textData, 0x20));
    func_00297D88(cEvent_nullStr06, CEVENT_TEXT_SEC(self->textData, 0x24));
    func_00297DD0(cEvent_nullStr07, CEVENT_TEXT_SEC(self->textData, 0x28));
    func_00297E18(cEvent_nullStr08, CEVENT_TEXT_SEC(self->textData, 0x30));
    func_00297E60(cEvent_nullStr09, CEVENT_TEXT_SEC(self->textData, 0x2C));
    func_00297EA8(cEvent_nullStr10, CEVENT_TEXT_SEC(self->textData, 0x48));
    func_00297EF0(cEvent_nullStr11, CEVENT_TEXT_SEC(self->textData, 0x54));
    func_00297F38(cEvent_nullStr12, CEVENT_TEXT_SEC(self->textData, 0x44));
    func_00297F80(cEvent_nullStr13, CEVENT_TEXT_SEC(self->textData, 0x4C));
    func_00297FC8(cEvent_nullStr14, CEVENT_TEXT_SEC(self->textData, 0x58));
}

/* Release stage of the play state: fade out on phase 0, wait for the
 * release on phase 8, count up in between. */
__attribute__((section(".text.func_00297038")))
void func_00297038(cEvent *self) {
    unsigned long f = self->flags;
    unsigned long t;
    if (((f >> 7) & 1) == 0 || (f & CEVENT_F_TEXT_DATA) == 0) {
        func_00297128(self);
        return;
    }
    switch ((signed char)self->phase) {
    case 0:
        t = D_00586B34;
        if (((t >> 6) & 1) == 0) {
            classFADE_start(D_00747470, 0, 8, 0, 0xFF000000, 0xFF000000, 0);
            Set_bg_mode(1, 0, 0, 0);
            cNowLoading_executeTask(D_003C2558);
        }
        cEvent_startReleaseObj(self);
    default:
        self->phase++;
        break;
    case 8:
        if (func_00297AA8(self) != 0) {
            func_00297128(self);
        }
        break;
    }
}
