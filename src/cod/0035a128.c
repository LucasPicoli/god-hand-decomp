/* cygnus-2.96 matched TU. */

extern int D_003EE0C0[];
extern int Obj34D8_SetGlobalEE0B8_IfField48(void *hn);

extern int GetArrayElemA0C_35A1C8(void *hn, int id);

__attribute__((section(".text.SFD_GetCond")))
int SFD_GetCond(void *hn, int id, int *out)
{
    if (!hn) {
        *out = D_003EE0C0[id];
    } else if (Obj34D8_SetGlobalEE0B8_IfField48(hn)) {
        return func_0034DD70(0, 0xFF000113U);
    } else {
        *out = GetArrayElemA0C_35A1C8(hn, id);
    }
    return 0;
}
