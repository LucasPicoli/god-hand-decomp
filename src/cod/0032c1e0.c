/* cygnus-2.96: Sofdec stream setup (0x32BE10) and stream feed (0x32C1E0). */

extern int ADXSJD_GetLpStartOfst(void *sj);
extern int Obj3270_GetField_30(void *sj);
extern void Obj3270_SetField_3C(void *sj, int v);
extern void ADXSTM_SetEos(void *sj, int len);
extern int func_003280D8(void *sj, int sectors);

__attribute__((section(".text.adxt_eos_entry")))
void adxt_eos_entry(char *self)
{
    void *in;
    void *out;
    int n;

    out = *(void **)(self + 8);
    in = *(void **)(self + 4);
    if (out == 0 || in == 0) {
        return;
    }
    n = ADXSJD_GetLpStartOfst(in);
    if (*(signed char *)(self + 2) == 4) {
        ADXSTM_SetEos(*(void **)(self + 8), 0x7FFFFFFF);
    } else if (*(signed char *)(self + 0x6C) == 0) {
        if (Obj3270_GetField_30(*(void **)(self + 4)) >= *(int *)(self + 0xC4)) {
            Obj3270_SetField_3C(*(void **)(self + 4), -1);
        }
        ADXSTM_SetEos(*(void **)(self + 8), 0x7FFFFFFF);
    } else {
        func_003280D8(out, n / 2048);
    }
}

