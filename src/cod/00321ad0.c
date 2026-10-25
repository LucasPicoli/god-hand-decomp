/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */
#include "godhand/ehFrameSort.h"

extern void func_003A7B48(void) __attribute__((noreturn));   /* abort */
extern void func_00322748(fde_vector *linear, fde_vector *erratic);   /* fde_split */
extern void func_003219D0(fde_vector *v1, fde_vector *v2);            /* fde_merge */
extern void UpdateGlobalPtrWithParam_3A7CC0(void *p);                 /* free */

/* gcc frame.c end_fde_sort, with frame_heapsort inlined. */
__attribute__((section(".text.end_fde_sort")))
fde **end_fde_sort(fde_accumulator *accu, unsigned int count)
{
    if (accu->linear.count != count)
        func_003A7B48();
    func_00322748(&accu->linear, &accu->erratic);
    if (accu->linear.count + accu->erratic.count != count)
        func_003A7B48();
    {
        fde_vector *erratic = &accu->erratic;
        fde **a = erratic->array;
        unsigned int n = erratic->count;
        unsigned int m = n;
        unsigned int i;

#define SWAP(x, y) do { fde *tmp = x; x = y; y = tmp; } while (0)
        while (m > 0) {
            m--;
            for (i = m; 2 * i + 1 < n; ) {
                if (2 * i + 2 < n
                    && fde_compare(a[2 * i + 2], a[2 * i + 1]) > 0
                    && fde_compare(a[2 * i + 2], a[i]) > 0) {
                    SWAP(a[i], a[2 * i + 2]);
                    i = 2 * i + 2;
                } else if (fde_compare(a[2 * i + 1], a[i]) > 0) {
                    SWAP(a[i], a[2 * i + 1]);
                    i = 2 * i + 1;
                } else
                    break;
            }
        }
        while (n > 1) {
            n--;
            SWAP(a[0], a[n]);
            for (i = 0; 2 * i + 1 < n; ) {
                if (2 * i + 2 < n
                    && fde_compare(a[2 * i + 2], a[2 * i + 1]) > 0
                    && fde_compare(a[2 * i + 2], a[i]) > 0) {
                    SWAP(a[i], a[2 * i + 2]);
                    i = 2 * i + 2;
                } else if (fde_compare(a[2 * i + 1], a[i]) > 0) {
                    SWAP(a[i], a[2 * i + 1]);
                    i = 2 * i + 1;
                } else
                    break;
            }
        }
#undef SWAP
    }
    func_003219D0(&accu->linear, &accu->erratic);
    UpdateGlobalPtrWithParam_3A7CC0(accu->erratic.array);
    return accu->linear.array;
}
