/* include/godhand/objField.h - small field helpers the effect setup code calls.
 *
 * Obj0000_Set_Field_50_173998, Obj0000_Set_Byte_54 and the three CopyVec3
 * helpers write fixed offsets of the record the caller passes. In the setup
 * code at 0x160E78 and its siblings that record is a 0x60-byte slot from the
 * array at owner + 0x628, and field 0x50 gets a pointer to node + 0x80. The
 * record has no typed struct yet.
 *
 * Set_Field_50 and Set_Byte_54 are defined in the monolith 000000.c, the
 * CopyVec3 helpers in the carved TU 0014b6f8.c, ForwardVec3At30_147C60 in
 * 00124f60.c. Each definition includes this header, so a drifted prototype
 * fails to compile.
 *
 * GetField_54_173900 is not here on purpose: callers declare it returning int
 * and the definition returns unsigned char, and one prototype would change
 * what the callers compile to.
 */
#ifndef GODHAND_OBJFIELD_H
#define GODHAND_OBJFIELD_H

/* Store the pointer value at offset 0x50 of rec. */
extern void Obj0000_Set_Field_50_173998(void *rec, void *value);

/* Store the low byte of value at offset 0x54 of rec. */
extern void Obj0000_Set_Byte_54(void *rec, int value);

/* Copy x, y and z from src into the vector at offset 0x20 of rec. */
extern void CopyVec3ToField20_173908(char *rec, float *src);

/* Copy x, y and z from src into the vector at offset 0x30 of rec. */
extern void CopyVec3ToField30_173938(char *rec, float *src);

/* Copy x, y and z from src into the vector at offset 0x40 of rec. */
extern void CopyVec3ToField40_173968(char *rec, float *src);

/* Write the translation row of the 4x4 matrix mtx (floats 12 to 14) to dst.
 * The body passes only the three floats: dst reaches func_00150710 untouched
 * in $a0. */
extern void ForwardVec3At30_147C60(void *dst, float *mtx);

#endif
