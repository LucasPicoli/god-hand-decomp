/* sn-2.95.3-136 matched TU. */

extern void __malloc_lock(void *reent);
extern void __malloc_unlock(void *reent);

/* newlib freer.c :: _free_r  -> func_003ACA28 */

typedef unsigned int INTERNAL_SIZE_T;

struct malloc_chunk {
    INTERNAL_SIZE_T prev_size;
    INTERNAL_SIZE_T size;
    struct malloc_chunk *fd;
    struct malloc_chunk *bk;
};

typedef struct malloc_chunk *mchunkptr;
typedef struct malloc_chunk *mbinptr;

extern mbinptr D_003FA9D0[];      /* __malloc_av_ */
extern unsigned long D_003FADD8;  /* __malloc_trim_threshold */
extern unsigned long D_003FADE0;  /* __malloc_top_pad */



extern int func_003ACD20(void *reent, unsigned int pad); /* _malloc_trim_r */

#define SIZE_SZ 4
#define MALLOC_ALIGNMENT 16
#define MALLOC_ALIGN_MASK 15
#define MINSIZE 16
#define PREV_INUSE 0x1
#define IS_MMAPPED 0x2
#define SIZE_BITS (PREV_INUSE | IS_MMAPPED)

#define av_ D_003FA9D0
#define bin_at(i) ((mbinptr)((char *)&(av_[2 * (i) + 2]) - 2 * SIZE_SZ))
#define top (av_[2])
#define last_remainder (bin_at(1))
#define binblocks_r ((INTERNAL_SIZE_T)av_[1])
#define binblocks_w (av_[1])
#define trim_threshold D_003FADD8
#define top_pad D_003FADE0

#define mem2chunk(mem) ((mchunkptr)((char *)(mem) - 2 * SIZE_SZ))
#define chunk2mem(p) ((void *)((char *)(p) + 2 * SIZE_SZ))
#define chunksize(p) ((p)->size & ~(SIZE_BITS))
#define chunk_at_offset(p, s) ((mchunkptr)(((char *)(p)) + (s)))
#define inuse_bit_at_offset(p, s) \
    (((mchunkptr)(((char *)(p)) + (s)))->size & PREV_INUSE)
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (((mchunkptr)((char *)(p) + (s)))->prev_size = (s))

#define SMALLBIN_WIDTH 8
#define MAX_SMALLBIN 63
#define MAX_SMALLBIN_SIZE 512
#define BINBLOCKWIDTH 4

#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)

#define bin_index(sz)                                                          \
(((((unsigned long)(sz)) >> 9) ==    0) ?       (((unsigned long)(sz)) >>  3): \
 ((((unsigned long)(sz)) >> 9) <=    4) ?  56 + (((unsigned long)(sz)) >>  6): \
 ((((unsigned long)(sz)) >> 9) <=   20) ?  91 + (((unsigned long)(sz)) >>  9): \
 ((((unsigned long)(sz)) >> 9) <=   84) ? 110 + (((unsigned long)(sz)) >> 12): \
 ((((unsigned long)(sz)) >> 9) <=  340) ? 119 + (((unsigned long)(sz)) >> 15): \
 ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18): \
                                          126)

#define idx2binblock(ix) ((unsigned long)1 << (ix / BINBLOCKWIDTH))
#define mark_binblock(ii) (binblocks_w = (mbinptr)(binblocks_r | idx2binblock(ii)))

#define unlink(P, BK, FD)                                                      \
{                                                                              \
  BK = P->bk;                                                                  \
  FD = P->fd;                                                                  \
  FD->bk = BK;                                                                 \
  BK->fd = FD;                                                                 \
}

#define link_last_remainder(P)                                                 \
{                                                                              \
  last_remainder->fd = last_remainder->bk = P;                                 \
  P->fd = P->bk = last_remainder;                                              \
}

#define frontlink(P, S, IDX, BK, FD)                                           \
{                                                                              \
  if (S < MAX_SMALLBIN_SIZE)                                                   \
  {                                                                            \
    IDX = smallbin_index(S);                                                   \
    mark_binblock(IDX);                                                        \
    BK = bin_at(IDX);                                                          \
    FD = BK->fd;                                                               \
    P->bk = BK;                                                                \
    P->fd = FD;                                                                \
    FD->bk = BK->fd = P;                                                       \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    IDX = bin_index(S);                                                        \
    BK = bin_at(IDX);                                                          \
    FD = BK->fd;                                                               \
    if (FD == BK) mark_binblock(IDX);                                          \
    else                                                                       \
    {                                                                          \
      while (FD != BK && S < chunksize(FD)) FD = FD->fd;                        \
      BK = FD->bk;                                                             \
    }                                                                          \
    P->bk = BK;                                                                \
    P->fd = FD;                                                                \
    FD->bk = BK->fd = P;                                                       \
  }                                                                            \
}

__attribute__((section(".text.func_003ACA28")))
void func_003ACA28(void *RARG, void *mem)
{
    mchunkptr p;
    INTERNAL_SIZE_T hd;
    INTERNAL_SIZE_T sz;
    int idx;
    mchunkptr next;
    INTERNAL_SIZE_T nextsz;
    INTERNAL_SIZE_T prevsz;
    mchunkptr bck;
    mchunkptr fwd;
    int islr;

    if (mem == 0)
        return;

    __malloc_lock(RARG);

    p = mem2chunk(mem);
    hd = p->size;

    sz = hd & ~PREV_INUSE;
    next = chunk_at_offset(p, sz);
    nextsz = chunksize(next);

    if (next == top) {
        sz += nextsz;

        if (!(hd & PREV_INUSE)) {
            prevsz = p->prev_size;
            p = chunk_at_offset(p, -((long)prevsz));
            sz += prevsz;
            unlink(p, bck, fwd);
        }

        set_head(p, sz | PREV_INUSE);
        top = p;
        if ((unsigned long)(sz) >= (unsigned long)*(volatile unsigned long *)&trim_threshold)
            func_003ACD20(RARG, top_pad);
        __malloc_unlock(RARG);
        return;
    }

    set_head(next, nextsz);

    islr = 0;

    if (!(hd & PREV_INUSE)) {
        prevsz = p->prev_size;
        p = chunk_at_offset(p, -((long)prevsz));
        sz += prevsz;

        if (p->fd == last_remainder)
            islr = 1;
        else
            unlink(p, bck, fwd);
    }

    if (!(inuse_bit_at_offset(next, nextsz))) {
        sz += nextsz;

        if (!islr && next->fd == last_remainder) {
            islr = 1;
            link_last_remainder(p);
        } else
            unlink(next, bck, fwd);
    }

    set_head(p, sz | PREV_INUSE);
    set_foot(p, sz);
    if (!islr)
        frontlink(p, sz, idx, bck, fwd);

    __malloc_unlock(RARG);
}
