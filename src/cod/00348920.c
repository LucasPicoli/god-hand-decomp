/* cygnus-2.96 matched TU. Kept out of 000000.c: in that unit cc1's choice
 * between retail's `sll; lui $at` and `lui; sll` flips whenever a header adds
 * a declaration, so a one-line prototype elsewhere broke the ELF. */

extern unsigned char D_003EE088[];

__attribute__((section(".text.Obj0000_Get_Ptr_D_003EE088_Scaled_8_348920")))
void *Obj0000_Get_Ptr_D_003EE088_Scaled_8_348920(int a0) {
    return (void *)(D_003EE088 + a0 * 8);
}
