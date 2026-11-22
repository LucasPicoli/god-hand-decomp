/* include/godhand/CustomIDPanel.h - CustomID panel helpers (0x1DE4F8.., 0x1ECE30..).
 *
 * The panels keep 0x7C-byte CustomIDWork records from +0x60. Their slot and
 * digit tables live in rodata and are copied whole into locals (ldl/ldr,
 * sdl/sdr), so they are declared as structs. Colours are built in an
 * uninitialised bitfield struct and passed as *(unsigned int *)&col.
 * Kept apart from CustomIDWork.h because older callers declare these
 * methods with other parameter types.
 */
#ifndef GODHAND_CUSTOMIDPANEL_H
#define GODHAND_CUSTOMIDPANEL_H

typedef struct { int w[5]; } CustomIDSlotTbl;
typedef struct { int w[8]; } CustomIDSlotTbl8;
typedef struct { int w[5][2]; } CustomIDDigitTbl;
typedef struct { unsigned int r:8, g:8, b:8, a:8; } CustomIDColor;

extern void CustomIDWork_SetOffsetPosX(void *work, int x);
extern void CustomIDWork_SetMoveOffsetPosX(void *work, int from, int to, int frames);
extern void CustomIDWork_SetOffsetPosY(void *work, int y);
extern void CustomIDWork_SetMoveOffsetPosY(void *work, int from, int to, int frames);
extern void CustomIDWork_SetScaleAnimSin(void *work, int frames, float from, float to);
extern void CustomIDWork_ResetScaleAnim(void *work);
extern void CustomIDWork_SetColorAnimSin(void *work, unsigned int from, unsigned int to, int frames);
extern void CustomIDWork_ResetColorAnim(void *work);
extern void CustomIDWork_SetColorAnimNormal_2D6898(void *work, unsigned int col, int frames);
extern void CustomIDWork_SetDisp(char *work, int disp);
extern void CustomIDWork_SetLocalPosY(void *work, int y);
extern void CustomIDWork_SetMessNo(void *work, int no);
extern void CustomIDWork_SetNumber(void *work, int n);
extern void SetCustomIDDispOneOrAll_1DD258(char *self, int id, int disp);
extern void SetCustomIDDispOneOrAll_1F29C0(void *self, int id, int disp);
extern void CustomIDWork_SetNoDisp(void *work, int noDisp);
extern void CustomIDWork_SetChildNoDisp(void *work, int noDisp);

extern CustomIDSlotTbl8 D_0042B678;
extern CustomIDSlotTbl8 D_0042B698;
extern CustomIDDigitTbl D_0042BD70;

#endif
