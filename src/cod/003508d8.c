/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct SfMpv SfMpv;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} SfPrep;

extern int func_0034CA30(SfMpv *p, int id);           /* SFBUF_GetPrepFlg */
extern void func_0034CA00(SfMpv *p, int id, int v);   /* SFBUF_SetPrepFlg */
extern int sfmpv_IsPrepEnd(SfMpv *p);
extern void Obj0000_Set_Field_E48_If_Field_E6C_NE_MAX(SfMpv *p);   /* sfmpv_FixedStartTtu */

__attribute__((section(".text.func_003508D8")))
void func_003508D8(SfMpv *p)
{
    SfPrep *b = (SfPrep *) ((char *) p + 0x1FB8);
    int f14 = b->f14;
    int f10 = b->f10;

    if (func_0034CA30(p, f14) == 1)
        return;
    if (func_0034CA30(p, f10) != 1)
        return;
    if (sfmpv_IsPrepEnd(p) == 0)
        return;
    func_0034CA00(p, f14, 1);
    Obj0000_Set_Field_E48_If_Field_E6C_NE_MAX(p);
}
