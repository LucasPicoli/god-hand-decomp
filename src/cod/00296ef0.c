/* sn-2.95.3-136 matched TU. */

#include "godhand/cEvent.h"

extern int D_00747A84;
extern void func_0();
extern char D_00583F20[];
extern int cDvd_Check(char *, int);

/* End a move scene: run the stripped teardown hooks, remember whether the
 * scene can be skipped, and clear the running flags. */
__attribute__((section(".text.cEvent_movePlayQuit")))
void cEvent_movePlayQuit(cEvent *self) {
    unsigned long f = self->flags;
    long on = (f >> 2) & 1;                /* CEVENT_F_MOVE_ON */
    if (on != 0) {
        if ((unsigned char)func_00298028(cEvent_nullStr00, 0x20) != 0) {
            self->skipOk = 1;
        }
        func_0(cEvent_nullStr01);
        func_0(cEvent_nullStr02);
        func_0(cEvent_nullStr00);
        func_0(cEvent_nullStr03);
        func_0(cEvent_nullStr04);
        func_0(cEvent_nullStr05);
        func_0(cEvent_nullStr06);
        func_0(cEvent_nullStr07);
        func_0(cEvent_nullStr08);
        func_0(cEvent_nullStr09);
        func_0(cEvent_nullStr10);
        func_0(cEvent_nullStr11);
        func_0(cEvent_nullStr12);
        func_0(cEvent_nullStr13);
        func_0(cEvent_nullStr14);
        func_0(cEvent_nullStr15);
        func_0(cEvent_nullStr00);
        /* raw form: the typed member lets the D_00747A84 load float above this store */
        *(int *)((char *)self + CEVENT_OFFSET(flags)) &= ~CEVENT_F_MOVE_ON;
        D_00747A84 &= ~1;
    }
}

/* Nonzero when the cutscene data read has finished. */
__attribute__((section(".text.cEvent_isLoadEnd")))
int cEvent_isLoadEnd(cEvent *self) {
    return cDvd_Check(D_00583F20, self->loadHandle) == 0;
}

/* Nonzero when the data read has finished (same body as cEvent_isLoadEnd). */
__attribute__((section(".text.cEvent_isLoadEndAfterCut")))
int cEvent_isLoadEndAfterCut(cEvent *self) {
    return cDvd_Check(D_00583F20, self->loadHandle) == 0;
}

/* Frame the current cut is on. */
__attribute__((section(".text.cEvent_getCutFrame")))
float cEvent_getCutFrame(void) {
    return cEvent_work.cutFrame;
}
