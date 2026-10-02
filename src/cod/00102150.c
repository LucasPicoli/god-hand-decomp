/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEmManage.h"

extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void cSnd_DieDemoStart(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern char D_00462FC0[];
extern char D_005FEE00[];
extern int D_00747A24;
extern char *Getplayer(void);
extern void func_0012C540(void *a0, int a1);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern int GetSeqSEBase(void *a0);
extern void cSnd_SeCall_2CB8A0(char *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern void func_00102418(void *a0);
extern int cCollisionSolidManage_ChkHit(void *a0, void *a1);
extern int ChkCollScrWall(void *a0, void *a1, int a2, void *a3, int t0, int t1, float f12);
extern int func_001329C0(void *a0, void *a1, int a2, void *a3, float f12);
extern void cObjBase_SetSeqEffect(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern int D_00747A78;
extern void cSnd_BattleBgmAllPause(void *a0, float f12);
extern void cSnd_BgmEventFade(void *a0, int a1, float f12, float f13, float f14);
extern void func_001F6A80(void *a0);
extern void func_001F6AF8(void *a0);
extern char D_007474A0[];
extern int *D_003BF0C0[];
extern int D_003BF0D0[];
extern void func_00294AD8(void *a0);
extern void func_00125F38(void *a0);
extern float SetMotionStep(void *a0, float f);
extern void func_00291D48(void *a0);
extern void func_00292F68(void *a0);

__attribute__((section(".text.func_00121798")))
void func_00121798(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;

    *(float *)(s0 + 0x54C) = 5.0f;
    *(int *)(s0 + 0x250) = *(int *)(s0 + 0x250) | 0x10000;
    s1 = *(char **)(s0 + 0x694);
    cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        float buf[4];
        float z;

        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        (*(float **)(s0 + 0xF0))[0] = 0.0f;
        (*(float **)(s0 + 0xF0))[2] = 0.0f;
        if (s1 != 0) {
            float *q = *(float **)(s1 + 0xF0);
            float *p = *(float **)(s0 + 0xF0);
            if (q != p) {
                q[0] = p[0];
                q[1] = p[1];
                q[2] = p[2];
            }
        }
        buf[1] = 0.0f;
        buf[0] = -0.128133342f;
        z = buf[1];
        buf[2] = 0.870266676f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 0, z);
        cEm00_GetPlMotion(s1, 0x2E, z, z);
        *(int *)(s0 + 0x15B0) = 1;
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            if (*(short *)(s0 + 0x54A) > 0) {
                pl00_clearMotionCam(s0, 0, 0);
                *(char *)(s0 + 0x2F4) = 1;
                *(char *)(s0 + 0x2F5) = 4;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F7) = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0) {
            if (*(int *)(s0 + 0x15B0) != 0) {
                *(int *)(s0 + 0x15B0) = 0;
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
                if (s1 != 0)
                    func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 100.0f));
                if (*(short *)(s0 + 0x54A) <= 0) {
                    *(short *)(s0 + 0x54A) = 0;
                    cSnd_DieDemoStart(D_005FEE00);
                    cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                    *(short *)(s0 + 0x434) = *(unsigned short *)(s0 + 0x434) | 8;
                }
                func_0012C348(s0, 2);
            }
        } else {
            *(int *)(s0 + 0x15B0) = 1;
        }
        break;
    case 2:
        cEm00_GetPlMotion(s1, 0x2F, 0.0f, 0.0f);
        *(int *)(s0 + 0x15B0) = 1;
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
        /* fallthrough */
    case 3:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            pl00_clearMotionCam(s0, 0, 0);
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
}

__attribute__((section(".text.func_00102418")))
void func_00102418(void *a0)
{
    int frame[4];
    char *s1 = (char *)a0;
    char *s3;
    char *p;
    int n;
    char *s2;
    short k;

    s3 = Getplayer();
    if ((*(int *)(s1 + 0x14B0) & 1) == 0)
        return;
    if (*(short *)(s3 + 0x54A) > 0 && *(unsigned char *)(s1 + 0x2F4) == 0 &&
        *(int *)(s1 + 0x14B4) <= 0) {
        func_0012C540(s3, 0);
        *(float *)(s1 + 0x54C) = 5.0f;
        return;
    }
    if ((*(int *)(s1 + 0x14B0) & 1) == 0)
        return;
    p = *(char **)(s1 + 0x5B0);
    if (p == 0)
        return;
    {
        long f = *(unsigned int *)(p + 0x60);
        if ((f & 1) == 0)
            return;
    }
    if (*(float *)(s1 + 0x54C) > 0.0f)
        return;
    n = *(int *)(p + 0x4C);
    s2 = *(char **)(p + 0x34);
    func_0012C0F8(s3, n);
    if (n > 0)
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
    {
        char *q = *(char **)(s1 + 0x5B0);
        int id = *(int *)(q + 0x40);
        int v = *(short *)(q + 0x44);

        if (id != -1)
            cSnd_SeCall_2CBA48(D_005FEE00, id, v, s1, 0, 0, 0, 0);
        else
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xA, s1, 0, 0, 0, 0);
    }
    switch (*(short *)(*(char **)(s1 + 0x5B0) + 0x46)) {
    default:
    {
        int cnt;
        char *obj;
        int idx;

        idx = 4;
        if ((frame[0] = cnt = *(unsigned char *)(s1 + 0x2B4)), (idx >= 0 && idx < cnt))
            obj = *(char **)(*(int *)(s1 + 0x278) + idx * 4);
        else
            obj = 0;
        if (obj != 0)
            SetEffectPos(0, 3, 0, *(void **)(obj + 0xF0), -1, 1.0f);
        break;
    }
    case 0x4A:
        SetEffect(0x58, 0x2A, 0, 0, -1, -1);
        if (s2 != 0)
            cSnd_SeCall_2CB8A0(D_005FEE00, 1, (short)(GetSeqSEBase(s2) + 0x1F), -1, -1, 0, 0);
        break;
    case 0x4B:
        SetEffect(0xA8, 0xE, 0, 0, -1, -1);
        if (s2 != 0)
            cSnd_SeCall_2CB8A0(D_005FEE00, 1, (short)(GetSeqSEBase(s2) + 0x1F), -1, -1, 0, 0);
        break;
    case 0x4C:
        SetEffect(0x63, 0xE, 0, 0, -1, -1);
        if (s2 != 0)
            cSnd_SeCall_2CB8A0(D_005FEE00, 1, (short)(GetSeqSEBase(s2) + 0x1F), -1, -1, 0, 0);
        break;
    }
    *(float *)(s1 + 0x54C) = 5.0f;
    pl00_clearMotionCam(s3, 0, 0);
    k = *(short *)(*(char **)(s1 + 0x5B0) + 0x46);
    if (k == 0x48 || k == 0x52)
        cEmManage_SetPlBombHit(&D_005864F0);
    if (*(short *)(s3 + 0x54A) > 0) {
        *(char *)(s1 + 0x2F4) = 1;
        *(char *)(s1 + 0x2F5) = 0;
        *(char *)(s1 + 0x2F6) = 0;
        *(char *)(s1 + 0x2F7) = 0;
    } else {
        *(char *)(s1 + 0x2F4) = 2;
        *(char *)(s1 + 0x2F5) = 0;
        *(char *)(s1 + 0x2F6) = 0;
        *(char *)(s1 + 0x2F7) = 0;
    }
}

struct Entry_00102150 { short f0; short f2; short f4; short f6; };
struct Table_00102150 { struct Entry_00102150 e[1]; };
extern struct Table_00102150 D_003BC748;

#include "godhand/vu0.h"

__attribute__((section(".text.func_00102150")))
void func_00102150(void *a0)
{
    float buf[4];
    int w;
    unsigned short *hit;
    char *s1 = (char *)a0;
    char *s3;

    s3 = Getplayer();
    if (D_00747A78 < 0)
        return;
    if (*(int *)(s1 + 0x14B4) != 0)
        *(int *)(s1 + 0x14B4) = *(int *)(s1 + 0x14B4) - 1;
    func_00102418(s1);
    cCollisionSolidManage_SetActive(D_00462FC0, s1, 1);
    *(int *)(s1 + 0x250) &= 0xFFFEFFFF;
    {
        char *e;
        int i8;
        int f0;
        int type; int arg; int (*fp)(int); long entry;

        i8 = *(unsigned char *)(s1 + 0x2F4) * 8;
        e = (char *)&D_003BC748 + i8;
        type = *(short *)(e + 2);
        if (type >= 0) {
            int base = *(int *)(s1 + *(short *)(e + 4));
            entry = *(long *)(base + type * 8 - 8);
            fp = (int (*)(int))(int)(entry >> 32);
        } else {
            fp = *(int (**)(int))((char *)&D_003BC748 + i8 + 4);
        }
        f0 = D_003BC748.e[*(unsigned char *)(s1 + 0x2F4)].f0;
        if (type >= 0)
            arg = (short)entry + f0;
        else
            arg = f0;
        fp((int)(s1 + arg));
    }
    cCollisionSolidManage_ChkHit(D_00462FC0, s1);
    if ((*(volatile int *)(s1 + 0x14B0) & 1) != 0) {
        VU0_SQC2_VF0(buf, 0);
        if (ChkCollScrWall(s1, buf, 0, &w, 0, 0, 0.400000006f) != 0) {
            (*(float **)(s1 + 0xF0))[0] = buf[0];
            (*(float **)(s1 + 0xF0))[2] = buf[2];
        }
    }
    if ((*(int *)(s1 + 0x14B0) & 1) != 0) {
        float y;

        *(int *)(s1 + 0x474) = 0;
        y = (*(float **)(s1 + 0xF0))[1];
        VU0_SQC2_VF0(buf, 0);
        if (func_001329C0(s1, buf, 0, &hit, 20.0f) != 0) {
            y = buf[1];
            *(int *)(s1 + 0x474) = *hit;
        }
        *(float *)(s1 + 0x5BC) = *(float *)(s1 + 0x5BC) - *(float *)(s1 + 0x5B8);
        (*(float **)(s1 + 0xF0))[1] = (*(float **)(s1 + 0xF0))[1] + *(float *)(s1 + 0x5BC);
        if ((*(float **)(s1 + 0xF0))[1] < y) {
            (*(float **)(s1 + 0xF0))[1] = y;
            *(float *)(s1 + 0x5BC) = 0.0f;
        }
    }
    cObjBase_SetSeqEffect(s1);
    cModel_calcParts(s1);
    IK_InverseKinematics(s1 + 0x448, s1);
    cModel_calcWorldParts(s1);
    {
        char *s = *(char **)(s1 + 0xF0);
        char *d = s1 + 0x490;

        if (d != s) {
            *(float *)(s1 + 0x490) = *(float *)(s + 0);
            *(float *)(d + 4) = *(float *)(s + 4);
            *(float *)(d + 8) = *(float *)(s + 8);
        }
    }
    if ((*(int *)(s1 + 0x14B0) & 1) != 0) {
        {
            float *d = *(float **)(s3 + 0xF0);
            float *s = *(float **)(s1 + 0xF0);

            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
        }
        {
            char *d = s3 + 0x100;
            char *s = s1 + 0x100;

            if (d != s) {
                *(float *)(s3 + 0x100) = *(float *)(s1 + 0x100);
                *(float *)(d + 4) = *(float *)(s + 4);
                *(float *)(d + 8) = *(float *)(s + 8);
            }
        }
    }
}

__attribute__((section(".text.func_001F6208")))
void func_001F6208(void *a0)
{
    char *s0 = (char *)a0;
    char *pad = D_007474A0;
    long b;

    if (*(long *)(pad + 0x1A0) & 0x10000000) {
        if (*(int *)(s0 + 0x24) != D_003BF0C0[*(int *)(s0 + 0xC)][*(int *)(s0 + 0x20)]) {
            if (*(int *)(s0 + 0x24) == -2)
                cSnd_BattleBgmAllPause(D_005FEE00, 20.0f);
            cSnd_BgmEventFade(D_005FEE00, *(int *)(s0 + 0x24), 20.0f, 0.0f, -1.0f);
            *(char *)(s0 + 0x5) = 1;
            *(int *)(s0 + 0x8) = 10;
            *(int *)(s0 + 0x24) = D_003BF0C0[*(int *)(s0 + 0xC)][*(int *)(s0 + 0x20)];
        }
        return;
    }
    b = *(long *)(pad + 0x1B0);
    if (b & 0x8000000) {
        if (D_003BF0D0[*(int *)(s0 + 0xC)] >= 7) {
            if (*(int *)(s0 + 0x20) >= 6) {
                *(int *)(s0 + 0x20) = *(int *)(s0 + 0x20) - 6;
            } else {
                *(int *)(s0 + 0x20) = *(int *)(s0 + 0x20) + 6;
                if (D_003BF0D0[*(int *)(s0 + 0xC)] - 1 < *(int *)(s0 + 0x20))
                    *(int *)(s0 + 0x20) = D_003BF0D0[*(int *)(s0 + 0xC)] - 1;
            }
        }
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x4000000) {
        if (D_003BF0D0[*(int *)(s0 + 0xC)] >= 7) {
            if (*(int *)(s0 + 0x20) >= 6) {
                *(int *)(s0 + 0x20) = *(int *)(s0 + 0x20) - 6;
            } else {
                *(int *)(s0 + 0x20) = *(int *)(s0 + 0x20) + 6;
                if (D_003BF0D0[*(int *)(s0 + 0xC)] - 1 < *(int *)(s0 + 0x20))
                    *(int *)(s0 + 0x20) = D_003BF0D0[*(int *)(s0 + 0xC)] - 1;
            }
        }
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x2000000) {
        int o = *(int *)(s0 + 0x20);
        int n = o + 1;

        *(int *)(s0 + 0x20) = n;
        if (n == 6 || n == D_003BF0D0[*(int *)(s0 + 0xC)]) {
            *(int *)(s0 + 0x20) = o;
            *(char *)(s0 + 0x1) = 2;
            *(char *)(s0 + 0x2) = 0;
            *(char *)(s0 + 0x3) = 0;
        }
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x1000000) {
        int o = *(int *)(s0 + 0x20);
        int n = o - 1;

        *(int *)(s0 + 0x20) = n;
        if (n == -1 || n == 5) {
            *(int *)(s0 + 0x20) = o;
            *(char *)(s0 + 0x1) = 2;
            *(char *)(s0 + 0x2) = 0;
            *(char *)(s0 + 0x3) = 0;
        }
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x1000000000) {
        func_001F6A80(s0);
        if (D_003BF0D0[*(int *)(s0 + 0xC)] - 1 < *(int *)(s0 + 0x20))
            *(int *)(s0 + 0x20) = D_003BF0D0[*(int *)(s0 + 0xC)] - 1;
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x10000000000) {
        func_001F6AF8(s0);
        if (D_003BF0D0[*(int *)(s0 + 0xC)] - 1 < *(int *)(s0 + 0x20))
            *(int *)(s0 + 0x20) = D_003BF0D0[*(int *)(s0 + 0xC)] - 1;
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    }
}

/* Main's two steps: a wait counts down to 0; a kept actor pointer is
 * dropped once the actor's dead bit (the sign bit of objFlags) is set. */
#define EM_COUNT_DOWN(f) if (self->f != 0) self->f = self->f - 1
#define EM_DROP_DEAD(f) if (self->f != 0 && self->f->objFlags < 0) self->f = 0

/* Runs once a frame: counts every wait down, drops kept actors that are
 * dead, works out the unk5A0..unk5A2 flags, copies the speed rate (times
 * the game rate at D_007474A0 + 0x574) to every listed enemy, then puts
 * the rate back to 1.0. */
__attribute__((section(".text.cEmManage_Main")))
void cEmManage_Main(cEmManage *self)
{
    cEmSlot *slot;
    unsigned int i;

    func_00294AD8(self);
    if (D_00747A78 & 0x40000000)
        return;
    EM_COUNT_DOWN(unk510);
    EM_COUNT_DOWN(slotWait);
    EM_COUNT_DOWN(unk530);
    EM_COUNT_DOWN(bigHitEffWait);
    EM_COUNT_DOWN(unk539);
    EM_COUNT_DOWN(unk53A);
    EM_COUNT_DOWN(plBombHit);
    EM_COUNT_DOWN(plCatched);
    EM_COUNT_DOWN(plSorry);
    if (0.0f < self->unk544)
        self->unk544 = self->unk544 - self->speedRate;
    EM_COUNT_DOWN(unk540);
    EM_COUNT_DOWN(unk541);
    EM_COUNT_DOWN(unk542);
    EM_DROP_DEAD(unk560[0]);
    EM_DROP_DEAD(unk560[1]);
    EM_DROP_DEAD(unk560[2]);
    EM_DROP_DEAD(unk560[3]);
    EM_DROP_DEAD(unk560[4]);
    EM_DROP_DEAD(unk588[0]);
    EM_DROP_DEAD(unk588[1]);
    EM_DROP_DEAD(unk588[2]);
    EM_DROP_DEAD(unk588[3]);
    i = 0;
    {
        cEmActor **p2 = self->unk5AC;
        cEmActor **pp;

        for (; i < EM_SPECIAL_NUM; i++) {
            pp = &self->specialEm[i];
            if (*pp != 0 && ((*pp)->objFlags & EMACTOR_FLAG_DEAD))
                *pp = 0;
        }
        for (i = 0, pp = p2; i < 2; i++, pp++) {
            if (*pp != 0 && ((*pp)->objFlags & EMACTOR_FLAG_DEAD))
                *pp = 0;
        }
    }
    if (self->unk5A3 == 3)
        self->unk5A0 = 1;
    else
        self->unk5A0 = 0;
    if (self->unk5A4 == 3)
        self->unk5A1 = 1;
    else
        self->unk5A1 = 0;
    if (self->unk5A5 != 0)
        self->unk5A2 = 1;
    else
        self->unk5A2 = 0;
    if (self->unk560[0] == 0 || self->unk560[1] == 0) {
        self->unk5A0 = 0;
        self->unk5A1 = 0;
        self->unk5A2 = 0;
    }
    func_00125F38(Getplayer());
    slot = self->list.top;
    if (slot != 0) {
        char *g = D_007474A0;

        for (; slot != 0; slot = slot->next) {
        cEmActor *e = slot->em;

        if (e != 0) {
            float v = self->speedRate * *(float *)(g + 0x574);

            e->speedRate = v;
            SetMotionStep(e, v);
        }
        }
    }
    self->speedRate = EM_SPEED_RATE_NORMAL;
    func_00291D48(self);
    func_00292F68(self);
}
