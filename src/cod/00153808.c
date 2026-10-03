/* sn-2.95.3-136 matched TU. */

#include "godhand/cModel.h"

extern void capVu0ApplyMatrixXYZ(cVec *dst, float *mtx, cVec *v);
extern void sceVu0InversMatrix(float *dst, float *src);
extern void func_001501D0(cParts *part, int objFlags);
extern unsigned int D_00747A34;

/* Aim one IK link: put the part on the model's matrix, pull its position onto `target`, then rebuild its local matrix from the parent's inverse. */


extern void func_0030A2E0(float *dst, float *a, float *b);              /* dst = a * b */




__attribute__((section(".text.func_00153808")))
void func_00153808(cOmBase *model, cParts *part, cVec *target) {
    cVec frame[6] __attribute__((aligned(16)));
    cParts *child = part->next;
    float *mtx = part->mtx;
    cVec *pos;
    cVec *copy;
    func_0030A2E0(mtx, model->mtx, part->mtxLocal);
    capVu0ApplyMatrixXYZ(part->pos, mtx, child->anchor);
    pos = part->pos;
    copy = &frame[4];
    VU0_ZERO_VSUB_XYZ_MEM(frame, 0x50, target, pos);
    VU0_LQC2(4, (char *)frame + 0x50, 0);
    VU0_SQC2(4, frame, 0x40);
    if (pos != copy) {
        pos->x = frame[4].x;
        pos->y = frame[4].y;
        pos->z = frame[4].z;
    }
    sceVu0InversMatrix((float *)frame, part->parent->mtx);
    func_0030A2E0(part->mtxLocal, (float *)frame, mtx);
    func_001501D0(child, model->objFlags);
}

/* Heap: first fit. Walk the block list for a block whose free tail holds `size` plus a 0x20 byte header after aligning
 * the user address to `align`; link a new header after it, hand the rest of the free space to the new block, return the user address. */
#define HEAP_HDR_SIZE  0x20
#define HEAP_LOCK      0x80000          /* D_00747A34 bit: allocation refused */

/* One block header: a used part, then free space up to the next block. */
typedef struct HeapBlk {
    char unk00[8];
    struct HeapBlk *next;               /* 0x08 */
    unsigned int freeSize;              /* 0x0C free bytes after the used part */
    unsigned int usedSize;              /* 0x10 header plus user bytes */
} HeapBlk;

typedef struct Heap {
    HeapBlk *head;                      /* 0x00 */
} Heap;


extern void func_002A9620(Heap *heap, HeapBlk *blk, HeapBlk *after);      /* link blk after `after` */

__attribute__((section(".text.func_002A9538")))
void *func_002A9538(Heap *heap, unsigned int size, unsigned int align) {
    HeapBlk *blk;
    HeapBlk *fresh;
    unsigned int need;
    unsigned int end;
    unsigned int user;
    unsigned int raw;
    unsigned int pad;
    unsigned int total;
    if (D_00747A34 & HEAP_LOCK) {
        return 0;
    }
    if (size == 0) {
        return 0;
    }
    blk = heap->head;
    need = size + HEAP_HDR_SIZE;
    while (blk != 0) {
        if (blk->freeSize >= need) {
            end = (unsigned int)blk + blk->usedSize;
            raw = end + (HEAP_HDR_SIZE - 1);
            user = (raw + align) & -align;
            fresh = (HeapBlk *)(user - HEAP_HDR_SIZE);
            pad = (unsigned int)fresh - end;
            total = need + pad;
            if (blk->freeSize >= total) {
                func_002A9620(heap, fresh, blk);
                fresh->usedSize = need;
                fresh->freeSize = blk->freeSize - total;
                blk->freeSize = pad;
                return (void *)user;
            }
        }
        blk = blk->next;
    }
    return 0;
}
