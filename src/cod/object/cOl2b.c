/* TU: cOl2b [object] - recovered C++ class. */
#include "include_asm.h"
typedef struct CGUnk_00180310
{
  unsigned char unk[0xA28];
} CGUnk_00180310_t;

__attribute__((section(".text.cOl2b_setOpen")))
void cOl2b_setOpen(CGUnk_00180310_t *a0)
{
  int v0 = *((int *) (((unsigned char *) a0) + 0xA24));
  if (v0 == 1)
  {
    return;
  }
  a0->unk[0x2F4] = 1;
  a0->unk[0x2F5] = 0;
  a0->unk[0x2F6] = 0;
  a0->unk[0x2F7] = 0;
}

__attribute__((section(".text.cOl2b_setClose")))
void cOl2b_setClose(unsigned char *a0)
{
  int new_var;
  new_var = *((int *) (a0 + 0xA24));
  if (new_var == 2)
  {
    return;
  }
  a0[0x2F4] = 2;
 do { a0[0x2F7] = 0; } while (0);
  a0[0x2F5] = 0;
  a0[0x2F6] = 0;
}

__attribute__((section(".text.cOl2b_isActive")))
unsigned char cOl2b_isActive(unsigned char *a0) {
    return a0[0xA28];
}

extern int D_005FEE00;
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);

__attribute__((section(".text.cOl2b_setFire")))
void cOl2b_setFire(char *p)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int b;
    int obj;
    int idx;

    if (*(unsigned char *)(p + 0xA29) != 0) return;
    SetEffect(1, 3, p, 0, -1, 0xFFFFFFFFu);
    idx = 2;
    if ((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (idx >= 0 && idx < b))
        obj = *(int *)(*(int *)(p + 0x278) + idx * 4);
    else
        obj = 0;
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xDD, p, 0, obj, 0, 0);
    b = 1;
    *(unsigned char *)(p + 0xA29) = b;
}
