/* sn-2.95.3-136 matched TU. */

static inline void put(unsigned char **pp, long v)
{
    unsigned char *q = *pp;

    *(long *)q = v;
    *pp = q + 8;
}

__attribute__((section(".text.func_002FA4F0")))
void func_002FA4F0(unsigned char **pp, unsigned char kind)
{
    switch (kind) {
    case 0:
        put(pp, 0x8000000044L);
        break;
    case 1:
        put(pp, 0x8000000048L);
        break;
    case 2:
        put(pp, 0x80000000A9L);
        break;
    case 3:
        put(pp, 0x8000000041L);
        break;
    case 4:
        put(pp, 0x8000000049L);
        break;
    case 5:
        put(pp, 0x8000000068L);
        break;
    case 6:
        put(pp, 0x8000000009L);
        break;
    case 7:
        put(pp, 0x8000000046L);
        break;
    case 8:
        put(pp, 0x80000000A4L);
        break;
    case 9:
        put(pp, 0x8000000042L);
        break;
    case 10:
        put(pp, 0x8000000006L);
        break;
    }
    put(pp, 0x42L);
}
