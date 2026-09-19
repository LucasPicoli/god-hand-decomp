/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

extern int SFHDS_SetHdr(void *hn, void *sj, int len, int ofs, int *hd);
extern void func_00350040(void *hn);


__attribute__((section(".text.sfmps_CopyPrvate")))
int sfmps_CopyPrvate(void *hn, void *sj, int len, int ofs)
{
    int hd;

    if (SFHDS_SetHdr(hn, sj, len, ofs, &hd) != 0) {
        func_00350040(hn);
        if (hd != 0) {
            func_0034F008(hn, 0, len - 0x12, ofs + 0x12);
        }
        return 1;
    }
    return func_0034F008(hn, sj, len, ofs);
}
