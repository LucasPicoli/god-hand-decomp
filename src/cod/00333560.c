/* cygnus-2.96: split a text buffer into fixed-width line slots after the nmax-entry header (LF/NUL-
 * terminated, CR/LF stripped) and convert them; the first table built is remembered. */
typedef struct LineTable {
    char *out;                          /* 0x0 */
    int count;                          /* 0x4 */
    int nmax;                           /* 0x8 */
    int width;                          /* 0xC */
} LineTable;

extern LineTable D_003D9DC0;

extern void *func_003A5148(void *d, const void *s, unsigned int n);
extern void dvci_to_large_to_yen(char *s);

__attribute__((section(".text.analysis_flist")))
int analysis_flist(char *out, char *buf, int size, int nmax, int width)
{
    int i;
    int start;
    int n;
    int len;
    char *p;
    char *q;
    char *r;
    char *dst;
    char c;

    i = 0;
    n = 0;
    start = 0;
    if (buf[0] != 0) {
        dst = (char *)(nmax * 8 + (int)out);
        while (1) {
            c = buf[i];
            if (c == '\n' || c == 0) {
                if (buf[i + 1] == '\n' || buf[i + 1] == 0)
                    i++;
                p = &buf[i];
                len = i - start;
                q = p - 1;
                if (*q == '\n' || *q == '\r')
                    *q = 0;
                r = p - 2;
                if (*r == '\n' || *r == '\r')
                    *r = 0;
                func_003A5148(dst, &buf[start], len);
                dvci_to_large_to_yen(dst);
                if (dst[len - 1] != 0)
                    dst[len] = 0;
                start = i + 1;
                dst = (char *)(width + (int)dst + 1);
                n++;
                if (n == nmax)
                    break;
            }
            i++;
            if (size < i)
                break;
            if (buf[i] == 0)
                break;
        }
    }
    if (D_003D9DC0.out == 0) {
        D_003D9DC0.width = width;
        D_003D9DC0.out = out;
        D_003D9DC0.nmax = nmax;
        D_003D9DC0.count = n;
    }
    return n;
}
