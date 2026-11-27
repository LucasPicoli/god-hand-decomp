/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEmManage.h"
#include "godhand/cSnd.h"
#include "godhand/effectPos.h"
#include "godhand/globals.h"
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"
#include "godhand/player.h"

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
extern int D_00747A24;
extern void func_0012C540(void *a0, int a1);
extern int GetSeqSEBase(void *a0);
extern void func_00102418(void *a0);
extern void cObjBase_SetSeqEffect(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern int D_00747A78;
extern void cSnd_BattleBgmAllPause(void *a0, float f12);
extern void cSnd_BgmEventFade(void *a0, int a1, float f12, float f13, float f14);
extern void SlotList_selectPrev(void *a0);
extern void func_001F6AF8(void *a0);
extern char D_007474A0[];
extern void func_00294AD8(void *a0);
extern void func_00125F38(void *a0);
extern float SetMotionStep(void *a0, float f);
extern void func_00291D48(void *a0);
extern void func_00292F68(void *a0);

__attribute__((section(".text.func_00121798")))
void func_00121798(void *a0)
{
    pl00 *s0 = a0;
    cEm00 *s1;

    s0->base.hitFlash = 5.0f;
    s0->base.objFlags = s0->base.objFlags | 0x10000;
    s1 = s0->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    switch (s0->base.step) {
    case 0:
    {
        float buf[4];
        float z;

        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        s0->base.pos->x = 0.0f;
        s0->base.pos->z = 0.0f;
        if (s1 != 0) {
            cVec *q = s1->pos;
            cVec *p = s0->base.pos;
            if (q != p) {
                q->x = p->x;
                q->y = p->y;
                q->z = p->z;
            }
        }
        buf[1] = 0.0f;
        buf[0] = -0.128133342f;
        z = buf[1];
        buf[2] = 0.870266676f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 0, z);
        cEm00_GetPlMotion(s1, 0x2E, z, z);
        s0->unk15B0 = 1;
        s0->base.unk56E = 0xF;
        (s0->base.step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            if (s0->base.hp > 0) {
                pl00_clearMotionCam(s0, 0, 0);
                s0->base.mode = 1;
                s0->base.phase = 4;
                s0->base.step = 0;
                s0->base.stepArg = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if ((s0->base.seqFlags & 1) != 0) {
            if (s0->unk15B0 != 0) {
                s0->unk15B0 = 0;
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
                if (s1 != 0)
                    func_0012C0F8(s0, (int)(s1->unk76C * 100.0f));
                if (s0->base.hp <= 0) {
                    s0->base.hp = 0;
                    cSnd_DieDemoStart(&D_005FEE00);
                    cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                    s0->base.motionFlags = s0->base.motionFlags | 8;
                }
                func_0012C348(s0, 2);
            }
        } else {
            s0->unk15B0 = 1;
        }
        break;
    case 2:
        cEm00_GetPlMotion(s1, 0x2F, 0.0f, 0.0f);
        s0->unk15B0 = 1;
        s0->base.unk56E = 0xF;
        (s0->base.step)++;
        /* fallthrough */
    case 3:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            pl00_clearMotionCam(s0, 0, 0);
            s0->base.mode = 0;
            s0->base.phase = 0;
            s0->base.step = 0;
            s0->base.stepArg = 0;
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
    cGameObj *s1 = a0;
    cGameObj *s3;
    char *p;
    int n;
    char *s2;
    short k;

    s3 = Getplayer();
    if ((*(int *)((char *)s1 + 0x14B0) & 1) == 0)
        return;
    if (s3->hp > 0 && s1->mode == 0 &&
        *(int *)((char *)s1 + 0x14B4) <= 0) {
        func_0012C540(s3, 0);
        s1->hitFlash = 5.0f;
        return;
    }
    if ((*(int *)((char *)s1 + 0x14B0) & 1) == 0)
        return;
    p = *(char **)((char *)s1 + 0x5B0);
    if (p == 0)
        return;
    {
        long f = *(unsigned int *)(p + 0x60);
        if ((f & 1) == 0)
            return;
    }
    if (s1->hitFlash > 0.0f)
        return;
    n = *(int *)(p + 0x4C);
    s2 = *(char **)(p + 0x34);
    func_0012C0F8(s3, n);
    if (n > 0)
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
    {
        char *q = *(char **)((char *)s1 + 0x5B0);
        int id = *(int *)(q + 0x40);
        int v = *(short *)(q + 0x44);

        if (id != -1)
            cSnd_SeCall_2CBA48(&D_005FEE00, id, v, a0, 0, 0, 0, 0);
        else
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xA, a0, 0, 0, 0, 0);
    }
    switch (*(short *)(*(char **)((char *)s1 + 0x5B0) + 0x46)) {
    default:
    {
        int cnt;
        cOmBase *obj;
        int idx;

        idx = 4;
        if ((frame[0] = cnt = s1->partNum), (idx >= 0 && idx < cnt))
            obj = s1->children[idx];
        else
            obj = 0;
        if (obj != 0)
            SetEffectPos(0, 3, 0, obj->pos, 1.0f, -1);
        break;
    }
    case 0x4A:
        SetEffect(0x58, 0x2A, 0, 0, -1, EFFECT_FOLLOW_OWNER);
        if (s2 != 0)
            cSnd_SeCall_2CB8A0(&D_005FEE00, 1, (short)(GetSeqSEBase(s2) + 0x1F), -1, -1, 0, 0);
        break;
    case 0x4B:
        SetEffect(0xA8, 0xE, 0, 0, -1, EFFECT_FOLLOW_OWNER);
        if (s2 != 0)
            cSnd_SeCall_2CB8A0(&D_005FEE00, 1, (short)(GetSeqSEBase(s2) + 0x1F), -1, -1, 0, 0);
        break;
    case 0x4C:
        SetEffect(0x63, 0xE, 0, 0, -1, EFFECT_FOLLOW_OWNER);
        if (s2 != 0)
            cSnd_SeCall_2CB8A0(&D_005FEE00, 1, (short)(GetSeqSEBase(s2) + 0x1F), -1, -1, 0, 0);
        break;
    }
    s1->hitFlash = 5.0f;
    pl00_clearMotionCam(s3, 0, 0);
    k = *(short *)(*(char **)((char *)s1 + 0x5B0) + 0x46);
    if (k == 0x48 || k == 0x52)
        cEmManage_SetPlBombHit(&D_005864F0);
    if (s3->hp > 0) {
        s1->mode = 1;
        s1->phase = 0;
        s1->step = 0;
        s1->stepArg = 0;
    } else {
        s1->mode = 2;
        s1->phase = 0;
        s1->step = 0;
        s1->stepArg = 0;
    }
}

struct Entry_00102150 { short f0; short f2; short f4; short f6; };
struct Table_00102150 { struct Entry_00102150 e[1]; };
extern struct Table_00102150 D_003BC748;

#include "godhand/vu0.h"
#include "godhand/cObjBase.h"

__attribute__((section(".text.func_00102150")))
void func_00102150(void *a0)
{
    cVec buf;
    struct AK_HIT_INFO *w;
    unsigned short *hit;
    cGameObj *s1 = a0;
    cGameObj *s3;

    s3 = Getplayer();
    if (D_00747A78 < 0)
        return;
    if (*(int *)((char *)s1 + 0x14B4) != 0)
        *(int *)((char *)s1 + 0x14B4) = *(int *)((char *)s1 + 0x14B4) - 1;
    func_00102418(s1);
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 1);
    s1->objFlags &= 0xFFFEFFFF;
    {
        char *e;
        int i8;
        int f0;
        int type; int arg; int (*fp)(int); long entry;

        i8 = s1->mode * 8;
        e = (char *)&D_003BC748 + i8;
        type = *(short *)(e + 2);
        if (type >= 0) {
            int base = *(int *)((char *)s1 + *(short *)(e + 4));
            entry = *(long *)(base + type * 8 - 8);
            fp = (int (*)(int))(int)(entry >> 32);
        } else {
            fp = *(int (**)(int))((char *)&D_003BC748 + i8 + 4);
        }
        f0 = D_003BC748.e[s1->mode].f0;
        if (type >= 0)
            arg = (short)entry + f0;
        else
            arg = f0;
        fp((int)((char *)s1 + arg));
    }
    cCollisionSolidManage_ChkHit(&D_00462FC0, (cGameObj *)s1);
    if ((*(volatile int *)((char *)s1 + 0x14B0) & 1) != 0) {
        VU0_SQC2_VF0(&buf, 0);
        if (ChkCollScrWall(a0, 0.400000006f, &buf, 0, &w, 0, 0) != 0) {
            s1->pos->x = buf.x;
            s1->pos->z = buf.z;
        }
    }
    if ((*(int *)((char *)s1 + 0x14B0) & 1) != 0) {
        float y;

        s1->groundKind = 0;
        y = s1->pos->y;
        VU0_SQC2_VF0(&buf, 0);
        if (func_001329C0(a0, &buf, 0, &hit, 20.0f) != 0) {
            y = buf.y;
            s1->groundKind = *hit;
        }
        *(float *)((char *)s1 + 0x5BC) = *(float *)((char *)s1 + 0x5BC) - *(float *)((char *)s1 + 0x5B8);
        s1->pos->y = s1->pos->y + *(float *)((char *)s1 + 0x5BC);
        if (s1->pos->y < y) {
            s1->pos->y = y;
            *(float *)((char *)s1 + 0x5BC) = 0.0f;
        }
    }
    cObjBase_SetSeqEffect(s1);
    cModel_calcParts(s1);
    IK_InverseKinematics(s1->ik, s1);
    cModel_calcWorldParts(s1);
    {
        cVec *s = s1->pos;
        cVec *d = &s1->posA;

        if (d != s) {
            s1->posA.x = s->x;
            d->y = s->y;
            d->z = s->z;
        }
    }
    if ((*(int *)((char *)s1 + 0x14B0) & 1) != 0) {
        {
            cVec *d = s3->pos;
            cVec *s = s1->pos;

            if (d != s) {
                d->x = s->x;
                d->y = s->y;
                d->z = s->z;
            }
        }
        {
            cVec *d = &s3->rot;
            cVec *s = &s1->rot;

            if (d != s) {
                s3->rot.x = s1->rot.x;
                d->y = s->y;
                d->z = s->z;
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
                cSnd_BattleBgmAllPause(&D_005FEE00, 20.0f);
            cSnd_BgmEventFade(&D_005FEE00, *(int *)(s0 + 0x24), 20.0f, 0.0f, -1.0f);
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
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
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
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
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
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
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
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x1000000000) {
        SlotList_selectPrev(s0);
        if (D_003BF0D0[*(int *)(s0 + 0xC)] - 1 < *(int *)(s0 + 0x20))
            *(int *)(s0 + 0x20) = D_003BF0D0[*(int *)(s0 + 0xC)] - 1;
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x10000000000) {
        func_001F6AF8(s0);
        if (D_003BF0D0[*(int *)(s0 + 0xC)] - 1 < *(int *)(s0 + 0x20))
            *(int *)(s0 + 0x20) = D_003BF0D0[*(int *)(s0 + 0xC)] - 1;
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
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
        cOmbb **p2 = self->unk5AC;
        cEmActor **pp;
        cOmbb **bp;

        for (; i < EM_SPECIAL_NUM; i++) {
            pp = &self->specialEm[i];
            if (*pp != 0 && ((*pp)->objFlags & EMACTOR_FLAG_DEAD))
                *pp = 0;
        }
        for (i = 0, bp = p2; i < 2; i++, bp++) {
            if (*bp != 0 && ((*bp)->base.objFlags & GAMEOBJ_OBJ_SKIP))
                *bp = 0;
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
