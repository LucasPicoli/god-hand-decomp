/* sn-2.95.3-136 matched TU. */
#include "godhand/cEvent.h"

extern int D_005FEE00;
extern int D_003C2558;
extern void func_002CBC58(int *, int, int);
extern void LoadResourceEntry_297378();
extern void cSnd_BgmEvDataInit();
extern void LoadDisplayText_297450();
extern void cEvent_clearSystem();
extern void func_00297540();
extern int cSnd_BgmEvDataCheck();
extern void cSnd_BgmEvCutSet();
extern int cSnd_BgmEvCutCheck();
extern void func_002977E8();
extern void cEvent_startCreateWork();
extern int cEvent_isEndCreateWork();
extern int func_0();
extern void func_002D1E18();
extern void Obj0000_Set_D_003C2555_One_2B65F0();

extern int func_00297428(cEvent *);
extern int func_002975D0(cEvent *);
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
            func_002CBC58(&D_005FEE00, i, 0);
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
        if (func_00297428(self) == 0) {
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
        func_00297540(self);
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
        if (func_002975D0(self) == 0) {
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
        func_002977E8(self);
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
            func_002D1E18(&D_005FEE00, 1, -1);
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
            Obj0000_Set_D_003C2555_One_2B65F0(D_003C2558);
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
        Obj0000_Set_D_003C2555_One_2B65F0(D_003C2558);
        return 1;
    }
    return 0;
}
