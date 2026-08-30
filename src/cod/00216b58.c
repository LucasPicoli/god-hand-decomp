/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00569B70[];
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Adjust_theta(float f12);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern unsigned int Forward30F348_31CFE0(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_00262AA8(void *a0);
extern void SetOrientByType_26AF20(void *a0, int a1, unsigned int a2);
extern void func_002705D8(void *a0);
extern void func_0026B4E8(void *a0);

/* sn-2.95.3-136 matched TU. */


















__attribute__((section(".text.func_00216B58")))
void func_00216B58(void *a0)
{
    char *s1 = (char *)a0;
    int gb;
    int s2v, s0v;
    int t;

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        t = *(int *)(s1 + 0x564);
        if (t == 0x21E) goto a0_hit;
        if (t <= 0x21E) goto a0_def;
        if (t == 0x22F) goto a0_hit;
    a0_def:
        {
            char *v0 = *(char **)(s1 + 0x304);
            s2v = *(int *)(v0 + 0x1E68) + (int)v0;
            s0v = *(int *)(v0 + 0x1E6C) + (int)v0;
        }
        goto a0_end;
    a0_hit:
        {
            char *v1 = *(char **)(s1 + 0x304);
            s2v = *(int *)(v1 + 0x1518) + (int)v1;
            s0v = *(int *)(v1 + 0x151C) + (int)v1;
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                char *w = *(char **)(s1 + 0x304);
                s0v = *(int *)(w + 0x1520) + (int)w;
            }
        }
    a0_end:
        func_002A8578(s1, s2v, s0v, 0.0f, 3, gb, 0);
        *(int *)(s1 + 0x5F0) = 0xA;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.75f); break;
        case 2: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.8f); break;
        case 3: case 4: *(int *)(s1 + 0x5F0) = (int)((float)*(int *)(s1 + 0x5F0) * 0.9f); break;
        case 5: break;
        }
        *(int *)(s1 + 0x5F4) = 1;
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x104);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x10) != 0) {
            *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x80000000;
        }
        if (*(int *)(s1 + 0x5F0) != 0) {
            void *s0;
            char *v0;
            float th;

            *(int *)(s1 + 0x5F0) -= 1;
            s0 = *(void **)(s1 + 0xF0);
            v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            th = Turn_dest(s0, *(void **)(v0 + 0xF0), *(float *)(s1 + 0x600), *(float *)(s1 + 0x5A8) * 0.3926991f);
            *(float *)(s1 + 0x600) += th;
            *(float *)(s1 + 0x600) = Adjust_theta(*(float *)(s1 + 0x600));
            *(float *)(s1 + 0x104) += th;
            *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        }
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 2: {
        *(int *)(s1 + 0x17D0) = Forward30F348_31CFE0() % 5;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        t = *(int *)(s1 + 0x564);
        if (t == 0x21E) goto a2_hit;
        if (t <= 0x21E) goto a2_def;
        if (t == 0x22F) goto a2_hit;
    a2_def:
        {
            char *v0 = *(char **)(s1 + 0x304);
            s2v = *(int *)(v0 + 0x1560) + (int)v0;
            s0v = *(int *)(v0 + 0x1564) + (int)v0;
        }
        goto a2_end;
    a2_hit:
        {
            char *v0 = *(char **)(s1 + 0x304);
            s2v = *(int *)(v0 + 0x10A8) + (int)v0;
            s0v = *(int *)(v0 + 0x10AC) + (int)v0;
        }
    a2_end:
        func_002A8578(s1, s2v, s0v, 0.0f, 3, gb, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3: {
        char *p;

        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        p = *(char **)(s1 + 0x700);
        if (p != 0 && capVu0MagnitudeSqXZ(*(void **)(p + 0xF0), *(void **)(s1 + 0xF0)) < 2.25f) {
            *(unsigned char *)(s1 + 0x2F6) += 1;
        } else {
            func_00262AA8(s1);
        }
        break;
    }
    case 4: {
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        t = *(int *)(s1 + 0x564);
        if (t == 0x21E) goto a4_hit;
        if (t <= 0x21E) goto a4_def;
        if (t == 0x22F) goto a4_hit;
    a4_def:
        {
            char *v0;
            *(float *)(s1 + 0x54C) = 10.0f;
            v0 = *(char **)(s1 + 0x304);
            s2v = *(int *)(v0 + 0x15A4) + (int)v0;
            s0v = *(int *)(v0 + 0x15A8) + (int)v0;
            SetOrientByType_26AF20(s1, *(int *)(s1 + 0x700), 1);
        }
        goto a4_end;
    a4_hit:
        {
            char *v0 = *(char **)(s1 + 0x304);
            s2v = *(int *)(v0 + 0x1524) + (int)v0;
            s0v = *(int *)(v0 + 0x1528) + (int)v0;
            SetOrientByType_26AF20(s1, *(int *)(s1 + 0x700), 3);
        }
    a4_end:
        *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x80000000;
        func_002A8578(s1, s2v, s0v, 0.0f, 3, gb, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5: {
        t = *(int *)(s1 + 0x564);
        if (t == 0x21E) goto a5_ck;
        if (t <= 0x21E) goto a5_set;
        if (t != 0x22F) goto a5_set;
    a5_ck:
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x10) == 0) goto a5_done;
    a5_set:
        *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x80000000;
    a5_done:
        if (moveMotion(s1) != 0) {
            t = *(int *)(s1 + 0x564);
            if (t == 0x21E) goto a6_hit;
            if (t <= 0x21E) goto a6_def;
            if (t == 0x22F) goto a6_hit;
        a6_def:
            SetOrientByType_26AF20(s1, *(int *)(s1 + 0x700), 0);
            goto a6_end;
        a6_hit:
            SetOrientByType_26AF20(s1, *(int *)(s1 + 0x700), 2);
        a6_end:
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0) {
        if (*(int *)(s1 + 0x5F4) != 0) {
            *(int *)(s1 + 0x5F4) = 0;
            func_0026B4E8(s1);
        }
    }
}
