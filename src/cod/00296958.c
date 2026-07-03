/* sn-2.95.3-136 matched TU. */

extern int D_005FEE00;
extern int D_003C2558;
extern void func_002CBC58(int *, int, int);
extern void LoadResourceEntry_297378();
extern void cSnd_BgmEvDataInit();
extern void LoadDisplayText_297450();
extern void cEvent_clearSystem();
extern void func_00297540();
extern int cSnd_BgmEvDataCheck();
extern void cSnd_BgmEvCutSet();
extern int cSnd_BgmEvCutCheck();
extern void func_002977E8();
extern void cEvent_startCreateWork();
extern int cEvent_isEndCreateWork();
extern int func_0();
extern void func_002D1E18();
extern void Obj0000_Set_D_003C2555_One_2B65F0();

__attribute__((section(".text.func_00296958")))
int func_00296958(char *s1) {
    short i;
    int flags;
    long t;
    void (*cb)();

    switch (*(signed char *)(s1 + 0x5)) {
    case 0:
        for (i = 0; i < 0x34; i++) {
            func_002CBC58(&D_005FEE00, i, 0);
        }
        LoadResourceEntry_297378(s1);
        cb = *(void (**)())s1;
        if (cb == 0) {
            cSnd_BgmEvDataInit(&D_005FEE00, func_00297B80(s1));
        } else {
            cb();
            *(int *)s1 = 0;
        }
        *(unsigned char *)(s1 + 0x5) += 1;
        /* fall through */
    case 1:
        if (func_00297428(s1) == 0) {
            return 0;
        }
        if (*(int *)(s1 + 0x10) == 0) {
            s1[0x5] = 0;
            s1[0x4] = 4;
            s1[0x6] = 0;
            s1[0x7] = 0;
            return 0;
        }
        LoadDisplayText_297450(s1);
        cEvent_clearSystem(s1, *(int *)(s1 + 0x18));
        *(unsigned char *)(s1 + 0x5) += 1;
        /* fall through */
    case 2:
        func_00297540(s1);
        *(unsigned char *)(s1 + 0x5) += 1;
        /* fall through */
    case 3:
        if (*(unsigned char *)(s1 + 0x9) & 1) {
            if (cSnd_BgmEvDataCheck(&D_005FEE00) == 0) {
                return 0;
            }
            cSnd_BgmEvCutSet(&D_005FEE00, -1);
        }
        *(unsigned char *)(s1 + 0x5) += 1;
        /* fall through */
    case 4:
        if (func_002975D0(s1) == 0) {
            return 0;
        }
        if (*(unsigned char *)(s1 + 0x9) & 1) {
            if (cSnd_BgmEvCutCheck(&D_005FEE00, -1) == 0) {
                return 0;
            }
        } else {
            s1[0x5] = 0;
            s1[0x4] = 4;
            s1[0x6] = 0;
            s1[0x7] = 0;
            return 0;
        }
        func_002977E8(s1);
        cEvent_startCreateWork(s1);
        *(unsigned char *)(s1 + 0x5) += 1;
        if (*(int *)(s1 + 0x8) & 0x10000000) {
            s1[0x5] = 0;
            s1[0x4] = 4;
            s1[0x6] = 0;
            s1[0x7] = 0;
            return 0;
        }
        /* fall through */
    case 5:
        if (cEvent_isEndCreateWork(s1) == 0) {
            return 0;
        }
        if (func_0(func_0) == 0) {
            func_002D1E18(&D_005FEE00, 1, -1);
            s1[0x5] = 0;
            s1[0x4] = 4;
            s1[0x6] = 0;
            s1[0x7] = 0;
            return 0;
        }
        flags = *(int *)(s1 + 0x8) | 0x10;
        *(int *)(s1 + 0x8) = flags;
        t = flags;
        if (!(((unsigned long)t >> 5) & 1)) {
            Obj0000_Set_D_003C2555_One_2B65F0(D_003C2558);
            s1[0x5] = 0;
            s1[0x4] = 3;
            s1[0x6] = 0;
            s1[0x7] = 0;
            return 1;
        }
        *(unsigned char *)(s1 + 0x5) += 1;
        /* fall through */
    case 6:
        flags = *(int *)(s1 + 0x8);
        t = flags;
        if (!(((unsigned long)t >> 6) & 1)) {
            return 0;
        }
        s1[0x5] = 0;
        s1[0x4] = 3;
        s1[0x6] = 0;
        s1[0x7] = 0;
        Obj0000_Set_D_003C2555_One_2B65F0(D_003C2558);
        return 1;
    }
    return 0;
}
