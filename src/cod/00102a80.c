/* sn-2.95.3-136 matched TU. */

extern int func_002DDAB0(void *a0, int a1, float f);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void Tramp_00312708_1B79B0(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern char D_00462FC0;
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_00270C78(void *a0);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float Adjust_theta(float f12);
extern void func_001034E0(void *a0);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern void func_00260438(void *a0);
extern void func_002705D8(void *a0);
extern unsigned short D_00747A50;
extern void func_00124540(void *a0, int a1);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f12);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_0012B618(void *a0);

__attribute__((section(".text.func_00277C48")))
void func_00277C48(void *a0)
{
    char *s0 = (char *)a0;
    void *e;
    float one;
    int v0;

    e = (void *)func_002DDAB0(*(void **)(s0 + 0xF0), 0, 15.0f);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x5C) + v0, *(int *)(v0 + 0x60) + v0, 0.0f, 3, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            if (e != 0) {
                Tramp_00312708_1B79B0(e);
            }
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00246F40")))
void func_00246F40(void *a0)
{
    char *s0 = (char *)a0;
    float one;
    int v0, t;

    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
    *(int *)(s0 + 0x16D0) |= 0x20000;
    *(int *)(s0 + 0x16D0) |= 0x10000;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0);
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0xC34) + v0, *(int *)(v0 + 0xC38) + v0, 80.0f, 10, t & 0xFFFF, 0);
        *(int *)(s0 + 0x5B4) = 0x1869F;
        func_0026F120(s0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        *(int *)(s0 + 0x16D0) |= 0x20000;
        if (moveMotion(s0) != 0) {
            func_00270C78(s0);
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00102A80")))
void func_00102A80(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    float one;
    float f;
    int v0;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x1C) + v0, *(int *)(v0 + 0x20) + v0, 0.0f, 10, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (*(unsigned char *)(s1 + 0x61F) != 0) {
            f = 3.1415927f - *(float *)(s1 + 0x608);
            f = f - 0.5235988f;
            if (f < 0.0f) {
                f = 0.0f;
            }
            f = f * 0.4f;
            if (0.0418879f < f) {
                f = 0.0418879f;
            }
            if (*(float *)(s1 + 0x604) < 0.0f) {
                f = -f;
            }
            *(float *)(s0 + 0x104) = *(float *)(s0 + 0x104) + f;
            *(float *)(s0 + 0x104) = Adjust_theta(*(float *)(s0 + 0x104));
        }
        one = 1.0f;
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
    func_001034E0(s0);
}

__attribute__((section(".text.func_00258C40")))
void func_00258C40(void *a0)
{
    char *s0 = (char *)a0;
    float one;
    int a, c;

    *(int *)(s0 + 0x16D0) |= 0x4000;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        switch (*(int *)(s0 + 0x564)) {
        default:
        {
            int b = *(int *)(s0 + 0x304);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247:
        {
            int b = *(int *)(s0 + 0x304);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        case 0x24F: case 0x250: case 0x251:
        {
            int b = *(int *)(s0 + 0x304);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        case 0x278: case 0x279:
        {
            int b = *(int *)(s0 + 0x304);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        }
        func_002A8578(s0, a, c, 0.0f, 10, Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6E;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00246088")))
void func_00246088(void *a0)
{
    char *p = (char *)a0;
    char *v;
    float one;
    int flag;
    int s0v, s1v;

    flag = 1;
    switch (*(unsigned char *)(p + 0x2F6)) {
    case 0:
        *(unsigned char *)(p + 0x1864) = 0;
        if (D_00747A50 == 0x303) {
            if ((*(int *)(p + 0x16D4) & 0x2000000) == 0) {
                *(int *)(p + 0x16D4) |= 0x2000000;
                *(float *)(p + 0x54C) = 10.0f;
                flag = 0;
            }
        }
        if (flag != 0) {
            func_00260438(p);
        }
        v = *(char **)(p + 0x304);
        s0v = *(int *)(v + 0xBCC) + (int)v;
        s1v = *(int *)(v + 0xBD4) + (int)v;
        func_002A8578(p, s0v, s1v, 0.0f, 10, Obj0000_Get_Byte_17C3_NZ_2_276468(p) & 0xFFFF, 0);
        *(short *)(p + 0x568) = 3;
        *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
    case 1:
        v = (char *)Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(p, *(int *)(v + 0xF0), *(float *)(p + 0x5A8) * 0.19634954f);
        if (moveMotion(p) != 0) {
            if (--*(short *)(p + 0x568) <= 0) {
                func_002705D8(p);
            }
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(p, one);
        AddScaledXfmVecToField_F0_14F928(p, one);
        break;
    }
}

__attribute__((section(".text.func_00110E98")))
void func_00110E98(void *a0)
{
    char *s0 = (char *)a0;
    char *v;
    float one;

    *(int *)(s0 + 0x15F4) |= 0x100000;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        func_00124540(s0, 4);
        if (*(int *)(s0 + 0x6A0) != 0) {
            v = *(char **)(s0 + 0x304);
            func_002A8578(*(void **)(s0 + 0x6A0), *(int *)(v + 0x37C) + (int)v, *(int *)(v + 0x398) + (int)v, 0.0f, 3, 0, 0);
        }
        v = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v + 0x364) + (int)v, *(int *)(v + 0x368) + (int)v, 0.0f, 3, 0, 0);
        *(int *)(s0 + 0x15B0) = 1;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (*(int *)(s0 + 0x640) != 0) {
            *(unsigned char *)(s0 + 0x648) = 0x14;
        }
        InvokeVirtualAtField214AndForward_124E68(s0, 0.19634954f);
        if (moveMotion(s0) != 0) {
            Obj0000_Clear_Fields_640_648_124E58(s0);
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 1) {
        func_0012B618(s0);
    }
    if (func_00123938(s0, 1) != 0) {
        Obj0000_Clear_Fields_640_648_124E58(s0);
    }
}
