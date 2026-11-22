#include "godhand/globals.h"
extern void func_0033F130(const char *msg);
extern void func_00329EA8(void *self);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void *func_00338B90(void *src, int mode);
extern void func_00329B60(char *self, void *sj);
extern void func_0032B660(char *self, int arg);

#define BSWAP32(x) ((((unsigned int)(x) >> 24) | ((x) << 24)) | ((((x) << 8) & 0xFF0000) | (((x) >> 8) & 0xFF00)))

typedef struct {
    int pad00;
    int count;
    struct {
        int offset;
        int size;
    } ent[1];
} AdxPackHdr;

__attribute__((section(".text.func_0032BE10")))
void func_0032BE10(char *self, AdxPackHdr *hdr, int no)
{
    void *sj;

    if (self == 0 || hdr == 0 || no < 0) {
        func_0033F130(D_00452830);
        return;
    }
    func_00329EA8(self);
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
    func_00329B60(self, sj);
    func_0032B660(self, 0);
    Forward33B670_33E690();
}

