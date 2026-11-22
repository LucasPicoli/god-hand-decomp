#include "godhand/MpvHandle.h"

__attribute__((section(".text.m2v_IsConformable")))
Sint32 m2v_IsConformable(Uint8 *buf, Sint32 len)
{
    Uint8 *p;

    p = MPV_SearchDelim(buf, len, MPV_DLM_SHC);
    if (p == 0)
        return 0;
    p += 4;
    len -= p - buf;
    if (len <= 0)
        return 0;
    buf = p;
    p = MPV_SearchDelim(buf, len, -1);
    if (p == 0)
        return 0;
    if ((MPV_CheckDelim(p) & MPV_DLM_ESC) == 0)
        return 0;
    p += 4;
    len -= p - buf;
    if (len <= 0)
        return 0;
    return (*p >> 4) == 1;
}
