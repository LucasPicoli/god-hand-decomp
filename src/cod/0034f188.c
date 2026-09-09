/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct {
    unsigned int addr;
    int size;
} SjBlk;

typedef struct SfMps SfMps;

typedef struct {
    unsigned char pad0[0x18];
    void (*GetSj)(SfMps *mps, int ch, int len, SjBlk *blk);
    unsigned char pad1C[4];
    void (*PutSj)(SfMps *mps, int ch, SjBlk *blk);
    int (*GetSjSize)(SfMps *mps, int ch);
} SjIf;

struct SfMps {
    SjIf *vt;
};

extern void func_00366960(void *src, void *dst, int size);   /* MEM_Copy */

__attribute__((section(".text.sfmps_ExecCopySj")))
int sfmps_ExecCopySj(SfMps *mps, void *dst, int len)
{
    SjBlk blk;

    mps->vt->GetSj(mps, 0, len, &blk);
    func_00366960((void *) blk.addr, dst, blk.size);
    mps->vt->PutSj(mps, 1, &blk);
    return blk.size;
}
