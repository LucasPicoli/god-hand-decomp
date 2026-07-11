/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_00368EE0")))
int func_00368EE0(int *a0, int a1){
  int v = a1;
  a0[2] = v;
  if (v != 0) {
    v = a0[0];
    if (v != 0)
      v = ((int (*)(int))v)(a0[1]);
  }
  return v;
}

__attribute__((section(".text.func_00369F70")))
int func_00369F70(int *a0, int a1){
  int v = a1;
  a0[2] = v;
  if (v != 0) {
    v = a0[0];
    if (v != 0)
      v = ((int (*)(int))v)(a0[1]);
  }
  return v;
}

__attribute__((section(".text.func_0036D938")))
int func_0036D938(int *a0, int a1){
  int v = a1;
  a0[2] = v;
  if (v != 0) {
    v = a0[0];
    if (v != 0)
      v = ((int (*)(int))v)(a0[1]);
  }
  return v;
}

__attribute__((section(".text.func_00334E80")))
int func_00334E80(signed char c){ return c == 0x5C ? 0x2F : c; }

__attribute__((section(".text.func_0033A010")))
int func_0033A010(char *a0, int a1, int a2){ return ((int *)(a0 + 0x28))[a1*2 + a2]; }

__attribute__((section(".text.func_0036C3B8")))
void func_0036C3B8(char *a0, int *a1, int *a2){
  int *p = (int *)(a0 + 0x78);
  *a1 = p[6];
  *a2 = p[7];
}

__attribute__((section(".text.func_0033C7A0")))
void func_0033C7A0(int *a0, int a1, int a2){ a0[35] += a2; a0[34] += a2; }

__attribute__((section(".text.func_0034D188")))
unsigned int func_0034D188(unsigned char *a0){
  unsigned int v = a0[0];
  v = (v << 8) | a0[1];
  v = (v << 8) | a0[2];
  v = (v << 8) | a0[3];
  return v;
}

struct S_00334e80 { long long sum, mn, mx; int cnt; };
__attribute__((section(".text.func_0035BB40")))
void func_0035BB40(struct S_00334e80 *p){ p->mn = 0x7FFFFFFFFFFFFFFFLL; p->sum = 0; p->mx = 0; p->cnt = 0; }
