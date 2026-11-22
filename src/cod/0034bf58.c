/* cygnus-2.96 matched TU. */

/* cygnus-2.96 candidate: sfbuf_InitUoSjBuf */

typedef struct SjBuf {
    unsigned char d[116];
} SjBuf;

extern void sfbuf_InitBufData(void *d, int type, int flag);
extern void sfbuf_InitUoSj(void *p);

__attribute__((section(".text.sfbuf_InitUoSjBuf")))
void sfbuf_InitUoSjBuf(SjBuf *buf, int *p1, int *p2, int no)
{
    char *d = (char *)&buf[no];
    char *u = d + 0x10;
    sfbuf_InitBufData(d, 3, 1);
    sfbuf_InitUoSj(u);
}
