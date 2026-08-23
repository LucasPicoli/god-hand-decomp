/* cygnus-2.96 matched TU. */

extern char D_00459990[];
extern int D_003EE320;
extern int D_003EE31C;
extern int D_003EE328;
extern int D_003EE32C;
extern void func_003A52F0(int a0, int a1, int a2);
extern void func_003A57C4(int a0, char *a1);
extern int strlen(const char *s);

/* func_0035CB20 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 8 B too early. The TRUE ENTRY is 0x0035CB20.
 * Byte-exact over the TRUE span under cygnus-2.96 with
 * c_flags_drop: ["-f=-freorder-blocks"].
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 2 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body looks
 * like in this class. Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_0035CB20 = 0x0035CB20; // type:func
 *   scripts/resplat.sh
 *
 * LANE X1 repair, wave 18.
 * CAUSE: integrate_batch._rehome hoists every `extern ...;` line above the
 * typedef it names, so `typedef struct {...} T112; extern T112 D_00459990;`
 * gave "parse error before "D_00459990"" and cc1 exit 33 in the merged TU.
 * REPAIR: the extern names no local type; the struct tag stays in the body
 * block and the global is cast once. Byte-exact, no .rodata. */









struct S35CB20 { char b[0x112]; };

__attribute__((section(".text.func_0035CB20")))
void func_0035CB20(void) {
    struct S35CB20 buf = *(struct S35CB20 *)D_00459990;
    if (D_003EE320 != 0) {
        func_003A52F0(D_003EE320, 0, D_003EE31C);
        D_003EE328 = D_003EE320;
        func_003A57C4(D_003EE320, buf.b);
        D_003EE328 = D_003EE328 + strlen(buf.b);
        D_003EE32C = D_003EE328;
    }
}
