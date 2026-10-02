/* ── 1. id/mask thunks ──────────────────────────────────────────────
 * `addiu $a0,1 ; jal helper ; ori $a1,0xFFFF` — a forwarding call with
 * a stack frame (the helper is not a tail call).  $v0 is left as the
 * helper's return value.
 */
extern int ResetGlobalStateFields_107DE0(int id, int mask);
extern int func_00155DC8(int id, int mask);
extern int func_001574F0(int id, int mask);
extern int func_00294AE0(int id, int mask);
extern int func_00308EE8(int id, int mask);
extern int func_0031D9F0(int id, int mask);

__attribute__((section(".text.Forward107DE0_107E20")))
int Forward107DE0_107E20(void) { return ResetGlobalStateFields_107DE0(1, 0xFFFF); }

__attribute__((section(".text.Forward155DC8_1563D0")))
int Forward155DC8_1563D0(void) { return func_00155DC8(1, 0xFFFF); }

__attribute__((section(".text.Forward1574F0_157540")))
int Forward1574F0_157540(void) { return func_001574F0(1, 0xFFFF); }

__attribute__((section(".text.Forward294AE0_294B18")))
int Forward294AE0_294B18(void) { return func_00294AE0(1, 0xFFFF); }

__attribute__((section(".text.Forward308EE8_308EF8")))
int Forward308EE8_308EF8(void) { return func_00308EE8(1, 0xFFFF); }

__attribute__((section(".text.Forward31D9F0_31DA28")))
int Forward31D9F0_31DA28(void) { return func_0031D9F0(1, 0xFFFF); }

/* ── 2. trivial leaves ──────────────────────────────────────────────*/

/* `jr $ra ; nop` — empty. */
__attribute__((section(".text.NoOp_1F0530")))
void NoOp_1F0530(void) {}

/* `jr $ra ; lw $v0, 0xF0($a0)` — return obj->field_F0. */
__attribute__((section(".text.cGameObj_getPos")))
int cGameObj_getPos(void *obj) { return *(int *)((char *)obj + 0xF0); }

/* `sb $a2,0x54($a0) ; jr $ra ; sb $a1,0x3A($a0)` — two byte stores. */
/* Source order is swapped vs the asm: SN -O2 schedules the second store
 * into the jr delay slot, so writing 0x3A then 0x54 yields the retail
 * `sb a2,0x54 ; jr ; sb a1,0x3A` order. */
/* ── 3. store-then-init constructor variants ────────────────────────
 * Like batch C (store a struct/vtable pointer, then call an init helper
 * with obj) but with a non-0xF0 store offset, or a 2-arg registration.
 */
extern int D_0041D7B8;
extern int D_00424D18;
extern int D_00586AF0;
extern void InitVtableField30_1339C0(void *obj);
extern void SetField214PtrThenInit_1B6F38(void *obj);
extern void func_00298088(void);
extern void func_00297B40(void *a, void *b);

__attribute__((section(".text.InitObjVtableField30_133B58")))
void InitObjVtableField30_133B58(void *obj) {
    *(int **)((char *)obj + 0x30) = &D_0041D7B8;
    InitVtableField30_1339C0(obj);
}

__attribute__((section(".text.InitObjVtableField214_195ED0")))
void InitObjVtableField214_195ED0(void *obj) {
    *(int **)((char *)obj + 0x214) = &D_00424D18;
    SetField214PtrThenInit_1B6F38(obj);
}

/* `func_00297B40(&D_00586AF0, &func_00298088)` — register a callback. */
__attribute__((section(".text.Forward297B40_298060")))
void Forward297B40_298060(void) {
    func_00297B40(&D_00586AF0, (void *)&func_00298088);
}
