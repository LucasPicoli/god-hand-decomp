/* cygnus-2.96 matched TU. */

typedef struct Sub {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1c[0x3C - 0x1C];
    int f3C;
} Sub;

extern void SFSET_SetCond(void *p, int a1, int a2);

__attribute__((section(".text.sfply_AdjustSyncMode")))
void sfply_AdjustSyncMode(char *p)
{
    Sub *s;

    s = (Sub *)(p + 0xA0C);
    if (s->f18 == 0 && s->f3C == 2) {
        SFSET_SetCond(p, 0xF, 1);
    }
    if (s->f14 == 0 && s->f3C == 1) {
        SFSET_SetCond(p, 0xF, 2);
    }
}
