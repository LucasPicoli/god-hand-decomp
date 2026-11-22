/* cygnus-2.96: open a file handle on dev: look the file up, open it, read its size when unknown, and
 * reset the read state. */
#include "godhand/globals.h"
#define SECTOR_SHIFT  11
#define SECTOR_MASK   0x7FF

typedef struct HostFileInfo {
    int fd;                             /* 0x00 */
    int size;                           /* 0x04 */
} HostFileInfo;

typedef union HostFileStat {
    long all;
    HostFileInfo f;
} HostFileStat;

typedef struct HostFileHn {
    char used;                          /* 0x00 */
    char sized;                         /* 0x01 the size came with the lookup */
    char unk02;                         /* 0x02 */
    char pad03[5];
    long size;                          /* 0x08 */
    int sectors;                        /* 0x10 */
    int unk14;
    int fd;                             /* 0x18 */
    int unk1C;
    int unk20;
    int unk24;
} HostFileHn;

extern char D_003DA250[];

extern void func_00334008(void *dev, char *msg);
extern HostFileHn *func_003344C8(void);
extern void func_003351C0(void *dev, HostFileInfo *info);
extern void func_00334D68(void *dev, char *name);
extern void LogPrintf(char *fmt, ...);
extern long func_00334310(void *dev);
extern void PushGlobalD8478History_331C78(int tag);
extern int func_00331EE8(char *name, int mode);
extern void Forward3A52F0_334500(HostFileHn *f);

__attribute__((section(".text.func_00334520")))
HostFileHn *func_00334520(void *dev, void *arg, int mode)
{
    HostFileHn *f;
    HostFileStat info;

    info.all = 0;
    if (dev == 0) {
        func_00334008(dev, D_00454878);
        return 0;
    }
    if (mode != 0) {
        func_00334008(0, D_004548A0);
        return 0;
    }
    f = func_003344C8();
    if (f == 0) {
        func_00334008(0, D_004548C8);
        return 0;
    }
    func_003351C0(dev, &info.f);
    if (info.f.size == 0) {
        func_00334D68(dev, D_003DA250);
        LogPrintf(D_004548F8, dev);
        f->size = func_00334310(dev);
        if (f->size == 0)
            return 0;
        PushGlobalD8478History_331C78(0x4900);
        f->fd = func_00331EE8(D_003DA250, D_003DA390);
        PushGlobalD8478History_331C78(0x4901);
        if (f->fd < 0) {
            func_00334008(0, D_00454920);
            Forward3A52F0_334500(f);
            return 0;
        }
        f->sized = 0;
    } else {
        f->sized = 1;
        f->fd = info.f.fd;
        f->size = info.f.size;
    }
    f->unk1C = 0;
    f->unk20 = 0;
    f->unk24 = 0;
    f->sectors = (f->size + SECTOR_MASK) >> SECTOR_SHIFT;
    f->unk14 = 0;
    f->unk02 = 0;
    f->used = 1;
    return f;
}
