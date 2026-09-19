/* ee-2.9-991111 matched TU. */

extern void func_003B63A0(void);
extern int EIntr(void);
extern int EnableDmac(int cause);
extern void _sceSDC(unsigned int start, unsigned int end);
extern void _sceIDC(unsigned int start, unsigned int end);
extern char D_007816E8[];
extern char D_003FAE30[];
extern char *D_003FAEF0;
extern char D_00781BA8[];
extern char *D_003FAEFC;

/* ee-2.9-991111; libkernl intr.o wrapper around the EnableDmac syscall stub. */

#include "godhand/sync.h"





__attribute__((section(".text.func_003B0810")))
int func_003B0810(int cause)
{
    unsigned int stat;
    int r;

    GH_MFC0_STATUS(stat);
    stat &= 0x10000;
    if (stat) {
        func_003B63A0();
    }
    r = EnableDmac(cause);
    GH_SYNC();
    if (stat) {
        EIntr();
    }
    return r;
}

/* ee-2.9-991111; libkernl cache.o. */

#include "godhand/sync.h"





__attribute__((section(".text.SyncDCache")))
void SyncDCache(void *start, void *end)
{
    unsigned int stat;

    GH_MFC0_STATUS(stat);
    stat &= 0x10000;
    if (stat) {
        func_003B63A0();
    }
    _sceSDC((unsigned int)start & 0xFFFFFFC0, (unsigned int)end & 0xFFFFFFC0);
    if (stat) {
        EIntr();
    }
}

/* ee-2.9-991111; libkernl cache.o. */

#include "godhand/sync.h"





__attribute__((section(".text.func_003B0640")))
void func_003B0640(void *start, void *end)
{
    unsigned int stat;

    GH_MFC0_STATUS(stat);
    stat &= 0x10000;
    if (stat) {
        func_003B63A0();
    }
    _sceIDC((unsigned int)start & 0xFFFFFFC0, (unsigned int)end & 0xFFFFFFC0);
    if (stat) {
        EIntr();
    }
}

/* ee-2.9-991111; libkernl filestub.o / eeloadfile.o version handshake. */






__attribute__((section(".text.func_003B4158")))
int func_003B4158(void)
{
    int r;
    const char *ver;
    char *info;

    r = 0;
    ver = &D_003FAE30[0xC];
    info = D_007816E8;
    if (func_003A50B4(info, ver, 4) != 0) {
        if (func_003A50B4(info, D_003FAEF0, 4) != 0) {
            r = func_003A50B4(ver, D_003FAEF0, 4) != 0;
        }
    }
    return r;
}

/* ee-2.9-991111; libkernl filestub.o / eeloadfile.o version handshake. */






__attribute__((section(".text.func_003B5B80")))
int func_003B5B80(void)
{
    int r;
    const char *ver;
    char *info;

    r = 0;
    ver = &D_003FAE30[0xC];
    info = D_00781BA8;
    if (func_003A50B4(info, ver, 4) != 0) {
        if (func_003A50B4(info, D_003FAEFC, 4) != 0) {
            r = func_003A50B4(ver, D_003FAEFC, 4) != 0;
        }
    }
    return r;
}
