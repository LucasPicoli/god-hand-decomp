/* sn-2.95.3-136 matched TU. */
#include "godhand/Slot2.h"

extern void displayScrollLayer(int a0, int a1);
extern void InitAllocBuffer_14FE08(void *a0, int a1);
extern void func_003A52F0(void *d, int c, int n);
extern void func_0031A300(void *a0, int a1, void *a2);
extern void func_0031A320(void *a0, int a1);
extern void SetCustomIDSlotNumber_1F4C40(void *a0, int a1, int a2);
extern void func_001F4B98(void *a0, int a1, int a2, int a3);
extern void func_001F4CA8(void *a0, int a1, int a2, int a3);
extern void func_001F4FF0(void *a0, int a1, int a2, int a3);
extern void NoOp_1F5098(void *a0, int a1, int a2, int a3);
extern void func_001F50A0(void *a0, int a1, int a2, int a3);
extern void SetCustomIDSlotNumberAlt_1F5210(void *a0, int a1, int a2, int a3);
extern void func_001F5278(void *a0, int a1, int a2);
extern char D_00569B70[];
extern void func_002E0DE8(int a0, int a1, int a2, void *a3);
extern void func_00381CE0(void *a0, void *a1);
extern void func_00380DC0(void *a0);
extern void func_00381DC0(void *a0, void *a1, void *a2);
extern void func_00381D38(void *a0, void *a1, void *a2);
extern void func_00381010(void *a0, void *a1, int a2);
extern void func_00381E30(void *a0, void *a1);
extern void func_00381EA0(void *a0, void *a1);
extern void func_0032A160(int a0, void *a1, void *a2);
extern void func_00382898(void *a0);
extern void func_00380678(void *a0, int a1, int a2, int a3, int a4);
extern char D_0045C760[];
extern char D_0045C780[];

typedef struct { int w[15]; } Tbl15;
extern Tbl15 D_0042B890;


/* Slot2 scroll counter step: every 0x15 frames pick the next row of table
 * D_0042B890 and show or hide those layers (bit 0x4000 flips each time). */
__attribute__((section(".text.func_001E4010")))
void func_001E4010(Slot2 *self)
{
    int tbl[5][3];
    int *lay;
    unsigned v;
    unsigned w;
    int i, j;

    v = self->scroll;
    if ((v & 0x8000) == 0)
        return;
    v = v + 1;
    self->scroll = v;
    if ((v & 0x3FF) < 0x15)
        return;
    w = (~v & 0x4000) | (v & 0x3800);
    w |= 0x8000;
    *(Tbl15 *)tbl = D_0042B890;
    self->scroll = w;
    i = (w >> 11) & 7;
    j = i;
    if (w & 0x4000) {
        lay = (int *)self->layer;
        displayScrollLayer(*(int *)((char *)lay + (tbl[i][0] << 2)), 1);
        displayScrollLayer(*(int *)((char *)lay + (tbl[i][1] << 2)), 1);
        lay += tbl[i][2];
        displayScrollLayer(*lay, 1);
        displayScrollLayer(*(int *)(self->layer + 0x2C), 1);
    } else {
        lay = (int *)self->layer;
        displayScrollLayer(*(int *)((char *)lay + (tbl[j][0] << 2)), 0);
        displayScrollLayer(*(int *)((char *)lay + (tbl[j][1] << 2)), 0);
        lay += tbl[j][2];
        displayScrollLayer(*lay, 0);
        displayScrollLayer(*(int *)(self->layer + 0x2C), 0);
    }
}

__attribute__((section(".text.func_0031A0E8")))
void func_0031A0E8(char *a0)
{
    char *s0 = a0;
    int i = 1;
    char *p9 = s0 + 0xA00;
    char *p8 = s0 + 0x900;
    char *p7 = s0 + 0x800;
    char *p6 = s0 + 0x700;
    char *p5 = s0 + 0x600;
    char *p4 = s0 + 0x500;
    char *p3 = s0 + 0x300;
    char *p2 = s0 + 0x200;
    char *p1 = s0 + 0x100;
    char *p0 = s0;

    for (; i >= 0; i--) {
        InitAllocBuffer_14FE08(p0, 2);
        p0 += 0x80;
        InitAllocBuffer_14FE08(p1, 0x10);
        p1 += 0x80;
        InitAllocBuffer_14FE08(p2, 6);
        p2 += 0x80;
        InitAllocBuffer_14FE08(p3, 0x400);
        p3 += 0x80;
        InitAllocBuffer_14FE08(p4, 0xD);
        p4 += 0x80;
        InitAllocBuffer_14FE08(p5, 0x400);
        p5 += 0x80;
        InitAllocBuffer_14FE08(p6, 9);
        p6 += 0x80;
        InitAllocBuffer_14FE08(p7, 2);
        p7 += 0x80;
        InitAllocBuffer_14FE08(p8, 3);
        p8 += 0x80;
        InitAllocBuffer_14FE08(p9, 2);
        p9 += 0x80;
    }
    *(char *)(s0 + 0xB58) = 0;
    func_003A52F0(s0 + 0xB00, 0, 0x58);
    func_0031A300(s0, 0, s0);
    func_0031A300(s0, 1, s0 + 0x100);
    func_0031A300(s0, 3, s0 + 0x200);
    func_0031A300(s0, 2, s0 + 0x300);
    func_0031A300(s0, 4, s0 + 0x500);
    func_0031A300(s0, 5, s0 + 0x600);
    func_0031A300(s0, 6, s0 + 0x700);
    func_0031A300(s0, 7, s0 + 0x800);
    func_0031A300(s0, 8, s0 + 0x900);
    func_0031A300(s0, 9, s0 + 0xA00);
    func_0031A320(s0, 10);
}

__attribute__((section(".text.func_001F4068")))
void func_001F4068(char *a0, unsigned short a1, short *a2, int a3)
{
    char *s2;

    if (a1 < 7) {
        s2 = a0 + 0x60;
        SetCustomIDSlotNumber_1F4C40(s2, a1, a2[0]);
        if (func_001F4530(a0, a2[0], *(unsigned short *)((char *)a2 + 4)) != 0) {
            func_001F4B98(s2, a1, func_001FC4D0(D_00569B70, a2[0]), a3);
            func_001F4CA8(s2, a1, a2[4], a3);
            func_001F4FF0(s2, a1, a2[5], a3);
            NoOp_1F5098(s2, a1, 0, a3);
            func_001F50A0(s2, a1, *(int *)((char *)a2 + 0xC), a3);
            SetCustomIDSlotNumberAlt_1F5210(s2, a1,
                func_001FC4D0(D_00569B70, a2[0]) ? 0 : *(int *)((char *)a2 + 0x10), a3);
            func_001F5278(s2, a1, 0);
        } else {
            func_001F4B98(s2, a1, func_001FC4D0(D_00569B70, a2[0]), 0);
            func_001F4CA8(s2, a1, a2[4], 0);
            func_001F4FF0(s2, a1, a2[5], 0);
            NoOp_1F5098(s2, a1, 0, 0);
            func_001F50A0(s2, a1, *(int *)((char *)a2 + 0xC), 0);
            SetCustomIDSlotNumberAlt_1F5210(s2, a1,
                func_001FC4D0(D_00569B70, a2[0]) ? 0 : *(int *)((char *)a2 + 0x10), 0);
            func_001F5278(s2, a1, a3);
        }
    }
}

__attribute__((section(".text.func_00381940")))
int func_00381940(char *a0, char *a1)
{
    char *s0 = a0;
    char *s1 = a1;
    char *s2 = s0 + 0x318;
    char *s3 = s0 + 0x348;
    char buf[0x10];
    int v;

    if (*(int *)(*(int *)(s0 + 0x3C) - 0x10) == 0) {
        if ((*(int *)(s1 + 0x34) & 0xF0) != 0) {
            *(char *)s0 = 0;
            return 1;
        }
        func_002E0DE8(0xE, 0xA, 0xE, D_0045C760);
        func_002E0DE8(0xD, 0xC, 8, D_0045C780);
        return 1;
    }
    if (*(unsigned char *)(s2 + 1) != 0) {
        if ((*(int *)(s1 + 0x34) & 0xF0) != 0)
            *(char *)(s2 + 1) = 0;
    } else {
        func_00381CE0(s0, s3);
        if ((*(int *)(s1 + 0x34) & 0x40) != 0) {
            *(char *)s0 = 0;
            *(int *)(s2 + 0x2C) = 0;
            return 1;
        }
        if ((*(int *)(s1 + 0x34) & 0x20) != 0) {
            if ((*(int *)(s1 + 0x2C) & 2) != 0)
                func_00380DC0(s0);
            if (func_00381BC8(s0, s2) != 0)
                goto done;
        }
        if ((*(int *)(s1 + 0x34) & 0x80) != 0)
            func_00381DC0(s0, s3, s2);
        if ((*(int *)(s1 + 0x34) & 0x10) != 0)
            func_00381D38(s0, s3, s2);
        func_00381010(s0, s1, 3);
        func_00381E30(s0, s1);
        func_00381EA0(s0, s1);
        if (*(int *)(s3 + 0x20) != 0)
            *(int *)(s2 + 0x2C) = func_0032DC58(*(int *)(s3 + 0x20));
        else
            *(int *)(s2 + 0x2C) = -1;
        if (*(int *)(s2 + 0x2C) >= 0) {
            v = func_0032DCD0(*(int *)(s3 + 0x20), 0);
            if (v != 0)
                func_0032A160(v, s3 + 0x14, buf);
        }
    }
done:
    func_00382898(s0);
    func_00380678(s0, 0x18, *(unsigned char *)(s0 + 4) * 8 + 0x78, 0x80006060, 0xFFF8);
    return 1;
}
