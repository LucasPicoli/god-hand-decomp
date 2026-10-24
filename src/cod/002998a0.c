/* sn-2.95.3-136 */

/* One A+D packet entry holding a pair of floats, for the ST register. */
typedef struct GsAdFloat {
    float s;                            /* 0x0 */
    float t;                            /* 0x4 */
    long addr;                          /* 0x8 GS register number */
} GsAdFloat;

/* The packet build buffer: entries go at cur, num counts them. */
typedef struct GsPktCtx {
    char buf[0x10000];
    GsAdFloat *cur;                     /* 0x10000 */
    char unk10004[0xC];
    int num;                            /* 0x10010 */
} GsPktCtx;

/* Store the S and T pair of an entry. */
static __inline__ void GsAdFloat_setST(GsAdFloat *e, float s, float t)
{
    e->s = s;
    e->t = t;
}

/* Append an A+D entry that writes s and t to GS register addr. */
__attribute__((section(".text.func_002998A0")))
void func_002998A0(GsPktCtx *ctx, long addr, float s, float t)
{
    GsAdFloat_setST(ctx->cur, s, t);
    ctx->cur->addr = addr;
    ctx->cur++;
    ctx->num++;
}
