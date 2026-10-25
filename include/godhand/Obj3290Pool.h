/* include/godhand/Obj3290Pool.h - the 40-entry request pool of src/cod/00327*.c..00328*.c (CRI libadxe).
 *
 * D_003D04D0 holds OBJ3290_POOL_NUM entries of 0x60 bytes. The first byte of an
 * entry is its state (0 = free). D_003D04C4 is the lock word the trampoline
 * Obj3290_Tramp_0033BF18_9058 takes. Field names are ours, from the methods
 * that touch them; offsets are exact. A field nobody has named yet stays as
 * unkNNN padding.
 */
#ifndef GODHAND_OBJ3290POOL_H
#define GODHAND_OBJ3290POOL_H

#define OBJ3290_POOL_NUM    40
#define OBJ3290_STATE_FREE  0
#define OBJ3290_STATE_QUEUED 1

typedef struct Obj3290Ent {
    signed char state;                  /* 0x00 */
    char unk01[0x5F];
} Obj3290Ent;                           /* 0x60 */

extern Obj3290Ent D_003D04D0[OBJ3290_POOL_NUM];
extern volatile int D_003D04C4;         /* lock word, polled by other threads */
extern int Obj3290_Tramp_0033BF18_9058(volatile int *lock);
extern void func_003288E0(void *ent);

#endif
