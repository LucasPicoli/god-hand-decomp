/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct { int sema; void *dst; int size; char name[0x400]; } Pkt;

struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};


extern void func_003B3F50(void);
extern int SignalSema_3B3EF8(void);
extern int CreateSema(struct SemaParam *p);
extern int DeleteSema(int id);
extern int WaitSema(int id);

extern int D_003FAEDC;
extern Pkt D_0077FFC0;
extern char D_004601C8[];
extern char D_00780C00[];
extern char D_007816C0[];

__attribute__((section(".text.func_003B5120")))
int func_003B5120(const char *name, int cmd)
{
    struct SemaParam sp;
    int result;
    int sid;
    int r;
    int flag;
    int i;
    Pkt *q = &D_0077FFC0;

    func_003B3EC8(cmd);
    if (D_003FAEDC == 0)
        func_003B3F50();
    for (i = 0; i < 0x400; i++) {
        if ((q->name[i] = name[i]) == 0)
            break;
    }
    if (i == 0x400) {
        q->name[0x3FF] = 0;
        i = 0x3FF;
    }
    sp.maxCount = 1;
    sp.initCount = 0;
    sp.option = (unsigned int)D_004601C8;
    sid = CreateSema(&sp);
    q->dst = &result;
    q->sema = sid;
    q->size = 4;
    r = func_003B3958(D_007816C0, cmd, 0, &D_0077FFC0, i + 0xD, D_00780C00, 4, 0, 0, 0);
    if (r < 0) {
        DeleteSema(sid);
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
