/* ee-2.9-991111: sceOpen-style open(name, flags, mode) over the SIF RPC packet at D_0077FFC0 (0x3B4220). */
extern int func_003B3EC8(int cmd);

typedef struct { int f0; int f4; int f8; int fC; } Iob;
typedef struct {
    int sema;
    void *dst;
    int size;
    int flags;
    int mode;
    char name[0x400];
    int unit;
} OpenPkt;

struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

extern Iob *new_iob(void);
extern void func_003B3F50(void);
extern int func_003B4158(void);
extern int func_003B3958(void *, int, int, void *, int, void *, int, int, int, int);

extern int SignalSema_3B3EF8(void);
extern int CreateSema(struct SemaParam *p);
extern int DeleteSema(int id);
extern int WaitSema(int id);
extern int SignalSema(int id);

extern int D_003FAEDC;
extern int D_003FAEE8;
extern Iob D_007814C0[32];
extern OpenPkt D_0077FFC0;
extern char D_00460120[];
extern char D_00780C00[];
extern char D_007816C0[];

__attribute__((section(".text.func_003B4220")))
int func_003B4220(const char *name, int flags, ...)
{
    struct SemaParam sp;
    int result;
    Iob *p;
    int sid;
    int r;
    int i;
    int mode;
    int unit;

    OpenPkt *q = &D_0077FFC0;

    func_003B3EC8(0);
    if (!D_003FAEDC)
        func_003B3F50();
    if (func_003B4158()) {
        SignalSema_3B3EF8();
        return 0xFFFEFFFC;
    }
    p = new_iob();
    if (!p) {
        SignalSema_3B3EF8();
        return -19;
    }
    mode = *(int *)((char *)__builtin_next_arg(flags) - 0x30);
    for (i = 0; i < 0x400; i++) {
        if ((q->name[i] = name[i]) == 0)
            break;
    }
    if (i == 0x400)
        q->name[0x3FF] = 0;
    q->flags = flags & 0x7FFFFFFF;
    q->mode = mode;
    unit = p - D_007814C0;
    q->unit = unit;
    sp.maxCount = 1;
    sp.initCount = 0;
    sp.option = (unsigned int)D_00460120;
    sid = CreateSema(&sp);
    q->dst = &result;
    q->sema = sid;
    q->size = 4;
    r = func_003B3958(D_007816C0, 0, 0, &D_0077FFC0, 0x418, D_00780C00, 4, 0, 0, 0);
    if (r < 0) {
        DeleteSema(sid);
        SignalSema_3B3EF8();
        return -11;
    }
    r = *(int *)((unsigned int)D_00780C00 | 0x20000000);
    SignalSema_3B3EF8();
    if (r == 0) {
        DeleteSema(sid);
        return -11;
    }
    WaitSema(sid);
    DeleteSema(sid);
    if (result < 0) {
        WaitSema(D_003FAEE8);
        p->f4 = 0;
        SignalSema(D_003FAEE8);
        return result;
    }
    r = unit;
    WaitSema(D_003FAEE8);
    p->f0 = result;
    p->f4 |= flags;
    SignalSema(D_003FAEE8);
    return r;
}
