/* sn-2.95.3-136 matched TU. */

extern void cSndSeVoice_Stop(void *node);
extern void cSndBgmNode_Release(void *node);
extern void func_002CB070(void *this);
extern void func_00375050(int a, int b);
extern void cSnd_update(void *this);
extern void sceGsSyncV(int a);
extern void cSnd_resetAll(void *this);
extern void cSndMemHeap_Close(void *a);
extern void AIXP_Finish(void);
extern void ADXT_Finish(void);
extern void ADXM_ShutdownThrd(void);
extern char D_006036A0[];
extern char D_00603310[];
extern char D_00602F80[];

/* func_002CA040 — sn-2.95.3-136, --call-loop-pad */

















__attribute__((section(".text.func_002CA040")))
void func_002CA040(void *this) {
    char *base = (char *)this;
    char *node;

    node = *(char **)(base + 0x1C);
    if (node != 0) {
        do {
            cSndSeVoice_Stop(node);
            node = *(char **)(node + 0x4);
        } while (node != 0);
    }
    node = *(char **)(base + 0x18);
    if (node != 0) {
        do {
            cSndBgmNode_Release(node);
            node = *(char **)(node + 0x88);
        } while (node != 0);
    }
    *(int *)(base + 0xAC) = 0;

    *(int *)(base + 0xB0) = 0;
    *(int *)(base + 0x30) = 0;
    *(int *)(base + 0xA8) = 0;
    func_002CB070(this);
    func_00375050(0, 0);
    while (SdeIssEndCheck() == 1) {
        cSnd_update(this);
        sceGsSyncV(0);
    }
    cSnd_resetAll(this);
    cSndMemHeap_Close(D_006036A0);
    cSndMemHeap_Close(D_00603310);
    cSndMemHeap_Close(D_00602F80);
    AIXP_Finish();
    ADXT_Finish();
    ADXM_ShutdownThrd();
}
