/* sn-2.95.3-136: func_0030B298, boot setup of the game work: clear it, set the language and video mode,
 * pick the boot room, then start the graphics, data and sound systems. */
#include "godhand/gameWork.h"
#include "godhand/criStm.h"

/* The game work (D_007474A0) as the boot code sees it: only word fields, so 4-byte aligned. */
typedef struct BootWork {
    char pad000[0x569];
    unsigned char unk569;               /* 0x569 */
    char pad56A[2];
    int language;                       /* 0x56C */
    char pad570[8];
    int mode;                           /* 0x578 1 = PAL */
    int unk57C;                         /* 0x57C */
    int unk580;                         /* 0x580 */
    int flags;                          /* 0x584 */
    char pad588[4];
    int sysFlags;                       /* 0x58C D_00747A2C starts here */
    char pad590[8];
    int flags598;                       /* 0x598 */
    int flags59C;                       /* 0x59C */
    char pad5A0[0x10];
    short room;                         /* 0x5B0 */
    char pad5B2[0x620 - 0x5B2];
} BootWork;

extern int D_003C3CCC;
extern int D_00752D3C;
extern char D_005E8140[];
extern char D_005E8640[];
extern char D_00580D40[];
extern char D_004504D8[];

extern void func_0030D258(void);
extern void func_0030ECF8(int a0);
extern void Tramp_func_0015B0C0_0015B0A0(void);
extern void func_0031CEB8(void);
extern void func_002BDFF8(void *p);
extern void func_0030CB30(void);
extern int sceGsResetGraph(short mode, short inter, short omode, short ffmode);
extern int sceGsSyncV(int mode);
extern void func_0030B148(void);
extern void func_00395F68(void (*fn)(void));
extern void func_0030D1F8(void);
extern int func_001FF858(void *a0, void *a1);
extern void func_002BE6E8(void *obj);

static inline int isPal(BootWork *s)
{
    return s->mode == 1;
}

static inline int sysIsPal(void)
{
    return ((BootWork *)&D_007474A0)->mode == 1;
}

__attribute__((section(".text.func_0030B298")))
void func_0030B298(void)
{
    GameSys *e3;
    BootWork *sys;
    BootWork *g = (BootWork *)&D_007474A0;

    func_0030D258();
    func_0030ECF8(0);
    Tramp_func_0015B0C0_0015B0A0();
    func_0031CEB8();
    func_003A52F0(g, 0, sizeof(BootWork));
    g->language = 1;
    g->mode = 0;
    g->flags59C &= ~0x100000;
    if (!(g->flags598 & 0x200000) || (g->flags59C & 0x1000000))
        g->room = GAMEWORK_ROOM_NOPLAYER;
    else
        g->flags |= 0x200;
    e3 = &D_00747A2C;                   /* D_00747A2C sits at 0x58C of the game work */
    if (e3->flags & 0x800)
        ((BootWork *)((char *)e3 - 0x58C))->language = 1;
    sys = (BootWork *)((char *)e3 - 0x58C);
    sys->unk57C = 0;
    sys->unk580 = 0;
    if (!isPal(sys))
        D_003C3CCC = 0x40;
    else
        D_003C3CCC = 0x50;
    func_002BDFF8(D_005E8140);
    func_0030CB30();
    if (sysIsPal()) {
        sceGsResetGraph(0, 1, 3, 0);
        sceGsSyncV(0);
    }
    func_00395F68(func_0030B148);
    func_0030D1F8();
    func_001FF858(D_00580D40, D_004504D8);
    g->unk569 = 2;
    D_00752D3C = 0;
    func_002BE6E8(D_005E8640);
}
