#include "godhand/adxInit.h"

/* Register the library's error handler and its two named callbacks, then apply the init record (zeros without one). */
__attribute__((section(".text.ADX_InitHandlers")))
void ADX_InitHandlers(AdxInitCfg *cfg)
{
    func_00330E70(Forward33F130_3292C0, 0);
    func_00330318(D_00451F50, func_00336318, 0);
    func_00330E70(Forward33F130_3292C0, 0);
    func_00330318(D_00451F58, func_00333FA0, 0);
    func_00330580(D_00451F58);
    if (cfg != 0) {
        func_00335218(cfg->mode);
        func_00335248(cfg->fmt);
        if (cfg->flagA == 0)
            Forward331C98_333F60(0);
        else
            Forward331C98_333F60(1);
        if (cfg->flagB == 0) {
            Forward331CE0_333F80(0);
            return;
        }
        Forward331CE0_333F80(1);
        return;
    }
    func_00335218(0);
    func_00335248(0);
    Forward331C98_333F60(0);
    Forward331CE0_333F80(0);
}
