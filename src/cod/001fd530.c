/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cDamageManage.h"

__attribute__((section(".text.SetTarget_1FD530")))
int SetTarget_1FD530(cDamageTake *self, struct cGameObj *owner, int kind) {
    if (self->type == 0) {
        return 1;
    }
    self->owner = owner;
    self->live = 1;
    func_001FD988((cDamageUnit *)self, kind);
    self->attacker = 0;
    return 1;
}

__attribute__((section(".text.ForwardEventToList_1FD820")))
void ForwardEventToList_1FD820(void *a0, void *a1) {
    int *s0 = *(int **)((char*)a0 + 0x3C);
    while (s0) {
        char *v1 = *(char **)((char*)s0 + 0x28);
        char *a2 = *(char **)(v1 + 0x34);
        char *v0 = *(char **)(a2 + 0x100);
        short a0h = *(short *)(v0 + 0x38);
        void (*f3c)(char *, void *) = *(void (**)(char *, void *))(v0 + 0x3C);
        f3c(a2 + a0h, a1);
        s0 = *(int **)((char*)s0 + 0x24);
    }
}

__attribute__((section(".text.InitPools_1FDFA8")))
void InitPools_1FDFA8(cDamageManage *self) {
    InitEntryPool_1FE188(self);
    InitNodePool_1FE2B8(self);
}

__attribute__((section(".text.InitEntryPool_1FE188")))
void InitEntryPool_1FE188(cDamageManage *self) {
    cDamageGive *p = self->give;
    cDamageGive *end = self->give + CDAMAGE_GIVE_MAX;
    do {
        cDamageManage_ReleaseDamageGive(self, p);
        p++;
    } while (p < end);
}

__attribute__((section(".text.cDamageManage_CreateDamageTake")))
cDamageTake *cDamageManage_CreateDamageTake(cDamageManage *self, struct cGameObj *owner, int kind) {
    cDamageTake *p = func_001FE310(self);
    if (p == 0) return 0;
    if (SetTarget_1FD530(p, owner, kind) == 0) p = 0;
    return p;
}

__attribute__((section(".text.InitNodePool_1FE2B8")))
void InitNodePool_1FE2B8(cDamageManage *self) {
    cDamageTake *p = self->take;
    unsigned int i = 0;
    do {
        ClearAndResetFields_1FE278(self, p);
        i++;
        p++;
    } while (i < CDAMAGE_TAKE_MAX);
}
