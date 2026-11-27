/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern unsigned short D_0076A790;

__attribute__((section(".text.ClearPendingFlagEvents_376E38")))
void ClearPendingFlagEvents_376E38(void) {
    unsigned short *p = &D_0076A790;
    unsigned short v;
    v = *(unsigned short*)((char*)p + 0x22);
    if (v & 0x4) {
        *(unsigned short*)((char*)p + 0x22) = v & 0xFFFB;
        SeqNode_setSubByKind(2, 1);
    }
    v = *(unsigned short*)((char*)p + 0x22);
    if (v & 0x8) {
        *(unsigned short*)((char*)p + 0x22) = v & 0xFFF7;
        SeqNode_setSubByKind(2, 2);
    }
}

__attribute__((section(".text.CopyChannelParams_377378")))
void CopyChannelParams_377378(char *a0, char *a1) {
    char *s1 = a1 + 0x26;
    char *s3 = a0 + 0x38;
    char *s0 = a0 + 0x3E;
    int mask = 1;
    int i;
    *(int*)(a0 + 0x58) = *(int*)(a1 + 0x40);
    for (i = 3; i >= 0; i--) {
        if (*(int*)(a0 + 0x58) & mask) {
            *(short*)(s0 - 4) = (short)(*(unsigned short*)(s1 - 4) << 8);
            *(short*)(s0 + 0) = (short)*(unsigned short*)(s1 + 0);
            SdeFadeSpdSet(s3);
        }
        mask <<= 1;
        s3 += 8;
        s0 += 8;
        s1 += 8;
    }
    *(unsigned short*)(a0 + 0) = *(unsigned short*)(a0 + 0) | 0x10;
}

__attribute__((section(".text.UpdateSoundNodeState_377598")))
void UpdateSoundNodeState_377598(void *a0) {
    unsigned short v = *(unsigned short*)a0;
    if ((v & 0x8000) == 0) {
        if ((v & 0x8) != 0) {
            *(short*)((char*)a0 + 0x14) = 3;
            return;
        }
        UpdateChannelState_3775F0(a0);
    }
    UpdateChannelOutputLevels_377700(a0);
}

__attribute__((section(".text.UpdateChannelState_3775F0")))
void UpdateChannelState_3775F0(void *a0) {
    int i;
    if ((*(unsigned short*)a0 & 0x10) != 0) {
        for (i = 0; i < 4; i++) {
            strCtlFadeStereoOne(a0, i);
        }
        if (*(int*)((char*)a0 + 0x58) == 0) {
            short *p;
            i = 0;
            p = (short*)((char*)a0 + 0x38);
            *(unsigned short*)a0 = *(unsigned short*)a0 & 0xFFEF;
            for (; i < 4; i++) {
                if (*p != 0) return;
                p += 4;
            }
            SdeStrCtlFadeOutEnd(a0);
        }
    }
}

__attribute__((section(".text.UpdateChannelOutputLevels_377700")))
void UpdateChannelOutputLevels_377700(void *a0) {
    unsigned short f = *(unsigned short*)((char*)a0 + 0x10);
    if ((f & 1) != 0) {
        short *s3 = (short*)((char*)a0 + 0x68);
        short *s2 = (short*)((char*)a0 + 0x60);
        short *s0 = (short*)((char*)a0 + 0x38);
        int i = 3;
        do {
            i--;
            *s2 = func_003780B0(*(short*)((char*)a0 + 0x5C), *s0);
            s2++;
            *s3 = func_003780B0(*(short*)((char*)a0 + 0x5E), *s0);
            s3++;
            s0 += 4;
        } while (i >= 0);
        SeqTrack_copyPartTables(a0, 1);
    }
    if ((*(unsigned short*)((char*)a0 + 0x10) & 2) != 0) {
        SeqTrack_copyPartTables(a0, 2);
    }
    *(short*)((char*)a0 + 0x10) = 0;
}
