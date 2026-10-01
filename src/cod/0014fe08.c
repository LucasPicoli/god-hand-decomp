extern int D_00754200;
extern int D_00569B70;
extern char D_005FEE00[];

__attribute__((section(".text.InitAllocBuffer_14FE08")))
void InitAllocBuffer_14FE08(unsigned char *a0, int a1) {
    int n = a1 << 4;
    void *p = EnsureInitThenForward_2A9538_30EE08(n, 0x80, &D_00754200);
    *(void **)(a0 + 0x0) = p;
    func_003A52F0(p, 0, n);
    *(int *)(a0 + 0x20) = a1;
    func_0014FE78(a0);
}

__attribute__((section(".text.InitDamageCollPair_1B18B8")))
void InitDamageCollPair_1B18B8(unsigned char *a0) {
    int v = 0x32;
    *(short *)(*(unsigned char **)(a0 + 0x66C) + 0x46) = 0x30;
    *(int *)(*(unsigned char **)(a0 + 0x66C) + 0x4C) = v;
    cDamageUnit_SetDamageCollActive(*(unsigned char **)(a0 + 0x66C), 1);
    *(short *)(*(unsigned char **)(a0 + 0x670) + 0x46) = 0x48;
    *(int *)(*(unsigned char **)(a0 + 0x670) + 0x4C) = v;
    cDamageUnit_SetDamageCollActive(*(unsigned char **)(a0 + 0x670), 1);
}

__attribute__((section(".text.cCoreSave_findNextStage")))
int cCoreSave_findNextStage(int *a0) {
    unsigned int s0;
    if (*a0 == 0) {
        return 0;
    }
    s0 = 1;
    while (s0 < 8) {
        if (cCoreSave_ckClearStage(&D_00569B70, s0) == 0) {
            break;
        }
        s0 = (s0 + 1) & 0xFF;
    }
    return (signed char)s0;
}

__attribute__((section(".text.AddQueueEntry_1FF4D0")))
void AddQueueEntry_1FF4D0(int a0, int a1)
{
    int *s0 = (int *)a0;
    int new_var;
    int v0;
    int *base;
    int *q1;
    int *q2;

    new_var = a1 - 0x200;
    if ((unsigned int)new_var < 0xFF) {
        v0 = func_002CB278(D_005FEE00);
        base = (int *)((char *)s0 + 0x24);
        q1 = base + s0[6];
        *q1 = v0;
        q2 = base + s0[6];
        if (*q2 != -1) {
            new_var = s0[6] + 1;
            s0[6] = new_var;
        }
    }
}

__attribute__((section(".text.FreeObjectSlot_2018F0")))
void FreeObjectSlot_2018F0(int a0)
{
    int *s0 = (int *)a0;
    int *v0;

    v0 = (int *)s0[0];
    if (v0 != 0) {
        func_00323A70(v0[0x21]);
        v0 = (int *)s0[0];
        v0[0x21] = 0;
        v0 = (int *)s0[0];
        if (v0[0x1F] != 0) {
            func_002A9648(v0[0x1F], v0[0x20], v0[0x1E], 0x10);
        }
        func_003A52F0(s0[0], 0, 0x88);
        s0[0] = 0;
    }
}
