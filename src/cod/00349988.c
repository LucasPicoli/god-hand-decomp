/* cygnus-2.96: build a request block for the handle's player, submit it, then commit with the reply buffer. */
extern void MWSFSFX_CnvFrmInfToSfx(char *h, int a1, char *req);
extern int SFX_Make1PlaneCftDstBuf(void *ply, char *req, int a2, char *rep, int a3, int a4, int a5, int a6);
extern int func_0035F788(void *ply, char *req, char *rep);

__attribute__((section(".text.func_00349988")))
void func_00349988(char *h, int a1, int a2, int a3, int a4, int a5, int a6)
{
    char req[0xA0];
    char rep[0x70];
    void *ply = *(void **)(h + 0xA8);

    MWSFSFX_CnvFrmInfToSfx(h, a1, req);
    SFX_Make1PlaneCftDstBuf(ply, req, a2, rep, a3, a4, a5, a6);
    func_0035F788(ply, req, rep);
}
