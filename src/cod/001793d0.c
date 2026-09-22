/* sn-2.95.3-136 matched TU. */

extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern char D_005FEE00[];
extern void func_003057D0(void *a, int b, int c);
extern void ClearAndResetFields_1FE278(void *a, void *b);
extern void espSys_effDataRelease(void *a, int b);
extern void SetField214PtrThenInit_1B6F38(void *a, void *b);
extern char D_00422EB8[];
extern char D_00574380[];
extern char D_007419A0[];
extern int cSeData_IsAlive(void *p);
extern int EnsureInitThenForward_2A9538_30EE08(int a, int b, int c);
extern int FindEntryValue_1FF9C0(void *a, void *b, int c, int d);
extern void func_002CFCB0(void *a, int b);
extern char D_00580D40[];
extern void cIDBase_initialize(void *p, int a, int b);
extern void cIDBase_restartAnim(void *p);
extern void *cIDBase_getIDWork(void *p, int i);
extern void CustomIDWork_Initialize(void *p, void *w);
extern void CustomIDWork_SetDisp(void *p, int f);
extern void CustomIDWork_SetNumber_1DD218(void *p, int n);
extern void func_001DD238(void *p, int n);
extern void SetFieldShorts0C0E_1F9C88(void *p);
extern void func_001F9ED0(void *p);
extern void CopyGlobalPairToTarget_1F9C30(void *p);
extern void UpdateCounterClamped_1F9C58(void *p);
extern void func_001F9DD0(void *p);
extern void func_001F9E28(void *p);
extern void Obj0000_Set_Field_178_D_00747A0C_1F9E90(void *p);
extern void func_001FACB0(void *p);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void cCoreSave_setVital(void *p, int v);

__attribute__((section(".text.func_001793D0")))
void func_001793D0(char *p)
{
    int st = *(unsigned char *)(p + 0x2F5);
    int n;

    if (st == 0) goto init;
    if (st == 1) goto tick;
    return;
init:
    cSnd_SeCall_2CBA48((void *)D_005FEE00, 2, 2, p, 0, 0, 0, 0);
    *(short *)(p + 0x654) = 0xF;
    *(char *)(p + 0x2F5) = 1;
    *(char *)(p + 0x2F6) = 0;
    *(char *)(p + 0x2F7) = 0;
tick:
    n = *(unsigned short *)(p + 0x654) - 1;
    *(short *)(p + 0x654) = n;
    if ((short)n <= 0) {
        *(char *)(p + 0x2F4) = 0;
        *(char *)(p + 0x2F5) = 0;
        *(char *)(p + 0x2F6) = 0;
        *(char *)(p + 0x2F7) = 0;
    }
}

typedef struct { int kind; int pad[3]; } Slot;

__attribute__((section(".text.func_00305908")))
int func_00305908(void *a0, int a1, int a2)
{
    char *e;
    Slot *t;
    int i;

    e = (char *)func_003058D8(a0, a1, a2);
    t = (Slot *)a0;
    if (e == 0) goto scan;
    *(int *)(e + 0xC) = *(int *)(e + 0xC) + 1;
    goto ok;
scan:
    for (i = 0; (unsigned int)i < 0x40; i++) {
        if (t[i].kind == 5) goto found;
    }
    return 0;
found:
    func_003057D0(&t[i], a1, a2);
ok:
    return 1;
}

__attribute__((section(".text.func_001838D8")))
void func_001838D8(char *p, void *arg)
{
    void **q;
    int i;

    *(void **)(p + 0x214) = (void *)D_00422EB8;

    q = (void **)(p + 0x600);
    for (i = 0; (unsigned int)i < 7; i++) {
        if (q[i] != 0) {
            ClearAndResetFields_1FE278((void *)D_00574380, q[i]);
            q[i] = 0;
        }
    }

    espSys_effDataRelease((void *)D_007419A0, 0x298);
    SetField214PtrThenInit_1B6F38(p, arg);
}

__attribute__((section(".text.func_002CFBC0")))
int func_002CFBC0(char *p)
{
    char *x;
    int r;

    if (cSeData_IsAlive(p) == 1) return 0;

    *(int *)(p + 0x24) = EnsureInitThenForward_2A9538_30EE08(
        ((**(unsigned int **)(p + 0x20) + 0x8E) >> 1) * 4,
        0x10,
        *(int *)(p + 0x8));

    x = *(char **)(p + 0x10);
    r = FindEntryValue_1FF9C0((void *)D_00580D40, x + *(int *)(x + 0x30), 0, 0);

    if (func_00322A68(*(void **)(p + 0x28), 0, r, *(int *)(p + 0x24)) != 0) return 0;

    func_002CFCB0(p, 4);
    return 1;
}

__attribute__((section(".text.func_001DD0D8")))
void func_001DD0D8(char *p)
{
    int i;

    cIDBase_initialize(p + 0x10, 0x12, 0);
    cIDBase_restartAnim(p + 0x10);
    for (i = 0; i < 0x4D; i++) {
        CustomIDWork_Initialize(p + 0x60 + i * 0x7C, cIDBase_getIDWork(p + 0x10, i));
    }
    CustomIDWork_SetDisp(p + 0x60, 0);
    CustomIDWork_SetNumber_1DD218(p, 0);
    func_001DD238(p, 0);
}

__attribute__((section(".text.func_001F9B88")))
void func_001F9B88(char *p, int flag)
{
    SetFieldShorts0C0E_1F9C88(p);
    if (flag != 0) {
        func_001F9ED0(p);
        CopyGlobalPairToTarget_1F9C30(p);
        UpdateCounterClamped_1F9C58(p);
        func_001F9DD0(p);
        func_001F9E28(p);
        Obj0000_Set_Field_178_D_00747A0C_1F9E90(p);
    }
    func_001FACB0(p);
    if (*(short *)(Obj0000_Get_D_00747A94_2DB6B0() + 0x54A) > 0) {
        cCoreSave_setVital(p, *(short *)(Obj0000_Get_D_00747A94_2DB6B0() + 0x54A));
    } else {
        cCoreSave_setVital(p, 1);
    }
}
