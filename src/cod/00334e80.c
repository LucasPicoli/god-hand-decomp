/* cygnus-2.96 matched TU. */
#include "godhand/MpvHandle.h"
#include "godhand/criSj.h"

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
int func_00369F70(MpvErr *err, int code){
  int v = code;
  err->code = v;
  if (v != 0) {
    v = (int)err->fn;
    if (v != 0)
      v = err->fn(err->obj, code);
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

__attribute__((section(".text.SJRBF_GetFlowCnt")))
int SJRBF_GetFlowCnt(SjObj *sj, int lane, int kind){ SjRbf *rbf = (SjRbf *)sj; return rbf->flow[lane][kind]; }

__attribute__((section(".text.MPV_GetDctCnt")))
void MPV_GetDctCnt(char *a0, int *a1, int *a2){
  int *p = (int *)(a0 + 0x78);
  *a1 = p[6];
  *a2 = p[7];
}

__attribute__((section(".text.adxb_DefAddWr")))
void adxb_DefAddWr(int *a0, int a1, int a2){ a0[35] += a2; a0[34] += a2; }

__attribute__((section(".text.sfhds_ReadLong")))
unsigned int sfhds_ReadLong(unsigned char *a0){
  unsigned int v = a0[0];
  v = (v << 8) | a0[1];
  v = (v << 8) | a0[2];
  v = (v << 8) | a0[3];
  return v;
}

struct S_00334e80 { long long sum, mn, mx; int cnt; };
__attribute__((section(".text.func_0035BB40")))
void func_0035BB40(struct S_00334e80 *p){ p->mn = 0x7FFFFFFFFFFFFFFFLL; p->sum = 0; p->mx = 0; p->cnt = 0; }
