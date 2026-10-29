/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"

extern int func_002E0C80(int a, int b, int c, int d, int zero, int fmt, void *args);
extern void SetActionJumpUp(cEm00 *self);
extern void SetActionJumpDown(void);
extern int moveMotion(cEm00 *self);
extern void MtxInitCoord(void *a0, int a1, int a2, int a3, int t0);
extern int D_00422A80;
extern void func_002AD288(void *a0, int a1);
extern void SetField214PtrThenInit_1B6F38(void *a0, void *a1);
extern void Slot2_hideBankLayerIds(void *a0);
extern void displayScrollLayer(int id, int on);

/* Variadic wrapper: forwards the first four arguments and the format word
 * to func_002E0C80, plus a pointer to the register save area that holds the
 * unnamed arguments. */


__attribute__((section(".text.printf_2E0DA8")))
int printf_2E0DA8(int a, int b, int c, int d, int fmt, ...)
{
    char *args;
    args = (char *)__builtin_next_arg(fmt) - 24;
    return func_002E0C80(a, b, c, d, 0, fmt, args);
}

/* cEm00_startJumpSetup: if the 0x6A0 link is empty, do the jump-up and jump-down
 * setup and raise bit 0x100 of the flag word. */
#define EM_LINK6A0(self) (*(int *)((char *)(self) + 0x6A0))



__attribute__((section(".text.cEm00_startJumpSetup")))
void cEm00_startJumpSetup(cEm00 *self)
{
    if (EM_LINK6A0(self) == 0) {
        SetActionJumpUp(self);
        SetActionJumpDown();
        self->unk15F4 |= 0x100;
    }
}

/* cEm00_stepMotionCounter: step the motion; when the 0x984 counter has run out, reset the
 * phase block (phase 2), then count the counter down. */
#define EM_COUNT984(self) (*(short *)((char *)(self) + 0x984))


__attribute__((section(".text.cEm00_stepMotionCounter")))
void cEm00_stepMotionCounter(cEm00 *self)
{
    moveMotion(self);
    if (EM_COUNT984(self) <= 0) {
        self->step = 0;
        self->phase = 2;
        self->stepArg = 0;
    }
    EM_COUNT984(self) = EM_COUNT984(self) - 1;
}

/* Record that owns four coordinate vectors at 0x20..0x50; it builds them once. */
typedef struct CoordSet {
    char unk00[0x15];
    unsigned char kind;        /* 0x15 passed to MtxInitCoord as the last argument */
    unsigned char built;       /* 0x16 set when the vectors are built */
    char unk17[9];
    float v20[4];              /* 0x20 */
    float v30[4];              /* 0x30 */
    float v40[4];              /* 0x40 */
    float v50[4];              /* 0x50 */
} CoordSet;



/* func_002B64C0: build the four vectors once, then mark the record built. */
__attribute__((section(".text.func_002B64C0")))
void func_002B64C0(CoordSet *self)
{
    if (self->built == 0) {
        MtxInitCoord(self->v50, (int)self->v40, (int)self->v30, (int)self->v20, self->kind);
        self->built = 1;
    }
}

/* cObj_initWithSubRecord: set the method table (0x214), prepare the 0xB10 sub-record, then run the shared init. */
__attribute__((section(".text.cObj_initWithSubRecord")))
void cObj_initWithSubRecord(char *self, void *arg)
{
    *(int **)(self + 0x214) = &D_00422A80;
    func_002AD288(self + 0xB10, 2);
    SetField214PtrThenInit_1B6F38(self, arg);
}

/* Scroll_showLayerBySelector: run the shared setup, then turn on one of two scroll layers (0x400 or 0x404). */
__attribute__((section(".text.Scroll_showLayerBySelector")))
void Scroll_showLayerBySelector(char *self, int sel)
{
    Slot2_hideBankLayerIds(self);
    if (sel != 0) {
        displayScrollLayer(*(int *)(self + 0x400), 1);
    } else {
        displayScrollLayer(*(int *)(self + 0x404), 1);
    }
}
