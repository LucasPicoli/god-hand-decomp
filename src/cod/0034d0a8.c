/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

extern int sfhds_IsPrvate2PketStart(char *p);
extern int SFHDS_IsSfdHeader(char *p, int len);


__attribute__((section(".text.SFHDS_SetHdr")))
int SFHDS_SetHdr(void *hn, int kind, char *buf, int len, int *out)
{
    *out = 0;
    if (kind != 2) return 0;
    buf -= 6;
    len += 6;
    if (sfhds_IsPrvate2PketStart(buf) == 0) {
        buf -= 2;
        len += 2;
        if (sfhds_IsPrvate2PketStart(buf) == 0) return 0;
    }
    buf -= 12;
    len += 12;
    if (SFHDS_IsSfdHeader(buf, len) == 0) return 0;
    *out = func_0034D210(hn, buf, len);
    return 1;
}
