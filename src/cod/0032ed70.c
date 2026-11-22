typedef struct AdxBufDec {
    char pad0[2];
    signed char nch;
    signed char nbuf;
    char pad4[0xC - 4];
    int buf[(0x26C - 0xC) / 4];
    int mode;
} AdxBufDec;

extern int func_003297A8(int addr, int size);
extern int func_00329438(int nch, int addr, int size);

__attribute__((section(".text.aixp_create_track")))
int aixp_create_track(AdxBufDec *d, int addr, int size)
{
    int cur, rest, unit, i;

    cur = (addr + 0x3F) & ~0x3F;
    rest = size - (cur - addr);
    if (d->mode == 1)
        unit = 0x85C0;
    else
        unit = (d->nch * 0x40C0 + 0x7F) & ~0x3F;
    for (i = 0; i < d->nbuf; i++) {
        int a = cur;
        rest -= unit;
        cur += unit;
        if (rest < 0)
            return -1;
        if (d->mode == 1) {
            if ((d->buf[i] = func_003297A8(a, unit)) == 0)
                return -1;
        } else {
            if ((d->buf[i] = func_00329438(d->nch, a, unit)) == 0)
                return -1;
        }
    }
    return 0;
}
