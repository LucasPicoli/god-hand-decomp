/* sn-2.95.3-136 matched TU. */

extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void func_00126770(void *a0);
extern unsigned short func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void moveMotion(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_0012C348(void *a0, int a1);
extern void func_00103760(void *a0, int a1);
extern void pl00_reset(void *a0);
extern char D_005FEE00[];
extern char *D_00586A88;
__attribute__((section(".text.func_0012C540"))) void func_0012C540(void *a0, int a1)
{
  char *s0 = (char *) a0;
  char *s1 = D_00586A88;
  float t = 15.0f;
  int v0;
  *((float *) (s0 + 0x54C)) = t;
  SetEffectPos(0xAA, 0xB, 0, *((void **) (s0 + 0xF0)), -1, 1.0f);
  cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xD1, s0, 0, 0, 0, 0);
  func_0012C348(s0, 0);
  switch (a1)
  {
    default:

    case 0:
      *((int *) (s0 + 0x250)) = (*((int *) (s0 + 0x250))) & 0xFFFFFFFD;
      if ((*((char **) (s0 + 0x68C))) != 0)
    {
      *((int *) ((*((char **) (s0 + 0x68C))) + 0x250)) = (*((int *) ((*((char **) (s0 + 0x68C))) + 0x250))) & 0xFFFFFFFD;
    }
      *((int *) (s0 + 0x15F4)) = (*((int *) (s0 + 0x15F4))) & (~0x1000);
      pl00_reset(s0);
      *((unsigned char *) (s0 + 0x2F5)) = 0x46;
      *((unsigned char *) (s0 + 0x2F6)) = 4;
      v0 = *((int *) (s0 + 0x304));
      *((unsigned char *) (s0 + 0x2F4)) = 0;
      *((unsigned char *) (s0 + 0x2F7)) = 0;
      func_002A8578(s0, (*((int *) (v0 + 0x6F8))) + v0, (*((int *) (v0 + 0x6FC))) + v0, 0, 0.0f, 0, 0);
      moveMotion(s0);
      cModel_calcParts(s0);
      IK_InverseKinematics(s0 + 0x448, s0);
      cModel_calcWorldParts(s0);
      if (s1 != 0)
    {
      func_00103760(s1, 0);
    }
      break;

    case 1:
      if (s1 != 0)
    {
      *((int *) (s0 + 0x15F4)) = (*((int *) (s0 + 0x15F4))) & (~0x1000);
      ClearField15F4Bit1_124F60(s0, 0, 0);
      func_00126770(s0);
      *((int *) (s0 + 0x250)) = (*((int *) (s0 + 0x250))) | 2;
      func_00103760(s1, 1);
      *((float *) (s1 + 0x54C)) = t;
    }
      break;

  }

}
