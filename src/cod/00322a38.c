/* cygnus-2.96 matched TU. */
#include "godhand/MpvHandle.h"

extern void func_0034DD70(int, int);
extern void UTY_MemcpyByte(int, int, int);
extern char D_00766C28[];
extern void func_0036D7E0(int);
extern char D_003F2048[];
extern void func_0032A6D0(int);
extern void func_0034C2A0(int, int, int);
extern void SFBUF_SetTermFlg(int, int, int);
extern void ADXT_SetOutVol(int);
extern void UTY_MemsetDword(int, int, int);
extern void func_0032A838(int);
extern void func_0032B830(int);
extern void func_0032AAA0(int);
extern void adxf_LoadPtNwEx(int, int, int, int, int, int);
extern char D_003C532F[];

__attribute__((section(".text.func_0034B9E0")))
void func_0034B9E0(int a0, int a1) { func_0034DD70(a0, 0xff000a01); }

__attribute__((section(".text.sfmpvp_RestoreMpvp")))
void sfmpvp_RestoreMpvp(int a0, int a1, int a2) { UTY_MemcpyByte(((*(int *)((char *)a0 + 0x1fc0)) + 0x1150), D_00766C28, 0x48); }

__attribute__((section(".text.func_0034E048")))
void func_0034E048(int a0, int a1) { func_0034DD70(a0, 0xff000501); }

__attribute__((section(".text.func_0036D7C0")))
void func_0036D7C0(int a0) { func_0036D7E0(D_003F2048); }

__attribute__((section(".text.func_0034BA20")))
void func_0034BA20(int a0, int a1) { func_0034DD70(a0, 0xff000a01); }

__attribute__((section(".text.func_0034FF58")))
void func_0034FF58(int a0, int a1) { func_0034DD70(a0, 0xff000d0b); }

__attribute__((section(".text.func_00349BA8")))
void func_00349BA8(int a0) { func_0032A6D0((*(int *)((char *)(*(int *)((char *)a0 + 0x2004)) + 0x0))); }

__attribute__((section(".text.SFMEM_GetWrite")))
void SFMEM_GetWrite(int a0, int a1, int a2) { func_0034C2A0(a0, (*(int *)((char *)a0 + 0x1f44)), a1); }

__attribute__((section(".text.func_0034BA40")))
void func_0034BA40(int a0, int a1) { func_0034DD70(a0, 0xff000a01); }

__attribute__((section(".text.func_0034B548")))
void func_0034B548(int a0, int a1) { func_0034DD70(a0, 0xff000c03); }

__attribute__((section(".text.sfmpv_SetTermDst")))
void sfmpv_SetTermDst(int a0, int a1, int a2) { SFBUF_SetTermFlg(a0, (*(int *)((char *)a0 + 0x1fcc)), a1); }

__attribute__((section(".text.func_0034BA00")))
void func_0034BA00(int a0, int a1) { func_0034DD70(a0, 0xff000a01); }

__attribute__((section(".text.func_0034FF18")))
void func_0034FF18(int a0, int a1) { func_0034DD70(a0, 0xff000d0b); }

__attribute__((section(".text.func_0034FF38")))
void func_0034FF38(int a0, int a1) { func_0034DD70(a0, 0xff000d0b); }

__attribute__((section(".text.func_0034B568")))
void func_0034B568(int a0, int a1) { func_0034DD70(a0, 0xff000c03); }

__attribute__((section(".text.func_00349BE8")))
void func_00349BE8(int a0) { ADXT_SetOutVol((*(int *)((char *)(*(int *)((char *)a0 + 0x2004)) + 0x0))); }

__attribute__((section(".text.func_0034FF78")))
void func_0034FF78(int a0, int a1) { func_0034DD70(a0, 0xff000d0b); }

__attribute__((section(".text.sfadxt_SetTermDst")))
void sfadxt_SetTermDst(int a0, int a1, int a2) { SFBUF_SetTermFlg(a0, (*(int *)((char *)a0 + 0x2010)), a1); }

__attribute__((section(".text.func_00354DC8")))
void func_00354DC8(int a0, int a1) { func_0034DD70(a0, 0xff000f0d); }

__attribute__((section(".text.sfmpv_InitPicAtr")))
void sfmpv_InitPicAtr(int a0, int a1, int a2) { UTY_MemsetDword(a0, (-1), 0x20); }

__attribute__((section(".text.func_0034B508")))
void func_0034B508(int a0, int a1) { func_0034DD70(a0, 0xff000c03); }

__attribute__((section(".text.func_00349BC8")))
void func_00349BC8(int a0) { func_0032A838((*(int *)((char *)(*(int *)((char *)a0 + 0x2004)) + 0x0))); }

__attribute__((section(".text.func_0034A3E0")))
void func_0034A3E0(int a0) { func_0032B830((*(int *)((char *)(*(int *)((char *)a0 + 0x2004)) + 0x0))); }

__attribute__((section(".text.func_00369E60")))
void func_00369E60(int a0) { func_00369E80(&D_003F1AA0); }

__attribute__((section(".text.func_00349C08")))
void func_00349C08(int a0) { func_0032AAA0((*(int *)((char *)(*(int *)((char *)a0 + 0x2004)) + 0x0))); }

__attribute__((section(".text.func_0034B528")))
void func_0034B528(int a0, int a1) { func_0034DD70(a0, 0xff000c03); }

__attribute__((section(".text.func_0034E068")))
void func_0034E068(int a0, int a1) { func_0034DD70(a0, 0xff000501); }

__attribute__((section(".text.sfmpvp_SaveMpvp")))
void sfmpvp_SaveMpvp(int a0, int a1, int a2) { UTY_MemcpyByte(D_00766C28, ((*(int *)((char *)a0 + 0x1fc0)) + 0x1150), 0x48); }

__attribute__((section(".text.func_00354DE8")))
void func_00354DE8(int a0, int a1) { func_0034DD70(a0, 0xff000f0d); }

__attribute__((section(".text.func_00322A38")))
void func_00322A38(int a0, int a1, int a2, int a3, int t0, int t1) { adxf_LoadPtNwEx(a0, a1, a2, a3, ((int)D_003C532F & (-64)), 0x800); }
