#include "godhand/globals.h"
extern void ADXT_DestroyAll(void);
extern void Obj3260_Tramp_00337D20_D2A0(void);
extern void func_0033F4C8(void);
extern void ADXSTM_Finish(void);
extern void LSC_Finish(void);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void SVM_DelCbSvr(int a0, int a1);
extern void SVM_Finish(void);
extern void ADXSJD_Finish(void);
extern void func_0033F0F0(void);
extern void SJMEM_Finish(void);
extern void SJRBF_Finish(void);
extern void SJUNI_Finish(void);
extern void ADXCRS_Finish(void);
extern void SVM_CallErr1(void *p);
extern void ADXT_Destroy(char *p);
extern char D_003C7420[];

__attribute__((section(".text.ADXT_Finish")))
void ADXT_Finish(void)
{
    int i;
    char *p;

    if (--D_003C7400 == 0) {
        D_003D84AC = 0;
        ADXT_DestroyAll();
        Obj3260_Tramp_00337D20_D2A0();
        func_0033F4C8();
        ADXSTM_Finish();
        LSC_Finish();
        Forward33B658_33E678();
        SVM_DelCbSvr(2, 1);
        SVM_DelCbSvr(4, D_003C7414);
        SVM_DelCbSvr(5, D_003C7408);
        SVM_Finish();
        ADXSJD_Finish();
        func_0033F0F0();
        SJMEM_Finish();
        SJRBF_Finish();
        SJUNI_Finish();
        Forward33B670_33E690();
        ADXCRS_Finish();
        D_003D84AC = 1;
        for (i = 0; i < 16; i++) {
            p = D_003C7420 + i * 0xC8;
            if (*p != 0) {
                SVM_CallErr1(D_00451B48);
                ADXT_Destroy(p);
            }
        }
    }
}
