/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

/* volatile on both objects: it keeps the in-use count's lui out of the beqz
 * slot and its store out of the jr slot, which is retail's schedule. */
extern volatile int D_003EE800;         /* the pool's in-use count, word 0 of its work block */

/* Release a handle: mark it free and drop the pool's in-use count. */
__attribute__((section(".text.func_0035FFB0")))
void func_0035FFB0(volatile int *hn)
{
    if (hn != 0) {
        *hn = 0;
        D_003EE800 = D_003EE800 - 1;
    }
}
