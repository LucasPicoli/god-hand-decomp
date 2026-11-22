/* cygnus-2.96: open a file handle on dev: look the file up, read its size from the disc when unknown,
 * and reset the read state. */
#include "godhand/globals.h"
#define SECTOR_SHIFT  11
#define SECTOR_MASK   0x7FF

typedef struct CdFileInfo {
    int unk0;
    unsigned int size;                  /* 0x04 */
} CdFileInfo;

typedef struct CdFileHn {
    char used;                          /* 0x00 */
    char sized;                         /* 0x01 the size came with the lookup */
    char unk02;                         /* 0x02 */
    char pad03;
    unsigned int size;                  /* 0x04 */
    unsigned int sectors;               /* 0x08 */
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    CdFileInfo info;                /* 0x20 */
} CdFileHn;

extern void func_00332808(void *dev, char *msg);
extern CdFileHn *dvci_alloc(void);
extern int dvci_get_fstate(void *dev, CdFileInfo *info);
extern void func_00333390(void *dev, char *name);
extern void func_003260C8(const char *fmt, ...);
extern void PushGlobalD8478History_331C78(int tag);
extern int func_00398DA0(int mode);
extern int dvCiCdSearchFile(CdFileInfo *info, char *name);
extern void Forward3A52F0_332BE0(CdFileHn *f);

__attribute__((section(".text.func_00332C00")))
CdFileHn *func_00332C00(void *dev, void *arg, int mode)
{
    CdFileHn *f;
    int kind;
    unsigned int size;

    if (dev == 0) {
        func_00332808(dev, D_00454380);
        return 0;
    }
    if (mode != 0) {
        func_00332808(0, D_004543A8);
        return 0;
    }
    f = dvci_alloc();
    if (f == 0) {
        func_00332808(0, D_004543D0);
        return 0;
    }
    kind = dvci_get_fstate(dev, &f->info);
    if (f->info.size == 0) {
        func_00333390(dev, D_003D9C90);
        func_003260C8(D_00454400, D_003D9C90);
        PushGlobalD8478History_331C78(0x8300);
        func_00398DA0(0);
        PushGlobalD8478History_331C78(0x8301);
        if (dvCiCdSearchFile(&f->info, D_003D9C90) == 0) {
            func_00332808(0, D_00454428);
            Forward3A52F0_332BE0(f);
            return 0;
        }
        f->sized = 0;
    } else {
        f->sized = 1;
    }
    size = f->info.size;
    f->sectors = (size + SECTOR_MASK) >> SECTOR_SHIFT;
    f->used = 1;
    f->size = size;
    f->unk0C = 0;
    f->unk18 = 0;
    f->unk10 = 0;
    f->unk14 = 0;
    f->unk02 = 0;
    f->unk1C = 0;
    if (kind == 1)
        f->sectors = 0x7FFFFFFF;
    return f;
}
