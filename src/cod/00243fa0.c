/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern void func_00129718(void *a0, void *a1, int a2);
extern char D_00462FC0;

/* sn-2.95.3-136 matched TU. */












__attribute__((section(".text.func_00243FA0")))
void func_00243FA0(char *s0)
{
    int b;
    char *o;
    float *p;
    float t;

    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
    *(int *)(s0 + 0x16D0) |= 0x10000;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x24B4) + b, *(int *)(b + 0x24B8) + b,
                      0.0f, 3, 0, 0);
        *(char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        o = Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s0, *(int *)(o + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.19634954f);
        if (moveMotion(s0) != 0)
            *(char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2:
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x24C4) + b, *(int *)(b + 0x24C8) + b,
                      0.0f, 3, 0, 0);
        *(float *)(s0 + 0x600) = 0.05f;
        *(float *)(s0 + 0x604) = 150.0f;
        *(char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        if (64.0f < *(float *)(s0 + 0x618)) {
            o = Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s0, *(int *)(o + 0xF0),
                                             *(float *)(s0 + 0x5A8) *
                                                 0.09817477f);
        }
        moveMotion(s0);
        *(float *)(s0 + 0x600) =
            *(float *)(s0 + 0x600) + *(float *)(s0 + 0x5A8) * 0.05f;
        if (0.3f < *(float *)(s0 + 0x600))
            *(float *)(s0 + 0x600) = 0.3f;
        *(float *)(s0 + 0x338) =
            *(float *)(s0 + 0x600) * *(float *)(s0 + 0x5A8);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (func_00270DB0(s0) != 0) {
            o = Obj0000_Get_D_00747A94_2DB6B0();
            func_00129718(o, s0, 0x12);
            *(char *)(s0 + 0x2F6) = 6;
        } else {
            t = *(float *)(s0 + 0x604) - *(float *)(s0 + 0x5A8);
            *(float *)(s0 + 0x604) = t;
            if (t <= 0.0f)
                *(char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    case 4:
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x24CC) + b, *(int *)(b + 0x24D0) + b,
                      0.0f, 3, 0, 0);
        *(char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 5:
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0x7F;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        *(float *)(s0 + 0x600) =
            *(float *)(s0 + 0x600) *
            (1.0f - *(float *)(s0 + 0x5A8) * 0.1f);
        *(float *)(s0 + 0x338) =
            *(float *)(s0 + 0x600) * *(float *)(s0 + 0x5A8);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 6:
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x24BC) + b, *(int *)(b + 0x24C0) + b,
                      0.0f, 3, 0, 0);
        *(char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 7:
        o = Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s0, *(int *)(o + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.19634954f);
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0x7F;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    p = *(float **)(s0 + 0xF0);
    p[1] = p[1] * 0.9f + *(float *)(s0 + 0x1738) * 0.1f;
}
