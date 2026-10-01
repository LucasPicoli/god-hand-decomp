/* pl00_DiscardWeapon — if the player holds a weapon object (0x698), release it
 * (cOmWeapon_dropToGround) and null the slot.  sn-2.95.3-136. */

extern void cOmWeapon_dropToGround(void *);

__attribute__((section(".text.pl00_DiscardWeapon")))
void pl00_DiscardWeapon(void *a0) {
    void *p = *(void **)((char *)a0 + 0x698);
    if (!p)
        return;
    cOmWeapon_dropToGround(p);
    *(int *)((char *)a0 + 0x698) = 0;
}
