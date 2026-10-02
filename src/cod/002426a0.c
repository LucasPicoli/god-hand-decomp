/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int D_00462FC0;
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void *Getplayer(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_00281260(void *a0);
extern void ClearBytes2F4To2F7_283170(void *a0);
extern void func_002495E0(void *a0, float f);
extern int D_005850B0;
extern char D_005CB000[];

__attribute__((section(".text.func_002426A0")))
void func_002426A0(void *a0)
{
    char *s0 = (char *)a0;
    float one;

    cCollisionSolidManage_SetActive(&D_00462FC0, s0, 0);
    *(int *)(s0 + 0x16D0) |= 0x11000;
    *(int *)(s0 + 0x16D0) |= 0x20000;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int id = *(int *)(s0 + 0x564);
        int b = *(int *)(s0 + 0x304);
        int p1 = *(int *)(b + 0x3F4) + b;
        int p2 = *(int *)(b + 0x3F8) + b;
        float f = 0.0f;

        if (id == 0x215) {
            f = 25.0f;
        }
        func_002A8578(s0, p1, p2, f, 10, t0, 0);
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) & 0xDFFFFFFF;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 1:
        one = 1.0f;
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        if (0.0f < *(float *)(s0 + 0x16C0)) {
            func_002705D8(s0);
        }
        if ((*(int *)(s0 + 0x16D0) & 0x20000000) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        break;
    case 2:
    {
        int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        int v0 = *(int *)(s0 + 0x304);

        func_002A8578(s0, *(int *)(v0 + 0x1B58) + v0, *(int *)(v0 + 0x1B5C) + v0, 0.0f, 3, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 3:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00249960"))) void func_00249960(void *a0)
{
  char *s0 = (char *) a0;
  int v0;
  int t0;
  float one;
  unsigned char *hs;
  capVu0MagnitudeSqXZ(*((void **) (((char *) Getplayer()) + 0xF0)), &D_005850B0);
  *((int *) (s0 + 0x16D0)) = (*((int *) (s0 + 0x16D0))) | 0x30400;
  switch (*((unsigned char *) (s0 + 0x2F6)))
  {
 do { case 0: *((char *) (s0 + 0x1864)) = 0; t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF; v0 = *((int *) (s0 + 0x304)); func_002A8578(s0, (*((int *) (v0 + 0x3D34))) + v0, (*((int *) (v0 + 0x3D38))) + v0, 0.0f, 10, t0, 0); if ((*((void **) (s0 + 0x748))) != 0) { func_00281260(*((void **) (s0 + 0x748))); } if ((*((void **) (s0 + 0x74C))) != 0) { ClearBytes2F4To2F7_283170(*((void **) (s0 + 0x74C))); } if ((*((void **) (s0 + 0x750))) != 0) { ClearBytes2F4To2F7_283170(*((void **) (s0 + 0x750))); } *((int *) (s0 + 0x16D0)) = (*((int *) (s0 + 0x16D0))) & 0xFCFFFFFF; *((unsigned char *) (s0 + 0x2F6)) = (*((unsigned char *) (s0 + 0x2F6))) + 1; case 1: func_002495E0(s0, 0.0f); moveMotion(s0); one = 1.0f; cObjBase_addNullSpeed_Rotation(s0, one); cObjBase_addNullSpeed(s0, one); hs = (unsigned char *) D_005CB000; break; } while (0);
    default:
      hs = (unsigned char *) D_005CB000;
      break;

  }

  if (hs[0x10] == 0)
  {
    func_00262AA8(s0);
  }
}
