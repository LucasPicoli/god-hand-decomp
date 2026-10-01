#include "godhand/vu0.h"
#include "godhand/cSnd.h"
extern void Tramp_func_0030A2E0_00147548(void *, int, void *);
extern unsigned char D_00747A50[];
extern unsigned char D_00586AB0;
extern int D_00747A24;
extern int D_0044F4F8;
extern int D_0044F6D8;

__attribute__((section(".text.UpdateObjWithVtableDispatch_2BB1F0")))
void UpdateObjWithVtableDispatch_2BB1F0(void *a0)
{
    unsigned char *s0 = (unsigned char *)a0;
    long v1 = s0[0x4];
    long a0v = v1 & 1;
    int *v0;
    if (a0v == 1 && ((v1 >> 1) & 1) == a0v) {
        Tramp_func_0030A2E0_00147548(s0 + 0x80, *(int *)(s0 + 0x8), s0 + 0x10);
    }
    v0 = *(int **)(s0 + 0x100);
    (*(void (**)(void *))((char *)v0 + 0x4C))(s0 + *(short *)((char *)v0 + 0x48));
}

__attribute__((section(".text.ForwardCheckedRequest_2BED60")))
int ForwardCheckedRequest_2BED60(void *a0, int a1, int a2)
{
    int *s1 = (int *)a0;
    int s2 = a2;
    int s0;
    int v0;
    a1 = a1 & 0xFFFF;
    if (D_00747A50[1] != ((unsigned int)a1 >> 8)) {
        return 0;
    }
    s0 = s1[0];
    func_002BEBC8(s1, a1);
    v0 = func_002BED08(s1, s2);
    s1[0] = s0;
    return v0;
}

__attribute__((section(".text.ClearInputState_2C33D8")))
void ClearInputState_2C33D8(void *a0)
{
    unsigned char *s0 = (unsigned char *)a0;
    int (*v0)();
    unsigned long v1;
    unsigned long b6;
    D_00586AB0 = 0;
    v0 = *(int (**)())((char *)*(void **)(s0 + 0xD4) + 0x4);
    if (v0 != 0) {
        v0();
    }
    v1 = D_00747A24;
    b6 = (v1 >> 6) & 1;
    if (b6) {
        s0[0x14] = 0;
    } else if (v1 & 0x200) {
        s0[0x14] = 0;
    }
}

/* Cuts the extension off a file name, then loads it into the slot's entry. */
__attribute__((section(".text.cSnd_SeLoadFile")))
int cSnd_SeLoadFile(cSnd *self, int slot, char *name)
{
    char *dot = func_003A54D8(name, 0x2E);
    if (dot != 0) {
        *dot = 0;
    }
    return cSeData_LoadFile(cSnd_GetSeEntry(self, slot), slot, name);
}






__attribute__((section(".text.Setup_Field_2B0_2F61C8")))
void *Setup_Field_2B0_2F61C8(void *obj) {
    InitObject_2FBCC8(obj);
    *(int *)((char *)obj + 0x2B0) = 0;
    *(float *)((char *)obj + 0x2D4) = 1.0f;
    *(int **)((char *)obj + 0xF0) = &D_0044F4F8;
    *(int *)((char *)obj + 0x2B4) = 0;
    *(int *)((char *)obj + 0x2B8) = 0;
    *(int *)((char *)obj + 0x2BC) = 0;
    *(int *)((char *)obj + 0x2C0) = 0;
    *(int *)((char *)obj + 0x2C4) = 0;
    *(int *)((char *)obj + 0x2C8) = 0;
    *(int *)((char *)obj + 0x2D8) = 0;
    *(int *)((char *)obj + 0x2DC) = 0;
    VU0_SQC2_VF0(obj, 0x2F0);
    return obj;
}






__attribute__((section(".text.InitObjectFields_2F7110")))
void *InitObjectFields_2F7110(void *obj) {
    InitObject_2FBCC8(obj);
    *(int *)((char *)obj + 0x2B0) = 0;
    *(float *)((char *)obj + 0x2D4) = 1.0f;
    *(int **)((char *)obj + 0xF0) = &D_0044F6D8;
    *(int *)((char *)obj + 0x2B4) = 0;
    *(int *)((char *)obj + 0x2B8) = 0;
    *(int *)((char *)obj + 0x2BC) = 0;
    *(int *)((char *)obj + 0x2C0) = 0;
    *(int *)((char *)obj + 0x2C4) = 0;
    *(int *)((char *)obj + 0x2C8) = 0;
    *(int *)((char *)obj + 0x2D8) = 0;
    *(int *)((char *)obj + 0x2DC) = 0;
    VU0_SQC2_VF0(obj, 0x2F0);
    return obj;
}
