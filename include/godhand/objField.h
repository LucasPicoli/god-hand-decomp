/* include/godhand/objField.h - the object-field helpers every actor setup uses.
 *
 * These four helpers read and write fixed offsets inside an actor record
 * (the base of the cObj family, see cObjBase.h). They live in the monolithic
 * TU 000000.c / 0014b6f8.c and are called from the actor setup code that
 * spawns a move and fills in its position.
 *
 * The declarations here are the one form each helper has: every caller in
 * src/cod used to spell the same prototype locally, so moving them here
 * cannot change what any translation unit compiles to.
 */
#ifndef GODHAND_OBJFIELD_H
#define GODHAND_OBJFIELD_H

/* Write *a1* into the int at offset 0x50 of the actor record. */
extern void Obj0000_Set_Field_50_173998(int *a0, int a1);

/* Copy x, y and z from *a1* into the vector at offset 0x20 of the record. */
extern void CopyVec3ToField20_173908(char *a0, float *a1);

/* Copy x, y and z from *a1* into the vector at offset 0x30 of the record. */
extern void CopyVec3ToField30_173938(char *a0, float *a1);

/* Copy x, y and z from *a1* into the vector at offset 0x40 of the record. */
extern void CopyVec3ToField40_173968(char *a0, float *a1);

#endif
