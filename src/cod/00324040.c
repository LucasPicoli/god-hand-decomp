/* cygnus-2.96 matched TU. */

extern int D_003C7410;
extern signed char D_003C7420[];
extern int ADXT_GetOutPan(signed char *, int);
extern void func_0032A720(signed char *, int, int);
extern void func_0032A900(signed char *, int);
extern int D_00451858;
extern int D_00451880;
extern int D_00457650, D_00457678;
extern void func_00344710(void *);
extern void MWSFSVM_Error(void *);
extern int D_00455040;

__attribute__((section(".text.func_0032BA30")))
void func_0032BA30(int a0) {
    signed char *p = D_003C7420;
    int i;
    D_003C7410 = a0;
    for (i = 15; i >= 0; i--, p += 0xC8) {
        if (p[0] == 1) {
            int j;
            for (j = 0; j < p[3]; j++) {
                int pan = ADXT_GetOutPan(p, j);
                func_0032A720(p, j, pan);
            }
            func_0032A900(p, func_0032A9C0(p));
        }
    }
}

__attribute__((section(".text.func_0034CAF8")))
void func_0034CAF8(int a0, int *a1, int *a2) {
    if (func_0034CC40(a0)) {
        *a1 = func_0033A010(a0, 1, 1);
        *a2 = func_0033A010(a0, 0, 1);
    } else if (func_0034CC78(a0)) {
        int v = func_00339430(a0);
        int *vt = *(int **)a0;
        int r;
        *a1 = v;
        r = (*(int (**)(int, int))((char *)vt + 0x24))(a0, 1);
        *a2 = *a1 - r;
    } else {
        *a1 = 0;
        *a2 = 0;
    }
}

int func_00333278(void);
int func_00333288(void);
int func_003332A8(void);
int Forward3331E0_3332B0(void);

__attribute__((section(".text.func_003332C8")))
int func_003332C8(int a0, int a1) {
    int r = 0;
    if (a0 == 0) return 0;
    switch (a1) {
        case 0xC8: r = func_00333278(); break;
        case 0xC9: r = func_00333288(); break;
        case 0xCA: r = func_003332A8(); break;
        case 0xCB: r = Forward3331E0_3332B0(); break;
        case 0xCC: r = func_003332A8(); break;
        case 0xCD: r = Forward3331E0_3332B0(); break;
        case 0x12B: r = 1; break;
    }
    return r;
}

int sfply_IsPrepEnd(void*);
void sfply_AdjustPrepEnd(void*);
void sfply_TrStart(void*);
int func_00357988(void*);

__attribute__((section(".text.func_003574D8")))
int func_003574D8(int *a0) {
    int ret = a0[0x12];
    int sel = a0[0x13];
    if (sfply_IsPrepEnd(a0) == 0) {
        return ret;
    }
    sfply_AdjustPrepEnd(a0);
    switch (sel) {
        case 2:
            ret = 2;
            break;
        case 4:
        case 6:
            if (func_00357988(a0) != 0) {
                sfply_TrStart(a0);
                ret = 4;
                break;
            }
            /* fallthrough */
        case 3:
            ret = 3;
            break;
    }
    return ret;
}

int func_003228C0(int, int, void*, int, int);
int func_0033F130(void*);
int func_003282D0(int);

__attribute__((section(".text.func_00324040")))
int func_00324040(int *a0) {
    func_003228C0(7, 0, a0, -1, -1);
    if (a0 == 0) {
        func_0033F130(&D_00451858);
        return -3;
    }
    {
        signed char v1 = *((signed char*)a0 + 1);
        if (v1 == 1) {
            return a0[5];
        }
        if (v1 == 3) {
            *((char*)a0 + 1) = 1;
            return a0[5];
        }
        if (a0[1] == 0) {
            func_0033F130(&D_00451880);
            return -1;
        }
        func_003282D0(a0[1]);
        *((char*)a0 + 3) = 1;
        func_003228C0(7, 1, a0, -1, -1);
        return a0[5];
    }
}

__attribute__((section(".text.func_00344300")))
int func_00344300(char *s0) {
    char *s1 = s0 + 8;
    int s2 = func_00346C10(*(int*)(s1 + 8), *(int*)(s1 + 0xC));
    int r = func_00344568(s0, s2);
    if (r == 0) {
        MWSFSVM_Error(&D_00457650);
        func_00344710(s0);
        return -1;
    }
    *(int*)(s0 + 0xAC) = r;
    *(int*)(s0 + 0xB0) = s2;
    if (func_003472E8(s1) == 1) {
        int r2 = func_00344568(s0, 0x20000);
        if (r2 == 0) {
            MWSFSVM_Error(&D_00457678);
            func_00344710(s0);
            return -1;
        }
        *(int*)(s0 + 0x180) = r2;
        *(int*)(s0 + 0x184) = 0x20000;
    } else {
        *(int*)(s0 + 0x180) = 0;
        *(int*)(s0 + 0x184) = 0;
    }
    return 0;
}

__attribute__((section(".text.func_00336048")))
void func_00336048(char *s0) {
    if (*(int*)(s0 + 0x28) == 0) {
        func_00335D40(&D_00455040);
        return;
    }
    {
        char *s1 = s0 + (*(int*)(s0 + 0x20) << 5) + 0x38;
        switch (func_00328098(*(int*)(s0 + 0x28))) {
        case 2:
            *(int*)(s1 + 0x1C) = func_00328140(*(int*)(s0 + 0x28));
            break;
        case 3: {
            int t = *(int*)(s0 + 0x2C);
            *(int*)(s1 + 0x18) = 2;
            *(int*)(s1 + 0x1C) = t;
            break;
        }
        case 4:
            *(char*)(s0 + 1) = 3;
            break;
        }
    }
}
