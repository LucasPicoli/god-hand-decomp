/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Field_BA8_Via_Ptr0_1FC530(void *p);
extern char D_00569B70[];
extern int D_00568240;
extern int D_003C2388;
extern int *D_003C2384;
extern char D_005864F0[];
extern char D_0042BE30[];
extern char D_00583F20[];
extern char D_00754220[];
extern char D_007474A0[];
extern void cIDManager_getLocalFileName(int a, void *b, void *c, int d);
extern void cDvd_CheckWait(void *a, void *b);
extern void cIDManager_setIDData(int a, int b, int c);
extern void func_001F27B0(void *a);
extern void func_001F2A88(void *a, int b);
extern void func_001F2B28(void *a, short b, int c);
extern void func_001F2B80(void *a, int b, int c, int d, int t0, int t1);
extern void func_001EFA50(void *a);
extern void SetField_B98_1EFD50(void *a);
extern void ColiseumBattle_PlCtrlOff(void *a, int b);
extern void SetBgmTbl(int a, int b, int c);
extern void SetCustomIDDispOneOrAll_1DD258(int a0, int a1, int a2);

/* sn-2.95.3-136 candidate. */

typedef struct { char b[0x28]; } Blob28;



extern Blob28 D_003BE8B0[];









extern void *cDvd_ReadAlloc(void *a, void *b, void *c, void *d,
                            int t0, int t1, int t2, int t3);












__attribute__((section(".text.ColiseumBattle_Initialize")))
void ColiseumBattle_Initialize(char *self)
{
    char name[0x40];
    int info[4];
    int *q;
    void *h;
    int n;
    int t;
    char *g;

    *(Blob28 *)(self + 0xB60) =
        D_003BE8B0[Obj0000_Get_Field_BA8_Via_Ptr0_1FC530(D_00569B70)];
    *(int *)(self + 0xB94) = 0;
    D_00568240 &= ~2;
    D_00568240 &= ~4;
    q = (int *)(self + 0xC64);
    for (n = 0x1D; n >= 0; n--) q[n] = 0;
    D_005864F0[0x5B5] = 1;
    cIDManager_getLocalFileName(D_003C2388, name, D_0042BE30, -1);
    h = cDvd_ReadAlloc(D_00583F20, name, info, D_00754220, 0, 0, 0, 0);
    cDvd_CheckWait(D_00583F20, h);
    cIDManager_setIDData(*D_003C2384, 0x15, info[0]);
    func_001F27B0(self + 0x60);
    func_001F2A88(self + 0x60, *(int *)(self + 0xB6C) != 0);
    func_001F2B28(self + 0x60, *(short *)(self + 0xB6A), 1);
    if (*(int *)(self + 0xB6C) != 0) {
        func_001F2B80(self + 0x60, 1, *(int *)(self + 0xB6C) / 60,
                      *(int *)(self + 0xB6C) % 60, 0, 1);
    }
    *(int *)(self + 0x4) = 0;
    *(int *)(self + 0x8) = 0;
    *(int *)(self + 0xC) = 0;
    t = func_001EF8B8(self);
    *(int *)(self + 0xB88) = 0;
    *(int *)(self + 0xB8C) = t;
    func_001EFA50(self);
    if (*(int *)(self + 0xB6C) != 0) SetField_B98_1EFD50(self);
    ColiseumBattle_PlCtrlOff(self, 1);
    g = D_007474A0;
    SetBgmTbl(*(unsigned short *)(g + 0x5B0), *(int *)(self + 0xB84), 1);
}

/* sn-2.95.3-136 */

typedef struct { int w[10]; } Blob;

extern Blob D_0042B600;


__attribute__((section(".text.func_001DDDB0")))
void func_001DDDB0(int a0, unsigned char a1, unsigned char a2)
{
    Blob b;

    if (a1 >= 5) {
        return;
    }
    b = D_0042B600;
    switch (a2) {
    case 0:
        SetCustomIDDispOneOrAll_1DD258(a0, b.w[a1 * 2], 0);
        {
            char *bp = (char *)&b + 4;

            bp += a1 * 8;
            SetCustomIDDispOneOrAll_1DD258(a0, *(int *)bp, 0);
        }
        break;
    case 1:
        SetCustomIDDispOneOrAll_1DD258(a0, b.w[a1 * 2], 0);
        {
            char *bp = (char *)&b + 4;

            bp += a1 * 8;
            SetCustomIDDispOneOrAll_1DD258(a0, *(int *)bp, 1);
        }
        break;
    case 2:
        SetCustomIDDispOneOrAll_1DD258(a0, b.w[a1 * 2], 1);
        {
            char *bp = (char *)&b + 4;

            bp += a1 * 8;
            SetCustomIDDispOneOrAll_1DD258(a0, *(int *)bp, 0);
        }
        break;
    }
}
