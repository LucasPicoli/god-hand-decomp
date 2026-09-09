/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct SfMpv SfMpv;

extern int GetArrayElemA0C_35A1C8(SfMpv *p, int idx);

extern void func_003502D8(SfMpv *p, int n, int cond);

__attribute__((section(".text.sfmpv_SetCondY16")))
void sfmpv_SetCondY16(SfMpv *p)
{
    int r;
    int cond;

    if (GetArrayElemA0C_35A1C8(p, 0x1C) == 0) return;
    r = func_0034DB20(p);
    cond = 1;
    if (r != 0) {
        if (r <= 0) {
            if (r == -1) return;
        }
        cond = 0;
    }
    func_003502D8(p, 5, cond);
}
