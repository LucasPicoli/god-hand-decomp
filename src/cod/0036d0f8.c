typedef unsigned char Uint8;
typedef int Sint32;
extern Uint8 *MPV_SearchDelim(Uint8 *buf, Sint32 len, Sint32 type);
extern Sint32 MPV_CheckDelim(Uint8 *ptr);

__attribute__((section(".text.m2v_IsConformable")))
Sint32 m2v_IsConformable(Uint8 *buf, Sint32 len)
{
    Uint8 *p;

    p = MPV_SearchDelim(buf, len, 0x40);
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
    if ((MPV_CheckDelim(p) & 0x10) == 0)
        return 0;
    p += 4;
    len -= p - buf;
    if (len <= 0)
        return 0;
    return (*p >> 4) == 1;
}
