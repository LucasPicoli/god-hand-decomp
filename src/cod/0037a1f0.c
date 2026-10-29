/* sn-2.95.3-136: func_0037A1F0, applies the per-mode position to the active sub-object and latches the
 * mode's flag byte. */
typedef struct {
    char pad0[7];
    signed char mode; /* 0x07 */
    char pad8[0x16 - 0x8];
    short x[3]; /* 0x16 */
    short y[3]; /* 0x1C */
    unsigned char flag[3]; /* 0x22 */
    unsigned char curflag; /* 0x25 */
    char pad26[0x9C - 0x26];
    char obj0[0xCC - 0x9C]; /* 0x9C */
    char obj1[0x12C - 0xCC]; /* 0xCC */
    char obj2[4]; /* 0x12C */
} ModeSel;
extern int SdeIssTblGet(int x, int y, void *obj);
extern void func_00386DE0(int x, int y, void *obj);
extern int func_00375AB0(int x, int y, void *obj);

__attribute__((section(".text.func_0037A1F0")))
void func_0037A1F0(ModeSel *m)
{
    int mode = m->mode;
    int x = m->x[mode];
    int y = m->y[mode];

    switch (mode) {
    case 0:
        SdeIssTblGet(x, y, m->obj0);
        break;
    case 1:
        func_00386DE0(x, y, m->obj1);
        break;
    case 2:
        func_00375AB0(x, y, m->obj2);
        break;
    }
    m->curflag = m->flag[m->mode];
}
