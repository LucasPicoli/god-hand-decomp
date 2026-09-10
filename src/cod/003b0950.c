/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

struct ThreadParam {
    int status;
    void *func;
    void *stack;
    int stack_size;
    void *gp_reg;
    int initial_priority;
    int current_priority;
    unsigned int attr;
    unsigned int option;
};

struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

typedef struct { int f0; int f4; } Ring;

extern int CreateSema(struct SemaParam *p);
extern int CreateThread(struct ThreadParam *p);
extern int DeleteSema(int id);
extern int GetThreadId(void);
extern int ChangeThreadPriority(int tid, int prio);
extern void func_003B0BA8(int tid, Ring *r);
extern void topThread(Ring *r);
extern int D_003FAE48;
extern int D_0077DF90;
extern Ring D_0077DF98;
extern char D_0077DB90[];
extern char D_00468CF0[];
extern char D_0045FE28[];

__attribute__((section(".text.func_003B0950")))
int func_003B0950(void)
{
    struct ThreadParam tp;
    struct SemaParam sp;
    int tid;

    if (D_003FAE48 > 0)
        return -1;
    sp.maxCount = 0xFF;
    sp.initCount = 0;
    sp.option = (unsigned int)D_0045FE28;
    D_0077DF90 = CreateSema(&sp);
    if (D_0077DF90 < 0)
        return -1;
    tp.func = topThread;
    tp.stack = D_0077DB90;
    tp.stack_size = 0x400;
    tp.gp_reg = D_00468CF0;
    tp.initial_priority = 0;
    tp.option = (unsigned int)D_0045FE28;
    tid = CreateThread(&tp);
    D_003FAE48 = tid;
    if (tid < 0) {
        DeleteSema(D_0077DF90);
        return -1;
    }
    D_0077DF98.f0 = 0;
    D_0077DF98.f4 = 0;
    func_003B0BA8(tid, &D_0077DF98);
    ChangeThreadPriority(GetThreadId(), 1);
    return D_003FAE48;
}
