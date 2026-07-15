#include "include_asm.h"

extern void cIDBase(void *);
extern void CustomIDWork(void *);

/* -- PERMANENT (bnel/beql) — stay in monolithic asm/cod/000000 ------------ */
/* func_001F20F8 (beql+bnel, 0x324 B) stays in monolithic — PERMANENT.      */
/* func_001F2428 (bnel, 0x110 B) stays in monolithic — PERMANENT.           */
/* func_001F2540 (beql+bnel, 0x108 B) stays in monolithic — PERMANENT.      */
/* func_001F2650 (bnel, 0x40 B) stays in monolithic — PERMANENT.            */

/* -- Ghidra fragment (no jr $ra) — stay in monolithic asm/cod/000000 ------ */
/* func_001F26F0 (5 insn, no jr $ra) stays in monolithic — FRAGMENT.        */
/* func_001F27A8 (1 insn, no jr $ra) stays in monolithic — FRAGMENT.        */

/* -- Accessor C bodies (5) — jr $ra; nop empty functions ------------------ */

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_20F0")))
void Obj1F20_NoOp_20F0(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2420")))
void Obj1F20_NoOp_2420(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2538")))
void Obj1F20_NoOp_2538(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2648")))
void Obj1F20_NoOp_2648(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2690")))
void Obj1F20_NoOp_2690(void) {}

/* -- Call-chain (nonmatching) --------------------------------------------- */
INCLUDE_ASM("nonmatching", func_001F2698);

__attribute__((section(".text.func_001F2708")))
void *func_001F2708(void *a0) {
    char *this = (char *)a0;
    char *p;
    int i;

    *(int *)this = 0;
    cIDBase(this + 0x10);

    p = this + 0x60;
    /* `i != -1`, not `i >= 0`: retail materialises -1 and closes with bne. */
    for (i = 0x11; i != -1; i--) {
        CustomIDWork(p);
        p += 0x7C;
    }

    cIDBase(this + 0x930);

    p = this + 0x980;
    for (i = 2; i != -1; i--) {
        CustomIDWork(p);
        p += 0x7C;
    }

    return this;
}

INCLUDE_ASM("nonmatching", func_001F27B0);
