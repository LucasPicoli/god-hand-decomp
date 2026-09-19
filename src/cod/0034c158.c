/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

typedef struct SupInfo { int w[6]; } SupInfo;

typedef struct SupBuf {
    SupInfo inf;
    int conti[2];
    int f20;
    int f24;
    int que[1];
} SupBuf;

extern void Thunk_func_0033B658(void *cs);
extern void Thunk_func_0033B670(void *cs);
extern void func_0034C1F8(void *conti);
extern void func_003592D0(void *que);

__attribute__((section(".text.sfbuf_SetSupSj")))
void sfbuf_SetSupSj(SupBuf *d, SupInfo *q, int *e, int flag)
{
    int cs[4];

    Thunk_func_0033B658(cs);
    e[1] = flag;
    d->inf = *q;
    func_0034C1F8(d->conti);
    d->f20 = 0;
    d->f24 = 0;
    func_003592D0(d->que);
    Thunk_func_0033B670(cs);
}
