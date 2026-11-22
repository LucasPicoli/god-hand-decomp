/* cygnus-2.96: m2vlib_InitWork, fits as many 0x700-byte entries as the work area allows and clears them. */
typedef struct {
    char pad0[0x40];
    int count;   /* 0x40 */
    char *work;  /* 0x44 */
} EntPool;

extern EntPool D_0076A590;
extern void *func_003A52F0(void *p, int c, int n);

__attribute__((section(".text.m2vlib_InitWork")))
void *m2vlib_InitWork(int n, int work, unsigned int size)
{
    void *r;

    while (size < (unsigned int)(n * 0x700 + 0x40))
        n--;
    work = (work + 0x3F) & ~0x3F;
    r = func_003A52F0((void *)work, 0, n * 0x700);
    D_0076A590.count = n;
    D_0076A590.work = (char *)work;
    return r;
}
