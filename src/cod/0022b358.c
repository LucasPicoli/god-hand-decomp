#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* sn-2.95.3-136 matched TU. */











#define GRP                                                                    \
    case 0x21A:                                                                \
    case 0x21B:                                                                \
    case 0x21C:                                                                \
    case 0x21D:                                                                \
    case 0x21E:                                                                \
    case 0x225:                                                                \
    case 0x22C:                                                                \
    case 0x22D:                                                                \
    case 0x22E:                                                                \
    case 0x22F:                                                                \
    case 0x248:                                                                \
    case 0x249:                                                                \
    case 0x24C:                                                                \
    case 0x24D:                                                                \
    case 0x24E:                                                                \
    case 0x252:                                                                \
    case 0x25A

__attribute__((section(".text.func_0022B358")))
void func_0022B358(cEm00 *self)
{
    cEm00 *s0 = self;
    int t0;
    int a1, a2;
    char *s1;
    unsigned int s2;

    *(char *)((char *)s0 + 0x186A) = 2;
    s0->emFlags2 |= 0x400;
    if (s0->step == 0) {
        switch (s0->emNo) {
        GRP:
            *(char *)((char *)s0 + 0x2F6) = 2;
            break;
        }
    }
    switch (s0->step) {
    case 0:
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        {
            int b = *(int *)((char *)s0 + 0x304);
            func_002A8578(s0, *(int *)(b + 0xDDC) + b, *(int *)(b + 0xDE0) + b,
                          3, 0.0f, t0, 0);
        }
        s0->timerC = 0;
        *(char *)((char *)s0 + 0x2F6) = s0->step + 1;
    case 1:
        s0->unk16DC = 0x64;
        s0->unk16E0 = 0x96;
        cGameObj_SetTgtTurn((cGameObj *)s0, &self->unk16A0,
                                         s0->speedRate * 0.09817477f);
        if (moveMotion(s0) != 0)
            *(char *)((char *)s0 + 0x2F6) = s0->step + 1;
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if ((s0->seqFlags & 1) != 0) {
            if (s0->unk17C3 != 0)
                func_0026A638(self, 1);
            else
                func_0026A638(self, 0);
        }
        break;
    case 2:
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        switch (s0->emNo) {
        default:
            {
                int b = *(int *)((char *)s0 + 0x304);
                a1 = *(int *)(b + 0xDE4) + b;
                a2 = *(int *)(b + 0xDE8) + b;
            }
            break;
        GRP:
            {
                int b = *(int *)((char *)s0 + 0x304);
                a1 = *(int *)(b + 0x152C) + b;
                a2 = *(int *)(b + 0x1530) + b;
            }
            break;
        }
        func_002A8578(s0, a1, a2, 3, 0.0f, t0, 0);
        *(char *)((char *)s0 + 0x2F6) = s0->step + 1;
    case 3:
        s0->unk16DC = 0x64;
        s0->unk16E0 = 0x96;
        s0->emFlags |= 0x400;
        cGameObj_SetTgtTurn((cGameObj *)s0, &self->unk16A0,
                                         s0->speedRate * 0.09817477f);
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (s0->playerDist < 2.25f)
            *(char *)((char *)s0 + 0x2F6) = 4;
        break;
    case 4:
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        switch (s0->emNo) {
        default:
            {
                int b = *(int *)((char *)s0 + 0x304);
                a1 = *(int *)(b + 0xDEC) + b;
                a2 = *(int *)(b + 0xDF0) + b;
            }
            break;
        GRP:
            {
                int b = *(int *)((char *)s0 + 0x304);
                a1 = *(int *)(b + 0x1534) + b;
                a2 = *(int *)(b + 0x1538) + b;
            }
            break;
        }
        func_002A8578(s0, a1, a2, 3, 0.0f, t0, 0);
        *(char *)((char *)s0 + 0x2F6) = s0->step + 1;
    case 5:
        s0->unk16DC = 0x64;
        s0->unk16E0 = 0x96;
        s0->emFlags |= 0x400;
        cGameObj_SetTgtTurn((cGameObj *)s0, &self->unk16A0,
                                         s0->speedRate * 0.09817477f);
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (6.25f < s0->playerDist)
            *(char *)((char *)s0 + 0x2F6) = 2;
        break;
    }

    s2 = 0;
    s1 = (char *)s0 + 0x6E4;
    while (s2 < 2) {
        void *e = *(void **)s1;
        if (e != 0 && CountdownObj_tickIsSpent(e) != 0) {
            EmThrower_throwHeld(self, 0, 1);
            EmThrower_throwHeld(self, 1, 1);
            break;
        }
        s1 += 4;
        s2++;
    }
    if ((s0->seqFlags & 3) != 0)
        s0->timerC = 1;
    if (s0->timerC != 0)
        s0->emFlags2 &= 0xFFFFFBFFU;
}
