/* SN ProDG ee-gcc 2.95.3 matched TU. */

__attribute__((section(".text.SetTarget_1FD530")))
int SetTarget_1FD530(void *a0, int a1, int a2) {
    if (*(char*)((char*)a0+0x49) == 0) {
        return 1;
    }
    *(int*)((char*)a0+0x30) = a1;
    *(char*)((char*)a0+0x4A) = 1;
    func_001FD988(a0, a2);
    *(int*)((char*)a0+0x34) = 0;
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
void InitPools_1FDFA8(void *a0) {
    InitEntryPool_1FE188(a0);
    InitNodePool_1FE2B8(a0);
}

__attribute__((section(".text.InitEntryPool_1FE188")))
void InitEntryPool_1FE188(int a0) {
    char *p = (char *)a0;
    char *end = (char *)a0 + 0x3C00;
    do {
        cDamageManage_ReleaseDamageGive(a0, (int)p);
        p += 0x60;
    } while (p < end);
}

__attribute__((section(".text.cDamageManage_CreateDamageTake")))
int cDamageManage_CreateDamageTake(int a0, int a1, int a2) {
    int p = func_001FE310(a0);
    if (p == 0) return 0;
    if (SetTarget_1FD530(p, a1, a2) == 0) p = 0;
    return p;
}

__attribute__((section(".text.InitNodePool_1FE2B8")))
void InitNodePool_1FE2B8(int a0) {
    char *p = (char *)a0 + 0x3C00;
    unsigned int i = 0;
    do {
        ClearAndResetFields_1FE278(a0, (int)p);
        i++;
        p += 0x70;
    } while (i < 0x100);
}
