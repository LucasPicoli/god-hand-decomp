/* sn-2.95.3-136 matched TU. */

#include "godhand/cEvent.h"

extern int D_00747A2C;
extern int D_00586B34;
extern char D_00747470[];
extern void classFADE_start(char *, int, int, int, int, int, int);
extern int D_00747A84;
extern void func_0();

/* Start the opening fade, unless a fade or movie flag already owns the screen. */
__attribute__((section(".text.cEvent_startPlayFade")))
void cEvent_startPlayFade(cEvent *self) {
    unsigned long f;
    if (D_00747A2C >= 0) {
        f = D_00586B34;
        if (!((f >> 1) & 1) && !((f >> 2) & 1) && !((f >> 3) & 1)) {
            classFADE_start(D_00747470, 0, 10, 0, 0, 0xFF000000, 15);
        }
    }
}

/* Begin a move scene: raise the global move flag, run the 16 stripped setup
 * hooks, and mark the scene as running. */
__attribute__((section(".text.cEvent_movePlayInit")))
void cEvent_movePlayInit(cEvent *self) {
    unsigned long f = self->flags;
    long inited;
    inited = (f >> 1) & 1;                 /* CEVENT_F_INITED */
    if (inited != 0 && ((f >> 2) & 1) == 0) { /* and not CEVENT_F_MOVE_ON */
        D_00747A84 |= 1;
        func_0(cEvent_nullStr00);
        func_0(cEvent_nullStr00);
        func_0(cEvent_nullStr01);
        func_0(cEvent_nullStr02);
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
        self->flags |= CEVENT_F_MOVE_ON;
    }
}

/* Run the move scene's stripped teardown hooks and return the last result,
 * or 0 when no move scene is running. */
__attribute__((section(".text.cEvent_movePlayStep")))
int cEvent_movePlayStep(cEvent *self) {
    unsigned long f = self->flags;
    long on = (f >> 2) & 1;                /* CEVENT_F_MOVE_ON */
    if (on == 0) return 0;
    func_0(cEvent_nullStr00);
    func_0(cEvent_nullStr00);
    func_0(cEvent_nullStr00);
    func_0(cEvent_nullStr01);
    func_0(cEvent_nullStr02);
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
    return cEvent_nullHookI(cEvent_nullStr00);
}
