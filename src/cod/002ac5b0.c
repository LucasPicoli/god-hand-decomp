/* sn-2.95.3-136 matched TU. */

extern float ESLib_ESHermite(float a, float b, float c, float d, float e);

/* sn-2.95.3-136 matched TU. */

typedef struct {
    short f0;
    short f2;
    short f4;
    short f6;
    short f8;
    short fA;
} KeyAC5B0;



__attribute__((section(".text.func_002AC5B0")))
float func_002AC5B0(int a0, short t, int idx, void *tbl)
{
    KeyAC5B0 *p;
    KeyAC5B0 *q;

    p = (KeyAC5B0 *)tbl + idx;
    q = p + 1;
    return ESLib_ESHermite((float)(t - p->f8) / (float)(q->f8 - p->f8),
                           0.0f, 1.0f,
                           p->f6 * (1.0f / 4096.0f),
                           q->f4 * (1.0f / 4096.0f));
}
