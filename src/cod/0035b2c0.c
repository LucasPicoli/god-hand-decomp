/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_0035B3F8")))
void func_0035B3F8(int a0, char *a1, int *a2, int *a3) {
    int f8  = *(int *)(a1 + 0x8);
    int fC  = *(int *)(a1 + 0xC);
    int f10 = *(int *)(a1 + 0x10);
    int f14 = *(int *)(a1 + 0x14);
    int f18 = *(int *)(a1 + 0x18);
    int f1E = *(short *)(a1 + 0x1E);
    int v1, r;
    v1 = (((f10 * 30) + (fC / 10)) * 2) + ((f8 * 215892) + (fC * 3598));
    v1 = v1 + (f14 + f18);
    r = (v1 * 1000) + (f1E * 500);
    *a2 = r;
    *a3 = a0;
}

__attribute__((section(".text.func_0035B360")))
void func_0035B360(int a0, char *s, int *out2, int *out3) {
    int d = *(int *)(s + 0xC);
    int t5 = *(int *)(s + 8) * 0x1A574 + d * 0x706;
    int t4 = *(int *)(s + 0x14) + *(int *)(s + 0x18);
    int t0 = (*(int *)(s + 0x10) * 15 + d / 10) * 2 + t5 + t4;
    *out2 = t0 * 1000 + *(short *)(s + 0x1E) * 500;
    *out3 = a0;
}

__attribute__((section(".text.func_0035B2C0")))
void func_0035B2C0(int a0, int *a1, int *a2, int *a3)
{
  int v1;
  int s = (*((short *) (((char *) a1) + 0x1E))) * 500;
  int new_var3;
  int new_var;
  int new_var2;
  new_var = a1[3];
  new_var2 = (a1[2] * 0x15114) + (new_var * 0x59E);
  new_var3 = a1[5] + a1[6];
  v1 = ((a1[4] * 12) + (new_var / 10)) << 1;
  v1 += new_var2;
  v1 += new_var3;
  *a2 = (v1 * 1000) + s;
  *a3 = a0;
}
