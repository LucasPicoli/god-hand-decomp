/* cygnus-2.96 matched TU. */

extern void *GetArrayElemA0C_35A1C8(void *h, int n);
extern void func_0035C2D0(void *h, int a, int b, int c, int d);
extern int Obj34D8_SetGlobalEE0B8_IfField48(void *h);
extern void func_0035A260(void *h, int a, void *b);

__attribute__((section(".text.SFAOAP_Start")))
void SFAOAP_Start(void *h)
{
    if (GetArrayElemA0C_35A1C8(h, 6) != 0) {
        func_0035C2D0(h, 3, 6, 0, 0);
        do { } while (0);
    }
}

__attribute__((section(".text.SFAOAP_Stop")))
void SFAOAP_Stop(void *h)
{
    if (GetArrayElemA0C_35A1C8(h, 6) != 0) {
        func_0035C2D0(h, 3, 7, 0, 0);
        do { } while (0);
    }
}

__attribute__((section(".text.SFCON_IsEndcodeSkip")))
int SFCON_IsEndcodeSkip(void *h)
{
    return GetArrayElemA0C_35A1C8(h, 0x31) != 0;
}

__attribute__((section(".text.SFD_GetTrHn")))
int SFD_GetTrHn(void *h, int a, void *b)
{
    if (Obj34D8_SetGlobalEE0B8_IfField48(h) != 0) {
        return func_0034DD70(0, 0xFF000117);
    }
    func_0035A260(h, a, b);
    return 0;
}
