/* sn-2.95.3-136 matched TU. */

extern void func_002CE430(void *node);
extern void func_002CCB10(void *node);
extern void func_002CB070(void *this);
extern void func_00375050(int a, int b);
extern void func_002CA470(void *this);
extern void sceGsSyncV(int a);
extern void func_002CA148(void *this);
extern void func_002CD780(void *a);
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
            func_002CE430(node);
            node = *(char **)(node + 0x4);
        } while (node != 0);
    }
    node = *(char **)(base + 0x18);
    if (node != 0) {
        do {
            func_002CCB10(node);
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
    func_002CD780(D_006036A0);
    func_002CD780(D_00603310);
    func_002CD780(D_00602F80);
    func_0032D250();
    func_00324AC8();
    func_00325818();
}
