/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_0038C018")))
int func_0038C018(int a0, int a1) { int v0 = *(int *)(a0 + 8); *(int *)(a0 + 8) = a1; return v0; }

__attribute__((section(".text.func_0038C090")))
long long func_0038C090(int a0, long long a1) { long long v0 = *(long long *)(a0 + 0x10); *(long long *)(a0 + 0x10) = a1; return v0; }

__attribute__((section(".text.AIXSJD_GetSfreq")))
int AIXSJD_GetSfreq(int a0, int a1) { a1 = (a1 << 4) + a0; return *(int *)(a1 + 0xB4); }

__attribute__((section(".text.func_0038C0A8")))
short func_0038C0A8(int a0, short a1) { short v0 = *(short *)(a0 + 0x18); *(short *)(a0 + 0x18) = a1; return v0; }

__attribute__((section(".text.func_0038C0C0")))
int func_0038C0C0(int a0, int a1) { int v0 = *(int *)(a0 + 4); *(int *)(a0 + 4) = a1; return v0; }

__attribute__((section(".text.func_00355630")))
void func_00355630(int *a0) { if (a0 != 0) *a0 = 0; }

__attribute__((section(".text.m2v_SetPicUsrBuf")))
void m2v_SetPicUsrBuf(int a0, int a1, int a2) { a0 += 0x14C; *(int *)(a0 + 0) = a1; *(int *)(a0 + 4) = a2; }
