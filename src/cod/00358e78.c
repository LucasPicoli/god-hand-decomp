/* cygnus-2.96 matched TU. */

extern int Obj34D8_SetGlobalEE0B8_IfField48(void *hn);
extern void func_0034DD70(void *a0, unsigned int err);
extern void func_0035C2D0(void *hn, int a1, int a2, void *a3, int a4);

__attribute__((section(".text.SFD_GetWritePtr")))
void SFD_GetWritePtr(void *hn, void *p)
{
    if (Obj34D8_SetGlobalEE0B8_IfField48(hn) != 0) {
        func_0034DD70(0, 0xFF000134);
        return;
    }
    func_0035C2D0(hn, 0, 9, p, 0);
}
