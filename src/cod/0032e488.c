/* cygnus-2.96: stream frame step: advance the current frame (by callback or by one), wrap at the loop
 * end, and when looping reprogram the reader range for the new frame. */
typedef struct StmFrameHn {
    char pad000;
    signed char stat;                   /* 0x001 */
    char pad002[2];
    void *src;                          /* 0x004 */
    void *rd;                           /* 0x008 */
    char pad00C[0x1AC - 0xC];
    int mode;                           /* 0x1AC */
    signed char loop;                   /* 0x1B0 */
    signed char seek;                   /* 0x1B1 */
    char pad1B2[0x1BC - 0x1B2];
    int frame;                          /* 0x1BC */
    char pad1C0[4];
    int loopStart;                      /* 0x1C4 */
    int loopEnd;                        /* 0x1C8 */
    char pad1CC[0x270 - 0x1CC];
    int (*nextFn)(void *obj, int frame, int last); /* 0x270 */
    void *nextObj;                      /* 0x274 */
} StmFrameHn;

extern int func_0032F4F0(void *src);
extern int func_0032F570(void *src);
extern void AIXSJD_GetPhMediaInf(void *src, int frame, int *ofs, int *len);
extern void func_003280D8(void *rd, int sct);
extern void ADXSTM_SetEos(void *rd, int sct);
extern void func_003281C8(void *rd);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern void Obj33F8_Tramp_0033B670_FC88(void);

__attribute__((section(".text.aixp_entry_eos_cb")))
void aixp_entry_eos_cb(StmFrameHn *s)
{
    int frame;
    int kind;
    int ofs;
    int len;

    if (s->mode != 1 && s->stat != 2)
        return;
    if (s->nextFn != 0) {
        s->frame = s->nextFn(s->nextObj, s->frame, func_0032F4F0(s->src) - 1);
        if (s->frame < 0) {
            s->loop = 0;
            s->seek = 0;
        }
    } else {
        s->frame++;
    }
    if (s->loop == 1 && s->frame >= s->loopEnd)
        s->frame = s->loopStart;
    if (s->seek != 1)
        return;
    if (s->frame >= func_0032F4F0(s->src))
        return;
    Obj33F8_Tramp_0033B658_FC70();
    frame = s->frame;
    kind = func_0032F570(s->src);
    switch (kind) {
    case 0:
        AIXSJD_GetPhMediaInf(s->src, frame, &ofs, &len);
        func_003280D8(s->rd, ofs / 2048);
        ADXSTM_SetEos(s->rd, (ofs + len) / 2048);
        func_003281C8(s->rd);
        break;
    case 1:
        func_003280D8(s->rd, 0);
        ADXSTM_SetEos(s->rd, -1);
        func_003281C8(s->rd);
        break;
    }
    Obj33F8_Tramp_0033B670_FC88();
}
