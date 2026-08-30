/* sn-2.95.3-136 matched TU. */

extern void __malloc_lock(void *reent);
extern void __malloc_unlock(void *reent);

/* newlib mallocr.c :: _malloc_r  -> func_003AC2F8 */

typedef unsigned int INTERNAL_SIZE_T;
typedef unsigned int size_t;

struct malloc_chunk {
    INTERNAL_SIZE_T prev_size;
    INTERNAL_SIZE_T size;
    struct malloc_chunk *fd;
    struct malloc_chunk *bk;
};

typedef struct malloc_chunk *mchunkptr;
typedef struct malloc_chunk *mbinptr;

extern mbinptr D_003FA9D0[]; /* __malloc_av_ */



extern void func_003AC090(void *reent, INTERNAL_SIZE_T nb); /* malloc_extend_top */

#define SIZE_SZ 4
#define MALLOC_ALIGNMENT 16
#define MALLOC_ALIGN_MASK 15
#define MINSIZE 16
#define PREV_INUSE 0x1
#define IS_MMAPPED 0x2
#define SIZE_BITS (PREV_INUSE | IS_MMAPPED)

#define av_ D_003FA9D0
#define bin_at(i) ((mbinptr)((char *)&(av_[2 * (i) + 2]) - 2 * SIZE_SZ))
#define next_bin(b) ((mbinptr)((char *)(b) + 2 * sizeof(mbinptr)))
#define prev_bin(b) ((mbinptr)((char *)(b) - 2 * sizeof(mbinptr)))
#define first(b) ((b)->fd)
#define last(b) ((b)->bk)
#define top (av_[2])
#define last_remainder (bin_at(1))
#define binblocks_r ((INTERNAL_SIZE_T)av_[1])
#define binblocks_w (av_[1])

#define chunk2mem(p) ((void *)((char *)(p) + 2 * SIZE_SZ))
#define chunksize(p) ((p)->size & ~(SIZE_BITS))
#define chunk_at_offset(p, s) ((mchunkptr)(((char *)(p)) + (s)))
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (((mchunkptr)((char *)(p) + (s)))->prev_size = (s))
#define set_inuse_bit_at_offset(p, s) \
    (((mchunkptr)(((char *)(p)) + (s)))->size |= PREV_INUSE)

#define SMALLBIN_WIDTH 8
#define MAX_SMALLBIN 63
#define MAX_SMALLBIN_SIZE 512
#define BINBLOCKWIDTH 4

#define request2size(req) \
  (((long)((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) < \
    (long)(MINSIZE + MALLOC_ALIGN_MASK)) ? MINSIZE : \
   (((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) & ~(MALLOC_ALIGN_MASK)))

#define is_small_request(nb) (nb < MAX_SMALLBIN_SIZE - SMALLBIN_WIDTH)
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
#define clear_binblock(ii) (binblocks_w = (mbinptr)(binblocks_r & ~(idx2binblock(ii))))

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

#define clear_last_remainder \
  (last_remainder->fd = last_remainder->bk = last_remainder)

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

static __inline__ long long_sub_size_t(size_t a, size_t b)
{
  if (a < b)
    {
      size_t diff = b - a;
      return - (long) diff;
    }
  else
    {
      size_t diff = a - b;
      return diff;
    }
}

__attribute__((section(".text.func_003AC2F8")))
void *func_003AC2F8(void *RARG, size_t bytes)
{
  mchunkptr victim;
  INTERNAL_SIZE_T victim_size;
  int idx;
  mbinptr bin;
  mchunkptr remainder;
  long remainder_size;
  int remainder_index;
  unsigned long block;
  int startidx;
  mchunkptr fwd;
  mchunkptr bck;
  mbinptr q;

  INTERNAL_SIZE_T nb;

  nb = request2size(bytes);

  __malloc_lock(RARG);

  /* Check for exact match in a bin */

  if (is_small_request(nb))
  {
    idx = smallbin_index(nb);

    q = bin_at(idx);
    victim = last(q);

    if (victim != q)
    {
      victim_size = chunksize(victim);
      unlink(victim, bck, fwd);
      set_inuse_bit_at_offset(victim, victim_size);
      __malloc_unlock(RARG);
      return chunk2mem(victim);
    }

    idx += 2;
  }
  else
  {
    idx = bin_index(nb);
    bin = bin_at(idx);

    for (victim = last(bin); victim != bin; victim = victim->bk)
    {
      victim_size = chunksize(victim);
      remainder_size = long_sub_size_t(victim_size, nb);

      if (remainder_size >= (long)MINSIZE)
      {
        --idx;
        break;
      }

      else if (remainder_size >= 0)
      {
        unlink(victim, bck, fwd);
        set_inuse_bit_at_offset(victim, victim_size);
        __malloc_unlock(RARG);
        return chunk2mem(victim);
      }
    }

    ++idx;
  }

  /* Try to use the last split-off remainder */

  if ((victim = last_remainder->fd) != last_remainder)
  {
    victim_size = chunksize(victim);
    remainder_size = long_sub_size_t(victim_size, nb);

    if (remainder_size >= (long)MINSIZE)
    {
      remainder = chunk_at_offset(victim, nb);
      set_head(victim, nb | PREV_INUSE);
      link_last_remainder(remainder);
      set_head(remainder, remainder_size | PREV_INUSE);
      set_foot(remainder, remainder_size);
      __malloc_unlock(RARG);
      return chunk2mem(victim);
    }

    clear_last_remainder;

    if (remainder_size >= 0)
    {
      set_inuse_bit_at_offset(victim, victim_size);
      __malloc_unlock(RARG);
      return chunk2mem(victim);
    }

    frontlink(victim, victim_size, remainder_index, bck, fwd);
  }

  if ((block = idx2binblock(idx)) <= binblocks_r)
  {
    if ((block & binblocks_r) == 0)
    {
      idx = (idx & ~(BINBLOCKWIDTH - 1)) + BINBLOCKWIDTH;
      block <<= 1;
      while ((block & binblocks_r) == 0)
      {
        idx += BINBLOCKWIDTH;
        block <<= 1;
      }
    }

    for (;;)
    {
      startidx = idx;
      q = bin = bin_at(idx);

      do
      {
        for (victim = last(bin); victim != bin; victim = victim->bk)
        {
          victim_size = chunksize(victim);
          remainder_size = long_sub_size_t(victim_size, nb);

          if (remainder_size >= (long)MINSIZE)
          {
            remainder = chunk_at_offset(victim, nb);
            set_head(victim, nb | PREV_INUSE);
            unlink(victim, bck, fwd);
            link_last_remainder(remainder);
            set_head(remainder, remainder_size | PREV_INUSE);
            set_foot(remainder, remainder_size);
            __malloc_unlock(RARG);
            return chunk2mem(victim);
          }

          else if (remainder_size >= 0)
          {
            set_inuse_bit_at_offset(victim, victim_size);
            unlink(victim, bck, fwd);
            __malloc_unlock(RARG);
            return chunk2mem(victim);
          }
        }

        bin = next_bin(bin);

        if (idx < MAX_SMALLBIN)
        {
          bin = next_bin(bin);
          ++idx;
        }

      } while ((++idx & (BINBLOCKWIDTH - 1)) != 0);

      do
      {
        if ((startidx & (BINBLOCKWIDTH - 1)) == 0)
        {
          av_[1] = (mbinptr)(binblocks_r & ~block);
          break;
        }
        --startidx;
        q = prev_bin(q);
      } while (first(q) == q);

      if ((block <<= 1) <= binblocks_r && (block != 0))
      {
        while ((block & binblocks_r) == 0)
        {
          idx += BINBLOCKWIDTH;
          block <<= 1;
        }
      }
      else
        break;
    }
  }

  /* Try to use top chunk */

  remainder_size = long_sub_size_t(chunksize(top), nb);
  if (chunksize(top) < nb || remainder_size < (long)MINSIZE)
  {
    func_003AC090(RARG, nb);
    remainder_size = long_sub_size_t(chunksize(top), nb);
    if (chunksize(top) < nb || remainder_size < (long)MINSIZE)
    {
      __malloc_unlock(RARG);
      return 0;
    }
  }

  victim = top;
  set_head(victim, nb | PREV_INUSE);
  top = chunk_at_offset(victim, nb);
  set_head(top, remainder_size | PREV_INUSE);
  __malloc_unlock(RARG);
  return chunk2mem(victim);
}
