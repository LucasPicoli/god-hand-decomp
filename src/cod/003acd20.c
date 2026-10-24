/* sn-2.95.3-136 TU. */

extern void __malloc_lock(void *reent);
extern void __malloc_unlock(void *reent);

/* newlib mallocr.c :: _malloc_trim_r -> func_003ACD20 */

#include "godhand/newlibMalloc.h"
extern char *D_003FADE8;          /* __malloc_sbrk_base */
struct mallinfo {
    int arena;
    int ordblks;
    int smblks;
    int hblks;
    int hblkhd;
    int usmblks;
    int fsmblks;
    int uordblks;
    int fordblks;
    int keepcost;
};

extern struct mallinfo D_003FAE00; /* __malloc_current_mallinfo */

extern void *func_003AE0C8(void **reent, int size); /* _sbrk_r */

#define MINSIZE 16
#define PREV_INUSE 0x1
#define IS_MMAPPED 0x2
#define SIZE_BITS (PREV_INUSE | IS_MMAPPED)

#define av_ D_003FA9D0
#define top (av_[2])
#define sbrk_base D_003FADE8
#define sbrked_mem (D_003FAE00.arena)
#define chunksize(p) ((p)->size & ~(SIZE_BITS))
#define set_head(p, s) ((p)->size = (s))
#define MORECORE(size) func_003AE0C8(reent_ptr, (size))
#define MORECORE_FAILURE ((void *)-1)

__attribute__((section(".text.func_003ACD20")))
int func_003ACD20(void *reent_ptr, unsigned int pad)
{
    long top_size;
    long extra;
    char *current_brk;
    char *new_brk;
    unsigned long pagesz = 4096;

    __malloc_lock(reent_ptr);

    top_size = chunksize(top);
    extra = ((top_size - pad - MINSIZE + (pagesz - 1)) / pagesz - 1) * pagesz;

    if (extra < (long)pagesz) {
        __malloc_unlock(reent_ptr);
        return 0;
    } else {
        current_brk = (char *)MORECORE(0);
        if (current_brk != (char *)top + top_size) {
            __malloc_unlock(reent_ptr);
            return 0;
        } else {
            new_brk = (char *)MORECORE(-extra);
            if (new_brk == (char *)MORECORE_FAILURE) {
                current_brk = (char *)MORECORE(0);
                top_size = current_brk - (char *)top;
                if (top_size >= (long)MINSIZE) {
                    sbrked_mem = current_brk - sbrk_base;
                    set_head(top, top_size | PREV_INUSE);
                }
                __malloc_unlock(reent_ptr);
                return 0;
            } else {
                set_head(top, (top_size - extra) | PREV_INUSE);
                sbrked_mem -= extra;
                __malloc_unlock(reent_ptr);
                return 1;
            }
        }
    }
}
