/* sn-2.95.3-136 matched TU. */

extern int D_0041EBE8;
extern char D_0044AE28[];
extern void (*D_003C4908)(void);
extern void func_00329EA8(int a0);
extern void func_0032B300(int a0, int a1);
extern void func_003298C0(int a0);
extern void func_0031C900(int a0);
extern void func_003A6290(void);
extern void Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54(int a0, int a1, int a2, int a3);
extern int D_003FA62C;
extern void __malloc_lock(int a0);
extern void __malloc_unlock(int a0);
extern int D_003C2388;
extern int D_00583F20[];
extern int D_00754230[];
extern void cIDManager_getLocalFileName(int a0, void *a1, int a2, int a3);
extern int cDvd_ReadAlloc(void *a0, void *a1, void *a2, void *a3, int t0, int t1, int t2, int t3);
extern int cDvd_CheckWait(void *a0, int a1);
extern void func_0015EAC8(int a0);
extern void func_002D5890(int a0, int a1);
extern void func_002D5440(int a0, int a1);

__attribute__((section(".text.func_0014EA28")))
int func_0014EA28(int a0) {
    *(int*)((char*)a0+0x214) = (int)&D_0041EBE8;
    return func_0014E5D0(a0);
}

__attribute__((section(".text.func_002A73C8")))
int func_002A73C8(int a0) {
    *(int*)((char*)a0+0x214) = (int)D_0044AE28;
    return func_0014EA28(a0);
}

__attribute__((section(".text.func_00201228")))
int func_00201228(int a0, int a1) {
    return func_003A52F0(a1, 0, 0x88);
}

__attribute__((section(".text.func_00320280")))
void func_00320280(void) {
    D_003C4908();
}

__attribute__((section(".text.func_00380EB0")))
void func_00380EB0(int a0, int a1, int a2)
{
    int t;
    func_00329EA8(*(int*)((char*)a1+0x30));
    if (*(unsigned char*)((char*)a2+0x0) != 0) {
        *(char*)((char*)a2+0x0) = 0;
        func_0032B300(*(int*)((char*)a1+0x30), 0);
    }
    func_003298C0(*(int*)((char*)a1+0x30));
    t = *(int*)((char*)a1+0x34);
    *(int*)((char*)a1+0x30) = 0;
    func_0031C900(t);
}

__attribute__((section(".text.func_003A61F0")))
void func_003A61F0(int a0)
{
    int s1 = a0 + 0x1E4;
    *(int*)((char*)a0+0x3C) = (int)&func_003A6290;
    *(int*)((char*)a0+0x38) = 1;
    Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54(s1, 4, 0, a0);
    Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54(a0 + 0x23C, 9, 1, a0);
    Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54(a0 + 0x294, 0xA, 2, a0);
    *(int*)((char*)a0+0x1E0) = s1;
    *(int*)((char*)a0+0x1DC) = 3;
    *(int*)((char*)a0+0x1D8) = 0;
}

__attribute__((section(".text.func_003A7C70")))
int func_003A7C70(int a0)
{
    int r;
    __malloc_lock(D_003FA62C);
    r = func_003AC2F8(D_003FA62C, a0);
    __malloc_unlock(D_003FA62C);
    return r;
}

__attribute__((section(".text.func_00161500")))
int func_00161500(int a0, int a1)
{
    int local[16];
    if (*(int*)((char*)a0+0x50) == 0) {
        int r;
        cIDManager_getLocalFileName(D_003C2388, &local, a1, -1);
        r = cDvd_ReadAlloc(D_00583F20, &local, (void*)((char*)a0+0x50), D_00754230, 0, 0, 0, 0);
        *(int*)((char*)a0+0x54) = r;
        cDvd_CheckWait(D_00583F20, r);
    }
    return *(int*)((char*)a0+0x50);
}

__attribute__((section(".text.cObjBase_KageInit")))
void cObjBase_KageInit(int a0, int a1, int a2)
{
    int s2 = 0;
    int s1 = 1;
    *(int*)((char*)a0+0x44C) = a2;
    *(int*)((char*)a0+0x450) = a1;
    do {
        s1 = s1 - 1;
        func_0015EAC8(*(int*)((char*)a0+0x450) + s2);
        s2 += 0x750;
    } while (s1 >= 0);
}

__attribute__((section(".text.cTaskManager_execute")))
int cTaskManager_execute(int a0, int a1, int a2)
{
    int *v1 = *(int**)((char*)a0+0x30);
    int (*fp)(int, int) = (int (*)(int, int))v1[5];
    int s0 = fp(a0 + *(short*)((char*)v1+0x10), a2);
    if (s0 != -1) {
        func_002D5890(*(int*)((char*)a0+0x0) + s0 * 0x58, a1);
    }
    func_002D5440(a0, s0);
    return s0;
}
