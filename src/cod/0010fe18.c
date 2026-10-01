/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_00126770(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int t0, int t1);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int t0, int t1);
extern void func_0010A438(void *a0);
extern void func_00129EB0(void *a0);
extern void func_00123938(void *a0, int a1);
extern unsigned char D_00462FC0[];
extern unsigned char D_005864F0[];
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void func_00289610(void *a0, int a1, float f12, float f13);
extern unsigned char D_005FEE00[];
extern int D_00747A24;
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);

__attribute__((section(".text.func_001160A0")))
void func_001160A0(void *a0)
{
    char *s1 = (char *)a0;
    float *d;
    float *s;
    *(float *)(s1 + 0x54C) = 5.0f;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int t;
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_001268F0(s1);
        Obj0000_Clear_Fields_640_648_124E58(s1);
        d = (float *)(s1 + 0x490);
        (*(float **)(s1 + 0xF0))[0] = *(float *)(s1 + 0x660);
        (*(float **)(s1 + 0xF0))[2] = *(float *)(s1 + 0x668);
        s = *(float **)(s1 + 0xF0);
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
        *(float *)(s1 + 0x104) = *(float *)(s1 + 0x670);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x954) + t, *(int *)(t + 0x958) + t, 0.0f, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 1, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
}

__attribute__((section(".text.func_0010FE18")))
void func_0010FE18(void *a0){ char *s0=(char*)a0; int v0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  *(short*)(s0+0x5E0)=0; *(short*)(s0+0x5E2)=0;
  Obj0000_Clear_Fields_640_648_124E58(s0);
  func_00126770(s0);
  ClearField15F4Bit1_124F60(s0,0,0);
  Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s0,0x14,0xB,0xA,0,0xA);
  Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s0,0x14,0xB,0xA,0,0xA);
  v0=*(int*)(s0+0x304);
  *(char*)(s0+0x1684)=0;
  func_002A8578(s0,*(int*)(v0+0x100)+v0,*(int*)(v0+0x108)+v0,0.0f,3,0,0);
  *(int*)(s0+0x15B0)=1;
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0; *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
  AddScaledVecToField_100_14F9F0(s0,1.0f);
  AddScaledXfmVecToField_F0_14F928(s0,1.0f);
 }
 func_0010A438(s0);
 if((*(unsigned short*)(s0+0x3AC)&3)!=0 && *(int*)(s0+0x15B0)!=0){
  *(int*)(s0+0x15B0)=0; func_00129EB0(s0); }
 func_00123938(s0,1); }

#include "godhand/vu0.h"
__attribute__((section(".text.func_001228D8")))
void func_001228D8(void *a0)
{
    char *s1 = (char *)a0;
    char *s2;
    float buf[4] __attribute__((aligned(16)));
    float v;

    *(float *)(s1 + 0x54C) = 5.0f;
    s2 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(&D_005864F0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        buf[0] = 0.5174f;
        buf[1] = 0.0f;
        buf[2] = 0.5303f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(s1, s2, buf, 0, v);
        func_00289610(s2, 0, v, v);
        *(short *)(s1 + 0x56E) = 0xF;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 1:
        if (*(short *)(s1 + 0x56E) != 0 && s2 != 0) {
            char *d;
            char *e = s2 + 0x550;
            *(short *)(s1 + 0x56E) = *(unsigned short *)(s1 + 0x56E) - 1;
            d = *(char **)(s1 + 0xF0);
            VU0_VADD_XYZ_IP(d, 0, e);
        }
        func_00124EC0(s1);
        if (moveMotion(s1)) {
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
}

/* sn-2.95.3-136 matched TU. */






















/* sn-2.95.3-136 matched TU. */






















__attribute__((section(".text.func_0011F0D0")))
void func_0011F0D0(void *a0)
{
    char *s1 = (char *)a0;
    char *s0;
    float buf[4] __attribute__((aligned(16)));
    float v;

    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    s0 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(&D_005864F0);

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        buf[0] = 0.0969f;
        buf[1] = 0.0f;
        buf[2] = 0.6003f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(s1, s0, buf, 0, v);
        cEm00_GetPlMotion(s0, 0x1C, v, v);
        *(int *)(s1 + 0x15B0) = 1;
        *(int *)(s1 + 0x15B4) = 1;
        *(short *)(s1 + 0x56E) = 0x3C;
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (*(short *)(s1 + 0x54A) <= 0) {
                *(short *)(s1 + 0x54A) = 1;
            }
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0 && *(int *)(s1 + 0x15B4) != 0) {
            *(int *)(s1 + 0x15B4) = 0;
            if (s0 != 0) {
                func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 3.0f));
            }
            func_0012C348(s1, 2);
        } else {
            *(int *)(s1 + 0x15B4) = 1;
        }
        if ((*(unsigned short *)(s1 + 0x3AC) & 2) != 0 && *(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = 0;
            if (s0 != 0) {
                func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 8.0f));
            }
            if (*(short *)(s1 + 0x54A) <= 0) {
                *(short *)(s1 + 0x54A) = 1;
                OrChildField98AndSelfFieldB0AC_2CA718(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                *(short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
            }
            func_0012C348(s1, 2);
        }
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x200) != 0 && *(short *)(s1 + 0x54A) < 9) {
            *(unsigned char *)(s1 + 0x2F6) = 2;
        }
        break;
    case 2:
        cEm00_GetPlMotion(s0, 0x1D, 0.0f, 0.0f);
        *(short *)(s1 + 0x54A) = 0;
        func_0012C348(s1, 2);
        OrChildField98AndSelfFieldB0AC_2CA718(&D_005FEE00);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 3:
        *(short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            D_00747A24 = D_00747A24 | 8;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
}
