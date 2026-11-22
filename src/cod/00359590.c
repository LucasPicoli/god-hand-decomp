/* cygnus-2.96: sfpts_ReadPtsQueSub, skips the queued items reported by func_00359628 and returns the item at the
 * new head of the 16-byte ring queue. */
typedef struct { int w[4]; } __attribute__((aligned(8))) QItem;
typedef struct {
    QItem *buf;
    int cap;
    int count;
    int tail;
    int head;
} Queue;

extern int func_00359628(Queue *q, int a1, int a2, int a3);

__attribute__((section(".text.sfpts_ReadPtsQueSub")))
void sfpts_ReadPtsQueSub(Queue *q, int a1, QItem *out, int a3, int a4)
{
    int n;
    int h;

    if (q->count == 0)
        return;
    n = func_00359628(q, a1, a3, a4);
    if (n == -1)
        return;
    h = q->head + n;
    if (h >= q->cap)
        h -= q->cap;
    q->head = h;
    q->count -= n;
    *out = q->buf[h];
}
