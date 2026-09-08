/* Thin forwarding wrappers in the newlib/stdio region (SN ProDG cc 2.95.3
 * build 136).  Each tail-forwards to its target; gcc 2.9x performs no
 * sibling-call optimisation, so the `return inner()` retains the
 * jal + ra-save shape rather than collapsing to a `j`.
 * Byte-match retail 0x0038F000..0x0038F138 (the ra-only-save wrappers;
 * the 0x0038F020 / 0x0038F0F0 neighbours remain INCLUDE_ASM).
 */

extern int func_00392F00(void);
extern int func_00393230(void);
extern int func_00393258(void);
extern int func_003932B8(void);
extern int func_00393278(void);
extern int func_00393298(void);
extern int xsgetn__9streambufPcl(void);

__attribute__((section(".text.func_0038F000")))
int func_0038F000(void) { return func_00392F00(); }

__attribute__((section(".text.func_0038F050")))
int func_0038F050(void) { return func_00393230(); }

__attribute__((section(".text.func_0038F070")))
int func_0038F070(void) { return func_00393258(); }

__attribute__((section(".text.func_0038F090")))
int func_0038F090(void) { return func_003932B8(); }

__attribute__((section(".text.func_0038F0B0")))
int func_0038F0B0(void) { return func_00393278(); }

__attribute__((section(".text.func_0038F0D0")))
int func_0038F0D0(void) { return func_00393298(); }

__attribute__((section(".text.func_0038F120")))
int func_0038F120(void) { return xsgetn__9streambufPcl(); }
