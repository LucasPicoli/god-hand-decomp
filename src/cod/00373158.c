/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern void *memcpy(void *, const void *, unsigned int);
extern void func_003745C0(void *, int, float, int);
extern void func_00373FF0(void *, int, float);
extern char D_00754210[];

__attribute__((section(".text.SetSequenceEntry_373158")))
int SetSequenceEntry_373158(void *a0, int a1) {
    char *s0 = (char*)a0;
    char *p0;
    char *p1;
    char *p2;
    int s1;
    int ret;
    int b;
    int reset;

    p0 = *(char**)(s0+0x6C) + (a1 << 5);
    *(int*)(s0+0x70) = (int)p0;
    *(int*)(s0+0x58) = *(unsigned char*)(p0+0xA);
    b = *(unsigned char*)(p0+0xB);
    *(int*)(s0+0x78) = a1;
    *(int*)(s0+0x54) = b & 3;
    memcpy(s0+0x5C, p0+0x11, 15);

    p1 = *(char**)(s0+0x70);
    if (*(unsigned char*)(p1+0x10) == 0) {
        s1 = 0;
    } else {
        s1 = *(int*)(s0+0x7C);
    }
    ret = func_00373B20(s0);
    if (ret == 1) {
        s1 = func_00374360(s0, *(int*)(s0+0x74), *(int*)(s0+0x70));
    } else {
        p2 = *(char**)(s0+0x70);
        if ((unsigned int)((*(unsigned char*)(p2+0xB) >> 2) & 3) < 2 && (*(int*)(s0+0x4C) & 0x10)) {
            reset = 1;
        } else {
            reset = 0;
            *(int*)(s0+0x4C) = *(int*)(s0+0x4C) & 0xFFFFFFEF;
        }
        s1 = func_00373D90(s0, *(int*)(s0+0x74), *(int*)(s0+0x70), s1, reset);
    }
    *(int*)(s0+0x4C) = *(int*)(s0+0x4C) | 0x2;
    if (s1 == 0) {
        ResetNodeData_3733C8(s0);
    }
    return s1;
}

__attribute__((section(".text.UpdateSequenceEntry_373298")))
int UpdateSequenceEntry_373298(void *a0, int a1) {
    char *s0 = (char*)a0;
    char *p0;
    char *p1;
    char *p2;
    int s1;
    int ret;
    int b;
    int reset;
    int t;

    p0 = *(char**)(s0+0x6C) + (a1 << 5);
    *(int*)(s0+0x70) = (int)p0;
    *(int*)(s0+0x58) = *(unsigned char*)(p0+0xA);
    b = *(unsigned char*)(p0+0xB);
    *(int*)(s0+0x78) = a1;
    *(int*)(s0+0x54) = b & 3;
    memcpy(s0+0x5C, p0+0x11, 15);

    p1 = *(char**)(s0+0x70);
    if (*(unsigned char*)(p1+0x10) == 0) {
        s1 = 0;
    } else {
        s1 = *(int*)(s0+0x7C);
    }
    ret = func_00373B20(s0);
    if (ret == 1) {
        s1 = func_00374508(s0, *(int*)(s0+0x74), *(int*)(s0+0x70));
    } else {
        p2 = *(char**)(s0+0x70);
        t = *(int*)(s0+0x4C);
        if ((unsigned int)((*(unsigned char*)(p2+0xB) >> 2) & 3) < 2 && (t & 0x10)) {
            reset = 1;
        } else {
            reset = 0;
            *(int*)(s0+0x4C) = t & 0xFFFFFFEF;
        }
        s1 = func_00373F38(s0, *(int*)(s0+0x74), *(int*)(s0+0x70), s1, reset);
    }
    if (s1 == 0) {
        ResetNodeData_3733C8(s0);
    }
    return s1;
}

__attribute__((section(".text.UpdateSequenceNode_373430")))
void UpdateSequenceNode_373430(void *a0) {
    if (func_00373A50(a0) != 0) {
        if (func_00373B20(a0) == 1) {
            func_00374548(a0);
        } else {
            func_00373F78(a0);
        }
    }
}

__attribute__((section(".text.UpdateSequenceNodeSetFlag_373488")))
void UpdateSequenceNodeSetFlag_373488(void *a0) {
    if (func_00373A50(a0) != 0) {
        if (func_00373B20(a0) == 1) {
            func_00374570(a0);
        } else {
            func_00373FA0(a0);
        }
        *(int*)((char*)a0+0x4C) = *(int*)((char*)a0+0x4C) | 0x2;
    }
}

__attribute__((section(".text.UpdateSequenceNodeWeighted_373560")))
void UpdateSequenceNodeWeighted_373560(void *a0, int a1, float f) {
    if (func_00373A50(a0) != 0) {
        if (func_00373B20(a0) == 1) {
            func_003745C0(a0, *(int*)((char*)a0+0x54), f, a1);
        } else {
            func_00373FF0(a0, *(int*)((char*)a0+0x54), f);
        }
    }
}

__attribute__((section(".text.ForwardSequenceItems_373690")))
void ForwardSequenceItems_373690(void *a0, int a1, int a2) {
    if (func_00373A50(a0)) {
        if (*(int*)((char*)a0+0x58) >= 2) {
            ForwardCollectionItems_374820(a0, a2, a1);
        } else {
            func_00374120(a0, a2, a1);
        }
    }
}

__attribute__((section(".text.UpdateSequenceState_373708")))
void UpdateSequenceState_373708(void *a0, int a1, int a2) {
    if (func_00373A50(a0)) {
        if (func_00373B20(a0) != 1) {
            func_00374148(a0, a1, a2);
        }
    }
}

__attribute__((section(".text.GetSequenceResult_373770")))
int GetSequenceResult_373770(void *a0) {
    if (!func_00373A50(a0)) {
        return 0;
    }
    if (func_00373B20(a0) != 1) {
        return func_00374170(a0);
    }
    return func_003748A8(a0);
}

__attribute__((section(".text.IsSequenceFlagSet_3737C8")))
int IsSequenceFlagSet_3737C8(void *a0, int a1) {
    if (!func_00373A50(a0)) {
        return 0;
    }
    return (*(int*)((char*)a0+0x4C) & a1) != 0;
}

__attribute__((section(".text.SetSequenceFlags_373810")))
void SetSequenceFlags_373810(void *a0, int a1) {
    if (func_00373A50(a0)) {
        *(int*)((char*)a0+0x4C) = *(int*)((char*)a0+0x4C) | a1;
    }
}

__attribute__((section(".text.GetSequenceBlendWeight_373938")))
float GetSequenceBlendWeight_373938(void *a0, int a1) {
    float r;
    if (!func_00373A50(a0)) {
        r = 0.0f;
    } else if (func_00373B20(a0) == 1) {
        r = *(float *)((a1 << 2) + (char *)a0 + 0x2C);
    } else {
        r = *(float *)((char *)a0 + 0x20);
    }
    return r;
}

__attribute__((section(".text.SetSequenceBlendWeight_3739A0")))
void SetSequenceBlendWeight_3739A0(void *a0, int a1, float f) {
    if (!func_00373A50(a0)) {
        return;
    }
    if (func_00373B20(a0) == 1) {
        *(float *)((char *)a0 + 0x40) = f;
        if (a1 == 1) {
            *(float *)((char *)a0 + 0x3C) = f;
        }
    } else {
        *(float *)((char *)a0 + 0x30) = f;
        if (a1 == 1) {
            *(float *)((char *)a0 + 0x2C) = f;
        }
    }
}

__attribute__((section(".text.SetSequenceParam_373A18")))
void SetSequenceParam_373A18(void *a0, int a1) {
    if (func_00373A50(a0)) {
        *(int *)((char *)a0 + 0x50) = a1;
    }
}

__attribute__((section(".text.GetSequenceHandle_373B68")))
int GetSequenceHandle_373B68(void *a0) {
    int t;
    if (!func_00373A50(a0)) {
        return 0;
    }
    t = func_00373B20(a0);
    if (t == 1) {
        return *(int *)((char *)a0 + 0x10);
    }
    return *(int *)((char *)a0 + 0x10);
}

__attribute__((section(".text.FreeSequenceNode_373D48")))
void FreeSequenceNode_373D48(int *a0) {
    int *s0 = a0;
    if (s0[0] != 0) {
        ADXT_Destroy(s0[0]);
        func_0031C928(s0[1], D_00754210);
    }
}

__attribute__((section(".text.ClearSequenceNode_374318")))
void ClearSequenceNode_374318(int *a0) {
    int *s0 = a0;
    if (s0[0] != 0) {
        func_0032D6F0(s0[0]);
        func_0031C928(s0[1], D_00754210);
    }
}
