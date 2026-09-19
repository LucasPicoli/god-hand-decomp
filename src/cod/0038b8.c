/* Struct: CGObj38B8_t */
#include "include_asm.h"

/* -- Forward declarations for called functions -------------------------------- */
extern int doallocbuf__9streambuf(char *a0);
extern int _IO_getc(char *a0);
extern int _IO_putc(char *a0, char *a1);
extern unsigned int _IO_sgetn(void *fp, void *buf, unsigned int n);
extern int _IO_padn(char *a0, int a1);
extern void _IO_seekpos(char *a0);
extern void _IO_seekoff(char *a0);
extern void _IO_free_backup_area(void *fp);
extern int *func_0038C168(void);
extern void SetField_0_4_8_31EEA8(void *a0, void *a1, void *a2);
extern void func_0038AFB0(int a0);
extern void *func_0038BE98(void);

/* -- Extern globals ----------------------------------------------------------- */
extern int D_786768;
extern int D_786778;
extern char D_0045D350[];
extern char D_0045D360[];
extern char D_00460DB0[];


__attribute__((section(".text.Obj38B8_GetSignedField38_OrMinus1")))
int Obj38B8_GetSignedField38_OrMinus1(char *a0) {
    int x = *(int *)(a0 + 0x38);
    int sign = (unsigned int)(~x) >> 31;
    return sign ? x : -1;
}

__attribute__((section(".text.Obj38B8_IsField38_NonNegative")))
int Obj38B8_IsField38_NonNegative(char *a0) {
    return *(int *)(a0 + 0x38) >= 0;
}

__attribute__((section(".text.func_0038B8B0")))
void *func_0038B8B0(void) {
    int *s0 = &D_786768;
    if (!*s0) {
        func_0038BE98();
        SetField_0_4_8_31EEA8(s0, &D_0045D350, &D_786778);
    }
    return s0;
}
/* streambuf::stossc — advance gptr while it is below egptr. */
__attribute__((section(".text.stossc__9streambuf")))
void stossc__9streambuf(int *p) {
    int a = p[1];
    if ((unsigned int)a < (unsigned int)p[2]) {
        p[1] = a + 1;
    }
}
__attribute__((section(".text.sputc__9streambufi")))
int sputc__9streambufi(char *sb, int c) {
    return _IO_putc((char *)c, sb);
}
/* streambuf::sgetn out-of-lined from gcc-2.95.2 streambuf.h. */
__attribute__((section(".text.sgetn__9streambufPcl")))
long sgetn__9streambufPcl(void *sb, char *s, long n) {
    return _IO_sgetn(sb, s, n);
}
__attribute__((section(".text.func_0038BA68")))
int func_0038BA68(void *a0, int a1) {
    return _IO_padn(a0, (char)a1);
}
/* streambuf::sputn out-of-lined from gcc-2.95.2 streambuf.h: a virtual call through the g++ 2.x vtable at 0x50 (entry 6 = xsputn). */
struct VtEnt { short delta; short index; void *pfn; };
__attribute__((section(".text.sputn__9streambufPCcl")))
long sputn__9streambufPCcl(char *sb, const char *s, long n) {
    struct VtEnt *vt = *(struct VtEnt **)(sb + 0x50);
    return ((long (*)(char *, const char *, long))vt[6].pfn)(sb + vt[6].delta, s, n);
}
__attribute__((section(".text.Obj38B8_GetField14MinusField10")))
int Obj38B8_GetField14MinusField10(char *a0) {
    return *(int *)(a0 + 0x14) - *(int *)(a0 + 0x10);
}

__attribute__((section(".text.Obj38B8_GetField8MinusField4")))
int Obj38B8_GetField8MinusField4(char *a0) {
    return *(int *)(a0 + 8) - *(int *)(a0 + 4);
}

/* streambuf::allocate out-of-lined from gcc-2.95.2 streambuf.h: base() || unbuffered() ? 0 : doallocate() (vtable entry 12). */
__attribute__((section(".text.allocate__9streambuf")))
int allocate__9streambuf(char *sb) {
    if (*(char **)(sb + 0x1C) != 0 || ((*(int *)sb >> 1) & 1)) return 0;
    else {
        struct VtEnt *vt = *(struct VtEnt **)(sb + 0x50);
        return ((int (*)(char *))vt[12].pfn)(sb + vt[12].delta);
    }
}
__attribute__((section(".text.func_0038BB48")))
void func_0038BB48(char *arg0, int arg1) {
    if (arg1) {
        *(int *)(arg0 + 0x0) |= 0x200;
    } else {
        *(int *)(arg0 + 0x0) &= ~0x200;
    }
}
__attribute__((section(".text.func_0038BB70")))
void func_0038BB70(char *arg0, int arg1) {
    if (arg1) {
        *(int *)(arg0 + 0x0) |= 2;
    } else {
        *(int *)(arg0 + 0x0) &= ~2;
    }
}
__attribute__((section(".text.Obj38B8_GetFlag0_Bit9")))
int Obj38B8_GetFlag0_Bit9(char *a0) {
    return (*(int *)a0 >> 9) & 1;
}

__attribute__((section(".text.Obj38B8_GetFlag0_Bit1")))
int Obj38B8_GetFlag0_Bit1(char *a0) {
    return (*(int *)a0 >> 1) & 1;
}

/* func_0038BBB8 / func_0038BBD8 matched & carved to merged_orphans_f.c (sn). */
__attribute__((section(".text.Obj38B8_GetFlag0_Mask800")))
int Obj38B8_GetFlag0_Mask800(char *a0) {
    return *(int *)a0 & 0x800;
}
__attribute__((section(".text.Obj38B8_IsField30_NonZero")))
int Obj38B8_IsField30_NonZero(char *a0) {
    return *(int *)(a0 + 0x30) != 0;
}
__attribute__((section(".text.Obj38B8_IsField24_NonZero")))
int Obj38B8_IsField24_NonZero(char *a0) {
    return *(int *)(a0 + 0x24) != 0;
}
__attribute__((section(".text.Obj38B8_GetField2C")))
int Obj38B8_GetField2C(char *a0) {
    return *(int *)(a0 + 0x2C);
}

__attribute__((section(".text.Obj38B8_GetField24")))
int Obj38B8_GetField24(char *a0) {
    return *(int *)(a0 + 0x24);
}

__attribute__((section(".text.Obj38B8_GetMode100Or_8_2C")))
int Obj38B8_GetMode100Or_8_2C(char *a0) {
    return (*(int *)a0 & 0x100) ? *(int *)(a0 + 8) : *(int *)(a0 + 0x2C);
}

__attribute__((section(".text.Obj38B8_GetField28")))
int Obj38B8_GetField28(char *a0) {
    return *(int *)(a0 + 0x28);
}

__attribute__((section(".text.Obj38B8_GetMode100Or_C_24")))
int Obj38B8_GetMode100Or_C_24(char *a0) {
    return (*(int *)a0 & 0x100) ? *(int *)(a0 + 0xC) : *(int *)(a0 + 0x24);
}

__attribute__((section(".text.Obj38B8_GetMode100Or_2C_8")))
int Obj38B8_GetMode100Or_2C_8(char *a0) {
    return (*(int *)a0 & 0x100) ? *(int *)(a0 + 0x2C) : *(int *)(a0 + 8);
}

__attribute__((section(".text.Obj38B8_GetMode100Or_24_C")))
int Obj38B8_GetMode100Or_24_C(char *a0) {
    return (*(int *)a0 & 0x100) ? *(int *)(a0 + 0x24) : *(int *)(a0 + 0xC);
}

__attribute__((section(".text.Obj38B8_GetMode100Mask")))
int Obj38B8_GetMode100Mask(char *a0) {
    return *(int *)a0 & 0x100;
}
__attribute__((section(".text.Obj38B8_GetPtrField4B")))
char *Obj38B8_GetPtrField4B(char *a0) {
    return a0 + 0x4B;
}

/* streambuf::setg out-of-lined from gcc-2.95.2 streambuf.h. */
__attribute__((section(".text.setg__9streambufPcT1T1")))
void setg__9streambufPcT1T1(char *sb, char *eb, char *g, char *eg) {
    if (*(int *)sb & 0x100) _IO_free_backup_area(sb);
    *(char **)(sb + 0xC) = eb; *(char **)(sb + 0x4) = g; *(char **)(sb + 0x8) = eg;
}
/* func_0038BD40: the two do{}while(0) barriers keep the retail store order. */
__attribute__((section(".text.func_0038BD40")))
void func_0038BD40(int *p, int a, int b) {
    p[5] = a;
    p[4] = a;
    p[6] = b;
}
__attribute__((section(".text.Obj38B8_AddField14")))
int Obj38B8_AddField14(char *a0, int a1) {
    int v = *(int *)(a0 + 0x14) + a1;
    *(int *)(a0 + 0x14) = v;
    return v;
}

__attribute__((section(".text.Obj38B8_MaskedSetField0")))
void Obj38B8_MaskedSetField0(char *a0, int a1, int a2) {
    *(int *)a0 = (*(int *)a0 & ~a2) | (a1 & a2);
}
__attribute__((section(".text.Obj38B8_OrField0")))
void Obj38B8_OrField0(char *a0, int a1) {
    *(int *)a0 |= a1;
}

__attribute__((section(".text.Obj38B8_ExchangeField0")))
int Obj38B8_ExchangeField0(char *a0, int a1) {
    int old = *(int *)a0;
    *(int *)a0 = a1;
    return old;
}
__attribute__((section(".text.Obj38B8_GetField0")))
int Obj38B8_GetField0(char *a0) {
    return *(int *)a0;
}

__attribute__((section(".text.Obj38B8_WriteByteAndAdvance14")))
void Obj38B8_WriteByteAndAdvance14(char *a0, int a1) {
    char *p = (char *)*(int *)(a0 + 0x14);
    *p++ = (char)a1;
    *(int *)(a0 + 0x14) = (int)p;
}
__attribute__((section(".text.Obj38B8_GetField20MinusField1C")))
int Obj38B8_GetField20MinusField1C(char *a0) {
    return *(int *)(a0 + 0x20) - *(int *)(a0 + 0x1C);
}

__attribute__((section(".text.Obj38B8_GetField20")))
int Obj38B8_GetField20(char *a0) {
    return *(int *)(a0 + 0x20);
}

__attribute__((section(".text.Obj38B8_GetField1C")))
int Obj38B8_GetField1C(char *a0) {
    return *(int *)(a0 + 0x1C);
}

__attribute__((section(".text.Obj38B8_GetMode100Or_C_24_v2")))
int Obj38B8_GetMode100Or_C_24_v2(char *a0) {
    return (*(int *)a0 & 0x100) ? *(int *)(a0 + 0x24) : *(int *)(a0 + 0xC);
}

__attribute__((section(".text.Obj38B8_GetField10")))
int Obj38B8_GetField10(char *a0) {
    return *(int *)(a0 + 0x10);
}

__attribute__((section(".text.Obj38B8_GetField18")))
int Obj38B8_GetField18(char *a0) {
    return *(int *)(a0 + 0x18);
}

__attribute__((section(".text.Obj38B8_GetMode100Or_2C_8_v2")))
int Obj38B8_GetMode100Or_2C_8_v2(char *a0) {
    return (*(int *)a0 & 0x100) ? *(int *)(a0 + 0x2C) : *(int *)(a0 + 8);
}

__attribute__((section(".text.Obj38B8_GetField14")))
int Obj38B8_GetField14(char *a0) {
    return *(int *)(a0 + 0x14);
}

__attribute__((section(".text.Obj38B8_GetMode100Or_24_4")))
int Obj38B8_GetMode100Or_24_4(char *a0) {
    return (*(int *)a0 & 0x100) ? *(int *)(a0 + 0x24) : *(int *)(a0 + 4);
}

__attribute__((section(".text.Obj38B8_GetPtrField34")))
char *Obj38B8_GetPtrField34(char *a0) {
    return a0 + 0x34;
}

__attribute__((section(".text.Obj38B8_GetPtrField50")))
char *Obj38B8_GetPtrField50(char *a0) {
    return a0 + 0x50;
}

__attribute__((section(".text.func_0038BE98")))
void *func_0038BE98(void) {
    int *s0 = &D_786778;
    if (!*s0) {
        func_0038C168();
        SetField_0_4_8_31EEA8(s0, &D_0045D360, &D_00460DB0);
    }
    return s0;
}
__attribute__((section(".text.Obj38B8_ReturnOne")))
int Obj38B8_ReturnOne(void) {
    return 1;
}

__attribute__((section(".text.Obj38B8_SetField8")))
void Obj38B8_SetField8(char *a0, int a1) {
    *(int *)(a0 + 8) = a1;
}

__attribute__((section(".text.Obj38B8_GetSelfPtr")))
char *Obj38B8_GetSelfPtr(char *a0) {
    return a0;
}

__attribute__((section(".text.Obj38B8_AndNotByte1A")))
void Obj38B8_AndNotByte1A(char *a0, int a1) {
    a0[0x1A] = (unsigned char)(a0[0x1A] & ~a1);
}
/* func_0038BF38: exchange word 0 and set bit 2 of byte 0x1A when v is zero. */
__attribute__((section(".text.func_0038BF38")))
int func_0038BF38(int *p, unsigned int v) {
    unsigned int t = v < 1;
    int old = p[0];
    p[0] = v;
    *((unsigned char *)p + 0x1A) = t << 2;
    return old;
}
__attribute__((section(".text.Obj38B8_GetField0_v2")))
int Obj38B8_GetField0_v2(char *a0) {
    return *(int *)a0;
}

__attribute__((section(".text.Obj38B8_SetByte1B")))
void Obj38B8_SetByte1B(char *a0, int a1) {
    a0[0x1B] = (unsigned char)a1;
}

__attribute__((section(".text.Obj38B8_GetByte1B")))
unsigned int Obj38B8_GetByte1B(char *a0) {
    return (unsigned char)a0[0x1B];
}

__attribute__((section(".text.Obj38B8_GetByte1A_Mask6")))
unsigned int Obj38B8_GetByte1A_Mask6(char *a0) {
    return (unsigned char)a0[0x1A] & 0x6;
}
/* func_0038BF78: return -1 when byte 0x1A has neither bit 1 nor bit 2. */
__attribute__((section(".text.func_0038BF78")))
unsigned int func_0038BF78(unsigned char *p) {
    return (p[0x1A] & 6) ? 0 : 0xFFFFFFFF;
}
__attribute__((section(".text.Obj38B8_GetByte1A")))
unsigned int Obj38B8_GetByte1A(char *a0) {
    return (unsigned char)a0[0x1A];
}

__attribute__((section(".text.Obj38B8_GetByte1A_Mask4")))
unsigned int Obj38B8_GetByte1A_Mask4(char *a0) {
    return (unsigned char)a0[0x1A] & 4;
}
__attribute__((section(".text.Obj38B8_GetByte1A_Mask6_v2")))
unsigned int Obj38B8_GetByte1A_Mask6_v2(char *a0) {
    return (unsigned char)a0[0x1A] & 6;
}
__attribute__((section(".text.Obj38B8_GetByte1A_Mask1")))
unsigned int Obj38B8_GetByte1A_Mask1(char *a0) {
    return (unsigned char)a0[0x1A] & 1;
}
__attribute__((section(".text.Obj38B8_IsByte1A_Zero")))
unsigned int Obj38B8_IsByte1A_Zero(char *a0) {
    return (unsigned char)a0[0x1A] == 0;
}
__attribute__((section(".text.Obj38B8_OrByte1A")))
void Obj38B8_OrByte1A(char *a0, int a1) {
    a0[0x1A] = (unsigned char)((unsigned char)a0[0x1A] | a1);
}

__attribute__((section(".text.Obj38B8_OrByte1A_v2")))
void Obj38B8_OrByte1A_v2(char *a0, int a1) {
    a0[0x1A] = (unsigned char)((unsigned char)a0[0x1A] | a1);
}
