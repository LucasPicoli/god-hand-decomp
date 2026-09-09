/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct {
    unsigned int addr;
    int size;
} SjBlk;

typedef struct SfMps SfMps;

typedef struct {
    unsigned char pad0[0x24];
    int (*GetSjSize)(SfMps *mps, int ch);
} SjIf;

struct SfMps {
    SjIf *vt;
};

extern int sfmps_ExecCopySj(SfMps *mps, void *dst, int len);
extern int D_003EE2E8;

__attribute__((section(".text.sfmps_CopySj")))
int sfmps_CopySj(SfMps *mps, void *dst, int len)
{
    int n;

    if (mps->vt->GetSjSize(mps, 0) < len)
        return 0;
    n = sfmps_ExecCopySj(mps, dst, len);
    if (n == 0)
        return 0;
    len -= n;
    dst = (char *) dst + n;
    if (len > 0) {
        if (sfmps_ExecCopySj(mps, dst, len) != len)
            D_003EE2E8++;
    }
    return 1;
}
