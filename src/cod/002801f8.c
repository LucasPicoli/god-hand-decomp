/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void CopyVec3From110To120_14A2B0(void *a0);
extern void Forward30A2B0_2DA9B8(void *a0);
extern void func_0028FB08(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int D_00462FC0;
extern char D_005FEE00[];
extern unsigned int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Field_424_1595F0(void *a0);

__attribute__((section(".text.func_00288178")))
void func_00288178(void *a0)
{
    char *s0 = (char *)a0;
    int v0;
    float z;

    *(int *)(s0 + 0x15B0) = *(int *)(s0 + 0x15B0) | 0x10020;
    *(float *)(s0 + 0x54C) = 3.0f;
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x180) + v0, *(int *)(v0 + 0x184) + v0, 3, 0.0f, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        moveMotion(s0);
        CopyVec3From110To120_14A2B0(s0);
        Forward30A2B0_2DA9B8(s0);
        if ((*(int *)(s0 + 0x15B0) & 8) != 0) {
            *(short *)(s0 + 0x54A) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        break;
    case 2:
        z = 0.0f;
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x188) + v0, *(int *)(v0 + 0x18C) + v0, 3, z, 0, 0);
        func_0028FB08(s0);
        cCoreSave_addKillNpcNum(&D_00569B70);
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x90) + v0, *(int *)(v0 + 0x94) + v0, 5, z, 0, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5F, s0, 0, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F4) = 2;
            *(unsigned char *)(s0 + 0x2F5) = 2;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        CopyVec3From110To120_14A2B0(s0);
        Forward30A2B0_2DA9B8(s0);
        break;
    }
}

__attribute__((section(".text.func_002801F8")))
void func_002801F8(void *a0)
{
    char *s0 = (char *)a0;
    int s2 = *(int *)(s0 + 0x1580);
    int v0;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        if (func_0026F1D8(s2) != 0) {
            switch (Forward30F348_31CFE0() & 1) {
            default:
            case 0:
                v0 = *(int *)(s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0x118) + v0, *(int *)(v0 + 0x11C) + v0, 2, 0.0f, 0, 0);
                break;
            case 1:
                v0 = *(int *)(s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0x118) + v0, *(int *)(v0 + 0x11C) + v0, 2, 0.0f, 0, 0);
                break;
            }
        } else {
            switch (Forward30F348_31CFE0() % 3) {
            default:
            case 0:
                v0 = *(int *)(s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0xE8) + v0, *(int *)(v0 + 0xEC) + v0, 2, 0.0f, 0, 0);
                break;
            case 1:
                v0 = *(int *)(s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0xE8) + v0, *(int *)(v0 + 0xF4) + v0, 2, 0.0f, 0, 0);
                break;
            case 2:
                v0 = *(int *)(s0 + 0x304);
                func_002A8578(s0, *(int *)(v0 + 0xE8) + v0, *(int *)(v0 + 0xFC) + v0, 2, 0.0f, 0, 0);
                break;
            }
        }
        cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)Obj0000_Get_Field_424_1595F0(s0), s0, 0, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            if (func_0026F1D8(s2) != 0) {
                *(unsigned char *)(s0 + 0x2F5) = 0x10;
                *(unsigned char *)(s0 + 0x2F6) = 2;
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
            } else {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
            }
        }
        break;
    }
}
