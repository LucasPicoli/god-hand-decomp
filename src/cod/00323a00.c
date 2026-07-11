/* cygnus-2.96 matched TU. */

extern void sfadxt_WtPause(void *, void *, int);
extern int MPSLIB_CheckHn(void *);
extern int D_003E0710;
extern int D_003E0708;
extern int D_003EAEC8;
extern void func_00323AA0(int a0);
extern int D_003C7420;
extern void func_003298F0(int a0);
extern int D_003D1488;
extern void func_0032E720(int a0);
extern int D_003DA5F8;
extern void func_00336218(int a0);
extern void func_0035B5B8(void *, int *, int *);
extern void func_0035B500(void *, int, int);
extern void func_0035B568(void *, int, int);
extern int Obj0000_Set_D_003EE2BC_358A28(int a0);
extern int MWSFSVM_Error(char *msg);
extern char D_00457890[];
extern int MWSTM_IsFsStatErr(void *a0);
extern int Obj35C0_GetIndexed_1F30_C338(void *a, int b);
extern void Obj35C0_SetIndexed_1F30_C320(void *a, int b, int c);
extern int Obj35C0_GetIndexed_1F34_C368(void *a, int b);
extern void Obj35C0_SetIndexed_1F34_C350(void *a, int b, int c);
extern void *getElemInfPtr(void *a, int b);
extern int D_0045A580[];
extern int D_0045A590[];
extern int D_003EB708;
extern void Forward3B0640_33F3D0(int a0, int a1);
extern int sfmps_CopySj(int a0, int a1, int a2, int a3);
extern int GetArrayElemA0C_35A1C8(int a0, int a1);
extern void func_003B1F28(int a0, int a1);
extern int D_00454110;
extern char D_00454170[];
extern void func_00331D40(int a0, int a1, int a2);
extern void func_00331D78(void);
extern int D_003D90E0;
extern char D_003D9150[];
extern void func_00332890(char *a0);
extern int D_003D9F74;
extern char D_003D9FE0[];
extern void func_003340F0(char *a0);
extern char D_00455788[];
extern void func_00326050(char *a0);
extern int D_003E8DD4;
extern int D_003E9068;
extern int D_003E8DDC;
extern void DTX_Destroy(int a0);
extern void Tramp_sceSifFreeSysMemory_3B5A50(int a0);
extern void func_003325F8(void);

__attribute__((section(".text.func_0034B430")))
void func_0034B430(void *a0, int a1) {
    void *v1;
    int v0;
    void *a0new;
    void *a0call;

    v0 = a1;
    v1 = *(void **)((char *)a0 + 0x2004);
    a0new = (char *)a0 + 0x1020;
    a0call = *(void **)v1;
    if (v0 == 0) {
        v1 = *(void **)((char *)v1 + 0x2C);
        if ((int)(long)v1 == 1) {
            return;
        }
    }
    sfadxt_WtPause(a0call, a0new, v0);
}

__attribute__((section(".text.func_00366D28")))
void func_00366D28(int *a0, int a1, int a2) {
    if (!MPSLIB_CheckHn(a0)) {
        *(int *)((char *)a0 + 0xE4) = a1;
        *(int *)((char *)a0 + 0xE8) = a2;
    }
}

__attribute__((section(".text.func_00366D78")))
void func_00366D78(int *a0, int a1, int a2) {
    if (!MPSLIB_CheckHn(a0)) {
        *(int *)((char *)a0 + 0xEC) = a1;
        *(int *)((char *)a0 + 0xF0) = a2;
    }
}

__attribute__((section(".text.func_00338418")))
int func_00338418(int *a0) {
    int r;
    int *tmp;
    int *obj;
    int *vt;
    if (D_003E0710 == 1) {
        if (D_003E0708 <= 0) {
            return 0;
        }
    }
    tmp = *(int**)((char*)a0 + 8);
    obj = *(int**)((char*)tmp + 8);
    vt = *(int**)obj;
    r = ((int(*)(int*, int))vt[9])(obj, 0);
    return r / 2;
}

__attribute__((section(".text.func_00358A48")))
int func_00358A48(int *a0) {
    int r;
    int *s0;
    s0 = a0;
    r = 0;
    if (*(int*)((char*)s0 + 0x48) != 4) {
        goto set_fields;
    }
    r = func_0035C2D0(s0, 7, 7, 0, 0);
    if (r != 0) {
        return r;
    }
set_fields:
    *(int*)((char*)s0 + 0x48) = 1;
    *(int*)((char*)s0 + 0x4C) = 1;
    return 0;
}

__attribute__((section(".text.func_00323B80")))
void func_00323B80(void) {
    int s0;
    int s1;
    int s2;
    s0 = (int)&D_003EAEC8;
    s1 = 0xF;
    s2 = 1;
    do {
        if (*(char *)s0 == s2) {
            func_00323AA0(s0);
        }
        s1--;
        s0 += 0x44;
    } while (s1 >= 0);
}

__attribute__((section(".text.func_00329AF0")))
void func_00329AF0(void) {
    int s0;
    int s1;
    int s2;
    s0 = (int)&D_003C7420;
    s1 = 0xF;
    s2 = 1;
    do {
        if (*(char *)s0 == s2) {
            func_003298F0(s0);
        }
        s1--;
        s0 += 0xC8;
    } while (s1 >= 0);
}

__attribute__((section(".text.func_0032EC00")))
void func_0032EC00(void) {
    int s0;
    int s1;
    int s2;
    s0 = (int)&D_003D1488;
    s1 = 0x3;
    s2 = 1;
    do {
        if (*(char *)s0 == s2) {
            func_0032E720(s0);
        }
        s1--;
        s0 += 0x278;
    } while (s1 >= 0);
}

__attribute__((section(".text.func_00335A40")))
void func_00335A40(void) {
    int s0;
    int s1;
    int s2;
    s0 = (int)&D_003DA5F8;
    s1 = 0x1F;
    s2 = 1;
    do {
        if (*(char *)s0 == s2) {
            func_00336218(s0);
        }
        s1--;
        s0 += 0x238;
    } while (s1 >= 0);
}

__attribute__((section(".text.func_003473A0")))
int func_003473A0(int a0) {
    int s0;
    int v1;
    int v0;

    s0 = a0;
    v0 = func_003472D8(a0);
    if (v0 == 1) {
        return 0;
    }
    v1 = *(int *)((char *)s0 + 0x17C);
    if (v1 == 0) {
        return 0;
    }
    v0 = func_0035CE60(*(int *)((char *)s0 + 0x3C), 2, v1, 0);
    v1 = -1;
    if (v0 == 0) {
        v1 = 0;
    }
    return v1;
}

__attribute__((section(".text.func_00347698")))
int func_00347698(int a0) {
    int s0;
    int v1;
    int v0;

    s0 = a0;
    v0 = func_003472D8(a0);
    if (v0 == 1) {
        return 0;
    }
    v1 = *(int *)((char *)s0 + 0x17C);
    if (v1 == 0) {
        return 0;
    }
    v0 = func_0035CE60(*(int *)((char *)s0 + 0x3C), 2, 0, 0);
    v1 = -1;
    if (v0 == 0) {
        v1 = 0;
    }
    return v1;
}

__attribute__((section(".text.func_0035B4A0")))
void func_0035B4A0(void *a0, int a1) {
    void *s0;
    int tmp0;
    int tmp1;
    s0 = a0;
    if ((unsigned int)a1 < 2) return;
    if (a1 != 2) return;
    func_0035B5B8(s0, &tmp0, &tmp1);
    func_0035B500(s0, tmp0, tmp1);
    func_0035B568(s0, tmp0, tmp1);
}

__attribute__((section(".text.func_003383B0")))
int func_003383B0(int a0) {
    int v0;
    int v1;
    int t;

    if (D_003E0710 == 1 && D_003E0708 <= 0) {
        return 0;
    }
    v0 = *(int *)(*(int *)(a0 + 8) + 8);
    v1 = *(int *)v0;
    v0 = ((int (*)(int, int))*(int *)(v1 + 0x24))(v0, 0);
    v1 = 0x4000 - v0;
    t = (unsigned int)v1 >> 31;
    v1 = v1 + t;
    v0 = v1 >> 1;
    return v0;
}

__attribute__((section(".text.func_00357988")))
int func_00357988(int a0) {
    int a1;
    int a2;
    int v0;
    int v1;

    a1 = a0;
    a2 = a1 + 0xA0C;
    v0 = 1;
    v1 = *(int *)(a2 + 0x38);
    if (v1 == 0) {
        return v0;
    }
    a1 = a1 + 0xD30;
    v1 = *(int *)(a2 + 0x14);
    if (v1 == 0) {
        return v0;
    }
    v1 = *(int *)(a1 + 0x2B0);
    if (v1 != 0) {
        return v0;
    }
    v1 = *(int *)(a1 + 0x2CC);
    a1 = *(int *)(a2 + 0xB4);
    v1 = (v1 < a1);
    if (v1 == 0) {
        return v0;
    }
    v0 = func_00357FC8(a0);
    v0 = ((unsigned int)0 < (unsigned int)v0);
    return v0;
}

__attribute__((section(".text.func_003582C0")))
int func_003582C0(int a0) {
    int v1;
    int v0;

    v1 = a0;
    v0 = *(int *)(v1 + 0x4);
    if (v0 == 0) {
        return func_0034DD70(0, 0xFF000204);
    }
    v0 = *(int *)(v1 + 0x40);
    if ((unsigned int)v0 < 0x37D0u) {
        return func_0034DD70(0, 0xFF000205);
    }
    return 0;
}

__attribute__((section(".text.func_003589C0")))
int func_003589C0(char *a0)
{
    int r;
    char *s0;

    s0 = a0;
    if (*(int *)(s0 + 0x48) == 1) {
        return 0;
    }
    r = func_00358A48(s0);
    if (r) {
        return r;
    }
    *(int *)(s0 + 0x4C) = 0;
    *(int *)(s0 + 0x48) = 0;
    Obj0000_Set_D_003EE2BC_358A28(1);
    r = func_00358AA8(s0);
    Obj0000_Set_D_003EE2BC_358A28(0);
    return r;
}

__attribute__((section(".text.func_00344C30")))
int func_00344C30(int a0)
{
    int r;

    if (a0 == 2) {
        r = 2;
    } else if ((unsigned int)a0 < 3) {
        if (a0 == 1) {
            r = 1;
        } else {
            MWSFSVM_Error(D_00457890);
            r = 1;
        }
    } else {
        if (a0 == 3) {
            r = 3;
        } else if (a0 == 4) {
            r = 4;
        } else {
            MWSFSVM_Error(D_00457890);
            r = 1;
        }
    }
    return r;
}

__attribute__((section(".text.func_003491D0")))
void func_003491D0(void *a0)
{
    char *s0 = (char *)a0;
    int v0;
    v0 = *(int *)(s0 + 0x40);
    if (v0 != 0) {
        if (MWSTM_IsFsStatErr((void *)v0)) {
            *(int *)(s0 + 0x4) = 4;
        }
    }
    a0 = *(void **)(s0 + 0x48);
    if (a0 != 0) {
        if (func_00347DF8(a0) == 1) {
            *(int *)(s0 + 0x4) = 4;
        }
    }
}

__attribute__((section(".text.func_0034B7A8")))
void func_0034B7A8(void *a0)
{
    int r;
    r = Obj35C0_GetIndexed_1F30_C338(a0, 7);
    if (r == 1) return;
    r = func_0034CA30(a0, *(int*)((char*)a0 + 0x211C));
    if (r != 1) return;
    Obj35C0_SetIndexed_1F30_C320(a0, 7, 1);
}

__attribute__((section(".text.func_0034B818")))
void func_0034B818(void *a0)
{
    int r;
    r = Obj35C0_GetIndexed_1F34_C368(a0, 7);
    if (r == 1) return;
    r = func_0034CA98(a0, *(int*)((char*)a0 + 0x211C));
    if (r != 1) return;
    Obj35C0_SetIndexed_1F34_C350(a0, 7, 1);
}

__attribute__((section(".text.func_0035E238")))
int func_0035E238(void *a0, int a1, int *a2)
{
    int s0;
    void *s1;
    int r;

    s0 = a1 & 0xFF;
    *a2 = 0;
    s1 = getElemInfPtr(a0, s0);
    if (!s1)
        return 0;
    r = func_0035E9E8(s0);
    if (r != 0xC0)
        return 0;
    *a2 = *(unsigned char *)((char *)s1 + 0x1B);
    return 1;
}

__attribute__((section(".text.func_0035E2A8")))
int func_0035E2A8(int a0, int a1, int *a2) {
    void *s1;
    int s0;
    s0 = a1 & 0xFF;
    *a2 = 0;
    s1 = getElemInfPtr(a0, s0);
    if (s1 == 0) {
        return 0;
    }
    if (func_0035E9E8(s0) != 0xC0) {
        return 0;
    }
    *a2 = *(int *)((char *)s1 + 0x1C);
    return 1;
}

__attribute__((section(".text.func_0036E308")))
void func_0036E308(int *a0) {
    int *p;
    int v0;
    int v1;
    int idx;
    p = a0;
    if (*(int *)((char *)p + 0x118) == 3) {
        *(int *)((char *)p + 0x3C8) = 0;
        *(int *)((char *)p + 0x3C4) = 0;
    } else {
        v0 = *(int *)((char *)p + 0x3C8);
        v1 = ((v0 + (int)((unsigned int)v0 >> 31)) >> 1) << 1;
        *(int *)((char *)p + 0x3C8) = v0 + 1;
        *(int *)((char *)p + 0x3C4) = v0 - v1;
    }
    idx = *(int *)((char *)p + 0x114);
    *(int *)((char *)p + 0x320) = D_0045A580[idx];
    *(int *)((char *)p + 0x330) = D_0045A590[idx];
}

__attribute__((section(".text.func_00323A00")))
void func_00323A00(int *a0) {
    int *s0;
    int *a1;
    int *v1;
    int (*v0)(int);
    s0 = a0;
    a1 = (int *)(*(int *)((char *)s0 + 0x8));
    if (a1 == 0) {
        return;
    }
    if (*(signed char *)((char *)s0 + 0x2) != 0) {
        return;
    }
    if (D_003EB708 == 1) {
        Forward3B0640_33F3D0(*(int *)((char *)s0 + 0x24), *(int *)((char *)s0 + 0x28));
        a1 = (int *)(*(int *)((char *)s0 + 0x8));
    }
    v1 = (int *)(*(int *)((char *)a1 + 0x0));
    *(int *)((char *)s0 + 0x8) = 0;
    v0 = (int (*)(int))(*(int *)((char *)v1 + 0xC));
    v0((int)a1);
}

__attribute__((section(".text.func_0034EB28")))
int func_0034EB28(int a0, int (*a1)(int, int), int a2, int a3, int a4, int a5) {
    int r;
    r = sfmps_CopySj(a0, a4, a5, a3);
    if (r == 1) {
        if (a1) {
            a1(a2, a3);
        }
    }
    return r;
}

__attribute__((section(".text.func_00355260")))
int func_00355260(int a0) {
    int r;
    int s0;
    int s1;
    int buf;
    int v1;

    s1 = a0;
    s0 = *(int *)((char *)s1 + 0x1FC0);
    r = func_003552D0(s1, s0, &buf);
    if (r != 0) {
        return r;
    }
    r = 2;
    v1 = buf;
    *(int *)((char *)s0 + 0x74) = r;
    if (v1 == 0 || GetArrayElemA0C_35A1C8(s1, 0x30) == 0) {
        *(int *)((char *)s0 + 0x78) = 0xC0;
    } else {
        *(int *)((char *)s0 + 0x78) = 0xC8;
    }
    return 0;
}

__attribute__((section(".text.func_0035E148")))
int func_0035E148(int a0, int a1, int *a2) {
    int s0;
    int s1;
    int v0;
    int v1;

    *a2 = -1;
    s0 = a1 & 0xFF;
    s1 = getElemInfPtr(a0, s0);
    if (!s1) {
        return 0;
    }
    v0 = func_0035E9E8(s0);
    v1 = 0xC0;
    if (v0 != v1) {
        return 0;
    }
    v1 = ((unsigned char *)s1)[25];
    *a2 = v1;
    return 1;
}

__attribute__((section(".text.func_0035E318")))
int func_0035E318(int a0, int a1, int *a2) {
    int s0;
    int s1;

    *a2 = -1;
    s0 = a1 & 0xFF;
    s1 = getElemInfPtr(a0, s0);
    if (s1 == 0) {
        return 0;
    }
    if (func_0035E9E8(s0) != 0xE0) {
        return 0;
    }
    *a2 = *(unsigned char *)((char *)s1 + 0x19);
    return 1;
}

__attribute__((section(".text.func_0035E4B0")))
int func_0035E4B0(int a0, int a1, int *a2) {
    int s0;
    int s1;

    *a2 = 0;
    s0 = a1 & 0xFF;
    s1 = getElemInfPtr(a0, s0);
    if (s1 == 0) {
        return 0;
    }
    if (func_0035E9E8(s0) != 0xE0) {
        return 0;
    }
    *a2 = func_0035E8F8(*(unsigned char *)((char *)s1 + 0x1F));
    return 1;
}

__attribute__((section(".text.func_00331E70")))
int func_00331E70(int a0, int a1, int a2) {
    int s0;
    int s1;
    int s2;
    int r;

    s0 = a0;
    s1 = a1;
    s2 = a2;
    func_00331D40(a0, a1, a2);
    r = func_003B4D98(s0, s1, s2);
    if (r < 0) {
        func_003B1F28((int)&D_00454110, r);
    }
    func_00331D78();
    return r;
}

__attribute__((section(".text.func_00331FA8")))
int func_00331FA8(int a0, int a1, int a2) {
    int s0;
    func_00331D40(a0, a1, a2);
    s0 = func_003B4868(a0, a1, a2);
    if (s0 < 0) {
        func_003B1F28(D_00454170, s0);
    }
    func_00331D78();
    return s0;
}

__attribute__((section(".text.func_0035E388")))
int func_0035E388(int a0, int a1, int *a2) {
    void *s1;
    int s0;
    int v1;
    int a0t;
    s0 = a1 & 0xFF;
    *a2 = 0;
    s1 = getElemInfPtr(a0, s0);
    if (s1 == 0) {
        return 0;
    }
    if (func_0035E9E8(s0) != 0xE0) {
        return 0;
    }
    v1 = (unsigned short)(*(unsigned short *)((char *)s1 + 0x1A));
    a0t = v1 ^ 0xFFFF;
    v1 = a0t ? v1 : 0;
    *a2 = v1;
    return 1;
}

__attribute__((section(".text.func_00332958")))
void func_00332958(void) {
    int s2;
    char *s0;
    int s1;
    if (func_0033BF18(&D_003D90E0) != 0) {
        s2 = 1;
        s0 = D_003D9150;
        s1 = 0x27;
        do {
            if (*s0 == s2) {
                func_00332890(s0);
            }
            s1--;
            s0 += 0x48;
        } while (s1 >= 0);
        D_003D90E0 = 0;
    }
}

__attribute__((section(".text.func_003341B8")))
void func_003341B8(void) {
    int s2;
    char *s0;
    int s1;
    if (func_0033BF18(&D_003D9F74) != 0) {
        s2 = 1;
        s0 = D_003D9FE0;
        s1 = 0xC;
        do {
            if (*s0 == s2) {
                func_003340F0(s0);
            }
            s1--;
            s0 += 0x30;
        } while (s1 >= 0);
        D_003D9F74 = 0;
    }
}

__attribute__((section(".text.func_00338710")))
void func_00338710(int a0, int a1) {
    int s1;
    int s0;
    s0 = a1;
    s1 = a0;
    if (D_003E0710 == 1) {
        if (D_003E0708 <= 0) {
            return;
        }
    }
    if (0xBB80 % s0 != 0) {
        func_00326050(D_00455788);
    }
    *(int *)((char *)s1 + 0x30) = s0;
}

__attribute__((section(".text.func_0033B3B0")))
void func_0033B3B0(void) {
    int *p;
    int s0;
    int v0;
    p = &D_003E8DD4;
    v0 = *p - 1;
    *p = v0;
    if (v0 != 0) {
        return;
    }
    s0 = D_003E9068;
    DTX_Destroy(s0);
    D_003E9068 = 0;
    s0 = D_003E8DDC;
    if (s0 != 0) {
        Tramp_sceSifFreeSysMemory_3B5A50(s0);
        D_003E8DDC = 0;
    }
    func_003325F8();
}
