/* sn-2.95.3-136 matched TU. */
#include "godhand/ColiseumBattle.h"

extern int cCoreSave_getBonus(void *p);
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












/* Loads the ring's rules record and the result UI data, then sets up the
* player and the clock for the fight. */
__attribute__((section(".text.ColiseumBattle_Initialize")))
void ColiseumBattle_Initialize(ColiseumBattle *self)
{
    char name[0x40];
    int info[4];
    int *q;
    void *h;
    int n;
    int t;
    char *g;

    *(Blob28 *)&self->ring =
        D_003BE8B0[cCoreSave_getBonus(D_00569B70)];
    self->phase = 0;
    D_00568240 &= ~2;
    D_00568240 &= ~4;
    q = self->unkC64;
    for (n = 0x1D; n >= 0; n--) q[n] = 0;
    D_005864F0[0x5B5] = 1;
    cIDManager_getLocalFileName(D_003C2388, name, D_0042BE30, -1);
    h = cDvd_ReadAlloc(D_00583F20, name, info, D_00754220, 0, 0, 0, 0);
    cDvd_CheckWait(D_00583F20, h);
    cIDManager_setIDData(*D_003C2384, 0x15, info[0]);
    func_001F27B0(self->ui);
    func_001F2A88(self->ui, self->ring.timeLimit != 0);
    func_001F2B28(self->ui, self->ring.unk0A, 1);
    if (self->ring.timeLimit != 0) {
        func_001F2B80(self->ui, 1, self->ring.timeLimit / 60,
                      self->ring.timeLimit % 60, 0, 1);
    }
    self->mode = 0;
    self->state = 0;
    self->unk0C = 0;
    t = ColiseumBattle_CountLiveEnemies(self);
    self->unkB88 = 0;
    self->enemyNum = t;
    func_001EFA50(self);
    if (self->ring.timeLimit != 0) SetField_B98_1EFD50(self);
    ColiseumBattle_PlCtrlOff(self, 1);
    g = D_007474A0;
    SetBgmTbl(*(unsigned short *)(g + 0x5B0), self->ring.bgm, 1);
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
