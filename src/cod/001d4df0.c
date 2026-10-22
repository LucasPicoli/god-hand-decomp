/* sn-2.95.3-136: func_001D4DF0, load the blackjack ID file, set up its 45 ID works and default display. */
#include "godhand/heapArena.h"
extern int D_003C2388;
extern char **D_003C2384;
extern char D_00583F20[];
extern char D_0042B190[];

extern int cIDManager_getLocalFileName(int mgr, char *buf, char *name, int lang);
extern int cDvd_ReadAlloc(char *dvd, char *name, void *out, void *heap, int a4, int a5, int a6, int a7);
extern void cDvd_CheckWait(char *dvd, int req);
extern void cIDManager_setIDData(void *mgr, int kind, int res);
extern int cIDBase_initialize(void *self, int kind, int a2);
extern void cIDBase_restartAnim(void *self);
extern void *cIDBase_getIDWork(void *self, int idx);
extern void CustomIDWork_Initialize(void *w, void *id);
extern void CustomIDWork_SetDisp(void *w, int show);
extern void CustomIDWork_SetNumber_1D5760(char *self, int n);
extern void func_001D5780(void *self, int n);
extern void func_001D6A30(void *self, int n);
extern void func_001D6A50(void *self, int n);
extern void BlackJackId_SetDefaultDisp(void *self);

__attribute__((section(".text.func_001D4DF0")))
void func_001D4DF0(char *self)
{
    char buf[0x40];
    int res;
    int r;
    int i;

    cIDManager_getLocalFileName(D_003C2388, buf, D_0042B190, -1);
    r = cDvd_ReadAlloc(D_00583F20, buf, &res, &D_00754220, 0, 0, 0, 0);
    if (r != 0) {
        cDvd_CheckWait(D_00583F20, r);
        cIDManager_setIDData(*D_003C2384, 0x13, res);
        cIDBase_initialize(self + 0x10, 0x13, 0);
        cIDBase_restartAnim(self + 0x10);
        for (i = 0; i < 45; i++)
            CustomIDWork_Initialize(self + 0x60 + i * 0x7C, cIDBase_getIDWork(self + 0x10, i));
        CustomIDWork_SetDisp(self + 0x60, 0);
        CustomIDWork_SetNumber_1D5760(self, 0);
        func_001D5780(self, 0);
        func_001D6A30(self, 0);
        func_001D6A50(self, 0);
        BlackJackId_SetDefaultDisp(self);
    }
}
