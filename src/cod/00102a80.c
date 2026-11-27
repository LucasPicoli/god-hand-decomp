#include "godhand/cCollisionSolid.h"
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cObj.h"
#include "godhand/cObjBase.h"
/* sn-2.95.3-136 matched TU. */

extern int func_002DDAB0(void *a0, int a1, float f);
extern int moveMotion(void *a0);
extern void cOmBase_dieCommon(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void *Getplayer(void);
extern void func_001034E0(void *a0);
extern void func_00260438(void *a0);
extern unsigned short D_00747A50;
extern void func_00124540(void *a0, int a1);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f12);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_0012B618(void *a0);

__attribute__((section(".text.func_00277C48")))
void func_00277C48(void *a0)
{
    cObj *s0 = a0;
    void *e;
    float one;
    int v0;

    e = (void *)func_002DDAB0(*(void **)((char *)s0 + 0xF0), 0, 15.0f);
    switch (s0->step) {
    case 0:
        v0 = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x5C) + v0, *(int *)(v0 + 0x60) + v0, 3, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            if (e != 0) {
                cOmBase_dieCommon(e);
            }
            s0->mode = 0;
            s0->phase = 0;
            s0->step = 0;
            s0->stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00246F40")))
void func_00246F40(void *a0)
{
    cObj *s0 = a0;
    float one;
    int v0, t;

    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    *(int *)((char *)s0 + 0x16D0) |= 0x20000;
    *(int *)((char *)s0 + 0x16D0) |= 0x10000;
    switch (s0->step) {
    case 0:
        t = Obj0000_Get_Byte_17C3_NZ_2_276468(s0);
        v0 = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0xC34) + v0, *(int *)(v0 + 0xC38) + v0, 10, 80.0f, t & 0xFFFF, 0);
        *(int *)((char *)s0 + 0x5B4) = 0x1869F;
        func_0026F120(a0);
        s0->step = s0->step + 1;
    case 1:
        *(int *)((char *)s0 + 0x16D0) |= 0x20000;
        if (moveMotion(s0) != 0) {
            func_00270C78(a0);
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00102A80")))
void func_00102A80(void *a0)
{
    cObj *s0 = a0;
    char *s1 = (char *)Getplayer();
    float one;
    float f;
    int v0;

    switch (s0->step) {
    case 0:
        v0 = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x1C) + v0, *(int *)(v0 + 0x20) + v0, 10, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    case 1:
        if (*(unsigned char *)(s1 + 0x61F) != 0) {
            f = 3.1415927f - *(float *)(s1 + 0x608);
            f = f - 0.5235988f;
            if (f < 0.0f) {
                f = 0.0f;
            }
            f = f * 0.4f;
            if (0.0418879f < f) {
                f = 0.0418879f;
            }
            if (*(float *)(s1 + 0x604) < 0.0f) {
                f = -f;
            }
            s0->rot.y = s0->rot.y + f;
            s0->rot.y = Adjust_theta(s0->rot.y);
        }
        one = 1.0f;
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
    func_001034E0(s0);
}

__attribute__((section(".text.func_00258C40")))
void func_00258C40(void *a0)
{
    cGameObj *s0 = a0;
    float one;
    int a, c;

    *(int *)((char *)s0 + 0x16D0) |= 0x4000;
    switch (s0->step) {
    case 0:
        switch (s0->emNo) {
        default:
        {
            int b = *(int *)((char *)s0 + 0x304);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247:
        {
            int b = *(int *)((char *)s0 + 0x304);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        case 0x24F: case 0x250: case 0x251:
        {
            int b = *(int *)((char *)s0 + 0x304);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        case 0x278: case 0x279:
        {
            int b = *(int *)((char *)s0 + 0x304);
            a = *(int *)(b + 0xC4C) + b;
            c = *(int *)(b + 0xC50) + b;
        }
        break;
        }
        func_002A8578(s0, a, c, 10, 0.0f, Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF, 0);
        s0->step = s0->step + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            s0->mode = 0;
            s0->phase = 0x6E;
            s0->step = 0;
            s0->stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00246088")))
void func_00246088(void *a0)
{
    cGameObj *p = a0;
    char *v;
    float one;
    int flag;
    int s0v, s1v;

    flag = 1;
    switch (p->step) {
    case 0:
        *(unsigned char *)((char *)p + 0x1864) = 0;
        if (D_00747A50 == 0x303) {
            if ((*(int *)((char *)p + 0x16D4) & 0x2000000) == 0) {
                *(int *)((char *)p + 0x16D4) |= 0x2000000;
                p->hitFlash = 10.0f;
                flag = 0;
            }
        }
        if (flag != 0) {
            func_00260438(p);
        }
        v = p->pack;
        s0v = *(int *)(v + 0xBCC) + (int)v;
        s1v = *(int *)(v + 0xBD4) + (int)v;
        func_002A8578(p, s0v, s1v, 10, 0.0f, Obj0000_Get_Byte_17C3_NZ_2_276468(p) & 0xFFFF, 0);
        p->unk568 = 3;
        p->step = p->step + 1;
    case 1:
        v = (char *)Getplayer();
        cGameObj_SetTgtTurn((cGameObj *)p, *(cVec **)(v + 0xF0), p->speedRate * 0.19634954f);
        if (moveMotion(p) != 0) {
            if (--p->unk568 <= 0) {
                func_002705D8(p);
            }
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(p, one);
        cObjBase_addNullSpeed(p, one);
        break;
    }
}

__attribute__((section(".text.func_00110E98")))
void func_00110E98(void *a0)
{
    cObjBase *s0 = a0;
    char *v;
    float one;

    *(int *)((char *)s0 + 0x15F4) |= 0x100000;
    switch (s0->step) {
    case 0:
        *(short *)((char *)s0 + 0x5E0) = 0;
        *(short *)((char *)s0 + 0x5E2) = 0;
        func_00124540(s0, 4);
        if (*(int *)((char *)s0 + 0x6A0) != 0) {
            v = s0->pack;
            func_002A8578(*(void **)((char *)s0 + 0x6A0), *(int *)(v + 0x37C) + (int)v, *(int *)(v + 0x398) + (int)v, 3, 0.0f, 0, 0);
        }
        v = s0->pack;
        func_002A8578(s0, *(int *)(v + 0x364) + (int)v, *(int *)(v + 0x368) + (int)v, 3, 0.0f, 0, 0);
        *(int *)((char *)s0 + 0x15B0) = 1;
        s0->step = s0->step + 1;
    case 1:
        if (*(int *)((char *)s0 + 0x640) != 0) {
            *(unsigned char *)((char *)s0 + 0x648) = 0x14;
        }
        InvokeVirtualAtField214AndForward_124E68(s0, 0.19634954f);
        if (moveMotion(s0) != 0) {
            Obj0000_Clear_Fields_640_648_124E58(s0);
            s0->mode = 0;
            s0->phase = 0;
            s0->step = 0;
            s0->stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
    if (s0->seqFlags & 1) {
        func_0012B618(s0);
    }
    if (func_00123938(s0, 1) != 0) {
        Obj0000_Clear_Fields_640_648_124E58(s0);
    }
}
