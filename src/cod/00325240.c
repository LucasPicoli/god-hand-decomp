/* cygnus-2.96 matched TU. */

extern int iReferThreadStatus(int, int *);
extern void func_003B0A40(int);
extern int MPSLIB_CheckHn(int);
extern int GetArrayElemA0C_35A1C8(int, int);
extern int ReferThreadStatus(int thid, void *info);
extern int WakeupThread(int thid);
extern int D_003EE270;
extern void func_0033ACA0(void *a0, int a1, void *a2, void *a3);

__attribute__((section(".text.func_00325240")))
void func_00325240(int a0) {
    int local[12];
    int status;
    if (a0 != 0) {
        iReferThreadStatus(a0, local);
        status = local[0];
        if (status == 4 || status == 0xC)
            func_003B0A40(a0);
    }
}

__attribute__((section(".text.func_00366DC8")))
void func_00366DC8(int a0, int a1, int a2) {
    if (MPSLIB_CheckHn(a0) == 0) {
        *(int *)(a0 + 0xF4) = a1;
        *(int *)(a0 + 0xF8) = a2;
    }
}

__attribute__((section(".text.func_0035A7C8")))
void func_0035A7C8(int a0, int a1) {
    if (GetArrayElemA0C_35A1C8(a0, 0x47) == 1)
        *(int *)(a1 + 0x2D0) = *(volatile int *)(a1 + 0x2A8);
    else
        *(int *)(a1 + 0x2D0) = *(volatile int *)(a1 + 0x2DC);
}

__attribute__((section(".text.func_00325290")))
void func_00325290(int a0) {
    int info[12];
    if (a0 != 0) {
        ReferThreadStatus(a0, info);
        if (info[0] == 4 || info[0] == 0xC) {
            WakeupThread(a0);
        }
    }
}

__attribute__((section(".text.func_0035B848")))
void func_0035B848(int a0, int a1, int a2, int *a3) {
    volatile int *t0 = (volatile int *)(a0 + 0xD30);
    int *dp = &D_003EE270;
    if (t0[0xB3] < 0) {
        t0[0xB3] = 0;
        *a3 = 1;
    } else {
        if (func_00366918(a1, a2, t0[0xB3], dp[2]) != 0) {
            *a3 = 1;
        } else {
            *a3 = 0;
        }
    }
}

__attribute__((section(".text.func_00357910")))
int func_00357910(int a0) {
    int mode, ret;
    if (func_00357ED8(a0) != 0) {
        return *(int *)(a0 + 0x48);
    }
    if (func_003579F0(a0) != 0) {
        return *(int *)(a0 + 0x48);
    }
    mode = *(int *)(a0 + 0x4C);
    ret = *(int *)(a0 + 0x48);
    if (mode >= 2) {
        if (mode >= 5) {
            if (mode == 6) {
                ret = 6;
            }
        }
    }
    return ret;
}

typedef void (*VFN)();

__attribute__((section(".text.func_00349FB0")))
void func_00349FB0(int *thisp, int flag, void *arg) {
    int buf[4];
    if (flag == 0) {
        (*(VFN)(*(int *)(*(char **)thisp + 0x1C)))(thisp);
    } else {
        func_0033ACA0(arg, flag, arg, buf);
        (*(VFN)(*(int *)(*(char **)thisp + 0x20)))(thisp, 1, arg);
        (*(VFN)(*(int *)(*(char **)thisp + 0x1C)))(thisp, 0, buf);
    }
}
