/* sn-2.95.3-136 matched TU. */
#include "godhand/cArea.h"

extern float D_0041FE60[];
extern float D_0041FE78[];

/* Build an area at height band [s[1], s[1] + z). Type 1 is a quad of size x by y centred on (s[0], s[2]);
 * type 2 is a circle of radius x / 2 centred there. */
__attribute__((section(".text.func_001F88A8")))
void func_001F88A8(cArea *o, float *s, unsigned char t, float x, float y, float z)
{
    float hx;
    float hy;
    float hx2;

    o->used = 1;
    o->type = t;
    o->pad02 = 0;
    if (t == CAREA_TYPE_QUAD) goto one;
    if (t == CAREA_TYPE_CIRCLE) goto two;
    return;
one:
    {
        hx = x * 0.5f;
        hy = y * 0.5f;
        o->y = s[1];
        o->height = z;
        o->radius = hx;
        o->corner[0].x = s[0] - hx;
        o->corner[0].z = s[2] - hy;
        o->corner[1].x = s[0] - hx;
        o->corner[1].z = s[2] + hy;
        o->corner[2].x = s[0] + hx;
        o->corner[2].z = s[2] + hy;
        o->corner[3].x = s[0] + hx;
        o->corner[3].z = s[2] - hy;
    return;
    }
two:
    {
        o->corner[0].x = s[0];
        hx2 = x * 0.5f;
        o->corner[0].z = s[2];
        o->y = s[1];
        o->height = z;
        o->radius = hx2;
        o->corner[1].x = 0.0f;
        o->corner[1].z = 0.0f;
        o->corner[2].x = 0.0f;
        o->corner[2].z = 0.0f;
        o->corner[3].x = 0.0f;
        o->corner[3].z = 0.0f;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.cScenario_getObjIdFromStr")))
int cScenario_getObjIdFromStr(void *thiz, char *s)
{
    int id;

    if (s[0] == 'p' && s[1] == 'l') id = 0x100;
    else if (s[0] == 'e' && s[1] == 'm') id = 0x200;
    else if (s[0] == 'o' && s[1] == 'm') id = 0x300;
    else if (s[0] == 'o' && s[1] == 'l') id = 0x400;
    else if (s[0] == 'e' && s[1] == 'f') id = 0x500;
    else if (s[0] == 'e' && s[1] == 'l') id = 0x600;
    else return 0xFFFF;
    if (s[2] < 'a') id += (s[2] - 0x30) << 4;
    else id += (s[2] - 0x57) << 4;
    if (s[3] >= 'a') id += s[3] - 0x57;
    else id += s[3] - 0x30;
    return id;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */



__attribute__((section(".text.func_00169258")))
void func_00169258(char *o)
{
    float f;
    switch (o[0x5B]) {
    case 0:
        f = D_0041FE60[0];
        *(short *)(o + 0x1D2) = 0;
        *(short *)(o + 0x1D0) = 0;
        *(float *)(*(int *)(o + 0x124) + 0x3C) = f;
        o[0x5B] = 1;
        break;
    case 1:
        *(float *)(*(int *)(o + 0x124) + 0x3C) = D_0041FE60[*(short *)(o + 0x1D2)];
        break;
    case 2:
        *(short *)(*(int *)(o + 0x8C) + 0x90) = 0x2001;
        *(short *)(*(int *)(o + 0x90) + 0x90) = 0x2001;
        *(int *)(*(int *)(o + 0x94) + 0x2C) &= 0xF7FFFFFF;
        *(int *)(*(int *)(o + 0x98) + 0x2C) &= 0xF7FFFFFF;
        *(float *)(*(int *)(o + 0x94) + 0x38) = D_0041FE78[o[0x1D4]];
        break;
    case 4:
        if (*(unsigned char *)(o + 0x286) != 0) o[0x5B] = 3;
        else o[0x5A] = 6;
        break;
    }
}
