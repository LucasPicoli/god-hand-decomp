#include "godhand/cGame.h"

/* TU: cGame - recovered C++ class. */
extern void cEmManage_ReleaseEmAll(void *mgr);
extern char D_005864F0[];
#include "include_asm.h"

/* Release every enemy and start the heap-release wait (5 frames). */
__attribute__((section(".text.cGame_setReleaseActiveHeap")))
void cGame_setReleaseActiveHeap(cGame *self) {
    cEmManage_ReleaseEmAll(D_005864F0);
    self->heapWait = 5;
}
