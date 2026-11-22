/* cygnus-2.96: sfxcnv_ExecCnvFrmByCbFunc, builds a frame info block and the (time, rate) pair for a frame and passes
 * them to the handle's frame callback. */
typedef struct {
    int time; /* 0x00 */
    int rate; /* 0x04 */
    int pad8[6];
} FrmTim;
typedef struct Sfx Sfx;
struct Sfx {
    char pad0[0x38];
    int time; /* 0x38 */
    char pad3C[0x50 - 0x3C];
    int rate; /* 0x50 */
    char pad54[0x68 - 0x54];
    void (*cbfn)(char *inf, void *frm, FrmTim *tim); /* 0x68 */
};
extern void *func_003A52F0(void *d, int c, unsigned int n);
extern void sfxcnv_MakeCftSrcBuf(Sfx *sfx, void *src, char *inf);
extern int func_0035FD78(Sfx *sfx);
extern void Obj35E8_StepCounter_EA60(void *frm);

__attribute__((section(".text.sfxcnv_ExecCnvFrmByCbFunc")))
void sfxcnv_ExecCnvFrmByCbFunc(Sfx *sfx, void *src, void *frm, int intime)
{
    char inf[0x64];
    FrmTim tim;

    func_003A52F0(inf, 0, sizeof(inf));
    sfxcnv_MakeCftSrcBuf(sfx, src, inf);
    tim.time = (intime == 1) ? sfx->time : 0;
    tim.rate = sfx->rate;
    if (func_0035FD78(sfx) == 1)
        Obj35E8_StepCounter_EA60(frm);
    if (sfx->cbfn != 0)
        sfx->cbfn(inf, frm, &tim);
}
