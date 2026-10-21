/* cygnus-2.96 matched TU. */
#include "godhand/criStm.h"
#include "godhand/sync.h"

extern void *func_003A52F0(void *p, int v, int n);
extern void func_00325DF0(void);
extern void func_00325FA8(void);
extern void func_0033BFB8(void);
extern void func_0033BFE8(void);
extern void SetFlagAndForward_325EF8(void);
extern int func_00348210(int *a, int *b, int *c);
extern int func_0033B810(int type, int arg0, int arg1, int arg2);
extern void func_0035FF98(int);
extern int D_003EE800;
extern void func_0036CB58(int);
extern int D_003F1EC8;
extern int D_00760D88;
extern int D_00760D8C;
extern int GetArrayElemA0C_35A1C8(int, int);
extern int func_0035E080(int, int *);
extern void Obj33F8_Init_D003EB858_F888(void);
extern int func_0033C520(void);
extern void func_0033C708(int);

__attribute__((section(".text.func_0033C728")))
void func_0033C728(void)
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
    if (func_0035E080(value, &slot) == 1)
        return slot;
    return -1;
}



__attribute__((section(".text.func_003B06C8")))
unsigned int func_003B06C8(void)
{
    unsigned int status;
    GH_MFC0_STATUS(status);
    return !(status & 1);
}



__attribute__((section(".text.func_00325F20")))
void func_00325F20(void)
{
    func_0033BFB8();
    func_00325DF0();
    func_00325FA8();
    SetFlagAndForward_325EF8();
    func_0033BFE8();
}


__attribute__((section(".text.func_00348A70")))
int func_00348A70(int arg0, int arg1, int arg2)
{
    int result = func_0033B810(6, arg0, arg1, arg2);
    D_00760D88 = result;
    return result;
}

__attribute__((section(".text.func_00348AC8")))
int func_00348AC8(int arg0, int arg1, int arg2)
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

__attribute__((section(".text.func_0034B618")))
void *func_0034B618(char *self)
{
    char *node = *(char **)(self + 0x36B0);
    char *inner = *(char **)(self + 0x2004);
    if (node == 0)
        return 0;
    if (*(int *)(inner + 0x40) <= 0)
        return node + 0xD0C;
    return 0;
}

__attribute__((section(".text.func_003553C8")))
void *func_003553C8(char *self)
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

__attribute__((section(".text.func_0034A6F8")))
int func_0034A6F8(int a0, int *a1, int *a2) {
    int *r = func_0034B618(a0);
    if (r == 0) return -1;
    *a1 = r[3];
    *a2 = r[4];
    return 0;
}

__attribute__((section(".text.func_0035FEF0")))
int func_0035FEF0(void) {
    int *s0 = (int *)func_0035FF48();
    if (s0 == 0) return 0;
    func_0035FF98((int)s0);
    D_003EE800 += 1;
    *s0 = 1;
    return (int)s0;
}

__attribute__((section(".text.func_0036CAB0")))
int func_0036CAB0(void) {
    int *s0 = (int *)func_0036CB08();
    if (s0 == 0) return 0;
    func_0036CB58((int)s0);
    D_003F1EC8 += 1;
    *s0 = 1;
    return (int)s0;
}
