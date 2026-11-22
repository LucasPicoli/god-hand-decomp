#include "godhand/globals.h"
extern void func_0033F130(const char *msg);
extern void ADXT_Stop(void *self);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void *func_00338B90(void *src, int mode);
extern void adxt_start_sj(char *self, void *sj);
extern void ADXT_SetLnkSw(char *self, int arg);

#define BSWAP32(x) ((((unsigned int)(x) >> 24) | ((x) << 24)) | ((((x) << 8) & 0xFF0000) | (((x) >> 8) & 0xFF00)))

typedef struct {
    int pad00;
    int count;
    struct {
        int offset;
        int size;
    } ent[1];
} AdxPackHdr;

__attribute__((section(".text.adxt_StartMemIdx")))
void adxt_StartMemIdx(char *self, AdxPackHdr *hdr, int no)
{
    void *sj;

    if (self == 0 || hdr == 0 || no < 0) {
        func_0033F130(D_00452830);
        return;
    }
    ADXT_Stop(self);
    if (no >= (int)BSWAP32(hdr->count) || no < 0) {
        return;
    }
    Forward33B658_33E678();
    sj = func_00338B90((char *)hdr + BSWAP32(((AdxPackHdr *)(no * 8 + (int)hdr))->ent[0].offset), 0x40000000);
    if (sj == 0) {
        Forward33B670_33E690();
        func_0033F130(D_00452860);
        return;
    }
    self[2] = 2;
    adxt_start_sj(self, sj);
    ADXT_SetLnkSw(self, 0);
    Forward33B670_33E690();
}

