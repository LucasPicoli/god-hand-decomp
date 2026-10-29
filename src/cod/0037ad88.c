typedef struct MenuSlider {
    short *val;
    char pad4[6];
    short min;
    short max;
    short step;
    short bigStep;
    char pad12[2];
} MenuSlider;

typedef struct MenuSliderCtl {
    char pad0[0x26];
    signed char cur;
    char pad27[5];
    int flags;
    char pad30[4];
    int trg;
    int rep;
    char pad3C[0x120];
    char snd[4];
} MenuSliderCtl;

extern MenuSlider D_003F2638[];
extern void SdeSystemVolGet(char *snd);
extern void SdeSystemVolSet(char *snd);
extern void SdePlayVolReset(int se);

__attribute__((section(".text.func_0037AD88")))
int func_0037AD88(MenuSliderCtl *m)
{
    MenuSlider *s = &D_003F2638[m->cur];
    short v, old, step;
    int pad;

    SdeSystemVolGet(m->snd);
    v = *s->val;
    old = v;
    if (m->flags & 8)
        step = s->bigStep;
    else
        step = s->step;
    if (m->flags & 0x80) {
        pad = m->trg;
        if (pad & 0x8000)
            v = s->min;
        if (pad & 0x2000)
            v = s->max;
        if (pad & 0x1000)
            v = 0;
        if (pad & 0x4000)
            v = 0;
    } else {
        if (m->rep & 0x8000)
            v -= step;
        if (m->rep & 0x2000)
            v += step;
    }
    if (v < s->min)
        v = s->max;
    if (v > s->max)
        v = s->min;
    if (v != old) {
        *s->val = v;
        SdeSystemVolSet(m->snd);
        SdePlayVolReset(7);
        return 1;
    }
    return 0;
}
