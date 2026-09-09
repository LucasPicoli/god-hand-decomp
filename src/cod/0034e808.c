/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct {
    unsigned char pad0[0x28];
    int hdr_size;                       /* +0x28 */
} SfMps;

extern int func_0034E8E8(const unsigned char *p, int n);   /* sfmps_IsZero */
extern int func_00368A28(const unsigned char *p);          /* MPS_CheckDelim */
extern int sfmps_IsEndOfRingBuf(SfMps *mps, const unsigned char *p);

__attribute__((section(".text.sfmps_SkipNext")))
void sfmps_SkipNext(SfMps *mps, const unsigned char *p, int len, int *out)
{
    int n;
    int cnt;

    *out = 0;
    n = mps->hdr_size;
    if (len >= n + 3) {
        if (func_0034E8E8(p, n)) {
            *out = n;
            return;
        }
    }
    cnt = 0;
    while (len >= 4) {
        if (func_00368A28(p++) & 0x000D0000) {
            *out = cnt;
            return;
        }
        len--;
        cnt++;
    }
    if ((unsigned int) (len - 1) < 3) {
        if (sfmps_IsEndOfRingBuf(mps, p + len))
            cnt += len;
    }
    *out = cnt;
}
