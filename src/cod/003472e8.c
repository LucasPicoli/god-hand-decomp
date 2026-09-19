/* cygnus-2.96 matched TU. */

extern int SFCON_IsEndcodeSkip(void *h);
extern int SFCON_IsSystemEndcodeSkip(void *h);

typedef struct H { char pad0[0x20]; int f20; } H;

__attribute__((section(".text.func_003472E8")))
int func_003472E8(H *h)
{
    int ret;

    if (h->f20 != 0) {
        ret = 0;
        if (h->f20 != 0x101) goto out;
    }
    ret = 1;
out:
    return ret;
}

__attribute__((section(".text.sfmps_IsEffectiveEndcode")))
int sfmps_IsEffectiveEndcode(void *h, int code)
{
    if (code != 0x80000) return 0;
    if (SFCON_IsEndcodeSkip(h) || SFCON_IsSystemEndcodeSkip(h)) return 0;
    return 1;
}

__attribute__((section(".text.sfmpv_IsPrepEnd")))
int sfmpv_IsPrepEnd(void *h)
{
    if (func_003554E8(h) || (func_003509E8(h) && func_00350A50(h))) return 1;
    return 0;
}
