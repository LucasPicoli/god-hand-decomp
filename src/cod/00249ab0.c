/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005850B0[];
extern unsigned char D_005CB010;
extern char *Getplayer(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float f, int t0, int t1);
extern void func_00281260(void *a0);
extern void ClearBytes2F4To2F7_283170(void *a0);
extern void func_002495E0(void *a0, float f12);
extern void func_00249770(void *a0, float f12);
extern float fRand0_1(void);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

__attribute__((section(".text.func_00249AB0")))
void func_00249AB0(void *a0)
{
    char *s0 = (char *)a0;

    capVu0MagnitudeSqXZ(*(void **)(Getplayer() + 0xF0), &D_005850B0);
    *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x30400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int gb;
        int b;
        void *q;

        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x3D34) + b, *(int *)(b + 0x3D38) + b, 0xA, 0.0f, gb, 0);
        *(float *)(s0 + 0x600) = 30.0f;
        q = *(void **)(s0 + 0x748);
        if (q != 0) {
            func_00281260(q);
        }
        q = *(void **)(s0 + 0x74C);
        if (q != 0) {
            ClearBytes2F4To2F7_283170(q);
        }
        q = *(void **)(s0 + 0x750);
        if (q != 0) {
            ClearBytes2F4To2F7_283170(q);
        }
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) & 0xFCFFFFFFU;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 1: {
        float d;

        func_002495E0(s0, 0.0f);
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (D_005CB010 != 0) {
            *(char *)(s0 + 0x2F5) = 0x6B;
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
            break;
        }
        d = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
        *(float *)(s0 + 0x600) = d;
        if (d <= 0.0f) {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    }
    case 2: {
        int gb;
        int b;
        void *q;
        float rv;
        float z = 0.0f;

        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x3D34) + b, *(int *)(b + 0x3D38) + b, 0xA, z, gb, 0);
        *(float *)(s0 + 0x600) = 60.0f;
        q = *(void **)(s0 + 0x748);
        if (q != 0) {
            func_00281260(q);
        }
        q = *(void **)(s0 + 0x74C);
        if (q != 0) {
            ClearBytes2F4To2F7_283170(q);
        }
        q = *(void **)(s0 + 0x750);
        if (q != 0) {
            ClearBytes2F4To2F7_283170(q);
        }
        *(char *)(s0 + 0x1864) = 0;
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) & 0xFCFFFFFFU;
        Obj0000_Get_Byte_17C3_NZ_2_276468(s0);
        if (z < *(float *)(s0 + 0x75C)) {
            *(short *)(s0 + 0x568) = 0;
        } else {
            *(short *)(s0 + 0x568) = 1;
        }
        *(int *)(s0 + 0x604) = 0;
        rv = fRand0_1() * 60.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        *(float *)(s0 + 0x600) = rv + 60.0f;
    }
    case 3: {
        float d;

        if ((*(unsigned short *)(s0 + 0x568) & 1) != 0) {
            float v = *(float *)(s0 + 0x604) + *(float *)(s0 + 0x5A8) * 0.0008726646f;

            *(float *)(s0 + 0x604) = v;
            if (0.017453292f < v) {
                *(float *)(s0 + 0x604) = 0.017453292f;
            }
        } else {
            float v = *(float *)(s0 + 0x604) - *(float *)(s0 + 0x5A8) * 0.0008726646f;

            *(float *)(s0 + 0x604) = v;
            if (v < -0.017453292f) {
                *(float *)(s0 + 0x604) = -0.017453292f;
            }
        }
        func_00249770(s0, *(float *)(s0 + 0x604) * *(float *)(s0 + 0x5A8));
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (D_005CB010 != 0) {
            *(char *)(s0 + 0x2F6) = 4;
        }
        d = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
        *(float *)(s0 + 0x600) = d;
        if (d <= 0.0f) {
            *(char *)(s0 + 0x2F6) = 4;
        }
        break;
    }
    case 4:
        *(char *)(s0 + 0x1864) = 0;
        Obj0000_Get_Byte_17C3_NZ_2_276468(s0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 5: {
        if ((*(unsigned short *)(s0 + 0x568) & 1) != 0) {
            float v = *(float *)(s0 + 0x604) - *(float *)(s0 + 0x5A8) * 0.0008726646f;

            *(float *)(s0 + 0x604) = v;
            if (v < 0.0f) {
                *(float *)(s0 + 0x604) = 0.0f;
                *(unsigned char *)(s0 + 0x2F5) = 0xA1;
                *(char *)(s0 + 0x2F4) = 0;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F7) = 0;
            }
        } else {
            float v = *(float *)(s0 + 0x604) + *(float *)(s0 + 0x5A8) * 0.0008726646f;

            *(float *)(s0 + 0x604) = v;
            if (0.0f < v) {
                *(float *)(s0 + 0x604) = 0.0f;
                *(unsigned char *)(s0 + 0x2F5) = 0xA1;
                *(char *)(s0 + 0x2F4) = 0;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F7) = 0;
            }
        }
        func_00249770(s0, *(float *)(s0 + 0x604) * *(float *)(s0 + 0x5A8));
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    }
    }
}
