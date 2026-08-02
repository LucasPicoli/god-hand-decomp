/* include/godhand/eesyscall.h — EE kernel syscall-stub helper.
 *
 * # Why this header is project-local (not `include/sce/eesyscall.h`)
 *
 * The retail ELF statically links the SCE `libkernel` syscall
 * trampolines: one four-instruction leaf per kernel service,
 *
 *     addiu  $v1, $zero, <num>
 *     syscall
 *     jr     $ra
 *      nop
 *
 * There is no C construct that emits a `syscall` instruction, and
 * ee-gcc 2.95/2.96 exposes no `__builtin_syscall`, so every one of
 * these stubs is hand-written assembly in the original SDK.  This
 * header is the project-local **idiom-stabilising** wrapper for that
 * shape — the same role `godhand/vu0.h` plays for COP2 macromode.
 * Per the lazy-vendor rule, if a canonical SCE header with this
 * trampoline ever surfaces, this header is superseded and
 * moved/dropped accordingly.
 *
 * # Shape and why the framing is load-bearing
 *
 * `EE_SYSCALL(num)` expands to a `.set noreorder` block containing
 * exactly the two instructions the retail stub has before its
 * epilogue:
 *
 *   .set push ; .set noreorder ; addiu $3, $0, num ; syscall ; .set pop
 *
 * `$3` is `$v1`, the EE kernel's syscall-number register.  The
 * `.set noreorder` framing pins order so neither ee-gcc's scheduler
 * nor ee-as's reorder pass can pull an unrelated instruction into
 * the (architecturally non-existent) slot between the number load
 * and the trap, and so `syscall` cannot be hoisted into the `jr $ra`
 * delay slot of the compiler-emitted epilogue.  The stub bodies are
 * leaves with no frame, so ee-gcc emits `jr $ra ; nop` after the
 * block — byte-identical to retail.
 *
 * `num` is a compile-time literal in [-0x100, 0xFF]; the negative
 * range is the kernel-internal ("K"-prefixed) service block, and
 * `addiu` sign-extends its 16-bit immediate, so negative literals
 * assemble to the same word retail uses.  It must stay an `"i"`
 * constraint — a register-passed number would emit an extra move.
 *
 * # Scope
 *
 * One macro, one shape.  Do NOT speculatively add variants (e.g.
 * argument-shuffling stubs); add on demand when a real match needs
 * one, the same lazy-vendor rule `godhand/vu0.h` follows.
 */
#ifndef GODHAND_EESYSCALL_H
#define GODHAND_EESYSCALL_H

/* EE_SYSCALL(num): load the kernel syscall number into $v1 and trap.
 *
 * Expands to:
 *     .set push
 *     .set noreorder
 *     addiu $3, $0, num
 *     syscall
 *     .set pop
 */
#define EE_SYSCALL(num)                                                \
    __asm__ __volatile__ (                                             \
        ".set push\n"                                                  \
        ".set noreorder\n"                                             \
        "addiu $3, $0, %0\n"                                           \
        "syscall\n"                                                    \
        ".set pop\n"                                                   \
        :                                                              \
        : "i"((int)(num))                                              \
        : "memory")

#endif /* GODHAND_EESYSCALL_H */
