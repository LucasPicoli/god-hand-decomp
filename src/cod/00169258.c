/* sn-2.95.3-136 matched TU. */

extern float D_0041FE60[];
extern float D_0041FE78[];

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_001F88A8")))
void func_001F88A8(char *o, float *s, unsigned char t, float x, float y, float z)
{
    float hx;
    float hy;
    float hx2;

    o[0] = 1;
    o[1] = t;
    *(short *)(o + 2) = 0;
    if (t == 1) goto one;
    if (t == 2) goto two;
    return;
one:
    {
        hx = x * 0.5f;
        hy = y * 0.5f;
        *(float *)(o + 4) = s[1];
        *(float *)(o + 8) = z;
        *(float *)(o + 0xC) = hx;
        *(float *)(o + 0x10) = s[0] - hx;
        *(float *)(o + 0x14) = s[2] - hy;
        *(float *)(o + 0x18) = s[0] - hx;
        *(float *)(o + 0x1C) = s[2] + hy;
        *(float *)(o + 0x20) = s[0] + hx;
        *(float *)(o + 0x24) = s[2] + hy;
        *(float *)(o + 0x28) = s[0] + hx;
        *(float *)(o + 0x2C) = s[2] - hy;
    return;
    }
two:
    {
        *(float *)(o + 0x10) = s[0];
        hx2 = x * 0.5f;
        *(float *)(o + 0x14) = s[2];
        *(float *)(o + 4) = s[1];
        *(float *)(o + 8) = z;
        *(float *)(o + 0xC) = hx2;
        *(float *)(o + 0x18) = 0.0f;
        *(float *)(o + 0x1C) = 0.0f;
        *(float *)(o + 0x20) = 0.0f;
        *(float *)(o + 0x24) = 0.0f;
        *(float *)(o + 0x28) = 0.0f;
        *(float *)(o + 0x2C) = 0.0f;
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
