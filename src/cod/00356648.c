/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct ViBuf ViBuf;

extern void viBufBeginPut(ViBuf *b, unsigned int *a0, unsigned int *a1,
                          unsigned int *a2, unsigned int *a3);
extern int copy2area(unsigned int d0, unsigned int n0, unsigned int d1, unsigned int n1,
                     unsigned int src, int len, int p6, int p7);
extern void viBufEndPut(ViBuf *b, int n);

__attribute__((section(".text.sfmpvp_PutVibuf")))
int sfmpvp_PutVibuf(ViBuf *b, unsigned int src, int len)
{
    unsigned int d0;
    unsigned int n0;
    unsigned int d1;
    unsigned int n1;
    int n;

    viBufBeginPut(b, &d0, &n0, &d1, &n1);
    n = copy2area((d0 & 0x0FFFFFFF) | 0x20000000, n0,
                  (d1 & 0x0FFFFFFF) | 0x20000000, n1, src, len, 0, 0);
    viBufEndPut(b, n);
    return n;
}
