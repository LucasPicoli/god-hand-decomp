/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"
#include "godhand/MpvHandle.h"
#include "godhand/sftim.h"

extern struct S2 { int a; int b; } D_00457B10;
extern int func_00345848;
extern void MWSFSVM_Error();
extern int Cmp_a1_Eq_0x37B0(int *, int);
extern char D_003DA5F8;
extern void func_00323AA0(int a0);
extern void sfbuf_SetSupSj(void *a0, void *a1, void *a2, int a3);
extern void sfbuf_InitBufData(void *a0, int a1, int a2);
extern int SFHDS_ProcessHdr();
extern int Obj34D8_CopyVec3_From98_To934();
extern int MPS_SetErrFn();
extern void func_0034FE78();

__attribute__((section(".text.sfadxt_ChkPrepFlg")))
int sfadxt_ChkPrepFlg(int a0)
{
    int *v0;
    int s0, s2;
    int r;

    v0 = (int *)((char *)a0 + 0x1FFC);
    s2 = *(int *)((char *)v0 + 0x14);
    s0 = *(int *)((char *)v0 + 0x10);

    r = SFBUF_GetPrepFlg(a0, s2);
    if (r == 1)
        return r;

    r = SFBUF_GetPrepFlg(a0, s0);
    if (r != 1)
        return r;

    r = sfadxt_IsPrepEnd(a0);
    if (r == 0)
        return r;

    return SFBUF_SetPrepFlg(a0, s2, 1);
}

__attribute__((section(".text.mpvhdec_GetCodec")))
int mpvhdec_GetCodec(MpvHandle *hn, SjChunk *ck)
{
    Sint8 *p;
    int d;

    if (hn->codec != 0)
        return hn->codec;

    p = MPV_SearchDelim(ck->data, ck->len, MPV_DLM_SHC);
    if (p == 0)
        return hn->codec;

    p += 4;
    p = MPV_SearchDelim(p, ck->len - (p - ck->data), -1);
    if (p == 0)
        return hn->codec;

    d = MPV_CheckDelim(p);
    if (d & MPV_DLM_ESC)
        hn->codec = MPV_CODEC_M2V;
    else if (d != 0)
        hn->codec = MPV_CODEC_M1V;
    return hn->codec;
}

__attribute__((section(".text.func_00345780")))
int func_00345780(int a0)
{
    struct S2 sp;

    sp = D_00457B10;
    sp.b = a0;

    if (Cmp_a1_Eq_0x37B0(&D_00457BD8, 0x37B0) != 1) {
        MWSFSVM_Error(&D_00457BE0);
        return -1;
    }

    if (func_0034DB60(&sp) != 0) {
        MWSFLIB_SetErrCode(-0x12D);
    } else {
        if (func_0034DE20(0, &func_00345848, 0) != 0)
            MWSFLIB_SetErrCode(-0x12F);
    }
}

void func_00335500(void *);
void func_003A52F0(void *, int, int);
void func_00335DD8(void);
void func_00335D18(int, int);

__attribute__((section(".text.LSC_Finish")))
void LSC_Finish(void)
{
    int cmp;
    int i;
    char *p;

    if (--D_003DA5F0 != 0) {
        return;
    }

    cmp = 1;
    p = &D_003DA5F8;
    for (i = 0x1F; i >= 0; p += 0x238, i--) {
        if (*p == cmp) {
            func_00335500(p);
        }
    }

    func_003A52F0(&D_003DA5F8, 0, 0x4700);
    func_00335DD8();
    func_00335D18(0, 0);
}

int Forward328098_349B88(int);
void MWSTM_SetFileRange(int, int, int, int, int);
int Forward3281C8_349B48(int);
int MWSFLIB_SetErrCode();
void MWSFSVM_Error();
void func_00342FF8(void *);

__attribute__((section(".text.func_00348FF0")))
int func_00348FF0(void *a0)
{
    void *s0;
    int r;

    s0 = a0;
    r = Forward328098_349B88(*(int *)((char *)s0 + 0x40));

    if (r == 2) {
        return -1;
    }

    {
        void *obj = *(void **)((char *)s0 + 0x1BC);
        if (obj != 0) {
            int *vtbl = *(int **)obj;
            void (*fn)(void *) = (void (*)(void *))vtbl[5];
            fn(obj);
        }
    }

    MWSTM_SetFileRange(
        *(int *)((char *)s0 + 0x40),
        *(int *)((char *)s0 + 0x1A4),
        *(int *)((char *)s0 + 0x1B0),
        *(int *)((char *)s0 + 0x1B4),
        *(int *)((char *)s0 + 0x1B8));

    r = Forward3281C8_349B48(*(int *)((char *)s0 + 0x40));

    if (r == -1) {
        *(int *)((char *)s0 + 4) = 4;
        MWSFLIB_SetErrCode(-0x66);
        MWSFSVM_Error(D_00459300, *(int *)((char *)s0 + 0x1A4));
        *(int *)((char *)s0 + 0x1AC) = 0;
        return -1;
    }

    func_00342FF8(s0);
    return 1;
}

void func_00349718(void *, int);
void func_00349728(void *, int);
void SFD_ExecOne(int);
void mwSfdExecDecSvrHndl(void *);
int Obj0000_Get_Field_44_LT_1_If_Field_48_In_1_4(int);

__attribute__((section(".text.func_00349630")))
int func_00349630(void *a0)
{
    void *s0;
    int s1;
    int s2;

    s0 = a0;
    s2 = *(int *)((char *)s0 + 0x3C);
    func_00349718(s0, 1);
    s1 = *(int *)s0;

    if (s1 != 1) {
        func_00349718(s0, 0);
        return 0;
    }

    D_003EE0A0 = (int)s0;
    func_00349728(s0, 1);
    SFD_ExecOne(s2);
    func_00349728(s0, 0);

    if (*(int *)((char *)s0 + 4) == 0) {
        *(int *)((char *)s0 + 0x68) = 0;
    } else {
        *(int *)((char *)s0 + 0x68) = s1;
        mwSfdExecDecSvrHndl(s0);
    }

    func_00349718(s0, 0);
    return (unsigned int)(Obj0000_Get_Field_44_LT_1_If_Field_48_In_1_4(s2) ^ 1) > 0;
}

__attribute__((section(".text.sfmpv_DiscardSec")))
void sfmpv_DiscardSec(void *a0, SjObj *sj) {
    SjChunk ck;

    while (1) {
        sj->vt->getChunk(sj, 1, 4, &ck);
        if (ck.len != 4) break;
        if (MPV_CheckDelim(ck.data) != MPV_DLM_SEC) break;
        sj->vt->putChunk(sj, 0, &ck);
        sfmpv_AddRtotSj(a0, 4);
    }
    sj->vt->ungetChunk(sj, 1, &ck);
}

__attribute__((section(".text.func_00323780")))
int func_00323780(int a0, int a1, int a2, int a3) {
    int s4, s3, s1, s0, s2;

    s4 = a0;
    s3 = a1;
    s1 = a2;
    s0 = a3;

    adxf_SetCmdHstry(1, 0, s4, s3, -1);
    s2 = adxf_CreateAdxFs();

    if (s2 != 0) {
        int r = adxf_SetFileInfoRange(s2, s4, s3, s1, s0);
        if (r < 0) {
            func_00323AA0(s2);
            s2 = 0;
        }
    }

    adxf_SetCmdHstry(1, 1, s4, s3, -1);
    return s2;
}

__attribute__((section(".text.sfbuf_InitRingSj")))
int sfbuf_InitRingSj(char *a0, int *a1, int *a2, int a3, void *t0) {
    int buf[8];
    char *s0;
    char *s1;
    int s2;
    int s3;
    int v1;

    s0 = a0 + a3 * 116;
    a2 = a2 + a3;
    a1 = a1 + a3;

    v1 = *a2;
    s1 = s0 + 16;

    if (v1 == 0) {
        s3 = 0;
        s2 = 4;
    } else {
        int r;
        s3 = 1;
        r = sfbuf_CreateSj(buf, *a1, v1, t0);
        s2 = 5;
        if (r != 0) return r;
        sfbuf_SetSupSj(s1, buf, s0, 1);
    }

    sfbuf_InitBufData(s0, s2, s3);
    return 0;
}

__attribute__((section(".text.sfhds_SetHdrRaw")))
int sfhds_SetHdrRaw(SftimHn *hn, char *raw, int len) {
    int (*fn)();
    int elem;
    int sz;
    SfdHdInf *hdr;

    fn = (int (*)())GetArrayElemA0C_35A1C8(hn, 0x4B);
    elem = GetArrayElemA0C_35A1C8(hn, 0x4C);
    if (fn) {
        fn(elem, raw, len);
    }
    hdr = &hn->hdr;
    if (hdr->valid != 0) {
        return 0;
    }
    sz = 0x800;
    if (len < 0x801) sz = len;
    MEM_Copy(hdr->raw, raw, sz);
    hdr->len = sz;
    SFHDS_ProcessHdr(hdr);
    Obj34D8_CopyVec3_From98_To934(hn);
    func_0034D2D8(hn);
    return 1;
}

__attribute__((section(".text.func_0034FD28")))
int func_0034FD28(int a0) {
    void *s1;
    int *s2;

    s2 = (int *)(a0 + 0x2198);
    *(int *)(a0 + 0x1F7C) = (int)s2;
    sfmps_InitInf(s2);

    s1 = func_00368FE8();
    if (!s1) {
        return func_0034DD70(0, 0xFF000D08);
    }
    if (MPS_SetErrFn(s1, func_0034FE78, a0)) {
        Tramp_MPS_Destroy_34FEE0(s1);
        return func_0034DD70(0, 0xFF000D09);
    }
    *s2 = (int)s1;
    return 0;
}
