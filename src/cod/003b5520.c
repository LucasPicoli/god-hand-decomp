/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct { int f0; int f4; int f8; int fC; } Iob;
typedef struct { int sema; void *dst; int size; int fd; void *buf; } Pkt;

struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

extern Iob *get_iob(int fd);

extern int SignalSema_3B3EF8(void);
extern int CreateSema(struct SemaParam *p);
extern int DeleteSema(int id);
extern int WaitSema(int id);

extern int D_003FAEDC;
extern Pkt D_0077FFC0;
extern char D_00460240[];
extern char D_00780C00[];
extern char D_007816C0[];

__attribute__((section(".text.func_003B5520")))
int func_003B5520(int fd, void *buf)
{
    struct SemaParam sp;
    int result;
    Iob *p;
    int sid;
    int r;
    int flag;
    Pkt *q = &D_0077FFC0;

    p = get_iob(fd);
    func_003B3EC8(11);
    if (!D_003FAEDC || !p || !p->f4) {
        SignalSema_3B3EF8();
        return -9;
    }
    q->fd = p->f0;
    q->buf = buf;
    sp.maxCount = 1;
    sp.initCount = 0;
    sp.option = (unsigned int)D_00460240;
    sid = CreateSema(&sp);
    D_0077FFC0.sema = sid;
    q->dst = &result;
    q->size = 4;
    r = func_003B3958(D_007816C0, 11, 0, q, 0x20, D_00780C00, 4, 0, 0, 0);
    if (r < 0) {
        WaitSema(sid);
        SignalSema_3B3EF8();
        return -11;
    }
    flag = *(int *)((unsigned int)D_00780C00 | 0x20000000);
    SignalSema_3B3EF8();
    if (flag == 0) {
        DeleteSema(sid);
        return -11;
    }
    WaitSema(sid);
    DeleteSema(sid);
    return result;
}
