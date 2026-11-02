/* include/godhand/fpu.h - single FPU instructions that have to stay where retail has them. */
#ifndef GODHAND_FPU_H
#define GODHAND_FPU_H

/* sqrt.s dst, src as written. With __builtin_sqrtf, cc1 schedules the constant
 * loads ahead of the root; retail loads the operand, pads two nops and takes the
 * root first (0x26A874 in func_0026A838), and only a volatile sqrt.s keeps that
 * order. Use it per function, only where __builtin_sqrtf doesn't match. */
#define FPU_SQRT_S(dst, src) __asm__ volatile("sqrt.s %0, %1" : "=f"(dst) : "f"(src))

#endif
