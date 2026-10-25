/* cygnus-2.96 matched TU. */

extern int Obj33F8_Tramp_0033B658_FC70(void *a0);
extern void SndSlide_start(void *a0);
extern int Obj33F8_Tramp_0033B670_FC88(void);

__attribute__((section(".text.func_0032DE38")))
int func_0032DE38(void *a0, float f12) {
    *(float*)((char*)a0+0x1E4) = f12;
    Obj33F8_Tramp_0033B658_FC70(a0);
    if (func_0032DC90(a0) == 2) {
        SndSlide_start(a0);
    }
    return Obj33F8_Tramp_0033B670_FC88();
}
