/* sn-2.95.3-136 matched TU. */
#include "godhand/cEvent.h"

extern int D_005FEE00;
extern int D_003C2558;
extern void cSnd_SeFadeVoicesByKey(int *, int, int);
extern void LoadResourceEntry_297378();
extern void cSnd_BgmEvDataInit();
extern void LoadDisplayText_297450();
extern void cEvent_clearSystem();
extern void cEvent_startLoadText();
extern int cSnd_BgmEvDataCheck();
extern void cSnd_BgmEvCutSet();
extern int cSnd_BgmEvCutCheck();
extern void cEvent_setTextSections();
extern void cEvent_startCreateWork();
extern int cEvent_isEndCreateWork();
extern int func_0();
extern void cSnd_BgmEvFadeDefault();
extern void cNowLoading_exitTask();

extern int cEvent_isLoadEnd(cEvent *);
extern int cEvent_isLoadEndAfterCut(cEvent *);
extern int func_00297B80(cEvent *);
/* CREATE stage: load the entry and the display text, wait for the music
 * data, create the work and wait for it. Any failure goes to RELEASE; success
 * goes to PLAY. */
__attribute__((section(".text.func_00296958")))
int func_00296958(cEvent *self) {
    short i;
    int flags;
    long t;
    void (*cb)();

    switch ((signed char)self->phase) {
    case 0:
        for (i = 0; i < 0x34; i++) {
            cSnd_SeFadeVoicesByKey(&D_005FEE00, i, 0);
        }
        LoadResourceEntry_297378(self);
        cb = self->onLoaded;
        if (cb == 0) {
            cSnd_BgmEvDataInit(&D_005FEE00, func_00297B80(self));
        } else {
            cb();
            self->onLoaded = 0;
        }
        self->phase += 1;
        /* fall through */
    case 1:
        if (cEvent_isLoadEnd(self) == 0) {
            return 0;
        }
        if (self->resData == 0) {
            self->phase = 0;
            self->state = CEVENT_STATE_RELEASE;
            self->unk06 = 0;
            self->unk07 = 0;
            return 0;
        }
        LoadDisplayText_297450(self);
        cEvent_clearSystem(self, self->dataNo);
        self->phase += 1;
        /* fall through */
    case 2:
        cEvent_startLoadText(self);
        self->phase += 1;
        /* fall through */
    case 3:
        if (CEVENT_FLAG_BYTE(self, 1) & 1) {
            if (cSnd_BgmEvDataCheck(&D_005FEE00) == 0) {
                return 0;
            }
            cSnd_BgmEvCutSet(&D_005FEE00, -1);
        }
        self->phase += 1;
        /* fall through */
    case 4:
        if (cEvent_isLoadEndAfterCut(self) == 0) {
            return 0;
        }
        if (CEVENT_FLAG_BYTE(self, 1) & 1) {
            if (cSnd_BgmEvCutCheck(&D_005FEE00, -1) == 0) {
                return 0;
            }
        } else {
            self->phase = 0;
            self->state = CEVENT_STATE_RELEASE;
            self->unk06 = 0;
            self->unk07 = 0;
            return 0;
        }
        cEvent_setTextSections(self);
        cEvent_startCreateWork(self);
        self->phase += 1;
        if (self->flags & CEVENT_F_NO_START) {
            self->phase = 0;
            self->state = CEVENT_STATE_RELEASE;
            self->unk06 = 0;
            self->unk07 = 0;
            return 0;
        }
        /* fall through */
    case 5:
        if (cEvent_isEndCreateWork(self) == 0) {
            return 0;
        }
        if (func_0(func_0) == 0) {
            cSnd_BgmEvFadeDefault(&D_005FEE00, 1, -1);
            self->phase = 0;
            self->state = CEVENT_STATE_RELEASE;
            self->unk06 = 0;
            self->unk07 = 0;
            return 0;
        }
        flags = self->flags | CEVENT_F_CREATED;
        self->flags = flags;
        t = flags;
        if (!(((unsigned long)t >> 5) & 1)) {
            cNowLoading_exitTask(D_003C2558);
            self->phase = 0;
            self->state = CEVENT_STATE_PLAY;
            self->unk06 = 0;
            self->unk07 = 0;
            return 1;
        }
        self->phase += 1;
        /* fall through */
    case 6:
        flags = self->flags;
        t = flags;
        if (!(((unsigned long)t >> 6) & 1)) {
            return 0;
        }
        self->phase = 0;
        self->state = CEVENT_STATE_PLAY;
        self->unk06 = 0;
        self->unk07 = 0;
        cNowLoading_exitTask(D_003C2558);
        return 1;
    }
    return 0;
}
