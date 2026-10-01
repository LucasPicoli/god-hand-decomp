/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int Forward30F348_31CFE0(void);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void Obj2810_SetState_D_a1(void *a0, int a1);
extern void SetBytes2F4Mode10_2833C0(void *a0, int a1);
extern void func_0026F120(void *a0);
extern void func_00270C78(void *a0);
extern void func_002705D8(void *a0);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
extern void func_0027D670(void *a0, int a1, int a2);
extern void func_00124540(void *a0, int a1);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_0010A438(void *a0);
extern void func_00124EC0(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void SetField548AndGlobals_292F38(void *a0, float f12);
extern char D_005864F0[];
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern float fRand0_1(void);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern unsigned char D_00462FC0[];
extern unsigned char D_005FEE00[];

__attribute__((section(".text.func_0025B5A8")))
void func_0025B5A8(void *a0){ char *s0=(char*)a0;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0: {
  int nb=Obj0000_Get_Byte_17C3_NZ_2_276468(s0)&0xFFFF;
  int f=Forward30F348_31CFE0()&1; int s2, s1;
  *(unsigned char*)(s0+0x2F7)=f;
  if(*(unsigned char*)(s0+0x2F7)){ int b=*(int*)(s0+0x304); s2=*(int*)(b+0x3DF4)+b; s1=*(int*)(b+0x3DF8)+b; }
  else { int b=*(int*)(s0+0x304); s2=*(int*)(b+0x3DEC)+b; s1=*(int*)(b+0x3DF0)+b; }
  *(int*)(s0+0x16D0)=*(int*)(s0+0x16D0)&0xFEFFFFFF;
  func_002A8578(s0,s2,s1,0.0f,2,nb,0);
  if(*(int*)(s0+0x748)) Obj2810_SetState_D_a1(*(void**)(s0+0x748),*(unsigned char*)(s0+0x2F7));
  if(*(int*)(s0+0x74C)) SetBytes2F4Mode10_2833C0(*(void**)(s0+0x74C),*(unsigned char*)(s0+0x2F7));
  if(*(int*)(s0+0x750)) SetBytes2F4Mode10_2833C0(*(void**)(s0+0x750),*(unsigned char*)(s0+0x2F7));
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1; }
 case 1:
  if(moveMotion(s0)!=0){ func_0026F120(s0);
   if(func_0026F1D8(s0)!=0) func_00270C78(s0); else func_002705D8(s0); }
  break; } }

__attribute__((section(".text.func_0027C2B8")))
void func_0027C2B8(void *a0){ char *s0=(char*)a0; int v0; float f;
 *(int*)(s0+0x1560)|=3;
 switch(*(unsigned char*)(s0+0x2F6)){
 case 0:
  *(unsigned char*)(s0+0x2F7)=Forward30F348_31CFE0()&1;
  if(*(unsigned char*)(s0+0x2F7)){ v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x18)+v0,*(int*)(v0+0x1C)+v0,0.0f,5,0,0);
   InitRenderStruct_2A8608(s0,0xBC,0x1E,0,2,*(int*)(s0+0x15B0)); }
  else { v0=*(int*)(s0+0x304);
   func_002A8578(s0,*(int*)(v0+0x20)+v0,*(int*)(v0+0x24)+v0,0.0f,5,0,0);
   InitRenderStruct_2A8608(s0,0xBC,0x1F,0,2,*(int*)(s0+0x15B0)); }
  *(int*)(s0+0x5F0)=1;
  *(int*)(s0+0x600)=0;
  *(unsigned char*)(s0+0x2F6)=*(unsigned char*)(s0+0x2F6)+1;
 case 1:
  if(moveMotion(s0)!=0){ *(unsigned char*)(s0+0x2F4)=0; *(unsigned char*)(s0+0x2F5)=0;
   *(unsigned char*)(s0+0x2F6)=0; *(unsigned char*)(s0+0x2F7)=0; }
 }
 if(*(unsigned short*)(s0+0x3AC)&1){
  if(*(unsigned char*)(s0+0x2F7)){
   f=*(float*)(s0+0x600)-*(float*)(s0+0x5A8);
   *(float*)(s0+0x600)=f;
   if(f<=0.0f){ *(float*)(s0+0x600)=6.0f;
    func_0027D670(s0,*(unsigned char*)(s0+0x2F7),0); } }
  else if(*(int*)(s0+0x5F0)!=0){ *(int*)(s0+0x5F0)=0;
    func_0027D670(s0,*(unsigned char*)(s0+0x2F7),0); }
 } else *(int*)(s0+0x5F0)=1;
}

static __inline__ long inr(unsigned short k, int lo, int hi)
{
    long c; int t;
    c = 0;
    if (k >= lo) { t = (k < hi); c = t; }
    return c;
}
__attribute__((section(".text.func_0010F4B8")))
void func_0010F4B8(void *a0)
{
    char *s0 = (char *)a0;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int p1, p2;
        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        func_00124540(s0, 0);
        if (*(int *)(s0 + 0x640) != 0) {
            if (inr(*(unsigned short *)(*(int *)(s0 + 0x640) + 0x2FE), 0x200, 0x300) & 0xFF)
                cCoreSave_addGameLevelPoint(&D_00569B70, 0x14);
        }
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            char *v;
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s0, (int)(*(float *)(s0 + 0x600) * 20.0f), 0x19, 0xB, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s0, (int)(*(float *)(s0 + 0x600) * 20.0f), 0x19, 0xB, 0, 0x123);
            *(char *)(s0 + 0x1684) = 0;
            v = *(char **)(s0 + 0x304);
            p1 = *(int *)(v + 0x1C8) + (int)v;
            p2 = *(int *)(v + 0x1CC) + (int)v;
        } else {
            char *v;
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s0, (int)(*(float *)(s0 + 0x600) * 20.0f), 0x18, 0x1D, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s0, (int)(*(float *)(s0 + 0x600) * 20.0f), 0x18, 0x1D, 0, 0x123);
            *(char *)(s0 + 0x1684) = 0;
            v = *(char **)(s0 + 0x304);
            p1 = *(int *)(v + 0x1A4) + (int)v;
            p2 = *(int *)(v + 0x1A8) + (int)v;
        }
        func_002A8578(s0, p1, p2, 0.0f, 3, 0, 0);
        *(float *)(s0 + 0x54C) = 15.0f;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
    case 1:
        func_00124EC0(s0);
        if (*(int *)(s0 + 0x640) != 0)
            *(char *)(s0 + 0x648) = 0x14;
        if (moveMotion(s0) != 0) {
            if (*(unsigned char *)(s0 + 0x2F7) == 0)
                Obj0000_Clear_Fields_640_648_124E58(s0);
            ClearField15F4Bit1_124F60(s0, 1, 0);
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        break;
    }
    func_0010A438(s0);
    if (*(unsigned short *)(s0 + 0x3AC) & 0x100) {
        SetField548AndGlobals_292F38(D_005864F0, 0.1f);
    }
    if (func_00123938(s0, 1) != 0) {
        if (*(unsigned char *)(s0 + 0x2F7) == 0)
            Obj0000_Clear_Fields_640_648_124E58(s0);
        ClearField15F4Bit1_124F60(s0, 1, 0);
    }
}

__attribute__((section(".text.func_00287E50")))
void func_00287E50(void *a0)
{
    char *s0 = (char *)a0;
    *(float *)(s0 + 0x54C) = 3.0f;
    *(int *)(s0 + 0x15B0) = *(int *)(s0 + 0x15B0) | 0x10000;
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    *(int *)(s0 + 0x258) = *(int *)(s0 + 0x258) | 0x80000000;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x168) + v0, *(int *)(v0 + 0x16C) + v0, 0.0f, 3, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 1:
        moveMotion(s0);
        break;
    case 2: {
        int v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x170) + v0, *(int *)(v0 + 0x174) + v0, 0.0f, 3, 0, 0);
        *(unsigned short *)(s0 + 0x54A) = *(unsigned short *)(s0 + 0x54A) - 0x32;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 3:
        if (moveMotion(s0) != 0)
            *(unsigned char *)(s0 + 0x2F6) = 0;
        break;
    }
    if (*(short *)(s0 + 0x54A) <= 0) {
        float *p = *(float **)(s0 + 0xF0);
        p[1] = p[1] - *(float *)(s0 + 0x5A8) * 0.1f;
        if ((*(float **)(s0 + 0xF0))[1] < -5.0f) {
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F4) = 2;
            *(unsigned char *)(s0 + 0x2F5) = 2;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
    }
    *(float *)(s0 + 0x600) = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
    if (*(float *)(s0 + 0x600) <= 0.0f) {
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x60, s0, 0, 0, 0, 0);
        *(float *)(s0 + 0x600) = fRand0_1() * 60.0f + 90.0f;
    }
    *(float *)(s0 + 0x604) = *(float *)(s0 + 0x604) - *(float *)(s0 + 0x5A8);
    if (*(float *)(s0 + 0x604) <= 0.0f) {
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x51, s0, 0, 0, 0, 0);
        *(float *)(s0 + 0x604) = fRand0_1() * 4.0f + 8.0f;
    }
}
