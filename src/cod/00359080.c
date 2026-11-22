/* cygnus-2.96. */

extern int Obj34D8_SetGlobalEE0B8_IfField48(void *a0);
extern int func_0034DD70(int a, int b);
extern int SetFieldIfUnset_359218(void *self, int flag);
extern int SFTRN_CallTrtTrif(void *self, int a, int b, int *c, int *d);
extern void (*D_003EE304)(void *self, int v);
extern long func_0035BA58(void);
__attribute__((section(".text.SFD_GetIdFrm")))
int SFD_GetIdFrm(char *self, int *slot, int *count)
{
  int n;
  void (*fn)(void *, int);
  *count = 0;
  *slot = -1;
  if (Obj34D8_SetGlobalEE0B8_IfField48(self) != 0)
  {
    func_0034DD70(0, 0xFF00013A);
    return 0;
  }
  if (SetFieldIfUnset_359218(self, 2) != 0)
  {
    return 0;
  }
  SFTRN_CallTrtTrif(self, 6, 0xB, count, slot);
  fn = D_003EE304;
  if (fn == 0)
  {
    n = *count;
  }
  else
  {
    fn(self, *count);
    n = *count;
  }
  if (n == 0)
  {
    return 0;
  }
  n = *((int *) (self + 0x968));
  if (n == 0)
  {
    *((long *) (self + 0x3780)) = func_0035BA58();
    n = *((int *) (self + 0x968));
  }
  *((int *) (self + 0x968)) = 1;
  *((int *) (self + 0x968)) = n + (*((int *) (self + 0x968)));
  return 1;
}
