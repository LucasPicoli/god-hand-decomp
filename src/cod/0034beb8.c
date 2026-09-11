/* cygnus-2.96 matched TU. */

extern void func_0034BFA8(void *d, int type, int flag);

/* cygnus-2.96 candidate: sfbuf_InitAringBuf */

typedef struct SjBuf {
    unsigned char d[116];
} SjBuf;



__attribute__((section(".text.func_0034BEB8")))
void func_0034BEB8(SjBuf *buf, int *a, int *b, int no)
{
    char *d = (char *)&buf[no];
    int *p = (int *)(d + 0x10);
    int *pa = a + no;
    int *pb = b + no;
    int va;
    int vb;
    func_0034BFA8(d, 2, *pb != 0);
    va = *pa;
    vb = *pb;
    do { } while (0);
    p[0] = va;
    p[1] = vb;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
}

__attribute__((section(".text.func_0035A6F8")))
void func_0035A6F8(int a0)
{
    volatile int *t = (volatile int *)(a0 + 0xD30);
    if (func_0035A768(a0) != 0) {
        t[0xAA] += t[0xAB];
    }
    if (func_0035A7A0(a0, a0 + 0xD30) != 0) {
        t[0xB3] += t[0xAB];
    }
}
