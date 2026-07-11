/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern char *D_003C2F84;
extern char *D_003C23A4;
extern void func_002C4150(char *a0, int a1, int a2, int a3, int t0, int t1);
extern void cTaskWork_exit(int a0);
extern void func_002C1D68(int a0, int a1, int a2);
extern void cSceAtUnit_getCenterPos(int a0, int a1);
extern void func_002D56A8(void *a0);
extern char D_007474A0[];
extern char D_0061A990[];
extern void func_002D9BD0(void *a0);
extern void func_002D9BD8(void *a0);

__attribute__((section(".text.SetNodeCallback_2C2138")))
int SetNodeCallback_2C2138(char *a0, int a1) {
    int t;
    if (*(int*)(a0+0x3C) == 0) {
        return 0;
    }
    t = func_002C38D8(D_003C2F84, *(int*)(a0+0x3C), *(int*)(a0+0x40), *(char*)(a0+0x44));
    *(int*)(D_003C2F84 + (t << 3) + 0x58) = a1;
    return 1;
}

__attribute__((section(".text.ForwardEntityAndExit_2C2368")))
void ForwardEntityAndExit_2C2368(char *a0) {
    char *s1 = a0 + 0x5C;
    int v1 = *(unsigned short*)(s1 + 2);
    if ((unsigned int)v1 < 0x1000) {
        v1 = func_002AEB50(D_003C23A4, *(unsigned short*)(a0 + 0x5C), v1);
    }
    func_002C4150(D_003C2F84, v1, *(int*)(s1 + 0xC), 0, 0, 1);
    cTaskWork_exit(*(int*)(D_003C2F84 + 0x20));
}

__attribute__((section(".text.FindNodeByHit_2C2490")))
int FindNodeByHit_2C2490(int a0, int a1, float *a2) {
    int s0;
    int sp[12];
    s0 = func_002C30C0(a0);
    while ((s0 = func_002C30C8(a0, s0)) != 0) {
        if ((*(int*)(s0 + 0x34) & 0xFF01) == 0xB01) {
            func_002C1D68(a0, (int)sp, s0);
            if (cArea_HitCheck_1F83E8((int)sp, a1) == 1) {
                if (a2 != 0) {
                    a2[0] = *(float*)(s0 + 0x5C);
                    a2[1] = *(float*)(s0 + 0x60);
                    a2[2] = *(float*)(s0 + 0x64);
                }
                return 1;
            }
        }
    }
    return 0;
}

__attribute__((section(".text.FindNodeByType_2C2568")))
int FindNodeByType_2C2568(int a0, int a1, float *a2) {
    int s0;
    int sp[12];
    s0 = func_002C30C0(a0);
    while ((s0 = func_002C30C8(a0, s0)) != 0) {
        if (*(unsigned char*)(s0 + 0x35) == 0xD) {
            func_002C1D68(a0, (int)sp, s0);
            if (cArea_HitCheck_1F83E8((int)sp, a1) == 1) {
                if (a2 != 0) {
                    a2[0] = *(float*)(s0 + 0x5C);
                    a2[1] = *(float*)(s0 + 0x60);
                    a2[2] = *(float*)(s0 + 0x64);
                }
                return 1;
            }
        }
    }
    return 0;
}

__attribute__((section(".text.FindEntityAtPosition_2C2638")))
int FindEntityAtPosition_2C2638(int a0, int a1, int a2, float *a3) {
    int s0;
    int buf[12];
    s0 = func_002C30C0(a0);
    while ((s0 = func_002C30C8(a0, s0)) != 0) {
        if (((*(unsigned char *)(s0 + 0x34) ^ 1) & 1) != 0) continue;
        if (*(unsigned char *)(s0 + 0x35) != 0xC) continue;
        func_002C1D68(a0, buf, s0);
        if (cArea_HitCheck_1F83E8(buf, a1) != 1) continue;
        if (a2 != 0) cSceAtUnit_getCenterPos(s0, a2);
        if (a3 != 0) *a3 = *(float *)(s0 + 0x10);
        return 1;
    }
    return 0;
}

__attribute__((section(".text.ResetEntityStateById_2C29F8")))
int ResetEntityStateById_2C29F8(int a0, int a1) {
    int r;
    if (*(int*)a0 == 0) return 0;
    r = cSceAtManager_getUnit(a0, a1 & 0xFFFF);
    if (r == 0) return 0;
    return cSceAtManager_SetDisable(a0, r);
}

__attribute__((section(".text.FindEntityByTypeIndex_2C2AE0")))
int FindEntityByTypeIndex_2C2AE0(int a0, int a1) {
    int e;
    e = func_002C30C0(a0);
    while ((e = func_002C30C8(a0, e)) != 0) {
        if (*(unsigned char*)((char*)e + 0x35) == 1) {
            if (*(unsigned char*)((char*)e + 0x79) == a1) return e;
        }
    }
    return 0;
}

__attribute__((section(".text.ClearActorList_2C32C0")))
void ClearActorList_2C32C0(void *a0) {
    func_002D56A8((char*)a0 + 0x1C);
    *(char*)((char*)a0 + 0x14) = 0;
}

__attribute__((section(".text.ResetActorState_2C3440")))
void ResetActorState_2C3440(void *a0) {
    int v0;
    char *b = D_007474A0;
    *(unsigned short*)((char*)a0 + 0x112) = 0xFFFF;
    *(int*)((char*)a0 + 0x104) = 0;
    *(int*)((char*)a0 + 0xEC) = 0;
    *(int*)((char*)a0 + 0xF0) = 0;
    *(int*)((char*)a0 + 0xF4) = 0;
    *(int*)((char*)a0 + 0xF8) = 0;
    *(int*)((char*)a0 + 0xFC) = 0;
    *(int*)((char*)a0 + 0x100) = 0;
    *(char*)((char*)a0 + 0x108) = 0;
    *(short*)((char*)a0 + 0xE8) = 0;
    *(int*)(b + 0x610) = 0xFFFFu;
    v0 = *(int*)((char*)a0 + 0x48);
    v0 &= -2;
    v0 &= -3;
    *(int*)((char*)a0 + 0x48) = v0;
    if ((*(int*)(b + 0x590) & 1) == 0) {
        void (*f)(void);
        func_002D9BD0(D_0061A990);
        f = *(void (**)(void))(*(char**)((char*)a0 + 0xD4) + 8);
        if (f != 0) f();
        func_002D9BD8(D_0061A990);
    }
}

__attribute__((section(".text.func_002C3820")))
void func_002C3820(void *a0) {
    void (*f)(int) = *(void (**)(int))((char*)a0 + 0xEC);
    if (f != 0) {
        f(*(int*)((char*)a0 + 0xF0));
        *(int*)((char*)a0 + 0xEC) = 0;
    }
}
