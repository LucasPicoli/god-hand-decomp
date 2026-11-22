/* cygnus-2.96: Sofdec handle, enable or disable the user callback (0x35AF68). */
extern int Obj34D8_SetGlobalEE0B8_IfField48(char *h);
extern int func_0034DD70(int a0, int err);
extern void SFSET_SetCond(char *h, int a1, int a2);

__attribute__((section(".text.SFD_SetExtClockFn")))
int SFD_SetExtClockFn(char *h, int func, int obj, int arg)
{
    char *cb;

    if (Obj34D8_SetGlobalEE0B8_IfField48(h) != 0) {
        return func_0034DD70(0, 0xFF000129);
    }
    cb = h + 0xD30;
    if (func != 0) {
        *(int *)(cb + 0x2D4) = func;
        *(int *)(cb + 0x2E4) = obj;
        *(int *)(cb + 0x2E8) = arg;
        SFSET_SetCond(h, 0xF, 5);
        SFSET_SetCond(h, 0x47, 0);
    } else {
        SFSET_SetCond(h, 0x47, 1);
        SFSET_SetCond(h, 0xF, 1);
        *(int *)(cb + 0x2E8) = arg;
        *(int *)(cb + 0x2E4) = obj;
        *(int *)(cb + 0x2D4) = 0;
    }
    return 0;
}
