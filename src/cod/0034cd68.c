/* cygnus-2.96 matched TU. */

extern void *GetArrayElemA0C_35A1C8(void *h, int n);

__attribute__((section(".text.SFCON_IsSystemEndcodeSkip")))
int SFCON_IsSystemEndcodeSkip(void *h)
{
    if (GetArrayElemA0C_35A1C8(h, 0x31) == 0) {
        if (GetArrayElemA0C_35A1C8(h, 0x38) == 0) return 0;
    }
    return 1;
}

__attribute__((section(".text.SFCON_IsVideoEndcodeSkip")))
int SFCON_IsVideoEndcodeSkip(void *h)
{
    if (GetArrayElemA0C_35A1C8(h, 0x31) == 0) {
        if (GetArrayElemA0C_35A1C8(h, 0x39) == 0) return 0;
    }
    return 1;
}
