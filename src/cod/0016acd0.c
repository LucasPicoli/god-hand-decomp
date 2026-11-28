/* sn-2.95.3-136 matched TU. */
#include "godhand/cIDMenuPanel.h"

extern void cIDBase_trans(void *a0);
extern unsigned char D_005864F0[];
extern int cEmManage_CreateItem(void *a0, int a1, int a2, int a3);
extern void func_0019BA08(void *a0, int a1, int a2);
extern void SetField5B0Bit2ClearBit8_1B7908(int a0);
extern float capVu0Atan2(float y, float x);
extern void DamageObj_disableDamage(void *a0);
extern void func_00373FA0(void *a0);
extern void func_0032BDC0(void *a0, int a1, int a2);
extern void func_0032BB48(void *a0, int a1, int a2);
extern void func_003741B0(void *a0, float f);
extern void func_00374570(void *a0);
extern void func_0032DE88(int a0, int a1);
extern void func_0032DEF8(int a0, int a1);
extern void func_0032DF70(void *a0, int a1, int a2);
extern void func_0032DA28(void *a0, int a1, int a2);
extern void func_00374958(void *a0, float f);

#define SHOP_INPUTS  5                  /* combo inputs shown at once */

/* sn-2.95.3-136 matched TU. */





/* cSubScrShopMain, retail's name (its type-info function func_0016C1E8
 * registers "15cSubScrShopMain"): the shop's main sub-screen, with a second
 * display at 0xD0 and the combo input display at 0x210. */
typedef struct cSubScrShopMain {
    cIDPanelHead head;                  /* 0x000 */
    char unk064[0xD0 - 0x64];
    cIDBaseObj subBase;                 /* 0x0D0 */
    char unk118[0x210 - 0x118];
    cIDBaseObj inputBase;               /* 0x210 entry 0 drawn once per shown input */
    char unk258[0x260 - 0x258];
    short inputTimer[SHOP_INPUTS];      /* 0x260 frames each shown input stays up */
    char unk26A[2];
    int input[SHOP_INPUTS];             /* 0x26C input shown in each slot */
} cSubScrShopMain;

__attribute__((section(".text.func_0016ACD0")))
void func_0016ACD0(cSubScrShopMain *self)
{
    unsigned short i;

    if (self->head.state == 3) {
        for (i = 0; i < SHOP_INPUTS; i++) {
            short *tbl = self->inputTimer;
            short *q = tbl + i;
            if (*q != 0) {
                cIDBaseEnt *w1 = cIDBase_getIDWork(&self->inputBase, 0);
                cIDBaseEnt *w2 = cIDBase_getIDWork(&self->inputBase, 0);
                cIDBaseEnt *w3;
                cIDBaseEnt *w4;
                w1->posY = w2->src->posY - i * 26;
                w3 = cIDBase_getIDWork(&self->inputBase, 0);
                w3->colorBase.c[3] = (int)(*q / 20.0f * 256.0f);
                w4 = cIDBase_getIDWork(&self->inputBase, 0);
                w4->number = self->input[i];
                cIDBase_move(&self->inputBase);
                cIDBase_trans(&self->inputBase);
            }
        }
    }
    cIDBase_trans(&self->subBase);
    cIDBase_trans(&self->head.base);
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/effectPos.h"
#include "godhand/vu0.h"
#include "godhand/cGameObj.h"









__attribute__((section(".text.func_0019B580")))
void func_0019B580(void *a0)
{
    cGameObj *s0 = a0;
    cVec buf __attribute__((aligned(16)));

    switch (s0->phase) {
    case 0: {
        float *src;
        VU0_SQC2_VF0(&buf, 0);
        src = CVCALL_FN(s0, 16, float *(*)(void *))(CVCALL_THIS(s0, 16));
        if (&buf.x != src) {
            buf.x = src[0];
            buf.y = src[1];
            buf.z = src[2];
        }
        SetEffectPos(0, 0xCC, 0, &buf, 1.0f, -1);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, a0, 0, 0, 0, 0);
        if (*(char *)((char *)s0 + 0xA92) == 0) {
            func_0019BA08(s0, 0, 2);
            cEmManage_CreateItem(&D_005864F0, (int)s0->pos, 0xFFFF, 0);
            s0->hp = s0->hpMax;
            *(unsigned char *)((char *)s0 + 0xA92) = *(unsigned char *)((char *)s0 + 0xA92) + 1;
            s0->mode = 0;
            s0->phase = 0;
            s0->step = 0;
            s0->stepArg = 0;
            break;
        }
        func_0019BA08(s0, 1, 3);
        SetField5B0Bit2ClearBit8_1B7908((int)s0);
        s0->phase = 1;
        *(short *)((char *)s0 + 0xA90) = 0x1E;
        s0->step = 0;
        s0->stepArg = 0;
    }
    /* fallthrough */
    case 1: {
        int v = *(unsigned short *)((char *)s0 + 0xA90) - 1;
        *(short *)((char *)s0 + 0xA90) = v;
        if ((short)v > 0)
            break;
        *(short *)((char *)s0 + 0xA90) = 0xF;
        s0->phase = 2;
        s0->step = 0;
        s0->stepArg = 0;
        break;
    }
    case 2: {
        int v = *(unsigned short *)((char *)s0 + 0xA90) - 1;
        short t = v;
        *(short *)((char *)s0 + 0xA90) = v;
        s0->tint.w = (float)t / 15.0f;
        if (t > 0)
            break;
        s0->phase = 3;
        s0->step = 0;
        s0->stepArg = 0;
        break;
    }
    case 3:
        s0->mode = 3;
        s0->phase = 0;
        s0->step = 0;
        s0->stepArg = 0;
        break;
    }
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmBase.h"






typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;


typedef struct Frame {
    Vec4 a;               /* 0x00 */
    cEffectParam s;                  /* 0x10 */
} Frame;

__attribute__((section(".text.func_001BFD28")))
void func_001BFD28(void *a0)
{
    cOmBase *s0 = a0;
    Frame fr;
    cEffectParam *e;
    float ang;

    switch (s0->phase) {
    case 0: {
        float *src;
        ang = capVu0Atan2(s0->knock.x, s0->knock.z);
        VU0_SQC2_VF0(&fr, 0x00);
        src = CVCALL_FN(s0, 16, float *(*)(void *))(CVCALL_THIS(s0, 16));
        if ((void *)&fr.a != (void *)src) {
            fr.a.x = src[0];
            fr.a.y = src[1];
            fr.a.z = src[2];
        }
        e = &fr.s;
        e->color.x = 1.0f;
        e->color.y = 1.0f;
        e->color.z = 1.0f;
        e->color.w = 1.0f;
        VU0_SQC2_VF0(&fr, 0x20);
        VU0_SQC2_VF0(&fr, 0x30);
        {
            float *q = &e->scale.x;
            q[0] = 1.0f;
            q[1] = 1.0f;
            q[2] = 1.0f;
            q[3] = 1.0f;
        }
        e->size = 1.0f;
        fr.s.unk44 = 0;
        fr.s.flags = 0;
        e->unk4C = -1;
        fr.s.unk4D = 0;
        fr.s.unk4E = 0;
        e->unk4F = 0xFF;
        fr.s.unk50 = 0;
        VU0_SQC2_VF0(&fr, 0x70);
        fr.s.unk10.y = ang;
        fr.s.unk70 = 0;
        fr.s.unk72 = 0;
        fr.s.unk74 = 0;
        fr.s.unk78 = 0;
        if ((void *)&fr.s.unk20 != (void *)&fr.a) {
            fr.s.unk20.x = fr.a.x;
            fr.s.unk20.y = fr.a.y;
            fr.s.unk20.z = fr.a.z;
        }
        fr.s.size = 1.0f;
        SetEffect(0, 0x1C, 0, &fr.s, -1, EFFECT_FOLLOW_OWNER);
        CVCALL_FN(s0, 21, void (*)(void *))(CVCALL_THIS(s0, 21));
        DamageObj_disableDamage(s0);
        SetField5B0Bit2ClearBit8_1B7908((int)s0);
        s0->phase = 1;
        *(short *)((char *)s0 + 0x604) = 0x1E;
        s0->step = 0;
        s0->stepArg = 0;
    }
    /* fallthrough */
    case 1: {
        int v = *(unsigned short *)((char *)s0 + 0x604) - 1;
        *(short *)((char *)s0 + 0x604) = v;
        if ((short)v > 0)
            break;
        *(short *)((char *)s0 + 0x604) = 0xF;
        s0->phase = 2;
        s0->step = 0;
        s0->stepArg = 0;
        break;
    }
    case 2: {
        int v = *(unsigned short *)((char *)s0 + 0x604) - 1;
        short t = v;
        *(short *)((char *)s0 + 0x604) = v;
        s0->tint.w = (float)t / 15.0f;
        if (t > 0)
            break;
        s0->phase = 3;
        s0->step = 0;
        s0->stepArg = 0;
        break;
    }
    case 3:
        s0->mode = 3;
        s0->phase = 0;
        s0->step = 0;
        s0->stepArg = 0;
        break;
    }
}

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_00373D90")))
int func_00373D90(void *a0, int a1, void *a2, int a3)
{
    char *o = (char *)a0;
    char *c = (char *)a2;
    int flag;
    int one;
    int nil;
    int m;

    if (*(int *)o != 0) {
        return 0;
    }
    one = 1;
    nil = 0;
    flag = nil;
    if (*(unsigned char *)(c + 0x10) != 0) {
        flag = one;
    }
    *(float *)(o + 0x20) = (float)*(unsigned char *)(c + 0xC);
    *(float *)(o + 0x24) = (float)*(unsigned short *)(c + 4);
    *(float *)(o + 0x28) = (float)*(unsigned short *)(c + 6);
    *(int *)(o + 0x18) = 0;
    *(int *)(o + 0x1C) = 0;
    *(float *)(o + 0x34) =
        (float)((int)((float)*(unsigned char *)(c + 0xD)
                    / (float)*(unsigned char *)(c + 0xC) * 100.0f) + 1) / 100.0f;
    *(int *)(o + 0xC) = *(unsigned short *)(c + 8);
    m = (*(unsigned char *)(c + 0xB) >> 2) & 3;
    *(int *)(o + 0x10) = m;
    if (m == 0) {
        *(int *)(o + 0x10) = 2;
    }
    *(float *)(o + 0x30) = *(float *)(o + 0x2C) = 1.0f;
    if (func_00373BA8(o, *(unsigned short *)(c + 8), *(unsigned char *)(c + 0xF), flag) == 0) {
        return 0;
    }
    func_00373FA0(o);
    func_0032B188(*(int *)o, 1);
    if (flag == one) {
        func_0032BDC0(*(void **)o, a3, *(unsigned short *)(c + 2));
    } else {
        func_0032BB48(*(void **)o, a1, *(unsigned short *)(c + 2));
    }
    func_003741B0(o, 2.0f);
    return 1;
}

/* sn-2.95.3-136 matched TU. */









__attribute__((section(".text.func_00374360")))
int func_00374360(void *a0, int a1, void *a2)
{
    char *o = (char *)a0;
    char *c = (char *)a2;
    char *v;
    int i;
    int m;

    if (*(int *)o != 0) {
        return 0;
    }
    if (*(unsigned char *)(c + 0xA) != 0) {
        i = 0;
        v = o + 0x24;
        do {
            float f = (float)*(unsigned char *)(c + 0xC);
            *(int *)(v - 8) = 0;
            *(int *)v = 0;
            *(float *)(v + 8) = f;
            v += 4;
        } while (++i < *(unsigned char *)(c + 0xA));
    }
    *(float *)(o + 0x34) = (float)*(unsigned short *)(c + 4);
    *(float *)(o + 0x38) = (float)*(unsigned short *)(c + 6);
    *(float *)(o + 0x44) =
        (float)((int)((float)*(unsigned char *)(c + 0xD)
                    / (float)*(unsigned char *)(c + 0xC) * 100.0f) + 1) / 100.0f;
    *(int *)(o + 0xC) = *(unsigned char *)(c + 0xA);
    m = (*(unsigned char *)(c + 0xB) >> 2) & 3;
    *(int *)(o + 0x10) = m;
    if (m == 0) {
        *(int *)(o + 0x10) = 2;
    }
    *(float *)(o + 0x40) = *(float *)(o + 0x3C) = 1.0f;
    if (func_00374210(o, *(unsigned short *)(c + 8), *(unsigned char *)(c + 0xF),
                      *(unsigned char *)(c + 0xA)) == 0) {
        return 0;
    }
    func_00374570(o);
    func_0032DE88(*(int *)o, 1);
    func_0032DEF8(*(int *)o, 1);
    func_0032DF70(*(void **)o, 1, 1);
    func_0032DA28(*(void **)o, a1, *(unsigned short *)(c + 2));
    func_00374958(o, 2.0f);
    return 1;
}
