/* Lazy-init singleton getter.  Real entry is 0x0012CF08 (the 8-byte
 * `addiu $sp,+0x10 ; nop` orphan at 0x0012CF00 is dead code that now
 * stays in the monolithic remainder after the boundary fix).
 * The dispatch pointer in .rodata (0x0041D224) stores 0x0012CF08.
 * This natural body byte-matches retail 0x0012CF08..0x0012CF58 (80 B).
 */
extern int D_00785518;
extern int D_0041D2C0;
extern int D_007854C8;
extern void cPlBase__tf(void);
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);

__attribute__((section(".text.GetOrInit_785518_12CF08")))
int *GetOrInit_785518_12CF08(void) {
    if (D_00785518 == 0) {
        cPlBase__tf();
        SetField_0_4_8_31EEA8(&D_00785518, &D_0041D2C0, &D_007854C8);
    }
    return &D_00785518;
}
