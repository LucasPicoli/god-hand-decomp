/* cygnus-2.96 matched TU. */
/* cygnus-2.96 */

extern int func_00328098(void *a0);
extern void func_00329C68(void *a0, int a1, int a2, int a3, int a4);
extern int Obj3260_GetByte_1_D778(void *a0);
extern int Obj3270_GetVia4_0033CE98_77A0(void *a0);
extern void ADXERR_ItoA2(int a0, int a1, char *buf, int a3);
extern void func_0033F1A8(char *msg, char *buf);
extern void func_00329EA8(void *a0);
extern int Obj3270_GetVia4_Obj33C8_14_7788(void *a0);
extern int GetVia4_Obj33C8_GetShort_24_327800(void *a0);
extern int Obj3270_GetVia4_Obj33C8_10_77D0(void *a0);
extern void StoreArgAndUpdateChildB(void *a0, int a1);
extern void func_00328448(void *a0, int a1);
extern int Obj3270_GetVia4_Obj33C8_18_77E8(void *a0);
extern void Obj3270_SetField_3C(void *a0, int a1);
extern void Obj3270_SetField_44(void *a0, int a1);
extern void Obj3270_SetField_40(void *a0, int a1);
extern void Obj3270_SetField_48_4C(void *a0, void (*cb)(void *), void *a2);
extern int GetVia4_Obj33C8_GetField_34_7878_327878(void *a0);
extern void func_003283E8(void *a0, void (*cb)(void *), void *a2);
extern int GetVia4_Obj33C8_GetField_30_7860_327860(void *a0);
extern int GetVia4_Obj33C8_GetField_28_7818_327818(void *a0);
extern int Obj3270_GetVia4_0033CEF0_77B8(void *a0);
extern void Obj3260_Tramp_00338848_D428(void *a0, int a1);
extern void Obj3260_Tramp_00338710_D3C8(void *a0, int a1);
extern void Obj3260_Tramp_003386E0_D3B0(void *a0, int a1);
extern void Obj3260_NoOp_D490(void *a0, int a1);
extern void func_0032A9F0(void *a0, int a1);
extern void func_0032B490(void *a0, int *a1, int *a2);
extern void func_0032B488(void *a0, int a1, int a2);
extern void func_0032C2A8(void *a0);
extern void func_0033C238(void *a0, int a1);
extern int Obj3270_GetVia4_Obj33C8_98_7770(void *a0);
extern int func_00327968(void *a0);
extern void Obj3260_CallReturn0_003388F8_D498(void *a0, int a1);
extern void Obj3260_Tramp_003382A0_D320(void *a0, int a1);
extern void func_0032BF90(void *a0);
extern void func_0032C1E0(void *a0);
extern void func_0032C310(void *a0);
extern char D_004528C0[];
extern void (*D_003D145C)(void *a0, int a1, int a2, int a3);

/* adxt_stat_decinfo: read the stream header, size the buffers and start decoding */
__attribute__((section(".text.func_0032C5F8")))
void func_0032C5F8(void *a0)
{
    char *adxt = (char *)a0;
    char buf[32];
    int err1;
    int err2;
    void *sj;
    int secsize = 0x800;
    int bufsize;
    int stat;
    int hdr;
    int unit;
    int hdrsize;
    int nsect;
    int rem;
    int sfreq;
    int nch;
    int nbits;

    err1 = 0;
    sj = *(void **)(adxt + 0x4);
    err2 = 0;
    *(int *)(adxt + 0xA8) = 0;
    if (*(unsigned char *)(adxt + 0x2) < 2 && *(char *)(adxt + 0xAC) == 1) {
        void **obj;

        if (func_00328098(*(void **)(adxt + 0x8)) == 2) {
            return;
        }
        obj = *(void ***)(adxt + 0x10);
        if (obj != 0) {
            void (*fn)(void *) = *(void (**)(void *))((char *)*obj + 0x14);
            fn(obj);
        }
        func_00329C68(adxt, *(int *)(adxt + 0xB4), *(int *)(adxt + 0xB8),
                      *(int *)(adxt + 0xBC), *(int *)(adxt + 0xC0));
        *(char *)(adxt + 0xAC) = 0;
    }
    stat = Obj3260_GetByte_1_D778(sj);
    if (stat == 2) {
        nch = Obj3270_GetVia4_0033CE98_77A0(sj);
        if (*(char *)(adxt + 0x3) < nch) {
            ADXERR_ItoA2(nch, *(char *)(adxt + 0x3), buf, 0x10);
            func_0033F1A8(D_004528C0, buf);
            func_00329EA8(adxt);
            return;
        }
        bufsize = Obj3270_GetVia4_Obj33C8_14_7788(sj);
        hdr = GetVia4_Obj33C8_GetShort_24_327800(sj);
        if (hdr > 0) {
            *(int *)(adxt + 0x48) = (bufsize / *(int *)(adxt + 0x38)) * 3;
        } else {
            *(int *)(adxt + 0x48) = (bufsize / *(int *)(adxt + 0x38)) * 3 / 2;
        }
        unit = Obj3270_GetVia4_Obj33C8_10_77D0(sj) * 2;
        *(int *)(adxt + 0x48) = ((*(int *)(adxt + 0x48) + unit) / unit) * unit;
        StoreArgAndUpdateChildB(sj, *(int *)(adxt + 0x48));
        if (hdr > 0) {
            if (*(char *)(adxt + 0x2) == 2) {
                *(int *)(adxt + 0x50) = 0;
            } else {
                hdrsize = GetVia4_Obj33C8_GetField_34_7878_327878(sj);
                rem = secsize - hdrsize % secsize;
                *(int *)(adxt + 0x50) = rem;
                *(int *)(adxt + 0x50) = rem % secsize;
                nsect = (hdrsize + 0x7FF) / secsize;
                *(int *)(adxt + 0x8C) = nsect;
                func_00328448(*(void **)(adxt + 0x8), nsect);
                func_003283E8(*(void **)(adxt + 0x8), func_0032C1E0, adxt);
            }
            GetVia4_Obj33C8_GetField_30_7860_327860(sj);
            unit = GetVia4_Obj33C8_GetField_28_7818_327818(sj);
            *(int *)(adxt + 0x90) = unit;
            Obj3270_SetField_3C(sj, unit);
            Obj3270_SetField_44(sj, 0);
            Obj3270_SetField_40(sj, 0);
            Obj3270_SetField_48_4C(sj, func_0032BF90, adxt);
        } else {
            if (*(void **)(adxt + 0x8) != 0) {
                func_00328448(*(void **)(adxt + 0x8), 0x7FFFFFFF);
            }
            Obj3270_SetField_3C(sj, Obj3270_GetVia4_Obj33C8_18_77E8(sj));
            Obj3270_SetField_44(sj, 0);
            Obj3270_SetField_40(sj, 0);
            Obj3270_SetField_48_4C(sj, func_0032C310, adxt);
        }
        bufsize = Obj3270_GetVia4_Obj33C8_14_7788(sj);
        nch = Obj3270_GetVia4_0033CE98_77A0(sj);
        sfreq = Obj3270_GetVia4_Obj33C8_18_77E8(sj);
        nbits = Obj3270_GetVia4_0033CEF0_77B8(sj);
        Obj3260_Tramp_00338848_D428(*(void **)(adxt + 0xC), nbits);
        Obj3260_Tramp_00338710_D3C8(*(void **)(adxt + 0xC), bufsize);
        Obj3260_Tramp_003386E0_D3B0(*(void **)(adxt + 0xC), nch);
        Obj3260_NoOp_D490(*(void **)(adxt + 0xC), sfreq);
        func_0032A9F0(adxt, *(short *)(adxt + 0x40));
        func_0032B490(adxt, &err1, &err2);
        if (err1 != 0 || err2 != 0) {
            func_0032B488(adxt, err1, err2);
        }
        func_0032C2A8(adxt);
        if (*(void **)(adxt + 0x74) != 0) {
            func_0033C238(*(void **)(adxt + 0x74), bufsize);
        }
        if (Obj3270_GetVia4_Obj33C8_98_7770(sj) == 2) {
            Obj3260_CallReturn0_003388F8_D498(*(void **)(adxt + 0xC), func_00327968(sj));
        }
        Obj3260_Tramp_003382A0_D320(*(void **)(adxt + 0xC), 1);
        if (D_003D145C != 0) {
            D_003D145C(adxt, bufsize, nch, sfreq);
        }
        *(char *)(adxt + 0x1) = 2;
    } else if (stat == 4) {
        *(char *)(adxt + 0x1) = 6;
    }
}
