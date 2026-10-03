/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int GetSeqSEBase(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int cDamageUnit_SetDamageCollActive(void *a0, int a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern unsigned char D_005FEE00[];
extern void *Getplayer(void);
extern int irand(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f);
extern void Obj2810_SetState_8_a1(char *a0, int a1);
extern void SetBytes2F4Mode7_283270(char *a0, char a1);
extern void ClearBytes2F4To2F7_283170(void *a0);
extern void func_0026DB00(void *a0, int a1, int a2);

/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, cDamageUnit_SetDamageCollActive, cSnd_SeCall_2CBA48, GetSeqSEBase, moveMotion and
 * 2 more. */
__attribute__((section(".text.func_0025FCF8"))) void func_0025FCF8(cEm00 *self)
{
    char *s1 = (char *)self;
    void *self;
    int p;
    int nb;
    int b;
    int o;
    float one;

    p = *(int *)(s1 + 0x214);
    self = (*(void *(**)(void *))(p + 0xB4))(s1 + *(short *)(p + 0xB0));
    switch (*(unsigned char *)(s1 + 0x2F6)) {
        case 0:
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            b = *(int *)(s1 + 0x304);
            o = EM_RES_REC(b, 0x108C);
            func_002A8578(s1, o, o, 0.0f, 3, nb, 0);
            cDamageUnit_SetDamageCollActive(self, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(s1) + 8), s1, 0, 0, 0, 0);
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        case 1:
            if (moveMotion(s1) != 0) {
                *(unsigned char *)(s1 + 0x2F6) = 0;
                *(unsigned char *)(s1 + 0x2F4) = 2;
                *(unsigned char *)(s1 + 0x2F5) = 2;
                *(unsigned char *)(s1 + 0x2F7) = 0;
            } else {
                one = 1.0f;
                cObjBase_addNullSpeed_Rotation(s1, one);
                cObjBase_addNullSpeed(s1, one);
            }
            break;
    }
    *(unsigned short *)(s1 + 0x3AC) = *(unsigned short *)(s1 + 0x3AC) | 0x400;
}

/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * cCoreSave_getGameLevel, Obj2810_SetState_8_a1, SetBytes2F4Mode7_283270,
 * ClearBytes2F4To2F7_283170, func_002A8578 and 4 more. */
__attribute__((section(".text.func_0024B218"))) void func_0024B218(cEm00 *self)
{
    float one;

    self->emFlags = self->emFlags | 0x30400;
    switch (self->step) {
        case 0: {
            int t0, b, b2, a1v, a2v;
            self->unk1864 = 0;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = self->resource;
            a1v = EM_RES_REC(b, 0x3DA4);
            a2v = EM_RES_REC(b, 0x3DA8);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                b2 = self->resource;
                a2v = EM_RES_REC(b2, 0x3DAC);
                if (self->sub0 != 0)
                    Obj2810_SetState_8_a1((char *)self->sub0, 1);
                if (self->sub1 != 0)
                    SetBytes2F4Mode7_283270((char *)self->sub1, 1);
                if (self->sub2 != 0)
                    ClearBytes2F4To2F7_283170((char *)self->sub2);
            } else {
                if (self->sub0 != 0)
                    Obj2810_SetState_8_a1((char *)self->sub0, 0);
                if (self->sub1 != 0)
                    SetBytes2F4Mode7_283270((char *)self->sub1, 0);
                if (self->sub2 != 0)
                    ClearBytes2F4To2F7_283170((char *)self->sub2);
            }
            func_002A8578(self, a1v, a2v, 0.0f, 0xA, t0, 0);
        }
            self->step++;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0xA1;
                self->step = 0;
                self->stepArg = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
    if (self->moveFlags & 1) {
        func_0026DB00(self, 4, 0);
    }
}
