/* cygnus-2.96 matched TU. */

struct AsyncCall;
extern int Obj33C8_GetField_CC(struct AsyncCall *self);
extern short Obj33C8_GetShort_E0(struct AsyncCall *self);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern int Obj33F8_Tramp_0033B670_FC88(void);
extern void func_003A52F0(void *a0, int a1, int a2);
extern int D_003D1E68;
extern int D_003D1E70[];

/* AINF volume offset while the stream prepares or plays; 0 otherwise or without AINF. */
__attribute__((section(".text.func_00327890")))
int func_00327890(char *a0) {
    if (Obj33C8_GetField_CC(*(struct AsyncCall **)(a0 + 4)) <= 0) {
        return 0;
    }
    if ((unsigned int)(*(unsigned char*)(a0 + 1) - 2) < 2) {
        return Obj33C8_GetShort_E0(*(struct AsyncCall **)(a0 + 4));
    }
    return 0;
}

__attribute__((section(".text.func_0032F230")))
int func_0032F230(void) {
    int v;
    Obj33F8_Tramp_0033B658_FC70();
    v = D_003D1E68;
    if (v == 0) {
        func_003A52F0(D_003D1E70, 0, 0x6590);
        v = D_003D1E68;
    }
    D_003D1E68 = v + 1;
    return Obj33F8_Tramp_0033B670_FC88();
}
