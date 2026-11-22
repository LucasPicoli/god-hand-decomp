/* cygnus-2.96: MWSFSFX_CnvFrmInfToSfx, fills an sfx frame request from a decoded frame: format, picture and
 * timing fields, then hands the frame back. */
typedef struct {
    char pad0[8];
    int fmt; /* 0x08 */
    char padC[0x30 - 0xC];
    int stm; /* 0x30 */
    char pad34[0x88 - 0x34];
    int f88; /* 0x88 */
    int f8C; /* 0x8C */
} MwsfdFrm;
typedef struct {
    int type; /* 0x00 */
    char pad4[0x88 - 0x4];
    int f88; /* 0x88 */
    int f8C; /* 0x8C */
    int f90; /* 0x90 */
    int f94; /* 0x94 */
} SfxReq;
extern int mwsfsfx_CnvFrmFmtTypeToSfx(int fmt);
extern void mwsfsfx_SetYcc420plnInfToSfx(MwsfdFrm *frm, SfxReq *req);
extern int func_00346FA0(MwsfdFrm *frm, SfxReq *req);
extern void mwsfsfx_SetSfxInfTag(char *h, MwsfdFrm *frm, SfxReq *req);
extern void mwsfsfx_SetFrmDetail(char *h, SfxReq *req);
extern int MWSFD_IsColAdjFrame(char *h, MwsfdFrm *frm);
extern int MWSFD_GetFxType(char *h, int stm);
extern void mwsfsfx_DecideCompoMode(char *h, MwsfdFrm *frm);

__attribute__((section(".text.MWSFSFX_CnvFrmInfToSfx")))
void MWSFSFX_CnvFrmInfToSfx(char *h, MwsfdFrm *frm, SfxReq *req)
{
    int f88;
    int f8C;

    req->type = mwsfsfx_CnvFrmFmtTypeToSfx(frm->fmt);
    mwsfsfx_SetYcc420plnInfToSfx(frm, req);
    func_00346FA0(frm, req);
    mwsfsfx_SetSfxInfTag(h, frm, req);
    mwsfsfx_SetFrmDetail(h, req);
    f88 = frm->f88;
    f8C = frm->f8C;
    req->f88 = f88;
    req->f8C = f8C;
    req->f90 = MWSFD_IsColAdjFrame(h, frm);
    req->f94 = MWSFD_GetFxType(h, frm->stm);
    mwsfsfx_DecideCompoMode(h, frm);
}
