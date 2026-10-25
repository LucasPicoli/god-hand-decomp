/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern unsigned char D_0076A790[];
extern unsigned char D_0076F050[];
extern unsigned char D_00770850[];
extern unsigned char D_0076CF20[];

__attribute__((section(".text.GetSoundEntryStatus_375EF8")))
int GetSoundEntryStatus_375EF8(void *a0) {
    unsigned short *p;
    int r;
    if (SndVoice_find(a0) != 0) return 1;
    p = func_00376A90(a0);
    if (!p) return 0;
    r = 2;
    if (*p & 0x100) r = 6;
    return r;
}

__attribute__((section(".text.ClearEventFlagsPending_375FA0")))
void ClearEventFlagsPending_375FA0(void) {
    unsigned char *base = D_0076A790;
    unsigned short *p = (unsigned short *)(base + 0x22);
    unsigned short v;
    v = *p;
    if (v & 0x10) {
        *(unsigned short *)(base + 0x22) = v & 0xFFEF;
        SeqNode_setSubByKind(4, 1);
        v = *(unsigned short *)(base + 0x22);
    }
    if (v & 0x20) {
        *(unsigned short *)(base + 0x22) = v & 0xFFDF;
        SeqNode_setSubByKind(4, 2);
    }
}

__attribute__((section(".text.ClearPendingEntries_376008")))
void ClearPendingEntries_376008(void) {
    unsigned char *s0 = D_0076F050;
    int s1 = 0x5F;
    do {
        if (*(unsigned short *)s0 != 0) {
            if (*(unsigned char *)(s0 + 8) & 0x10) {
                BuildSlotEntry_376200(s0);
            } else {
                SndSlot_startFromDesc(s0);
            }
            *(unsigned short *)s0 = 0;
        }
        s0 += 0x40;
    } while (--s1 >= 0);
}

__attribute__((section(".text.BuildSlotEntry_376200")))
int BuildSlotEntry_376200(void *a0) {
    void *r;
    r = func_00376A90(*(void **)((char *)a0 + 4));
    if (r == 0) return -1;
    if (*(short *)((char *)a0 + 0xA) == 0) {
        SetSlotEntry_376260(r, a0);
    } else {
        func_003762D8(r, a0);
    }
    return 0;
}

__attribute__((section(".text.ClearInvalidEntry_376400")))
void ClearInvalidEntry_376400(char *a0) {
    if (func_0037D0A8(*(int*)(a0+4)) == 0) {
        *(short*)(a0+0) = 0;
        *(int*)(a0+4) = 0;
    }
}

__attribute__((section(".text.BuildLinkedEntry_376510")))
int BuildLinkedEntry_376510(char *a0, unsigned short *a1) {
    unsigned short v1 = *a1;
    if (v1 & 1) {
        if ((v1 & 2) == 0) {
            return 0;
        }
    }
    *a1 = 1;
    *(int*)((char*)a1 + 4) = func_00377FF8();
    *(short*)((char*)a1 + 8) = *(unsigned short*)(a0 + 8);
    *(short*)((char*)a1 + 0xA) = *(unsigned short*)(*(int*)(a0 + 0x30) + 6);
    InitRandFields_3768B0((int)a0, a1);
    return 0;
}

__attribute__((section(".text.BuildMsgNode_376588")))
int BuildMsgNode_376588(char *a0, char *a1) {
    char *t1 = func_0037D170();
    if (t1 == 0) {
        return 0;
    }
    *(short*)(t1 + 0x0) = 1;
    *(int*)(t1 + 0x4) = *(int*)(a1 + 4);
    *(int*)(t1 + 0x8) = *(int*)(a0 + 4);
    *(char*)(t1 + 0xC) = 0x10;
    *(char*)(t1 + 0xD) = 4;
    *(short*)(t1 + 0x10) = -1;
    *(short*)(t1 + 0xE) = 0;
    *(short*)(t1 + 0x12) = *(unsigned short*)(a0 + 2);
    *(short*)(t1 + 0x14) = *(unsigned short*)(a1 + 2);
    func_00376CF8(a0, t1);
    return 0;
}

__attribute__((section(".text.BuildHitMsgNode_376618")))
int BuildHitMsgNode_376618(char *a0, char *a1) {
    char *s0;
    InitRandFields_3768B0(a0, a1);
    s0 = func_0037D170();
    if (s0 == 0) {
        return 0;
    }
    *(short*)(s0 + 0x0) = 1;
    *(int*)(s0 + 0x4) = *(int*)(a1 + 4);
    *(int*)(s0 + 0x8) = *(int*)(a0 + 4);
    *(char*)(s0 + 0xC) = 0x10;
    *(char*)(s0 + 0xD) = 4;
    *(short*)(s0 + 0xE) = 1;
    *(short*)(s0 + 0x10) = 0;
    *(short*)(s0 + 0x12) = *(unsigned short*)(a0 + 2);
    *(short*)(s0 + 0x14) = *(unsigned short*)(a1 + 2);
    func_00376CF8(a0, s0);
    *(short*)(s0 + 0x2A) = 0xD;
    *(short*)(s0 + 0x30) = *(unsigned short*)(a1 + 0xC);
    *(short*)(s0 + 0x32) = *(unsigned short*)(a1 + 0xC);
    *(short*)(s0 + 0x34) = *(unsigned short*)(a1 + 0xE);
    *(short*)(s0 + 0x3C) = *(unsigned short*)(a1 + 0x10);
    return 0;
}

__attribute__((section(".text.UpdatePendingFlags_376820")))
void UpdatePendingFlags_376820(void *a0) {
    char *s = (char *)a0;
    if (*(unsigned short *)(s + 0x12) & 0x1) {
        *(short *)(s + 0x24) = func_003780B0(*(short *)(s + 0x20), *(short *)(s + 0x18));
        *(short *)(s + 0x26) = func_003780B0(*(short *)(s + 0x22), *(short *)(s + 0x18));
        func_00376D28(a0, 1);
    }
    if (*(unsigned short *)(s + 0x12) & 0x2) {
        func_00376D28(a0, 2);
    }
    if (*(unsigned short *)(s + 0x12) & 0x4) {
        func_00376D28(a0, 4);
    }
    *(short *)(s + 0x12) = 0;
}

__attribute__((section(".text.InitRandFields_3768B0")))
void InitRandFields_3768B0(void *a0, void *a1) {
    char *s1 = (char *)a1;
    char *c = *(char **)((char *)a0 + 0x30);
    int s0;
    *(short *)(s1 + 0xC) = *(unsigned short *)(c + 0x8);
    *(short *)(s1 + 0xE) = *(unsigned short *)(c + 0xA);
    *(short *)(s1 + 0x10) = *(unsigned short *)(c + 0xC);
    s0 = *(short *)(c + 0xE);
    if (s0 == 0) {
        *(short *)(s1 + 0x12) = 0;
        return;
    }
    {
        short result;
        if (s0 < 0x11) {
            result = (short)(func_00377FA0() % (s0 + 1));
        } else {
            unsigned int x = (unsigned int)func_00377FA0();
            int q = s0 / 16;
            result = (short)((int)(x % 0x11u) * q);
        }
        *(short *)(s1 + 0x12) = result;
    }
}

__attribute__((section(".text.FindSlotEntry_376A10")))
void *FindSlotEntry_376A10(void *a0) {
    char *a1 = (char *)a0;
    char *s0 = (char *)D_00770850 + (int)(*(signed char *)(a1 + 0x9)) * 0xE0;
    if (*(unsigned short *)s0 == 0) {
        return s0;
    }
    {
        int av = *(signed char *)(a1 + 0x8);
        int bv = *(signed char *)(s0 + 0x10);
        if (av < bv) {
            return (void *)0;
        }
        if (av == bv) {
            if ((*(unsigned short *)(a1 + 0xE) & 0x20) == 0) {
                return (void *)0;
            }
        }
        ClearSlotRefs_376AE0(s0, -1);
        return s0;
    }
}

__attribute__((section(".text.ClearSlotRefs_376AE0")))
void ClearSlotRefs_376AE0(void *a0, int a1) {
    int s2 = (int)(short)a1;
    char *s = (char *)D_0076CF20;
    char *end = (char *)D_0076CF20 + 0xF00;
    do {
        if (*(unsigned short *)s != 0) {
            if (*(unsigned char *)(s + 0x5) & 0x4) {
                if (*(int *)(s + 0x14) == *(int *)((char *)a0 + 0x4)) {
                    func_0037D8B8(s, s2);
                }
            }
        }
        s += 0x50;
    } while ((int)s < (int)end);
    *(short *)a0 = 0;
    *(int *)((char *)a0 + 0x4) = 0;
}
