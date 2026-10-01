/* cygnus-2.96 matched TU. */
#include "godhand/CustomIDWork.h"

/* Sets the element's local X and stops its position animation. */
__attribute__((section(".text.CustomIDWork_SetLocalPosX")))
void CustomIDWork_SetLocalPosX(CustomIDWork *self, int v)
{
    CustomIDObj *obj = self->obj;

    if (obj != 0) {
        self->localFlags = 0;
        obj->localPos[0] = (float)v;
    }
}

/* Sets the element's local Y and stops its position animation. */
__attribute__((section(".text.CustomIDWork_SetLocalPosY")))
void CustomIDWork_SetLocalPosY(CustomIDWork *self, int v)
{
    CustomIDObj *obj = self->obj;

    if (obj != 0) {
        self->localFlags = 0;
        obj->localPos[1] = (float)v;
    }
}

/* Sets the element's offset X and stops its offset animation. */
__attribute__((section(".text.CustomIDWork_SetOffsetPosX")))
void CustomIDWork_SetOffsetPosX(CustomIDWork *self, int v)
{
    CustomIDObj *obj = self->obj;

    if (obj != 0) {
        self->offsFlags = 0;
        obj->offsetPos[0] = (float)v;
    }
}

/* Sets the element's offset Y and stops its offset animation. */
__attribute__((section(".text.CustomIDWork_SetOffsetPosY")))
void CustomIDWork_SetOffsetPosY(CustomIDWork *self, int v)
{
    CustomIDObj *obj = self->obj;

    if (obj != 0) {
        self->offsFlags = 0;
        obj->offsetPos[1] = (float)v;
    }
}

/* cygnus-2.96 | fp_hazard_rules mtc1 */
__attribute__((section(".text.func_002D6578")))
void func_002D6578(char *p, int v)
{
    char *q = *(char **)(p + 0x4);

    if (q != 0) {
        *(float *)(q + 0x68) = (float)v;
    }
}

/* cygnus-2.96 | fp_hazard_rules mtc1 */
__attribute__((section(".text.func_002D65A0")))
void func_002D65A0(char *p, int v)
{
    char *q = *(char **)(p + 0x4);

    if (q != 0) {
        *(float *)(q + 0x6C) = (float)v;
    }
}
