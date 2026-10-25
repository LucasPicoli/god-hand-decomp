/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136: func_00381F18, applies one pad step to the selected channel of a mixer record:
 * a negative flag word and bit 30 move the volume entry down and up by the step, bits 15 and 13
 * move the table index instead and reload the volume from the table. */
typedef struct MixChan {
    char unk00[2];
    unsigned char sel;                  /* 0x02 selected channel */
    char unk03;
    short vol[5];                       /* 0x04 volume per channel */
    short idx[5];                       /* 0x0E table index per channel */
} MixChan;

typedef struct MixPad {
    char unk00[0x2C];
    unsigned int flags;                 /* 0x2C bit 1: coarse step */
    char unk30[8];
    int btn;                            /* 0x38 button word */
} MixPad;

#define MIX_CHAN_OFFSET     0x318

extern short D_003F2060[];

extern void func_003820C0(void *mix, MixChan *chan);

__attribute__((section(".text.func_00381F18")))
void func_00381F18(char *mix, MixPad *pad)
{
    MixChan *c = (MixChan *)(mix + MIX_CHAN_OFFSET);
    short step = 1;
    int btn;

    if ((pad->flags & 2) != 0)
        step = 10;
    btn = pad->btn;
    if (btn < 0) {
        if (c->vol[c->sel] >= step - 0x3C0)
            c->vol[c->sel] = c->vol[c->sel] - step;
        else
            c->vol[c->sel] = -0x3C0;
        goto reidx;
    }
    if ((btn & 0x40000000) != 0) {
        if (c->vol[c->sel] <= -step)
            c->vol[c->sel] = c->vol[c->sel] + step;
        else
            c->vol[c->sel] = 0;
reidx: /* shared by the negative-flag and bit-30 arms, as in the matched sibling func_003851C0 */
        c->idx[c->sel] = func_003807E0(mix, c->vol[c->sel]);
    } else if ((btn & 0x8000) != 0) {
        if (c->idx[c->sel] >= step)
            c->idx[c->sel] = c->idx[c->sel] - step;
        else
            c->idx[c->sel] = 0;
        c->vol[c->sel] = D_003F2060[c->idx[c->sel]];
    } else {
        if ((btn & 0x2000) == 0)
            return;
        if (c->idx[c->sel] <= 0x7F - step)
            c->idx[c->sel] = c->idx[c->sel] + step;
        else
            c->idx[c->sel] = 0x7F;
        c->vol[c->sel] = D_003F2060[c->idx[c->sel]];
    }
    func_003820C0(mix, c);
}
