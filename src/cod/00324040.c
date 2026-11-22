/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern signed char D_003C7420[];
extern int ADXT_GetOutPan(signed char *, int);
extern void func_0032A720(signed char *, int, int);
extern void func_0032A900(signed char *, int);
extern void mwsfcre_AllFree(void *);
extern void MWSFSVM_Error(void *);

__attribute__((section(".text.ADXT_SetOutputMono")))
void ADXT_SetOutputMono(int a0) {
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

__attribute__((section(".text.SFBUF_GetFlowCnt")))
void SFBUF_GetFlowCnt(int a0, int *a1, int *a2) {
    if (func_0034CC40(a0)) {
        *a1 = SJRBF_GetFlowCnt(a0, 1, 1);
        *a2 = SJRBF_GetFlowCnt(a0, 0, 1);
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

int dvci_getnumtr_upper(void);
int dvci_getnumtr_lower(void);
int func_003332A8(void);
int Forward3331E0_3332B0(void);

__attribute__((section(".text.func_003332C8")))
int func_003332C8(int a0, int a1) {
    int r = 0;
    if (a0 == 0) return 0;
    switch (a1) {
        case 0xC8: r = dvci_getnumtr_upper(); break;
        case 0xC9: r = dvci_getnumtr_lower(); break;
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
int sfply_IsStartSync(void*);

__attribute__((section(".text.sfply_StatPrep")))
int sfply_StatPrep(int *a0) {
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
            if (sfply_IsStartSync(a0) != 0) {
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

int adxf_SetCmdHstry(int, int, void*, int, int);
int func_0033F130(void*);
int ADXSTM_StopNw(int);

__attribute__((section(".text.func_00324040")))
int func_00324040(int *a0) {
    adxf_SetCmdHstry(7, 0, a0, -1, -1);
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
        ADXSTM_StopNw(a0[1]);
        *((char*)a0 + 3) = 1;
        adxf_SetCmdHstry(7, 1, a0, -1, -1);
        return a0[5];
    }
}

__attribute__((section(".text.mwsfcre_MallocCompoWork")))
int mwsfcre_MallocCompoWork(char *s0) {
    char *s1 = s0 + 8;
    int s2 = func_00346C10(*(int*)(s1 + 8), *(int*)(s1 + 0xC));
    int r = func_00344568(s0, s2);
    if (r == 0) {
        MWSFSVM_Error(&D_00457650);
        mwsfcre_AllFree(s0);
        return -1;
    }
    *(int*)(s0 + 0xAC) = r;
    *(int*)(s0 + 0xB0) = s2;
    if (MWSFTAG_IsUseAinfSj(s1) == 1) {
        int r2 = func_00344568(s0, 0x20000);
        if (r2 == 0) {
            MWSFSVM_Error(&D_00457678);
            mwsfcre_AllFree(s0);
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

__attribute__((section(".text.lsc_StatRead")))
void lsc_StatRead(char *s0) {
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
