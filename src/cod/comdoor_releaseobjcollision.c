#include "godhand/cOmDoor.h"

/* cOmDoor_releaseObjCollision — if the door holds a collision object (0x644),
 * release it from the collision manager (D_005CAE50 via func_0012EC58) and null
 * the slot.  sn-2.95.3-136. */

extern void func_0012EC58(void *, void *);
extern char D_005CAE50;

/* If the door holds a collision object, release it from the collision
 * manager (D_005CAE50) and null the slot. */
__attribute__((section(".text.cOmDoor_releaseObjCollision")))
void cOmDoor_releaseObjCollision(cOmDoor *self) {
    void *coll = self->collision;
    if (!coll)
        return;
    func_0012EC58(&D_005CAE50, coll);
    self->collision = 0;
}
