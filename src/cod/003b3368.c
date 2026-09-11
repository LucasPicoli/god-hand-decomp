/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct rpcq {
    void *f0;
    int f4;
    int f8;
    int fC;
    int f10;
    struct rpcq *next;
} RpcQ;

typedef struct {
    char pad0[0x28];
    RpcQ *q;
} RpcData;



extern RpcData D_0077FF40;

__attribute__((section(".text.func_003B3368")))
void func_003B3368(RpcQ *q, void *thread)
{
    func_003B63A0();
    q->f0 = thread;
    q->f4 = 0;
    q->f8 = 0;
    q->fC = 0;
    q->f10 = 0;
    q->next = 0;
    {
        RpcData *rd = &D_0077FF40;
        RpcQ *p;
        if (rd->q == 0) {
            rd->q = q;
        } else {
            p = rd->q;
            while (p->next != 0)
                p = p->next;
            p->next = q;
        }
    }
    EIntr();
}
