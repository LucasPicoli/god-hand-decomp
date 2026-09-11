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

__attribute__((section(".text.sceSifRemoveRpcQueue")))
RpcQ *sceSifRemoveRpcQueue(RpcQ *q)
{
    RpcQ *p;

    func_003B63A0();
    {
        RpcData *rd = &D_0077FF40;
        p = rd->q;
        if (p == q) {
            rd->q = p->next;
        } else {
            while (p != 0) {
                if (p->next == q) {
                    p->next = q->next;
                    break;
                }
                p = p->next;
            }
        }
    }
    EIntr();
    return p;
}
