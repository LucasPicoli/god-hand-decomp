/* cygnus-2.96 matched TU. */

/* cygnus-2.96 candidate: sfbuf_SetSupplySjSub */

typedef struct SjBuf {
    unsigned char d[116];
} SjBuf;

typedef struct SupInfo {
    int f0;
    int f4;
} SupInfo;


extern void sfbuf_SetSupSj(void *d, SupInfo *q, void *e, int flag);

__attribute__((section(".text.func_0034C0E8")))
int func_0034C0E8(char *p, SupInfo *q, int no)
{
    SjBuf *e = (SjBuf *)(p + 0x1310);
    char *b = (char *)&e[no];
    char *d = b + 0x10;
    if (*(int *)b != 4) {
        return func_0034DD70(p, 0xFF000409);
    }
    sfbuf_SetSupSj(d, q, b, q->f4 != 0);
    return 0;
}
