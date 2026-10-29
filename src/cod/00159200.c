/* sn-2.95.3-136 matched TU. */

/* Sample a keyframe track at time t: the track's frames are 16-bit values scaled by a track scale and added to a track base; between two frames blend with the fraction of t, past the last frame return the last one. Contexts whose type nibble (bits 8 to 11) is 3, 4 or 5 blend with Ang_mult_late instead. */
typedef struct KeyHead {
    char unk00[4];
    unsigned short num;                 /* 0x04 frames in a track */
} KeyHead;

typedef struct KeyCtx {
    unsigned int flags;                 /* 0x00 bits 8 to 11: blend type */
    char unk04[4];
    int trackOfs;                       /* 0x08 offset of the track from the head */
} KeyCtx;

typedef struct KeyTrack {
    float base;                         /* 0x00 added to every frame */
    float scale;                        /* 0x04 */
    unsigned short frame[1];            /* 0x08 */
} KeyTrack;

#define KEY_TYPE_MASK   0xF00
#define KEY_TYPE_3      0x300
#define KEY_TYPE_4      0x400
#define KEY_TYPE_5      0x500

extern float Ang_mult_late(float hi, float lo, float frac);

__attribute__((section(".text.KeyTrack_sample")))
float KeyTrack_sample(KeyHead *head, KeyCtx *ctx, float t)
{
    int idx = (int)t;
    KeyTrack *trk = (KeyTrack *)((char *)head + ctx->trackOfs);
    unsigned short *fr = trk->frame;
    float hi;
    float lo;
    float frac;
    unsigned int type;
    unsigned int num = head->num;

    if (idx >= (int)num - 1)
        return (float)*(fr + num - 1) * trk->scale + trk->base;
    frac = t - (float)idx;
    lo = (float)*(fr + idx) * trk->scale + trk->base;
    hi = (float)*(fr + idx + 1) * trk->scale + trk->base;
    type = ctx->flags & KEY_TYPE_MASK;
    if (type == KEY_TYPE_3 || type == KEY_TYPE_4 || type == KEY_TYPE_5)
        return Ang_mult_late(hi, lo, frac);
    return lo * (1.0f - frac) + hi * frac;
}
