/* cygnus-2.96 matched TU. */

extern void func_0035ABC0(int a0, int *out0, int *out1);
extern void func_0035A7C8(int a0, int a1);
extern int Obj35C0_GetIndexed_1F34_C368(int a0, int a1);
extern int Obj35D0_ReturnOne_D048(int a0);
extern int Obj35C0_SetIndexed_1F34_C350(int a0, int a1, int a2);
extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(int a0, int a1);
extern int M2VERR_SetCode(int a0, int a1);
extern void func_0036DE80(int a0);
extern volatile int D_003DA5D8;
extern int D_003DA5F0;
extern int D_003DA5F8;
extern void Forward33B658_335CE8(int *);
extern void Forward33B670_335D00(int *);
extern void func_003A52F0(void *, int, int);
extern void func_00335DD0(void);
extern void func_00335D18(int, int);
extern int Obj35C0_IsIndexedSet_1F3C_C380(int, int);
extern int GetArrayElemA0C_35A1C8(int, int);
extern void *getElemInfPtr(void *, int);
extern void func_00335D40(void *);
extern void func_00328368(void *);
extern void func_00335848(void *);
extern int D_00454CD8;
extern int GetD003EE078_3463F8();
extern void mwrsc_WaitSprDmaEnd();
extern void func_00346498(int a0, int a1, int *a2);
extern void MWDMA_WaitEnd(int a0);
extern void func_00346578(int *a0, int a1, int a2);
extern int D_003EE080;
extern int D_0075CC80;
extern int D_00758C80;
extern void func_00345B38(void *a0);
extern void func_00345F48(void *a0, int a1);
extern int SFD_SetConcatPlay(int a0);
extern int MWSFSVM_Error(char *msg);
extern char D_004592D0[];
extern void sfbuf_PeekChunk(void *buf, int a1, void *out0, void *out1);
extern int Obj0000_Set_D_00766D44_Check_Field_188_NE_2(void *a0);
extern int D_00766CE8[];
extern void func_00368AB0(int a0, int *a1);
extern void func_00368B18(int a0, int *a1, int a2);
extern void PushGlobalD8478History_331C78(int);
extern void Forward3A52F0_334500(void *);
extern int D_00454948[];
extern void Thunk_func_0033B658(void *sp);
extern void Thunk_func_0033B670(void *sp);
extern int MPV_DecodePicAtr(int a0, int *a1, int *a2);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void func_00327418(void *a);
extern void func_003272C0(void *a);
extern void func_00326890(void *a);
extern void func_00327568(void *a);
extern void Obj0000_PostInc_D_003E3A80_338960(void);
extern void func_00338478(char *p);
extern void Obj0000_Decrement_D_003E3A80_338978(void);
extern void func_00340130(void);
extern void Forward332778_33B200(void);
extern int D_003E0710;
extern int D_003E0708;
extern char D_003E2B68[];
extern int GuardedCall_00329FD0_329F98();
extern long long func_0031DE10(long long a, long long b);
extern long long func_003B7FE0(long long a, long long b);
extern void func_00326CB8(void *a0);
extern void func_0033D870(int a0);
extern void func_00327048(void *a0);
extern void func_00327230(void *a0);
extern void func_00359F78(int a0, int a1);
extern int Obj34D8_SetGlobalEE0B8_IfField48(void *a0);
extern void func_0035A000(void *a0, int a1, int a2);
extern void func_0035A050(void *a0, int a1, int a2);
extern int D_003EE0C0[];

__attribute__((section(".text.func_0035B058")))
void func_0035B058(int a0) {
    int tmp0, tmp1;
    int s1 = a0;
    int s0 = s1 + 0xD30;
    int v0, v1;
    func_0035ABC0(s1, &tmp0, &tmp1);
    if (*(int *)(s0 + 0x28C) != tmp0 || *(int *)(s0 + 0x290) != tmp1) {
        func_0035A7C8(s1, s0);
        v0 = tmp0;
        v1 = tmp1;
        *(int *)(s0 + 0x28C) = v0;
        *(int *)(s0 + 0x290) = v1;
    }
    *(int *)(s1 + 0x44) = 1;
}

__attribute__((section(".text.func_0035CFC8")))
void func_0035CFC8(int a0) {
    int s0 = a0;
    if (Obj35C0_GetIndexed_1F34_C368(s0, 8) == 1) return;
    if (func_0034CA98(s0, *(int *)(s0 + 0x2160)) != 1) return;
    if (!Obj35D0_ReturnOne_D048(s0)) return;
    Obj35C0_SetIndexed_1F34_C350(s0, 8, 1);
}

__attribute__((section(".text.func_0036DE00")))
int func_0036DE00(int a0, int a1) {
    int s1 = a0;
    int s0 = a1;
    if (Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(s1, s0)) {
        return M2VERR_SetCode(0, 0xFF03020C);
    }
    s0 = func_0036DFF0(s1, s0);
    if (!s0) {
        func_0036DE80(s1);
    }
    return s0;
}

__attribute__((section(".text.func_00335DE0")))
void func_00335DE0(void) {
    int *s0;
    int sp_buf[1];
    int v3;

    v3 = D_003DA5D8;
    Forward33B658_335CE8(sp_buf);
    s0 = &D_003DA5F0;
    if (!*s0) {
        func_003A52F0(&D_003DA5F8, 0, 0x4700);
        func_00335DD0();
        func_00335D18(0, 0);
    }
    *s0 = *s0 + 1;
    Forward33B670_335D00(sp_buf);
}

__attribute__((section(".text.sfsee_IsAudioAnalyzing")))
int sfsee_IsAudioAnalyzing(int a0, int a1, int a2) {
    int s0;
    int s1;
    int s2;
    int r;
    int v0;

    s2 = a1;
    s1 = a2;
    r = Obj35C0_IsIndexedSet_1F3C_C380(a0, 3);
    s0 = a0;
    if (r) {
        r = GetArrayElemA0C_35A1C8(s0, 6);
        if (r == 1) {
            *(int*)s1 = r;
            v0 = *(int*)s2;
            return ((unsigned int)v0 < 1u);
        }
    }
    *(int*)s1 = 0;
    return 0;
}

__attribute__((section(".text.func_0035E1B8")))
int func_0035E1B8(void *a0, int a1, int *a2) {
    int *s2;
    int s0;
    void *s1;
    int v0;
    int v1;
    s2 = a2;
    s0 = a1 & 0xFF;
    *s2 = 0;
    s1 = getElemInfPtr(a0, s0);
    if (!s1) {
        return 0;
    }
    v0 = func_0035E9E8(s0);
    if (v0 != 0xC0) {
        return 0;
    }
    v1 = *(unsigned char *)((char *)s1 + 0x19);
    if (v1 != 1) {
        return 0;
    }
    v1 = *(unsigned char *)((char *)s1 + 0x1A);
    *s2 = v1;
    return 1;
}

__attribute__((section(".text.func_00335980")))
void func_00335980(void *a0) {
    void *s0;
    int v0;
    int v1;
    s0 = a0;
    if (!s0) {
        func_00335D40(&D_00454CD8);
        return;
    }
    if (!(v0 = *(signed char *)((char *)s0 + 1))) {
        goto end;
    }
    a0 = (void *)*(int *)((char *)s0 + 0x28);
    *(signed char *)((char *)s0 + 1) = 0;
    if (!a0) {
        goto common_0x2C;
    }
    v1 = *(signed char *)((char *)s0 + 2);
    if (v1 != 1) {
        *(int *)((char *)s0 + 0x2C) = 0;
        goto common_exit;
    }
    func_00328368(a0);
    *(signed char *)((char *)s0 + 2) = 0;
common_0x2C:
    *(int *)((char *)s0 + 0x2C) = 0;
common_exit:
    func_00335848(s0);
    *(int *)((char *)s0 + 0x34) = 0;
end:;
}

__attribute__((section(".text.sfsee_IsVideoAnalyzing")))
int sfsee_IsVideoAnalyzing(void *a0, int *a1, int *a2) {
    int *s2;
    void *s0;
    int *s1;
    int v1;
    int v0;
    s2 = a1;
    s0 = a0;
    s1 = a2;
    if (!Obj35C0_IsIndexedSet_1F3C_C380(s0, 2)) {
        goto fail;
    }
    v1 = GetArrayElemA0C_35A1C8(s0, 5);
    if (v1 != 1) {
        goto fail;
    }
    *s1 = v1;
    v0 = !(*s2);
    goto done;
fail:
    *s1 = 0;
    v0 = 0;
done:
    return v0;
}

__attribute__((section(".text.func_00346368")))
void func_00346368(void)
{
    int *s0;

    if (GetD003EE078_3463F8() == 1) {
        s0 = (int *)((char *)&D_003EE080);
        if (*s0 != 0) {
            mwrsc_WaitSprDmaEnd();
            func_00346498(0, 0x4000, &D_0075CC80);
            MWDMA_WaitEnd(8);
            func_00346578((int *)&D_00758C80, 0x4000, 0);
            MWDMA_WaitEnd(9);
            *s0 = 0;
        }
    }
}

__attribute__((section(".text.func_00359DF0")))
void func_00359DF0(int a0)
{
    int s0;
    int v0;
    int fa0;
    int fa1;
    int fa2;

    s0 = *(int *)((char *)a0 + 0x36B0);
    v0 = *(int *)((char *)s0 + 0xDD0);
    if (v0 > 0) {
        *(int *)((char *)s0 + 0xDA8) = v0;
        return;
    }
    fa0 = *(int *)((char *)s0 + 0xDC4);
    fa2 = *(int *)((char *)s0 + 0xDC8);
    fa1 = *(int *)((char *)s0 + 0xDCC);
    if (fa0 <= 0 || fa2 <= 0) {
        v0 = *(int *)((char *)s0 + 0x4);
        if (v0 > 0) {
            *(int *)((char *)s0 + 0xDA8) = v0;
            return;
        }
        if (fa0 <= 0) {
            fa0 = *(int *)((char *)s0 + 0xDAC);
        }
        if (fa2 <= 0) {
            fa2 = *(int *)((char *)s0 + 0xDB0);
            fa1 = *(int *)((char *)s0 + 0xDB4);
        }
        if (fa0 <= 0) {
            *(int *)((char *)s0 + 0xDA8) = v0;
            return;
        }
        if (fa2 <= 0) {
            *(int *)((char *)s0 + 0xDA8) = v0;
            return;
        }
    }
    v0 = func_0036C920(fa0, fa1, fa2);
    *(int *)((char *)s0 + 0xDA8) = v0;
}

__attribute__((section(".text.func_00348F68")))
void func_00348F68(void *a0) {
    void *s0;
    int r;
    int v1;

    s0 = a0;
    r = func_00359E80(*(int *)((char *)s0 + 0x3C));
    if (r == 3) {
        func_00345B38(s0);
        v1 = *(signed char *)((char *)s0 + 0x72);
        if (!v1) {
            func_00345F48(s0, 0);
        }
        v1 = *(signed char *)((char *)s0 + 0x70);
        if (v1 == 1) {
            r = SFD_SetConcatPlay(*(int *)((char *)s0 + 0x3C));
            if (r) {
                MWSFSVM_Error(D_004592D0);
            }
        }
    }
}

__attribute__((section(".text.sfset_IsCondValid")))
int sfset_IsCondValid(char *a0, int a1, int a2)
{
    if (a1 == 6 && a2 == 1) {
        if (Obj35C0_IsIndexedSet_1F3C_C380(a0, 3) == 0)
            return 0;
    }
    if (a1 == 5 && a2 == 1) {
        if (Obj35C0_IsIndexedSet_1F3C_C380(a0, 2) == 0)
            return 0;
    }
    return 1;
}

typedef struct {
    int start;
    int len;
} SfChunk;

typedef struct {
    int pos;            /* offset 0 = a0+0x18 */
    int next;           /* offset 4 = a0+0x1C */
} SfConti;

typedef struct {
    void *dummy0;
    void *buf;          /* offset 4 */
    int pad[4];
    SfConti conti;      /* offset 0x18 */
} SfBuf;



__attribute__((section(".text.sfbuf_ResetConti")))
void sfbuf_ResetConti(SfBuf *a0) {
    SfConti *s0;
    SfChunk chunk1;
    SfChunk chunk2;
    unsigned int pos;
    s0 = &a0->conti;
    sfbuf_PeekChunk(a0->buf, 1, &chunk1, &chunk2);
    pos = (unsigned int)s0->pos;
    if ((unsigned int)pos < (unsigned int)chunk1.start) {
        goto check2;
    }
    if ((unsigned int)pos < (unsigned int)(chunk1.start + chunk1.len)) {
        return;
    }
check2:
    if ((unsigned int)pos < (unsigned int)chunk2.start) {
        s0->pos = 0;
        s0->next = 0;
        return;
    }
    if ((unsigned int)pos < (unsigned int)(chunk2.start + chunk2.len)) {
        return;
    }
    s0->pos = 0;
    s0->next = 0;
}

__attribute__((section(".text.func_0036C568")))
int func_0036C568(int *a0, int a1, int *a2) {
    int *s0;
    int s1;
    int *s2;
    int *base;

    s0 = a0;
    s1 = a1;
    s2 = a2;

    if (s0 == 0) {
        base = D_00766CE8;
    } else {
        if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(s0) != 0) {
            return func_00369F20(0, 0xFF030210);
        }
        base = (int *)((char *)s0 + 0x190);
    }
    *s2 = base[s1];
    return 0;
}

__attribute__((section(".text.func_0034FAD8")))
void func_0034FAD8(int *a0) {
    int buf[12];
    int *s2;
    int *s1;
    int s0;
    int v0;

    s1 = (int*)((char*)a0 + 0x90C);
    s2 = (int*)*(int*)((char*)a0 + 0x1F7C);
    s0 = *s2;
    func_00368AB0(s0, buf);
    s0 = s0;
    v0 = buf[3];
    if (v0 > 0) {
        *(int*)((char*)s1 + 0x18) = v0;
    }
    func_00368B18(s0, (int*)((char*)buf + 0x10), 1);
    {
        int t;
        t = buf[8];
        if (t != -1) {
            *(int*)((char*)s1 + 0x1C) = t;
        }
        t = *(int*)((char*)s1 + 0x24);
        if (t == -1) {
            *(int*)((char*)s1 + 0x24) = *(int*)((char*)s2 + 8);
        }
        t = *(int*)((char*)s1 + 0x28);
        if (t == -1) {
            *(int*)((char*)s1 + 0x28) = *(int*)((char*)s2 + 4);
        }
    }
}

__attribute__((section(".text.func_00334698")))
void func_00334698(void *a0) {
    char *s1 = (char *)a0;
    int s0;

    if (s1 == 0) {
        return;
    }

    if ((unsigned char)s1[2] >= 2) {
        func_00334998(s1);
    }

    if (s1[1] == 0) {
        PushGlobalD8478History_331C78(0x5000);
        s0 = func_00331F50(*(int *)(s1 + 0x18));
        PushGlobalD8478History_331C78(0x5001);
        if (s0 < 0) {
            func_00326050(D_00454948);
        }
    }
    s1[0] = 0;
    Forward3A52F0_334500(s1);
}

typedef int (*FN)(int, int);

__attribute__((section(".text.func_0034C7F0")))
int func_0034C7F0(int a0, int a1) {
    int buf[4];
    int *s0;
    int s1;
    int s2;
    int v0;
    int v1;
    FN fn;
    int idx;
    idx = a1 * 116;
    s0 = (int *)((char *)a0 + idx + 0x1320);
    Thunk_func_0033B658(buf);
    s1 = ((int *)((char *)s0 + 0x20))[0];
    s2 = ((int *)((char *)s0 + 0x24))[0];
    if (s1 == 0 && s2 != 0) {
        v0 = *(int *)((char *)s0 + 0x4);
        v1 = *(int *)v0;
        fn = (FN)(*(int *)((char *)v1 + 0x24));
        s1 = s2 + fn(v0, 1);
    }
    if (s1 < 0) {
        s1 = 0x7FFFFFFF;
    }
    Thunk_func_0033B670(buf);
    return s1;
}

__attribute__((section(".text.func_00350820")))
void func_00350820(int a0) {
    int s0;
    int s1;
    int s2;
    int v0;
    int v1;
    int local[8];
    s0 = a0;
    s1 = *(int *)((char *)s0 + 0x1FC0);
    s2 = *(int *)s1;
    v0 = GetArrayElemA0C_35A1C8(s0, 0x5D);
    local[0] = v0;
    v1 = GetArrayElemA0C_35A1C8(s0, 0x5E);
    v0 = local[0];
    local[1] = v1;
    if (v0 == 0) {
        return;
    }
    if (v1 == 0) {
        return;
    }
    if (*(int *)((char *)s1 + 0x78) != 0xC0) {
        return;
    }
    if (MPV_DecodePicAtr(s2, local, local + 4) != 0) {
        return;
    }
    *(int *)((char *)s1 + 0x74) = 2;
    *(int *)((char *)s1 + 0x78) = 0xC8;
}

__attribute__((section(".text.func_00327370")))
void func_00327370(void *a0) {
    void *s0;
    int v0;
    char v1;

    s0 = a0;
    v0 = *(int *)((char *)s0 + 0xA0);
    if (v0 > 0) {
        Forward33B658_33E678();
        func_00327418(s0);
        Forward33B670_33E690();
    }
    v1 = *(char *)((char *)s0 + 1);
    if (v1 == 2) {
        func_003272C0(s0);
    } else if (v1 == 1) {
        func_00326890(s0);
    }
    v0 = *(int *)((char *)s0 + 0xA4);
    if (v0 <= 0) {
        return;
    }
    Forward33B658_33E678();
    func_00327568(s0);
    Forward33B670_33E690();
}

__attribute__((section(".text.func_00338638")))
void func_00338638(void) {
    int s1;
    char *s0;
    int s2;

    if (D_003E0710 == 1 && D_003E0708 <= 0) {
        return;
    }
    s2 = 1;
    Obj0000_PostInc_D_003E3A80_338960();
    s0 = D_003E2B68;
    s1 = 15;
    do {
        if (*s0 == s2) {
            func_00338478(s0);
        }
        s1--;
        s0 += 0x64;
    } while (s1 >= 0);
    Obj0000_Decrement_D_003E3A80_338978();
    func_00340130();
    Forward332778_33B200();
}

__attribute__((section(".text.func_0032F0D0")))
int func_0032F0D0(int *a0) {
    int *ptr;
    int i;
    int n;
    int r;

    ptr = a0 + 3;
    i = 0;
    n = func_0032F4C8(a0[1]);
    for (i = 0; i < n; i++) {
        r = GuardedCall_00329FD0_329F98(*ptr);
        ptr++;
        if (r == 6) {
            *((char *)a0 + 1) = 4;
        }
        if (r == 3) continue;
        break;
    }
    return i == n;
}

__attribute__((section(".text.func_0036C990")))
long long func_0036C990(long long a0, long long a1, long long a2) {
    long long s0;
    int s1;
    long long v0;
    long long v1;

    s0 = a2;
    if (s0) goto nonzero;
    v1 = a0 ^ a1;
    a0 = (long long)0x8000LL << 48;
    v0 = (long long)((unsigned long long)-1 >> 1);
    if (v1 < 0) v0 = a0;
    return v0;
nonzero:
    s1 = 1;
    if (a0 < 0) {
        s1 = -1;
        a0 = -a0;
    }
    if (a1 < 0) {
        s1 = -s1;
        a1 = -a1;
    }
    if (s0 < 0) {
        s0 = -s0;
        s1 = -s1;
    }
    v0 = func_0031DE10(a0, a1);
    v0 = func_003B7FE0(v0 + s0 / 2, s0);
    if (s1 < 0) v0 = -v0;
    return v0;
}

__attribute__((section(".text.func_003579F0")))
int func_003579F0(char *a0) {
    int local[4];
    char *s0 = a0;
    int *s1 = (int *)(a0 + 0x950);
    int s2 = 0;
    Thunk_func_0033B658(local);
    if (s1[0x20/4] == 0) {
        if (func_00357AA0(s0) != 0) {
            s1[0x20/4] = 1;
            s1[0x24/4] = s1[0x24/4] + 1;
            s2 = func_00356FD8(s0, 1);
        }
    } else {
        if (func_00357C20(s0) != 0) {
            s1[0x20/4] = 0;
            s2 = func_00356FD8(s0, 0);
        }
    }
    Thunk_func_0033B670(local);
    return s2;
}

__attribute__((section(".text.func_003272C0")))
void func_003272C0(void *a0) {
    void *s1 = a0;
    int s0 = *(int *)((char *)a0 + 4);
    int val;

    if (func_0033D190(s0) == 0) {
        func_00326CB8(s1);
    }

    func_0033D870(s0);

    if (func_0033D190(s0) == 3) {
        func_00327048(s1);
    }

    val = *(short *)((char *)s0 + 0x98);
    if (val == 0xA || val == 0x14 || val == 0xB || val == 0xC || val == 0xF) {
        func_00327230(s1);
    }
}

__attribute__((section(".text.func_0035E400")))
int func_0035E400(void *a0, int a1, int *out1, int *out2)
{
    int s0;
    char *s1;
    char *p;
    unsigned int b0;
    unsigned int b1;
    s0 = a1 & 0xFF;
    *out1 = 0;
    *out2 = 0;
    s1 = (char *)getElemInfPtr(a0, s0);
    if (!s1) return 0;
    if (func_0035E9E8(s0) != 0xE0) return 0;
    p = s1 + 0x1C;
    b0 = *(unsigned char *)p;
    *out1 = b0;
    b0 <<= 4;
    b0 |= *(unsigned char *)(p + 1) >> 4;
    *out1 = b0;
    b1 = *(unsigned char *)(p + 1);
    *out2 = b1;
    b1 <<= 8;
    b1 |= *(unsigned char *)(p + 2);
    b1 &= 0xFFF;
    *out2 = b1;
    return 1;
}

__attribute__((section(".text.SFD_SetCond")))
int SFD_SetCond(void *a0, int a1, int a2)
{
    if (!a0) {
        func_00359F78(a1, a2);
        D_003EE0C0[a1] = a2;
    } else if (Obj34D8_SetGlobalEE0B8_IfField48(a0)) {
        return func_0034DD70(0, 0xFF000112U);
    } else {
        func_0035A000(a0, a1, a2);
        func_0035A050(a0, a1, a2);
    }
    return 0;
}

__attribute__((section(".text.func_00334BD8")))
int func_00334BD8(int a0, int a1)
{
    int r = 0;
    if (a0 == 0)
        return r;
    switch (a1) {
    case 0xC8: r = func_00334B38(); break;
    case 0xC9: r = func_00334B58(); break;
    case 0xCA:
    case 0xCC: r = func_00334B88(); break;
    case 0xCB:
    case 0xCD: r = func_00334BA8(); break;
    case 0x12B: r = 1; break;
    }
    return r;
}
