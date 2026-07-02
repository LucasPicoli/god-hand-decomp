/* cygnus-2.96 matched TU — CRI libadxe, recovered from recvx-decomp (CC0). */

typedef unsigned short Uint16;
typedef signed char   Sint8;
typedef signed int    Sint32;
#define BSWAP_U16(_val) (Uint16)((*(Uint16*)_val >> 8) | (*(Uint16*)_val << 8))

__attribute__((section(".text.ADXT_IsEndcode")))
Sint32 ADXT_IsEndcode(Sint8 *adr, Sint32 siz, Sint32 *endsiz) {
    if (siz <= 1) {
        return 0;
    }
    if (BSWAP_U16(adr) != 0x8001) {
        return 0;
    }
    *endsiz = siz;
    return 1;
}

extern void Obj33F8_Tramp_0033F130_FCB0(int);
extern char D_00452BF8[];
extern char D_00452C20[];
extern void func_00335D40(int);
extern char D_00454FA0[];
extern void func_003412D8(int);
extern void func_00341120(int);
extern void func_0033F130(int);
extern char D_00452318[];
extern int D_003D1414;
extern int Obj3270_GetField_2C(int);
extern char D_00452688[];
extern int Forward33B568_33B6A0(void);
extern int D_003D8484;
extern int Forward33B5C8_33B6D0(void);

__attribute__((section(".text.func_0032DEC8")))
void func_0032DEC8(int a0, int a1) {
    if (a0 == 0) {
        Obj33F8_Tramp_0033F130_FCB0((int)D_00452BF8);
    } else {
        *(unsigned char *)((char *)a0 + 0x1B0) = a1;
    }
}

__attribute__((section(".text.func_0032DF38")))
void func_0032DF38(int a0, int a1) {
    if (a0 == 0) {
        Obj33F8_Tramp_0033F130_FCB0((int)D_00452C20);
    } else {
        *(unsigned char *)((char *)a0 + 0x1B1) = a1;
    }
}

__attribute__((section(".text.func_00335CA8")))
void func_00335CA8(int a0, int a1) {
    if (a0 == 0) {
        func_00335D40((int)D_00454FA0);
    } else {
        *(unsigned char *)((char *)a0 + 0x3) = a1;
    }
}

__attribute__((section(".text.func_00341458")))
void func_00341458(int a0) {
    if (*(short *)((char *)a0 + 0x9C) == 1) {
        func_003412D8(a0);
    } else {
        func_00341120(a0);
    }
}

__attribute__((section(".text.func_0032ABB0")))
void func_0032ABB0(int a0, int a1) {
    if (a0 == 0) {
        func_0033F130((int)D_00452318);
    } else {
        *(int *)((char *)a0 + 0x38) = a1;
        D_003D1414 = a1;
    }
}

__attribute__((section(".text.func_0032B718")))
int func_0032B718(int a0) {
    if (a0 == 0) {
        func_0033F130((int)D_00452688);
        return -1;
    }
    return Obj3270_GetField_2C(*(int *)((char *)a0 + 0x4));
}

__attribute__((section(".text.func_00331D40")))
void func_00331D40(void) {
    if (D_003D8484 == 1) {
        Forward33B568_33B6A0();
    }
}

__attribute__((section(".text.func_00331D78")))
void func_00331D78(void) {
    if (D_003D8484 == 1) {
        Forward33B5C8_33B6D0();
    }
}
