/* cygnus-2.96: build a request block for the handle's player, submit it with the block's own
 * two words at 0x44/0x48, then commit through func_0035F698. */
extern void MWSFSFX_CnvFrmInfToSfx(char *h, int a1, char *req);
extern int SFX_Make1PlaneCftDstBuf(void *ply, char *req, int a2, char *rep, int a3, int a4, int a5, int a6);
extern void func_0035F698(void *ply, char *req, char *rep);

__attribute__((section(".text.func_003498E8")))
void func_003498E8(char *h, int a1, int a2)
{
    char req[0xA0];
    char rep[0x70];
    void *ply = *(void **)(h + 0xA8);

    MWSFSFX_CnvFrmInfToSfx(h, a1, req);
    SFX_Make1PlaneCftDstBuf(ply, req, a2, rep, 0, 0, *(int *)(req + 0x44), *(int *)(req + 0x48));
    func_0035F698(ply, req, rep);
}
