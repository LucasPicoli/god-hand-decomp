/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00129578(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_0010A438(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_00124EC0(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern int D_005864F0;
extern int D_00462FC0;
extern void cHeatSys_AddHeatGage(void *a0, float a1, int a2);
extern int D_005CB000;
extern void func_002A52E8(void *a0, int a1);
extern int func_002A53A8(void *a0, int a1, float f12, float f13, float f14);
extern void func_002B1300(void *a0, float f12, float f13, float f14);
extern char *D_003C2380;

__attribute__((section(".text.func_00113768")))
void func_00113768(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    cEmManage_SetSlotWait(&D_005864F0, 2);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetBigHitEffWait(&D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int p1, p2;
        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_00129578(s1);
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 5, 0x17, 0x2A, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 5, 0x17, 0x2A, 0, 0xA);
        *(char *)(s1 + 0x1684) = 1;
        if (*(unsigned char *)(s1 + 0x2F7)) {
            char *q;
            cCoreSave_useGodItem(&D_00569B70);
            cCoreSave_useGodItem(&D_00569B70);
            q = *(char **)(s1 + 0x304);
            p1 = *(int *)(q + 0x70) + (int)q;
            p2 = *(int *)(q + 0x78) + (int)q;
        } else {
            char *r;
            cCoreSave_useGodItem(&D_00569B70);
            r = *(char **)(s1 + 0x304);
            p1 = *(int *)(r + 0x70) + (int)r;
            p2 = *(int *)(r + 0x74) + (int)r;
        }
        func_002A8578(s1, p1, p2, 0.0f, 3, 0, 0);
        *(int *)(s1 + 0x15B0) = 1;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        float one;
        func_00124EC0(s1);
        if (*(unsigned short *)(s1 + 0x3AC) & 0x100) {
            cCollisionSolidManage_SetActive(&D_00462FC0, s1, 0);
        }
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            pl00_clearMotionCam(s1, 0, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s1, one);
        cObjBase_addNullSpeed(s1, one);
        break;
    }
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) && *(int *)(s1 + 0x15B0) != 0) {
        *(int *)(s1 + 0x15B0) = 0;
        if (*(unsigned char *)(s1 + 0x2F7)) {
            cHeatSys_AddHeatGage(&D_005CB000, 80.0f, 1);
        } else {
            cHeatSys_AddHeatGage(&D_005CB000, 30.0f, 1);
        }
    }
    func_0010A438(s1);
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        pl00_clearMotionCam(s1, 0, 0);
    } else {
        cEmManage_SetSpeedRate(&D_005864F0, 0.1f);
        *(unsigned short *)(s1 + 0x3AC) |= 0x800;
        *(float *)(s1 + 0x674) = 0.05f;
    }
}

__attribute__((section(".text.func_002AFC48"))) unsigned short *func_002AFC48(char *o, unsigned short *a1, unsigned short *a2, unsigned short *a3, char *t0, float x, float y)
{
  unsigned short *r;
  int fl;
  if (a3 == 0)
  {
    goto keep;
  }
  if (a2 != (a1 + a3[0]))
  {
    goto keep;
  }
  a3 = (unsigned short *) (((char *) a3) + ((a3[2] * 2) + 6));
  r = 0;
  if ((*a3) != 0xFFFF)
  {
    r = a3;
  }
  goto done;
  keep:
  r = a3;

  done:
  fl = *((int *) o);

  if (fl & 1)
  {
    y = y + (((*((float *) (o + 0x38))) + 12.0f) * (*((float *) (o + 0x48))));
  }
  if ((fl >> 1) & 1)
  {
    func_002A52E8(D_003C2380, 0xFF000000);
    *((float *) (D_003C2380 + 0x2A068)) = ((*((float *) t0)) * (*((float *) (o + 0x3C)))) * (*((float *) (o + 0x44)));
    *((float *) (D_003C2380 + 0x2A06C)) = ((*((float *) t0)) * (*((float *) (o + 0x40)))) * (*((float *) (o + 0x48)));
    if (func_002B12A0(a2) == 0)
    {
      func_002A53A8(D_003C2380, *a2, x + 2.0f, y + 2.0f, 65535.0f);
    }
  }
  else
  {
    func_002A52E8(D_003C2380, *((int *) (t0 + 4)));
    *((float *) (D_003C2380 + 0x2A068)) = ((*((float *) t0)) * (*((float *) (o + 0x3C)))) * (*((float *) (o + 0x44)));
    *((float *) (D_003C2380 + 0x2A06C)) = ((*((float *) t0)) * (*((float *) (o + 0x40)))) * (*((float *) (o + 0x48)));
    if (func_002B12A0(a2) != 0)
    {
      if ((*((int *) (o + 0x4C))) != 3)
      {
        func_002B1300(a2, x, y, ((*((float *) t0)) * (*((float *) (o + 0x40)))) * (*((float *) (o + 0x48))));
      }
    }
    else
    {
      func_002A53A8(D_003C2380, *a2, x, y, 65535.0f);
      if ((*((unsigned int *) (t0 + 8))) & 1)
      {
        ;
        func_002A53A8(D_003C2380, *a2, x + 1.0f, y + 1.0f, 65535.0f);
        func_002A53A8(D_003C2380, *a2, x + 1.0f, y - 1.0f, 65535.0f);
      }
    }
  }
  return r;
}
