typedef struct SfdTcSub {
    char pad00[0x70];
    int *cur;
} SfdTcSub;

typedef struct SfdTcCtx {
    char pad0000[0x58];
    int mode;
    char pad005C[0x1FC0 - 0x5C];
    SfdTcSub *sub;
} SfdTcCtx;

extern int *SFMPVF_SearchFrmObjFromId(SfdTcCtx *ctx, int key);
extern int *SFMPVF_SearchVfrmData(SfdTcCtx *ctx, int *ent);
extern int *func_00355258(SfdTcCtx *ctx, int id);
extern int *SFMPVF_SearchFrmObj(SfdTcCtx *ctx, int id);
extern void SFMPVF_EndDrawFrm(int *ent);
extern int func_0034DD70(SfdTcCtx *ctx, int err);

__attribute__((section(".text.sfmpv_AddReadSub")))
int sfmpv_AddReadSub(SfdTcCtx *ctx, int id, int key)
{
    SfdTcSub *sub = ctx->sub;
    int *ent;
    int *st;

    if (ctx->mode == 2) {
        ent = SFMPVF_SearchFrmObjFromId(ctx, key);
        if (ent == 0) {
            return func_0034DD70(ctx, 0xFF000F1F);
        }
        st = SFMPVF_SearchVfrmData(ctx, ent);
    } else {
        st = func_00355258(ctx, id);
        if (*st != 1) {
            return func_0034DD70(ctx, 0xFF000F0E);
        }
        ent = SFMPVF_SearchFrmObj(ctx, id);
        if (sub->cur != ent) {
            return func_0034DD70(ctx, 0xFF000F0F);
        }
    }
    *st = 0;
    SFMPVF_EndDrawFrm(ent);
    return 0;
}
