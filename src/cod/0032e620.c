/* cygnus-2.96 matched TU. */

extern void func_00327E18(int a0, int a1, int a2, int a3, int a4);
extern void func_00328C80(int a0, int a1, int a2);
extern void func_003280D8(int a0, int a1);
extern void func_00328448(int a0, int a1);
extern void func_0032F4B8(int a0, int a1);
extern void func_0032F470(int a0);
extern unsigned int strlen(char *s);
extern int Obj34D8_SetGlobalEE0B8_IfField48(int a0);
extern void func_0034DD70(int a0, int a1);

__attribute__((section(".text.func_0032E620")))
void func_0032E620(void *a0) {
    int i = 0;
    func_00327FA8(*(int *)((char *)a0 + 8));
    {
        void *o = *(void **)((char *)a0 + 0x90);
        (*(void (**)(void *))(*(char **)o + 0x14))(o);
    }
    if (*(signed char *)((char *)a0 + 3) > 0) {
        void **p = (void **)((char *)a0 + 0x94);
        do {
            void *o = *p++;
            (*(void (**)(void *))(*(char **)o + 0x14))(o);
            i++;
        } while (i < *(signed char *)((char *)a0 + 3));
    }
    func_00327E18(*(int *)((char *)a0 + 8), *(int *)((char *)a0 + 0x1D0),
                  *(int *)((char *)a0 + 0x1D4), *(int *)((char *)a0 + 0x1D8),
                  *(int *)((char *)a0 + 0x1DC));
    func_00328C80(*(int *)((char *)a0 + 8), *(int *)((char *)a0 + 0x118) / 2, 0x7FFFFFFF);
    func_003280D8(*(int *)((char *)a0 + 8), 0);
    func_00328448(*(int *)((char *)a0 + 8), 3);
    func_003281C8(*(int *)((char *)a0 + 8));
    func_0032F4B8(*(int *)((char *)a0 + 4), 1);
    func_0032F470(*(int *)((char *)a0 + 4));
}

__attribute__((section(".text.func_00334CA0")))
int func_00334CA0(char *o) {
    unsigned int len = strlen(o);
    unsigned int n = len > 0x10 ? 0x10 : len;
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (o[i] == ':') return 1;
    }
    return 0;
}

__attribute__((section(".text.func_003502D8")))
void func_003502D8(int a0, int a1, int a2) {
    int v1 = 0;
    if (a0 != 0) {
        if (Obj34D8_SetGlobalEE0B8_IfField48(a0)) { func_0034DD70(0, 0xFF000181); return; }
        v1 = *(int *)*(int *)((char *)a0 + 0x1FC0);
    }
    if (func_0036C450(v1, a1, (a1 != 5) ? a2 : 0)) { func_0034DD70(a0, 0xFF000F12); return; }
}
