/* cygnus-2.96: AC3LINK_ExecOneAc3, per-frame stream decoder step: start it in state 1, then track the
 * decoded sample count in state 2 until the decoder reports done (3). */
typedef struct SndStream {
    char unk00[4];
    int state;                  /* 0x04 */
    char unk08[0x10];
    int total;                  /* 0x18 */
    char unk1C[0x6C];
    int played;                 /* 0x88 */
    char unk8C[4];
    int delta;                  /* 0x90 */
    int pos;                    /* 0x94 */
    char unk98[0x28];
    int dec;                    /* 0xC0 */
} SndStream;

extern int func_003BA800(int dec);
extern void AC3CNV_Stop(int dec);
extern void AC3CNV_Start(int dec);
extern void AC3CNV_ExecHndl(int dec);
extern void AC3CNV_GetNumByteCnv(int dec, int *pos, int *bytes);

__attribute__((section(".text.AC3LINK_ExecOneAc3")))
void AC3LINK_ExecOneAc3(SndStream *s)
{
    int dec = s->dec;
    int pos, bytes;

    if (func_003BA800(dec) == 0) {
        s->played = 0;
        AC3CNV_Stop(dec);
    }
    if (s->state == 1) {
        s->played = 0;
        AC3CNV_Start(dec);
        s->state = 2;
    } else if (s->state == 2) {
        AC3CNV_ExecHndl(dec);
        AC3CNV_GetNumByteCnv(dec, &pos, &bytes);
        s->pos = pos;
        s->delta = bytes / 4 - s->played;
        s->played += s->delta;
        if (func_003BA800(dec) == 3) {
            AC3CNV_Stop(dec);
            s->state = 0;
            s->total = bytes / 4;
        }
    }
}
