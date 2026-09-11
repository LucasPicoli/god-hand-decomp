/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, output.o :: _cpr8 */

#define D8_CHCR (*(volatile unsigned int *)0x1000D000)
#define D8_MADR (*(volatile unsigned int *)0x1000D010)
#define D8_QWC  (*(volatile unsigned int *)0x1000D020)
#define D8_SADR (*(volatile unsigned int *)0x1000D080)
#define D9_CHCR (*(volatile unsigned int *)0x1000D400)
#define D9_MADR (*(volatile unsigned int *)0x1000D410)
#define D9_QWC  (*(volatile unsigned int *)0x1000D420)
#define D9_SADR (*(volatile unsigned int *)0x1000D480)


extern void func_003B63F0(void);

__attribute__((section(".text.func_0039AEA0")))
void func_0039AEA0(char *c, char *f)
{
    int np;
    int off;
    int p;
    int q;
    int step;
    int ystep;
    int qwc;
    int i;
    int j;

    p = *(int *)(f + 0x0) & 0x0FFFFFFF;
    off = *(int *)(c + 0xEC) & 0x0FFFFFFF;
    if (*(int *)(c + 0x184) == 3 || *(int *)(c + 0xF4) == 0) {
        ystep = *(int *)(f + 0x10) * 0x180;
        qwc = ystep >> 4;
        if (*(int *)(c + 0xF4) != 0)
            step = (*(int *)(c + 0xF4) >> 4) * 0x180;
        else
            step = ystep;
        np = 1;
    } else {
        step = (*(int *)(c + 0xF4) >> 4) * 0xC0;
        ystep = (*(int *)(f + 0x10) >> 1) * 0x180;
        qwc = ystep >> 4;
        np = 2;
    }
    for (j = 0; j < np; j++) {
        q = off;
        for (i = 0; i < *(int *)(f + 0xC); i++) {
            int st;
            int p2;
            int q2;

            st = func_003B63A0();
            D9_SADR = 0;
            D9_MADR = p;
            D9_QWC = qwc;
            D9_CHCR = 0x101;
            if (st)
                func_003B63F0();
            p2 = p + ystep;
            q2 = q + step;
            while (D9_CHCR & 0x100)
                ;
            st = func_003B63A0();
            D8_SADR = 0;
            D8_MADR = q;
            D8_QWC = qwc;
            D8_CHCR = 0x100;
            if (st)
                func_003B63F0();
            while (D8_CHCR & 0x100)
                ;
            while (D8_QWC)
                ;
            q = q2;
            p = p2;
        }
        off += *(int *)(c + 0xF8) * 0xC0;
    }
}
