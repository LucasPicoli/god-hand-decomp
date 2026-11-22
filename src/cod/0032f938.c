/* cygnus-2.96 matched TU. */
#include "godhand/criStm.h"
#include "godhand/sync.h"
#include "godhand/globals.h"

extern void *func_003A52F0(void *p, int v, int n);
extern void ADXPS2_ResumeIdleThrd(void);
extern void func_00325FA8(void);
extern void func_0033BFB8(void);
extern void func_0033BFE8(void);
extern void SetFlagAndForward_325EF8(void);
extern int func_00348210(int *a, int *b, int *c);
extern int func_0033B810(int type, int arg0, int arg1, int arg2);
extern void sfxzmv_InitHn(int);
extern int D_003EE800;
extern void sfxalp_InitHn(int);
extern int D_003F1EC8;
extern int GetArrayElemA0C_35A1C8(int, int);
extern int SFH_AnlyMaxFrmNum(int, int *);
extern void Obj33F8_Init_D003EB858_F888(void);
extern int func_0033C520(void);
extern void func_0033C708(int);

__attribute__((section(".text.ADXB_Init")))
void ADXB_Init(void)
{
    Obj33F8_Init_D003EB858_F888();
    func_0033C520();
    func_003A52F0(D_003E9D60, 0, sizeof(D_003E9D60));
    func_0033C708(0);
}


__attribute__((section(".text.func_0034B8D8")))
int func_0034B8D8(int value)
{
    GetArrayElemA0C_35A1C8(value, 6);
    return 0;
}

__attribute__((section(".text.func_00344F30")))
int func_00344F30(int value)
{
    int slot;
    if (SFH_AnlyMaxFrmNum(value, &slot) == 1)
        return slot;
    return -1;
}



__attribute__((section(".text.QueryIntrContext")))
unsigned int QueryIntrContext(void)
{
    unsigned int status;
    GH_MFC0_STATUS(status);
    return !(status & 1);
}



__attribute__((section(".text.ADXM_WaitVsync")))
void ADXM_WaitVsync(void)
{
    func_0033BFB8();
    ADXPS2_ResumeIdleThrd();
    func_00325FA8();
    SetFlagAndForward_325EF8();
    func_0033BFE8();
}


__attribute__((section(".text.MWSFSVM_EntryIdleFunc")))
int MWSFSVM_EntryIdleFunc(int arg0, int arg1, int arg2)
{
    int result = func_0033B810(6, arg0, arg1, arg2);
    D_00760D88 = result;
    return result;
}

__attribute__((section(".text.MWSFSVM_EntryMainFunc")))
int MWSFSVM_EntryMainFunc(int arg0, int arg1, int arg2)
{
    int result = func_0033B810(5, arg0, arg1, arg2);
    D_00760D8C = result;
    return result;
}

__attribute__((section(".text.func_003481D8")))
int func_003481D8(void)
{
    int a;
    int b;
    int c;

    return func_00348210(&a, &b, &c);
}

__attribute__((section(".text.sfadxt_GetHd")))
void *sfadxt_GetHd(char *self)
{
    char *node = *(char **)(self + 0x36B0);
    char *inner = *(char **)(self + 0x2004);
    if (node == 0)
        return 0;
    if (*(int *)(inner + 0x40) <= 0)
        return node + 0xD0C;
    return 0;
}

__attribute__((section(".text.sfmpv_GetHd")))
void *sfmpv_GetHd(char *self)
{
    char *node = *(char **)(self + 0x36B0);
    char *inner = *(char **)(self + 0x1FC0);
    if (node == 0)
        return 0;
    if (*(int *)(inner + 0x88) <= 0)
        return node + 0xAD0;
    return 0;
}

__attribute__((section(".text.func_0032F938")))
void func_0032F938(unsigned char *a0) {
    func_003A52F0(a0, 0, 0x18B8);
    *(int *)(a0 + 0x210) = 1;
    *(int *)(a0 + 0x1894) = 1;
    *(short *)(a0 + 0x189A) = 1;
    *(short *)(a0 + 0x1898) = 0;
    *(short *)(a0 + 0x189C) = 0;
    *(short *)(a0 + 0x189E) = 0;
    a0[0xC] = 1;
}

__attribute__((section(".text.sfadxt_GetNchSfreq")))
int sfadxt_GetNchSfreq(int a0, int *a1, int *a2) {
    int *r = sfadxt_GetHd(a0);
    if (r == 0) return -1;
    *a1 = r[3];
    *a2 = r[4];
    return 0;
}

__attribute__((section(".text.func_0035FEF0")))
void *func_0035FEF0(void) {
    int *s0 = (int *)sfxzmv_SearchFreeHn();
    if (s0 == 0) return 0;
    sfxzmv_InitHn((int)s0);
    D_003EE800 += 1;
    *s0 = 1;
    return s0;
}

__attribute__((section(".text.func_0036CAB0")))
void *func_0036CAB0(void) {
    int *s0 = (int *)sfxalp_SearchFreeHn();
    if (s0 == 0) return 0;
    sfxalp_InitHn((int)s0);
    D_003F1EC8 += 1;
    *s0 = 1;
    return s0;
}
