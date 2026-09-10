/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Iob;

extern void func_003B3858(void);
extern int WaitSema(int semid);
extern int SignalSema(int semid);
extern int D_003FAEE8;
extern Iob D_007814C0[32];

__attribute__((section(".text.new_iob")))
Iob *new_iob(void)
{
    Iob *p;

    func_003B3858();
    WaitSema(D_003FAEE8);
    for (p = D_007814C0; p < D_007814C0 + 32; p++) {
        if (p->f4 == 0) {
            p->f4 = 0x10000000;
            SignalSema(D_003FAEE8);
            return p;
        }
    }
    SignalSema(D_003FAEE8);
    return 0;
}
