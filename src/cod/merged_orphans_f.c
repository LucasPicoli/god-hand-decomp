extern int D_0041D8F8;
extern int D_00424328;
extern int D_00574380;
extern void ForwardFieldNeg20_002A9680_30F5A0(void *obj);
extern void ClearAndResetFields_1FE278(void *a, void *b);
extern void SetField214PtrThenInit_1B6F38(void *obj, void *a1);

/* InitObjVtableField35C_139878: store vtable at obj+0x35C (always); call ForwardFieldNeg20_002A9680_30F5A0
 * only when bit 0 of the flag arg is set. */
__attribute__((section(".text.InitObjVtableField35C_139878")))
void InitObjVtableField35C_139878(void *obj, int flags) {
    *(int **)((char *)obj + 0x35C) = &D_0041D8F8;
    if (flags & 1)
        ForwardFieldNeg20_002A9680_30F5A0(obj);
}

/* InitObjVtableFreeField604_192210: store vtable at obj+0x214; if obj->field_604 is live,
 * release it via ClearAndResetFields_1FE278 and clear it; then init via SetField214PtrThenInit_1B6F38. */
__attribute__((section(".text.InitObjVtableFreeField604_192210")))
void InitObjVtableFreeField604_192210(void *obj, void *a1) {
    *(int **)((char *)obj + 0x214) = &D_00424328;
    if (*(int *)((char *)obj + 0x604) != 0) {
        ClearAndResetFields_1FE278(&D_00574380, *(void **)((char *)obj + 0x604));
        *(int *)((char *)obj + 0x604) = 0;
    }
    SetField214PtrThenInit_1B6F38(obj, a1);
}

/* func_0038BBB8 / func_0038BBD8 (RE4 twin: cItemMgr::bulletNum thunks): thin
 * forwarders that tail-pass `this` to the real impl. Carved here (sn) out of the
 * cygnus 0038b8.c TU because SN emits the full jal+frame retail uses (cygnus
 * sibcalls them to a frameless `j`). */
extern int func_0038E490(void *this);
__attribute__((section(".text.func_0038BBB8")))
int func_0038BBB8(void *this) { return func_0038E490(this); }

extern int func_0038E3F0(void *this);
__attribute__((section(".text.func_0038BBD8")))
int func_0038BBD8(void *this) { return func_0038E3F0(this); }
