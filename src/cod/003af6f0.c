/* sn-2.95.3-136 matched TU. */

/* newlib mprec __ratio (0x003AF6F0). */
typedef struct _Bigint {
    struct _Bigint *_next;
    int _k;
    int _maxwds;
    int _sign;
    int _wds;
    unsigned int _x[1];
} _Bigint;

typedef union { double d; unsigned int i[2]; } U;

extern double func_003AF3D8(_Bigint *a, int *e);   /* _b2d */
extern double func_0031E5F0(double a, double b);   /* __divdf3 */

__attribute__((section(".text.func_003AF6F0")))
double func_003AF6F0(_Bigint *a, _Bigint *b)
{
    U da, db;
    int k, ka, kb;

    da.d = func_003AF3D8(a, &ka);
    db.d = func_003AF3D8(b, &kb);
    k = ka - kb + 32 * (a->_wds - b->_wds);
    if (k > 0) {
        da.i[1] += k << 20;
    } else {
        k = -k;
        db.i[1] += k << 20;
    }
    return da.d / db.d;
}

/* newlib mallocr cALLOc / _calloc_r (0x003AF7B8). */
typedef unsigned int INTERNAL_SIZE_T;

extern void *func_003AC2F8(void *r, unsigned int n);         /* _malloc_r */
extern void *func_003A52F0(void *s, int c, unsigned int n);  /* memset    */

#define SIZE_SZ    (sizeof(INTERNAL_SIZE_T))
#define mem2chunk(mem) ((char *)(mem) - 2 * SIZE_SZ)
#define chunksize(p)   (*(INTERNAL_SIZE_T *)((char *)(p) + 4) & ~(INTERNAL_SIZE_T)0x3)

#define MALLOC_ZERO(charp, nbytes)                                            \
do {                                                                          \
  INTERNAL_SIZE_T mzsz = (nbytes);                                            \
  if(mzsz <= 9*sizeof(mzsz)) {                                                \
    INTERNAL_SIZE_T* mz = (INTERNAL_SIZE_T*)(charp);                          \
    if(mzsz >= 5*sizeof(mzsz)) {   *mz++ = 0;                                 \
                                   *mz++ = 0;                                 \
      if(mzsz >= 7*sizeof(mzsz)) { *mz++ = 0;                                 \
                                   *mz++ = 0;                                 \
        if(mzsz >= 9*sizeof(mzsz)) { *mz++ = 0;                               \
                                     *mz++ = 0; }}}                           \
                                   *mz++ = 0;                                 \
                                   *mz++ = 0;                                 \
                                   *mz = 0;                                   \
  } else func_003A52F0((charp), 0, mzsz);                                     \
} while(0)

__attribute__((section(".text.func_003AF7B8")))
void *func_003AF7B8(void *r, unsigned int n, unsigned int elem_size)
{
    char *p;
    INTERNAL_SIZE_T csz;
    INTERNAL_SIZE_T sz = n * elem_size;
    void *mem;

    mem = func_003AC2F8(r, sz);
    if (mem == 0) {
        return 0;
    } else {
        p = mem2chunk(mem);
        csz = chunksize(p);
        MALLOC_ZERO(mem, csz - SIZE_SZ);
        return mem;
    }
}
