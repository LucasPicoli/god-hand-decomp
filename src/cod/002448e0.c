/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00462FC0[];
extern unsigned char D_005FEE00[];
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern float fRand0_1(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, void *a1, float a2);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);

/* sn-2.95.3-136 matched TU. */

















__attribute__((section(".text.func_002448E0")))
void func_002448E0(void *a0)
{
    char *s0 = (char *)a0;

    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int gb;
        char *v1;

        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0xD70) + (int)v1, *(int *)(v1 + 0xD74) + (int)v1, 0.0f, 3, gb, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        *(float *)(s0 + 0x54C) = 2.0f;
        *(unsigned short *)(s0 + 0x434) = *(unsigned short *)(s0 + 0x434) | 8;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2:
        *(float *)(s0 + 0x600) = fRand0_1() * 45.0f + 90.0f;
        *(int *)(s0 + 0x4A8) = *(int *)(s0 + 0x4A8) | 0x80000000;
        *(float *)(s0 + 0x608) = 3.0f;
        *(unsigned char *)(s0 + 0x2F6) += 1;
        *(int *)(s0 + 0x604) = 0;
        /* fallthrough */
    case 3:
        *(char *)(s0 + 0x617) = 1;
        *(char *)(s0 + 0x623) = 1;
        *(float *)(s0 + 0x54C) = 2.0f;
        *(char *)(s0 + 0x531) = -1;
        AddScaledDeltaToField_104_2A7498(s0, s0 + 0x16A0, *(float *)(s0 + 0x5A8) * 0.09817477f);
        *(unsigned short *)(s0 + 0x434) = *(unsigned short *)(s0 + 0x434) | 8;
        moveMotion(s0);
        if (*(float *)(s0 + 0x618) > 1.0f) {
            *(int *)(s0 + 0x330) = 0;
            *(int *)(s0 + 0x334) = 0;
            *(float *)(s0 + 0x338) = *(float *)(s0 + 0x5A8) * 0.1f;
        } else {
            *(int *)(s0 + 0x330) = 0;
            *(int *)(s0 + 0x334) = 0;
            *(int *)(s0 + 0x338) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        *(float *)(s0 + 0x600) = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
        if (*(float *)(s0 + 0x600) <= 0.0f) {
            *(unsigned char *)(s0 + 0x2F6) = 4;
            break;
        }
        *(float *)(s0 + 0x604) = *(float *)(s0 + 0x604) - *(float *)(s0 + 0x5A8);
        if (*(float *)(s0 + 0x604) <= 0.0f) {
            SetEffectPos(0x58, 0x9C, 0, *(void **)(s0 + 0xF0), -1, 1.0f);
            *(float *)(s0 + 0x604) = 6.0f;
        }
        if (*(int *)(s0 + 0x474) != 1 && *(int *)(s0 + 0x474) != 9) {
            *(unsigned char *)(s0 + 0x2F6) = 4;
        }
        *(float *)(s0 + 0x608) = *(float *)(s0 + 0x608) - *(float *)(s0 + 0x5A8);
        if (*(float *)(s0 + 0x608) <= 0.0f) {
            *(float *)(s0 + 0x608) = 15.0f;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xFB, s0, 0, 0, 0, 0);
        }
        break;
    case 4: {
        int gb;
        int s2v, s1v;

        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        if ((*(int *)(s0 + 0x564) ^ 0x20F) != 0) {
            char *w = *(char **)(s0 + 0x304);
            s2v = *(int *)(w + 0xDA8) + (int)w;
            s1v = *(int *)(w + 0xDAC) + (int)w;
            StoreMotionParamsBoth_2609A8(s0, 0x14, 0x23, 0x37, -1, 0);
        } else {
            char *w = *(char **)(s0 + 0x304);
            s2v = *(int *)(w + 0xD78) + (int)w;
            s1v = *(int *)(w + 0xD7C) + (int)w;
        }
        func_002A8578(s0, s2v, s1v, 0.0f, 3, gb, 0);
        *(float *)(s0 + 0x1744) = 300.0f;
        *(char *)(s0 + 0x531) = 3;
        *(int *)(s0 + 0x4A8) = *(int *)(s0 + 0x4A8) & 0x7FFFFFFF;
        *(float *)(s0 + 0x54C) = 5.0f;
        *(unsigned char *)(s0 + 0x2F6) += 1;
        *(char *)(s0 + 0x623) = 0;
    }
        /* fallthrough */
    case 5:
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        func_00260B30(s0);
        break;
    }
}
