/* cygnus-2.96 matched TU. */

/* cygnus-2.96 candidate: sfbuf_InitUoSjBuf */

typedef struct SjBuf {
    unsigned char d[116];
} SjBuf;

extern void func_0034BFA8(void *d, int type, int flag);
extern void func_0034BFC8(void *p);

__attribute__((section(".text.func_0034BF58")))
void func_0034BF58(SjBuf *buf, int *p1, int *p2, int no)
{
    char *d = (char *)&buf[no];
    char *u = d + 0x10;
    func_0034BFA8(d, 3, 1);
    func_0034BFC8(u);
}
