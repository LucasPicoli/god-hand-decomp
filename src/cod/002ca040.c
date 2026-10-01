/* sn-2.95.3-136 matched TU. */

extern void cSndSeVoice_Stop(void *node);
extern void cSndBgmNode_Release(void *node);
extern void func_002CB070(void *this);
extern void func_00375050(int a, int b);
extern void func_002CA470(void *this);
extern void sceGsSyncV(int a);
extern void func_002CA148(void *this);
extern void cSndMemHeap_Close(void *a);
extern void func_0032D250(void);
extern void func_00324AC8(void);
extern void func_00325818(void);
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
    while (func_00375180() == 1) {
        func_002CA470(this);
        sceGsSyncV(0);
    }
    func_002CA148(this);
    cSndMemHeap_Close(D_006036A0);
    cSndMemHeap_Close(D_00603310);
    cSndMemHeap_Close(D_00602F80);
    func_0032D250();
    func_00324AC8();
    func_00325818();
}
