/* cygnus-2.96 matched TU. */

typedef struct {
    int f0, f4, f8, fc, f10, f14, f18;
} SfdAdxtCfg;

extern int ReturnK_003EE2BC_00358A38_358A38(void);

extern void *Obj0000_ReturnD_003EE2C0_34AFE0(void);
extern void func_0032AF40(void *hn, int flag);

__attribute__((section(".text.sfadxt_CreateEx")))
void *sfadxt_CreateEx(SfdAdxtCfg *cfg)
{
    void *hn;

    if (ReturnK_003EE2BC_00358A38_358A38() != 1) {
        hn = func_00329438(cfg->fc, cfg->f18, cfg->f14);
    } else {
        hn = Obj0000_ReturnD_003EE2C0_34AFE0();
    }
    if (hn == 0) return 0;
    func_0032AF40(hn, 0);
    return hn;
}
