/* TU: cEmWrap [enemy] - recovered C++ class. */
#include "godhand/cEmWrap.h"
struct vec4 { int a; float b; int c; float d; };
extern int D_00747B00[];
extern unsigned char D_005864F0[];
extern void func_0026E7A8(int a0, int a1);
extern void func_0026E7A0(int a0, float f);
extern void func_002736F8(int a0);
extern int D_0044A878;
extern void cEma2_SetEscPos(int a0, int a1);

__attribute__((section(".text.cEmWrap_setPos_2959B0")))
int cEmWrap_setPos_2959B0(int *a0, int a1)
{
    if (FindResolveActor_295978(a0)) {
        int a2 = *(int *)((char *)a0 + 4);
        int v0 = *(int *)(a2 + 0x214);
        short off = *(short *)(v0 + 0x70);
        void (*fp)(int, int) = *(void (**)(int, int))(v0 + 0x74);
        fp(a2 + off, a1);
        cModel_calcParts(*(int *)((char *)a0 + 4));
    }
}

__attribute__((section(".text.cEmWrap_setPos_295A08")))
void cEmWrap_setPos_295A08(int *a0, int a1, float f12)
{
    if (FindResolveActor_295978(a0)) {
        int s0 = *(int *)((char *)a0 + 4);
        int v0 = *(int *)(s0 + 0x214);
        short off = *(short *)(v0 + 0x70);
        void (*fp)(int, int) = *(void (**)(int, int))(v0 + 0x74);
        fp(s0 + off, a1);
        {
            int a2 = *(int *)(s0 + 0x214);
            struct vec4 v;
            short off2 = *(short *)(a2 + 0x78);
            v.a = 0;
            v.b = f12;
            v.c = 0;
            v.d = 1.0f;
            (*(void (**)(int, struct vec4 *))(a2 + 0x7C))(s0 + off2, &v);
        }
        cModel_calcParts(*(int *)((char *)a0 + 4));
    }
}

/* Pointer to the actor's rotation, or a shared default when the handle is dead. */
__attribute__((section(".text.cEmWrap_getRot")))
int *cEmWrap_getRot(cEmWrap *self)
{
    return FindResolveActor_295978(self) ? (int *)self->actor->rot : D_00747B00;
}

extern int cEmManage_ReleaseEm();
/* Give the actor back to the enemy manager. */
__attribute__((section(".text.cEmWrap_release")))
int cEmWrap_release(cEmWrap *self)
{
    cEmActor *actor;
    if (FindResolveActor_295978(self) == 0) {
        return 0;
    }
    actor = self->actor;
    if (actor != 0) {
        return cEmManage_ReleaseEm(D_005864F0, actor);
    }
    return 0;
}

/* Suspend or resume the actor through its method table. */
__attribute__((section(".text.cEmWrap_setSuspend")))
void cEmWrap_setSuspend(cEmWrap *self, int flag)
{
    if (FindResolveActor_295978(self)) {
        cEmActor *actor = self->actor;
        cEmActorVt *vt = actor->vt;
        int delta = vt->suspendDelta;
        void (*suspend)(char *, int) = (void (*)(char *, int))vt->suspend;
        suspend((char *)actor + delta, flag);
    }
}

extern int func_003A5678();
extern void func_00276090();
/* Set the lock-off flag unless the actor's kind is in the no-lock list. */
__attribute__((section(".text.cEmWrap_setLockOff")))
void cEmWrap_setLockOff(cEmWrap *self, int flag)
{
    extern unsigned char D_0044A870[];
    if (FindResolveActor_295978(self)) {
        cEmActor *actor = self->actor;
        if (func_003A5678(D_0044A870, actor->kind) == 0) {
            func_00276090(self->actor, flag);
        }
    }
}

extern void func_0028FB08(void *actor);
/* Kill the actor. */
__attribute__((section(".text.cEmWrap_setDead")))
void cEmWrap_setDead(cEmWrap *self)
{
    if (FindResolveActor_295978(self)) {
        func_0028FB08(self->actor);
    }
}

extern int cEmBase_checkDeadFlag();
/* 1 when the handle is dead or the actor's dead flag is set. */
__attribute__((section(".text.cEmWrap_isDead")))
int cEmWrap_isDead(cEmWrap *self)
{
    if (FindResolveActor_295978(self) == 0) {
        return 1;
    }
    return cEmBase_checkDeadFlag(self->actor);
}

/* Start the actor's current action through its method table. */
__attribute__((section(".text.cEmWrap_StartAction")))
void cEmWrap_StartAction(cEmWrap *self)
{
    if (FindResolveActor_295978(self)) {
        cEmActor *actor = self->actor;
        cEmActorVt *vt = actor->vt;
        int delta = vt->startDelta;
        void (*start)(char *) = (void (*)(char *))vt->startAction;
        start((char *)actor + delta);
    }
}

/* Current vital of the actor, 0 if the handle is dead. */
__attribute__((section(".text.cEmWrap_GetVital")))
int cEmWrap_GetVital(cEmWrap *self, int a1) {
    cEmActor *actor;
    if (FindResolveActor_295978(self, a1) == 0) return 0;
    actor = self->actor;
    return actor->vital;
}

/* Maximum vital of the actor, 0 if the handle is dead. */
__attribute__((section(".text.cEmWrap_GetVitalMax")))
int cEmWrap_GetVitalMax(cEmWrap *self, int a1) {
    cEmActor *actor;
    if (FindResolveActor_295978(self, a1) == 0) return 0;
    actor = self->actor;
    return actor->vitalMax;
}

/* Set the item the actor drops. */
__attribute__((section(".text.cEmWrap_setDropItem")))
void cEmWrap_setDropItem(cEmWrap *self, int item) {
    if (FindResolveActor_295978(self, item)) {
        self->actor->dropItem = item;
    }
}

/* Turn screen collision on (enable == 1) or off. */
__attribute__((section(".text.cEmWrap_setScrCollEnable")))
void cEmWrap_setScrCollEnable(cEmWrap *self, int enable) {
    if (FindResolveActor_295978(self, enable) == 0) return;
    if (enable == 1) {
        self->actor->scrFlags &= ~EMACTOR_FLAG_NOSCRCOLL;
    } else {
        self->actor->scrFlags |= EMACTOR_FLAG_NOSCRCOLL;
    }
}

extern int Obj0000_IsSet_Field_16D0_Bit_1_26ECC0();
/* Whether the actor is active; kinds in the no-lock list are never active. */
__attribute__((section(".text.cEmWrap_CkActive")))
int cEmWrap_CkActive(cEmWrap *self){
    extern unsigned char D_0044A870[];
    cEmActor *actor;
    if (!FindResolveActor_295978(self)) return 0;
    actor = self->actor;
    return func_003A5678(D_0044A870, actor->kind) ? 0 : Obj0000_IsSet_Field_16D0_Bit_1_26ECC0(self->actor);
}

extern int func_0026EA28();
/* Whether the actor is heading for a goto point; kinds in the no-lock list never are. */
__attribute__((section(".text.cEmWrap_ckGoto")))
int cEmWrap_ckGoto(cEmWrap *self){
    extern unsigned char D_0044A870[];
    cEmActor *actor;
    if (!FindResolveActor_295978(self)) return 0;
    actor = self->actor;
    return func_003A5678(D_0044A870, actor->kind) ? 0 : func_0026EA28(self->actor);
}

__attribute__((section(".text.cEmWrap_SetKeepPos")))
void cEmWrap_SetKeepPos(void *a0, int a1) {
    extern unsigned char D_0044A870[];
    void *s0 = a0;
    int s1 = a1;
    if (FindResolveActor_295978(s0)) {
        int *v0 = *(int**)((char*)s0 + 4);
        if (func_003A5678(&D_0044A870, *(int*)((char*)v0 + 0x4AC)) == 0)
            func_0026E7A8(*(int*)((char*)s0 + 4), s1);
    }
}

__attribute__((section(".text.cEmWrap_SetKeepLength")))
void cEmWrap_SetKeepLength(void *a0, float f) {
    extern int FindResolveActor_295978(void *a0, float f);
    extern int D_0044A870;
    if (FindResolveActor_295978(a0, f)) {
        int *p = *(int **)((char *)a0 + 4);
        if (func_003A5678(&D_0044A870, p[0x4AC / 4]) == 0) {
            func_0026E7A0(*(int *)((char *)a0 + 4), f);
        }
    }
}

__attribute__((section(".text.cEmWrap_clearNoMove")))
void cEmWrap_clearNoMove(void *a0, float f) {
    extern int FindResolveActor_295978(void *a0, float f);
    extern int D_0044A870;
    if (FindResolveActor_295978(a0, f)) {
        int *p = *(int **)((char *)a0 + 4);
        if (func_003A5678(&D_0044A870, p[0x4AC / 4]) == 0) {
            func_002736F8(*(int *)((char *)a0 + 4));
        }
    }
}

__attribute__((section(".text.cEmWrap_SetEscPos")))
void cEmWrap_SetEscPos(void *a0, int a1, float f) {
    extern int FindResolveActor_295978(void *a0, float f);
    if (FindResolveActor_295978(a0, f)) {
        int *p = *(int **)((char *)a0 + 4);
        if (func_003A5678(&D_0044A878, p[0x4AC / 4]) == 0) {
            cEma2_SetEscPos(*(int *)((char *)a0 + 4), a1);
        }
    }
}
