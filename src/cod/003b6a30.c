/* ee-2.9-991111 matched TU. */

typedef unsigned int u_int;

typedef struct tc {
    struct tc *next;   /* 0x00 */
    int  f04;
    int  f08;
    int  f0C;
    long f10;
    long f18;
    long f20;
    int  f28;
    int  pad[5];
} TimerCounter;

typedef struct {
    long ovf;          /* 0x00 */
    int  hid;          /* 0x08 */
    int  f0C;          /* 0x0C */
    int  f10;          /* 0x10 */
    TimerCounter *free;/* 0x14 */
} TimerCtl;

extern TimerCtl D_003FBE90;
extern TimerCounter D_00781C40[128];

extern void *func_003A52F0(void *, int, int);   /* memset */
extern void _InitAlarm(void);
extern int AddIntcHandler2(int, void *, int, int);
extern int cbTimerHandler();
extern int func_003B63A0(void);   /* DIntr */
extern int EIntr(void);
extern void SetT2_B0001000_3B6A00(int);   /* SetT2_COUNT */
extern void SetT2_B0001010_3B6A10(int);   /* SetT2_MODE */
extern void SetT2_B0001020_3B6A20(int);   /* SetT2_COMP */
extern int func_003B0740(int);    /* EnableIntc */

#define T2_MODE (*(volatile u_int *)0x10001010)

__attribute__((section(".text.func_003B6A30")))
int func_003B6A30(int mode)
{
    int i;
    int hid;
    int intr;
    u_int m;

    if (D_003FBE90.hid >= 0) {
        return 0x80008001;
    }
    D_003FBE90.ovf = 0;
    D_003FBE90.f10 = 0;
    func_003A52F0(D_00781C40, 0, 0x2000);
    D_003FBE90.free = D_00781C40;
    for (i = 0; i < 128; i++) {
        D_00781C40[i].next = &D_00781C40[i + 1];
    }
    D_00781C40[127].next = 0;
    _InitAlarm();
    hid = AddIntcHandler2(0xB, cbTimerHandler, 0, 0);
    if (hid < 0) {
        return 0x80009021;
    }
    D_003FBE90.hid = hid;
    intr = func_003B63A0();
    m = T2_MODE;
    m = (m & 0xFFFFFFFC) | mode;
    m |= 0x300;
    if (!(m & 0x80)) {
        SetT2_B0001000_3B6A00(0);
        m |= 0xC80;
        SetT2_B0001020_3B6A20(0xFFFF);
    }
    SetT2_B0001010_3B6A10(m);
    func_003B0740(0xB);
    if (intr) EIntr();
    return 0;
}
