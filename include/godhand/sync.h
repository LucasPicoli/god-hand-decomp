/* include/godhand/sync.h — R5900 CONTROL instructions as per-op intrinsics.
 *
 * # Why this header exists
 *
 * `sync` (and its `sync.l` / `sync.p` forms) has NO C form.  A probe of every
 * installed cc1 — 28 binaries as of D-032 — finds no `__builtin_*sync*` of any
 * kind, and no scalar C construct emits the instruction.  SCE's own
 * `eekernel.h` writes it as inline assembly for the same reason.
 *
 * D-032 (2026-09-09) widened the file from the barrier alone to the R5900
 * control instructions that share that ground, and added `ei` / `di`.  The same
 * 28-binary probe finds no builtin reaching either, and the 2,213 objects this
 * project compiles from its own C emit `ei` zero times and `di` zero times.
 * `eekernel.h` groups them with `sync`, which is why they live here and not in
 * a file of their own.
 *
 * It is therefore a **bucket-1** construct under map ticket 21: a per-op macro
 * that ADDS an instruction the compiler cannot emit.  It does not steer
 * register allocation, it does not move code the compiler could place itself,
 * and it expands to exactly one instruction.  That is the same ground
 * `include/godhand/vu0.h` stands on (D-026 / D-027 / D-028).
 *
 * # What it unblocks
 *
 * Three functions are byte-exact from plain C except for a single `sync`:
 * `sceGsSetDefClear`, `func_00396A70` and `VSync` — 896 B.  Two more,
 * `sceGsSetDefDrawEnv2` and `VSync2`, carry the same single-instruction gap.
 * Measured 2026-09-01 by wave 22 lane LB5.
 *
 * # The expansion
 *
 * Each macro is a `.set noreorder` block holding ONLY the barrier, so the
 * assembler adds nothing of its own and the delay-slot filler cannot move an
 * instruction across it by accident.  `memory` is in the clobber list because
 * that is what the barrier means; without it gcc may sink a store past it.
 */
#ifndef GODHAND_SYNC_H
#define GODHAND_SYNC_H

/* Plain `sync` — the R5900 spells the completion barrier this way. */
#define GH_SYNC()                                                              \
    __asm__ __volatile__(".set noreorder\n\t"                                  \
                         "sync\n\t"                                            \
                         ".set reorder"                                        \
                         : : : "memory")

/* `sync.l` — load barrier. */
#define GH_SYNC_L()                                                            \
    __asm__ __volatile__(".set noreorder\n\t"                                  \
                         "sync.l\n\t"                                          \
                         ".set reorder"                                        \
                         : : : "memory")

/* `sync.p` — pipeline barrier. */
#define GH_SYNC_P()                                                            \
    __asm__ __volatile__(".set noreorder\n\t"                                  \
                         "sync.p\n\t"                                          \
                         ".set reorder"                                        \
                         : : : "memory")

/* `ei` / `di` — enable and disable interrupts (COP0 Status IE).  Privileged
 * control instructions; no C construct reaches either.  D-032.
 *
 * SCE's `eekernel.h:62` writes the first as `__asm__ volatile("ei")`, with no
 * `.set noreorder` and no clobber.  These keep the barrier form of the three
 * macros above, because the `.set noreorder` block is what stops the delay-slot
 * filler moving an instruction across the site by accident, and both consumers
 * are byte-exact with it.  Drop back to the vendor spelling only against a
 * measured byte.
 *
 * The vendor's `DI()` is a RETRY LOOP, not one instruction — `di`, `sync.p`,
 * then `mfc0 $12` until the interrupt bit clears.  A retail body carrying that
 * whole shape needs the loop, not `GH_DI()`.  Read the bytes before you pick. */
#define GH_EI()                                                                \
    __asm__ __volatile__(".set noreorder\n\t"                                  \
                         "ei\n\t"                                              \
                         ".set reorder"                                        \
                         : : : "memory")

#define GH_DI()                                                                \
    __asm__ __volatile__(".set noreorder\n\t"                                  \
                         "di\n\t"                                              \
                         ".set reorder"                                        \
                         : : : "memory")

#endif /* GODHAND_SYNC_H */
