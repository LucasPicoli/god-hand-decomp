/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern void PushEsp(void *a0);
extern int D_003FA62C;
extern void __malloc_lock(int a0);
extern void func_003ACA28(int a0, int a1);
extern void __malloc_unlock(int a0);
extern float D_00741DC0;
extern float D_00754C48;

__attribute__((section(".text.UpdateObjByIndexedOp_2FBE50")))
void UpdateObjByIndexedOp_2FBE50(void *a0) {
    int r;
    r = func_002B5E50(a0);
    func_002B5CF0(a0, r);
    PushEsp(a0);
}

__attribute__((section(".text.UpdateGlobalPtrWithParam_3A7CC0")))
void UpdateGlobalPtrWithParam_3A7CC0(int a0) {
    __malloc_lock(D_003FA62C);
    func_003ACA28(D_003FA62C, a0);
    __malloc_unlock(D_003FA62C);
}

__attribute__((section(".text.SetField548AndGlobals_292F38")))
void SetField548AndGlobals_292F38(void *a0, float f12) {
    *(float*)((char*)a0 + 0x548) = f12;
    D_00741DC0 = f12;
    D_00754C48 = f12;
}
