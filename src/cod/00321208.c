/* sn-2.95.3-136 matched TU. */

extern char D_0076B040[];
extern char D_0076A7D4[];
extern void (*D_003C4908)(void);

/* LANE X1 repair, wave 18.
 * CAUSE: integrate_batch._rehome hoists every `extern ...;` line above the
 * typedef it names, so `typedef struct {...} T20; extern T20 D_...[];` gave
 * "parse error before `D_0076B040'" and cc1 exit 33 in the merged TU.
 * REPAIR: the extern lines name no local type; the struct tag stays in the
 * body block and the base pointers are cast once. Byte-exact, no .rodata. */



struct S374B00 { char b[0x20]; };

__attribute__((section(".text.func_00374B00")))
void func_00374B00(void) {
    int i;
    struct S374B00 *d = (struct S374B00 *)D_0076B040;
    struct S374B00 *s = (struct S374B00 *)D_0076A7D4;
    for (i = 1; i >= 0; i--) {
        *d = *s;
        d++;
        s++;
    }
}

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : terminate
 * TRUE ENTRY      : 0x00321208
 * head bytes      : 40 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_00321208 = 0x00321208; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 10 words.
 * Land it after the boundary moves.
 *
 * LANE X1 repair, wave 18.
 * CAUSE: integrate_batch._rehome hoists every `extern ...;` line above the
 * typedef it names, so `typedef void (*vfp)(void); extern vfp D_003C4908;`
 * gave "parse error before `D_003C4908'" and cc1 exit 33 in the merged TU.
 * REPAIR: the extern spells the function-pointer type itself and names no
 * typedef. The typedef stays for the signature and carries a unique name so
 * a second body can share the TU. Byte-exact, no .rodata. */


typedef void (*vfp321208)(void);

__attribute__((section(".text.func_00321208")))
vfp321208 func_00321208(vfp321208 func) {
    vfp321208 old;
    old = D_003C4908;
    D_003C4908 = func;
    return old;
}
