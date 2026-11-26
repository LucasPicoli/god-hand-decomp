/* ee-2.9-991111 matched TU. */

/* libgcc frame.c (gcc 2.95.2) fde_merge: merge two sorted FDE vectors into the first,
 * walking both from the back. Transcribed from the upstream source. */
typedef int sword __attribute__ ((mode (SI)));
typedef unsigned int uword __attribute__ ((mode (SI)));
typedef unsigned int uaddr __attribute__ ((mode (pointer)));
typedef int saddr __attribute__ ((mode (pointer)));
typedef unsigned int size_t;

struct dwarf_fde {
  uword length;
  sword CIE_delta;
  void *pc_begin;
  uaddr pc_range;
} __attribute__ ((packed, aligned (__alignof__ (void *))));

typedef struct dwarf_fde fde;

typedef struct fde_vector
{
  fde **array;
  size_t count;
} fde_vector;

static __inline__ saddr
fde_compare (fde *x, fde *y)
{
  return (saddr)x->pc_begin - (saddr)y->pc_begin;
}

/* Merge V1 and V2, both sorted, and put the result into V1. */
__attribute__((section(".text.fde_merge")))
void
fde_merge (fde_vector *v1, const fde_vector *v2)
{
  size_t i1, i2;
  fde * fde2;

  i2 = v2->count;
  if (i2 > 0)
    {
      i1 = v1->count;
      do {
	i2--;
	fde2 = v2->array[i2];
	while (i1 > 0 && fde_compare (v1->array[i1-1], fde2) > 0)
	  {
	    v1->array[i1+i2] = v1->array[i1-1];
	    i1--;
	  }
        v1->array[i1+i2] = fde2;
      } while (i2 > 0);
      v1->count += v2->count;
    }
}
