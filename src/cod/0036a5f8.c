/* cygnus-2.96 matched TU. */

typedef struct V {
    char pad0[0x18];
    int (*f18)(void *h, int a, int b, int *out);
    int (*f1C)(void *h, int a, int *out);
} V;
typedef struct H { V *vt; } H;

extern int MPV_CheckDelim(int v);

__attribute__((section(".text.mpvhdec_GetCurDelim")))
int mpvhdec_GetCurDelim(H *h)
{
    int buf[2];

    h->vt->f18(h, 1, 0x7FFFFFFF, buf);
    h->vt->f1C(h, 1, buf);
    if (buf[1] < 4) return 0;
    return MPV_CheckDelim(buf[0]);
}
