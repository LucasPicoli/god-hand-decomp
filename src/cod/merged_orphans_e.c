/* cSnd_SetBgmTblNo: `func_002D0658(0.0f)` — forwarding call with a float arg. */
extern void func_002D0658(float);
__attribute__((section(".text.cSnd_SetBgmTblNo")))
void cSnd_SetBgmTblNo(void) { func_002D0658(0.0f); }

/* cSceAtManager_isHit: chain — alloc via cSceAtManager_getUnit(a0,a1); if non-null,
 * tail-process via func_002C0ED0(obj, a2); else return 0. */
extern void *cSceAtManager_getUnit(void *a0, void *a1);
extern void *func_002C0ED0(void *obj, void *a2);
/* cRoomSave_getFree: pointer-arithmetic getter — DEFERRED.  The natural body
 * compiles to the right 10 insns but SN -O2 emits a branch-likely
 * (`beqzl`) with the shared `a1<<2` hoisted before the compare, whereas
 * retail uses a plain `beqz` with the shift in its delay slot.  Matching
 * needs branch-likely suppression (a per-TU `-mno-branch-likely` would
 * destabilize the other SN TUs); left for a focused codegen-flag pass. */

/* cEvent__isPlaying: gated predicate.  If a global flag bit is set, return
 * whether obj->byte_4 == 3; else 0. */
extern int D_00747A84;
__attribute__((section(".text.cEvent__isPlaying")))
int cEvent__isPlaying(signed char *a0) {
    if (!(D_00747A84 & 0x20000000))
        return 0;
    return a0[4] == 3;
}

/* cEmWrap_getPos: getter with a guard call.  If FindResolveActor_295978(a0) is 0,
 * return &D_00747B00; else return obj->field_4->field_F0. */
extern int D_00747B00;
extern int FindResolveActor_295978(void *a0);
__attribute__((section(".text.cEmWrap_getPos")))
void *cEmWrap_getPos(void *a0) {
    if (FindResolveActor_295978(a0) == 0)
        return &D_00747B00;
    return *(void **)(*(char **)((char *)a0 + 4) + 0xF0);
}

/* InitObjVtableAndRegister_2E76F8: constructor — store vtable at obj+0xF0, register via
 * cWorldLight_Del_LightData, then init via func_002FBE28(obj, a1). */
extern int D_0044E640;
extern int D_00604700;
extern void cWorldLight_Del_LightData(void *a, unsigned short b, int c);
extern void func_002FBE28(void *obj, void *a1);
__attribute__((section(".text.InitObjVtableAndRegister_2E76F8")))
void InitObjVtableAndRegister_2E76F8(void *obj, void *a1) {
    *(int **)((char *)obj + 0xF0) = &D_0044E640;
    cWorldLight_Del_LightData(&D_00604700, *(unsigned short *)((char *)obj + 0x2B2),
                  *(int *)((char *)obj + 0x2B4));
    func_002FBE28(obj, a1);
}
