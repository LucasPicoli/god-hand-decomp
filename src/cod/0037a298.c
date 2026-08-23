/* sn-2.95.3-136 matched TU. */

extern unsigned char D_0076DF10[];
extern unsigned char D_0076E510[];
extern unsigned char D_0076EA50[];

/* sn-2.95.3-136 matched TU. */

typedef struct D48 { char b[0x30]; } D48;
typedef struct D96 { char b[0x60]; } D96;

typedef struct Slot {
    int f0;
    char *f4;
    int f8;
    int fC;
    int f10;
    int f14;
    char *f18;
    int f1C;
} Slot;





typedef struct Obj {
    char pad0[7];
    signed char sel;        /* 0x07 */
    char pad8[0xE];
    short idxA[3];          /* 0x16 */
    short idxB[3];          /* 0x1C */
    unsigned char f22[4];   /* 0x22 */
    char pad26[0x76];
    D48 d9C;                /* 0x9C  */
    D96 dCC;                /* 0xCC  */
    D48 d12C;               /* 0x12C */
} Obj;

__attribute__((section(".text.func_0037A298")))
void func_0037A298(Obj *p)
{
    int n = p->sel;
    int i1 = p->idxA[n];
    int i2 = p->idxB[n];

    switch (n) {
    case 0:
        {
            Slot *s = &((Slot *)D_0076DF10)[i1];
            char *d = s->f4 + i2 * 0x30;
            *(D48 *)d = p->d9C;
        }
        break;
    case 1:
        {
            Slot *s = &((Slot *)D_0076E510)[i1];
            char *d = s->f4 + i2 * 0x60;
            *(D96 *)d = p->dCC;
        }
        break;
    case 2:
        {
            Slot *s = &((Slot *)D_0076EA50)[i1];
            char *d = s->f18 + i2 * 0x30;
            *(D48 *)d = p->d12C;
        }
        break;
    }
    p->f22[p->sel] = p->f22[3];
}
