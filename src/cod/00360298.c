/* cygnus-2.96: sfxzmv_MakeOrgZ32TblByDirect, builds a 256-entry threshold table: zeros, a low plateau, a linear ramp
 * from lo to hi over entries 17..223, a high plateau and saturated entries. INT_MIN inputs mean "max". */
__attribute__((section(".text.sfxzmv_MakeOrgZ32TblByDirect")))
void sfxzmv_MakeOrgZ32TblByDirect(int unused, int lo, int hi, int *tbl)
{
    int i;

    if (hi == (int)0x80000000)
        hi = 0x7FFFFFFF;
    if (lo == (int)0x80000000)
        lo = 0x7FFFFFFF;
    for (i = 8; i >= 0; i--)
        tbl[i] = 0;
    for (i = 9; i < 17; i++)
        tbl[i] = lo;
    if (lo == hi) {
        for (i = 17; i < 224; i++)
            tbl[i] = lo;
    } else {
        for (i = 17; i < 224; i++)
            tbl[i] = (unsigned int)(hi - lo) / 207 * (i - 17) + lo;
    }
    for (i = 224; i < 240; i++)
        tbl[i] = hi;
    for (i = 240; i < 256; i++)
        tbl[i] = 0x7FFFFFFF;
}
