/* Struct: CGObj3260_t — dispatch/trampoline object; byte flag +0x1, indirect target +0xC (mostly tail-call trampolines). */
#include "include_asm.h"

/* ── Forward declarations for called external functions ─────────────────── */
extern void func_00336E88(void);
extern void func_00337C00(void);
extern void func_00337C88(void);
extern void func_00337B30(int a0);
extern void func_00337B80(int a0);
extern void func_00337BC8(int a0);
extern void func_00337728(void);
extern void func_00337D20(void);
extern void func_00337DE0(void);
extern void func_003382A0();  /* K&R: accepts any args */
extern void func_003381B0();  /* K&R: accepts any args */
extern void func_00338338();  /* K&R: accepts any args */
extern void func_003383B0(void);
extern void func_00338418(void);
extern void func_00338638(void);
extern void func_003386E0(void);
extern void func_00338710(void);
extern void func_00338788(void);
extern void func_003387C8(void);
extern void func_00338818(void);
extern void func_00338848(void);
extern void func_003388B0(void);
extern void func_003A52F0(void *a0, int a1, int a2);

/* ── Extern globals ─────────────────────────────────────────────────────── */
extern int D_003CF9E8;      /* reference counter for D_003CF9F0 region      */
extern char D_003CF9F0[];   /* managed memory region (size 0xAC0)            */

/* ── Weird fragment — no jr $ra, cannot be expressed as valid C ─────────── */
INCLUDE_ASM("nonmatching", func_00326008);

/* ── Call-chain functions (11 = deferred) ───────────── */
INCLUDE_ASM("nonmatching", func_00326020);
INCLUDE_ASM("nonmatching", func_00326050);
extern void func_003A7AE8(void *a0, void *a1, void *a2);
extern void func_003B1F28();
extern int D_003CF9E0;

__attribute__((section(".text.func_003260C8")))
void func_003260C8(void *a0, ...)
{
    char buf[0x80];
    if (D_003CF9E0 != 2) {
        func_003A7AE8(buf, a0, (char *)__builtin_next_arg(a0) - 0x38);
        func_003B1F28(buf);
    }
}

INCLUDE_ASM("nonmatching", ADXPS2_GetNumDataSjtmp);
INCLUDE_ASM("nonmatching", func_003261A8);
/* Obj3260_TrampChain_D2D8: call func_00338338(a0,0) + func_003382A0(a0,0) + tail-call   */
/* func_003381B0(a0). Saves a0 in $s0 across both calls.                        */
__attribute__((section(".text.Obj3260_TrampChain_D2D8")))
void Obj3260_TrampChain_D2D8(void *a0) {
    func_00338338(a0, 0);
    func_003382A0(a0, 0);
    func_003381B0(a0);
}
INCLUDE_ASM("nonmatching", func_003265A8);
extern void func_0033C918(int);
extern void Forward33B658_33E678(void);
extern void func_003A52F0(void *a0, int a1, int a2);
extern void Forward33B670_33E690(void);

__attribute__((section(".text.func_00326718")))
void func_00326718(int a0) {
    int v0;
    if (a0 == 0)
        return;
    v0 = *(int*)(a0 + 4);
    if (v0 != 0) {
        *(int*)(a0 + 4) = 0;
        func_0033C918(v0);
    }
    Forward33B658_33E678();
    func_003A52F0((void *)a0, 0, 0xAC);
    Forward33B670_33E690();
}

INCLUDE_ASM("nonmatching", func_00326780);
INCLUDE_ASM("nonmatching", func_003267C0);

/* ── Obj3260_CallReturn0_003388F8_D498: simple call-then-return-zero (8 insns, jal) ─────────── */
/* Pattern: addiu; sd $ra; jal func_003388F8; nop; ld $ra; move $v0,$zero; jr $ra; addiu */
extern void func_003388F8(void);
__attribute__((section(".text.Obj3260_CallReturn0_003388F8_D498")))
int Obj3260_CallReturn0_003388F8_D498(void) { func_003388F8(); return 0; }

/* ── Simple trampolines (addiu; sd $ra; ld $ra; j target; addiu) ────────── */
/* 5 insns each: prologue saves $ra, epilogue restores $ra then tail-jumps.  */

/* Obj3260_Tramp_00336E88_D148 → j func_00336E88 */
__attribute__((section(".text.Obj3260_Tramp_00336E88_D148")))
void Obj3260_Tramp_00336E88_D148(void) { func_00336E88(); }

/* Obj3260_Tramp_00337C00_D1F0 → j func_00337C00 */
__attribute__((section(".text.Obj3260_Tramp_00337C00_D1F0")))
void Obj3260_Tramp_00337C00_D1F0(void) { func_00337C00(); }

/* Obj3260_Tramp_00337C88_D208 → j func_00337C88 */
__attribute__((section(".text.Obj3260_Tramp_00337C88_D208")))
void Obj3260_Tramp_00337C88_D208(void) { func_00337C88(); }

/* Obj3260_Tramp_00337728_D288 → j func_00337728 */
__attribute__((section(".text.Obj3260_Tramp_00337728_D288")))
void Obj3260_Tramp_00337728_D288(void) { func_00337728(); }

/* Obj3260_Tramp_00337D20_D2A0 → j func_00337D20 */
__attribute__((section(".text.Obj3260_Tramp_00337D20_D2A0")))
void Obj3260_Tramp_00337D20_D2A0(void) { func_00337D20(); }

/* Obj3260_Tramp_00337DE0_D2C0 → j func_00337DE0 */
__attribute__((section(".text.Obj3260_Tramp_00337DE0_D2C0")))
void Obj3260_Tramp_00337DE0_D2C0(void) { func_00337DE0(); }

/* Obj3260_Tramp_003382A0_D320 → j func_003382A0 */
__attribute__((section(".text.Obj3260_Tramp_003382A0_D320")))
void Obj3260_Tramp_003382A0_D320(void) { func_003382A0(); }

/* Obj3260_Tramp_00338338_D338 → j func_00338338 */
__attribute__((section(".text.Obj3260_Tramp_00338338_D338")))
void Obj3260_Tramp_00338338_D338(void) { func_00338338(); }

/* Obj3260_Tramp_003383B0_D358 → j func_003383B0 */
__attribute__((section(".text.Obj3260_Tramp_003383B0_D358")))
void Obj3260_Tramp_003383B0_D358(void) { func_003383B0(); }

/* func_00326370 → j func_00338418 */
/* NOTE: 3 trailing nops after endlabel (0xC extra bytes); ALIGN(8) only       */
/* adds 4 bytes → 8-byte deficit shifts all subsequent VMAs. Use INCLUDE_ASM.  */
INCLUDE_ASM("nonmatching", func_00326370);

/* Obj3260_Tramp_00338638_D390 → j func_00338638 */
__attribute__((section(".text.Obj3260_Tramp_00338638_D390")))
void Obj3260_Tramp_00338638_D390(void) { func_00338638(); }

/* Obj3260_Tramp_003386E0_D3B0 → j func_003386E0 */
__attribute__((section(".text.Obj3260_Tramp_003386E0_D3B0")))
void Obj3260_Tramp_003386E0_D3B0(void) { func_003386E0(); }

/* Obj3260_Tramp_00338710_D3C8 → j func_00338710 */
__attribute__((section(".text.Obj3260_Tramp_00338710_D3C8")))
void Obj3260_Tramp_00338710_D3C8(void) { func_00338710(); }

/* Obj3260_Tramp_00338788_D3E0 → j func_00338788 */
__attribute__((section(".text.Obj3260_Tramp_00338788_D3E0")))
void Obj3260_Tramp_00338788_D3E0(void) { func_00338788(); }

/* Obj3260_Tramp_003387C8_D3F8 → j func_003387C8 */
__attribute__((section(".text.Obj3260_Tramp_003387C8_D3F8")))
void Obj3260_Tramp_003387C8_D3F8(void) { func_003387C8(); }

/* Obj3260_Tramp_00338818_D410 → j func_00338818 */
__attribute__((section(".text.Obj3260_Tramp_00338818_D410")))
void Obj3260_Tramp_00338818_D410(void) { func_00338818(); }

/* Obj3260_Tramp_00338848_D428 → j func_00338848 */
__attribute__((section(".text.Obj3260_Tramp_00338848_D428")))
void Obj3260_Tramp_00338848_D428(void) { func_00338848(); }

/* Obj3260_Tramp_003388B0_D468 → j func_003388B0 */
__attribute__((section(".text.Obj3260_Tramp_003388B0_D468")))
void Obj3260_Tramp_003388B0_D468(void) { func_003388B0(); }

/* ── Modified trampolines (lw $a0, 0xC($a0); j target) ─────────────────── */
/* 6 insns: prologue + load $a0 = *(a0+0xC) + tail-jump with modified arg.  */

/* Obj3260_TrampVia0C_00337B30_D220: $a0 = *(int*)($a0+0xC), then j func_00337B30 */
__attribute__((section(".text.Obj3260_TrampVia0C_00337B30_D220")))
void Obj3260_TrampVia0C_00337B30_D220(char *a0) { func_00337B30(*(int *)(a0 + 0xC)); }

/* Obj3260_TrampVia0C_00337B80_D238: $a0 = *(int*)($a0+0xC), then j func_00337B80 */
__attribute__((section(".text.Obj3260_TrampVia0C_00337B80_D238")))
void Obj3260_TrampVia0C_00337B80_D238(char *a0) { func_00337B80(*(int *)(a0 + 0xC)); }

/* Obj3260_TrampVia0C_00337BC8_D250: $a0 = *(int*)($a0+0xC), then j func_00337BC8 */
__attribute__((section(".text.Obj3260_TrampVia0C_00337BC8_D250")))
void Obj3260_TrampVia0C_00337BC8_D250(char *a0) { func_00337BC8(*(int *)(a0 + 0xC)); }

/* ── Empty functions (jr $ra; nop) ─────────────────────────────────────── */

__attribute__((section(".text.Obj3260_NoOp_D2B8")))
void Obj3260_NoOp_D2B8(void) {}

__attribute__((section(".text.Obj3260_NoOp_D490")))
void Obj3260_NoOp_D490(void) {}

/* ── "addiu-only" stubs (no jr $ra; inserted as nonmatching) ────────────── */
/* These consist entirely of `addiu $sp, $sp, 0x10` (with nops);            */
/* they cannot be expressed as valid C that returns through $ra.             */
INCLUDE_ASM("nonmatching", func_003261A0);
INCLUDE_ASM("nonmatching", func_003261E0);
INCLUDE_ASM("nonmatching", func_00326268);
INCLUDE_ASM("nonmatching", func_00326310);
INCLUDE_ASM("nonmatching", func_00326350);
INCLUDE_ASM("nonmatching", func_003263A8);
INCLUDE_ASM("nonmatching", func_00326440);
INCLUDE_ASM("nonmatching", func_00326480);
INCLUDE_ASM("nonmatching", func_003264B8);

/* ── Byte getter ────────────────────────────────────────────────────────── */
/* Obj3260_GetByte_1_D778: jr $ra; lb $v0, 0x1($a0) — signed byte in delay slot      */

__attribute__((section(".text.Obj3260_GetByte_1_D778")))
int Obj3260_GetByte_1_D778(char *a0) { return a0[1]; }

/* ── Struct initializer (15 insns, no jal/branch) ────────────────────────  */
/* Store-rotation order: cygnus rotates the last source store to the front  */
/* and the second-to-last into the jr delay slot, so sw 0xA0 is written     */
/* second-to-last and sw 0x3C last to land them as front/delay.             */
__attribute__((section(".text.func_00326568")))
void func_00326568(char *p) {
  *(int *)(p + 0x38) = 0x7FFFFFFF;
  *(int *)(p + 0xA4) = 0;
  *(int *)(p + 0x98) = 0;
  *(int *)(p + 0x2C) = 0;
  *(int *)(p + 0x30) = 0;
  *(int *)(p + 0x34) = 0;
  *(int *)(p + 0x40) = 0;
  *(int *)(p + 0x44) = 0;
  p[0x3] = 0;
  *(int *)(p + 0xA0) = 0;
  *(int *)(p + 0x3C) = -1;
}

/* ── Branched-leaf (T0 attempt 1 failed → INCLUDE_ASM) ─────────────────── */
/* func_00326520: decrement refcount + conditional tail-call.                */
/* C compiler inverts branch logic (beqz vs bnez) → structural mismatch.    */
/* Deferred.                                              */
