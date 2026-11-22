/* cygnus-2.96: read the first sectors of a file into buf; host paths go to the host reader, disc paths
 * are searched and read through libcdvd with progress codes in the history ring. */
#include "godhand/globals.h"
typedef struct CdlFile {
    unsigned int lsn;                   /* 0x00 */
    unsigned int size;                  /* 0x04 */
    char name[16];                      /* 0x08 */
    unsigned char date[8];              /* 0x18 */
    unsigned int flag;                  /* 0x20 */
} CdlFile;                         /* 0x24 */

typedef struct CdRMode {
    unsigned char trycount;             /* 0x0 */
    unsigned char spindlctrl;           /* 0x1 */
    unsigned char datapattern;          /* 0x2 */
    unsigned char pad;                  /* 0x3 */
} CdRMode;

typedef struct DrvName {
    char c[5];
} DrvName;

extern int strcasecmp(const char *a, const char *b);
extern int htci_load_flist(char *path, void *buf);
extern void *func_003A52F0(void *dst, int c, int n);
extern void func_00333390(char *path, char *out);
extern void PushGlobalD8478History_331C78(int code);
extern int func_00398DA0(int mode);
extern int dvCiCdSearchFile(CdlFile *file, char *name);
extern int sceCdRead(unsigned int lsn, unsigned int sectors, void *buf, CdRMode *mode);

__attribute__((section(".text.load_flist")))
int load_flist(char *path, void *buf)
{
    CdlFile file;
    CdRMode mode;
    char drv[5];

    *(DrvName *)drv = *(DrvName *)path;
    drv[4] = 0;
    if (strcasecmp(drv, D_004544F0) == 0)
        return htci_load_flist(path + 4, buf);
    func_003A52F0(D_003D9EE8, 0, 0x80);
    func_00333390(path, D_003D9EE8);
    PushGlobalD8478History_331C78(0x9000);
    while (func_00398DA0(1) == 1)
        ;
    PushGlobalD8478History_331C78(0x9001);
    PushGlobalD8478History_331C78(0x9100);
    if (dvCiCdSearchFile(&file, D_003D9EE8) == 0) {
        PushGlobalD8478History_331C78(0x9101);
        return 0;
    }
    PushGlobalD8478History_331C78(0x9102);
    mode.trycount = 0;
    mode.spindlctrl = 1;
    mode.datapattern = 0;
    mode.pad = 0;
    PushGlobalD8478History_331C78(0x9200);
    if (sceCdRead(file.lsn, 2, buf, &mode) == 0) {
        PushGlobalD8478History_331C78(0x9201);
        return 0;
    }
    PushGlobalD8478History_331C78(0x9202);
    PushGlobalD8478History_331C78(0x9300);
    while (func_00398DA0(1) == 1)
        ;
    PushGlobalD8478History_331C78(0x9301);
    return 1;
}
