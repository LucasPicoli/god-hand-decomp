/* cygnus-2.96: memory-file read of nsct sectors into buf: clip to the file, copy from the mapped block
 * and zero the tail, under the reader lock. */
typedef struct MemFileReader {
    char unk00;
    signed char stat;                   /* 0x01 1 = idle, 2 = busy */
    char unk02[2];
    int sctSize;                        /* 0x04 */
    char unk08[4];
    int nsct;                           /* 0x0C file length in sectors */
    int pos;                            /* 0x10 current sector */
    int rdBytes;                        /* 0x14 */
    int rdSct;                          /* 0x18 */
    char map[0x14];                     /* 0x1C */
    int off;                            /* 0x30 */
    int size;                           /* 0x34 */
} MemFileReader;

extern char D_00455150[];
extern char D_00455170[];
extern char D_00455190[];

extern void func_00336330(MemFileReader *h, char *msg);
extern void Forward33B658_3362E8(void);
extern void Forward33B670_336300(void);
extern char *MemFile_readMapHeader(char *map, int *avail);
extern void *func_003A5148(void *d, const void *s, unsigned int n);
extern void *func_003A52F0(void *dst, int c, int n);

__attribute__((section(".text.func_003367F8")))
int func_003367F8(MemFileReader *h, int nsct, char *buf)
{
    char *base;
    int avail;
    int d;
    int n;
    int off;
    int size;
    int cp;
    int m;

    if (h == 0) { func_00336330(h, D_00455150); return 0; }
    if (nsct < 0) { func_00336330(h, D_00455170); return 0; }
    if (buf == 0) { func_00336330(h, D_00455190); return 0; }
    if (nsct == 0) {
        h->stat = 1;
        return 0;
    }
    if (h->stat == 2)
        return 0;
    Forward33B658_3362E8();
    h->rdBytes = 0;
    d = h->nsct - h->pos;
    n = d;
    if (nsct < d)
        n = nsct;
    off = h->pos * h->sctSize;
    size = n * h->sctSize;
    h->rdSct = n;
    if (size == 0) {
        h->stat = 1;
        Forward33B670_336300();
        return 0;
    }
    h->off = off;
    h->size = size;
    h->stat = 2;
    base = MemFile_readMapHeader(h->map, &avail);
    m = avail - h->off;
    cp = h->size;
    if (m < cp)
        cp = m;
    Forward33B670_336300();
    func_003A5148(buf, base + h->off, h->size);
    func_003A52F0(buf + cp, 0, h->size - cp);
    Forward33B658_3362E8();
    h->stat = 1;
    h->pos += h->rdSct;
    h->rdBytes = h->rdSct * h->sctSize;
    Forward33B670_336300();
    return h->rdSct;
}
