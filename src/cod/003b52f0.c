/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct { int f0; int f4; int f8; int fC; } Iob;


extern void func_003B3F50(void);
extern int SignalSema_3B3EF8(void);
extern Iob *new_iob(void);

extern int WaitSema(int semid);
extern int SignalSema(int semid);
extern int D_003FAEDC;
extern int D_003FAEE8;
extern Iob D_007814C0[32];

__attribute__((section(".text.sceDopen")))
int sceDopen(const char *name)
{
    Iob *p;
    int fd;

    func_003B3EC8(9);
    if (D_003FAEDC == 0)
        func_003B3F50();
    SignalSema_3B3EF8();
    p = new_iob();
    if (p == 0)
        return -19;
    fd = func_003B5120(name, 9);
    if (fd < 0) {
        WaitSema(D_003FAEE8);
        p->f4 = 0;
        SignalSema(D_003FAEE8);
        return fd;
    }
    WaitSema(D_003FAEE8);
    p->f0 = fd;
    fd = p - D_007814C0;
    SignalSema(D_003FAEE8);
    return fd;
}
