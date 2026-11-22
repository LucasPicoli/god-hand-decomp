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

extern int SFBUF_GetPrepFlg(SfMpv *p, int id);           /* SFBUF_GetPrepFlg */
extern void SFBUF_SetPrepFlg(SfMpv *p, int id, int v);   /* SFBUF_SetPrepFlg */
extern int sfmpv_IsPrepEnd(SfMpv *p);
extern void Obj0000_Set_Field_E48_If_Field_E6C_NE_MAX(SfMpv *p);   /* sfmpv_FixedStartTtu */

__attribute__((section(".text.sfmpv_ChkPrepFlg")))
void sfmpv_ChkPrepFlg(SfMpv *p)
{
    SfPrep *b = (SfPrep *) ((char *) p + 0x1FB8);
    int f14 = b->f14;
    int f10 = b->f10;

    if (SFBUF_GetPrepFlg(p, f14) == 1)
        return;
    if (SFBUF_GetPrepFlg(p, f10) != 1)
        return;
    if (sfmpv_IsPrepEnd(p) == 0)
        return;
    SFBUF_SetPrepFlg(p, f14, 1);
    Obj0000_Set_Field_E48_If_Field_E6C_NE_MAX(p);
}
