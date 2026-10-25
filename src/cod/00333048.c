typedef struct {
    char pad0[2];
    char state;
    char pad3[0x14 - 3];
    int unk14;
    char pad18[4];
    void *unk1C;
} CdStreamCtl;

extern char D_00454458[];
extern char D_004544B8[];
extern void func_00332808(CdStreamCtl *, char *);
extern int func_00331570(void *);
extern void CdSrd_finishRead(void);
extern void func_00332958(void);
extern int func_00333130(CdStreamCtl *);
extern void func_003260C8(char *);

__attribute__((section(".text.func_00333048")))
void func_00333048(CdStreamCtl *o)
{
    int n;

    n = 0;
    if (o == 0) {
        func_00332808(o, D_00454458);
        return;
    }
    if ((unsigned char)o->state < 2) {
        return;
    }
    if (o->unk1C != 0) {
        func_00331570(o->unk1C);
    }
    for (;;) {
        CdSrd_finishRead();
        func_00332958();
        func_00333130(o);
        if (o->state != 2) {
            break;
        }
        n++;
        if (n > 0x9FFFF) {
            func_003260C8(D_004544B8);
            break;
        }
    }
    o->state = 0;
    o->unk14 = 0;
}
