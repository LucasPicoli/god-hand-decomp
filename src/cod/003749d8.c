/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern unsigned short D_0076A7D4[];
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern int D_00773250[];
extern int D_0076DF10[];
extern char D_00770850[];

struct rec { unsigned short f0; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short f8; unsigned short fA; int fC; };
__attribute__((section(".text.StoreSoundEntry_3749D8")))
int StoreSoundEntry_3749D8(short a0, struct rec *a1) {
    short *dst = (short *)&D_0076A7D4[(int)a0 * 0x10];
    int n = 0;
    unsigned int f0;
    if (a0 == 0) n = a1->f2 & 1;
    f0 = a1->f0;
    if (f0 >= 0xA) n++;
    if (a1->f4 >= 0x81) n++;
    if (a1->f6 >= 0x81) n++;
    if (a1->f8 >= 0x80) n++;
    if (a1->fA >= 0x80) n++;
    if (((a1->fC & 0x1FFFF) ^ 0x1FFFF) != 0) n++;
    if (n != 0) return -1;
    dst[0] = f0; dst[1] = a1->f2; dst[2] = a1->f4; dst[3] = a1->f6;
    dst[4] = a1->f8; dst[5] = a1->fA;
    *(int *)(dst + 6) = a1->fC;
    *(int *)(dst + 8) = func_00374AE0((short)f0);
    return 0;
}

__attribute__((section(".text.InitSoundBlock_374D98")))
void InitSoundBlock_374D98(short a0, short a1, short *a2)
{
    func_003A52F0(a2, 0, 0x30);
    a2[1] = a1;
    a2[0] = a0;
    *(unsigned short *)((char *)a2 + 0xE) = 0x8000;
}

__attribute__((section(".text.BuildSoundNode_374DF8")))
int BuildSoundNode_374DF8(void *a0, int a1) {
    char *s2 = (char *)a0;
    char *p;
    if (*(unsigned short *)(s2 + 0xE) & 0x8000) return 0;
    p = func_0037D170();
    if (p == 0) return 0;
    *(short *)(p + 0x0) = 3;
    if (a1 != 0) *(int *)(p + 0x4) = a1;
    else *(int *)(p + 0x4) = func_00377FF8();
    *(char *)(p + 0xC) = 2;
    *(char *)(p + 0xD) = 1;
    *(int *)(p + 0x8) = 0;
    *(short *)(p + 0xE) = -1;
    *(short *)(p + 0x12) = -1;
    *(short *)(p + 0x10) = 0;
    *(short *)(p + 0x14) = 0;
    *(short *)(p + 0x16) = 0;
    *(short *)(p + 0x18) = 0;
    *(short *)(p + 0x1A) = 0;
    *(short *)(p + 0x1C) = 0;
    *(short *)(p + 0x1E) = 0;
    memcpy(p + 0x20, s2, 0x30);
    if (*(unsigned short *)(p + 0x48) != 0xFFFF) {
        *(char *)(p + 0xD) = *(unsigned char *)(p + 0xD) | 8;
    }
    return *(int *)(p + 0x4);
}

__attribute__((section(".text.AddSoundEntry_374F30")))
int AddSoundEntry_374F30(int a0, void *a1) {
    char *p = func_0037D170();
    if (p == 0) return -1;
    *(short *)(p + 0x0) = 1;
    *(char *)(p + 0xD) = 1;
    *(short *)(p + 0xE) = 1;
    *(int *)(p + 0x4) = a0;
    *(char *)(p + 0xC) = 0x10;
    *(short *)(p + 0x12) = -1;
    *(int *)(p + 0x8) = 0;
    *(short *)(p + 0x10) = 0;
    *(short *)(p + 0x14) = 0;
    *(short *)(p + 0x16) = 0;
    *(short *)(p + 0x18) = 0;
    *(short *)(p + 0x1A) = 0;
    *(short *)(p + 0x1C) = 0;
    *(short *)(p + 0x1E) = 0;
    memcpy(p + 0x20, a1, 0x30);
    if (D_00773250[*(short *)(p + 0x20)] != 0 && *(unsigned short *)(p + 0x48) != 0xFFFF) {
        *(char *)(p + 0xD) = *(unsigned char *)(p + 0xD) | 8;
    }
    return 0;
}

__attribute__((section(".text.func_003750E0")))
int func_003750E0(void *a0) {
    if (SeqCmd_findStartByMask(1, a0) != 0) return 1;
    if (func_0037D060(a0) != 0) return 2;
    return 0;
}

__attribute__((section(".text.func_00375128")))
int func_00375128(short a0) {
    if (func_0037D220(1, a0) != 0) return 1;
    if (func_0037D100(a0 & 0xFFFF) != 0) return 2;
    return 0;
}

__attribute__((section(".text.UpdateEntryVolume_3751B8")))
int UpdateEntryVolume_3751B8(void *a0, short a1) {
    unsigned short local;
    char *s0 = (char *)a0;
    int s1 = a1;
    int idx = *(short *)(s0 + 0);
    int *ent;
    int r;
    ent = (int *)((char *)D_0076DF10 + idx * 32);
    if (*(int *)((char *)ent + 0x10) != 0 && (*(unsigned short *)(s0 + 0xE) & 1) == 0) {
        r = func_003781F8(s1, s0, &local);
        if (r == -1) return -1;
        if (r == 0) {
            int v = *(short *)(s0 + 0x10) * (int)(short)local;
            v = v / 0x7F;
            *(short *)(s0 + 0x10) = (short)v;
            *(short *)(s0 + 0x12) = (short)v;
        }
        r = func_00378398(s1, s0, &local);
        if (r == -1) return -1;
        if (r == 0) {
            *(short *)(s0 + 0x1C) = local;
        }
    }
    return 0;
}

__attribute__((section(".text.UpdateEntryParams_3752A0")))
int UpdateEntryParams_3752A0(void *a0, int a1) {
    int v1 = 0;
    short s1 = (short)a1;
    unsigned char buf[0x10];
    if (((*(unsigned short *)((char *)a0 + 0xE)) & 2) == 0) {
        v1 = func_00378180(s1, buf);
        if (v1 == 0) {
            *(unsigned short *)((char *)a0 + 0x14) = *(unsigned short *)buf;
        }
    }
    if (((*(unsigned short *)((char *)a0 + 0xE)) & 4) == 0) {
        *(short *)((char *)a0 + 0x16) = s1;
    }
    return v1;
}

__attribute__((section(".text.InitSoundEntry_375B90")))
void InitSoundEntry_375B90(short a0, short a1, void *a2)
{
    func_003A52F0(a2, 0, 0x30);
    *(short *)((char *)a2 + 0x2) = a1;
    *(short *)((char *)a2 + 0x0) = a0;
    *(unsigned short *)((char *)a2 + 0xE) = (unsigned short)0x8000;
}

struct s_data { char d[0x30]; };




__attribute__((section(".text.BuildSoundEvent_375BF0")))
int BuildSoundEvent_375BF0(void *a0)
{
    char *p;
    if (*(unsigned short *)((char *)a0 + 0xE) & 0x8000) {
        return 0;
    }
    p = (char *)func_00376978();
    if (p == 0) {
        return 0;
    }
    *(short *)(p + 0x0) = 1;
    *(int *)(p + 0x4) = func_00377FF8();
    *(char *)(p + 0x8) = *(unsigned char *)((char *)a0 + 0x6);
    *(char *)(p + 0x9) = 4;
    *(short *)(p + 0xA) = -1;
    *(struct s_data *)(p + 0x10) = *(struct s_data *)a0;
    return *(int *)(p + 0x4);
}

struct s_data_cd0 { char d[0x30]; };



__attribute__((section(".text.BuildSoundEventCd0_375CD0")))
int BuildSoundEventCd0_375CD0(int a0, void *a1)
{
    char *p;
    p = (char *)func_00376978();
    if (p == 0) {
        return -1;
    }
    *(char *)(p + 0x8) = 0x10;
    *(int *)(p + 0x4) = a0;
    *(char *)(p + 0x9) = 4;
    *(short *)(p + 0x0) = 1;
    *(short *)(p + 0xA) = 1;
    *(struct s_data_cd0 *)(p + 0x10) = *(struct s_data_cd0 *)a1;
    return 0;
}

__attribute__((section(".text.ForwardSoundEventAll_375DE0")))
int ForwardSoundEventAll_375DE0(short a0, short a1)
{
    int e = (int)D_00770850;
    int end = (int)D_00770850 + 0x2A00;
    do {
        if (*(unsigned short *)(e + 0x0) != 0) {
            if (BuildSoundEventEntry_375E78(*(int *)(e + 0x4), a0, a1) == -1) {
                return -1;
            }
        }
        e += 0xE0;
    } while (e < end);
    return 0;
}

__attribute__((section(".text.BuildSoundEventEntry_375E78")))
int BuildSoundEventEntry_375E78(int a0, short a1, short a2)
{
    short *p;
    p = (short *)func_00376978();
    if (p == 0) {
        return -1;
    }
    *(short *)((char *)p + 0x0) = 1;
    *(short *)((char *)p + 0x26) = a2;
    *(int *)((char *)p + 0x4) = a0;
    *(char *)((char *)p + 0x8) = 0x10;
    *(char *)((char *)p + 0x9) = 4;
    *(short *)((char *)p + 0x22) = a1;
    *(short *)((char *)p + 0xA) = 0;
    return 0;
}
