/* ee-2.9-991111 matched TU. */

extern void func_003B3858(void);
extern int WaitSema(int sema);
extern int SignalSema(int sema);
extern int D_003FAEE8;
extern char D_007814C0[];

__attribute__((section(".text.get_iob")))
void *get_iob(int a0) {
    char *r;
    func_003B3858();
    WaitSema(D_003FAEE8);
    if ((unsigned int)a0 >= 0x20) {
        SignalSema(D_003FAEE8);
        return 0;
    }
    r = D_007814C0 + (a0 << 4);
    SignalSema(D_003FAEE8);
    return r;
}
