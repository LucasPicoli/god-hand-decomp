#include "include_asm.h"

/* ------------------------------------------------------------------ */
/* Externs unified across the 7-function D_0044BED0 cluster.          */
/* ------------------------------------------------------------------ */
extern unsigned char *D_003C23A4;  /* 0x003C23A4: pointer in .data */
extern char D_003C2555;                  /* 0x003C2555: 1-byte flag in .data */
extern int D_0044BED0;                   /* 0x0044BED0: first int of rodata table */
extern int D_005FEAC0;                   /* 0x005FEAC0: BSS word */
extern int D_00747A80;                   /* 0x00747A80: BSS word */
extern int D_00747A94;                   /* 0x00747A94: BSS word */
extern int D_00747A98;                   /* 0x00747A98: BSS word */


__attribute__((section(".text.Obj0000_Clear_Fields_50_To_7C_13C5C8")))
void Obj0000_Clear_Fields_50_To_7C_13C5C8(void *a0) {
    char *p = (char *)a0;
    *(int *)(p + 0x50) = 0;
    *(int *)(p + 0x54) = 0;
    *(int *)(p + 0x58) = 0;
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x64) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    *(short *)(p + 0x70) = 0;
    *(short *)(p + 0x72) = 0;
    p[0x74] = 0;
    p[0x75] = 0;
    p[0x76] = 0;
    p[0x77] = 0;
    p[0x78] = 0;
    p[0x79] = 0;
    p[0x7A] = 0;
    p[0x7B] = 0;  /* second-to-last -> delay slot */
    p[0x7C] = 0;  /* last -> scheduled first */
}

INCLUDE_ASM("nonmatching", func_00100000);

__attribute__((section(".text.NoOp_14E768")))
void NoOp_14E768(void) {

}

__attribute__((section(".text.NoOp_14E928")))
void NoOp_14E928(void) {

}

__attribute__((section(".text.NoOp_14E4C8")))
void NoOp_14E4C8(void) {}

__attribute__((section(".text.GetField_2B1_14B638")))
unsigned char GetField_2B1_14B638(unsigned char *arg0) { return arg0[0x2B1]; }

__attribute__((section(".text.SetField_2F4_10BE10")))
void SetField_2F4_10BE10(char *arg0) { arg0[0x2F4] = 0; }

__attribute__((section(".text.Obj0000_Set_Field_8_134648")))
void Obj0000_Set_Field_8_134648(int *arg0, int arg1) { *((int *)((char *)arg0 + 0x8)) = arg1; }

__attribute__((section(".text.SetField_104_13E3F8")))
void SetField_104_13E3F8(char *arg0) { arg0[0x104] = 0; }

__attribute__((section(".text.NoOp_133B98")))
void NoOp_133B98(void) {}

__attribute__((section(".text.NoOp_1352F0")))
void NoOp_1352F0(void) {}

__attribute__((section(".text.NoOp_13C750")))
void NoOp_13C750(void) {}

__attribute__((section(".text.NoOp_13D148")))
void NoOp_13D148(void) {}

__attribute__((section(".text.NoOp_1415E0")))
void NoOp_1415E0(void) {}

__attribute__((section(".text.NoOp_141620")))
void NoOp_141620(void) {}

__attribute__((section(".text.NoOp_146F90")))
void NoOp_146F90(void) {}

__attribute__((section(".text.NoOp_100318")))
void NoOp_100318(void) {}

/* The section attribute pins this function to the `.text.ReturnOne_100320`
 * slot the build-time lcf reserves for it (per-function .text sections
 * are needed for multi-carve TUs). */
__attribute__((section(".text.ReturnOne_100320")))
int ReturnOne_100320(void) { return 1; }

/* 10 matched candidates */
__attribute__((section(".text.Obj0000_Set_Field_424_1595E8")))
void Obj0000_Set_Field_424_1595E8(int *arg0, int arg1) {
    *((int *)((char *)arg0 + 0x424)) = arg1;
}

__attribute__((section(".text.Obj0000_Get_Field_424_1595F0")))
int Obj0000_Get_Field_424_1595F0(int *arg0) {
    return *((int *)((char *)arg0 + 0x424));
}

__attribute__((section(".text.NoOp_15F2A8")))
void NoOp_15F2A8(void) {}

__attribute__((section(".text.NoOp_15FB98")))
void NoOp_15FB98(void) {}

__attribute__((section(".text.NoOp_15FBA0")))
void NoOp_15FBA0(void) {}

__attribute__((section(".text.NoOp_161610")))
void NoOp_161610(void) {}

__attribute__((section(".text.NoOp_161618")))
void NoOp_161618(void) {}

__attribute__((section(".text.NoOp_161620")))
void NoOp_161620(void) {}

__attribute__((section(".text.NoOp_164978")))
void NoOp_164978(void) {}

__attribute__((section(".text.Obj0000_Memset_Backward_366B80")))
void Obj0000_Memset_Backward_366B80(char *a0, int a1, unsigned int a2) {
    signed char c = (signed char)a1;
    unsigned int rem = a2 & 0xF;
    a0 += a2;  /* advance a0 BEFORE the if check (always executes = in delay slot) */
    if (rem) {
        do {
            --a0;
            *a0 = c;
        } while (--rem);
    }
    a2 >>= 4;
    if (a2) {
        do {
            --a0; --a2;
            *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0; *a0 = c;
            --a0;
            *a0 = c;
        } while (a2);
    }
}

/* ====================================================================== */
/* 13 hand-decompiled function bodies                                     */
/* (integration-bug rolled back; manual re-merge here)                    */
/* ====================================================================== */

__attribute__((section(".text.GetField_BEE_2B1290")))
unsigned short GetField_BEE_2B1290(void) {
    return *(unsigned short *)(D_003C23A4 + 0xBEE);
}

__attribute__((section(".text.Obj0000_Set_D_003C2555_One_2B65F0")))
void Obj0000_Set_D_003C2555_One_2B65F0(void) {
    D_003C2555 = 1;
}

/* D_0044BED0 cluster — 7 byte-identical accessor functions */
__attribute__((section(".text.Obj0000_Set_Ptr_Field_100_2BA4D8")))
void Obj0000_Set_Ptr_Field_100_2BA4D8(char *arg0) {
    *(int **)(arg0 + 0x100) = &D_0044BED0;
}

__attribute__((section(".text.Obj0000_Set_Ptr_Field_100_2BA580")))
void Obj0000_Set_Ptr_Field_100_2BA580(char *arg0) {
    *(int **)(arg0 + 0x100) = &D_0044BED0;
}

__attribute__((section(".text.Obj0000_Set_Ptr_Field_100_2BA6E8")))
void Obj0000_Set_Ptr_Field_100_2BA6E8(char *arg0) {
    *(int **)(arg0 + 0x100) = &D_0044BED0;
}

__attribute__((section(".text.Obj0000_Set_Ptr_100_D_0044BED0_2BA818")))
void Obj0000_Set_Ptr_100_D_0044BED0_2BA818(char *arg0) {
    *(int **)(arg0 + 0x100) = &D_0044BED0;
}

__attribute__((section(".text.Obj0000_Set_Ptr_100_D_0044BED0_2BA8D0")))
void Obj0000_Set_Ptr_100_D_0044BED0_2BA8D0(char *arg0) {
    *(int **)(arg0 + 0x100) = &D_0044BED0;
}

__attribute__((section(".text.Obj0000_Set_Field_100_Ptr_D_0044BED0_2BA938")))
void Obj0000_Set_Field_100_Ptr_D_0044BED0_2BA938(char *arg0) {
    *(int **)(arg0 + 0x100) = &D_0044BED0;
}

__attribute__((section(".text.Obj0000_Set_Ptr_Field_100_D_0044BED0_2BAA30")))
void Obj0000_Set_Ptr_Field_100_D_0044BED0_2BAA30(char *arg0) {
    *(int **)(arg0 + 0x100) = &D_0044BED0;
}

__attribute__((section(".text.Obj0000_Set_D_00747A80_Field_70_2BF780")))
void Obj0000_Set_D_00747A80_Field_70_2BF780(int *arg0) {
    D_00747A80 = arg0[0x70 / 4];
}

__attribute__((section(".text.Obj0000_Set_D_005FEAC0_2C23E0")))
int Obj0000_Set_D_005FEAC0_2C23E0(int arg0) {
    D_005FEAC0 = arg0;
    return 0;
}

__attribute__((section(".text.Obj0000_Get_D_00747A94_2DB6B0")))
int Obj0000_Get_D_00747A94_2DB6B0(void) {
    return D_00747A94;
}

__attribute__((section(".text.GetJacket")))
int GetJacket(void) {
    return D_00747A98;
}

__attribute__((section(".text.NoOp_138BB8")))
void NoOp_138BB8(void) {}

__attribute__((section(".text.GetField_54_173900")))
unsigned char GetField_54_173900(unsigned char *a0) {
    return a0[0x54];
}

__attribute__((section(".text.Obj0000_Set_Field_50_173998")))
void Obj0000_Set_Field_50_173998(int *a0, int a1) {
    *(int *)((char *)a0 + 0x50) = a1;
}

__attribute__((section(".text.NoOp_178978")))
void NoOp_178978(void) {}

__attribute__((section(".text.GetField_601_17B810")))
unsigned char GetField_601_17B810(unsigned char *a0) {
    return a0[0x601];
}

__attribute__((section(".text.NoOp_17E2F0")))
void NoOp_17E2F0(void) {}

__attribute__((section(".text.NoOp_17EDC8")))
void NoOp_17EDC8(void) {}

__attribute__((section(".text.NoOp_17F1C8")))
void NoOp_17F1C8(void) {
}

__attribute__((section(".text.NoOp_17FD78")))
void NoOp_17FD78(void) {}

__attribute__((section(".text.GetField_A24_180688")))
int GetField_A24_180688(char *a0) {
    return *(int *)(a0 + 0xA24);
}

__attribute__((section(".text.NoOp_1812B0")))
void NoOp_1812B0(void) {}

__attribute__((section(".text.NoOp_1815A8")))
void NoOp_1815A8(void) {}

__attribute__((section(".text.NoOp_1B35C8")))
void NoOp_1B35C8(void) {}

__attribute__((section(".text.NoOp_1B38C8")))
void NoOp_1B38C8(void) {}

__attribute__((section(".text.NoOp_1B80A8")))
void NoOp_1B80A8(void) {
}

__attribute__((section(".text.GetField_600_1B8640")))
unsigned char GetField_600_1B8640(unsigned char *a0) {
    return a0[0x600];
}

__attribute__((section(".text.SetField_775_1BD778")))
void SetField_775_1BD778(unsigned char *a0) {
    a0[0x775] = 0;
}

__attribute__((section(".text.GetField_774_1BDD90")))
unsigned char GetField_774_1BDD90(unsigned char *a0) {
    return a0[0x774];
}

__attribute__((section(".text.GetField_775_1BDD98")))
unsigned char GetField_775_1BDD98(unsigned char *a0) {
    return a0[0x775];
}

__attribute__((section(".text.NoOp_1BE060")))
void NoOp_1BE060(void) {}

__attribute__((section(".text.NoOp_1BEA18")))
void NoOp_1BEA18(void) {}

__attribute__((section(".text.NoOp_1BFCE0")))
void NoOp_1BFCE0(void) {
}

__attribute__((section(".text.SetField_630_1C2370")))
void SetField_630_1C2370(char *a0) {
    *(int *)(a0 + 0x630) = 0;
}

__attribute__((section(".text.ReturnOne_1C5F40")))
int ReturnOne_1C5F40(void) {
    return 1;
}

__attribute__((section(".text.GetField_68C_1D0C10")))
int GetField_68C_1D0C10(char *a0) {
    return *(int *)(a0 + 0x68C);
}

__attribute__((section(".text.Obj0000_Set_Field_68C_Zero_1D0C18")))
void Obj0000_Set_Field_68C_Zero_1D0C18(int *a0) {
    *(int *)((char *)a0 + 0x68C) = 0;
}

__attribute__((section(".text.NoOp_1D4B70")))
void NoOp_1D4B70(void) {}

__attribute__((section(".text.NoOp_1DCE60")))
void NoOp_1DCE60(void) {}

__attribute__((section(".text.SetField_56_1DEBE8")))
void SetField_56_1DEBE8(char *a0, int a1) {
    a0[0x56] = (char)a1;
}

__attribute__((section(".text.SetField_162C_1ED488")))
void SetField_162C_1ED488(char *a0, int a1) {
    *(int *)(a0 + 0x162C) = a1;
}

__attribute__((section(".text.NoOp_1EF740")))
void NoOp_1EF740(void) {}

__attribute__((section(".text.NoOp_194550")))
void NoOp_194550(void) {
}

__attribute__((section(".text.NoOp_195FE0")))
void NoOp_195FE0(void) {}

__attribute__((section(".text.Obj0000_Get_Field_780_1A50F0")))
int Obj0000_Get_Field_780_1A50F0(int a0) {
    return a0 + 0x780;
}

__attribute__((section(".text.Obj0000_Get_Field_780_1A50F8")))
int Obj0000_Get_Field_780_1A50F8(int a0) {
    return a0 + 0x780;
}

__attribute__((section(".text.NoOp_1A6550")))
void NoOp_1A6550(void) {}

__attribute__((section(".text.NoOp_1A8680")))
void NoOp_1A8680(void) {}

__attribute__((section(".text.NoOp_1A8838")))
void NoOp_1A8838(void) {}

__attribute__((section(".text.NoOp_1A97E0")))
void NoOp_1A97E0(void) {
}

__attribute__((section(".text.GetField_60E_1ADA80")))
unsigned char GetField_60E_1ADA80(unsigned char *a0) {
    return a0[0x60E];
}

__attribute__((section(".text.NoOp_1B0978")))
void NoOp_1B0978(void) {}

__attribute__((section(".text.NoOp_1B0AE0")))
void NoOp_1B0AE0(void) {}

__attribute__((section(".text.NoOp_1B1598")))
void NoOp_1B1598(void) {}

__attribute__((section(".text.NoOp_1B15A0")))
void NoOp_1B15A0(void) {}

__attribute__((section(".text.NoOp_1F0490")))
void NoOp_1F0490(void) {
}

__attribute__((section(".text.NoOp_1F05F0")))
void NoOp_1F05F0(void) {
}

__attribute__((section(".text.NoOp_1F07B8")))
void NoOp_1F07B8(void) {}

__attribute__((section(".text.NoOp_1F0870")))
void NoOp_1F0870(void) {}

__attribute__((section(".text.NoOp_1F0A20")))
void NoOp_1F0A20(void) {
}

__attribute__((section(".text.NoOp_1F0E10")))
void NoOp_1F0E10(void) {
}

__attribute__((section(".text.NoOp_1F1140")))
void NoOp_1F1140(void) {}

__attribute__((section(".text.NoOp_1F15B8")))
void NoOp_1F15B8(void) {}

extern int D_003C80A8;

__attribute__((section(".text.GetD003C80A8_325610")))
int GetD003C80A8_325610(void) {
    return D_003C80A8;
}

extern unsigned char D_00756080[];

__attribute__((section(".text.Obj0000_Get_D_00756080_3306C8")))
unsigned char *Obj0000_Get_D_00756080_3306C8(void) {
    return D_00756080;
}

extern int D_003D9DD8;

__attribute__((section(".text.Obj0000_Set_D_003D9DD8_3331C0")))
void Obj0000_Set_D_003D9DD8_3331C0(int a0) {
    D_003D9DD8 = a0;
}

int D_003DA394;

__attribute__((section(".text.Obj0000_Set_D_003DA394_335348")))
void Obj0000_Set_D_003DA394_335348(int a0) {
    D_003DA394 = a0;
}

extern int D_003E9D5C;

__attribute__((section(".text.GetD003E9D5C_33C718")))
int GetD003E9D5C_33C718(void) {
    return D_003E9D5C;
}

extern unsigned char D_003EC7E0[];

__attribute__((section(".text.GetD003EC7E0_3452B0")))
void *GetD003EC7E0_3452B0(void) {
    return D_003EC7E0;
}

extern int D_003EE078;

__attribute__((section(".text.GetD003EE078_3463F8")))
int GetD003EE078_3463F8(void) {
    return D_003EE078;
}

extern int D_003EE2C0;

__attribute__((section(".text.Obj0000_ReturnD_003EE2C0_34AFE0")))
int Obj0000_ReturnD_003EE2C0_34AFE0(void) {
    return D_003EE2C0;
}

extern int D_003EE2F4;

__attribute__((section(".text.Obj0000_Set_D_003EE2F4_356348")))
void Obj0000_Set_D_003EE2F4_356348(int a0) {
    D_003EE2F4 = a0;
}

int D_003EE2BC;

__attribute__((section(".text.Obj0000_Set_D_003EE2BC_358A28")))
void Obj0000_Set_D_003EE2BC_358A28(int a0) {
    D_003EE2BC = a0;
}


__attribute__((section(".text.ReturnK_003EE2BC_00358A38_358A38")))
int ReturnK_003EE2BC_00358A38_358A38(void) {
    return D_003EE2BC;
}

extern unsigned char D_00459FA8[];

__attribute__((section(".text.Obj0000_Get_D_00459FA8_35F8A8")))
unsigned char *Obj0000_Get_D_00459FA8_35F8A8(void) {
    return D_00459FA8;
}

int D_003EE34C;

__attribute__((section(".text.Obj0000_Set_D_003EE34C_35FC18")))
void Obj0000_Set_D_003EE34C_35FC18(int a0) {
    D_003EE34C = a0;
}


__attribute__((section(".text.Obj0000_Get_D_003EE34C_35FC28")))
int Obj0000_Get_D_003EE34C_35FC28(void) {
    return D_003EE34C;
}

extern int D_003EE804;

__attribute__((section(".text.GetD003EE804_360720")))
int GetD003EE804_360720(void) {
    return D_003EE804;
}

extern unsigned char D_0045A1B0[];

__attribute__((section(".text.Obj0000_Get_D_0045A1B0_360790")))
unsigned char *Obj0000_Get_D_0045A1B0_360790(void) {
    return D_0045A1B0;
}

long long D_003EEA70;

__attribute__((section(".text.Obj0000_Get_D_003EEA70_360C58")))
long long Obj0000_Get_D_003EEA70_360C58(void) {
    return D_003EEA70;
}

long long D_003EEA70;

__attribute__((section(".text.Obj0000_Set_D_003EEA70_360C80")))
void Obj0000_Set_D_003EEA70_360C80(long long a0) {
    D_003EEA70 = a0;
}

extern char D_003EEA90[];

__attribute__((section(".text.GetD003EEA90_360D18")))
char *GetD003EEA90_360D18(void) {
    return D_003EEA90;
}

extern char D_003EEA98[];

__attribute__((section(".text.Obj0000_Get_D_003EEA98_365EB0")))
void *Obj0000_Get_D_003EEA98_365EB0(void) {
    return D_003EEA98;
}

extern int D_003F1FF0;

__attribute__((section(".text.Obj0000_Get_D_003F1FF0_36CCA8")))
int Obj0000_Get_D_003F1FF0_36CCA8(void) {
    return D_003F1FF0;
}

extern unsigned char D_0045A478[];

__attribute__((section(".text.Obj0000_Get_D_0045A478_36D0E8")))
unsigned char *Obj0000_Get_D_0045A478_36D0E8(void) {
    return D_0045A478;
}

extern int D_0076A7A4;

__attribute__((section(".text.Obj0000_Get_D_0076A7A4_3756F0")))
int Obj0000_Get_D_0076A7A4_3756F0(void) {
    return D_0076A7A4;
}

extern unsigned char D_003F8560[];

__attribute__((section(".text.GetD003F8560_395388")))
unsigned char *GetD003F8560_395388(void) {
    return D_003F8560;
}

int *D_003FA62C;

__attribute__((section(".text.Obj0000_Get_D_003FA62C_3A4FB8")))
int Obj0000_Get_D_003FA62C_3A4FB8(void) {
    return (int)D_003FA62C;
}

extern unsigned char D_0045FB80[];

__attribute__((section(".text.Obj0000_Get_D_0045FB80_3AD118")))
unsigned char *Obj0000_Get_D_0045FB80_3AD118(void) {
    return D_0045FB80;
}

extern int D_003C80A4;

__attribute__((section(".text.Obj0000_Get_D_003C80A4_NE_0_325620")))
int Obj0000_Get_D_003C80A4_NE_0_325620(void) {
    return D_003C80A4 != 0;
}

typedef signed char signed char;
typedef unsigned char unsigned char;
typedef signed short short;
typedef unsigned short unsigned short;
typedef signed int int;
typedef unsigned int unsigned int;
typedef signed long long long long;
typedef unsigned long long unsigned long long;
typedef float f32;
typedef double f64;
typedef int M2C_UNK;
typedef signed char M2C_UNK8;
typedef short M2C_UNK16;
typedef int M2C_UNK32;
typedef long long M2C_UNK64;
typedef struct CGUnk_0013C5C8
{
  unsigned char unk[0xA0];
} CGUnk_0013C5C8_t;
typedef struct CGUnk_0010B5C8
{
  unsigned char unk[0x300];
} CGUnk_0010B5C8_t;
typedef struct CGListNode_001346C8
{
  unsigned char unk[0x20];
} CGListNode_001346C8_t;
typedef struct CGUnk_0013E3F8
{
  unsigned char unk[0x110];
} CGUnk_0013E3F8_t;
typedef struct CGUnk_00134648
{
  unsigned char unk[0x10];
} CGUnk_00134648_t;
typedef struct CGObj293
{
  unsigned char unk[0x590];
} CGObj293_t;
extern unsigned char cMcLoaderState[0x1108];
typedef struct CGObj38B8
{
  unsigned char unk[0x60];
} CGObj38B8_t;
extern volatile int D_003D848C;
__attribute__((section(".text.GetD003D848C_3313E0")))
int GetD003D848C_3313E0(void)
{
  return D_003D848C;
}

extern volatile int D_003D8488;
__attribute__((section(".text.Obj0000_Set_D_003D8488_3313F0")))
void Obj0000_Set_D_003D8488_3313F0(int a0)
{
  D_003D8488 = a0;
}


__attribute__((section(".text.Obj0000_Set_D_003EE2C0_34B290")))
int Obj0000_Set_D_003EE2C0_34B290(int a0) {
    D_003EE2C0 = a0;
    return 0;
}

extern int D_0076B080;

__attribute__((section(".text.Obj0000_Set_D_0076B080_Field_A4_3754F0")))
void Obj0000_Set_D_0076B080_Field_A4_3754F0(void *arg0) {
    D_0076B080 = *(int *)((char *)arg0 + 0xA4);
}

extern char D_003C2554;

__attribute__((section(".text.Obj0000_Clear_Bytes_D_003C2554_D_003C2555_2B6598")))
void Obj0000_Clear_Bytes_D_003C2554_D_003C2555_2B6598(void) {
    D_003C2555 = 0;
    D_003C2554 = 0;
}

extern int D_00747A44;

__attribute__((section(".text.Obj0000_Store_D_00747A44_2BE968")))
int *Obj0000_Store_D_00747A44_2BE968(int *arg0) {
    *arg0 = D_00747A44;
    return arg0;
}

extern void *D_0044D388;

__attribute__((section(".text.Obj0000_Set_Vtbl_D_0044D388_2D9E18")))
void *Obj0000_Set_Vtbl_D_0044D388_2D9E18(void **a0) {
    *a0 = &D_0044D388;
    return a0;
}

extern int D_00451008;

__attribute__((section(".text.Obj0000_Set_Vtbl_D_00451008_31F360")))
void *Obj0000_Set_Vtbl_D_00451008_31F360(void **a0) {
    *a0 = &D_00451008;
    return a0;
}

extern int D_00451020;

__attribute__((section(".text.Obj0000_Set_Ptr_VTable_D_00451020_31F3F8")))
void *Obj0000_Set_Ptr_VTable_D_00451020_31F3F8(void *arg0) {
    *(int **)arg0 = &D_00451020;
    return arg0;
}

extern int D_00451270;

__attribute__((section(".text.Obj0000_Set_Vtbl_D_00451270_321848")))
void *Obj0000_Set_Vtbl_D_00451270_321848(void **a0) {
    *a0 = &D_00451270;
    return a0;
}

extern int D_00451288;

__attribute__((section(".text.Obj0000_Set_Vtbl_00451288_3218E0")))
void *Obj0000_Set_Vtbl_00451288_3218E0(void *a0) {
    *(int **)a0 = &D_00451288;
    return a0;
}

int D_003D1410;
int D_003D1414;

__attribute__((section(".text.Obj0000_Set_D_003D1410_And_D_003D1414_32AB58")))
void Obj0000_Set_D_003D1410_And_D_003D1414_32AB58(int a0) {
    D_003D1410 = a0;
    D_003D1414 = a0;
}

extern int D_003D90D4;
extern int D_003D90D8;

__attribute__((section(".text.Obj0000_Set_D_003D90D4_D_003D90D8_3329D0")))
void Obj0000_Set_D_003D90D4_D_003D90D8_3329D0(int a0, int a1) {
    D_003D90D4 = a0;
    D_003D90D8 = a1;
}

extern int D_003D9F6C;
extern int D_003D9F70;

__attribute__((section(".text.Obj0000_Set_D_003D9F6C_D_003D9F70_334230")))
void Obj0000_Set_D_003D9F6C_D_003D9F70_334230(int a0, int a1) {
    D_003D9F6C = a0;
    D_003D9F70 = a1;
}

extern int D_003DECFC;
extern int D_003DED00;

__attribute__((section(".text.Obj0000_Set_D_003DECFC_D_003DED00_3364F8")))
void Obj0000_Set_D_003DECFC_D_003DED00_3364F8(int a0, int a1) {
    D_003DECFC = a0;
    D_003DED00 = a1;
}

extern int D_007588A0[2];

__attribute__((section(".text.Obj0000_Set_D_007588A0_Pair_33BC18")))
void Obj0000_Set_D_007588A0_Pair_33BC18(int a0, int a1) {
    D_007588A0[0] = a0;
    D_007588A0[1] = a1;
}

struct {
    int x;
    int y;
} D_007588A8;

__attribute__((section(".text.Obj0000_Set_D_007588A8_XY_33BC30")))
void Obj0000_Set_D_007588A8_XY_33BC30(int a0, int a1) {
    D_007588A8.x = a0;
    D_007588A8.y = a1;
}

extern int D_007588C0[2];

__attribute__((section(".text.Obj0000_Set_D_007588C0_Fields_0_1_33BF88")))
void Obj0000_Set_D_007588C0_Fields_0_1_33BF88(int a0, int a1) {
    D_007588C0[0] = a0;
    D_007588C0[1] = a1;
}

extern int D_007588C8[2];

__attribute__((section(".text.Obj0000_Set_D_007588C8_Args_0_1_33BFA0")))
void Obj0000_Set_D_007588C8_Args_0_1_33BFA0(int a0, int a1) {
    D_007588C8[0] = a0;
    D_007588C8[1] = a1;
}

extern int D_003EC454;
extern int D_003EC458;

__attribute__((section(".text.Obj0000_Set_D_003EC454_D_003EC458_340438")))
void Obj0000_Set_D_003EC454_D_003EC458_340438(int a0, int a1) {
    D_003EC454 = a0;
    D_003EC458 = a1;
}

extern unsigned char D_003EE088[];

__attribute__((section(".text.Obj0000_Get_Ptr_D_003EE088_Scaled_8_348920")))
void *Obj0000_Get_Ptr_D_003EE088_Scaled_8_348920(int a0) {
    return (void *)(D_003EE088 + a0 * 8);
}

extern int D_003EE340[2];

__attribute__((section(".text.Obj0000_Set_D_003EE340_Args_0_1_35F958")))
void Obj0000_Set_D_003EE340_Args_0_1_35F958(int a0, int a1) {
    D_003EE340[0] = a0;
    D_003EE340[1] = a1;
}

extern unsigned char D_003BAFE0[];

__attribute__((section(".text.Obj0000_Set_Field_80_372C68")))
void *Obj0000_Set_Field_80_372C68(void *arg0) {
    *(void **)((unsigned char *)arg0 + 0x80) = (void *)D_003BAFE0;
    return arg0;
}

extern int D_003FC7AC;
extern int D_003FC7B0;

__attribute__((section(".text.Obj0000_Set_D_003FC7AC_D_003FC7B0_3B9D98")))
void Obj0000_Set_D_003FC7AC_D_003FC7B0_3B9D98(int a0, int a1) {
    D_003FC7AC = a0;
    D_003FC7B0 = a1;
}


__attribute__((section(".text.Obj0000_IsSet_D_00747A80_Bit_10000000_2B8978")))
unsigned int Obj0000_IsSet_D_00747A80_Bit_10000000_2B8978(void) {
    unsigned int v = D_00747A80 & 0x10000000U;
    return (unsigned int)(0U < v);
}

extern int D_00450FF0;

__attribute__((section(".text.Obj0000_Setup_Fields_00_01_D_00450FF0_31F2A8")))
int *Obj0000_Setup_Fields_00_01_D_00450FF0_31F2A8(int *a0, int a1) {
    a0[0] = a1;
    a0[1] = (int)&D_00450FF0;
    return a0;
}

extern int D_00451038;

__attribute__((section(".text.Obj0000_Set_Fields_00_01_D_00451038_31F488")))
int *Obj0000_Set_Fields_00_01_D_00451038_31F488(int *a0, int a1) {
    a0[0] = a1;
    a0[1] = (int)&D_00451038;
    return a0;
}

extern int D_003EB308[];

__attribute__((section(".text.Obj0000_Get_D_003EB308_Plus10_By_Index_324808")))
int Obj0000_Get_D_003EB308_Plus10_By_Index_324808(int a0) {
    return D_003EB308[a0] + 0x10;
}

extern long long D_003C8100;

__attribute__((section(".text.Obj0000_Increment_D_003C8100_324E98")))
void Obj0000_Increment_D_003C8100_324E98(void) {
    D_003C8100 += 1;
}

extern int D_003D04CC;

__attribute__((section(".text.Obj0000_PostInc_D_003D04CC_3284A0")))
int Obj0000_PostInc_D_003D04CC_3284A0(void) {
    return ++D_003D04CC;
}

int D_003D1428;

__attribute__((section(".text.Obj0000_PostInc_D_003D1428_32A148")))
int Obj0000_PostInc_D_003D1428_32A148(void) {
    return ++D_003D1428;
}

int D_003D84B0;

__attribute__((section(".text.Obj0000_Increment_D_003D84B0_3320E0")))
void Obj0000_Increment_D_003D84B0_3320E0(void) {
    D_003D84B0 += 1;
}


__attribute__((section(".text.Obj0000_Get_D_003EEA70_LT_2_360C40")))
int Obj0000_Get_D_003EEA70_LT_2_360C40(void) {
    return (unsigned long long)D_003EEA70 < 2;
}

extern int D_003C4F00;

__attribute__((section(".text.Obj0000_Swap_D_003C4F00_321218")))
int Obj0000_Swap_D_003C4F00_321218(int a0) {
    unsigned long v0 = D_003C4F00;
    int new_var;
    new_var = v0;
    D_003C4F00 = a0;
    return new_var;
}

extern int D_003E3A80;

__attribute__((section(".text.Obj0000_PostInc_D_003E3A80_338960")))
int Obj0000_PostInc_D_003E3A80_338960(void) {
    return ++D_003E3A80;
}


__attribute__((section(".text.Obj0000_Decrement_D_003E3A80_338978")))
void Obj0000_Decrement_D_003E3A80_338978(void) {
    D_003E3A80--;
}

int D_003EC450;

__attribute__((section(".text.Obj0000_PreDec_D_003EC450_340520")))
int Obj0000_PreDec_D_003EC450_340520(void) {
    return --D_003EC450;
}

extern int D_003FC50C;

__attribute__((section(".text.Obj0000_PostInc_D_003FC50C_3B9D68")))
int Obj0000_PostInc_D_003FC50C_3B9D68(void) {
    return ++D_003FC50C;
}


__attribute__((section(".text.Obj0000_PreDec_D_003FC50C_3B9D80")))
int Obj0000_PreDec_D_003FC50C_3B9D80(void) {
    return --D_003FC50C;
}

typedef struct {
    unsigned char unk[0x5D8];
    int field_5D8;
    unsigned char pad[4];
    int field_5E0;
} CGUnk_007474A0_t;

extern CGUnk_007474A0_t D_007474A0;

__attribute__((section(".text.Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0")))
void Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(unsigned char *a0) {
    *(int *)(a0 + 0x68) = D_007474A0.field_5D8;
    *(int *)(a0 + 0x6C) = D_007474A0.field_5E0;
}

extern unsigned char *D_003BD6E8;

__attribute__((section(".text.Obj0000_Clear_Byte_D_003BD6E8_1380_94_Bit0_1F75B0")))
void Obj0000_Clear_Byte_D_003BD6E8_1380_94_Bit0_1F75B0(void) {
    unsigned char *base = D_003BD6E8 + 0x1380;
    base[0x94] = base[0x94] & 0xFE;
}

extern int D_00747A0C;

__attribute__((section(".text.Obj0000_Set_Field_178_D_00747A0C_1F9E90")))
void Obj0000_Set_Field_178_D_00747A0C_1F9E90(int **a0) {
    int *ptr = *a0;
    if (ptr == 0) return;
    *(int *)((char *)ptr + 0x178) = D_00747A0C;
}


__attribute__((section(".text.Obj0000_Set_D_00747A0C_Field_178_If_NonNull_1F9EB0")))
void Obj0000_Set_D_00747A0C_Field_178_If_NonNull_1F9EB0(int **a0) {
    int *ptr = *a0;
    if (ptr != 0) {
        D_00747A0C = *(int *)((char *)ptr + 0x178);
    }
}


__attribute__((section(".text.Obj0000_Get_D_003C23A4_By_Short_A1p2_2B1270")))
int Obj0000_Get_D_003C23A4_By_Short_A1p2_2B1270(int a0, unsigned char *a1) {
    unsigned int idx = (unsigned int)(*(unsigned short *)(a1 + 2)) << 2;
    return *(int *)((unsigned char *)D_003C23A4 + idx + 0xBDC);
}

__attribute__((section(".text.func_003951B0")))
void func_003951B0(void) {
    __asm__ volatile("nop; nop");
}

__attribute__((section(".text.func_003951C0")))
void func_003951C0(void) {
    __asm__ volatile("nop; nop");
}

__attribute__((section(".text.func_003951D0")))
void func_003951D0(void) {
    __asm__ volatile("nop; nop");
}

__attribute__((section(".text.Obj0000_Set_Byte_54")))
void Obj0000_Set_Byte_54(char *arg0, int arg1) {
    arg0[0x54] = arg1;
}

extern unsigned char D_0061B670;

__attribute__((section(".text.Obj0000_Get_Byte_D_0061B670")))
int Obj0000_Get_Byte_D_0061B670(void) {
    return D_0061B670;
}

__attribute__((section(".text.Obj0000_Set_Byte_2F5_If_Field_618_GE_29")))
void Obj0000_Set_Byte_2F5_If_Field_618_GE_29(CGUnk_0010B5C8_t *arg0)
{
  if ((*((int *) (((unsigned char *) arg0) + 0x618))) >= 0x29)
  {
    *(((unsigned char *) arg0) + 0x2F7) = 0;
 do { *(((unsigned char *) arg0) + 0x2F5) = 1; *(((unsigned char *) arg0) + 0x2F6) = 0; } while (0);
  }
}

__attribute__((section(".text.Obj0000_Clear_Field_28_And_Ptr4_Field_30_34")))
void Obj0000_Clear_Field_28_And_Ptr4_Field_30_34(char *a0) {
    char *ptr = *(char * volatile *)(a0 + 0x4);
    if (ptr == 0) return;
    *(int *)(a0 + 0x28) = 0;
    *(int *)(ptr + 0x30) = 0;
    ptr = *(char * volatile *)(a0 + 0x4);
    *(int *)(ptr + 0x34) = 0;
}

extern int D_003D8408;
void func_003302B0(void *, void *, int);

__attribute__((section(".text.Tramp_003302B0_003302E0")))
void Tramp_003302B0_003302E0(void *a0) {
    func_003302B0(&D_003D8408, a0, 0);
}

__attribute__((section(".text.Tramp_003A52F0_00333AD8")))
void Tramp_003A52F0_00333AD8(void) {
    extern void func_003A52F0(void *a0, int a1, int a2);
    extern char D_003D9DC0[];
    func_003A52F0(D_003D9DC0, 0, 0x10);
}

extern void (*D_003E9D30)(void);

__attribute__((section(".text.Tramp_003E9D30_0033C4C0")))
void Tramp_003E9D30_0033C4C0(void) {
    D_003E9D30();
}

typedef struct CGUnk_00343E00 { unsigned char unk[0x1D0]; } CGUnk_00343E00_t;

extern void func_003395A0(int a0, int a1, int a2);

__attribute__((section(".text.Obj0000_Call_003395A0_Field_1C4_1C8_1CC")))
void Obj0000_Call_003395A0_Field_1C4_1C8_1CC(CGUnk_00343E00_t *arg0) {
    int a0 = *(int *)((unsigned char *)arg0 + 0x1C4);
    int a1 = *(int *)((unsigned char *)arg0 + 0x1C8);
    int a2 = *(int *)((unsigned char *)arg0 + 0x1CC);
    func_003395A0(a0, a1, a2);
}

extern int SFD_SetCond(int);

__attribute__((section(".text.Obj0000_Call_00359EC0_Field_3C")))
int Obj0000_Call_00359EC0_Field_3C(int *a0) {
    int v0 = 0;
    if (a0 != 0) {
        v0 = *(int *)((char *)a0 + 0x3C);
    }
    return SFD_SetCond(v0);
}

extern int SFD_GetCond(int);

__attribute__((section(".text.Obj0000_Call_0035A128_Field_3C")))
int Obj0000_Call_0035A128_Field_3C(unsigned char *arg0) {
    int v0;
    if (arg0 == 0) {
        v0 = 0;
    } else {
        v0 = *(int *)(arg0 + 0x3C);
    }
    return SFD_GetCond(v0);
}

extern void func_00328C80(void *);

__attribute__((section(".text.Obj0000_Call_00328C80_If_NonNull")))
void Obj0000_Call_00328C80_If_NonNull(void *arg0) {
    if (arg0 == 0) {
        return;
    }
    func_00328C80(arg0);
}

extern void func_0034C378();

__attribute__((section(".text.Obj0000_Call_0034C378_Field_1F44")))
void Obj0000_Call_0034C378_Field_1F44(unsigned char *a0, void *a1, void *a2)
{
    func_0034C378(a0, *(int *)(a0 + 0x1F44), a1, a2);
}

__attribute__((section(".text.Obj0000_Set_Field_E48_If_Field_E6C_NE_MAX")))
void Obj0000_Set_Field_E48_If_Field_E6C_NE_MAX(unsigned char *a0) {
    unsigned char *ptr = a0 + 0xE48;
    if (*(int *)(ptr + 0x24) == 0x7FFFFFFF) return;
    *(int *)(ptr) = 1;
}

__attribute__((section(".text.scTag2")))
void scTag2(unsigned long long *a0, unsigned int a1, unsigned int a2, unsigned int a3) {
    *a0 = ((unsigned long long)a1 << 32) | ((unsigned long long)a2 << 28) | (unsigned long long)a3;
}

__attribute__((section(".text.Obj0000_Get_Field_44_LT_1_If_Field_48_In_1_4")))
int Obj0000_Get_Field_44_LT_1_If_Field_48_In_1_4(unsigned char *a0) {
    int v1 = *(int *)(a0 + 0x48);
    if ((unsigned int)(v1 - 1) >= 4) {
        return 1;
    }
    return (unsigned int)*(int *)(a0 + 0x44) < 1;
}

extern int D_00766CD8;

__attribute__((section(".text.MPSLIB_CheckHn")))
int MPSLIB_CheckHn(int *a0) {
    int v1;
    int v0;
    D_00766CD8 = (int)a0;
    if (a0 == 0) {
        return -1;
    }
    v1 = *a0 ^ 1;
    v0 = -1;
    if (v1 != 0) {
        v0 = 0;
    }
    return v0;
}

__attribute__((section(".text.Obj0000_Set_Field_3BC_Triple")))
void Obj0000_Set_Field_3BC_Triple(unsigned char *a0, int a1, int a2, int a3, int a4) {
    int *p = (int *)(a0 + 0x3BC + a1 * 12);
    p[0] = a2;
    p[1] = a3;
    p[2] = a4;
}

__attribute__((section(".text.Tramp_003356B0_00335610")))
void Tramp_003356B0_00335610(int a0, int a1) {
    func_003356B0(a0, a1, 0, 0, 0xFFFFF);
}

extern void *D_00766D44;

__attribute__((section(".text.Obj0000_Set_D_00766D44_Check_Field_188_NE_2")))
int Obj0000_Set_D_00766D44_Check_Field_188_NE_2(int *a0) {
    D_00766D44 = (void *)a0;
    if (a0 == 0) {
        return -1;
    }
    return (*(int *)((char *)a0 + 0x188) ^ 2) == 0 ? 0 : -1;
}

extern int func_0036CD98(int);

__attribute__((section(".text.Obj0000_Get_Field_3B4_Via_func_0036CD98")))
int Obj0000_Get_Field_3B4_Via_func_0036CD98(unsigned char *a0) {
    int v0 = 0;
    if (a0 != 0) {
        v0 = *(int *)(a0 + 0x3B4);
    }
    return func_0036CD98(v0);
}

extern int *D_0076A5D8;

__attribute__((section(".text.Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2")))
int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(int *a0) {
    int v1;
    D_0076A5D8 = (int *)a0;
    if (a0 == 0) {
        return -1;
    }
    v1 = *a0 ^ 0x2;
    return v1 == 0 ? 0 : -1;
}

__attribute__((section(".text.Obj0000_Set_Field_11C_Triple")))
void Obj0000_Set_Field_11C_Triple(unsigned char *a0, int a1, int a2, int a3, int a4) {
    int *entry = (int *)(a0 + 0x11C + a1 * 12);
    entry[0] = a2;
    entry[1] = a3;
    entry[2] = a4;
}

typedef struct CGUnk_00180310
{
  unsigned char unk[0xA28];
} CGUnk_00180310_t;
__attribute__((section(".text.Obj0000_Set_Short_88_If_LT_1000")))
void Obj0000_Set_Short_88_If_LT_1000(void *a0, short a1) {
    if ((unsigned short)a1 < 1000) {
        *(short *)((signed char *)(*(void **)a0) + 0x88) = a1;
    }
}

__attribute__((section(".text.Obj0000_Set_D_003FAE30_Field_10_Zero")))
void Obj0000_Set_D_003FAE30_Field_10_Zero(void) {
    extern char D_003FAE30[];
    *(int *)(D_003FAE30 + 0x10) = 0;
}

__attribute__((section(".text.Tramp_001F7DF8_00101E28"))) void Tramp_001F7DF8_00101E28(void)
{
 do { capVu0Length(); } while (0);
}

__attribute__((section(".text.Tramp_func_0014EA50_0010B760"))) void Tramp_func_0014EA50_0010B760(void)
{
 do { cObjBase_R0_scenario(); } while (0);
}

__attribute__((section(".text.Tramp_func_0014EFA8_0012BBE0")))
void Tramp_func_0014EFA8_0012BBE0(void)
{
 do { cObjBase_KageDraw(); } while (0);
}

__attribute__((section(".text.Tramp_func_002AAC28_0013C508"))) void Tramp_func_002AAC28_0013C508(void)
{
 do { cIDBase_trans(); } while (0);
}

__attribute__((section(".text.Tramp_func_0030A548_00147528"))) void Tramp_func_0030A548_00147528(void)
{
  func_0030A548();
 do { } while (0);
}

void func_0030A2E0(void);
__attribute__((section(".text.Tramp_func_0030A2E0_00147548"))) void Tramp_func_0030A2E0_00147548(void)
{
  func_0030A2E0();
 do { } while (0);
}

__attribute__((section(".text.Tramp_func_0030A2B0_001508D8"))) void Tramp_func_0030A2B0_001508D8(void)
{
  sceVu0ApplyMatrix();
 do { } while (0);
}

__attribute__((section(".text.Tramp_func_0015B0F0_0015B080_15B080")))
void Tramp_func_0015B0F0_0015B080_15B080(void)
{
  PostInc_D_00566E10_0015B0F0_15B0F0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_0015B0C0_0015B0A0")))
void Tramp_func_0015B0C0_0015B0A0(void)
{
 do { func_0015B0C0(); } while (0);
}

__attribute__((section(".text.Obj0000_Call_func_0015FD18_Field_48_161288"))) void Obj0000_Call_func_0015FD18_Field_48_161288(unsigned char *a0)
{
 do { func_0015FD18(a0, *((int *) (0x48 + a0))); } while (0);
}

__attribute__((section(".text.Tramp_func_0015FF10_001612A8_1612A8")))
void Tramp_func_0015FF10_001612A8_1612A8(void)
{
  func_0015FF10();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_002AAC28_00161970_161970")))
void Tramp_func_002AAC28_00161970_161970(void)
{
  cIDBase_trans();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001614D0_00161BB0_161BB0")))
void Tramp_func_001614D0_00161BB0_161BB0(void)
{
  ClearFields_1614D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_002AAC28_00162278_162278")))
void Tramp_func_002AAC28_00162278_162278(void)
{
  cIDBase_trans();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001614D0_00166618_166618")))
void Tramp_func_001614D0_00166618_166618(void)
{
  ClearFields_1614D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001614D0_001673B0_1673B0")))
void Tramp_func_001614D0_001673B0_1673B0(void)
{
  ClearFields_1614D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_002AAC28_001682A8_1682A8")))
void Tramp_func_002AAC28_001682A8_1682A8(void)
{
  cIDBase_trans();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_0016F5E8_16F5E8")))
void Tramp_func_001C29D0_0016F5E8_16F5E8(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Obj0000_Set_Short_202")))
void Obj0000_Set_Short_202(unsigned char *a0)
{
  do { func_0016B1F8(a0, *((short *) (0x202 + a0))); } while (0);
}

__attribute__((section(".text.Obj0000_Set_Short_204")))
void Obj0000_Set_Short_204(unsigned char *a0)
{
    do { func_0016B1F8(a0, *((short *)(a0 + 0x204))); } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_0016F8E0")))
void Tramp_func_001C29D0_0016F8E0(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_0016FBD8")))
void Tramp_func_001C29D0_0016FBD8(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_0016FE48")))
void Tramp_func_001C29D0_0016FE48(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00170130")))
void Tramp_func_001C29D0_00170130(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00170418")))
void Tramp_func_001C29D0_00170418(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BFB80_001706E0")))
void Tramp_func_001BFB80_001706E0(void)
{
  func_001BFB80();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BFB80_00170970")))
void Tramp_func_001BFB80_00170970(void)
{
  func_001BFB80();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BFB80_00170C00")))
void Tramp_func_001BFB80_00170C00(void)
{
  func_001BFB80();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BFB80_00170E90")))
void Tramp_func_001BFB80_00170E90(void)
{
  func_001BFB80();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BFB80_00171000")))
void Tramp_func_001BFB80_00171000(void)
{
  func_001BD6B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_001717A0")))
void Tramp_func_001B79B0_001717A0(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BD6B0_00171C20")))
void Tramp_func_001BD6B0_00171C20(void)
{
  func_001BD6B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_00173198")))
void Tramp_func_001B79B0_00173198(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_001741E8")))
void Tramp_func_001B79B0_001741E8(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_00174FB0")))
void Tramp_func_001B79B0_00174FB0(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_00176738")))
void Tramp_func_001B79B0_00176738(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_00177DC0")))
void Tramp_func_001B79B0_00177DC0(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_001784F8")))
void Tramp_func_001C29D0_001784F8(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_001787A0")))
void Tramp_func_001C29D0_001787A0(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_001789F8")))
void Tramp_func_001B79B0_001789F8(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00178CC0")))
void Tramp_func_001C29D0_00178CC0(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00178F58")))
void Tramp_func_001C29D0_00178F58(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_00179798")))
void Tramp_func_001B79B0_00179798(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0017A508")))
void Tramp_func_001B79B0_0017A508(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0017B548")))
void Tramp_func_001B79B0_0017B548(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0017C008")))
void Tramp_func_001B79B0_0017C008(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BD6B0_0017C5B0")))
void Tramp_func_001BD6B0_0017C5B0(void)
{
  func_001BD6B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0017CE18")))
void Tramp_func_001B79B0_0017CE18(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BC0A0_0017D560")))
void Tramp_func_001BC0A0_0017D560(void)
{
  func_001BC0A0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0017DB40")))
void Tramp_func_001B79B0_0017DB40(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0017E658")))
void Tramp_func_001B79B0_0017E658(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BC0A0_0017EA28")))
void Tramp_func_001BC0A0_0017EA28(void)
{
  func_001BC0A0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BD6B0_0017EB98")))
void Tramp_func_001BD6B0_0017EB98(void)
{
  func_001BD6B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0017EDD0")))
void Tramp_func_001B79B0_0017EDD0(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0017F1D0")))
void Tramp_func_001B79B0_0017F1D0(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BC0A0_0017F470")))
void Tramp_func_001BC0A0_0017F470(void)
{
  func_001BC0A0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0017F990")))
void Tramp_func_001B79B0_0017F990(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0017FD80")))
void Tramp_func_001B79B0_0017FD80(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_001815B0")))
void Tramp_func_001B79B0_001815B0(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BC0A0_001817C8")))
void Tramp_func_001BC0A0_001817C8(void)
{
  func_001BC0A0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_00182020")))
void Tramp_func_001B79B0_00182020(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00182818")))
void Tramp_func_001C29D0_00182818(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_00182FD8")))
void Tramp_func_001B79B0_00182FD8(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BFB80_001834F0")))
void Tramp_func_001BFB80_001834F0(void)
{
  func_001BFB80();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_001837D8")))
void Tramp_func_001C29D0_001837D8(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_00184A20")))
void Tramp_func_001B79B0_00184A20(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_0014EFA8_001866A0")))
void Tramp_func_0014EFA8_001866A0(void)
{
  cObjBase_KageDraw();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BC0A0_00186928")))
void Tramp_func_001BC0A0_00186928(void)
{
  func_001BC0A0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_00187190")))
void Tramp_func_001B79B0_00187190(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00187958")))
void Tramp_func_001C29D0_00187958(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00187C18")))
void Tramp_func_001C29D0_00187C18(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_00188528")))
void Tramp_func_001B79B0_00188528(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00188C88")))
void Tramp_func_001C29D0_00188C88(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00188F10")))
void Tramp_func_001C29D0_00188F10(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0018A110")))
void Tramp_func_001B79B0_0018A110(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0018AD88")))
void Tramp_func_001B79B0_0018AD88(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0018BAA0")))
void Tramp_func_001B79B0_0018BAA0(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0018C8A8")))
void Tramp_func_001B79B0_0018C8A8(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0018D698")))
void Tramp_func_001B79B0_0018D698(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0018E450")))
void Tramp_func_001B79B0_0018E450(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_0018EC28")))
void Tramp_func_001C29D0_0018EC28(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BFB80_0018EE38")))
void Tramp_func_001BFB80_0018EE38(void)
{
  func_001BFB80();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BC0A0_0018F0A0")))
void Tramp_func_001BC0A0_0018F0A0(void)
{
  func_001BC0A0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_0018FBF0")))
void Tramp_func_001B79B0_0018FBF0(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_001915B8")))
void Tramp_func_001B79B0_001915B8(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00191CC8")))
void Tramp_func_001C29D0_00191CC8(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BC0A0_00191F30")))
void Tramp_func_001BC0A0_00191F30(void)
{
  func_001BC0A0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001BC0A0_00192198")))
void Tramp_func_001BC0A0_00192198(void)
{
  func_001BC0A0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001B79B0_001928B0")))
void Tramp_func_001B79B0_001928B0(void)
{
  Tramp_00312708_1B79B0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00192BC8")))
void Tramp_func_001C29D0_00192BC8(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00192EF8")))
void Tramp_func_001C29D0_00192EF8(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Tramp_func_001C29D0_00193180")))
void Tramp_func_001C29D0_00193180(void)
{
  func_001C29D0();
  do { } while (0);
}

__attribute__((section(".text.Obj0000_Set_Fields_1EC_280_Zero")))
void Obj0000_Set_Fields_1EC_280_Zero(unsigned char *a0, unsigned char *a1)
{
    int v1 = *(int *)(a1 + 0x18);
    int *p = (int *)(a0 + 0x1EC);
    int a2 = *(int *)(a1 + 0x1C);
    int *q = (int *)(a0 + 0x280);
    int i = 0x1F;

    p[0] = v1;
    p[1] = a2;
    p[2] = *(int *)(a1 + 0x18);
    p[3] = 0;
    *(int *)(a0 + 0x200) = 0;

    do {
        i = i - 1;
        *q = 0;
        q = q - 1;
    } while (i >= 0);
}

typedef struct {
    void **vtbl;
} ObjVT;

__attribute__((section(".text.Obj0000_Call_Vtbl6_Vtbl8_Field_1_0034C680")))
int Obj0000_Call_Vtbl6_Vtbl8_Field_1_0034C680(ObjVT *obj, int a1, int a2) {
    int local[2];
    int s1 = (unsigned int)a1 < 1U;
    ((void (*)(ObjVT *, int, int, int *))obj->vtbl[6])(obj, a1, a2, local);
    ((void (*)(ObjVT *, int, int *))obj->vtbl[8])(obj, s1, local);
    return local[1];
}

void __sread(void);
void __swrite(void);
void __sseek(void);
void func_003A6EC8(void);

typedef struct {
    int unk_00;      /* 0x00 */
    int unk_04;      /* 0x04 */
    int unk_08;      /* 0x08 */
    short unk_0C;      /* 0x0C */
    short unk_0E;      /* 0x0E */
    int unk_10;      /* 0x10 */
    int unk_14;      /* 0x14 -- not touched */
    int unk_18;      /* 0x18 */
    void *unk_1C;    /* 0x1C */
    void (*fn_20)(void); /* 0x20 */
    void (*fn_24)(void); /* 0x24 */
    void (*fn_28)(void); /* 0x28 */
    void (*fn_2C)(void); /* 0x2C */
    int unk_30[9];   /* 0x30 -- not touched, pad to 0x54 */
    int unk_54;      /* 0x54 */
} CGUnk_3A6188_t;

__attribute__((section(".text.Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54")))
void Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54(CGUnk_3A6188_t *a0, short a1, short a2, int a3) {
    a0->unk_00 = 0;
    a0->unk_04 = 0;
    a0->unk_08 = 0;
    a0->unk_0C = a1;
    a0->unk_0E = a2;
    a0->unk_10 = 0;
    a0->unk_18 = 0;
    a0->unk_1C = (void *)a0;
    a0->fn_20 = __sread;
    a0->fn_24 = __swrite;
    a0->fn_28 = __sseek;
    a0->fn_2C = func_003A6EC8;
    a0->unk_54 = a3;
}

__attribute__((section(".text.Obj0000_Call_FnFC_Field_100_94_90_Scaled")))
void Obj0000_Call_FnFC_Field_100_94_90_Scaled(unsigned char *arg0)
{
  signed char b;
  int a2;
  int f4;
  int a1;
  int a0arg;
  void (*fn)(int, int, int);
  a2 = *((int *) (arg0 + 0x90));
  f4 = *((int *) (arg0 + 0xF4));
  b = *((signed char *) (arg0 + 0xE));
  a1 = *((int *) (arg0 + 0x94));
  a2 = a2 * b;
  fn = *((void (**)(int, int, int)) (arg0 + 0xFC));
  a1 = a1 - f4;
  ;
  a1 = (a1 < 0) ? (a1 + 0x7FFFFFFF) : (a1);
  fn(*((int *) (arg0 + 0x100)), a1, a2 << 1);
  *((int *) (arg0 + 0xF4)) = *((int *) (arg0 + 0x94));
}

extern int D_0045A460;
extern unsigned char D_0045A470;

extern int func_00369F20(int, unsigned int);

__attribute__((section(".text.Obj0000_Check_D_0045A460_Magic_And_D_0045A470_Val")))
int Obj0000_Check_D_0045A460_Magic_And_D_0045A470_Val(void)
{
    if (D_0045A460 != (int)0x5A5A5A5A) {
        return func_00369F20(0, 0xFF03FF02U);
    }
    if (D_0045A470 != 4) {
        while (1) {
            ((void(*)(void))(unsigned int)-1)();
        }
    }
    return 0;
}

typedef struct { unsigned char unk[0x5D8]; int field_5D8; unsigned char pad[4]; int field_5E0; } D007474A0_t;

__attribute__((section(".text.Obj0000_Set_D_007474A0_Fields_5D8_5E0")))
void Obj0000_Set_D_007474A0_Fields_5D8_5E0(unsigned char *a0) {
    D_007474A0.field_5D8 = *(int *)(a0 + 0x68);
    D_007474A0.field_5E0 = *(int *)(a0 + 0x6C);
}

__attribute__((section(".text.Obj0000_Or_Field_B90_Bit_A1")))
void Obj0000_Or_Field_B90_Bit_A1(int **a0, int a1) {
    int *ptr = *a0;
    if (ptr == 0) return;
    *(int *)((char *)ptr + 0xB90) |= (1 << a1);
}

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
} Entry344FD8;

typedef struct {
    unsigned char pad[0xB4];
    int fB4;
    int fB8;
    int fBC;
    Entry344FD8 entries[8];
} Obj344FD8;

__attribute__((section(".text.Obj0000_Init_Fields_B4_B8_BC_Entries")))
void Obj0000_Init_Fields_B4_B8_BC_Entries(Obj344FD8 *a0) {
    int i;
    a0->fB4 = 0;
    a0->fB8 = 0;
    a0->fBC = 0;
    for (i = 0; i <= 7; i++) {
        a0->entries[i].f0 = 0;
        a0->entries[i].f4 = 0;
        a0->entries[i].f8 = 0;
        a0->entries[i].fC = 0;
        a0->entries[i].f10 = 0x11;
    }
}

/* SetFieldIfUnset_359218 lives in its own TU (src/cod/SetFieldIfUnset_359218.c) with
 * -f=-freorder-blocks dropped via compile_config.json::compile_units,
 * See the
 * sibling TU header for the matching rationale.  */

extern void func_0034FA28(void *obj, int *out0, int *out4);
extern void func_0034F718(void *obj);
extern void func_0034FAD8(void *obj);
extern void func_0034F930(void *obj);
extern void func_0034FB70(void *obj);
extern void func_0034FC20(void *obj);

__attribute__((section(".text.UpdateObj0000Fields_34F6C0")))
void UpdateObj0000Fields_34F6C0(void *obj) {
    int out0;
    int out4;
    func_0034FA28(obj, &out0, &out4);
    func_0034F718(obj);
    func_0034FAD8(obj);
    func_0034F930(obj);
    func_0034FB70(obj);
    func_0034FC20(obj);
}


__attribute__((section(".text.Obj0000_Get_Field_5FC_NE_Zero_12C748")))
int Obj0000_Get_Field_5FC_NE_Zero_12C748(char *a0) { return *(int *)(a0 + 0x5FC) != 0; }

__attribute__((section(".text.Obj0000_Get_Field_1028_Masked_138F88")))
int Obj0000_Get_Field_1028_Masked_138F88(char *a0, int a1) { return a1 & *(int *)(a0 + 0x1028); }

__attribute__((section(".text.Obj0000_Clear_Fields_94_9C_13C808")))
void Obj0000_Clear_Fields_94_9C_13C808(char *a0) { *(int *)(a0 + 0x94) = 0; *(int *)(a0 + 0x9C) = 0; }

__attribute__((section(".text.GetField_2_158CC8")))
float GetField_2_158CC8(int a0, float *a1) { return a1[2]; }

__attribute__((section(".text.Obj0000_Clear_Fields_640_648_124E58")))
void Obj0000_Clear_Fields_640_648_124E58(char *a0) { *(int *)(a0 + 0x640) = 0; a0[0x648] = 0; }

__attribute__((section(".text.ReturnOne_1F6FA0")))
int ReturnOne_1F6FA0(void) { return 1; }

__attribute__((section(".text.Obj0000_Set_Short_00_1FFE08")))
void Obj0000_Set_Short_00_1FFE08(char *a0) { *(short *)a0 = 0; }

__attribute__((section(".text.Obj0000_Get_Low16_2006B0")))
int Obj0000_Get_Low16_2006B0(int a0) { return a0 & 0xFFFF; }

__attribute__((section(".text.GetSelf_200AB0")))
int GetSelf_200AB0(int a0) { return a0; }

__attribute__((section(".text.GetField_110C_2019F8")))
int GetField_110C_2019F8(char *a0) { return *(unsigned char *)(a0 + 0x110C); }

__attribute__((section(".text.ReturnZero_20D138")))
int ReturnZero_20D138(void) { return 0; }

__attribute__((section(".text.NoOp_1F1B18")))
void NoOp_1F1B18(void) {}

__attribute__((section(".text.Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408")))
void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(char *a0, int a1, int a2, int a3, int a4, short a5) {
    *(int*)(a0 + 0x1668) = a1;
    *(int*)(a0 + 0x1660) = a2;
    *(int*)(a0 + 0x1670) = a3;
    *(int*)(a0 + 0x1678) = a4;
    *(short*)(a0 + 0x1680) = a5;
}

__attribute__((section(".text.Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420")))
void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(char *a0, int a1, int a2, int a3, int a4, short a5) {
    *(int*)(a0 + 0x166C) = a1;
    *(int*)(a0 + 0x1664) = a2;
    *(int*)(a0 + 0x1674) = a3;
    *(int*)(a0 + 0x167C) = a4;
    *(short*)(a0 + 0x1682) = a5;
}

__attribute__((section(".text.Obj0000_Get_Byte_2F4_EQ_1_10B5B8")))
int Obj0000_Get_Byte_2F4_EQ_1_10B5B8(char *a0) {
    return *(unsigned char*)(a0 + 0x2F4) == 1;
}

__attribute__((section(".text.Obj0000_IsSet_Field_15F4_Bit_400000_10B698")))
int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(char *a0) {
    int v = *(int*)(a0 + 0x15F4) & 0x400000;
    return v != 0;
}

__attribute__((section(".text.Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_10BD08")))
void Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_10BD08(char *a0, unsigned char a1) {
    *(unsigned char*)(a0 + 0x2F7) = a1;
    *(unsigned char*)(a0 + 0x2F4) = 6;
    *(unsigned char*)(a0 + 0x2F6) = 2;
    *(unsigned char*)(a0 + 0x2F5) = 0;
}

__attribute__((section(".text.Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_12C0D8")))
void Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_12C0D8(char *a0) {
    *(unsigned char*)(a0 + 0x2F4) = 0;
    *(unsigned char*)(a0 + 0x2F5) = 0x45;
    *(unsigned char*)(a0 + 0x2F6) = 0;
    *(unsigned char*)(a0 + 0x2F7) = 0;
}

__attribute__((section(".text.Obj0000_IsSet_Field_15F4_Bit_1000_12C530")))
int Obj0000_IsSet_Field_15F4_Bit_1000_12C530(char *a0) {
    int v = *(int*)(a0 + 0x15F4) & 0x1000;
    return v != 0;
}

__attribute__((section(".text.Obj0000_IsSet_Field_15F4_Bit_100000_12CA48")))
int Obj0000_IsSet_Field_15F4_Bit_100000_12CA48(char *a0) {
    int v = *(int*)(a0 + 0x15F4) & 0x100000;
    return v != 0;
}

__attribute__((section(".text.Obj0000_IsSet_Field_15F4_Bit_1000000_12CED8")))
int Obj0000_IsSet_Field_15F4_Bit_1000000_12CED8(char *a0) {
    int v = *(int*)(a0 + 0x15F4) & 0x1000000;
    return v != 0;
}

__attribute__((section(".text.Obj0000_Get_Byte_15F4_Bit7_12CEF0")))
unsigned long long Obj0000_Get_Byte_15F4_Bit7_12CEF0(char *a0) {
    unsigned long long v = *(unsigned char*)(a0 + 0x15F4);
    return v >> 7;
}

__attribute__((section(".text.Obj0000_Get_Field_20_Plus_A1_Shifted3_1333B8")))
int Obj0000_Get_Field_20_Plus_A1_Shifted3_1333B8(char *a0, unsigned short a1) {
    return *(int*)(a0 + 0x20) + ((a1 & 0xFFFF) << 3);
}

__attribute__((section(".text.SetField_8_133B80")))
void SetField_8_133B80(char *a0) {
    *(int*)(a0 + 0x8) = *(int*)(a0 + 0x8) & ~0x2;
}

__attribute__((section(".text.Obj0000_Set_Fields_360_364_368_139B68")))
void Obj0000_Set_Fields_360_364_368_139B68(char *a0, int a1, int a2, int a3) {
    *(int*)(a0 + 0x360) = a1;
    *(int*)(a0 + 0x364) = a2;
    *(int*)(a0 + 0x368) = a3;
}


__attribute__((section(".text.Obj0000_Init_Fields_00_04_1D6DB0")))
int Obj0000_Init_Fields_00_04_1D6DB0(int a0) {
    *(int*)((char*)a0 + 0x0) = 0;
    *(int*)((char*)a0 + 0x4) = 8;
    return a0;
}

__attribute__((section(".text.Obj0000_Or_Field_0_Bit_1_Clear_Field_348_1ED7C8")))
int Obj0000_Or_Field_0_Bit_1_Clear_Field_348_1ED7C8(int a0) {
    int v0 = *(int*)((char*)a0 + 0x0);
    *(int*)((char*)a0 + 0x348) = 0;
    v0 |= 1;
    *(int*)((char*)a0 + 0x0) = v0;
    return v0;
}

__attribute__((section(".text.NoOp_1F1C48")))
void NoOp_1F1C48(void) {}

__attribute__((section(".text.NoOp_1F1ED8")))
void NoOp_1F1ED8(void) {}

__attribute__((section(".text.NoOp_1F5098")))
void NoOp_1F5098(void) {}

__attribute__((section(".text.Obj0000_Clear_Fields_00_08_0C_0E_10_12_1F6CF8")))
void Obj0000_Clear_Fields_00_08_0C_0E_10_12_1F6CF8(int a0) {
    *(int*)((char*)a0 + 0x8) = 0;
    *(short*)((char*)a0 + 0xC) = 0;
    *(short*)((char*)a0 + 0xE) = 0;
    *(short*)((char*)a0 + 0x10) = 0;
    *(short*)((char*)a0 + 0x12) = 0;
    *(int*)((char*)a0 + 0x0) = 0;
}

__attribute__((section(".text.NoOp_1F6ED8")))
void NoOp_1F6ED8(void) {}

__attribute__((section(".text.Obj0000_Swap_Field_4_In_Scaled_A1_Entry_1F7800")))
int Obj0000_Swap_Field_4_In_Scaled_A1_Entry_1F7800(int a0, int a1, int a2) {
    int v0;
    a1 = (a1 << 4) + 4;
    a0 = a0 + a1;
    v0 = *(int*)((char*)a0 + 4);
    *(int*)((char*)a0 + 4) = a2;
    *(int*)((char*)a2 + 4) = v0;
    return v0;
}

__attribute__((section(".text.NoOp_1F7B50")))
void NoOp_1F7B50(void) {}

__attribute__((section(".text.NoOp_1F7B58")))
void NoOp_1F7B58(void) {}

__attribute__((section(".text.NoOp_1F7D18")))
void NoOp_1F7D18(void) {}

__attribute__((section(".text.Obj0000_Get_Short_1C_Via_Ptr_1FA620")))
short Obj0000_Get_Short_1C_Via_Ptr_1FA620(int *a0)
{
    int p = *a0;
    if (p == 0) return 0;
    return *(short*)(p + 0x1C);
}

__attribute__((section(".text.Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678")))
char Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(int *a0)
{
    int p = *a0;
    if (p == 0) return 1;
    return *(char*)(p + 0x1F);
}

__attribute__((section(".text.Obj0000_Get_Field_24_Via_Ptr0_1FA858")))
int Obj0000_Get_Field_24_Via_Ptr0_1FA858(int *a0)
{
    int p = *a0;
    if (p == 0) return 0;
    return *(int*)(p + 0x24);
}

__attribute__((section(".text.Obj0000_Get_Byte_A8_Via_Ptr0_1FAC58")))
unsigned char Obj0000_Get_Byte_A8_Via_Ptr0_1FAC58(int *a0)
{
    int p = *a0;
    return *(unsigned char*)(p + 0xA8);
}

__attribute__((section(".text.Obj0000_Get_Field_84_Or_ReturnK_64_1FAC68")))
int Obj0000_Get_Field_84_Or_ReturnK_64_1FAC68(int *a0)
{
    int p = *a0;
    if (p == 0) return 0x64;
    return *(int*)(p + 0x84);
}

__attribute__((section(".text.GetField80ViaPtr_1FAC80")))
int GetField80ViaPtr_1FAC80(int *a0)
{
    int p = *a0;
    if (p == 0) return 0x64;
    return *(int*)(p + 0x80);
}

__attribute__((section(".text.Obj0000_Set_Byte_156_If_NonNull_1FAE28")))
void Obj0000_Set_Byte_156_If_NonNull_1FAE28(int *a0, unsigned char a1)
{
    int p = *a0;
    if (p != 0) *(unsigned char*)(p + 0x156) = a1;
}

__attribute__((section(".text.Obj0000_Add_Byte_156_If_Ptr0_NonNull_1FAE40")))
void Obj0000_Add_Byte_156_If_Ptr0_NonNull_1FAE40(int *a0, unsigned char a1)
{
    int p = *a0;
    if (p != 0) *(unsigned char*)(p + 0x156) = a1 + *(unsigned char*)(p + 0x156);
}

__attribute__((section(".text.Obj0000_Get_Short_12_Via_Ptr_1FBF48")))
unsigned short Obj0000_Get_Short_12_Via_Ptr_1FBF48(int *a0)
{
    int p = *a0;
    if (p == 0) return 0;
    return *(unsigned short*)(p + 0x12);
}

__attribute__((section(".text.Obj0000_Set_Short_12_If_Ptr_NonNull_1FBF78")))
void Obj0000_Set_Short_12_If_Ptr_NonNull_1FBF78(int a0, unsigned short a1)
{
    int p = *(int*)a0;
    if (p) {
        *(short*)(p + 0x12) = a1;
    }
}

__attribute__((section(".text.Obj0000_Get_Byte_AF_1FC0C0")))
unsigned char Obj0000_Get_Byte_AF_1FC0C0(int a0)
{
    int p = *(int*)a0;
    if (!p) return 0;
    return *(unsigned char*)(p + 0xAF);
}

__attribute__((section(".text.Obj0000_Set_Bytes_AE_AF_1FC100")))
void Obj0000_Set_Bytes_AE_AF_1FC100(int a0, unsigned char a1)
{
    int p = *(int*)a0;
    if (p) {
        *(unsigned char*)(p + 0xAE) = a1;
        *(unsigned char*)(*(int*)a0 + 0xAF) = a1;
    }
}

__attribute__((section(".text.Obj0000_Set_Byte_157_If_Ptr_NonNull_1FC120")))
void Obj0000_Set_Byte_157_If_Ptr_NonNull_1FC120(int a0)
{
    int p = *(int*)a0;
    if (p) {
        *(unsigned char*)(p + 0x157) = 1;
    }
}

__attribute__((section(".text.Obj0000_Get_Field_B94_Via_Ptr0_1FC3D0")))
int Obj0000_Get_Field_B94_Via_Ptr0_1FC3D0(int a0)
{
    int p = *(int*)a0;
    if (!p) return 0;
    return *(int*)(p + 0xB94);
}

__attribute__((section(".text.Obj0000_Get_Field_BA8_Via_Ptr0_1FC530")))
int Obj0000_Get_Field_BA8_Via_Ptr0_1FC530(int a0)
{
    int p = *(int*)a0;
    if (!p) return 0;
    return *(int*)(p + 0xBA8);
}

__attribute__((section(".text.Obj0000_Get_Short_BB6_Via_Ptr_1FC5D0")))
unsigned short Obj0000_Get_Short_BB6_Via_Ptr_1FC5D0(int a0)
{
    int p = *(int*)a0;
    if (!p) return 0;
    return *(unsigned short*)(p + 0xBB6);
}

__attribute__((section(".text.Obj0000_Get_Short_BB8_Via_Ptr_1FC600")))
unsigned short Obj0000_Get_Short_BB8_Via_Ptr_1FC600(int a0)
{
    int p = *(int*)a0;
    if (!p) return 0;
    return *(unsigned short*)(p + 0xBB8);
}

__attribute__((section(".text.Obj0000_Clear_Short_BBA_Bit0_1FC6C8")))
void Obj0000_Clear_Short_BBA_Bit0_1FC6C8(int a0)
{
    int p = *(int*)a0;
    if (p) {
        *(unsigned short*)(p + 0xBBA) = *(unsigned short*)(p + 0xBBA) & 0xFFFE;
    }
}

__attribute__((section(".text.Obj0000_Or_Short_BBA_Bit_1_1FC6E8")))
void Obj0000_Or_Short_BBA_Bit_1_1FC6E8(int a0)
{
    int p = *(int*)a0;
    if (p) {
        *(unsigned short*)(p + 0xBBA) = *(unsigned short*)(p + 0xBBA) | 1;
    }
}

__attribute__((section(".text.Obj0000_Get_Short_BBA_Bit0_Via_Ptr_1FC708")))
int Obj0000_Get_Short_BBA_Bit0_Via_Ptr_1FC708(int a0)
{
    int p = *(int*)a0;
    if (p) {
        return *(unsigned short*)(p + 0xBBA) & 1;
    }
    return 0;
}

__attribute__((section(".text.Obj0000_Get_Field_BC0_Via_Ptr_1FC740")))
int Obj0000_Get_Field_BC0_Via_Ptr_1FC740(int a0)
{
    int p = *(int*)a0;
    if (!p) return 0;
    return *(int*)(p + 0xBC0);
}

__attribute__((section(".text.NoOp_268500")))
void NoOp_268500(void) {}

__attribute__((section(".text.Obj0000_IsSet_Field_16D0_Bit_1_26ECC0")))
int Obj0000_IsSet_Field_16D0_Bit_1_26ECC0(void *a0) {
    if (*(int *)((char *)a0 + 0x16D0) & 0x2) return 1;
    return 0;
}

__attribute__((section(".text.Obj0000_IsSet_Field_16D0_Bit_100000_26F2F0")))
int Obj0000_IsSet_Field_16D0_Bit_100000_26F2F0(void *a0) {
    if (*(int *)((char *)a0 + 0x16D0) & 0x100000) return 1;
    return 0;
}

__attribute__((section(".text.Obj0000_IsSet_Field_16D4_Bit_4_26F308")))
int Obj0000_IsSet_Field_16D4_Bit_4_26F308(void *a0) {
    if (*(int *)((char *)a0 + 0x16D4) & 0x4) return 1;
    return 0;
}

__attribute__((section(".text.Obj0000_IsSet_Short_3AC_Bit_4_26F318")))
int Obj0000_IsSet_Short_3AC_Bit_4_26F318(void *a0) {
    if (*(unsigned short *)((char *)a0 + 0x3AC) & 0x4) return 1;
    return 0;
}

__attribute__((section(".text.Obj0000_Or_Field_16D0_Bit_20000000_272570")))
void Obj0000_Or_Field_16D0_Bit_20000000_272570(void *a0) {
    *(int *)((char *)a0 + 0x16D0) |= 0x20000000;
}

__attribute__((section(".text.func_00273630")))
void func_00273630(void) {
    char buf[24];
    (void)buf;
}

__attribute__((section(".text.Obj0000_Or_Field_16D4_Bit_1000_274140")))
void Obj0000_Or_Field_16D4_Bit_1000_274140(void *a0) {
    *(int *)((char *)a0 + 0x16D4) |= 0x1000;
}

__attribute__((section(".text.Obj0000_Get_Byte_17C3_NZ_2_276468")))
int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0) {
    return *(unsigned char *)((char *)a0 + 0x17C3) != 0 ? 2 : 0;
}

__attribute__((section(".text.Obj0000_Get_Field_698_2767E0")))
int Obj0000_Get_Field_698_2767E0(int a0) { return *(int*)((char*)a0 + 0x698); }

__attribute__((section(".text.NoOp_277F08")))
void NoOp_277F08(void) {}

__attribute__((section(".text.NoOp_277F10")))
void NoOp_277F10(void) {}

__attribute__((section(".text.NoOp_277F78")))
void NoOp_277F78(void) {}

__attribute__((section(".text.NoOp_279670")))
void NoOp_279670(void) {}

__attribute__((section(".text.NoOp_279930")))
void NoOp_279930(void) {}

__attribute__((section(".text.Obj0000_Or_Field_1560_Bit_2_And_Return_279C88")))
int Obj0000_Or_Field_1560_Bit_2_And_Return_279C88(int a0) {
    *(int*)((char*)a0 + 0x1560) |= 4;
    return *(int*)((char*)a0 + 0x1560);
}

__attribute__((section(".text.NoOp_279E70")))
void NoOp_279E70(void) {}

__attribute__((section(".text.NoOp_279F60")))
void NoOp_279F60(void) {}

__attribute__((section(".text.Obj0000_Get_Field_1580_27A128")))
int Obj0000_Get_Field_1580_27A128(int a0) { return *(int*)((char*)a0 + 0x1580); }

__attribute__((section(".text.NoOp_27CFF8")))
void NoOp_27CFF8(void) {}

__attribute__((section(".text.NoOp_27D0D8")))
void NoOp_27D0D8(void) {}

__attribute__((section(".text.NoOp_27D0E0")))
void NoOp_27D0E0(void) {}

__attribute__((section(".text.NoOp_27D148")))
void NoOp_27D148(void) {}

__attribute__((section(".text.Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DAF0")))
void Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DAF0(char *a0) {
    *(char *)(a0 + 0x2F4) = 0;
    *(char *)(a0 + 0x2F5) = 2;
    *(char *)(a0 + 0x2F6) = 0;
    *(char *)(a0 + 0x2F7) = 0;
}

__attribute__((section(".text.Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DB08")))
void Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DB08(char *a0) {
    *(char *)(a0 + 0x2F4) = 0;
    *(char *)(a0 + 0x2F5) = 4;
    *(char *)(a0 + 0x2F6) = 0;
    *(char *)(a0 + 0x2F7) = 0;
}

__attribute__((section(".text.Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCB8")))
void Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCB8(char *a0, char a1) {
    *(char *)(a0 + 0x2F7) = a1;
    *(char *)(a0 + 0x2F5) = 9;
    *(char *)(a0 + 0x2F6) = 0;
    *(char *)(a0 + 0x2F4) = 0;
}

__attribute__((section(".text.Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCD0")))
void Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCD0(char *a0, char a1) {
    *(char *)(a0 + 0x2F7) = a1;
    *(char *)(a0 + 0x2F5) = 0xA;
    *(char *)(a0 + 0x2F6) = 0;
    *(char *)(a0 + 0x2F4) = 0;
}

__attribute__((section(".text.Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DCE8")))
void Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DCE8(char *a0) {
    *(char *)(a0 + 0x2F4) = 0;
    *(char *)(a0 + 0x2F5) = 3;
    *(char *)(a0 + 0x2F6) = 0;
    *(char *)(a0 + 0x2F7) = 0;
}

__attribute__((section(".text.Obj0000_Get_Field_1560_Bit0_27DD00")))
int Obj0000_Get_Field_1560_Bit0_27DD00(char *a0) {
    return *(int *)(a0 + 0x1560) & 0x1;
}

__attribute__((section(".text.NoOp_27E4E0")))
void NoOp_27E4E0(void) {}

__attribute__((section(".text.NoOp_27E5C0")))
void NoOp_27E5C0(void) {}

__attribute__((section(".text.NoOp_27E5C8")))
void NoOp_27E5C8(void) {}

__attribute__((section(".text.NoOp_27E630")))
void NoOp_27E630(void) {}

__attribute__((section(".text.NoOp_280A08")))
void NoOp_280A08(void) {}

__attribute__((section(".text.NoOp_280AE8")))
void NoOp_280AE8(void) {}

extern int func_003A52F0(int a0, int a1, int a2);
__attribute__((section(".text.Forward3A52F0_332BE0")))
int Forward3A52F0_332BE0(int a0) { return func_003A52F0(a0, 0, 0x48); }

extern int func_003331E0(void);
__attribute__((section(".text.Forward3331E0_3332B0")))
int Forward3331E0_3332B0(void) { return func_003331E0(); }

extern int func_00331C98(void);
__attribute__((section(".text.Forward331C98_333F60")))
int Forward331C98_333F60(void) { return func_00331C98(); }

extern int func_003A52F0(int a0, int a1, int a2);
__attribute__((section(".text.Forward3A52F0_334500")))
int Forward3A52F0_334500(int a0) { return func_003A52F0(a0, 0, 0x30); }

extern int func_00334310(void);
__attribute__((section(".text.Forward334310_334B20")))
int Forward334310_334B20(void) { return func_00334310(); }

extern int Forward33B568_33B658(void);
__attribute__((section(".text.Forward33B658_335CE8")))
int Forward33B658_335CE8(void) { return Forward33B568_33B658(); }

extern int Forward33B5C8_33B670(void);
__attribute__((section(".text.Forward33B670_335D00")))
int Forward33B670_335D00(void) { return Forward33B5C8_33B670(); }

extern int Forward33B568_33B658(void);
__attribute__((section(".text.Forward33B658_3362E8")))
int Forward33B658_3362E8(void) { return Forward33B568_33B658(); }

extern int Forward33B5C8_33B670(void);
__attribute__((section(".text.Forward33B670_336300")))
int Forward33B670_336300(void) { return Forward33B5C8_33B670(); }

extern int func_003A9228(void);
__attribute__((section(".text.Forward3A9228_336360")))
int Forward3A9228_336360(void) { return func_003A9228(); }

extern int func_003A52F0(int a0, int a1, int a2);
__attribute__((section(".text.Forward3A52F0_336588")))
int Forward3A52F0_336588(int a0) { return func_003A52F0(a0, 0, 0x38); }

extern int func_003406D0(int a0);
__attribute__((section(".text.Forward3406D0_336E20")))
int Forward3406D0_336E20(int a0) { return func_003406D0(*(int*)((char*)a0 + 0xE8)); }

extern int func_00340740(int a0, short a1);
__attribute__((section(".text.Forward340740_336E38")))
int Forward340740_336E38(int a0, short a1) { return func_00340740(*(int*)((char*)a0 + 0xE8), a1); }

extern int func_00340A20(int a0);
__attribute__((section(".text.Forward340A20_336E58")))
int Forward340A20_336E58(int a0) { return func_00340A20(*(int*)((char*)a0 + 0xE8)); }

extern int func_0033F130(int a0);
__attribute__((section(".text.Forward33F130_336E70")))
int Forward33F130_336E70(int a0, int a1) { return func_0033F130(a1); }

extern int Forward33B568_33B658(void);
__attribute__((section(".text.Forward33B658_3389F8")))
int Forward33B658_3389F8(void) { return Forward33B568_33B658(); }

extern int Forward33B5C8_33B670(void);
__attribute__((section(".text.Forward33B670_338A10")))
int Forward33B670_338A10(void) { return Forward33B5C8_33B670(); }

extern int Forward33B790_340AE8(void *a0);
extern char D_00455900[];
__attribute__((section(".text.Forward340AE8_338A28")))
int Forward340AE8_338A28(void) { return Forward33B790_340AE8(D_00455900); }

extern int Forward33B790_340AE8(void *a0);
extern char D_00455A60[];
__attribute__((section(".text.Forward340AE8_339438")))
int Forward340AE8_339438(void) { return Forward33B790_340AE8(D_00455A60); }

extern int Forward33B790_340AE8(void *a0);
extern char D_00455BB8[];
__attribute__((section(".text.Forward340AE8_33A028")))
int Forward340AE8_33A028(void) { return Forward33B790_340AE8(D_00455BB8); }

extern int func_00332778(int);
__attribute__((section(".text.Forward332778_33B200")))
int Forward332778_33B200(int a0) { return func_00332778(a0); }

extern int func_0033B568(int);
__attribute__((section(".text.Forward33B568_33B658")))
int Forward33B568_33B658(void) { return func_0033B568(1); }

extern int func_0033B5C8(int);
__attribute__((section(".text.Forward33B5C8_33B670")))
int Forward33B5C8_33B670(void) { return func_0033B5C8(1); }

extern int func_0033B568(int);
__attribute__((section(".text.Forward33B568_33B688")))
int Forward33B568_33B688(void) { return func_0033B568(2); }

extern int func_0033B568(int);
__attribute__((section(".text.Forward33B568_33B6A0")))
int Forward33B568_33B6A0(void) { return func_0033B568(4); }

extern int func_0033B5C8(int);
__attribute__((section(".text.Forward33B5C8_33B6B8")))
int Forward33B5C8_33B6B8(void) { return func_0033B5C8(2); }

extern int func_0033B5C8(int);
__attribute__((section(".text.Forward33B5C8_33B6D0")))
int Forward33B5C8_33B6D0(void) { return func_0033B5C8(4); }

extern int func_0033BC48(int);
__attribute__((section(".text.Forward33BC48_33BD18")))
int Forward33BC48_33BD18(void) { return func_0033BC48(0); }

extern int func_0033BC48(int);
__attribute__((section(".text.Forward33BC48_33BD30")))
int Forward33BC48_33BD30(void) { return func_0033BC48(1); }

extern int func_0033BC48(int);
__attribute__((section(".text.Forward33BC48_33BD48")))
int Forward33BC48_33BD48(void) { return func_0033BC48(2); }

extern int func_0033BC48(int);
__attribute__((section(".text.Forward33BC48_33BD60")))
int Forward33BC48_33BD60(void) { return func_0033BC48(3); }

extern int func_0033BC48(int);
__attribute__((section(".text.Forward33BC48_33BD78")))
int Forward33BC48_33BD78(void) { return func_0033BC48(4); }

extern int func_0033BC48(int);
__attribute__((section(".text.Forward33BC48_33BD90")))
int Forward33BC48_33BD90(void) { return func_0033BC48(5); }

extern int func_0033BC48(int);
__attribute__((section(".text.Forward33BC48_33BDA8")))
int Forward33BC48_33BDA8(void) { return func_0033BC48(6); }

extern int func_0033BC48(int);
__attribute__((section(".text.Forward33BC48_33BDC0")))
int Forward33BC48_33BDC0(void) { return func_0033BC48(7); }

extern int func_0032B300(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward32B300_342AF0")))
int Forward32B300_342AF0(int a0, int a1, int a2, int a3) {
    return func_0032B300(a0, a1, a2, a3);
}

extern int func_0032A9F0(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward32A9F0_342B08")))
int Forward32A9F0_342B08(int a0, int a1, int a2, int a3) {
    return func_0032A9F0(a0, a1, a2, a3);
}

extern int func_0032AAA0(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward32AAA0_342B20")))
int Forward32AAA0_342B20(int a0, int a1, int a2, int a3) {
    return func_0032AAA0(a0, a1, a2, a3);
}

extern int func_0032B660(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward32B660_342B38")))
int Forward32B660_342B38(int a0, int a1, int a2, int a3) {
    return func_0032B660(a0, a1, a2, a3);
}

extern int func_003443E0(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward3443E0_3443C8")))
int Forward3443E0_3443C8(int a0, int a1, int a2, int a3) {
    return func_003443E0(a0, a1, a2, a3);
}

extern int func_00345250(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward345250_344F18")))
int Forward345250_344F18(int a0, int a1, int a2, int a3) {
    return func_00345250(a0, a1, a2, a3);
}

extern int MWSFSVM_Error(int a0);
__attribute__((section(".text.Forward348BE0_3452C0")))
int Forward348BE0_3452C0(int a0, int a1) {
    return MWSFSVM_Error(a1);
}

extern int func_00345D58(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward345D58_345D40")))
int Forward345D58_345D40(int a0, int a1, int a2, int a3) {
    return func_00345D58(a0, a1, a2, a3);
}

extern int func_00345EE0(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward345EE0_345EC8")))
int Forward345EE0_345EC8(int a0, int a1, int a2, int a3) {
    return func_00345EE0(a0, a1, a2, a3);
}

extern int func_00346450(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward346450_3462A8")))
int Forward346450_3462A8(int a0, int a1, int a2, int a3) {
    return func_00346450(a0, a1, a2, a3);
}

extern int func_00346450(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward346450_3462C0")))
int Forward346450_3462C0(int a0, int a1, int a2, int a3) {
    return func_00346450(a0, a1, a2, a3);
}

extern int func_00325F20(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward325F20_3466A8")))
int Forward325F20_3466A8(int a0, int a1, int a2, int a3) {
    return func_00325F20(a0, a1, a2, a3);
}

extern int func_003462D8(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward3462D8_3466C0")))
int Forward3462D8_3466C0(int a0, int a1, int a2, int a3) {
    return func_003462D8(a0, a1, a2, a3);
}

extern int func_00346368(int a0, int a1, int a2, int a3);
__attribute__((section(".text.Forward346368_3466D8")))
int Forward346368_3466D8(int a0, int a1, int a2, int a3) {
    return func_00346368(a0, a1, a2, a3);
}

extern int MWSFSVM_Error(int a0);
__attribute__((section(".text.Forward348BE0_346BE0")))
int Forward348BE0_346BE0(int a0, int a1) {
    return MWSFSVM_Error(a1);
}
INCLUDE_ASM("nonmatching", chack_point_line);
INCLUDE_ASM("nonmatching", MotionGetParam);
INCLUDE_ASM("nonmatching", SetEv61HumanAlive);
INCLUDE_ASM("nonmatching", Dest_ck);
INCLUDE_ASM("nonmatching", setColorScrollLayer);
INCLUDE_ASM("nonmatching", displayOmLayer);
INCLUDE_ASM("nonmatching", GetViewScrollIdAll);
INCLUDE_ASM("nonmatching", getItemNumInRoom);
INCLUDE_ASM("nonmatching", SetEventCutEffect);
INCLUDE_ASM("nonmatching", setPlayerPos);

INCLUDE_ASM("nonmatching", pl00_CkSubScreen);

INCLUDE_ASM("nonmatching", cCollisionScroll_SetLayerCollEnable);

INCLUDE_ASM("nonmatching", cCockScroll_OnScroll);

INCLUDE_ASM("nonmatching", cModel_setMeshDisplay);

INCLUDE_ASM("nonmatching", cObj_setId);

INCLUDE_ASM("nonmatching", VecRotVec);

INCLUDE_ASM("nonmatching", VecRotY);

INCLUDE_ASM("nonmatching", GetPointCalcPointLine);

INCLUDE_ASM("nonmatching", MotionIsHaveParam);

INCLUDE_ASM("nonmatching", Quaternion_SetVectorRotation);

INCLUDE_ASM("nonmatching", cOl1b_setCloseFix);

INCLUDE_ASM("nonmatching", cOl21_setCollisionActive);

INCLUDE_ASM("nonmatching", cOl22_setOpenFix);

INCLUDE_ASM("nonmatching", cOl22_setCloseFix);

INCLUDE_ASM("nonmatching", cOl2b_setInit);

INCLUDE_ASM("nonmatching", cOl2b_setOpenFix);

INCLUDE_ASM("nonmatching", cOl2b_setCloseFix);

INCLUDE_ASM("nonmatching", cOl40_setVitalMax);

INCLUDE_ASM("nonmatching", cOm1f_setStart);

INCLUDE_ASM("nonmatching", cOm1f_setMoveRange);

INCLUDE_ASM("nonmatching", cOm4f_setOpenFix);

INCLUDE_ASM("nonmatching", cOm4f_setCloseFix);

INCLUDE_ASM("nonmatching", cOm4f_setOpenCloseRot);

INCLUDE_ASM("nonmatching", cOm53_setGetOffEm);

INCLUDE_ASM("nonmatching", cOmb0_ReleaseCollision);

INCLUDE_ASM("nonmatching", cOmb3_SetNextPoint);

INCLUDE_ASM("nonmatching", cOmSub_setVibration);

INCLUDE_ASM("nonmatching", ColiseumBattle_PlCtrlOff);

INCLUDE_ASM("nonmatching", CasinoWork_SetWarmUpRoom);

INCLUDE_ASM("nonmatching", capVu0Acos);

INCLUDE_ASM("nonmatching", cCoreSave_setGameDifficulty);

INCLUDE_ASM("nonmatching", cCoreSave_addGodItem);

INCLUDE_ASM("nonmatching", cCoreSave_ckGodReel);

INCLUDE_ASM("nonmatching", cCoreSave_getAllKillEmNum);

INCLUDE_ASM("nonmatching", cDamageUnit_SetDamageCollFlashActive);

INCLUDE_ASM("nonmatching", cDvd_Check);

INCLUDE_ASM("nonmatching", cEm00_CkDevilEvent);

INCLUDE_ASM("nonmatching", cEm00_setSitChair);

INCLUDE_ASM("nonmatching", cEm00_setR302Switch);

INCLUDE_ASM("nonmatching", cEm00_setEm65Separate);

INCLUDE_ASM("nonmatching", cEm12_SetParent);

__attribute__((section(".text.cEma2_SetPoison")))
void cEma2_SetPoison(char *a0) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 5;
    a0[0x2F6] = 0;
    a0[0x2F7] = 0;
}

__attribute__((section(".text.cEma2_SetPoisonDie")))
void cEma2_SetPoisonDie(char *a0) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 5;
    a0[0x2F6] = 2;
    a0[0x2F7] = 0;
}

INCLUDE_ASM("nonmatching", cEma2_gotoSwitch);

INCLUDE_ASM("nonmatching", cEmManage_GetEm);

INCLUDE_ASM("nonmatching", cGame_isReleaseActiveHeap);

INCLUDE_ASM("nonmatching", cHeatSys_SetHeatGage);

INCLUDE_ASM("nonmatching", cIDBase_getIDWork);

__attribute__((section(".text.cObjSimple_R0_Init")))
void cObjSimple_R0_Init(char *a0) {
    a0[0x2F4] = 1;
    a0[0x2F5] = 0;
    a0[0x2F6] = 0;
    a0[0x2F7] = 0;
}

INCLUDE_ASM("nonmatching", cObjSimple_SetPackIndex);

INCLUDE_ASM("nonmatching", cObjSimple_SetParentInfo);

INCLUDE_ASM("nonmatching", cPadVib_setSeq);

INCLUDE_ASM("nonmatching", cRoomSave_systemInit);

INCLUDE_ASM("nonmatching", cSceAtManager_SetDoorFunc);

INCLUDE_ASM("nonmatching", cSceAtManager_AtDataSet_exec_2C2750);

INCLUDE_ASM("nonmatching", cSceAtManager_AtDataReset);

INCLUDE_ASM("nonmatching", cScenario_isCamEnd);

INCLUDE_ASM("nonmatching", cScenario_beginRoomJump_2C4548);

INCLUDE_ASM("nonmatching", cScenario_getObjIdFromStr);

INCLUDE_ASM("nonmatching", cScenario_getStrFromObjId);

INCLUDE_ASM("nonmatching", cScenario_setOmSuspend);

INCLUDE_ASM("nonmatching", cScrArray_SearchScroll);

INCLUDE_ASM("nonmatching", cSnd_SetBgmLevel);

INCLUDE_ASM("nonmatching", CustomIDWork_Initialize);

INCLUDE_ASM("nonmatching", CustomIDWork_SetColorAnimNormal_2D6898);

INCLUDE_ASM("nonmatching", CustomIDWork_SetScaleAnimNormal);

INCLUDE_ASM("nonmatching", cWorldTime_getGlobalHMS);

INCLUDE_ASM("nonmatching", SetEventFrame);

INCLUDE_ASM("nonmatching", KeyStop);

INCLUDE_ASM("nonmatching", classPAD_WORK_Pad_act_set);

INCLUDE_ASM("nonmatching", SearchData);












































































































































































































































































































































































































































































































































































































