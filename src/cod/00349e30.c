/* cygnus-2.96 matched TU. */

extern void func_00349E48(void);
extern void func_0034CBB0(void);
extern void func_0034E1F0(void);
extern void func_0034DD70(void);
extern void MPS_Destroy(void);
extern void func_00350718(void);
extern void func_0036C3D0(void);
extern void func_0035A620(void);
extern void func_0035AB98(void);
extern void func_00360740(void);
extern void func_003607A0(void);
extern void func_0035FEA8(void);
extern void func_00360298(void);
extern void func_00368E80(void);
extern void func_0036CCF0(void);
extern void func_0036CD18(void);
extern void func_0036CA68(void);
extern void func_003BA088(void);
extern void Forward33B568_33B658(void);
extern void Forward33B5C8_33B670(void);
extern void func_0034C2D0(int a0, int a1, int a2, int a3);
extern void func_0034C3A8(int a0, int a1, int a2, int a3);
extern void func_0036CD48(void *a0);
extern void func_0034B648(int a0, int a1);
extern void func_0033F130(void *a0);

__attribute__((section(".text.func_00349E30")))
void func_00349E30(void) { func_00349E48(); }

__attribute__((section(".text.func_0034BA68")))
void func_0034BA68(void) { func_0034CBB0(); }

__attribute__((section(".text.func_0034E1D8")))
void func_0034E1D8(void) { func_0034E1F0(); }

__attribute__((section(".text.func_0034FE78")))
void func_0034FE78(void) { func_0034DD70(); }

__attribute__((section(".text.Tramp_MPS_Destroy_34FEE0")))
void Tramp_MPS_Destroy_34FEE0(void) { MPS_Destroy(); }

__attribute__((section(".text.func_00350700")))
void func_00350700(void) { func_00350718(); }

__attribute__((section(".text.func_00354D68")))
void func_00354D68(void) { func_0036C3D0(); }

__attribute__((section(".text.func_00357240")))
void func_00357240(void) { func_0035A620(); }

__attribute__((section(".text.func_0035AB80")))
void func_0035AB80(void) { func_0035AB98(); }

__attribute__((section(".text.func_0035FE60")))
void func_0035FE60(void) { func_00360740(); }

__attribute__((section(".text.func_0035FE78")))
void func_0035FE78(void) { func_003607A0(); }

__attribute__((section(".text.func_0035FE90")))
void func_0035FE90(void) { func_0035FEA8(); }

__attribute__((section(".text.func_00360280")))
void func_00360280(void) { func_00360298(); }

__attribute__((section(".text.func_00368E68")))
void func_00368E68(void) { func_00368E80(); }

__attribute__((section(".text.func_0036C658")))
void func_0036C658(void) { func_0036CCF0(); }

__attribute__((section(".text.func_0036C670")))
void func_0036C670(void) { func_0036CD18(); }

__attribute__((section(".text.func_0036CA50")))
void func_0036CA50(void) { func_0036CA68(); }

__attribute__((section(".text.func_003B9D30")))
void func_003B9D30(void) { func_003BA088(); }

__attribute__((section(".text.func_003B9DB0")))
void func_003B9DB0(void) { Forward33B568_33B658(); }

__attribute__((section(".text.func_003B9DC8")))
void func_003B9DC8(void) { Forward33B5C8_33B670(); }

__attribute__((section(".text.func_0034AAC8")))
int func_0034AAC8(int *a0) { return func_0034CA98(a0, *(int *)((char *)a0 + 0x200C)); }

__attribute__((section(".text.func_0034AAE0")))
int func_0034AAE0(int *a0) { return func_0034CA98(a0, *(int *)((char *)a0 + 0x2010)); }

__attribute__((section(".text.func_0034C2A0")))
void func_0034C2A0(int a0, int a1, int a2) { func_0034C2D0(a0, a1, a2, 0); }

__attribute__((section(".text.func_0034C378")))
void func_0034C378(int a0, int a1, int a2) { func_0034C3A8(a0, a1, a2, 0); }

__attribute__((section(".text.func_0034C390")))
void func_0034C390(int a0, int a1, int a2) { func_0034C3A8(a0, a1, a2, 1); }

__attribute__((section(".text.func_003508C0")))
int func_003508C0(int *a0) { return func_0034CA98(a0, *(int *)((char *)a0 + 0x1FCC)); }

__attribute__((section(".text.func_00351C00")))
int func_00351C00(int *a0) { return func_0034CA98(a0, *(int *)((char *)a0 + 0x1FC8)); }

__attribute__((section(".text.func_00357490")))
int func_00357490(int a0) { return func_0035C238(a0, 2); }

__attribute__((section(".text.func_003587D0")))
int func_003587D0(int a0) { return func_0035C238(a0, 3); }

__attribute__((section(".text.func_0036C688")))
void func_0036C688(char *a0) { func_0036CD48(*(void **)(a0 + 0x3B4)); }

__attribute__((section(".text.func_0036CA38")))
void func_0036CA38(int *a0, int a1) { func_0034B648(*(int *)((char *)a0 + 0x3C), a1); }

__attribute__((section(".text.func_003B9D48")))
void func_003B9D48(void *a0, void *a1) { func_0033F130(a1); }
