/* ee-2.9-991111 */

/* One motion-compensation set of the libmpeg decoder: up to four prediction
 * steps, each a pair of callbacks with their argument blocks, and the buffers
 * the result is added into or copied to. */
typedef struct MpegMcSet {
    int unk00;
    void *residual;                     /* 0x004 */
    char unk08[0x20];
    void (*predA[4])(void *arg);        /* 0x028 */
    void (*predB[4])(void *arg);        /* 0x038 */
    char argA[4][0x1C];                 /* 0x048 */
    char argB[4][0x1C];                 /* 0x0B8 */
    void *dst;                          /* 0x128 */
    int num;                            /* 0x12C prediction steps in use */
    int intra;                          /* 0x130 no prediction: copy the residual */
    int unk134;
    int predict;                        /* 0x138 run the prediction callbacks */
    int skipped;                        /* 0x13C no residual: copy the prediction */
} MpegMcSet;                            /* 0x140 */

/* The part of the libmpeg decoder state _doMC reads. */
typedef struct MpegMcState {
    char unk000[0x5A0];
    MpegMcSet mc[2];                    /* 0x5A0 */
    char unk820[0x10];
    void *pred;                         /* 0x830 prediction buffer */
} MpegMcState;

extern char D_0045E6C8[];               /* error message: intra and skipped both set */

int func_0039C390(int a0, int a1);      /* _sceMpegError */
void func_0039EEA8(void *dst, void *src);
void func_0039EDB8(void *dst, void *pred, void *residual);

/* Run motion compensation for set f: the prediction steps, then the copy or
 * add of residual and prediction into the destination. */
__attribute__((section(".text._doMC")))
void _doMC(MpegMcState *s, int f)
{
    int i;

    if (s->mc[f].predict) {
        for (i = 0; i < s->mc[f].num; i++) {
            s->mc[f].predA[i](s->mc[f].argA[i]);
            s->mc[f].predB[i](s->mc[f].argB[i]);
        }
    }
    if (s->mc[f].intra && s->mc[f].skipped) {
        func_0039C390((int)s, (int)D_0045E6C8);
    }
    if (s->mc[f].intra) {
        func_0039EEA8(s->mc[f].dst, s->mc[f].residual);
    } else if (s->mc[f].skipped) {
        func_0039EEA8(s->mc[f].dst, s->pred);
    } else {
        func_0039EDB8(s->mc[f].dst, s->pred, s->mc[f].residual);
    }
}
