/* cygnus-2.96 matched TU. */

extern void Obj3290_Tramp_0033E678_9028(void *a0);
extern int Obj3290_Tramp_0033E690_9040(void);
extern int Obj3270_GetVia4_0033CE98_77A0(int a0);
extern int D_00453310;
extern int D_00453330;
extern void Tramp_003302B0_003302E0(int *a0);
extern int D_00453348;
extern int D_00453368;
extern int D_00453380;
extern int D_004533A0;
extern int D_00453EB0;
extern int D_00453ED0;
extern int Forward33B568_33B688(void);
extern int Forward33B5C8_33B6B8(void);
extern void func_003B1F28(int *a0);
extern volatile unsigned int D_003D8460;
extern int D_003D844C;
extern int D_00453F98;

__attribute__((section(".text.func_00328300")))
int func_00328300(void *a0) {
    Obj3290_Tramp_0033E678_9028(a0);
    if ((*(int*)a0 & 0xFFFF00) == 0x10200) {
        *(char*)((char*)a0 + 0x48) = 1;
        if (*(signed char*)((char*)a0 + 0x47) == 1) {
            *(char*)((char*)a0 + 0x47) = 0;
        }
    } else {
        *(char*)((char*)a0 + 1) = 1;
    }
    return Obj3290_Tramp_0033E690_9040();
}

__attribute__((section(".text.func_0032C2A8")))
int func_0032C2A8(void *a0) {
    if (Obj3270_GetVia4_0033CE98_77A0(*(int*)((char*)a0 + 4)) == 1) {
        return func_0032A6D0(a0, 0, *(short*)((char*)a0 + 0x42));
    } else {
        func_0032A6D0(a0, 0, *(short*)((char*)a0 + 0x42));
        return func_0032A6D0(a0, 1, *(short*)((char*)a0 + 0x44));
    }
}

__attribute__((section(".text.func_00330B48")))
int func_00330B48(int *a0) {
    int s0;
    if (a0 == 0) {
        Tramp_003302B0_003302E0(&D_00453310);
        return 0;
    }
    {
        int (*fp)(int) = (int (*)(int))*(int*)(*(int*)a0 + 0x1C);
        if (fp != 0) {
            s0 = fp(a0[1]);
        } else {
            s0 = 0;
            Tramp_003302B0_003302E0(&D_00453330);
        }
    }
    return s0;
}

__attribute__((section(".text.func_00330BB0")))
int func_00330BB0(int *a0) {
    int s0;
    if (a0 == 0) {
        Tramp_003302B0_003302E0(&D_00453348);
        return 0;
    }
    {
        int (*fp)(int) = (int (*)(int))*(int*)(*(int*)a0 + 0x18);
        if (fp != 0) {
            s0 = fp(a0[1]);
        } else {
            s0 = 0;
            Tramp_003302B0_003302E0(&D_00453368);
        }
    }
    return s0;
}

__attribute__((section(".text.func_00330C18")))
int func_00330C18(int *a0) {
    int s0;
    if (a0 == 0) {
        Tramp_003302B0_003302E0(&D_00453380);
        return 0;
    }
    {
        int (*fp)(int) = (int (*)(int))*(int*)(*(int*)a0 + 0x20);
        if (fp != 0) {
            s0 = fp(a0[1]);
        } else {
            s0 = 0;
            Tramp_003302B0_003302E0(&D_004533A0);
        }
    }
    return s0;
}

__attribute__((section(".text.func_00331570")))
int func_00331570(int *a0) {
    int *s0 = a0;
    Forward33B568_33B688();
    if (s0 == 0) {
        func_003B1F28(&D_00453EB0);
    } else if (s0[1] == 1) {
        func_003B1F28(&D_00453ED0);
    } else {
        s0[1] = 1;
    }
    return Forward33B5C8_33B6B8();
}

__attribute__((section(".text.func_00331BF0")))
void func_00331BF0(void) {
    D_003D8460 = 0;
    while (1) {
        if (D_003D844C != 1) {
            return;
        }
        D_003D8460 = D_003D8460 + 1;
        if (0x19640000U < D_003D8460) {
            func_003B1F28(&D_00453F98);
            return;
        }
    }
}
