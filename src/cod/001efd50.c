/* sn-2.95.3-136 matched TU. */

extern int D_0044E808;
extern void func_002D9F68(void *, int, ...);

__attribute__((section(".text.CustomIDWork_SetLocalPosXY")))
void CustomIDWork_SetLocalPosXY(char *p, int x, int y) {
    if (*(int *)(p + 0x4) != 0) {
        *(int *)(p + 0x8) = 0;
        *(float *)(*(int *)(p + 0x4) + 0x38) = (float)x;
        *(float *)(*(int *)(p + 0x4) + 0x3C) = (float)y;
    }
}

__attribute__((section(".text.CustomIDWork_SetMoveOffsetPosX")))
void CustomIDWork_SetMoveOffsetPosX(int a0,int a1,int a2,unsigned short a3){if(*(int*)(a0+4)==0)return;*(int*)(a0+0x28)=3;*(short*)(a0+0x44)=a3;*(float*)(a0+0x2C)=(float)a1;*(float*)(a0+0x34)=(float)a2;*(short*)(a0+0x46)=0;}

__attribute__((section(".text.CustomIDWork_SetMoveOffsetPosXSin")))
void CustomIDWork_SetMoveOffsetPosXSin(char *a0, int a1, unsigned short a2) {
    if (*(int *)(a0 + 0x4) != 0) {
        *(int *)(a0 + 0x28) = 5;
        *(short *)(a0 + 0x44) = a2;
        *(float *)(a0 + 0x3C) = (float)a1;
        *(short *)(a0 + 0x46) = 0;
    }
}

__attribute__((section(".text.CustomIDWork_SetMoveOffsetPosY")))
void CustomIDWork_SetMoveOffsetPosY(int a0,int a1,int a2,unsigned short a3){if(*(int*)(a0+4)==0)return;*(int*)(a0+0x28)=9;*(short*)(a0+0x44)=a3;*(float*)(a0+0x30)=(float)a1;*(float*)(a0+0x38)=(float)a2;*(short*)(a0+0x46)=0;}

__attribute__((section(".text.CustomIDWork_SetOffsetPosXY")))
void CustomIDWork_SetOffsetPosXY(char *p, int x, int y) {
    if (*(int *)(p + 0x4) != 0) {
        *(int *)(p + 0x28) = 0;
        *(float *)(*(int *)(p + 0x4) + 0x30) = (float)x;
        *(float *)(*(int *)(p + 0x4) + 0x34) = (float)y;
    }
}

/* sn-2.95.3-136 | fp_hazard_rules mtc1 */
__attribute__((section(".text.SetField_B98_1EFD50")))
void SetField_B98_1EFD50(char *p)
{
    *(float *)(p + 0xB98) = (float)(*(int *)(p + 0xB6C) * 30);
}

__attribute__((section(".text.func_002D6838")))
void func_002D6838(char *a0, int a1, unsigned short a2) {
    if (*(int *)(a0 + 0x4) != 0) {
        *(int *)(a0 + 0x28) = 0x11;
        *(short *)(a0 + 0x44) = a2;
        *(float *)(a0 + 0x40) = (float)a1;
        *(short *)(a0 + 0x46) = 0;
    }
}

/* NOTE: needs "fp_hazard_rules": "mtc1" on its compile_units entry. */
/* sn-2.95.3-136 */




__attribute__((section(".text.func_002EA908")))
int func_002EA908(char *p)
{
    char *q;
    int m;
    unsigned int t;

    *(int *)(p + 0x2B8) = 0;
    *(int *)(p + 0x2BC) = 0;
    q = *(char **)(p + 0x110);
    *(float *)(p + 0x2C0) = *(float *)(q + 0x13C) * 0.1f;
    *(float *)(p + 0x2C4) = *(float *)(q + 0x140) * 0.1f;
    m = *(signed char *)(q + 0x18C) + 2;
    *(int *)(p + 0x2C8) = m;
    *(float *)(p + 0x2B0) = *(signed char *)(q + 0x18D) * 0.1f + 1.0f;
    *(float *)(p + 0x2B4) = *(signed char *)(q + 0x18E) * 0.1f + 1.0f;
    t = *(unsigned char *)(q + 0x18F);
    *(int *)(p + 0x2CC) = t;
    if (t >= 4) {
        func_002D9F68(p, (int)&D_0044E808, t);
        *(int *)(p + 0x2CC) = 0;
        return 0;
    }
    if (t != 0 && m == 2) {
        *(int *)(p + 0x2C8) = 3;
    }
    return 1;
}
