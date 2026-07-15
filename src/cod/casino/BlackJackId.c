/* TU: BlackJackId [casino] - recovered C++ class. */
#include "include_asm.h"

extern void SetFlagOnEntries7C_1D51B8();
extern void CustomIDWork_Main(void *a0);
extern void cIDBase_move(void *a0);

__attribute__((section(".text.BlackJackId_Move")))
void BlackJackId_Move(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;

    q = p + 0x60;
    /* `i >= 0`: retail closes this loop with `bgez` (not `bne`), so the
       counter compares against zero, not a materialised -1. The loop body
       carries a call, so ee-as omits the R5900 short-loop pad → this needs
       --call-loop-pad to reinsert the nop before the closing branch. */
    for (i = 0x2C; i >= 0; i--) {
        CustomIDWork_Main(q);
        q += 0x7C;
    }
    cIDBase_move(p + 0x10);
}

__attribute__((section(".text.BlackJackId_SetDefaultDisp")))
void BlackJackId_SetDefaultDisp(int a0) {
    SetFlagOnEntries7C_1D51B8(a0, 0x2D, 0);
    SetFlagOnEntries7C_1D51B8(a0, 0x1, 1);
    SetFlagOnEntries7C_1D51B8(a0, 0x2, 1);
    SetFlagOnEntries7C_1D51B8(a0, 0x3, 1);
    SetFlagOnEntries7C_1D51B8(a0, 0x4, 1);
    SetFlagOnEntries7C_1D51B8(a0, 0xA, 1);
    SetFlagOnEntries7C_1D51B8(a0, 0xC, 1);
    SetFlagOnEntries7C_1D51B8(a0, 0xF, 1);
    SetFlagOnEntries7C_1D51B8(a0, 0x22, 1);
    SetFlagOnEntries7C_1D51B8(a0, 0x19, 1);
}
