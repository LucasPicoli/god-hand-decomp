/* TU: cHeatSys [battle] - recovered C++ class. */
#include "include_asm.h"

extern int func_002A9B50(void *p);
extern int Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(void *p);
extern void *D_00569B70;
extern unsigned int D_00747A50;       /* lhu -> u16 */
extern void *D_003BD6E8;

__attribute__((section(".text.cHeatSys_AddHeatGage")))
void cHeatSys_AddHeatGage(void *a0, int a1, float heat)
{
    void *obj;
    float old4;
    float cur8;
    float min;
    unsigned short mode;

    old4 = *(float *)((char *)a0 + 0x4);

    if (a1 == 0 && *(unsigned char *)((char *)a0 + 0x10) != 0 && 0.0f < heat)
        return;

    obj = D_00569B70;
    if ((*(int *)((char *)obj + 0x14) & 0x04000000) == 0) {
        if (Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(&D_00569B70) == 0)
            heat = heat * 1.25f;
    }

    if (120.0f <= heat) {
        void *p = D_003BD6E8;
        *(int *)((char *)p + 0x4F0) = *(int *)((char *)p + 0x4F0) | 0x01000000;
    }

    mode = (unsigned short)D_00747A50;
    if (mode == 0x801) {
        heat = heat * 1.25f;
    }

    min = *(float *)((char *)a0 + 0x4) + heat;
    *(float *)((char *)a0 + 0x4) = min;
    if (*(float *)((char *)a0 + 0x0) < min)
        *(float *)((char *)a0 + 0x4) = *(float *)((char *)a0 + 0x0);

    if (0.0f < heat) {
        cur8 = *(float *)((char *)a0 + 0x8) +
               (*(float *)((char *)a0 + 0x4) - old4);
        *(float *)((char *)a0 + 0x8) = cur8;
        if (*(float *)((char *)a0 + 0x0) < cur8)
            *(float *)((char *)a0 + 0x8) = *(float *)((char *)a0 + 0x0);
    }

    func_002A9B50(a0);
}
