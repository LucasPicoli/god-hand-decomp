/* sn-2.95.3-136 matched TU. */

extern int Forward30F348_31CFE0(void);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_00280EB8(void *a0, int a1, int a2);
extern int D_00569B70;
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern int cEmManage_ChkActiveEm(void *a0, void *a1);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern char D_005864F0[];
extern int cIDManager_getLocalFileName();
extern int cDvd_ReadAlloc();
extern void cDvd_CheckWait();
extern void cIDManager_setIDData();
extern void cIDBase_initialize();
extern void cIDBase_restartAnim();
extern char *cIDBase_getIDWork();
extern void CustomIDWork_Initialize();
extern void CustomIDWork_SetMessNo();
extern void CustomIDWork_SetNumber();
extern void func_001E7600();
extern int D_003C2388;
extern char D_0042BB20[];
extern char D_00583F20[];
extern char D_00754220[];
extern int *D_003C2384;
extern int D_007474A0;
extern void func_00381D38(void *a0, void *a1, void *a2);
extern void func_00380E88(void *a0, void *a1, void *a2);
extern void func_0032DE88(int a0, int a1);
extern void func_0032DEF8(int a0, int a1);
extern void func_0032DF70(int a0, int a1, int a2);
extern void func_0032E040(int a0, int a1);
extern void func_0032B188(int a0, int a1);
extern void func_0032B300(int a0, int a1);
extern void func_00383170(void *a0, void *a1, int a2);
extern void func_003832C8(void *a0, void *a1, int a2);
extern void func_0032DA28(int a0, int a1, int a2);
extern void func_0032BB48(int a0, int a1, int a2);

/* PARKED 100/118 exact, insn delta +1, sn-2.95.3-136 + -f=-fno-gcse (w/7f970_b3.c). Residue: retail's dead 'daddu $s1,$zero,$zero' is reproduced only when z feeds the two level-arm calls, which then emit 'move t0,s1'; level-arm base lands in v1 where retail ties it to a2; 0x568/0x5F0 share one 'li v1,1' in retail. 7 bodies. */








__attribute__((section(".text.func_0027F970")))
void func_0027F970(void *a0)
{
    char *s0 = (char *)a0;
    char *p;
    int ok;
    unsigned long z = 0;

    *(int *)(s0 + 0x1560) |= 1;
    p = *(char **)(s0 + 0x1580);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        ok = 0;
        if (p != 0) {
            ok = *(short *)(p + 0x548) / 2 >= *(short *)(p + 0x54A);
        }
        if (ok && (Forward30F348_31CFE0() & 1)) {
            char *t = *(char **)(s0 + 0x304);
            func_002A8578(s0, *(int *)(t + 0x98) + (int)t, *(int *)(t + 0x9C) + (int)t, 0.0f, 5, z, 0);
        } else {
            int lvl = cCoreSave_getGameLevel(&D_00569B70);
            if (lvl >= 3) {
                char *t = *(char **)(s0 + 0x304);
                func_002A8578(s0, *(int *)(t + 0x6C) + (int)t, *(int *)(t + 0x74) + (int)t, 0.0f, 5, z, 0);
            } else {
                char *t = *(char **)(s0 + 0x304);
                func_002A8578(s0, *(int *)(t + 0x6C) + (int)t, *(int *)(t + 0x70) + (int)t, 0.0f, 5, z, 0);
            }
        }
        *(int *)(s0 + 0x5F0) = 1;
        *(short *)(s0 + 0x568) = 1;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        break;
    }
    if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0) {
        if (*(int *)(s0 + 0x5F0) != 0) {
            *(int *)(s0 + 0x5F0) = 0;
            func_00280EB8(s0, 0, 0);
            func_00280EB8(s0, 0, 1);
            *(short *)(s0 + 0x568) = 0;
        }
    } else {
        *(int *)(s0 + 0x5F0) = 1;
    }
    if (*(short *)(s0 + 0x568) != 0) {
        *(int *)(s0 + 0x1560) |= 2;
    }
}

typedef void *(*vfn)(void *);
inline static long InRange(unsigned short k, int lo, int hi)
{
  long c;
  int t;
  c = 0;
  if (k >= lo)
  {
    t = k < hi;
    c = t;
  }
  return c;
}

__attribute__((section(".text.func_00124C30"))) void func_00124C30(char *s1, int flag)
{
  char *o;
  char *o2;
  char *o3;
  float d;
  float t;
  float at;
  char *pos;
  int v;
  int lo;
  int hi;
  unsigned char ok;
  if ((*((signed char *) (s1 + 0x648))) <= 0)
  {
    Obj0000_Clear_Fields_640_648_124E58(s1);
    return;
  }
  o = *((char **) (s1 + 0x640));
  if (o != 0)
  {
    if (InRange(*((unsigned short *) (o + 0x2FE)), 0x200, 0x300) & 0xFF)
    {
      if (cEmManage_ChkActiveEm(D_005864F0, o) == 0)
      {
        goto clr;
      }
      if ((*((unsigned char *) (o + 0x617))) != 0)
      {
        goto clr;
      }
      if ((*((short *) (o + 0x54A))) <= 0)
      {
        char *vt = *((char **) (o + 0x214));
        if ((*((vfn *) (vt + 0xE4)))(o + (*((short *) (vt + 0xE0)))) == 0)
        {
          goto clr;
        }
      }
    }
    o2 = *((char **) (s1 + 0x640));
    if (InRange(*((unsigned short *) (o2 + 0x2FE)), 0x300, 0x500) & 0xFF)
    {
      if (((*((long *) (o2 + 0x250))) & 0x80008000) != 0)
      {
        goto clr;
      }
      if (func_001B79E0(o2) == 0)
      {
        goto clr;
      }
    }
  }
  if (flag == 0)
  {
    return;
  }
  o3 = *((char **) (s1 + 0x640));
  if (o3 == 0)
  {
    return;
  }
  {
    char *vt = *((char **) (o3 + 0x214));
    char *self = *((char **) (s1 + 0xF0));
    pos = (char *) (*((vfn *) (vt + 0x6C)))(o3 + (*((short *) (vt + 0x68))));
    d = capVu0MagnitudeSqXZ(self, pos);
  }
  if (0.25f < d)
  {
    char *vt;
    char *self;
    char *o4 = *((char **) (s1 + 0x640));
    self = *((char **) (s1 + 0xF0));
    vt = *((char **) (o4 + 0x214));
    pos = (char *) (*((vfn *) (vt + 0x6C)))(o4 + (*((short *) (vt + 0x68))));
    t = Turn_dest(self, pos, *((float *) (s1 + 0x104)), 3.14159274f);
    if (t < 0.0f)
    {
      at = -t;
    }
    else
    {
      at = t;
    }
    t = at;
    if (1.57079637f < t)
    {
      clr:
      Obj0000_Clear_Fields_640_648_124E58(s1);

      return;
    }
  }
  if (36.0f < d)
  {
    Obj0000_Clear_Fields_640_648_124E58(s1);
  }
}

/* func_001E71B8 sn-2.95.3-136: EXACT 105/107, length-exact, REG 2 only: hi(D_00583F20) in v1 (retail) vs v0 (mine) plus the paired addiu; permuter 7 min, no improvement. 8 bodies + permuter. */


















__attribute__((section(".text.func_001E71B8")))
void func_001E71B8(char *a0, int a1)
{
    char buf[0x40];
    int r;
    int i;
    char *w;
    char *b;
    char *g;

    cIDManager_getLocalFileName(D_003C2388, buf, D_0042BB20, -1);
    r = cDvd_ReadAlloc(D_00583F20, buf, a0 + 0x678, D_00754220, 0, 0, 0, 0);
    if (r != 0) {
        cDvd_CheckWait(D_00583F20, r);
        cIDManager_setIDData(*D_003C2384, 0x11, *(int *)(a0 + 0x678));
        cIDBase_initialize(a0, 0x11, a1);
        cIDBase_restartAnim(a0);
        for (i = 0; i < 10; i++)
            CustomIDWork_Initialize(a0 + 0x50 + i * 0x7C, cIDBase_getIDWork(a0, i));
        b = a0 + 0x530;
        cIDBase_initialize(b, 0x11, 2);
        cIDBase_restartAnim(b);
        for (i = 0; i < 2; i++)
            CustomIDWork_Initialize(a0 + 0x580 + i * 0x7C, cIDBase_getIDWork(b, i));
        g = (char *)&D_007474A0;
        if (*(unsigned short *)(g + 0x5B0) == 5)
            CustomIDWork_SetMessNo(a0 + 0x5FC, 0x1001);
        else
            CustomIDWork_SetMessNo(a0 + 0x5FC, 0x1001);
        CustomIDWork_SetNumber(a0 + 0x50, 0);
        func_001E7600(a0);
    }
}

typedef struct 
{
  int w[5];
} Word5;
typedef struct 
{
  int w[4];
} Word4;














__attribute__((section(".text.func_00382F40"))) int func_00382F40(char *a0, char *a1)
{
  char *s3 = a0;
  char *s0 = a1;
  int *t = *((int **) (s0 + 0xF8));
  char *s2;
  char *s5;
  char *s1;
  char *s4;
  int v;
  int nv;
  int nv2;
  int r;
  if ((((t[0] == 0) && (t[1] == 0)) && (t[2] == 0)) && (t[3] == 0))
  {
    return 1;
  }
  s2 = s0 + 0x34;
  s5 = s0 + 0x6C;
  s1 = s0 + 0xA4;
  s4 = s0 + 0xCC;
  if (s0[3] & 1)
  {
    func_00381D38(s3, s1, s0);
  }
  else
  {
    func_00380E88(s3, s2, s0);
  }
  if (((*((unsigned char *) (s0 + 3))) & 2) != 0)
  {
    v = func_00381B38(s3, s1, s0);
    if (v != 0)
    {
      *((unsigned char *) (s0 + 1)) = v;
      return 1;
    }
    func_0032DE88(*((int *) (s1 + 0x20)), 1);
    func_0032DEF8(*((int *) (s1 + 0x20)), 1);
    func_0032DF70(*((int *) (s1 + 0x20)), 1, 1);
    *((unsigned char *) s0) = 0;
    func_0032E040(*((int *) (s1 + 0x20)), 0);
    ((int *) s1)[0] = ((int *) s4)[0];
    ((int *) s1)[1] = ((int *) s4)[1];
    ((int *) s1)[2] = ((int *) s4)[2];
    ((int *) s1)[3] = ((int *) s4)[3];
    nv2 = ((int *) s4)[4];
    ((int *) s1)[4] = nv2;
    func_00383170(s3, s0, 1);
    func_003832C8(s3, s0, 1);
    func_0032DA28(*((int *) (s1 + 0x20)), 0xFF, *((unsigned char *) (s3 + 6)));
    nv = *((unsigned char *) (s0 + 3));
    nv2 = *((unsigned char *) (s3 + 6));
    nv |= 1;
  }
  else
  {
    v = func_00380AE8(s3, s2, s0);
    if (v != 0)
    {
      *((unsigned char *) (s0 + 1)) = v;
      return 1;
    }
    func_0032B188(*((int *) (s2 + 0x30)), 1);
    *((unsigned char *) s0) = 0;
    func_0032B300(*((int *) (s2 + 0x30)), 0);
    ((int *) s2)[0] = ((int *) s5)[0];
    ((int *) s2)[1] = ((int *) s5)[1];
    ((int *) s2)[2] = ((int *) s5)[2];
    ((int *) s2)[3] = ((int *) s5)[3];
    func_00383170(s3, s0, 0);
    func_003832C8(s3, s0, 0);
    func_0032BB48(*((int *) (s2 + 0x30)), 0xFF, *((unsigned char *) (s3 + 6)));
    nv = *((unsigned char *) (s0 + 3));
    nv2 = *((unsigned char *) (s3 + 6));
    nv &= 0xFE;
  }
  *((unsigned char *) (s0 + 2)) = nv2;
  *((unsigned char *) (s0 + 3)) = nv;
  return 0;
}
