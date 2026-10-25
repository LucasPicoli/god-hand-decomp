/* cygnus-2.96: fill a stream request from the global info block and push the handle's frame-rate and
 * time conditions into its timer object. */
#include "godhand/sftim.h"
typedef struct {
    int v[7];
} StmReqInfo;

typedef struct {
    int f00;
    int f04;
    StmReqInfo info;            /* 0x08 */
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
    void *cb;                   /* 0x3C */
    int f40;
    int f44;
    int f48;
    int f4C;
} StmReq;

extern StmReqInfo D_00760D90;
extern void SftrnHn_init(void *tm);
extern void Obj35C0_SetField_0_C4C0(void *tm, int v);
extern void Obj35C0_CopyPair_138_C4C8(void *tm, long long *p);
extern void Obj35C0_CopyPair_148_C4E0(void *tm, long long *p);
extern void Obj35C0_CopyPair_158_C4F8(void *tm, long long *p);
extern void Obj35C0_CopyPair_168_C510(void *tm, long long *p);
extern void Obj35C0_SetField10_IfPositive_C528(void *tm, int v);
extern void func_00360950(int v);
extern void func_0034A038(void *a0, int a1, int a2, int *a3);

__attribute__((section(".text.func_0034ADB8")))
int func_0034ADB8(char *hn, StmReq *req)
{
    long long t[4][2];

    if (D_00760D90.v[2] == 0 || D_00760D90.v[6] == 0)
        return func_0034DD70(0, 0xFF000C06);
    req->info = D_00760D90;
    req->f00 = 0;
    req->f04 = 0;
    req->f24 = -1;
    req->f28 = 1;
    req->f2C = 0;
    req->f30 = 0;
    req->f34 = 0;
    req->f38 = 0;
    req->cb = func_0034A038;
    req->f40 = 0;
    req->f44 = -1;
    req->f48 = 0;
    req->f4C = 0;
    t[0][0] = GetArrayElemA0C_35A1C8(hn, 0x3F);
    t[0][1] = 1000000;
    t[1][0] = GetArrayElemA0C_35A1C8(hn, 0x40);
    t[1][1] = 1000000;
    t[2][0] = GetArrayElemA0C_35A1C8(hn, 0x41);
    t[2][1] = 1000000;
    t[3][0] = GetArrayElemA0C_35A1C8(hn, 0x42);
    t[3][1] = 1000000;
    SftrnHn_init(hn + 0x1020);
    Obj35C0_SetField_0_C4C0(hn + 0x1020, GetArrayElemA0C_35A1C8(hn, 0x48));
    Obj35C0_CopyPair_138_C4C8(hn + 0x1020, t[0]);
    Obj35C0_CopyPair_148_C4E0(hn + 0x1020, t[1]);
    Obj35C0_CopyPair_158_C4F8(hn + 0x1020, t[2]);
    Obj35C0_CopyPair_168_C510(hn + 0x1020, t[3]);
    Obj35C0_SetField10_IfPositive_C528(hn + 0x1020, GetArrayElemA0C_35A1C8(hn, 0x3E));
    func_00360950(GetArrayElemA0C_35A1C8(hn, 0x3D));
    return 0;
}
